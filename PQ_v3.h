#pragma once

#include <iostream>
#include <stdlib.h>

using namespace std;

template <typename T>
struct Element
{
    T     element;
    int     priority;
    Element *next;

    Element(int el, int pr);
    friend ostream& operator <<(ostream& out, const Element& elem)
    {
        return out << elem.element;
    }
};

template <typename T>
class PriorityQueue
{
    Element* head;
    Element* tail;
    T i;
    bool Sort();
public:
    PriorityQueue();
    ~PriorityQueue();
    T& Dequeue();
    void Enqueue(T element, int priority);
    friend ostream& operator << (ostream& out, const PriorityQueue& link)
    {
        auto current = link.head;
        out << "{ ";
        while (current->next)
        {
            out << *current << ",  ";
            current = current->next;
        }
        return out << *current << " }";
    }
};



template<typename T>
inline PriorityQueue<T>::PriorityQueue()
    :head(nullptr), tail(nullptr)
{
}

template<typename T>
inline PriorityQueue<T>::~PriorityQueue()
{
    Element* temp = head;
    while (temp)

    {
        temp = head->next;
        delete head;
        head = temp;
    }
}

template<typename T>
inline bool PriorityQueue<T>::Sort()
{
    Element* temp = head;
    Element* tmp = new Element(0, 0);
    while (temp)
    {
        if (temp->next && temp->priority < temp->next->priority)
        {
            tmp->priority = temp->priority;
            tmp->element = temp->element;
            temp->priority = temp->next->priority;
            temp->element = temp->next->element;
            temp->next->priority = tmp->priority;
            temp->next->element = tmp->element;
            return false;
        }
        temp = temp->next;
    }
    return true;
}

template<typename T>
inline T& PriorityQueue<T>::Dequeue()
{
    Element* temp;
    int      result;

    result = 0;
    if (head)
    {
        temp = head;
        head = head->next;
        result = temp->element;
        delete temp;
    }
    return result;
}

template<typename T>
inline void PriorityQueue<T>::Enqueue(T element, int priority)
{
    Element* elem = new Element(element, priority);

    if (head)
    {
        tail->next = elem;
        tail = elem;
    }
    else head = tail = elem;
    while (!Sort())
        Sort();
}

template<typename T>
inline Element<T>::Element(int el, int pr)
{
    element = el;
    priority = pr;
    next = nullptr;
}
