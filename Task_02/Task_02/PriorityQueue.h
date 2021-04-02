#pragma once
#include <ostream>

template <class T>
struct Element;

template <class Type>
std::ostream& operator<<(std::ostream&, const Element<Type>&);

template <class T>
class PriorityQueue;

template <class Type>
std::ostream& operator<<(std::ostream&, const PriorityQueue<Type>&);

template <typename T>
struct Element
{
    T value;
    int priority = 0;
    Element *next = nullptr;

    explicit Element(const T& value, int priority = 0);
    Element(const Element& that);

    Element(Element&& that) = default;
    ~Element() = default;

    Element& operator=(const Element& that) = default;
    Element& operator=(Element&& that) = default;

    template <typename T1> friend std::ostream& operator<< (std::ostream& out, const Element& element);

    void Swap(Element& that);
};

template <typename T>
Element<T>::Element(const T& value, const int priority)
    : value(value), priority(priority), next(nullptr)
{
}

template <typename T>
Element<T>::Element(const Element& that)
    : Element(that.value, that.priority)
{
}

template <typename T>
std::ostream& operator<< (std::ostream& out, const Element<T>& element)
{
    return out << element.value;
}

template <typename T>
void Element<T>::Swap(Element& that)
{
    std::swap(this->value, that.value);
    std::swap(this->priority, that.priority);
}

template <typename T>
class PriorityQueue
{
    Element<T>* head;
    Element<T>* tail;

    bool IsEmpty() const noexcept;
    bool Sort();
    void Swap(Element<T>& first, Element<T>& second);

public:
    PriorityQueue();
    ~PriorityQueue();

    PriorityQueue(const PriorityQueue& that) = default;
    PriorityQueue(PriorityQueue&& that) = default;

    PriorityQueue& operator=(const PriorityQueue& that) = default;
    PriorityQueue& operator=(PriorityQueue&& that) = default;

    T& Dequeue();
    void Enqueue(const T& element, int priority);

    template <typename T1> friend std::ostream& operator<< (std::ostream& out, const PriorityQueue<T>& queue);
};

template<typename T>
PriorityQueue<T>::PriorityQueue()
    :head(nullptr), tail(nullptr)
{
}

template<typename T>
PriorityQueue<T>::~PriorityQueue()
{
    auto current = head;
    while (current != nullptr)
    {
        current = head->next;
        delete head;
        head = current;
    }
}

template <typename T>
bool PriorityQueue<T>::IsEmpty() const noexcept
{
    return this->head == nullptr;
}

template<typename T>
bool PriorityQueue<T>::Sort()
{
    auto current = this->head;
    while (current != nullptr)
    {
        if (current->next != nullptr && current->priority < current->next->priority)
        {
            this->Swap(*current, *(current->next));
            return false;
        }
        current = current->next;
    }
    return true;
}

template <typename T>
void PriorityQueue<T>::Swap(Element<T>& first, Element<T>& second)
{
    auto temporary = first;
    first.Swap(second);
    second.Swap(temporary);
}

template<typename T>
T& PriorityQueue<T>::Dequeue()
{
    if (this->IsEmpty())
    {
        throw std::exception("Queue is empty");
    }

    auto current = this->head;
    this->head = this->head->next;

    // HACK: Память выделяется динамически и не освобождается в методе,
    // чтобы передать объект из метода без возможности потери.
    auto result = new T(current->value);

    delete current;
    return *result;
}

template<typename T>
void PriorityQueue<T>::Enqueue(const T& element, const int priority)
{
    auto item = new Element<T>(element, priority);

    if (this->IsEmpty())
    {
        this->head = this->tail = item;
    }
    else
    {
        this->tail->next = item;
        this->tail = item;
    }

    while (!this->Sort());
}

template<typename T>
std::ostream& operator<<(std::ostream& out, const PriorityQueue<T>& queue)
{
    auto current = queue.head;
    out << "{ ";
    while (current->next != nullptr)
    {
        out << *current << ", ";
        current = current->next;
    }
    return out << *current << " }";
}
