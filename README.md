# *Quark*
This is my implementation of a blockchain - *Quark*.  
You can experiment with it in the *main.cpp* file. Follow through this *README* file to check out the functionalities and brief implementations of the methods provided.

## *Compilation*
```bash
meson build
cd build && meson compile
```
The main binary will be created in the build folder with name : "quark" after compiling with meson

## *BLOCK*
### <ins>*Header:*
#### Fields
    - Previous Hash
    - Timestamp
    - Index

### <ins>*Data:*
#### Fields
    - Money Transfer
    - Debtor
    - Creditor
    
#### Method
    - std:string toString() : Converts the data struct into a string
    

### <ins>*Methods:*
- Constructor:
```cpp
Block::Block(long long unsigned int& index, utils::Data& data, unsigned char*& prevHash){
    this->index     = index;
    this->data      = data;
    this->timestamp = utils::getTimestamp();
    strcpy((char*)this->prevHash, (char*)prevHash);
    this->calculateHash();
    //strcpy((char*)this->hash, (char*)hash); 
}
```
- Calculate Hash:
```cpp
bool Block::calculateHash(){
    // Calculate hash and set it to hash variable
    std::string stringStruct = this->data.toString();
    unsigned long long int len = strlen(stringStruct.c_str());
    SHA256((unsigned char*)stringStruct.c_str(), len, this->hash);
    return true;
}
```
<br />
<br />

## *BLOCKCHAIN*
### <ins> *Fields:*
    - Block Count
    - Chain (std::vector<Block>)
### <ins> *Methods:*
- Constructor:
    
```cpp
Blockchain::Blockchain(std::string debtor, std::string creditor, long long int moneyTransfer){
    // Create genesis block and add it to the chain
    utils::Data data;
    data.moneyTransfer  = moneyTransfer;
    data.debtor         = debtor;
    data.creditor       = creditor;
    long long unsigned initialIndex = 0;
    const char* zeroConstCharArr = "0";
    unsigned char* zeroHash = (unsigned char*)zeroConstCharArr;
    Block* genesisBlock = new Block(initialIndex, data, zeroHash);
    (this->chain).push_back(*genesisBlock);
    this->blockCount++;
}
```

- Get Latest Block : Gets the block added recently to the blockchain
```cpp
Block Blockchain::getLatestBlock(){
    return this->chain[blockCount - 1];
}
```

- Add New Block
```cpp
bool Blockchain::addNewBlock(Block newBlock){
    strcpy((char*)newBlock.prevHash, (char*)(this->getLatestBlock()).hash);
    newBlock.calculateHash();
    (this->chain).push_back(newBlock);
    this->blockCount++;
    return true;
}
```
