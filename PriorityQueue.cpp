// PriorityQueue.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#include <iostream>
#include <ostream>
#include <string.h>

using namespace std;

class PriorityQueue
{
public:
	int *element;
	int priority;
	PriorityQueue *next;
	void Show(PriorityQueue* list);
	void Enqueue(PriorityQueue *elem, PriorityQueue *list);
	void Sort(PriorityQueue *list);
	void Dequeue(PriorityQueue* list);
	PriorityQueue();
	PriorityQueue(int *element, int priority);
};


void PriorityQueue::Show(PriorityQueue *list)
{
	PriorityQueue *test_list = list;
	if (test_list)
	{
		cout << "Element\t" << "Priority" << endl;
		cout << *test_list->element << "\t" << test_list->priority << endl;
		while (test_list->next)
		{
			test_list = test_list->next;
			cout << *test_list->element << "\t" << test_list->priority << endl;
		}
	}
	else
	{
		cout << "Queue is empty!";
	}
}

void PriorityQueue::Enqueue(PriorityQueue *elem, PriorityQueue *list)
{
	PriorityQueue *tmp;
	if (elem && list)
	{
		tmp = list;
		while (tmp->next)
		{
			tmp = tmp->next;
		}
		tmp->next = elem;
	}
	else
	{
		list = elem;
	}
	Sort(list);
}

void PriorityQueue::Sort(PriorityQueue *list)
{
	PriorityQueue* test_list = list;
	int tmp;
	int *item;
	bool sort = true;

	if (test_list)
	{
		while (test_list->next)
		{
			if (test_list->priority < test_list->next->priority)
			{
				tmp = test_list->priority;
				test_list->priority = test_list->next->priority;
				test_list->next->priority = tmp;

				item = test_list->element;
				test_list->element = test_list->next->element;
				test_list->next->element = item;
				sort = false;
			}
			test_list = test_list->next;
		}
		if (sort == false)
		{
			Sort(list);
		}
	}
}

void PriorityQueue::Dequeue(PriorityQueue* list)
{
	delete list->element;
	delete &list->priority;
	list = list->next;	
}

PriorityQueue::PriorityQueue()
{
	this->element = 0;
	this->priority = 0;
	this->next = nullptr;
}

PriorityQueue::PriorityQueue(int *element, int priority)
{
	this->element = element;
	this->priority = priority;
	this->next = nullptr;
}

int main(void)
{
	int y = 5;
	PriorityQueue queue = PriorityQueue(&y,10);
	PriorityQueue queue1 = PriorityQueue(&y, 2);
	queue.Enqueue(&queue1,&queue);
	int x = 10;
	PriorityQueue queue2 = PriorityQueue(&x, 5);
	queue.Enqueue(&queue2, &queue);
	int e = 7;
	PriorityQueue queue3 = PriorityQueue(&e, 3);
	queue.Enqueue(&queue3, &queue);
	int w = 12;
	PriorityQueue queue4 = PriorityQueue(&w, 15);
	queue.Enqueue(&queue4, &queue);
	queue.Show(&queue);
	
	//cout << *queue->element << "," << queue->priority << endl;
}