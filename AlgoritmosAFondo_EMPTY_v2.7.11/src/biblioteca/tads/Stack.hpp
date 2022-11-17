#ifndef _TSTACK_TAD_
#define _TSTACK_TAD_

#include <iostream>
#include "../funciones/lists.hpp"

using namespace std;

template <typename T>
struct Stack
{
   Node<T>* p;
};

template <typename T>
Stack<T> stack()
{
   Stack<T> st;
   st.p = NULL;
   return st;
}

template <typename T>
T* stackPush(Stack<T>& st, T e)
{
   return &(push<T>(st.p,e)->info);
}

template <typename T>
T stackPop(Stack<T>& st)
{
   return pop<T>(st.p);
}

template <typename T>
bool stackIsEmpty(Stack<T> st)
{
   return isEmpty<T>(st.p);
}

template <typename T>
int stackSize(Stack<T> st)
{
   Node<T>* aux=st.p;
   int cant=0;
   while(aux!=NULL)
   {
      aux=aux->sig;
      cant++;
   }
   return cant;
}

#endif
