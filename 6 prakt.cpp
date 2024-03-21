#include <iostream>
class BankAccount {
private:
    int accountNumber; // Номер банковского счета
    double balance; // Баланс
    double interestRate; // Процентная ставка

public:
    // Конструктор с параметрами номера счета и начального баланса
    BankAccount(int accNumber, double bal) : accountNumber(accNumber), balance(bal), interestRate(0.0) {}

    // Внести средства на счет
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            std::cout << "Средства успешно зачислены." << std::endl;
        }
        else {
            std::cout << "Ошибка: введена некорректная сумма." << std::endl;
        }
    }

    // Снять средства со счета
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            std::cout << "Средства успешно списаны." << std::endl;
        }
        else {
            std::cout << "Ошибка: недостаточно средств на счете или введена некорректная сумма." << std::endl;
        }
    }

    // Получить текущий баланс
    double getBalance() {
        return balance;
    }

    // Рассчитать и вернуть проценты
    double getInterest() {
        return balance * interestRate * (1 / 12);
    }

    // Обновить процентную ставку
    void setInterestRate(double rate) {
        this->interestRate = rate; //   ключевое слово this для доступа к члену класса
        std::cout << "Процентная ставка обновлена." << std::endl;
    }

    int getAccountNumber() {
        return accountNumber;
    }

    static bool transfer(BankAccount& account1, BankAccount& account2, double amount) {
        if (amount > 0 && account1.getBalance() >= amount) {
            account1.withdraw(amount);
            account2.deposit(amount);
            std::cout << "Перевод успешно выполнен." << std::endl;
            return true;
        }
        else {
            std::cout << "Ошибка: недостаточно средств для перевода или введена некорректная сумма." << std::endl;
            return false;
        }
    }
};

int main() {
    BankAccount account1(12345, 1000.0);
    BankAccount account2(54321, 500.0);

    int choice;
    double amount;

    do {
        std::cout << "Меню:" << std::endl;
        std::cout << "1. Пополнить баланс на счете 1" << std::endl;
        std::cout << "2. Пополнить баланс на счете 2" << std::endl;
        std::cout << "3. Перевести средства между счетами" << std::endl;
        std::cout << "4. Выйти из меню" << std::endl;
        std::cout << "Выберите действие: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Введите сумму для пополнения на счете 1: ";
            std::cin >> amount;
            account1.deposit(amount);
            break;
        case 2:
            std::cout << "Введите сумму для пополнения на счете 2: ";
            std::cin >> amount;
            account2.deposit(amount);
            break;
        case 3:
            std::cout << "Введите сумму для перевода: ";
            std::cin >> amount;
            BankAccount::transfer(account1, account2, amount);
            break;
        case 4:
            std::cout << "Выход из меню." << std::endl;
            break;
        default:
            std::cout << "Ошибка: введено некорректное действие." << std::endl;
            break;
        }
    } while (choice != 4);

    return 0;
}
