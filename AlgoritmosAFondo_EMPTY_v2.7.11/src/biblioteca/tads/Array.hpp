#ifndef _TARR_TAD_
#define _TARR_TAD_

#include <iostream>
#include <stdlib.h>
#include "../funciones/arrays.hpp"

using namespace std;

template<typename T>
struct Array
{
   T* arr;
   int len;
   int cap;
};

template<typename T>
Array<T> array(int cap)
{

   Array<T> a;
   a.arr = new T[cap];
   a.len = 0;
   a.cap = cap;

   return a;
}

template <typename T>
Array<T> array()
{
   return array<T>(1);
}


template<typename T>
int arrayAdd(Array<T>& a,T t)
{
  
   return add<T>(a.arr,a.len,t);
}

template<typename T>
T* arrayGet(Array<T> a,int p)
{
   
  return a.arr+p;  

}

template<typename T>
void arraySet(Array<T>& a,int p,T t)
{
   for (int i = 0; i < a.len; i++)
   { 
      if (i == p)
      {
       a.arr[i]= t;
      }
      
   }
}

template<typename T>
void arrayInsert(Array<T>& a,T t,int p)
{
   insert<T>(a.arr,a.len,t,p);
}

template<typename T>
int arraySize(Array<T> a)
{
   return a.len;
}

template<typename T>
T arrayRemove(Array<T>& a,int p)
{
   return remove<T>(a.arr,a.len,p);
}

template<typename T>
void arrayRemoveAll(Array<T>& a)
{
   a.len = 0;
}

template<typename T,typename K>
int arrayFind(Array<T> a,K k,int cmpTK(T,K))
{
   return find<T>(a.arr,a.len,k, cmpTK);
}

template<typename T>
int arrayOrderedInsert(Array<T>& a,T t,int cmpTT(T,T))
{
   return orderedInsert<T>(a.arr, a.len, t, cmpTT);
}

template<typename T>
void arraySort(Array<T>& a,int cmpTT(T,T))
{
   sort<T>(a.arr,a.len, cmpTT);
}

//copia los elementos de un array, se usa en el TAD Map
template <typename T>
Array<T> copiarArray(Array<T> t)
{
   Array<T> copia = array<T>(arraySize<T>(t));
   for (int i=0; i<arraySize(t);i++)
   {
      arrayAdd<T>(copia,*(arrayGet(t,i)));
   }
   return copia;
}


#endif
