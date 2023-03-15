//written by Zeynep Su Uçan
//22103044 - Section 3

#include <string>
#include <iostream>
#include <fstream>
#include "MovieRentalSystem.h"

using namespace std;

MovieRentalSystem::MovieRentalSystem(const string movieInfoFileName,
                                     const string subscriberInfoFileName)
{

    MovieHead = NULL;
    SubscriberHead = NULL;

    string movieTxtName = movieInfoFileName;
    string subTxtName = subscriberInfoFileName;

    int number;
    int number2;
    int numOfMovies = 0;
    int numOfSubs = 0;

    ifstream movieInput;

    ifstream subInput;
    // Open the stream for the input file
    movieInput.open(movieTxtName.c_str(), ios_base::in);

    subInput.open(subTxtName.c_str(), ios_base::in);

    // Continue until the end of the file
    if (movieInput && subInput)
    {
        movieInput >> numOfMovies;

        for (int i=0; i < numOfMovies; i++)
        {
                int MovieId, MovieCopy;
                movieInput >> number;
                MovieId = number;
                movieInput >> number;
                MovieCopy = number;

                MovieNode *newNode = new MovieNode;
                newNode->movie = Movie(MovieId, MovieCopy);
                MovieNode *current = MovieHead;
                bool check = true;

                while (current)
                {
                    if (current->movie.getID() == MovieId)
                    {
                        check = false;
                        current = current->nextMovieNode;
                    }
                    else
                    {
                        current = current->nextMovieNode;
                    }
                }

                current = MovieHead;

                if (check)
                {
                    if (MovieHead == NULL || MovieHead->movie.getID() > newNode->movie.getID())
                    {
                        newNode->nextMovieNode = MovieHead;
                        MovieHead = newNode;
                    }
                    else
                    {
                        while (current->nextMovieNode != NULL && current->nextMovieNode->movie.getID() < newNode->movie.getID())
                        {
                            current = current->nextMovieNode;
                        }
                        newNode->nextMovieNode = current->nextMovieNode;
                        current->nextMovieNode = newNode;
                    }
                }

                else
                {
                    numOfMovies--;
                }
        }
        
        subInput >> numOfSubs;


        for (int i = 0; i < numOfSubs; i++)
        {

                int SubID;
                subInput >> number2;
                SubID = number2;

                SubscriberNode *newNode = new SubscriberNode;
                newNode->subscriber = Subscriber(SubID);
                SubscriberNode *current = new SubscriberNode;
                current = SubscriberHead;
                bool check = true;

                while (current)
                {
                    if (current->subscriber.getID() == SubID)
                    {
                        check = false;
                        current = current->nextSubscriberNode;
                    }
                    else
                    {
                        current = current->nextSubscriberNode;
                    }
                }

                if(check){
                    if (SubscriberHead == NULL || SubscriberHead->subscriber.getID() >= newNode->subscriber.getID())
                    {
                        newNode->nextSubscriberNode = SubscriberHead;
                        SubscriberHead = newNode;
                    }
                    else
                    {
                        current = SubscriberHead;
                        while (current->nextSubscriberNode != NULL && current->nextSubscriberNode->subscriber.getID() < newNode->subscriber.getID())
                        {
                            current = current->nextSubscriberNode;
                        }
                        newNode->nextSubscriberNode = current->nextSubscriberNode;
                        current->nextSubscriberNode = newNode;
                    }
                }
        }

        movieInput.close();

        subInput.close();

        cout << numOfSubs << " subscribers and " << numOfMovies << " movies have been loaded" << endl;
    }
    else if (!movieInput && subInput)
    {
        cout << "Input file " << movieTxtName << " does not exist" << endl;
    }
    else if (movieInput && !subInput)
    {
        cout << "Input file " << subTxtName << " does not exist" << endl;
    }
    else
    {
        cout << "Input file " << movieTxtName << " and " << subTxtName << " do not exist" << endl;
    }
}

MovieRentalSystem::~MovieRentalSystem()
{
    while (MovieHead != NULL)
    {
        MovieNode *nextHead = MovieHead->nextMovieNode;
        delete MovieHead;
        MovieHead = nextHead;
    }
    while (SubscriberHead != NULL)
    {
        SubscriberNode *nextHead = SubscriberHead->nextSubscriberNode;
        delete SubscriberHead;
        SubscriberHead = nextHead;
    }
}

void MovieRentalSystem::removeMovie(const int movieId)
{

    MovieNode *current = MovieHead;
    bool IDC = false;
    bool rentCheck = false;
    int currentIndex = 0;
    int position = 0;

    while (current)
    {
        rentCheck = false;
        if (current->movie.getID() == movieId)
        {
            IDC = true;
            position = currentIndex - 1;
        }
        else
            currentIndex++;

        if (current->movie.getRentedCopy() == 0)
            rentCheck = true;

        if (IDC && rentCheck)
        {
            MovieNode *previousNode = MovieHead;
            if (position < 0)
            {
                MovieHead = previousNode->nextMovieNode;
                cout << "Movie " << movieId << " has been removed" << endl;
                return;
            }
            for (int i = 0; i < position; i++)
            {
                previousNode = previousNode->nextMovieNode;
            }
            MovieNode *next = previousNode->nextMovieNode->nextMovieNode;
            delete previousNode->nextMovieNode;
            previousNode->nextMovieNode = next;
            cout << "Movie " << movieId << " has been removed" << endl;
            return;
        }
        else if (IDC && !rentCheck)
        {
            cout << "Movie " << movieId << " cannot be removed -- at least one copy has not been returned" << endl;
            return;
        }
        else
        {
            current = current->nextMovieNode;
        }
    }
    if (!IDC)
    {
        cout << "Movie " << movieId << " does not exist" << endl;
    }
}

