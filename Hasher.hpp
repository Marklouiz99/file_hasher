#pragma once
#include<stdexcept>
#include <openssl/evp.h>
#include<string>

class Hasher
{
public:
   static std::string computeHash(const void* data, size_t size);
};
