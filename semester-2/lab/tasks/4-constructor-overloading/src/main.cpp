// P<PAKANWAR<<SHAHAB<<<<<<<<<<<<<<<<<<<<<<<<<<
// AD17924316PAK7604119M09112564250115662437<04

#include <iostream>
#include <cctype>
#include <algorithm>
#include <string>

const char * months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};


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

	Passport(std::string firstName, std::string secondName)
	{
		mFullName = firstName + ' ' + secondName;
	}

	Passport(char gender, std::string nationality, std::string passportNumber)
	{
		mGender = gender;
		mNationality = nationality;
		mPassportNumber = passportNumber;
	}

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

			if (firstLine.length() != 44)
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

			if (lastLine.length() != 44)
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
		if (mCheckPassportNumber() == eInvalidCharacters)
		{
			std::cout << "Invalid Passport Number, It can only consist of Alphanumeric characters.\n";
		}
		else
		{
			mPassportNumber = mLastLine.substr(0, 9);
		}

		if (mCheckNationality() == eInvalidCharacters)
		{
			std::cout << "Invalid Nationality, Please enter valid nationality.\n";
		}
		else
		{
			mNationality = mLastLine.substr(10, 3);
		}
	
		if (mCheckBirthDate() == eInvalidCharacters)
		{
			std::cout << "Your birthdate should be in the format YYMMDD. Digits only.\n";
		}
		else
		{
			int dobYear = std::stoi(mLastLine.substr(13, 2));
			if (dobYear > 30)
			{
				dobYear += 1900;
			}
			else
			{
				dobYear += 2000;
			}

			int month = std::stoi(mLastLine.substr(15, 2));
			mBirthDate = mLastLine.substr(17, 2) + ' ' + months[month - 1] + ' ' + std::to_string(dobYear);
		}

		if (mCheckGender() == eInvalidCharacters)
		{
			std::cout << "Invalid gender. Can only contain alphabets.\n";
		}
		else
		{
			mGender = mLastLine[20];
		}
			
		if (mCheckExpirationDate() == eInvalidCharacters)
		{
			std::cout << "Expiration date should be in the format YYMMDD. Digits only.\n";
		}
		else
		{
			int year = std::stoi(mLastLine.substr(21, 2));
			if (year > 30)
			{
				year += 1900;
			}
			else
			{
				year += 2000;
			}

			int month = std::stoi(mLastLine.substr(23, 2));
			mExpiryDate = mLastLine.substr(25, 2) + ' ' + months[month - 1] + ' ' + std::to_string(year);
		}
	
		if (mCheckCitizenNumber() == eInvalidCharacters)
		{
			std::cout << "Your citizen number contains invalid characters. Can only contain alphabets or numbers\n";
		}
		else
		{
			mCitizenNumber = mLastLine.substr(28, 13);
		}
	}

	int mCheckPassportNumber()
	{
		for (int i = 0; i < 9; ++i)
		{
			if (!isalnum(mLastLine[i]))
			{
				mDisplayFlag = false;
				return eInvalidCharacters;
			}
		}

		return ePassed;
	}

	int mCheckNationality()
	{
		for (int i = 10; i < 13; ++i)
		{
			if (!isalpha(mLastLine[i]))
			{
				mDisplayFlag = false;
				return eInvalidCharacters;
			}
		}

		return ePassed;
	}

	int mCheckBirthDate()
	{
		for (int i = 13; i < 19; ++i)
		{
			if (!isdigit(mLastLine[i]))
			{
				mDisplayFlag = false;
				return eInvalidCharacters;
			}
		}

		return ePassed;
	}

	int mCheckGender()
	{
		if (!isalpha(mLastLine[20]))
		{
			mDisplayFlag = false;
			return eInvalidCharacters;
		}

		return ePassed;
	}

	int mCheckExpirationDate()
	{
		for (int i = 21; i < 27; ++i)
		{
			if (!isdigit(mLastLine[i]))
			{
				mDisplayFlag = false;
				return eInvalidCharacters;
			}
		}

		return ePassed;
	}

	int mCheckCitizenNumber()
	{
		for (int i = 28; i < 42; ++i)
		{
			if (!isalnum(mLastLine[i]) && mLastLine[i] != '<')
			{
				mDisplayFlag = false;
				return eInvalidCharacters;
			}
		}

		return ePassed;
	}


	void mDisplay()
	{
		if (mDisplayFlag)
		{
			std::cout << "Your details\n"
					  << "Passport Type: " << mFirstDigit << std::endl
					  << "Issuing Country: " << mIssuingCountry << std::endl
					  << "First Name: " << mFirstName << std::endl
					  << "Sur Name: " << mLastName << std::endl
					  << "Passport Number: " << mPassportNumber << std::endl
					  << "Nationality: " << mNationality << std::endl
					  << "Date of Birth: " << mBirthDate << std::endl
					  << "Gender: " << mGender << std::endl
					  << "Expiration Date: " << mExpiryDate << std::endl
					  << "Citizen Number: " << mCitizenNumber << std::endl;
		}
	}
};

int main()
{
	char userInput;
	do
	{
		std::cout << "\nPassport One\n";
		Passport passport1;
		passport1.mSetMachineReadableCode();
		passport1.mProcessFirstLine();
		passport1.mProcessLastLine();
		passport1.mDisplay();

		std::cout << "\nPassport Two\n";
		Passport passport2("Raahim", "Fareed");
		passport2.mSetMachineReadableCode();
		passport2.mProcessFirstLine();
		passport2.mProcessLastLine();
		passport2.mDisplay();

		std::cout << "\nPassport Three\n";
		Passport passport3('F', "IND", "FE9018374");
		passport3.mSetMachineReadableCode();
		passport3.mProcessFirstLine();
		passport3.mProcessLastLine();
		passport3.mDisplay();

		std::cout << "Would you like to run the program again? [Y]es / [N]o\n";
		std::cin >> userInput;
	} while (toupper(userInput) == 'Y');
}
