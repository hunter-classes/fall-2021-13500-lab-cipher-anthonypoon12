#include <iostream>
#include "funcs.h"
#include <cctype>
#include <vector>
#include <math.h>
#include <fstream>
char shiftChar(char c, int rshift)
{
	char output = c;
	if ((islower(c))&&((int)c+rshift>'z'))
		output = ((((int)c+rshift-'z')%26)+'a'-1);
	else if ((isupper(c))&&((int)c+rshift>'Z'))
		output = ((((int)c+rshift - 'Z')%26) + 'A'-1);
	else if ((isupper(c))||(islower(c)))
		output = c + rshift;
	return output;
}
std::string encryptCaesar(std::string plaintext, int rshift)
{
	std::string output = "";
	for (int i = 0; i<plaintext.length();i++)
		output += shiftChar(plaintext[i],rshift);
	return output;
}

std::string encryptVigenere(std::string plaintext, std::string keyword)
{
	int counter = 0;
	std::string output = "";
	for (int i = 0; i<plaintext.length(); i++)
	{
		if(islower(plaintext[i])||(isupper(plaintext[i])))
		{
			output += shiftChar(plaintext[i],(int)keyword[counter%keyword.length()]-(int)'a');
			counter++;
		}
		else
			output += plaintext[i];
	}
	return output;
}

std::string decryptCaesar(std::string ciphertext, int rshift)
{
	std::string output = "";
	output = encryptCaesar(ciphertext,26-((int)rshift%26));
	return output;
}

std::string decryptVigenere(std::string ciphertext, std::string keyword)
{
	std::string dummy="";
	std::string output;
	for (int i = 0; i<keyword.length(); i++)
	{
		dummy+=(char)('z'-keyword[i]+'a'+1);
	}
	output =encryptVigenere(ciphertext, dummy);
	return output;
}
std::vector<int[26]> helper(std::string input)//creates a vector made of all the rotations of the input vector
{
	std::vector<int[26]> output;
	for (int i = 0; i < 26; i++)
	{
		int dum[26];
		std::string dummy = encryptCaesar(input, i);
		for (char c: dummy)
		{
			if ((!isspace(c))&&(isalpha(c)))
			{
				dum[tolower(c)-'a']++;
			}
		}
		output.push_back(dum);
	}
	return output;
}
double distance(int input[26], double base[26])
{
	double sum = 0;
	for (int i = 0 ;i  < 26; i++)
	{
		sum += pow((input[i]-base[i]),2);
	}
//	std::cout<<sqrt(sum)<<" cool\n";
	return sqrt(sum);
}
void addfrequencies(double input[],std::string filename)
{
//	std::cout<<"hi";
	std::string totalstring = "";
	std::string small = "";
	std::string dummy = "";
	std::ifstream file(filename);
	while (getline(file,small))
		totalstring+=small;

    for (char c: totalstring)
    {
        if (!isspace(c)&&(isalpha(c)!=0))
	{
          input[(int)tolower(c)-(int)'a']+=1;
		dummy += c;
	}
    }
    for (int i = 0; i < 26;i++)
    {
        input[i]=(double)input[i]/dummy.size();
    }

	file.close();
}

std::string solve(std::string encrypted_string)
{
	double frequencies[26]={0.08167, 0.01492, 0.02782, 0.04253, 	0.12702, 0.02228,
                     0.02015, 0.06094, 0.06966, 0.00153, 0.00772, 0.04025,
                     0.02406, 0.06749, 0.07507, 0.01929, 0.00095, 0.05987,
                     0.06327, 0.09056, 0.02758, 0.00978, 0.02360, 0.00150,
                     0.01974, 0.00074};
    
    std::vector<int[26]> rotations = helper(encrypted_string);
	double minimum = distance(rotations[0],frequencies);
//	std::cout<<minimum<<" this is first\n";
	int ind = 0;
	for (int i = 1; i < rotations.size(); i++)
	{
	//	std::cout<<i<<" , "<<distance(rotations[i],frequencies)<<"\n";
		if (minimum > distance(rotations[i],frequencies))
		{
			minimum = distance(rotations[i],frequencies);
			ind = i;
		}
//	std::cout<<ind<<" hi "<<minimum<<"\n";
	}
//	std::cout<<encryptCaesar(dummy,21);
	dummy=encryptCaesar(dummy,ind);
    return dummy;
}
