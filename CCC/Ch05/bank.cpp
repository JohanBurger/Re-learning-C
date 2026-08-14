#include <stdexcept>

#include "account_database.cpp"
#include "logger.cpp"

struct Bank
{
    Bank(AccountDatabase *account_database, Logger *logger)
        : account_database(account_database),
          logger(logger)
    {
    }

    void set_logger(Logger *logger)
    {
        this->logger = logger;
    }

    void transfer(long from, long to, double amount)
    {
        double from_balance = account_database->get_balance(from);
        if (from_balance < amount)
        {
            throw std::runtime_error("Insufficient funds");
        }

        double to_balance = account_database->get_balance(to);
        account_database->update_balance(from, from_balance - amount);
        account_database->update_balance(to, to_balance + amount);
        // Log the transfer
        if (logger)
        {
            this->logger->log_transfer(from, to, amount);
        }
    }

private:
    AccountDatabase *account_database;
    Logger *logger;
};