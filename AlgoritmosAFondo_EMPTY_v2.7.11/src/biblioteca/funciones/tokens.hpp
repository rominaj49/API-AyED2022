#ifndef _TTOKENS_T_
#define _TTOKENS_T_

#include <iostream>
#include <stdio.h>
#include "strings.hpp"
using namespace std;

int tokenCount(string s,char sep)
{
 int ret = 0;

 if (s!="")
{
   if (charCount(s,sep)!=0)
   {
     ret = charCount(s,sep)+1;
   }

 else{
    ret = 1 ;
 }

}
   return ret;
}

void addToken(string& s,char sep,string t) 
{
   if(s==""){
     s= t;
   }
   else{
   s=s + sep + t;
   }

}

string getTokenAt(string s,char sep, int i)
{

   int pos = indexOfN(s,sep,i); // da -1
   int posM = indexOfN(s,sep,i+1); // da la siguiente posicion en q esta el |

   return substring(s,pos+1,posM);
}

void removeTokenAt(string& s,char sep, int i)
{
   string r = "",t = "";
   for( int l = 0; l<=(tokenCount(s,sep))-1; l++ )
   {
      r = getTokenAt(s,sep,l);

      if( l!=i )
      {
         addToken(t,sep,r);

      }
   }
   s = t;
}

void setTokenAt(string& s,char sep, string t,int i)
{
string r = "", d = "";

   for( int l = 0; l<=(tokenCount(s,sep))-1; l++ )
   {
      r = getTokenAt(s,sep,l);

      if( l!=i )
      {
         addToken(d,sep,r);

      }
      else{
         addToken(d,sep,t);
      }
   }
   s = d;

}

int findToken(string s,char sep, string t)
{
   int ret = -1;

   for (int i = 0; i < tokenCount(s,sep); i++)
   {
      string d = getTokenAt(s,sep,i);

      if (d==t)
      {
         ret=i;
      }
   
   }
   return ret;
}

#endif
