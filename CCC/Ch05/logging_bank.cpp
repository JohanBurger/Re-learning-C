// clang++ -std=c++17 -Wall -Wextra -pedantic logging_bank.cpp bank.cpp account_database.cpp logger.cpp -o logging_bank

#include "bank.cpp"

int main(void)
{
    ConsoleLogger console_logger("[CONS]");
    InMemoryAccountDatabase account_database;
    Bank bank(&account_database, &console_logger);

    bank.transfer(1001, 2002, 49.95);

    FileLogger file_logger;
    bank.set_logger(&file_logger);
    bank.transfer(2002, 4004, 20.00);
}
