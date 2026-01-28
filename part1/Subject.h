#ifndef SUBJECT_H
#define SUBJECT_H
#include <vector>
#include "Observer.h"
#include "OOP5EventException.h"
template<typename T> class Subject {
    std::vector<Observer<T>*> observers;
    public:
    Subject() =  default;
    virtual ~Subject() = default;
    void notify(const T& event)
    {
        for(auto& observer : observers){
            observer->handleEvent(event);
        }
    }
    void addObserver(Observer<T>& observer)
    {
        for(auto& obs : observers){
            if(obs == &observer){
                throw ObserverAlreadyKnownToSubject();
            }
        }
        observers.push_back(&observer);
    }

    void removeObserver(Observer<T>& observer)
    {
        auto it =std::find(observers.begin(), observers.end(), &observer);
        // observer.end() points to one past the last element
        if(it == observers.end())
        {
            throw ObserverUnknownToSubject();
        }
        observers.erase(it);  
    }

    Subject<T>& operator+=(Observer<T>& observer)
    {
        addObserver(observer);
        return *this;
    }
    
    Subject<T>& operator-=(Observer<T>& observer)
    {
        removeObserver(observer);
        return *this;
    }

    Subject<T>& operator()(const T& event)
    {
        notify(event);
        return *this;
    }

};
#endif //SUBJECT_H