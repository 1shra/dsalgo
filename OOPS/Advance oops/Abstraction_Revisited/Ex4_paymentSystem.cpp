#include <iostream>
#include <string>
using namespace std;

class PaymentMethod
{
protected:
    string provider;

public:
    PaymentMethod(const string &p) : provider(p) {}
    virtual ~PaymentMethod() = default;

    string getProvider() const { return provider; }
    virtual bool processPayment(double amount) = 0;
    virtual bool refund(double amount) = 0;
    virtual bool validate() = 0;
};

class CreditCard : public PaymentMethod
{
private:
    double creditLimit;
    double currentBalance;

public:
    CreditCard(const string &provider, double limit, double balance = 0)
        : PaymentMethod(provider), creditLimit(limit), currentBalance(balance) {}

    bool processPayment(double amount) override
    {
        if (!validate())
        {
            cout << "Credit card validation failed!" << endl;
            return false;
        }

        if (currentBalance + amount > creditLimit)
        {
            cout << "Payment failed: Exceeds credit limit!" << endl;
            return false;
        }

        currentBalance += amount;
        cout << "Credit card payment of $" << amount << " processed successfully!" << endl;
        cout << "Current balance: $" << currentBalance << endl;
        return true;
    }

    bool refund(double amount) override
    {
        if (amount <= 0)
        {
            cout << "Refund amount must be positive!" << endl;
            return false;
        }

        if (currentBalance - amount < 0)
        {
            cout << "Refund failed: Insufficient balance to refund!" << endl;
            return false;
        }

        currentBalance -= amount;
        cout << "Credit card refund of $" << amount << " processed successfully!" << endl;
        cout << "Current balance: $" << currentBalance << endl;
        return true;
    }

    bool validate() override
    {
        if (provider.empty())
        {
            cout << "Validation failed: No provider specified!" << endl;
            return false;
        }
        if (creditLimit <= 0)
        {
            cout << "Validation failed: Invalid credit limit!" << endl;
            return false;
        }
        cout << "Credit card validation successful!" << endl;
        return true;
    }
};

class PayPal : public PaymentMethod
{
private:
    string email;
    double balance;

public:
    PayPal(const string &provider, const string &email, double balance)
        : PaymentMethod(provider), email(email), balance(balance) {}

    bool processPayment(double amount) override
    {
        if (!validate())
        {
            cout << "PayPal validation failed!" << endl;
            return false;
        }

        if (balance < amount)
        {
            cout << "Payment failed: Insufficient balance!" << endl;
            return false;
        }

        balance -= amount;
        cout << "PayPal payment of $" << amount << " processed successfully!" << endl;
        cout << "Remaining balance: $" << balance << endl;
        return true;
    }

    bool refund(double amount) override
    {
        if (amount <= 0)
        {
            cout << "Refund amount must be positive!" << endl;
            return false;
        }

        balance += amount;
        cout << "PayPal refund of $" << amount << " processed successfully!" << endl;
        cout << "New balance: $" << balance << endl;
        return true;
    }

    bool validate() override
    {
        if (email.empty() || email.find('@') == string::npos)
        {
            cout << "Validation failed: Invalid email address!" << endl;
            return false;
        }
        if (balance < 0)
        {
            cout << "Validation failed: Balance cannot be negative!" << endl;
            return false;
        }
        cout << "PayPal validation successful!" << endl;
        return true;
    }
};

class BankTransfer : public PaymentMethod
{
private:
    string accountNumber;
    double balance;
    double transferLimit;

public:
    BankTransfer(const string &provider, const string &accNumber, double balance, double limit = 10000)
        : PaymentMethod(provider), accountNumber(accNumber), balance(balance), transferLimit(limit) {}

    bool processPayment(double amount) override
    {
        if (!validate())
        {
            cout << "Bank transfer validation failed!" << endl;
            return false;
        }

        if (amount > transferLimit)
        {
            cout << "Payment failed: Amount exceeds transfer limit of $" << transferLimit << "!" << endl;
            return false;
        }

        if (balance < amount)
        {
            cout << "Payment failed: Insufficient balance!" << endl;
            return false;
        }

        balance -= amount;
        cout << "Bank transfer of $" << amount << " processed successfully!" << endl;
        cout << "Remaining balance: $" << balance << endl;
        return true;
    }

    bool refund(double amount) override
    {
        if (amount <= 0)
        {
            cout << "Refund amount must be positive!" << endl;
            return false;
        }

        balance += amount;
        cout << "Bank transfer refund of $" << amount << " processed successfully!" << endl;
        cout << "New balance: $" << balance << endl;
        return true;
    }

    bool validate() override
    {
        if (accountNumber.empty() || accountNumber.length() < 5)
        {
            cout << "Validation failed: Invalid account number!" << endl;
            return false;
        }
        if (balance < 0)
        {
            cout << "Validation failed: Balance cannot be negative!" << endl;
            return false;
        }
        cout << "Bank transfer validation successful!" << endl;
        return true;
    }
};

class PaymentProcessor
{
public:
    static bool makePayment(PaymentMethod *method, double amount)
    {
        if (!method)
        {
            cout << "Error: No payment method provided!" << endl;
            return false;
        }

        cout << "\nProcessing payment with " << method->getProvider() << "..." << endl;
        return method->processPayment(amount);
    }

    static bool makeRefund(PaymentMethod *method, double amount)
    {
        if (!method)
        {
            cout << "Error: No payment method provided!" << endl;
            return false;
        }

        cout << "\nProcessing refund with " << method->getProvider() << "..." << endl;
        return method->refund(amount);
    }
};

int main()
{
    cout << "=== Payment System Demo ===" << endl;

    // Test Credit Card
    cout << "\n--- Testing Credit Card ---" << endl;
    CreditCard cc("Visa", 5000, 1000);
    PaymentProcessor::makePayment(&cc, 2000);
    PaymentProcessor::makePayment(&cc, 2500); // Should fail - exceeds limit
    PaymentProcessor::makeRefund(&cc, 500);

    // Test PayPal
    cout << "\n--- Testing PayPal ---" << endl;
    PayPal pp("PayPal", "user@example.com", 3000);
    PaymentProcessor::makePayment(&pp, 1500);
    PaymentProcessor::makePayment(&pp, 2000); // Should fail - insufficient funds
    PaymentProcessor::makeRefund(&pp, 500);

    // Test Bank Transfer
    cout << "\n--- Testing Bank Transfer ---" << endl;
    BankTransfer bt("Chase Bank", "123456789", 10000, 5000);
    PaymentProcessor::makePayment(&bt, 3000);
    PaymentProcessor::makePayment(&bt, 6000); // Should fail - exceeds transfer limit
    PaymentProcessor::makeRefund(&bt, 1000);

    // Test invalid PayPal (should fail validation)
    cout << "\n--- Testing Invalid PayPal ---" << endl;
    PayPal invalidPP("PayPal", "invalid-email", -100);
    PaymentProcessor::makePayment(&invalidPP, 100); // Should fail validation

    return 0;
}