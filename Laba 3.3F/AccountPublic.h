#include "Money.h"

class AccountPublic : public Money{
public:
    AccountPublic();
    AccountPublic(string name, int accNumber, double interest, Money sum);
    AccountPublic(const AccountPublic &other);

    void read();
    void init(std::string name, int accNumber, double interest, Money sum);
    void display() const;
    std::string toString() const;
    void changeOwner(std::string name);
    void withdraw(Money amount);
    void deposit(Money amount);
    void accrual();
    Money toDollars() const;
    Money toEuro() const;
    std::string numberToWords(int number) const;

    AccountPublic& operator=(const AccountPublic &other);
    friend istream& operator>>(istream& is, AccountPublic& acc);
    friend ostream& operator<<(ostream& output, const AccountPublic& acc);
    operator string() const;
    AccountPublic& operator++();
    AccountPublic operator++(int);
    AccountPublic& operator--();
    AccountPublic operator--(int);

public:
    int getAccNumber() const;
    void setAccNumber(int accNumber);
    double getInterest() const;
    void setInterest(double interest);
    const string &getName() const;
    void setName(const string &name);
    const Money &getSum() const;
    void setSum(const Money &sum);

private:
    int accNumber;
    double interest;
    string name;
    Money sum;
};