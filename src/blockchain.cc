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
    utils::Data* data;
    data->moneyTransfer  = moneyTransfer;
    data->debtor         = debtor;
    data->creditor       = creditor;
    Block* genesisBlock = new Block(data);
    (this->chain).push_back(*genesisBlock);
    this->blockCount++;
}

// Get the latest block
Block Blockchain::getLatestBlock(){
    return this->chain[blockCount - 1];
}

bool Blockchain::addNewBlock(Block& newBlock){
    // set prevHash of newBlock
    strcpy((char*)newBlock.header->prevHash, (char*)(this->getLatestBlock())->header->hash);
    // set index of newBlock
    newBlock.index = this->blockCount + 1;
    (this->chain).push_back(&newBlock);
    this->blockCount++;
    return true;
}

bool Blockchain::addNewBlock(Block*& newBlock){
    // set prevHash of newBlock
    strcpy((char*)newBlock->header->prevHash, (char*)(this->getLatestBlock())->header->hash);
    // set index of newBlock
    newBlock->index = this->blockCount + 1;
    (this->chain).push_back(newBlock);
    this->blockCount++;
    return true;
}