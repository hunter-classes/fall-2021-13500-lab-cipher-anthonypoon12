/*
Author: Anthony Poon
Course: CSCI-135
Instructor: Tong Yi, Mike Zamansky
Assignment: Lab Cipher main
main function for Lab
*/
#include <iostream>
#include "funcs.h"

int main()
{
	std::string in1 = "We hold these truths to be self-evident, that all men are created equal, that they are endowed by their Creator with certain unalienable Rights, that among these are Life, Liberty and the pursuit of Happiness.--That to secure these rights, Governments are instituted among Men, deriving their just powers from the consent of the governed, --That whenever any Form of Government becomes destructive of these ends, it is the Right of the People to alter or to abolish it, and to institute new Government, laying its foundation on such principles and organizing its powers in such form, as to them shall seem most likely to effect their Safety and Happiness. Prudence, indeed, will dictate that Governments long established should not be changed for light and transient causes; and accordingly all experience hath shewn, that mankind are more disposed to suffer, while evils are sufferable, than to right themselves by abolishing the forms to which they are accustomed. But when a long train of abuses and usurpations, pursuing invariably the same Object evinces a design to reduce them under absolute Despotism, it is their right, it is their duty, to throw off such Government, and to provide new Guards for their future security.--Such has been the patient sufferance of these Colonies; and such is now the necessity which constrains them to alter their former Systems of Government. The history of the present King of Great Britain is a history of repeated injuries and usurpations, all having in direct object the establishment of an absolute Tyranny over these States. To prove this, let Facts be submitted to a candid world.";
	std:: string in2 = "Harry Potter is a series of seven fantasy novels written by British author J. K. Rowling. The novels chronicle the lives of a young wizard, Harry Potter, and his friends Hermione Granger and Ron Weasley, all of whom are students at Hogwarts School of Witchcraft and Wizardry";
	std:: string in3 = "Computer science is the study of algorithmic processes, computational machines and computation itself.[1] As a discipline, computer science spans a range of topics from theoretical studies of algorithms, computation and information to the practical issues of implementing computational systems in hardware and software.[2][3]Its fields can be divided into theoretical and practical disciplines. For example, the theory of computation concerns abstract models of computation and general classes of problems that can be solved using them, while computer graphics or computational geometry emphasize more specific applications. Algorithms and data structures have been called the heart of computer science.[4] Programming language theory considers approaches to the description of computational processes, while computer programming involves the use of them to create complex systems. Computer architecture describes construction of computer components and computer-operated equipment. Artificial intelligence aims to synthesize goal-orientated processes such as problem-solving, decision-making, environmental adaptation, planning and learning found in humans and animals. A digital computer is capable of simulating various information processes.[5] The fundamental concern of computer science is determining what can and cannot be automated.[6] Computer scientists usually focus on academic research. The Turing Award is generally recognized as the highest distinction in computer sciences.";
	std:: string in4 = "Hello，my name is Anthony Poon and I am a college student! Nice to meet you! By the way, do you know where the bathroom is? No? Oh well.";
	std:: string in5 = "I like to eat lots of chocolate and candy and ice cream and mushrooms and I love to play video games.";
	std::string b = encryptCaesar(in1,15);
	std::string d = encryptCaesar(in2,20);
	std::string e = encryptCaesar(in3,2);
	std::string e2 = encryptCaesar(in3,0);
	std::string e3 = encryptCaesar(in3,26);
	std::string f = encryptCaesar(in4,17);
	std::string g = encryptCaesar(in5,23);
	std::cout<<"input1: \n\n"<<in1<<"\n\n\n";
	std::cout<<"input2: \n\n"<<in2<<"\n\n\n";
	std::cout<<"input3: \n\n"<<in3<<"\n\n\n";
	std::cout<<"input4: \n\n"<<in4<<"\n\n\n";
	std::cout<<"input5: \n\n"<<in5<<"\n\n\n";
	std::cout<<"input 1 is shifted by 15:\n\n"<<b<<"\n\n\n\n";
	std::cout<<"input 2 is shifted by 10:\n\n"<<d<<"\n\n\n\n";
	std::cout<<"input 3 is shifted by 2:\n\n"<<e<<"\n\n\n\n";
	std::cout<<"input 3 is shifted by 0:\n\n"<<e<<"\n\n\n\n";
	std::cout<<"input 3 is shifted by 26:\n\n"<<e<<"\n\n\n\n";
	std::cout<<"input 4 is shifted by 17:\n\n"<<f<<"\n\n\n\n";
	std::cout<<"input 5 is shifted by 23:\n\n"<<g<<"\n\n\n\n";
	std::cout<<"input 1 solved:\n\n"<<solve(b)<<"\n\n\n\n\n";
	std::cout<<"input 2 solved:\n\n"<<solve(d)<<"\n\n\n\n\n";
	std::cout<<"input 3-1 solved:\n\n"<<solve(e)<<"\n\n\n\n\n";
	std::cout<<"input 3-2 solved:\n\n"<<solve(e2)<<"\n\n\n\n\n";
	std::cout<<"input 3-3 solved:\n\n"<<solve(e3)<<"\n\n\n\n\n";
	std::cout<<"input 4 solved:\n\n"<<solve(f)<<"\n\n\n\n\n";
	std::cout<<"input 5 solved:\n\n"<<solve(g)<<"\n\n\n\n\n";
  return 0;
}
