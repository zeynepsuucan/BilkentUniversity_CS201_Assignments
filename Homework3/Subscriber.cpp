//written by Zeynep Su Uçan
//22103044 - Section 3

#include "Subscriber.h"
#include "MovieNodeSub.h"

using namespace std;

Subscriber::Subscriber(const int subscriberId)
{
    this->subscriberId = subscriberId;
    this->head = NULL;
    subsMovieNum = 0;
}
Subscriber::Subscriber(const Subscriber &otherSubs)
{
    this->subscriberId = otherSubs.getID();
    subsMovieNum = 0;
}
Subscriber::~Subscriber()
{
    while (head != NULL)
    {
        MovieNodeSub *nextHead = head->nextMovie;
        delete head;
        head = nextHead;
    }
}
const int Subscriber::getID() const
{
    return this->subscriberId;
}

MovieNodeSub *Subscriber::findMovie(const int movieId) const
{
    return nullptr;

} // finds the movie by its id

void Subscriber::addMovie(const int movieId, const int movieCopy)
{

    MovieNodeSub *newNode = new MovieNodeSub;
    newNode->movie = Movie(movieId, movieCopy);
    newNode->status = false; // true means not returned
    MovieNodeSub *current;
    if (head == NULL || head->movie.getID() > newNode->movie.getID())
    {
        newNode->nextMovie = head;
        head = newNode;
    }
    else
    {
        current = head;
        while (current->nextMovie && current->nextMovie->movie.getID() <= newNode->movie.getID())
        {
            current = current->nextMovie;
        }
        newNode->nextMovie = current->nextMovie;
        current->nextMovie = newNode;
    }
    subsMovieNum++;
}
void Subscriber::deleteMovie(const int movieId)
{

    MovieNodeSub *current = head;
    bool IDC = false;
    bool rentCheck = false;
    int currentIndex = 0;
    int position = 0;
    while (current)
    {
        if (current->movie.getID() == movieId)
        {
            current->status = true;
            current = current->nextMovie;
        }
        else
            current = current->nextMovie;
    }
}
bool Subscriber::hasMovie(const int movieId)
{
    MovieNodeSub *current = new MovieNodeSub;
    current = head;
    while (current)
    {
        if (current->movie.getID() == movieId)
        {
            return true;
        }
        else
        {
            current = current->nextMovie;
        }
    }
    return false;
}

bool Subscriber::hasMovieReturn(const int movieId)
{
    MovieNodeSub *current = new MovieNodeSub;
    current = head;
    while (current)
    {
        if (current->movie.getID() == movieId)
        {
            if (current->status == false)
            {
                return true;
            }
            current = current->nextMovie;
        }
        else
        {
            current = current->nextMovie;
        }
    }
    return false;
}

void Subscriber::showAllMovies()
{
    MovieNodeSub *current = new MovieNodeSub;
    current = head;
    while (current)
    {
        if (current->status)
        {
            cout << current->movie.getID() << " returned" << endl;
        }
        else
        {
            cout << current->movie.getID() << " not returned" << endl;
        }
        current = current->nextMovie;
    }
}
void Subscriber::showMovie(const int movieId)
{
    MovieNodeSub *current = new MovieNodeSub;
    current = head;
    while (current)
    {
        if (current->movie.getID() == movieId)
        {
            if (current->status)
            {
                cout << this->getID() << " returned" << endl;
            }
            else
            {
                cout << this->getID() << " not returned" << endl;
            }
        }
        current = current->nextMovie;
    }
}
