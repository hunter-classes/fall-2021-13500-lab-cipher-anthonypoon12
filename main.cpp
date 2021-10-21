#include <iostream>


#include "funcs.h"

int main()
{
//	std::cout<<"hi";
	double f[26];
//	std::cout<<"hi";
	addfrequencies(f,"dec.txt");
	for (int i = 0; i < 26; i++)
		std::cout<<f[i]<<"\n";
  return 0;
}
