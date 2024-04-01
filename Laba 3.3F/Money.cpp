
#include "Money.h"

Money::Money()
{
    this->init(0, 0);
}

Money::Money(const Money &other)
        : banknote(other.banknote), coin(other.coin) {}

Money::Money(double amount)
{
    double intPart;
    double fracPart;

    fracPart = modf(amount, &intPart);

    this->init(intPart, fracPart * 100);
}

const long Money::getBanknote() const
{
    return this->banknote;
}

const long Money::getCoin() const
{
    return this->coin;
}

void Money::init(long hrn, unsigned char kop)
{
    this->banknote = hrn;
    this->coin = kop;
}

void Money::init(long long coin)
{
    this->init(coin / 100, coin % 100);
}

void Money::read()
{
    std::cout << "Hrn: ";
    std::cin >> this->banknote;
    std::cout << "Kop: ";
    std::cin >> (int &)this->coin;
}

void Money::display() const
{
    std::cout << this->toString() << std::endl;
}

std::string Money::toString() const
{
    std::string result;

    result = std::to_string(this->banknote) + '.' + std::to_string(this->coin);

    return result;
}

void Money::setBanknote(long hrn)
{
    this->banknote = hrn;
}

void Money::setCoin(unsigned char kop)
{
    this->coin = kop;
}

Money Money::add(Money money)
{
    int kop = money.banknote * 100 + money.coin;

    return this->add(kop);
}

Money Money::add(int coins)
{
    Money result;

    int coin = this->banknote * 100 + this->coin + coins;

    result.init(coin);

    return result;
}

Money Money::minus(Money money)
{
    int coin = money.banknote * 100 + money.coin;

    return this->minus(coin);
}

Money Money::minus(int c)
{
    Money result;
    int coin = (this->banknote * 100 + this->coin) - c;
    result.init(coin);

    return result;
}

double Money::div(const Money& divider)
{
    long long this_amount = this->banknote * 100 + this->coin;
    long long divider_amount = divider.banknote * 100 + divider.coin;

    if (divider_amount == 0) {
        return 0.0;
    }

    double divided_amount = static_cast<double>(this_amount) / static_cast<double>(divider_amount);

    return divided_amount;
}


Money Money::div(double divider)
{
    Money result;
    double coin = (this->banknote * 100 + this->coin) / divider;
    result.init((long long)coin);

    return result;
}

Money Money::mul(double times)
{
    Money result;
    double coin = (this->banknote * 100 + this->coin) * times;

    result.init((long long)coin);

    return result;
}

bool Money::isEqual(Money money) {
    return this->banknote == money.banknote && this->coin == money.coin;
}

bool Money::isNotEqual(Money money) {
    return this->banknote != money.banknote || this->coin != money.coin;
}

bool Money::isGreatThan(Money money) {
    return this->banknote > money.banknote || (this->banknote == money.banknote && this->coin > money.coin);
}

bool Money::isLessThen(Money money) {
    return this->banknote < money.banknote || (this->banknote == money.banknote && this->coin < money.coin);
}

bool Money::isGreaterThanOrEqual(Money money) {
    return this->isGreatThan(money) || this->isEqual(money);
}

bool Money::isLessThanOrEqual(Money money) {
    return this->isLessThen(money) || this->isEqual(money);
}

Money& Money::operator=(const Money& other) {
    if (this != &other) {
        banknote = other.banknote;
        coin = other.coin;
    }
    return *this;
}

std::istream& operator>>(std::istream& input, Money& money) {
    input >> money.banknote;
    return input;
}

std::ostream& operator<<(std::ostream& output, const Money& money) {
    output << money.banknote;
    return output;
}

Money operator+(const Money& money1, const Money& money2) {
    Money result;
    int totalCents = money1.banknote * 100 + money1.coin + money2.banknote * 100 + money2.coin;
    result.init(totalCents / 100, totalCents % 100);
    return result;
}

Money operator+(const Money& money, int coin) {
    Money result;
    int totalCents = money.banknote * 100 + money.coin + coin;
    result.init(totalCents / 100, totalCents % 100);
    return result;
}

Money operator+(int coin, const Money& money) {
    return money + coin;
}

Money operator-(const Money& money1, const Money& money2) {
    Money result;
    int totalCents = money1.banknote * 100 + money1.coin - (money2.banknote * 100 + money2.coin);
    result.init(totalCents / 100, totalCents % 100);
    return result;
}

Money operator-(const Money& money, int coin) {
    Money result;
    int totalCents = money.banknote * 100 + money.coin - coin;
    result.init(totalCents / 100, totalCents % 100);
    return result;
}

Money operator-(int coin, const Money& money) {
    return money - coin;
}

double operator/(const Money& money1, const Money& money2) {
    double result = static_cast<double>(money1.banknote * 100 + money1.coin) / (money2.banknote * 100 + money2.coin);
    return result;
}

Money operator/(const Money& money, double divider) {
    double result = static_cast<double>(money.banknote * 100 + money.coin) / divider;
    return Money(result);
}

Money operator*(const Money& money, double times) {
    double result = static_cast<double>(money.banknote * 100 + money.coin) * times;
    return Money(result);
}

Money operator*(double times, const Money& money) {
    return money * times;
}

bool operator==(const Money& money1, const Money& money2) {
    return money1.banknote == money2.banknote && money1.coin == money2.coin;
}

bool operator!=(const Money& money1, const Money& money2) {
    return !(money1 == money2);
}

bool operator>(const Money& money1, const Money& money2) {
    int totalCents1 = money1.banknote * 100 + money1.coin;
    int totalCents2 = money2.banknote * 100 + money2.coin;
    return totalCents1 > totalCents2;
}

bool operator<(const Money& money1, const Money& money2) {
    return money2 > money1;
}

bool operator>=(const Money& money1, const Money& money2) {
    return !(money1 < money2);
}

bool operator<=(const Money& money1, const Money& money2) {
    return !(money1 > money2);
}
