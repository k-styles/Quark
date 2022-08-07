#include <stdio.h>
#include <iostream>
#include <vector> 
#include <string.h> 
#include <string>
#include <openssl/sha.h>

// No need to include utils.h
#include "block.h"

class Blockchain
{
    private:
        long long unsigned int blockCount = 0;
        std::vector<Block> chain;

    public:
        Blockchain(std::string, std::string, long long int);
        Block getLatestBlock();
        bool addNewBlock(Block);
};
