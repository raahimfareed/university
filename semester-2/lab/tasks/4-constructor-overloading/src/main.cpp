// P<PAKANWAR<<SHAHAB<<<<<<<<<<<<<<<<<<<<<<<<<<
#include <iostream>
#include <cctype>
#include <algorithm>

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
		int checkedResult = mCheckFirstDigit(mFirstLine[0]);
		if (checkedResult == eInvalidCharacters)
		{
			std::cout << "Incorrect First Digit, only alphabets are allowed.\n";
		}
		else
		{
			mFirstDigit = mFirstLine[0];
		}

		checkedResult = mCheckPassportType(mFirstLine[1]);
		if (checkedResult == eInvalidCharacters)
		{
			std::cout << "Incorrect Passport type, only alphabets or '<' character allowed.\n";
		}
		else
		{
			mPassportType = mFirstLine[1];
		}

		checkedResult = mCheckIssuingCountry();
		if (checkedResult == eInvalidCharacters)
		{
			std::cout << "Invalid country, Only alphabets are allowed!\n";
		}
		else
		{
			mIssuingCountry = mFirstLine.substr(2, 3);
		}

		checkedResult = mCheckSurName();
		if (checkedResult == eInvalidCharacters)
		{
			std::cout << "Invalid sur name, Only alphabets are allowed!\n";
		}

		checkedResult = mCheckFirstName();
		if (checkedResult == eInvalidCharacters)
		{
			std::cout << "Invalid first name, Only alphabets are allowed!\n";
		}
	}

	int mCheckFirstDigit(char firstIndex)
	{
		if (!isalpha(firstIndex))
		{
			mDisplayFlag = false;
			return eInvalidCharacters;
		}

		return ePassed;
	}

	int mCheckPassportType(char type)
	{
		if (!isalpha(type) && type != '<')
		{
			mDisplayFlag = false;
			return eInvalidCharacters;
		}

		return ePassed;
	}

	int mCheckIssuingCountry()
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

	int mCheckSurName()
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

	int mCheckFirstName()
	{
		int starting_index;
		int length = 0;
		bool found = false;
		for (int i = 5; i < 44; ++i)
		{
			if (!found)
			{
				if (mFirstLine[i] == '<' && mFirstLine[i + 1] == '<')
				{
					found = true;
					starting_index = i + 1;
					std::cout << starting_index << std::endl;
					continue;
				}
			}

			if (found)
			{
				if (mFirstLine[i] == '<' && mFirstLine[i + 1] == '<')
				{
					break;
				}

				if (!isalpha(mFirstLine[i]) && mFirstLine[i] != '<')
				{
					mDisplayFlag = false;
					return eInvalidCharacters;
				}

				++length;
			}


		}

		mFirstName = mFirstLine.substr(starting_index, length);
		mFirstName.erase(std::remove(mFirstName.begin(), mFirstName.end(), '<'), mFirstName.end());
		return ePassed;
	}


	void mProcessLastLine()
	{
		int checkedResult;
	}


	void mDisplay()
	{
		if (mDisplayFlag)
		{
			std::cout << "Your details\n"
					  << "Passport Type: " << mFirstDigit << std::endl
					  << "Issuing Country: " << mIssuingCountry << std::endl
					  << "First Name: " << mFirstName << std::endl
					  << "Sur Name: " << mLastName << std::endl;
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
