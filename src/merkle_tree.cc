#include <iostream>
#include "merkle_tree.h"

// Hash Node
HashNode::HashNode(){
    const char* zeroConstCharArr = "0";
    unsigned char* zeroHash = (unsigned char*)zeroConstCharArr;
    strcpy((char*)this->mHash, (char*)zeroHash);
}

HashNode::~HashNode(){
}

unsigned char[SHA256_DIGEST_LENGTH] HashNode::getHash(){
    return this->mHash;
}

// Transaction Node
TransactionNode::TransactionNode(){
    const char* zeroConstCharArr = "0";
    unsigned char* zeroHash = (unsigned char*)zeroConstCharArr;
    strcpy((char*)this->mHash, (char*)zeroHash);
}

TransactionNode::~TransactionNode(){
}

unsigned char[SHA256_DIGEST_LENGTH] TransactionNode::getHash(){
    return this->mHash;
}

// Merkle Tree
MerkleTree::MerkleTree(){
}

MerkleTree::~MerkleTree(){
}

bool addTransaction(utils::Data& aTransactionData){
    TransactionNode transaction;
     
}