#include <stdio.h>
#include <iostream>
#include <vector> 
#include <string.h> 
#include <string>
#include <openssl/sha.h>

#include "block.h"

// ***************************************************** Methods ************************************************* //
Block::Block(utils::Data& data){
    this->index     = 0;
    *this->data     = data;
    this->header->timestamp = utils::getTimestamp();
    // Initialize hash to zero hash of a newly created block
    const char* zeroConstCharArr = "0";
    unsigned char* zeroHash = (unsigned char*)zeroConstCharArr;
    strcpy((char*)this->header->prevHash, (char*)zeroHash);
    // Calculate hash of the block in creation
    this->calculateHash();
}

Block::Block(utils::Data*& dataPtr){
    this->index     = 0;
    this->data     = dataPtr;
    this->header->timestamp = utils::getTimestamp();
    // Initialize hash to zero hash of a newly created block
    const char* zeroConstCharArr = "0";
    unsigned char* zeroHash = (unsigned char*)zeroConstCharArr;
    strcpy((char*)this->header->prevHash, (char*)zeroHash);
    // Calculate hash of the block in creation
    this->calculateHash();
}

bool Block::calculateHash(){
    // Calculate hash and set it to hash variable
    std::string stringStruct = this->data.toString();
    unsigned long long int len = strlen(stringStruct.c_str());
    SHA256((unsigned char*)stringStruct.c_str(), len, this->header->hash);
    return true;
}
