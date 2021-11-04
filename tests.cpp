/*
Author: Anthony Poon
Course: CSCI-135
Instructor: Tong Yi, Mike Zamansky
Assignment: Lab Cipher tests
Tests for Lab Cipher
*/
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "funcs.h"
std::string a = "Hello, my name is Anthony Poon and it is lovely to meet you.";
std::string b = "Thank you. It is very nice to meet you as well. Please, have a seat.";
std::string c = "By the way, my favorite ice cream is chocolate. What is yours?";
std::string d = "Add a new function using the signature ~std::stringsolve(std::string encrypted_string)~ that will use the techniques we discussed in classto decode the parameter ~encrypted_string~. That string will be textthat has been encoded using the Caesar cipher you already wrote. ";
TEST_CASE("shiftChar")
{
	CHECK(shiftChar('a',0)=='a');
	CHECK(shiftChar('z',1)=='a');
	CHECK(shiftChar('b',4)=='f');
	CHECK(shiftChar('A',0)=='A');
	CHECK(shiftChar('Z',1)=='A');
	CHECK(shiftChar('B',4)=='F');
	CHECK(shiftChar('A',50)=='Y');
	CHECK(shiftChar('A',300)=='O');
	CHECK(shiftChar(' ',1)==' ');
}
TEST_CASE("encryptCaesar")
{
	CHECK(encryptCaesar("Hello",20)=="Byffi");
	CHECK(encryptCaesar("Hi my name is meh",2) == "Jk oa pcog ku ogj");
	CHECK(encryptCaesar("Anthony",300)=="Obhvcbm");
}
TEST_CASE("vigenere")
{
	CHECK(encryptVigenere("Hello, World!", "cake")=="Jevpq, Wyvnd!");
}
TEST_CASE("decryption")
{
	CHECK(decryptCaesar("Byffi",20)=="Hello");
	CHECK(decryptCaesar("Jk oa pcog ku ogj",2) == "Hi my name is meh");
	CHECK(decryptCaesar("Obhvcbm",300) == "Anthony");
	CHECK(decryptVigenere("Jevpq, Wyvnd!","cake")=="Hello, World!");
}
TEST_CASE("solve")
{
	CHECK(solve(encryptCaesar(a, 22)) == a);
	CHECK(solve(encryptCaesar(b, 0)) == b);
	CHECK(solve(encryptCaesar(c, 26)) == c);
	CHECK(solve(encryptCaesar(d, 17)) == d);
}
