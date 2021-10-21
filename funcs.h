#pragma once
char shiftChar(char c, int rshift);
std::string encryptCaesar(std::string plaintext, int rshift);
std::string encryptVigenere(std::string plaintext, std::string keyword);
std::string decryptCaesar(std::string ciphertext, int rshift);
std::string decryptVigenere(std::string ciphertext, std::string keyword);
std::string solve(std::string encrypted_string);
void addfrequencies(double f[26],std::string file);
