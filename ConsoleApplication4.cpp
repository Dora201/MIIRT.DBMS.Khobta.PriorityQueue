// ConsoleApplication4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

class PriorityQueue
{
private:
    int* Array;
    int* Priority;
    size_t size;

public:

    PriorityQueue(size_t size)
    {
        this->size = size;
    };

    ~PriorityQueue()
    {
        if (size > 0)
        {
            delete[] Array;
            delete[] Priority;
        }
    }
    int getArray()
    {
        return *Array;
    }
    int getPriority()
    {
        return *Priority;
    }

    void show(string name);

    void push(int element, int prior);

    void remove();
};

int main()
{
    PriorityQueue queue = PriorityQueue(7);
        queue.push(2,1);
        queue.push(5,3);
        queue.push(8,3);
        queue.push(7,2);
        queue.show("Queue 1");

 return 0;

}


void PriorityQueue::show(string name)
{
    cout << "Object:  " << name << endl;
    cout << "Elements   " << "Priority   " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << Array[i] << "   " << Priority[i] << endl;
        cout << "------------------------------------------";
    }
}

void PriorityQueue::push(int element, int prior)
{
    int* Array1;
    int* Priority1;
    int position;

    if (this->size == 0)
    {
        position = 0;
    }
    else
    {
        position = 0;
        while (position < size)
        {
            if (Priority1[position] > prior) break;
            position++;
        }
    }

    for (int i = 0; i < position; i++)
    {
        Array1[i] = Array[i];
        Priority1[i] = Priority[i];
    }
    Array1[position] = element;
    Priority1[position] = prior;

    for (int i = position + 1; i < size; i++)
    {
        Array1[i + 1] = Array[i];
        Priority1[i + 1] = Priority[i];
    }

    PriorityQueue::~PriorityQueue();
    Array = Array1;
    Priority = Priority1;

    size += 1;
}

void PriorityQueue::remove()
{
    int* Array1;
    int* Priority1;

    if (size = 0)
    {
        cout << "No elements in queue!" << endl;
    }
    int first;
    first = Array[0];

    for (int i = 0; i < size; i++)
    {
        Array1[i] = Array[i + 1];
        Priority1[i] = Priority[i + 1];
    }
    
    PriorityQueue::~PriorityQueue();

    Array = Array1;
    Priority = Priority1;

    size -= 1;
}

