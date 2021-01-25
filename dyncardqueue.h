#ifndef DYNCARDQUEUE_H
#define DYNCARDQUEUE_H
#include "MonsterCard.h"

class DynCardQueue
{
    public:
        DynCardQueue();
        ~DynCardQueue();
        void enqueue(MonsterCard);
        MonsterCard dequeue(MonsterCard);
        bool isEmpty() const;
        bool isFull() const;
        void clear();
    private:
        struct QueueNode{
            MonsterCard card;
            QueueNode *next;
        };

    QueueNode *front;
    QueueNode *rear;
    int numItems;

};


#endif // DYNCARDQUEUE_H
