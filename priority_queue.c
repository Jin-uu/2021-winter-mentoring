#include "priority_queue.h"
#include <stdlib.h>

static void pq_expend(priority_queue *this)
{
    this -> body = realloc(this -> body, this -> capacity * sizeof(int) *2);
    this -> capacity *= 2;
}

priority_queue *pq_alloc(int capacity)
{
    priority_queue *new_pq = malloc(sizeof(priority_queue));
    new_pq -> body = malloc(sizeof(int)*capacity);
    new_pq -> capacity = capacity;
    new_pq -> length = 0;
    return new_pq;
}

void pq_free(priority_queue *this)
{
    free(this -> body);
    free(this);
}

int *pq_top(priority_queue *this)
{
    return &(this -> body[1]);
}

bool pq_enqueue(priority_queue *this, int elem)
{
    if(this -> capacity == this -> length + 1)
        pq_expend(this);
    this -> length ++;
    int now = this -> length;
    this -> body[now] = elem;
    int temp;
    while(now != 1)
    {
        if(this -> body[now] > this -> body[now/2])
        {
            temp = this -> body[now];
            this -> body[now] = this -> body[now/2];
            this -> body[now/2] = temp;
            now = now/2;
        }
        else
            return true;
    }
    return true;
}

bool pq_dequeue(priority_queue *this)
{
    this -> body[1] = this -> body[this -> length];
    int now = 1;
    int temp;
    this -> length --;
    while(now <= this -> length / 2)
    {
        int k = now*2;
        if( this -> body[now*2] < this -> body[now*2 +1])
            k = now*2 + 1;
        if( this -> body[now] < this -> body[k])
        {
            temp = this -> body[now];
            this -> body[now] = this -> body[k];
            this -> body[k] = temp;
            now = k;
        }
        else
            return true;
    }
        return true;
}

bool pq_is_empty(priority_queue *this)
{
    if(this -> length == 0)
        return true;
    return false;
}





