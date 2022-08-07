#include <stdio.h>
#include <iostream>
#include <vector> 
#include <string.h> 
#include <string>
#include <openssl/sha.h>

#include "blockchain.h"
// ****************************************************************************************************** //

// Blockchain Constructor
Blockchain::Blockchain(std::string debtor, std::string creditor, long long int moneyTransfer){
    // Create genesis block and add it to the chain
    utils::Data data;
    data.moneyTransfer  = moneyTransfer;
    data.debtor         = debtor;
    data.creditor       = creditor;
    long long unsigned initialIndex = 0;
    std::string firstTimeStamp = utils::getTimestamp();
    const char* zeroConstCharArr = "0";
    unsigned char* zeroHash = (unsigned char*)zeroConstCharArr;
    Block* genesisBlock = new Block(initialIndex, firstTimeStamp, data, zeroHash);
    (this->chain).push_back(*genesisBlock);
    this->blockCount++;
}

// Get the latest block
Block Blockchain::getLatestBlock(){
    return this->chain[blockCount - 1];
}

bool Blockchain::addNewBlock(Block newBlock){
    strcpy((char*)newBlock.prevHash, (char*)(this->getLatestBlock()).hash);
    newBlock.calculateHash();
    (this->chain).push_back(newBlock);
    this->blockCount++;
    return true;
}