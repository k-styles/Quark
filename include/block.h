#include <stdio.h>
#include <iostream>
#include <vector> 
#include <string.h> 
#include <string>
#include <openssl/sha.h>

#include "utils.h"

class Block
{
    public:
        unsigned char hash[SHA256_DIGEST_LENGTH]; 
        unsigned char prevHash[SHA256_DIGEST_LENGTH];      
        bool calculateHash();
        utils::Data data;
    
    public:
        std::string timestamp;
        Block(long long unsigned int&, utils::Data&, unsigned char*&);
        long long unsigned int index;
    
    //friend class Blockchain;
};   