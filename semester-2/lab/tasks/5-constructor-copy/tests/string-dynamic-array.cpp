#include <iostream>
#include <string>

class DynamicArray
{
public:
    DynamicArray()
    : mCapacity(1), mNumberOfElements(0)
    {
        mArray = new std::string[mCapacity];
    }

    DynamicArray(int size)
    : mCapacity(size), mNumberOfElements(0)
    {
        mArray = new std::string[mCapacity];
    }

    DynamicArray(const DynamicArray& array)
    : mCapacity(array.getCapacity()), mNumberOfElements(array.length())
    {
        mArray = new std::string[mCapacity];
        for (size_t i = 0; i < mCapacity; ++i)
        {
            mArray[i] = array.get(i);
        }
    }

    ~DynamicArray()
    {
        delete[] mArray;
    }

    void add(std::string element)
    {
        if (mNumberOfElements >= mCapacity)
        {
            expand();
        }

        mArray[mNumberOfElements++] = element;
    }

    std::string get(int index) const
    {
        if (index > mNumberOfElements)
        {
            std::string exception = std::to_string(index) + " index is out of bounds.";
            
            std::cout << exception;
            return std::string();
        }

        if (index < 0)
        {
            if (mNumberOfElements + index < 0)
            {
                std::string exception = std::to_string(index) + " index result in " + std::to_string(mNumberOfElements + index) + " which is out of bounds.\n";
                
                std::cout << exception;
                return std::string();
            }

            return mArray[mNumberOfElements + index];
        }

        return mArray[index];
    }

    int length() const
    {
        return mNumberOfElements;
    }

    int getCapacity() const
    {
        return mCapacity;
    }
private:
    int mCapacity;
    int mNumberOfElements;
    std::string* mArray;

    void initialize(int from)
    {
        for (size_t i = from; i < mCapacity; ++i)
        {
            mArray[i] = std::string();
        }
    }

    void expand()
    {
        mCapacity *= 2;
        std::string* temporaryArray = new std::string[mCapacity];

        for (size_t i = 0; i < mNumberOfElements; ++i)
        {
            temporaryArray[i] = mArray[i];
        }

        delete[] mArray;

        mArray = temporaryArray;

        initialize(mNumberOfElements);
    }
};

int main()
{
    DynamicArray strings;
    strings.add("Hello");
    strings.add("World");

    std::cout << strings.get(-1) << std::endl;

    for (size_t i = 0; i < strings.length(); ++i)
    {
        std::cout << strings.get(i) << std::endl;
    }
}
