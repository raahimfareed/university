#include <iostream>

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

class Entertainment
{
public:
    Entertainment()
    : mTitle(""), mReleaseDate(""), mType(""), mRuntime(""), mCountry(""), mRating(0)
    {}

    Entertainment(std::string title, std::string releaseDate, std::string genre, std::string type, std::string runtime, std::string country, std::string actor, unsigned int rating)
    : mTitle(title), mReleaseDate(releaseDate), mType(type), mRuntime(runtime), mCountry(country), mRating(rating)
    {
        mGenres.add(genre);
        mActors.add(actor);
    }

    Entertainment(const Entertainment& e)
    : mCountry(e.getCountry()), mRating(e.getRating()), mGenres(e.mGenres)
    {}

    void setTitle(std::string title)
    {
        mTitle = title;
    }

    void setReleaseDate(std::string releaseDate)
    {
        mReleaseDate = releaseDate;
    }

    void setType(std::string type)
    {
        mType = type;
    }

    void setRuntime(std::string runtime)
    {
        mRuntime = runtime;
    }

    void setCountry(std::string country)
    {
        mCountry = country;
    }

    void addGenre(std::string genre)
    {
        mGenres.add(genre);
    }

    void addActor(std::string actor)
    {
        mActors.add(actor);
    }

    std::string getTitle() const
    {
        return mTitle;
    }

    std::string getReleaseDate() const
    {
        return mReleaseDate;
    }

    std::string getType() const
    {
        return mType;
    }

    std::string getRuntime() const
    {
        return mRuntime;
    }

    std::string getCountry() const
    {
        return mCountry;
    }

    unsigned int getRating() const
    {
        return mRating;
    }

    DynamicArray getGenres()
    {
        return mGenres;
    }

    DynamicArray getActors()
    {
        return mActors;
    }

    void display()
    {
        std::cout << "Title: " << mTitle << std::endl
                  << "Release Date: " << mReleaseDate << std::endl
                  << "Type: " << mType << std::endl
                  << "Runtime: " << mRuntime << std::endl
                  << "Country: " << mCountry << std::endl
                  << "Rating: " << mRating << std::endl;
        
        std::cout << "\nGenres\n";
        for (size_t i = 0; i < mGenres.length(); ++i)
        {
            std::cout << mGenres.get(i) << std::endl;
        }

        std::cout << "\nActors\n";
        for (size_t i = 0; i < mActors.length(); ++i)
        {
            std::cout << mActors.get(i) << std::endl;
        }
    }

private:
    std::string mTitle;
    std::string mReleaseDate;
    DynamicArray mGenres;
    std::string mType;
    std::string mRuntime;
    std::string mCountry;
    DynamicArray mActors;
    unsigned int mRating;
};

int main()
{
    Entertainment corona("COVID-19", "December 19, 2019", "Horror", "Movie", "1 Year 5 months+", "Global", "Corona Virus", 5);
    corona.addGenre("Realism");
    corona.display();

    std::cout << std::endl << std::endl;

    Entertainment coronaRemake(corona);
    coronaRemake.setReleaseDate("January 1, 2020");
    coronaRemake.setRuntime("Ongoing");
    coronaRemake.setTitle("COVID-19 Remake");
    coronaRemake.setType("Movie");
    coronaRemake.addActor("Novel COVID-19");
    coronaRemake.display();
}

