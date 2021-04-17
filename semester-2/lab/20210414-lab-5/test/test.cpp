#include <iostream>
#include <string>

using namespace std;

class English
{
private:
    string sentence;
    int size;

public:
    English()
    {
        cout << "Enter sentence: ";
        getline(cin, sentence);
        size = sentence.length();
    }

    English(English& object)
    {
        sentence = object.get_sentence();
        size = object.get_size();
    }

    string get_sentence()
    {
        return sentence;
    }

    unsigned int get_size()
    {
        return size;
    }

    void show_members()
    {
        cout << "Sentence = " << sentence << endl;
        cout << "Size = " << size << endl;
    }
};

int main()
{
    English english1;
    english1.show_members();

    English english2 = english1;
    english2.show_members();
}
