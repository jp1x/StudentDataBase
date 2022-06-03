#pragma once
class Encryptor
{
public:
	int Encrypt(const char* password, const char* databaseName);
	int Decrypt(const char* password, const char* databaseName);
};
