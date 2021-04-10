#include <iostream>
#include <string>

class PopSalon
{
private:
    int mTotalPrice;
    std::string mFlavor;
    std::string mSize;
    std::string mTopping;
    bool mWrapper;

    struct User
    {
        std::string name;
        std::string number;
        std::string email;
        int rating;
    } mUser;

public:
    PopSalon()
    : mTotalPrice(0), mWrapper(false)
    {
        std::cout << "Welcome to Pop Salon\n";
    }


    void mSetTotalPrice(int totalPrice)
    {
        mTotalPrice = totalPrice;
    }

    void mSetFlavor(std::string flavor)
    {
        mFlavor = flavor;
    }

    void mSetSize(std::string size)
    {
        mSize = size;
    }

    void mSetTopping(std::string topping)
    {
        mTopping = topping;
    }

    void mSetGiftWrapper(bool wrapper)
    {
        mWrapper = wrapper;
    }


    int mGetTotalPrice()
    {
        return mTotalPrice;
    }

    std::string mGetFlavor()
    {
        return mFlavor;
    }

    std::string mGetSize()
    {
        return mSize;
    }

    bool mGetGiftWrapper()
    {
        return mWrapper;
    }


    void mAddToTotal(double money)
    {
        mTotalPrice += money;
    }

    void mAddGiftWrapper()
    {
        char userInput;
        std::cout << "Do you want to add gift wrapper for an additional charge of Rs50?\n"
                  << "Y for yes, Any other key for no\n"
                  << "[Your Choice]: ";
        std::cin >> userInput;

        if (toupper(userInput) == 'Y')
        {
            mAddToTotal(50);
            mWrapper = true;
        }

        std::cout << std::endl;
    }


    bool mCheckSize(int option)
    {
        switch (option)
        {
            // Small size
            case 1:
                mAddToTotal(100);
                mSetSize("Small");
                break;

            // Medium size
            case 2:
                mAddToTotal(250);
                mSetSize("Medium");
                break;

            // Large size
            case 3:
                mAddToTotal(500);
                mSetSize("Large");
                break;

            // Extra Large size
            case 4:
                mAddToTotal(750);
                mSetSize("Extra Large");
                break;

            // Incorrect option
            default: return false;
        }
        return true;
    }

    bool mCheckFlavor(int option)
    {
        switch (option)
        {
            case 1:
                mSetFlavor("Chocolate");
                break;

            case 2:
                mSetFlavor("English Toffee");
                break;

            case 3:
                mSetFlavor("Salted Caramel");
                break;

            case 4:
                mSetFlavor("Caramel");
                break;

            case 5:
                mSetFlavor("Jalapeno");
                break;

            case 6:
                mSetFlavor("Cheese");
                break;

            case 7:
                mSetFlavor("Spiced Cheese");
                break;

            case 8:
                mSetFlavor("Plain Salted");
                break;

            case 9:
                mSetFlavor("Buttered");
                break;

            case 10:
                mSetFlavor("Salt and Pepper");
                break;

            case 11:
                mSetFlavor("Garlic");
                break;

            // Incorrect option
            default: return false;
        }
        return true;
    }

    bool mCheckTopping(int option)
    {
        switch (option)
        {
            // Chocolate
            case 1:
                mAddToTotal(50);
                mSetTopping("Chocolate");
                break;

            // Caramel
            case 2:
                mAddToTotal(30);
                mSetTopping("Caramel");
                break;

            // Melted Cheese
            case 3:
                mAddToTotal(60);
                mSetTopping("Melted Cheese");
                break;

            // No topping
            case 4:
                mSetTopping("No topping");
                break;

            // Incorrect option
            default: return false;
        }
        return true;
    }


    void mSizeMenu()
    {
        std::cout << "Size Menu\n"
                  << "Choose your size\n"
                  << "1) Small\tRs100\n"
                  << "2) Medium\tRs250\n"
                  << "3) Large\tRs500\n"
                  << "4) Extra Large\tRs750\n"
                  << "[Your Choice]: ";
    }

