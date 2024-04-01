#pragma one
#include <string>
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class Money
{
private:
    long banknote;
    unsigned char coin;
public:
    Money();
    Money(double amount);
    Money(const Money &other);
    const long getBanknote() const;
    const long getCoin() const;
    void init(long banknote, unsigned char coin);
    void init(long long coin);
    void read();
    void display() const;
    std::string toString() const;
    void setBanknote(long banknote);
    void setCoin(unsigned char coin);
    Money add(Money money);
    Money add(int coin);
    Money minus(Money money);
    Money minus(int coin);
    double div(const Money& divider);
    Money div(double divider);
    Money mul(double times);
    bool isEqual(Money money);
    bool isNotEqual(Money money);
    bool isGreatThan(Money money);
    bool isLessThen(Money money);
    bool isGreaterThanOrEqual(Money money);
    bool isLessThanOrEqual(Money money);

    Money& operator=(const Money& other);
    friend Money operator+(const Money& money1, const Money& money2);
    friend Money operator+(const Money& money, int coin);
    friend Money operator+(int coin, const Money& money);
    friend Money operator-(const Money& money1, const Money& money2);
    friend Money operator-(const Money& money, int coin);
    friend Money operator-(int coin, const Money& money);
    friend double operator/(const Money& money1, const Money& money2);
    friend Money operator/(const Money& money, double divider);
    friend Money operator*(const Money& money, double times);
    friend Money operator*(double times, const Money& money);
    friend bool operator==(const Money& money1, const Money& money2);
    friend bool operator!=(const Money& money1, const Money& money2);
    friend bool operator>(const Money& money1, const Money& money2);
    friend bool operator<(const Money& money1, const Money& money2);
    friend bool operator>=(const Money& money1, const Money& money2);
    friend bool operator<=(const Money& money1, const Money& money2);
    friend std::istream& operator>>(std::istream& input, Money& money);
    friend std::ostream& operator<<(std::ostream& output, const Money& money);
    operator std::string() const;
};
