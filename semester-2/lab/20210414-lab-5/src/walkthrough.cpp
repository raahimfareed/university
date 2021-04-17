#include <iostream>
#include <string>

class English
{
private:
    std::string mSentence;
    unsigned int mSize;

public:
    English(std::string sentence)
    : mSentence(sentence)
    {
        mSize = sentence.length();
    }

    English(const English& e)
    {
        mSentence = e.getSentence();
        mSize = e.getSize();
    }

    std::string getSentence() const
    {
        return mSentence;
    }

    unsigned int getSize() const
    {
        return mSize;
    }

    void display()
    {
        std::cout << "Sentence: " << mSentence << std::endl
                  << "Length: " << mSize << std::endl;
    }
};

int main()
{
    English shakespear("Yada yada yada");
    shakespear.display();

    English fox = shakespear;
    fox.display();

    std::cin.get();
}