    void mFlavorMenu()
    {
        std::cout << "Flavor Menu\n"
                  << "Choose your flavor\n"
                  << "1)  Chocolate\n"
                  << "2)  English Toffee\n"
                  << "3)  Salted Caramel\n"
                  << "4)  Caramel\n"
                  << "5)  Jalapeno\n"
                  << "6)  Cheese\n"
                  << "7)  Spiced Cheese\n"
                  << "8)  Plain Salted\n"
                  << "9)  Buttered\n"
                  << "10) Salt and Pepper\n"
                  << "11) Garlic\n"
                  << "[Your Choice]: ";
    }

    void mToppingMenu()
    {
        std::cout << "Topping Menu\n"
                  << "Choose your topping\n"
                  << "1) Chocolate\t Rs50\n"
                  << "2) Caramel\t Rs30\n"
                  << "3) Melted Cheese Rs60\n"
                  << "4) No topping\n"
                  << "[Your Choice]: ";
    }


    void mDisplayReceipt()
    {
        std::cout << "Receipt\n"
                  << "Flavor: " << mFlavor << std::endl
                  << "Size: " << mSize << std::endl
                  << "Topping: " << mTopping << std::endl
                  << "Gift Wrapping: ";

        if (mWrapper) std::cout << "Yes\n";
        else          std::cout << "No\n";

        std::cout << "Total Bill: " << mTotalPrice << std::endl << std::endl;
    }

    void mMonthlyPromotion()
    {
        bool loop = true;

        std::cin.ignore();
        std::cout << "Service Quality Assurance Survey\n";
        std::cout << "Enter your name: ";
        std::getline(std::cin, mUser.name);
        std::cout << "Enter your number: ";
        std::getline(std::cin, mUser.number);
        std::cout << "Enter your email: ";
        std::getline(std::cin, mUser.email);

        while (loop)
        {
            std::cout << "Rating\n"
                      << "1) Great\n"
                      << "2) Fair\n"
                      << "3) Neutral\n"
                      << "4) Poor\n"
                      << "5) Worst\n"
                      << "[Your Choice]: ";
            std::cin >> mUser.rating;

            if (mUser.rating >= 1 && mUser.rating <= 5)
            {
                std::cout << std::endl;
                return;
            }

            std::cout << "Invalid option, please try again.\n";
        }
    }


    ~PopSalon()
    {
        std::cout << "\nWe hope you enjoy your meal!\n";
    }
};


int main()
{
    PopSalon vendor;
    bool programLoop = true;
    int userInput;
    do
    {
        while (true)
        {
            vendor.mSizeMenu();
            std::cin >> userInput;
            if (vendor.mCheckSize(userInput))
            {
                std::cout << std::endl;
                break;
            }
            else
            {
                std::cout << "Incorrect option, choose again\n";
            }
        }

        while (true)
        {
            vendor.mFlavorMenu();
            std::cin >> userInput;
            if (vendor.mCheckFlavor(userInput))
            {
                std::cout << std::endl;
                break;
            }
            else
            {
                std::cout << "Incorrect option, choose again\n";
            }
        }

        while (true)
        {
            vendor.mToppingMenu();
            std::cin >> userInput;
            if (vendor.mCheckTopping(userInput))
            {
                std::cout << std::endl;
                break;
            }
            else
            {
                std::cout << "Incorrect option, choose again\n";
            }
        }

        vendor.mAddGiftWrapper();

        vendor.mDisplayReceipt();

        vendor.mMonthlyPromotion();


        char reRunProgram;
        std::cout << "Would you like to run the program again?\n"
                  << "Y for yes, Any other key for no\n"
                  << "[Your Choice]: ";
        std::cin >> reRunProgram;
        std::cin.ignore();

        if (toupper(reRunProgram) != 'Y')
        {
            programLoop = false;
        }
        else
        {
            vendor.mSetTotalPrice(0);
            vendor.mSetGiftWrapper(false);
        }

    } while (programLoop);
}
