#include <stdio.h>
#include <iostream>
#include <vector> 
#include <string.h> 
#include <string>
#include <openssl/sha.h>

#include "blockchain.h"

int main(int argc, char** argv){
    Blockchain blockchain("Alice", "bob", 30);

    std::cout << (blockchain.getLatestBlock()).data.toString() << "\n";

    utils::Data newData{1, "Leonard", "Sheldon"};    
    long long unsigned int newIndex = 1;
    std::string newTimeStamp = utils::getTimestamp();
    unsigned char* prevBlockHash = blockchain.getLatestBlock().hash;
    Block newBlock(newIndex, newTimeStamp, newData, prevBlockHash);
    blockchain.addNewBlock(newBlock);

    std::cout << (blockchain.getLatestBlock()).data.toString() << "\n";
    return EXIT_SUCCESS;
}