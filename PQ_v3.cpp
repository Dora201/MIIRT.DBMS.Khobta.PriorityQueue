// PQ_v3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <stdlib.h>
using namespace std;

struct Element
{
    int element;
    int priority;
    Element* next;
    Element(int el, int pr);
    friend ostream& operator <<(ostream& out, const Element& elem)
    {
        return out << elem.element;
    }
};



class PriorityQueue
{
    Element* head;
    Element* tail;
public:
    PriorityQueue();
    ~PriorityQueue();
    bool Sort();
    void Dequeue();
    void Enqueue(int element, int priority);
    friend ostream& operator << (ostream& out, const PriorityQueue& link)
    {
        auto current = link.head;
        out << "{ ";
        while (current->next != nullptr)
        {
            out << *current << ",  ";
            current = current->next;
        }
        return out << *current << " }";
    }
};

void main()
{
    PriorityQueue* queue = new PriorityQueue();
    queue->Enqueue(9, 4);
    queue->Enqueue(1, 6);
    queue->Enqueue(8, 2);
    queue->Enqueue(14, 3);
    cout << *queue << endl;
    queue->Dequeue();
    cout << *queue;
}

PriorityQueue::PriorityQueue()
    :head(nullptr), tail(nullptr)
{
}

PriorityQueue::~PriorityQueue()
{
    Element* temp = head;
    while (temp != nullptr)

    {
        temp = head->next;
        delete head;
        head = temp;
    }
}

bool PriorityQueue::Sort()
{
    Element* temp = head;
    Element* tmp = new Element(0,0);
    while (temp != NULL)
    {
        if (temp->next != NULL && temp->priority < temp->next->priority)
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

void PriorityQueue::Dequeue()
{
    if (head != nullptr)
    {
        Element* temp = head;
        head = head->next;
        delete temp; 
    }
}

void PriorityQueue::Enqueue(int element, int priority)
{
    Element* elem = new Element(element, priority);
    
    if (head != nullptr)
    {
        tail->next = elem;
        tail = elem;
    }
    else head = tail = elem;
    while (Sort() == false)
    {
        Sort();
    }
}

Element::Element(int el, int pr)
{
    element = el;
    priority = pr;
    next = nullptr;
}
