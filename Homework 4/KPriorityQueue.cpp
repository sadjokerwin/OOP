#include <iostream>
#include <exception>
#include "Queue.hpp"
template <typename T>
class kPriorityQueue
{
    T *data;
    MyQueue<T> *priority;
    size_t capacity;
    size_t size;

    size_t get;
    size_t put;

    void resize();

    void copyFrom(const kPriorityQueue<T> &other);
    void free();

public:
    kPriorityQueue();
    kPriorityQueue(size_t priority_num);
    kPriorityQueue(const kPriorityQueue<T> &other);
    kPriorityQueue<T> &operator=(const kPriorityQueue<T> &other);

    void push(const T &obj, size_t obj_prior);
    void push(T &&obj); //позволява и местене
    void pop();

    const T &peek() const;
    bool isEmpty() const;

    ~kPriorityQueue();
};

template <typename T>
kPriorityQueue<T>::kPriorityQueue()
{
    capacity = 4;
    data = new T[capacity];
    priority = nullptr;
    size = 0;
    get = put = 0;
}
template <typename T>
kPriorityQueue<T>::kPriorityQueue(size_t priority_num)
{
    priority = new size_t(priority_num);
}
template <typename T>
void kPriorityQueue<T>::push(const T &obj, size_t obj_prior)
{
    if(obj_prior>=sizeof(priority)/sizeof(size_t))
    if (size == capacity)
        resize();

    data[put] = obj; // operator=
    (++put) %= capacity;
    size++;
}

template <typename T>
void kPriorityQueue<T>::push(T &&obj)
{
    if (size == capacity)
        resize();

    data[put] = std::move(obj); // move operator =
    (++put) %= capacity;
    size++;
}

template <typename T>
bool kPriorityQueue<T>::isEmpty() const
{
    return size == 0;
}

template <typename T>
const T &kPriorityQueue<T>::peek() const
{
    if (isEmpty())
        throw std::logic_error("Empty queue!");

    return data[get];
}

template <typename T>
void kPriorityQueue<T>::pop()
{
    if (isEmpty())
        throw std::logic_error("Empty queue!");
    (++get) %= capacity;
    size--;
}

template <typename T>
void kPriorityQueue<T>::resize()
{
    T *resizedData = new T[capacity * 2];
    for (size_t i = 0; i < size; i++)
    {
        resizedData[i] = data[get];
        (++get) %= capacity;
    }
    capacity *= 2;
    delete[] data;
    data = resizedData;
    get = 0;
    put = size;
}

template <typename T>
void kPriorityQueue<T>::copyFrom(const kPriorityQueue<T> &other)
{
    data = new T[other.capacity];
    for (int i = 0; i < other.capacity; i++)
        data[i] = other.data[i];

    get = other.get;
    put = other.put;

    size = other.size;
    capacity = other.capacity;
}

template <typename T>
void kPriorityQueue<T>::free()
{
    delete[] data;
}

template <typename T>
kPriorityQueue<T>::kPriorityQueue(const kPriorityQueue<T> &other)
{
    copyFrom(other);
}

template <typename T>
kPriorityQueue<T> &kPriorityQueue<T>::operator=(const kPriorityQueue<T> &other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }
    return *this;
}

template <typename T>
kPriorityQueue<T>::~kPriorityQueue()
{
    free();
}
