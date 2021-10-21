#include <iostream>


#include "funcs.h"

int main()
{
//	std::cout<<"hi";
	double f[26];
//	std::cout<<"hi";
	addfrequencies(f,"engmix.txt");
	for (int i = 0; i < 26; i++)
		std::cout<<f[i]<<"\n";
	std::string s = "Bj rzxy, ymjwjktwj, fhvznjxhj ns ymj sjhjxxnyd, bmnhm ijstzshjx tzw Xjufwfynts, fsi mtqi ymjr, fx bj mtqi ymj wjxy tk rfspnsi, Jsjrnjx ns Bfw, ns Ujfhj Kwnjsix.";
	std::cout<<solve(s,"engmix.txt");
	std::cout<<"\n";
  return 0;
}
