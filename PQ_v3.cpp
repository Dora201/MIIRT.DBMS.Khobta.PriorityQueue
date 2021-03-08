#include "Header.h"

int    main()
{
    PriorityQueue<int>* queue = new PriorityQueue<int>();
    int last = -150;

    queue->Enqueue(9, 4);
    queue->Enqueue(1, 6);
    queue->Enqueue(8, 2);
    queue->Enqueue(14, 3);
    cout << *queue << endl;
    last = queue->Dequeue();
    cout << *queue;
}
