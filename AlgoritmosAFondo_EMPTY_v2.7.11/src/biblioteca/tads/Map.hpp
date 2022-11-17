
#ifndef _TMAP_TAD_
#define _TMAP_TAD_

#include <iostream>
#include "Array.hpp"

using namespace std;

//compara los k para el arrayFind
template <typename K>
int cmpTK(K x, K y)
{
   return x<y?-1:x>y?1:0;
}

template<typename K,typename V>
struct Map
{
  Array<K> k;
  Array<V> v;
  int pos;
};

template<typename K,typename V>
Map<K,V> map()
{
   Map<K,V> m;
   m.k = array<K>();
   m.v = array<V>();
   m.pos = 0;
   return m;
}

template<typename K,typename V>
V* mapGet(Map<K,V> m,K k)
{
   int p = arrayFind<K,K>(m.k,k, cmpTK);
   return p>=0?arrayGet<V>(m.v,p): NULL;
}

template<typename K,typename V>
V* mapPut(Map<K,V>& m,K k,V v)
{
   int pos= arrayFind<K,K>(m.k,k,cmpTK);
   if (pos>=0)
   {
     arraySet<V>(m.v,v,pos);
   }
   else{
     arrayAdd<K>(m.k,k);
     arrayAdd<V>(m.v,v);
   }

   return mapGet<K,V>(m,k);
}

template<typename K,typename V>
bool mapContains(Map<K,V> m,K k)
{
   return  arrayFind<K,K>(m.k,k,cmpTK)>=0;
}

template<typename K,typename V>
V mapRemove(Map<K,V>& m,K k)
{
   V v= NULL; /* contiene un valor nulo*/
   int pos= arrayFind<K,K>(m.k, k, cmpTK);
   if (pos>=0)
   {
      arrayRemove<K>(m.k,pos);
      v=arrayRemove<V>(m.v,pos); //aca removemos su valor y lo guardamos para luego retornarlo 
   }
   
   return v;
}

template<typename K,typename V>
void mapRemoveAll(Map<K,V>& m)
{

   arrayRemoveAll<K>(m.k);
   arrayRemoveAll<V>(m.v);
}

template<typename K,typename V>
int mapSize(Map<K,V> m)
{
   return arraySize<K>(m.k);
}

template<typename K,typename V>
bool mapHasNext(Map<K,V> m)
{
   return m.pos<mapSize<K,V>(m);
}

template<typename K,typename V>
K mapNextKey(Map<K,V>& m)
{
  K k = *(arrayGet<K>(m.k,m.pos));
   m.pos++;
      return k;
}

template<typename K,typename V>
V* mapNextValue(Map<K,V>& m)
{
   K k = mapNextKey<K, V>(m);
   return mapGet<K, V>(m,k);
}

template<typename K,typename V>
void mapReset(Map<K,V>& m)
{
   m.pos=0;
}

template<typename K,typename V>
void mapSortByKeys(Map<K,V>& m,int cmpKK(K,K))
{
  Array<K> ka = copiarArray<K>(m.k);      
   Array<V> va = array<V>(arraySize<V>(m.v));
   arraySort<K>(ka,cmpKK);

   for( int i = 0; i<arraySize<K>(ka); i++ )
   {
      K k = *(arrayGet<K>(ka,i));
      V v = *(mapGet<K, V>(m,k));
      arrayAdd<V>(va,v);
   }

   m.k = ka;
   m.v = va;}

template<typename K,typename V>
void mapSortByValues(Map<K,V>& m,int cmpVV(V,V))
{

      Array<K> ka = array<K>(arraySize<K>(m.k));
   Array<V> va = copiarArray<V>(m.v);      
   arraySort<V>(va,cmpVV);

   for( int i = 0; i<arraySize<V>(va); i++ )
   {
      V v = *(arrayGet<V>(va,i));
      int pos = arrayFind<V, V>(m.v,v,cmpVV);
      K k = *(arrayGet<K>(m.k,pos));
      arrayAdd<K>(ka,k);
      mapRemove<K, V>(m,k);
   }

   m.k = ka;
   m.v = va;
}

#endif
