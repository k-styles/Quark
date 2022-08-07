#include <stdio.h>
#include <iostream>
#include <chrono>
#include <string.h> 
#include <string>

namespace utils
{
    std::string getTimestamp();

    struct Data
    {
        long long int moneyTransfer;
        std::string debtor;
        std::string creditor;
        std::string toString();
    };
}
