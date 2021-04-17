#include <iostream>

template <class Type>
class DynamicArray
{
public:
    DynamicArray()
    : mCapacity(1), mNumberOfElements(0)
    {
        mArray = new Type[mCapacity];
    }

    DynamicArray(int size)
    : mCapacity(size), mNumberOfElements(0)
    {
        mArray = new Type[mCapacity];
    }

    DynamicArray(const DynamicArray& array)
    {}

    ~DynamicArray()
    {
        delete[] mArray;
    }

    void add(Type element)
    {
        if (mNumberOfElements >= mCapacity)
        {
            expand();
        }

        mArray[mNumberOfElements++] = element;
    }

    Type get(int index) const
    {
        if (index > mNumberOfElements)
        {
            std::string exception = std::to_string(index) + " index is out of bounds.";
            
            std::cout << exception;
            return "";
        }

        if (index < 0)
        {
            if (mNumberOfElements + index < 0)
            {
                std::string exception = std::to_string(index) + " index result in " + std::to_string(mNumberOfElements + index) + " which is out of bounds.\n";
                
                std::cout << exception;
                return "";
            }

            return mArray[mNumberOfElements + index];
        }

        return mArray[index];
    }

    Type pop()
    {
        if (mNumberOfElements > 0)
        {
            return mArray[--mNumberOfElements];
        }
        else
        {
            std::cout << "Array is empty, cannot use pop()\n";
            return "";
        }
    }

    int length()
    {
        return mNumberOfElements;
    }
private:
    int mCapacity;
    int mNumberOfElements;
    Type* mArray;

    void initialize(int from)
    {
        for (size_t i = from; i < mCapacity; ++i)
        {
            mArray[i] = "";
        }
    }

    void expand()
    {
        mCapacity *= 2;
        Type* temporaryArray = new Type[mCapacity];

        for (size_t i = 0; i < mCapacity; ++i)
        {
            std::cout << mArray[i] << std::endl;
            temporaryArray[i] = mArray[i];
        }

        std::cout << "Not reached\n";

        delete[] mArray;

        mArray = temporaryArray;

        initialize(mNumberOfElements);
    }
};


int main()
{
    DynamicArray<std::string> test;

    // test.pop();
    test.add("Hello");
    test.add("World");

    std::cout << test.get(1) << std::endl;
    // test.add("Hi");
    // test.add("Universe");

    for (size_t i = 0; i < test.length(); ++i)
    {
        std::cout << test.get(i)<< std::endl;
    }

    test.pop();

    for (size_t i = 0; i < test.length(); ++i)
    {
        std::cout << test.get(i)<< std::endl;
    }
}