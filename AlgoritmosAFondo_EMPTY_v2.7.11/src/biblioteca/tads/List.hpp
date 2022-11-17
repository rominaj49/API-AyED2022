#ifndef _TLIST_TAD_
#define _TLIST_TAD_

#include <iostream>
#include "../funciones/lists.hpp"

using namespace std;

template<typename T>
struct List
{
   Node<T>* p;
   Node<T>* next;
};

template<typename T>
List<T> list()
{
   List<T> lst;
   lst.p = NULL;
   lst.next = NULL;
   return lst;
}

template<typename T>
T* listAdd(List<T>& lst,T e)
{
   Node <T>* r= add(lst.p, e)
   return &(r->info);
}

template<typename T>
T* listAddFirst(List<T>& lst,T e)
{
   Node<T>* r = addFirst<T>(lst.p,e);
   return &(r->info);}

template<typename T,typename K>
T listRemove(List<T>& lst,K k,int cmpTK(T,K))
{
   return remove<T, K>(lst.p,k,cmpTK);
}

template<typename T>
T listRemoveFirst(List<T>& lst)
{
   return removeFirst<T>(lst.p);
}

template <typename T, typename K>
T* listFind(List<T> lst, K k, int cmpTK(T, K))
{
   Node<T>* r = find<T, K>(lst.p,k,cmpTK);
   return &(r->info);
}

template <typename T>
bool listIsEmpty(List<T> lst)
{
   return isEmpty<T>(lst.p);
}

template <typename T>
int listSize(List<T> lst)
{
   int i = 0;
   Node<T>* aux = lst.p;
   while( aux!=NULL )
   {
      aux = aux->sig;
      i++;
   }
   return i;
}

template <typename T>
void listFree(List<T>& lst)
{
   free<T>(lst.p);
}

template <typename T>
T* listOrderedInsert(List<T>& lst, T t, int cmpTT(T, T))
{
   Node<T>* r = orderedInsert<T>(lst.p,t,cmpTT);
   return &(r->info);
}

template <typename T>
void listSort(List<T>& lst, int cmpTT(T, T))
{
   sort<T>(lst.p,cmpTT);
}

template <typename T>
void listReset(List<T>& lst)
{
   lst.next=lst.p;
}

template <typename T>
bool listHasNext(List<T> lst)
{
   return lst.next!=NULL;
}

template <typename T>
T* listNext(List<T>& lst)
{
   Node<T>* r=lst.nex;
   lst.next=lst.next->sig;
   return &(r->info);
}

template <typename T>
T* listNext(List<T>& lst, bool& eol)
{
   T* r = listNext<T>(lst);
   eol = listHasNext<T>(lst);
   return r;
}

#endif
