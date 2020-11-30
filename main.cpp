#include <iostream>
using namespace std;

struct element
{
    element* q_next;
    int value;
};

struct Queue
{
    element* front;
    element* rear;
};

void constructor(Queue& myQueue)
{
    myQueue.front= nullptr;
    myQueue.rear= nullptr;
}

void destructor(Queue& myQueue)
{
    while (myQueue.front != nullptr)
    {
        element* tmp = new element;
        tmp=myQueue.front;
        myQueue.front=(*myQueue.front).q_next;
        delete tmp;
    }
}

unsigned int size(Queue& myQueue)
{
    element* size_q = new element;
    size_q = myQueue.front;
    unsigned int counter = 0;
    while (size_q != nullptr)
    {
        ++counter;
        size_q = (*size_q).q_next;
    }
    return counter;
}

void push(Queue& myQueue, element& l)
{
    if (myQueue.front == nullptr)
    {
        element* new_q= new element;
        (*new_q).value = l.value;
        myQueue.front = new_q;
        myQueue.rear = new_q;
    } else if (myQueue.front!= nullptr)
    {
        element* new_q = new element;
        (*new_q).value = l.value;
        (*new_q).q_next = new_q;
        myQueue.rear = new_q;

    }
}

element pop(Queue& myQueue)
{
    int v = (*myQueue.front).value;
    element s;
    element* tmp = new element;
    tmp = myQueue.front;
    myQueue.front=(*myQueue.front).q_next;
    delete tmp;
    s.value = v;
    s.q_next = myQueue.front;
    return s;
}

int main()
{
    Queue queue;
    constructor(queue);
    element element;
    int k;
    for (int i =0; i<5; ++i)
    {
        cin >> k;
        element.value=k;
        push(queue, element);
    }
    cout <<"size:" << size(queue) << endl;
    element = pop(queue);
    cout << "The first element:" << element.value << endl;
    element = pop(queue);
    cout << "The first element:" << element.value << endl;
    element = pop(queue);
    cout << "The first element:" << element.value << endl;
    cout <<"size:" << size(queue) << endl;
    destructor(queue);
    return 0;
}