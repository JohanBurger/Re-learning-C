#include <cstdio>

struct AccountDatabase
{
    virtual ~AccountDatabase() = default;
    virtual double get_balance(long account_id) = 0;
    virtual void update_balance(long account_id, double new_balance) = 0;
};

struct InMemoryAccountDatabase : AccountDatabase
{
    double get_balance(long account_id) override
    {
        // For demonstration purposes, return a fixed balance
        if (account_id == 1001)
            return 1000.0;
        return 999.0;
    }

    void update_balance(long account_id, double new_balance) override
    {
        // For demonstration purposes, just print the update action
        printf("Updating account %ld to new balance: %f\n", account_id, new_balance);
    }
};