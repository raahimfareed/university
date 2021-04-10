#include <iostream>

float arrayAverage(float *pArrayPointer, int size);
void arrayDisplay(float array[], int size);

int main()
{
    float array[6] = { 1.0f, 2.0f, 3.0f, 4.0f, 5.0f ,6.0f };

    std::cout << "The average of the array enteries is " << arrayAverage(array, 6);
    std::cout << "\nArray contains the following values\n";

    arrayDisplay(array, 6);
}

float arrayAverage(float *pArrayPointer, int size)
{
    float average = 0.0f;
    for (int i = 0; i < size; ++i)
    {
        average += pArrayPointer[i];
    }

    return (average / size);
}

void arrayDisplay(float array[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << array[i] << std::endl;
    }
}