void MovieRentalSystem::addMovie(const int movieId, const int numCopies)
{
    MovieNode *newNode = new MovieNode;
    newNode->movie = Movie(movieId, numCopies);
    MovieNode *current = MovieHead;
    bool check = true;

    while (current)
    {
        if (current->movie.getID() == movieId)
        {
            check = false;
            current = current->nextMovieNode;
        }
        else
        {
            current = current->nextMovieNode;
        }
    }

    current = MovieHead;

    if (check)
    {
        if (MovieHead == NULL || MovieHead->movie.getID() > newNode->movie.getID())
        {
            newNode->nextMovieNode = MovieHead;
            MovieHead = newNode;
        }
        else
        {
            while (current->nextMovieNode != NULL && current->nextMovieNode->movie.getID() < newNode->movie.getID())
            {
                current = current->nextMovieNode;
            }
            newNode->nextMovieNode = current->nextMovieNode;
            current->nextMovieNode = newNode;
        }
        cout << "Movie " << movieId << " has been added" << endl;
    }

    else
    {
        cout << "Movie " << movieId << " already exists." << endl;
    }
}

void MovieRentalSystem::removeSubscriber(const int subscriberId)
{
    SubscriberNode *current = SubscriberHead;
    bool IDC = false;
    bool rentCheck = false;
    int currentIndex = 0;
    int position = 0;
    while (current)
    {
        if (current->subscriber.getID() == subscriberId)
        {
            IDC = true;
            position = currentIndex - 1;
        }
        else
            currentIndex++;

        if (current->subscriber.getMovieNum() == 0)
            rentCheck = true;

        if (IDC && rentCheck)
        {
            SubscriberNode *previousNode = SubscriberHead;
            if (position < 0)
            {
                SubscriberHead = previousNode->nextSubscriberNode;
                cout << "Subscriber " << subscriberId << " has been removed" << endl;
                return;
            }
            for (int i = 0; i < position; i++)
            {
                previousNode = previousNode->nextSubscriberNode;
            }
            SubscriberNode *next = previousNode->nextSubscriberNode->nextSubscriberNode;
            delete previousNode->nextSubscriberNode;
            previousNode->nextSubscriberNode = next;
            cout << "Subscriber " << subscriberId << " has been removed" << endl;
            return;
        }
        else if (IDC && !rentCheck)
        {
            cout << "Subscriber " << subscriberId << " cannot be removed -- at least one movie has not been returned" << endl;
            return;
        }
        else
        {
            current = current->nextSubscriberNode;
        }
    }
    if (!IDC)
    {
        cout << "Subscriber " << subscriberId << " does not exist" << endl;
    }
}

void MovieRentalSystem::rentMovie(const int subscriberId, const int movieId)
{
    bool checkMov = false;
    bool checkSub = false;
    int movieCopy = 0;

    MovieNode *foundMov = new MovieNode;
    MovieNode *currentMov = new MovieNode;
    for (currentMov = MovieHead; currentMov != NULL; currentMov = currentMov->nextMovieNode)
    {
        if (currentMov->movie.getID() == movieId)
        {
            checkMov = true;
            foundMov = currentMov;
            movieCopy = foundMov->movie.getNumOfCopies();
        }
    }

    SubscriberNode *foundSub = new SubscriberNode;

    SubscriberNode *currentSub = new SubscriberNode;
    for (currentSub = SubscriberHead; currentSub != NULL; currentSub = currentSub->nextSubscriberNode)
    {
        if (currentSub->subscriber.getID() == subscriberId)
        {
            checkSub = true;
            foundSub = currentSub;
        }
    }

    bool availableCopy = false;
    if (foundMov->movie.getNumOfCopies() > foundMov->movie.getRentedCopy())
    {
        availableCopy = true;
    }

    if (checkMov && checkSub)
    {
        if (availableCopy)
        {
            foundSub->subscriber.addMovie(movieId, movieCopy);
            foundMov->movie.setRentedCopy(1);
            cout << "Movie " << movieId << " has been rented by subscriber " << subscriberId << endl;
        }
        else
        {
            cout << "Movie " << movieId << " has no available copy for renting" << endl;
        }
    }
    else if (!checkMov && checkSub)
    {
        cout << "Movie " << movieId << " does not exist" << endl;
    }
    else if (checkMov && !checkSub)
    {
        cout << "Subscriber " << subscriberId << " does not exist" << endl;
    }
    else
    {
        cout << "Subscriber " << subscriberId << " and movie " << movieId << " do not exist" << endl;
    }
}

