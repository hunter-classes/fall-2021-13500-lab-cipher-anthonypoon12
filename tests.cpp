#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "funcs.h"

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
