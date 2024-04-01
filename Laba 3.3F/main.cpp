#include "AccountPrivate.h"

int main() {
    AccountPublic acc;
    acc.init("Nazar", 22, 15, 20.35);
    acc.accrual();
    acc.display();
    acc.changeOwner("Bohdan");
    acc.withdraw(1.05);
    acc.display();
    Money m(10);
    acc.deposit((m / 0.5) / m);
    acc.display();
    std::cout << boolalpha << (m == Money(10)) << std::endl;
    std::cout << boolalpha << (m != Money(10)) << std::endl;
    std::cout << boolalpha << (m > Money(10)) << std::endl;
    std::cout << boolalpha << (m < Money(10)) << std::endl;
    std::cout << boolalpha << (m >= Money(10)) << std::endl;
    std::cout << boolalpha << (m <= Money(10)) << std::endl;

    return 0;
}