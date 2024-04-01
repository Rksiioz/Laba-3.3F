#include "AccountPublic.h"

class AccountPrivate : private Money{
public:
    AccountPrivate();
    AccountPrivate(string name, int accNumber, double interest, Money sum);
    AccountPrivate(const AccountPrivate &other);

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

    AccountPrivate& operator=(const AccountPrivate &other);
    friend istream& operator>>(istream& is, AccountPrivate& acc);
    friend ostream& operator<<(ostream& output, const AccountPrivate& acc);
    operator string() const;
    AccountPrivate& operator++();
    AccountPrivate operator++(int);
    AccountPrivate& operator--();
    AccountPrivate operator--(int);

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