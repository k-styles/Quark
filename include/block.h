#include <stdio.h>
#include <iostream>
#include <vector> 
#include <string.h> 
#include <string>
#include <openssl/sha.h>

#include "utils.h"

class Blockchain;

// Block fields definitions
struct BlockSize{

};

struct Header{
    std::string version;
    unsigned char prevHash[SHA256_DIGEST_LENGTH];      
    unsigned char hash[SHA256_DIGEST_LENGTH]; 
    // Merkle root hash
    std::string timestamp; // in seconds from unix epoch time
    // Difficulty target
    // NONCE
};

struct Transactions{
    // in form of merkle tree
};

struct TransactionCounter{

};

class Block
{
    public:
        BlockSize* blockSize;
        Header* header;
        Transactions* transactions;
        TransactionCounter* transactionCounter;

        bool calculateHash();
        utils::Data* data; // Transactions are pumped into merkle tree
    
    public:
        Block(utils::Data&);
        Block(utils::Data*&);
        long long unsigned int index;

    //friend class Blockchain;
    friend class Blockchain;
};   