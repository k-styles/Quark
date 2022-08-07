#include <stdio.h>
#include <iostream>
#include <vector> 
#include <string.h> 
#include <string>
#include <openssl/sha.h>

#include "block.h"

// ***************************************************** Methods ************************************************* //
Block::Block(long long unsigned int& index, std::string& timestamp, utils::Data& data, unsigned char*& prevHash){
    this->index     = index;
    this->data      = data;
    this->timestamp = timestamp;
    strcpy((char*)this->prevHash, (char*)prevHash);
    this->calculateHash();
    //strcpy((char*)this->hash, (char*)hash); 
}

bool Block::calculateHash(){
    // Calculate hash and set it to hash variable
    std::string stringStruct = this->data.toString();
    unsigned long long int len = strlen(stringStruct.c_str());
    SHA256((unsigned char*)stringStruct.c_str(), len, this->hash);
    return true;
}