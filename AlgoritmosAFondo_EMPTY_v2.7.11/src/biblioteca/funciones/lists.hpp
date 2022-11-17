#ifndef _TLIST_T_
#define _TLIST_T_

#include <iostream>
#include <stdio.h>

int cmpInt(int a,int b){
return a-b;
}

template <typename T>
struct Node
{
T info;
Node<T>* sig;
};

template <typename T>
Node<T>* add(Node<T>*& p,T e)
{ 
Node<T>* nuevo = new Node<T>();// creamos nuevo nodo
nuevo->info = e;  //el dato que queremos meter a la lista, osea el nodo nuevo
nuevo->sig = NULL; //declaramos que va a ser el ultimo, por eso el null
   if( p!=NULL )
   {
      Node<T>* aux = p; // creamos una copia del nodo, con su dirección
      while( aux->sig != NULL ){
      aux = aux->sig;
      }
     aux->sig = nuevo;
   }
    else{
    p = nuevo;
   }
   return nuevo;
}

template <typename T>
Node<T>* addFirst(Node<T>*& p,T e)
{
 Node<T>* nuevo = new Node<T>();
 nuevo->info = e;  // al nuevo modo le metemos la información
 nuevo->sig = p;  //(*nuevo).sig = p; decimos que el siguiente de ese nodo va a ser la dirección del nodo P
   
   p = nuevo;  // 
   
   return nuevo;
}

template <typename T, typename K>
T remove(Node<T>*& p,K k,int cmpTK(T,K))
{
    T t;

   Node<T>* sig = p;
   Node<T>* ant = NULL;
   while( sig!=NULL and cmpTK(sig->inf,k)!=0 )
   {
      ant = sig;
      sig = sig->sig;
   }
   if( ant==NULL )
   {
      p = sig->sig;
   }
   else
   {
      ant->sig = sig->sig;
   }
   t = sig->inf;
   delete sig;

   return t;
}

template <typename T>
T removeFirst(Node<T>*& p)
{
   T t= (*p).info;
   delete p;

   return t;
}

template <typename T, typename K>
Node<T>* find(Node<T>* p,K k,int cmpTK(T,K))
{
  Node<T>* sig = p;
  while( sig!=NULL and cmpTK((*sig).info,k)!=0)
   {
    sig = (*sig).sig;
   }

   return sig;
}

template <typename T>
Node<T>* orderedInsert(Node<T>*& p,T e,int cmpTT(T,T))
{
   Node<T>* nuevo = new Node<T>();
   Node<T>* aux = p;
   Node<T>* ant = NULL;
   while( aux!=NULL and cmpTT(aux->info,e)<0 )
   {
      ant = aux;
      aux = aux->sig;
   }
   if( ant==NULL )
   {
      nuevo = addFirst<T>(p,e);
   }
   else
   {
      nuevo->info = e;
      nuevo->sig = aux;
      ant->sig = nuevo;
   }
   return nuevo;
}

template <typename T>
Node<T>* searchAndInsert(Node<T>*& p,T e,bool& enc,int cmpTT(T,T))
{
    enc = true;
   Node<T>* encontro = find<T, T>(p,e,cmpTT);
   if( encontro==NULL )
   {
      encontro = orderedInsert<T>(p,e,cmpTT);
      enc = false;
   }
   return encontro;
}

template <typename T>
void sort(Node<T>*& p,int cmpTT(T,T))
{

  Node<T>* aux = NULL;
   while( p!=NULL )
   {
      T t = removeFirst<T>(p);
      orderedInsert<T>(aux,t,cmpTT);
   } 

   p = aux;
}

template <typename T>
bool isEmpty(Node<T>* p)
{
   return p==NULL;
}

template <typename T>
void free(Node<T>*& p)
{
    while( p!=NULL )
   {
      removeFirst<T>(p);
   }
}

template <typename T>
Node<T>* push(Node<T>*& p,T e)
{
    
   return addFirst<T>(p,e);
}

template <typename T> T pop(Node<T>*& p)
{
   T t = removeFirst<T>(p);
   return t;
}

template <typename T>
Node<T>* enqueue(Node<T>*& p,Node<T>*& q,T e)
{
   Node<T>* nuevo = new Node<T>();
   nuevo->info = e;
   nuevo->sig = NULL;
   if( p==NULL )
   {
      p = nuevo;
   }
   else
   {
      q->sig = nuevo;
   }
   q = nuevo;
   return nuevo;
}

template <typename T>
Node<T>* enqueue(Node<T>*& q,T e)
{
   Node<T>* nuevo = new Node<T>();
   nuevo->info = e;
   if( q==NULL )
   {
      nuevo->sig = nuevo;
   }
   else
   {
      nuevo->sig = q->sig;
      q->sig = nuevo;
   }
   q = nuevo;
   return nuevo;
}

template <typename T>
T dequeue(Node<T>*& p, Node<T>*& q)
{
    T t = removeFirst<T>(p);
   if( p==NULL )
   {
      q = NULL;
   }
   return t;
}

template <typename T>
T dequeue(Node<T>*& q)
{
  Node<T>* aux = q->sig;
   q->sig = aux->sig;
   T t = aux->info;
   if(q==aux)
   {
      q=NULL;
   }
   delete (aux);
   return t;
}

#endif
