#ifndef _TCOLL_T_
#define _TCOLL_T_

#include <iostream>
#include "../funciones/strings.hpp"

using namespace std;

template<typename T>
struct Coll
{
   string tokens;
   char sep;
   int pos;
};

template<typename T>
Coll<T> coll(char sep)
{

 Coll<T> c;

 c.sep;
 c.tokens;
 c.pos;
 
   return c;
}

template<typename T>
Coll<T> coll()
{
   Coll<T> c;

 c.tokens= "";
 c.sep= '|';
 c.pos=0;

return c;
}

template<typename T>
int collSize(Coll<T> c)
{
   return tokenCount(c.tokens, c.sep);
}

template<typename T>
int collAdd(Coll<T>& c,T t,string tToString(T))
{
 addToken(c.tokens, c.sep, tToString(t));

 return collSize<T>(c)-1;
}

template<typename T>
void collRemoveAll(Coll<T>& c)
{
   c.tokens="";
}

template<typename T>
void collRemoveAt(Coll<T>& c, int p)
{
 removeTokenAt(c.tokens,c.sep,p);

}

template <typename T>
void collSetAt(Coll<T>& c,T t,int p,string tToString(T))
{
   setTokenAt(c.tokens,c.sep,tToString(t), p);
}

template <typename T>
T collGetAt(Coll<T> c,int p,T tFromString(string)) 
{
   T t;
   t= tFromString(getTokenAt(c.tokens,c.sep,p)); //noentiend
   return t;
}


template <typename T, typename K>
int collFind(Coll<T> c,K k,int cmpTK(T,K),T tFromString(string))
{
  int ret = -1;

   for (int i = 0; i < collSize<T>(c)+1; i++)
   {
      T b = collGetAt<T>(c,i,tFromString);

      if ( cmpTK(b,k)>=0 )
      {
         ret=i; //si quiero que retorne en que lugar está, hago i++, muestra solo la posición.
      }
   
   }
   return ret;
}

int cmpIntTK (int t, int k)
{

return t>k?1:t==k?0:-1;
}

int cmpStr(string a, string b){

   return a==b?1:-1;
}


template<typename T>
bool collHasNext(Coll<T> c)
{
   
   return c.pos<(collSize<T>(c));
}

template <typename T>
void collSort(Coll<T>& c,int cmpTT(T,T),T tFromString(string),string tToString(T))
{
   string u="";
   while(c.tokens!="")
   {
      int cont=0;
      int posicion=0;

      T menor= collGetAt(c,cont,tFromString);
      for(cont=1; cont<collSize(c);cont++)
      {
        T n=collGetAt(c,cont,tFromString);
         cmpTT(menor, n);
         if(n<menor)
         {
            menor=n;
            posicion=cont;
         }
      }
      addToken(u,'|',tToString(menor));
      collRemoveAt(c,posicion);
   }
   c.tokens=u;
}

template<typename T>
T collNext(Coll<T>& c,T tFromString(string))
{
   T t=collGetAt<T>(c,c.pos, tFromString);
   c.pos++;
   return t;
}

template<typename T>
T collNext(Coll<T>& c,bool& endOfColl,T tFromString(string))
{
   T t;

   if (endOfColl==true && c.pos==(collSize(c)-1)){
    t = collNext (c, tFromString);
   }
   else{
      endOfColl=false;
   }

   return t;
}

template<typename T>
void collReset(Coll<T>& c)
{
   c.pos=0;
}

template<typename T>
string collToString(Coll<T> c)
{
	return c.sep+c.tokens;
}

template<typename T>
Coll<T> collFromString(string s)
{
	Coll<T> c;
	c.sep=s[0];
	c.tokens=substring(s,1);
	return c;
}

#endif