void MovieRentalSystem::returnMovie(const int subscriberId, const int movieId)
{
    bool checkMov = false;
    bool checkSub = false;
    bool checkMatch = false;
    int movieCopy;

    MovieNode *foundMov = new MovieNode;
    MovieNode *currentMov = new MovieNode;
    for (currentMov = MovieHead; currentMov != NULL; currentMov = currentMov->nextMovieNode)
    {
        if (currentMov->movie.getID() == movieId)
        {
            checkMov = true;
            foundMov = currentMov;
            movieCopy = foundMov->movie.getNumOfCopies();
        }
    }

    SubscriberNode *foundSub = new SubscriberNode;
    SubscriberNode *currentSub = new SubscriberNode;
    for (currentSub = SubscriberHead; currentSub; currentSub = currentSub->nextSubscriberNode)
    {
        if (currentSub->subscriber.getID() == subscriberId)
        {
            checkSub = true;
            foundSub = currentSub;
        }
    }

    if (foundSub->subscriber.hasMovieReturn(movieId))
    {
        checkMatch = true;
    }

    if (checkMov && checkSub && checkMatch)
    {
        foundSub->subscriber.deleteMovie(movieId);
        foundMov->movie.setRentedCopy(-1);
        cout << "Movie " << movieId << " has been returned by subscriber " << subscriberId << endl;
    }
    else if (!checkMov && checkSub)
    {
        cout << "Movie " << movieId << " does not exist" << endl;
    }
    else if (checkMov && !checkSub)
    {
        cout << "Subscriber " << subscriberId << " does not exist" << endl;
    }
    else if (!checkMov && !checkSub)
    {
        cout << "Subscriber " << subscriberId << " and movie " << movieId << " do not exist" << endl;
    }
    else if (checkMov && checkSub && !checkMatch)
    {
        cout << "No rental transaction for subscriber " << subscriberId << " and movie " << movieId << endl;
    }
    delete currentMov;
    delete currentSub;
}
void MovieRentalSystem::showMoviesRentedBy(const int subscriberId) const
{
    SubscriberNode *current = new SubscriberNode;
    current = SubscriberHead;
    bool check = false;
    bool checkRent = false;
    while (current)
    {
        if (current->subscriber.getID() == subscriberId)
        {
            check = true;
            if (current->subscriber.head)
            {
                cout << "Subscriber " << subscriberId << " has rented the following movies:" << endl;
                current->subscriber.showAllMovies();
            }
            else
            {
                cout << "Subscriber " << subscriberId << " has not rented any movies" << endl;
            }
        }
        current = current->nextSubscriberNode;
    }
    if (!check)
    {
        cout << "Subscriber " << subscriberId << " does not exist" << endl;
    }
}
void MovieRentalSystem::showSubscribersWhoRentedMovie(const int movieId) const
{
    MovieNode *current = new MovieNode;
    SubscriberNode *currentS = new SubscriberNode;
    current = MovieHead;
    currentS = SubscriberHead;
    bool check = false;
    bool checkRent = false;

    while (current)
    {
        if (current->movie.getID() == movieId)
        {
            check = true;
            current = current->nextMovieNode;
        }
        else
            current = current->nextMovieNode;
    }

    if (check)
    {

        while (currentS)
        {

            if (currentS->subscriber.hasMovie(movieId))
            {
                checkRent = true;
            }
            currentS = currentS->nextSubscriberNode;
        }
    }
    if (check && checkRent)
    {
        cout << "Movie " << movieId << " has been rented by the following subscribers:" << endl;
        currentS = SubscriberHead;
        while (currentS)
        {
            if (currentS->subscriber.hasMovie(movieId))
            {
                currentS->subscriber.showMovie(movieId);
                currentS = currentS->nextSubscriberNode;
            }
            currentS = currentS->nextSubscriberNode;
        }
    }

    if (!check)
    {
        cout << "Movie " << movieId << " does not exist" << endl;
    }
    if (check && !checkRent)
    {
        cout << "Movie " << movieId << " has not been rented by any subscriber" << endl;
    }
}

void MovieRentalSystem::showAllMovies() const
{
    cout << "Movies in the movie rental system:" << endl;
    MovieNode *current = new MovieNode;
    current = MovieHead;
    while (current->nextMovieNode != nullptr)
    {
        cout << current->movie.getID() << " " << current->movie.getNumOfCopies() << endl;
        current = current->nextMovieNode;

    }
    cout << current->movie.getID() << " " << current->movie.getNumOfCopies() << endl;
}

void MovieRentalSystem::showAllSubscribers() const
{
    cout << "Subscribers in the movie rental system:" << endl;
    SubscriberNode *current = new SubscriberNode;
    current = SubscriberHead;
    while (current->nextSubscriberNode != nullptr)
    {
        cout << current->subscriber.getID() << endl;
        current = current->nextSubscriberNode;
    }
    cout << current->subscriber.getID() << endl;
}
