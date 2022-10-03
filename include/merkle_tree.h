#include <iostream>
#include <string>
#include <vector>
#include "utils.h"

class HashNode
{
    private:
        unsigned char mHash[SHA256_DIGEST_LENGTH];
    public:
        unsigned char[SHA256_DIGEST_LENGTH] getHash();
    friend class MerkleTree;
};

class TransactionNode
{
    private:
        unsigned char mHash[SHA256_DIGEST_LENGTH];
    public:
        unsigned char[SHA256_DIGEST_LENGTH] getHash();
        utils::Data mTransactionData;
    friend class MerkleTree;
};

class MerkleTree
{
    // member class variables
    public:
        HashNode mMerkleRoot;
        std::vector<TransactionNode*> mTransactions;
    
    // methods
    public:
        MerkleTree();
        ~MerkleTree();
        bool addTransaction(std::string&);
        bool evaluateTree();

        bool calculateHash();
};