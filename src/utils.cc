#include <stdio.h>
#include <iostream>
#include <chrono>
#include <string.h> 
#include <string>
#include "utils.h"
std::string utils::getTimestamp(){
    uint64_t ms = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    uint64_t sec = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    return std::to_string(sec) + " : " + std::to_string(ms);
}

std::string utils::Data::toString(){
    return "Money Transferred: " + std::to_string(moneyTransfer) + "\nDebtor: " + debtor + "\nCreditor: " + creditor + "\n";
}
