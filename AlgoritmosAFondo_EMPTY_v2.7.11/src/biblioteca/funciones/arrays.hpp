#ifndef _TARRAYS_T_
#define _TARRAYS_T_

#include <iostream>

template <typename T>
int add(T arr[], int& len, T e)
{
   arr[len] = e;
   len++;
   return len-1;
}

template <typename T>
void insert(T arr[], int& len, T e, int p)
{
   for( int i = len-1; i>=p; i-- )
   {
      arr[i+1] = arr[i];
   }
   arr[p] = e;
   len++;
}

template <typename T>
T remove(T arr[],int& len,int p)
{
   T ret= arr[p];

   for (int i = p; i < len; i++)
   {
      arr[i]=arr[i+1];

    }
      len--;

   return ret;
}

template <typename T, typename K>
int find(T arr[],int len,K k,int cmpTK(T,K))
{
int ret=-1;
int i = 0;
    while (i< len)
   {
      if ( cmpTK(arr[i], k )==0 )
      {
       ret=i++; //si quiero que retorne en que lugar está, hago i++, muestra solo la posición.
      }
      i++;

   }
   return ret;
}

template <typename T>
int orderedInsert(T arr[],int& len,T e,int cmpTT(T,T))
{
 int i = 0;
 while ( i<len && cmpTT(arr[i],e)<0 )  // 0-4 = -4 | 1-4=-3 | 2-4= -2 | 3-4= -1 | 4-4 = 0 | 5-4= 1 cumple
 {
 i++;
 }
   insert<T>(arr,len,e,i);
   return i;
}

template <typename T>
void sort(T arr[],int len,int cmpTT(T,T))
{

   for (int i = 1; i < len; i++)
   {
      for (int j = 0; j < len-1; j++)
      {
         T a = arr[j];
         T b = arr[j+1];

         if ( cmpTT(a,b)>0 )   // 50-20 = 30   o 20 - 30 = -10
         {
           arr[j] = b;
           arr[j+1]= a;
         }
      }
   }
   
   return;
}



#endif
