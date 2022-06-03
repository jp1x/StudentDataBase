#include "Encryptor.h"
#include <time.h>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

int Encryptor::Encrypt(const char* password, const char* databaseName)
{
    string dbName = databaseName;

    string command = "openssl\\bin\\openssl.exe enc -aes-256-cbc -e -salt -pbkdf2 -in ";
    command += dbName;
    command += " -out ";
    command += dbName;
    command += ".enc -pass pass:";
    command += password;
    system(command.c_str());

    if (remove(dbName.c_str()) != 0)
    {
        cout << "[ERROR] - deleting file" << endl;
    }

    return 0;
}

int Encryptor::Decrypt(const char* password, const char* databaseName)
{
    string dbName = databaseName;

    string command = "openssl\\bin\\openssl.exe enc -aes-256-cbc -d -pbkdf2 -in ";
    command += dbName;
    command += ".enc -out ";
    command += dbName;
    command += " -pass pass:";
    command += password;
    int code = system(command.c_str());

    if (code == 1)
    {
        remove(dbName.c_str());
        return 1;
    }

    if (remove((dbName + ".enc").c_str()) != 0)
    {
        cout << "[ERROR] - deleting file" << endl;
    }

    return 0;
}
