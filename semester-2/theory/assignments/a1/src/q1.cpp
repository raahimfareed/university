#include <iostream>

class BankClient
{
private:
    std::string mClientName;
    std::string mAccountNumber;
    std::string mAccountType;
    double mBalance;
public:
    BankClient(std::string clientName, std::string accountNumber, std::string accountType, double balance)
    : mClientName(clientName), mAccountNumber(accountNumber), mAccountType(accountType), mBalance(balance)
    {}

    void mDepositMoney()
    {
        double deposit;
        while (true)
        {
            std::cout << "Enter the amount you need to desposit: ";
            std::cin >> deposit;
            if (deposit < 0)
            {
                std::cout << "Invalid amount\n";
            }
            else
            {
                break;
            }
        }
        mBalance += deposit;
        std::cout << deposit << " added into account.\nNew Balance: " << mBalance << std::endl;
    }

    void mWithdrawMoney()
    {
        double withdraw;

        while (true)
        {
            std::cout << "Enter the amount you need to withdraw: ";
            std::cin >> withdraw;

            if (mBalance - withdraw < 0)
            {
                std::cout << "Insufficient funds.\n";
            }
            else
            {
                break;
            }
        }

        mBalance -= withdraw;
        std::cout << withdraw << " withdrawn from account.\nNew Balance: " << mBalance << std::endl;
    }

    double mGetBalance() const
    {
        return mBalance;
    }
};

void menu();
void menuSelector(BankClient& client, const int input, bool& programLoop);

int main()
{
    bool loop = true;
    int userInput;
    BankClient clientOne("", "001", "Current", 500.0);
    BankClient clientTwo("", "002", "Current", 500.0);

    do
    {
        std::cout << "\nClient One\n";
        menu();
        std::cin >> userInput;
        menuSelector(clientOne, userInput, loop);
    } while (loop);


    loop = true;
    do
    {
        std::cout << "\nClient Two\n";
        menu();
        std::cin >> userInput;
        menuSelector(clientTwo, userInput, loop);
    } while (loop);

    std::cout << "\nClient Balance" << std::endl
              << "Client One: " << clientOne.mGetBalance() << std::endl
              << "Client Two: " << clientTwo.mGetBalance() << std::endl;

    std::cout << "Press [Enter] to exit the program.\n";
    std::cin.ignore();
    std::cin.get();
}

void menu()
{
    std::cout << "Menu\n"
              << "1. Deposit Money\n"
              << "2. Withdraw Money\n"
              << "3. Display Balance\n"
              << "4. Exit\n"
              << "[Your Choice]> ";
}

void menuSelector(BankClient& client, const int input, bool& loop)
{
    switch(input)
    {
        case 1:
            client.mDepositMoney();
            break;
        case 2:
            client.mWithdrawMoney();
            break;
        case 3:
            std::cout << "Your balance: " << client.mGetBalance() << std::endl;
            break;
        case 4:
            loop = false;
            break;
        default:
            std::cout << "Invalid option! Please try again.\n";
            break;
    }
}
