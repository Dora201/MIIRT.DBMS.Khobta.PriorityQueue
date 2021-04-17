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

    cout << "Without Iterator:" << endl;
    cout << *queue << endl;

    cout << "With Iterator:" << endl;
    cout << "{ ";
    for (Iterator<int> it = queue->cbegin(); it != queue->cend(); ++it)
    {
        cout << *it << ",";
    }
    cout << "}"<< endl;

    const auto result = queue->Dequeue();

    cout << *queue << endl
        << "result is " << result;
    cout << endl;

    cout << "{ ";
    for (Iterator<int> it = queue->cbegin(); it != queue->cend(); ++it)
    {
        cout << *it << ",";
    }
    cout << "}" << endl;

    delete queue;
    return 0;
}
