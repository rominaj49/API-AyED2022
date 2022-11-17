#ifndef _TSTRINGS_T_
#define _TSTRINGS_T_

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string>
#include <stdlib.h>

using namespace std;

int length(string s)
{
  int i = 0;
   while(s[i]!='\0'){
   i++;
   }
   return i;

}

int charCount(string s,char c)
{
    int i = 0;
    int cont=0;
   while(s[i]!='\0'){

      if (s[i]==c){
     cont++;
      }
    i++;
   }
   return cont;


}

string substring(string s,int d,int h)
{

    string c ="";

   while(d<h){
     
     c = c + s[d];
    d++;
   }

   return c;

}

string substring(string s,int d) // ok
{
   string c ="";

   while(s[d]!='\0'){
     
     c = c + s[d];
    d++;
   }
   
   return c;
}

int indexOf(string s,char c) // ok
{
   int ret= -1;
   int i=0;

  while(i<length(s) && ret==-1){

    if(s[i]!=c){
    i++;
   }
   else{
      ret = i;
    }

  }
   return ret;
}

int indexOf(string s,char c,int offSet) // ok
{

   int ret =-1;

   while(offSet<length(s) && ret==-1){

   if(s[offSet]!=c && ret==-1){

     offSet++;
  }
  else{

     ret= offSet;
  }

}

   return ret;
}

int indexOf(string s,string toSearch) // ok
{
    int ret =-1;
    int i = 0;

   while(i<length(s) && ret==-1){
   if (toSearch[0]==s[i])
   {
      ret=i;
   }
      i++;

   }

   return ret;
}

int indexOf(string s,string toSearch,int offset) // ok
{
   int ret =-1;

   while(offset<length(s) && ret==-1){

   if(s[offset]!=toSearch[0] && ret==-1){

     offset++;
  }
  else{

     ret= offset;
  }

}
   return ret;
}

int lastIndexOf(string s,char c)
{

   int ret=-1;
   int cont=0;


 while(cont<length(s)){

   if(s[cont]==c){

     ret= cont;
  }
  cont++;
  
}

   return ret;
}

int indexOfN(string s,char c,int n)
{
   int ret = -1;
   int cont = 0;
   int nro=0;
   
   while (n!=0 && cont<length(s) && nro!=n){

     if(s[cont]==c && nro<=n){
      ret= cont;
      nro++;
     } 
     else{
      ret= length(s);
     }
    cont++;
   }

   return ret;
}

int charToInt(char c)
{

int ret=0;
if( (int)c>=48 && (int)c<=57){
 ret= (int)c - 48;
}

else if((int)c>=65 && (int)c<=90){
   ret = (int)c-55;
}

return ret;
}

char intToChar(int i)
{

char ret;

if( i>=0 && (i<=9)){
 ret= (char)i + 48;
}

else if(i>=10 && i<=35){
   ret = (char)i+55;
}

return ret;
}

int getDigit(int n,int i)
{
   
 for (int z = 0; z<i; z++)
 {
 n= n/10;  //12345/10=1234
 }

 n=n%10;

return n;
}

int digitCount(int n)
{
 int cont=1;

 while (n/10!=0){
    cont++;
    n= n/10;
 }

return cont;

}

string intToString(int i)
{
string cad = "";
  
   int cont= digitCount(i)-1; //12345;  cont=5
   
   for (int d = 0; d<digitCount(i); d++)
   {
     char c = intToChar(getDigit(i, cont) );
     cad  = cad + c;
     cont--; //cont=4
   }
   
   return cad;
}

int stringToInt(string s,int b) // ok
{

   int valorDecimal=0;
   int cont=length(s)-1;
   int cont2=0;
   while(cont>=0)
   {
      char r=s[cont];
      int x =charToInt(r);
      x=x*pow(b,cont2);
      valorDecimal+=x;
      cont2++;
      cont--;
   }

return valorDecimal;
}

int stringToInt(string s) // ok
{
 
   return stringToInt(s,10);
 
}

string charToString(char c)
{
   string r = "";
   return r + c;
}

char stringToChar(string s)
{  
   return s[0];
}

string stringToString(string s)
{
   
   return s;
}

string doubleToString(double d)
{
   int parteEntera = (int)d;
   double parteDecimal = d-(double)parteEntera;// 0,04 =dos lgares

   while ( (int)parteDecimal==0){
   parteDecimal=parteDecimal*10;

   }

   int partN = (int)parteDecimal;
   string m = intToString(parteEntera) + "." + intToString(partN);

   return m;
}

