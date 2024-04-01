#include "AccountPrivate.h"

AccountPrivate::AccountPrivate() : accNumber(0), interest(0.0), name(""), sum(0) {}

AccountPrivate::AccountPrivate(std::string name, int accNumber, double interest, Money sum)
        : name(name), accNumber(accNumber), interest(interest), sum(sum) {}

AccountPrivate::AccountPrivate(const AccountPrivate &other)
        : name(other.name), accNumber(other.accNumber), interest(other.interest), sum(other.sum) {}

void AccountPrivate::read()
{
    std::cout << "Name: ";
    cin >> this->name;
    std::cout << "Acc#: ";
    cin >> this->accNumber;
    std::cout << "Interest: ";
    cin >> this->interest;
    std::cout << "Sum:\n";
    this->sum.read();
}

void AccountPrivate::init(std::string name, int accNumber, double interest, Money sum)
{
    this->name = name;
    this->accNumber = accNumber;
    this->interest = interest;
    this->sum = sum;
}

void AccountPrivate::display() const
{
    std::cout << this->toString() << std::endl;
}

std::string AccountPrivate::toString() const
{
    std::string result;

    const auto sum = this->sum;
    const auto usd = this->toDollars();
    const auto eur = this->toEuro();

    result += "#" + std::to_string(this->accNumber) + '\n';
    result += "Name: " + this->name + '\n';
    result += "Interest: " + std::to_string(this->interest) + '\n';

    result += "Sum: " + this->sum.toString() +
              " (" + this->numberToWords(sum.getBanknote()) + "hryvnias " +
              this->numberToWords(sum.getCoin()) + "kopiikas" + ")\n";

    result += "USD: " + usd.toString() +
              " (" + this->numberToWords(usd.getBanknote()) + "dollars " +
              this->numberToWords(usd.getCoin()) + "cents" + ")\n";

    result += "EUR: " + eur.toString() +
              " (" + this->numberToWords(eur.getBanknote()) + "euros " +
              this->numberToWords(eur.getCoin()) + "cents" + ")\n";

    return result;
}

void AccountPrivate::changeOwner(std::string name)
{
    this->name = name;
}

void AccountPrivate::withdraw(Money amount)
{
    this->sum = this->sum - amount;
}

void AccountPrivate::deposit(Money amount)
{
    this->sum = this->sum + amount;
}

void AccountPrivate::accrual()
{
    this->sum = this->sum + (this->sum * (this->interest / 100));
}

Money AccountPrivate::toDollars() const
{
    Money sum = this->sum;
    const double COURSE = 0.026;

    return sum * COURSE;
}

Money AccountPrivate::toEuro() const
{
    Money sum = this->sum;
    const double COURSE = 0.024;

    return sum * COURSE;
}

std::string AccountPrivate::numberToWords(int number) const
{
    if (number == 0)
        return "zero ";

    std::vector<std::string> units = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    std::vector<std::string> teens = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    std::vector<std::string> tens = {"", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
    std::vector<std::string> hundreds = {"", "one hundred", "two hundred", "three hundred", "four hundred", "five hundred", "six hundred", "seven hundred", "eight hundred", "nine hundred"};

    std::string word = "";

    if (number >= 1000 && number <= 9999)
    {
        int thousands = number / 1000;
        word += units[thousands] + " thousand ";
        number %= 1000;
    }

    if (number >= 100)
    {
        int hundred = number / 100;
        word += hundreds[hundred] + " ";
        number %= 100;
    }

    if (number >= 20)
    {
        int ten = number / 10;
        word += tens[ten] + " ";
        number %= 10;
    }
    else if (number >= 10 && number <= 19)
    {
        return word + teens[number - 10] + " ";
    }

    if (number > 0)
    {
        word += units[number] + " ";
    }

    return word;
}

int AccountPrivate::getAccNumber() const {
    return accNumber;
}

void AccountPrivate::setAccNumber(int accNumber) {
    AccountPrivate::accNumber = accNumber;
}

double AccountPrivate::getInterest() const {
    return interest;
}

void AccountPrivate::setInterest(double interest) {
    AccountPrivate::interest = interest;
}

const string &AccountPrivate::getName() const {
    return name;
}

void AccountPrivate::setName(const string &name) {
    AccountPrivate::name = name;
}

const Money &AccountPrivate::getSum() const {
    return sum;
}

void AccountPrivate::setSum(const Money &sum) {
    AccountPrivate::sum = sum;
}

AccountPrivate& AccountPrivate::operator=(const AccountPrivate &other) {
    if (this != &other) {
        name = other.name;
        accNumber = other.accNumber;
        interest = other.interest;
        sum = other.sum;
    }
    return *this;
}

std::istream& operator>>(std::istream& is, AccountPrivate& acc) {
    std::cout << "Name: ";
    is >> acc.name;
    std::cout << "Acc#: ";
    is >> acc.accNumber;
    std::cout << "Interest: ";
    is >> acc.interest;
    return is;
}

std::ostream& operator<<(std::ostream& os, const AccountPrivate& acc) {
    os << acc.toString();
    return os;
}

AccountPrivate::operator std::string() const {
    return toString();
}

AccountPrivate& AccountPrivate::operator++() {
    ++accNumber;
    return *this;
}

AccountPrivate AccountPrivate::operator++(int) {
    AccountPrivate temp(*this);
    operator++();
    return temp;
}

AccountPrivate& AccountPrivate::operator--() {
    --accNumber;
    return *this;
}

AccountPrivate AccountPrivate::operator--(int) {
    AccountPrivate temp(*this);
    operator--();
    return temp;
}