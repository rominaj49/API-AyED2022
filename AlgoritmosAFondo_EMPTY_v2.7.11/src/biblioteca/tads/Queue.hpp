#ifndef _TQUEUE_TAD_
#define _TQUEUE_TAD_

#include <iostream>
#include "../funciones/lists.hpp"

using namespace std;

template <typename T>
struct Queue
{
   Node<T>* p;
   Node<T>* u;
};

template <typename T>
Queue<T> queue()
{
   Queue<T> q;
   q.p = NULL;
   q.u = NULL;
   return q;
}

template <typename T>
T* queueEnqueue(Queue<T>& q, T e)
{
   return &(enqueue<T>(q.p,q.u,e)->info);
}

template <typename T>
T queueDequeue(Queue<T>& q)
{
   return dequeue<T>(q.p,q.u);
}

template <typename T>
bool queueIsEmpty(Queue<T> q)
{
   return isEmpty<T>(q.p);
}

template <typename T>
int queueSize(Queue<T> q)
{
   Node<T>* aux = q.p;
   int cant = 0;
   while( aux!=NULL )
   {
      aux = aux->sig;
      cant++;
   }
   return cant;
}

#endif