double stringToDouble(string s)
{
   bool neg = false;
   double r = 0;
   if( s[0]=='-' )
   {
      s = substring(s,1);
      neg = true;
   }
   if( charCount(s,'.')==1 )
   {
      int comLoc = indexOf(s,'.');
      string intLngS = substring(s,0,comLoc);
      string decLngS = substring(s,(comLoc+1));
      int ceros = 0;
      while( indexOfN(decLngS,'0',(ceros+1))==ceros )
      {
         ceros++;
      }
      double intLng = (double)stringToInt(intLngS);
      double decLng = (double)stringToInt(decLngS);
      while( (int)decLng!=0 )
      {
         decLng = decLng/10;
      }
      while( ceros>0 )
      {
         decLng = decLng/10;
         ceros--;
      }
      r = intLng+decLng;
   }
   else
   {
      r = (double)stringToInt(s);
   }
   if( neg )
   {
      r = r*-1;
   }
   return r;
}


bool isEmpty(string s)
{
   return s[0]=='\0';
}

bool startsWith(string s,string x)
{
 bool ret=true;

 for (int i = 0; i < length(x) && ret==true; i++)
 {
  if (x[i]==s[i]){
    ret= true;
  }
  else{
     ret=false;
  }
 }
 return ret;
}

bool endsWith(string s,string x)
{
 int cant = length(x)-1;  //Algoritmos cant=9 x
 int cant2 = length(s)-1;  //cursoDeAlgoritmos cant2=16 s
 int i = length(x)-1;  //Algoritmos cant=9 x
 bool ret=true;

while (i<=length(s)-1 && ret==true)
 {
  if (x[cant]==s[cant2]){
   ret= true;  
   cant2 --;// 15
   cant--; //8
  }

  else{
     ret=false;
  }

 i++;
 }

 return ret;
}

bool contains(string s,char c)
{
  bool ret= false;
   for (int i = 0; i < length(s) && ret==false; i++)
   {
    if (s[i]==c)
    {
      ret= true;
    }  
   }
   
   return ret;
}

string replace(string s,char oldChar,char newChar)
{
string nuevo;
   for (int i = 0; i < length(s); i++)
   {
      if (s[i]==oldChar)
      {
         s[i]=newChar;
         nuevo += s[i];
      }
      else{
         nuevo+= s[i];
      }
   
   }
   return nuevo;
}

string insertAt(string s,int pos,char c)
{
string nuevo;
  for (int i = 0; i<length(s)+1; i++)
   {
      if (i!=pos)
      {
      nuevo = nuevo + s[i]; 
      }

      else{
       nuevo+= c;
       nuevo+=s[i];
      }
   }
   
   return nuevo;
}

string removeAt(string s,int pos)
{
string nuevo;
  for (int i = 0; i<length(s); i++)
   {
      if (i!=pos)
      {
      nuevo = nuevo + s[i]; 
      }

      else{
      i++;
      nuevo += s[i];
      }
   }
   
   return nuevo;
}

string ltrim(string s)
{
   while( s[0]==' ' )
   {
      s = removeAt(s,0);
   }
   return s;
}

string rtrim(string s)
{
 while( s[length(s)-1]==' ' )
   {
      s = removeAt(s,length(s)-1);
   }
   return s;
   }

string trim(string s)
{
   return rtrim(ltrim(s));
}

string replicate(char c,int n)
{
   string b;
   for (int i = 0; i < n; i++)
   {
     b+=c;
   }
   return b;
}

string spaces(int n)
{
   return replicate(' ', n);
}

string lpad(string s,int n,char c)
{
   int pos= n-length(s);
   string b = replicate(c,pos);

   return b+s;
}

string rpad(string s,int n,char c)
{
   return s+ replicate(c,n-length(s));
}

string cpad(string s,int n,char c)
{
   int m= (n+length(s))/2;
   string b= lpad(s,m,c);

   return rpad(b,n,c);
}

bool isDigit(char c)
{
   return (int)c>=48 && (int)c<=57; 

}

bool isLetter(char c)
{
   return ((int)c>=65 && (int)c<=90) || ( (int)c>=97 && (int)c<=122); 
}

bool isUpperCase(char c)
{
return (int)c>=65 && (int)c<=90;

}

bool isLowerCase(char c)
{
 return (int)c>=97 && (int)c<=122; 
}

char toUpperCase(char c)
{
   if(isLowerCase(c)){     
   c= (int)c-32;
   }
   return c;
}

char toLowerCase(char c)
{
    if(isUpperCase(c)){     
   c= (int)c+32;
   }

   return c;
}

string toUpperCase(string s)
{ 
   string m;
   for (int i = 0; i < length(s); i++)
   {
   char d= toUpperCase(s[i]);
   m+= d;
   }
   
   return m;
}

string toLowerCase(string s)
{
  string m;
   for (int i = 0; i < length(s); i++)
   {
   char d= toLowerCase(s[i]);
   m+= d;
   }
   
   return m;
}

int cmpString(string a,string b)
{
   int ret= -1;

   if(a>b){
      ret=1;
   }
   
   else if(a==b){
      ret=0;
   }
   return ret;
}

int cmpDouble(double a,double b)
{
  int ret= -1;

   if(a>b){
      ret=1;
   }
   
   else if(a==b){
      ret=0;
   }
   return ret;
}

#endif
