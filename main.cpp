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
	std::cout<<solve(" Prudence, indeed, will dictate that Governments long established should not be changed for light and transient causes; and accordingly all experience hath shewn, that mankind are more disposed to suffer, while evils are sufferable, than to right themselves by abolishing the forms to which they are accustomed. ", "dec.txt");
	std::cout<<"\n";
  return 0;
}
