#include <iostream>
#include "caesar.h"
#include "funcs.h"
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
