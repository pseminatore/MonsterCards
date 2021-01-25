#include "dyncardqueue.h"
#include <iostream>

DynCardQueue::DynCardQueue()
{
    front = nullptr;
    rear = nullptr;
    numItems = 0;
}

DynCardQueue::~DynCardQueue()
{
    clear();
}
void DynCardQueue::enqueue(MonsterCard cardIn){

    QueueNode *newNode =nullptr;

    //Create a newnode and store num there
    newNode = new QueueNode;
    newNode->card = cardIn;
    newNode->next = nullptr;

    //Adjust front and rear
    if (isEmpty()) {
        front = newNode;
        rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }

    //Update numItems
    numItems++;
}

MonsterCard DynCardQueue::dequeue(MonsterCard cardOut){

    QueueNode *temp = nullptr;

    if (isEmpty()){
        std::cout << "The play queue is empty\n";
    } else {
        //save the front node value in num
        cardOut=front->card;

        //Remove the front node and delete it
        temp = front;
        front = front->next;
        delete temp;
        numItems--;
    }
    return cardOut;
}

bool DynCardQueue::isEmpty() const{
    bool status;
    if(numItems > 0)
        status = false;
    else
        status = true;
    return status;
}

void DynCardQueue::clear(){
    MonsterCard card;
    while(!isEmpty())
        dequeue(card);
}
