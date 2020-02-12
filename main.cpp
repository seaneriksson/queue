#include <iostream>
using namespace std;
//#include "Queue1.h"


class FullQueue
{};

class EmptyQueue
{};

typedef char ItemType;

class QueType
{
public:
    QueType(int max);
    QueType();
    ~QueType();
    void MakeEmpty();
    bool IsEmpty() const;
    bool IsFull() const;
    void Enqueue(ItemType newItem);
    void Dequeue(ItemType& item);
    void PrintQueue();
    int getLength();
    void printLength();
private:
    int front;
    int rear;
    int length;
    ItemType* items;
    int maxQue;
};



QueType::QueType(int max)
{
    maxQue = max + 1;
    front = maxQue - 1;
    rear = maxQue - 1;
    items = new ItemType[maxQue];
    length = 0;
}

QueType::QueType()
{
    maxQue = 501;
    front = maxQue - 1;
    rear = maxQue - 1;
    items = new ItemType[maxQue];
    length = 0;
}

QueType::~QueType()
{
    delete [] items;
}

void QueType::MakeEmpty()
{
    front = maxQue - 1;
    rear = maxQue -1;
    length = 0;
}

bool QueType::IsEmpty() const
{
    return (rear == front);
}

bool QueType::IsFull() const
{
    return ((rear + 1) % maxQue == front);
}

void QueType::Enqueue(ItemType newItem)
{
    if (IsFull())
        throw FullQueue();
    else
    {
        rear = (rear + 1) % maxQue;
        items[rear] = newItem;
        length++;
    }
}

void QueType::Dequeue(ItemType& item)
{
    if (IsEmpty())
        throw EmptyQueue();
    else
    {
        front = (front + 1) % maxQue;
        item = items[front];
    }
    length--;
}

void QueType::PrintQueue()
{
    int distanceOfQueue = length;

    if (IsEmpty())
    {
        throw EmptyQueue();
    }
    else
    {
        while (distanceOfQueue > -1)
        {
            cout << "" << items[rear-distanceOfQueue] << endl;
            distanceOfQueue--;
        }
    }
}

int QueType::getLength()
{
    return length;

}

void QueType::printLength()
{
    cout << "The length is: " << getLength() << endl;

}

int main()
{

    QueType newQueue;

    newQueue.Enqueue('A');
    newQueue.Enqueue('B');
    newQueue.Enqueue('C');
    newQueue.Enqueue('D');
    newQueue.Enqueue('E');

    newQueue.PrintQueue();
    newQueue.printLength();

    return 0;
}
