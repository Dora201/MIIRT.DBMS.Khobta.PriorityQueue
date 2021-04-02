#include <iostream>
#include "PriorityQueue.h"

using namespace std;

int main()
{
    auto queue = new PriorityQueue<int>();

    queue->Enqueue(9, 4);
    queue->Enqueue(1, 6);
    queue->Enqueue(8, 2);
    queue->Enqueue(14, 3);

    cout << *queue << endl;

    const auto result = queue->Dequeue();

    cout << *queue << endl
         << "result is " << result;

    delete queue;
    return 0;
}
