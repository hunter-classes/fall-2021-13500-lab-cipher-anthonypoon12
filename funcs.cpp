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
std::vector<std::vector<int>> helper(double input[26], int s)//creates a vector made of all the rotations of the input vector
{
    std::vector<std::vector<int>> output;
    for (int i = 0 ; i < s; i++)
    {
        std::vector<int> miniout;
        for (int j = 0; j < s;j++)
        {
            int a = i+j;
            if (a>s-1)
                a = i+j - s;
            miniout.push_back(input[a]);
        }
        output.push_back(miniout);
    }
    return output;
}
double distance(std::vector<int> input, double base[26])
{
	int sum = 0;
	for (int i = 0 ;i  < input.size(); i++)
	{
		sum += pow(input[i]-base[i],2);
	}
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
std::string solve(std::string encrypted_string, std::string filename)
{
	double frequencies[26];
	addfrequencies(frequencies, filename);
    double fofinput[26];
    std::string dummy = "";
    for (char c: encrypted_string)
    {
        if ((!isspace(c))&&(isalpha(c)))
            dummy+=tolower(c);
    }
    for (char d: dummy)
    {
        fofinput[d-'a']+=1;
    }
    for (int i = 0; i < sizeof(fofinput)/sizeof(fofinput[0]);i++)
    {
        fofinput[i]=(double)fofinput[i]/dummy.size();
    }
    std::vector<std::vector<int>> rotations = helper(fofinput,sizeof(fofinput)/sizeof(fofinput[0]));
	double minimum = distance(rotations[0],frequencies);
	int ind = 0;
	for (int i = 1; i < rotations.size(); i++)
	{
		if (minimum > distance(rotations[i],frequencies))
		{
			minimum = distance(rotations[i],frequencies);
			ind = i;
		}
	}
	dummy=encryptCaesar(dummy,ind);
    return dummy;
}
