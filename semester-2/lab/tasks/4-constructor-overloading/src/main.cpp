#include <iostream>
#include <cctype>

class Passport
{
private:
	std::string mFirstLine;
	std::string mLastLine;

	std::string mFirstName;
	std::string mLastName;
	std::string mFullName;
	std::string mIssuingCountry;
	char mFirstDigit;
	char mPassportType;

	std::string mPassportNumber;
	std::string mNationality;
	char mGender;
	std::string mBirthDate;
	std::string mExpiryDate;

	std::string mIssuingDate;
	std::string mCitizenNumber;

	bool mDisplayFlag = true;

	enum mErrors
	{
		ePassed,
		eInvalidCharacters,
	};

public:
	Passport()
	{
		mCitizenNumber = "*****-*******-*";
	}
	Passport(std::string, std::string);
	Passport(char, const char *, const char *);

	void mSetMachineReadableCode()
	{
		std::string firstLine;
		std::string lastLine;

		bool error;

		do
		{
			error = false;
			std::cout << "Please enter first line located at the bottom of your passport: ";
			std::getline(std::cin, firstLine);

			if (firstLine.length() > 44 || firstLine.length() < 44)
			{
				std::cout << "First line consists of 44 digits, your line is " << firstLine.length() << " characters long, please try again!\n";
				error = true;
			}

			if (error)
				continue;
			else
				break;

		} while (true);

		mSetFirstLine(firstLine);

		do
		{
			error = false;
			std::cout << "Please enter second line located at the bottom of your passport: ";
			std::getline(std::cin, lastLine);

			if (lastLine.length() > 44 || lastLine.length() < 44)
			{
				std::cout << "Last line consists of 44 digits, your line is " << lastLine.length() << " characters long, please try again!\n";
				error = true;
			}

			if (error)
				continue;
			else
				break;

		} while (true);

		mSetLastLine(lastLine);
	}

	void mSetFirstLine(std::string firstLine)
	{
		mFirstLine = firstLine;
	}

	void mSetLastLine(std::string lastLine)
	{
		mLastLine = lastLine;
	}

	void mProcessFirstLine()
	{
		int checkedResult = checkFirstDigit(mFirstLine[0]);
		if (checkedResult == eInvalidCharacters)
		{
			std::cout << "Incorrect First Digit, only alphabets are allowed.\n";
		}
		else
		{
			mFirstDigit = mFirstLine[0];
		}

		checkedResult = checkPassportType(mFirstLine[1]);
		if (checkedResult == eInvalidCharacters)
		{
			std::cout << "Incorrect Passport type, only alphabets or '<' character allowed.\n";
		}
		else
		{
			mPassportType = mFirstLine[1];
		}

		checkedResult = checkIssuingCountry();
		if (checkedResult == eInvalidCharacters)
		{
			std::cout << "Invalid country, Only alphabets are allowed!\n";
		}
		else
		{
			mIssuingCountry = mFirstLine.substr(2, 3);
		}

		checkedResult = checkSurName();
		if (checkedResult == eInvalidCharacters)
		{
			std::cout << "Invalid sur name, Only alphabets are allowed!\n";
		}
	}

	int checkFirstDigit(char firstIndex)
	{
		if (!isalpha(firstIndex))
		{
			mDisplayFlag = false;
			return eInvalidCharacters;
		}

		return ePassed;
	}

	int checkPassportType(char type)
	{
		if (!isalpha(type) && type != '<')
		{
			mDisplayFlag = false;
			return eInvalidCharacters;
		}

		return ePassed;
	}

	int checkIssuingCountry()
	{
		for (int i = 2; i < 5; ++i)
		{
			if (!isalpha(mFirstLine[i]) && mFirstLine[i] != '<')
			{
				mDisplayFlag = false;
				return eInvalidCharacters;
			}
		}

		return ePassed;
	}

	int checkSurName()
	{
		int length = 0;
		for (int i = 5; i < 44; ++i)
		{
			if (mFirstLine[i] == '<' && mFirstLine[i + 1] == '<')
			{
				break;
			}

			if (!isalpha(mFirstLine[i]))
			{
				mDisplayFlag = false;
				return eInvalidCharacters;
			}

			++length;
		}

		mLastName = mFirstLine.substr(5, length);
		return ePassed;
	}

	void mDisplay()
	{
		if (mDisplayFlag)
		{
			std::cout << "Your details\n"
					  << "Passport Type: " << mFirstDigit << std::endl
					  << "Issuing Country: " << mIssuingCountry << std::endl;
		}
	}
};

int main()
{
	char userInput;
	do
	{
		Passport passport;
		passport.mSetMachineReadableCode();
		passport.mProcessFirstLine();
		passport.mDisplay();

		std::cout << "Would you like to run the program again? [Y]es / [N]o\n";
		std::cin >> userInput;
	} while (toupper(userInput) == 'Y');
}
