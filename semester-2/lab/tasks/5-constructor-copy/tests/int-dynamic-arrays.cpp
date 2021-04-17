#include <iostream>
#include <string>

class DynamicArray
{
public:
    DynamicArray()
    : mCapacity(1), mNumberOfElements(0)
    {
        mArray = new int[mCapacity];
    }

    DynamicArray(int size)
    : mCapacity(size), mNumberOfElements(0)
    {
        mArray = new int[mCapacity];
    }

    DynamicArray(const DynamicArray& array)
    : mCapacity(array.getCapacity()), mNumberOfElements(array.length())
    {
        mArray = new int[mCapacity];
        for (size_t i = 0; i < mCapacity; ++i)
        {
            mArray[i] = array.get(i);
        }
    }

    ~DynamicArray()
    {
        delete[] mArray;
    }

    void add(int element)
    {
        if (mNumberOfElements >= mCapacity)
        {
            expand();
        }

        mArray[mNumberOfElements++] = element;
    }

    int get(int index) const
    {
        if (index > mNumberOfElements)
        {
            std::string exception = std::to_string(index) + " index is out of bounds.";
            
            std::cout << exception;
            return int();
        }

        if (index < 0)
        {
            if (mNumberOfElements + index < 0)
            {
                std::string exception = std::to_string(index) + " index result in " + std::to_string(mNumberOfElements + index) + " which is out of bounds.\n";
                
                std::cout << exception;
                return int();
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
    int* mArray;

    void initialize(int from)
    {
        for (size_t i = from; i < mCapacity; ++i)
        {
            mArray[i] = int();
        }
    }

    void expand()
    {
        int oldCapacity = mCapacity;
        mCapacity *= 2;
        int* temporaryArray = new int[mCapacity];

        for (size_t i = 0; i < oldCapacity; ++i)
        {
            std::cout << mArray[i] << std::endl;
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
    strings.add(1);
    strings.add(2);

    for (size_t i = 0; i < strings.length(); ++i)
    {
        std::cout << strings.get(i) << std::endl;
    }
}