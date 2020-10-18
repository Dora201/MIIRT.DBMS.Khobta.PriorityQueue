#include <iostream>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <tchar.h>
#include <conio.h>
#include <math.h>
#include <time.h>
using namespace std;


bool input(const size_t size)
{
	return size > 0;
}

void create(int* value, const size_t size)
{

	for (int i = 0; i < size; i++)
	{
		value[i] = rand();
	}
}

void output(const int* value, const size_t size)
{

	for (int i = 0; i < size - 1; i++)
	{
		cout << value[i] << ",";
	}
	cout << value[size - 1] << endl;

}

int sum(const int* value, const size_t size)
{
	int mysum = 0;
	for (int i = 0; i < size; i++)
	{
		mysum += value[i];
	}
	return mysum;
}

double average(double sum, const size_t size)
{
	return sum / size;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	size_t size;
	cout << "Введите размер массива" << endl;
	cin >> size;

	if (input(size))
	{
		const auto value = new int[size];
		create(value, size);
		cout << "Массив: ";
		output(value, size);
		cout << "Среднее арифметическое значение = " << average(sum(value, size), size) << endl;

	}
	else
	{
		cout << "Неверный размер массива" << endl;
	}

}