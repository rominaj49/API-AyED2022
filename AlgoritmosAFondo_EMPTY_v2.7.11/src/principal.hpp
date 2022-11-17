#ifndef _MAINHPP
#define _MAINHPP
#include <iostream>
#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include "biblioteca/funciones/strings.hpp"
#include "biblioteca/funciones/tokens.hpp"
#include "biblioteca/tads/Coll.hpp"
using namespace std;

struct Persona
{
	int dni;
	string nom;
};

int cmpPersonaDNI(Persona p,int d)
{
return p.dni-d;
}

string personaToString(Persona x)
{
	char sep = 1;
	string sDni=to_string(x.dni);
	string sNom=x.nom;
	return sDni+sep+sNom;
}

Persona personaFromString(string s)
{
	char sep = 1;
	Persona x;
	string t0 = getTokenAt(s,sep,0);
	x.dni=stoi(t0);
	string t1 = getTokenAt(s,sep,1);
	x.nom=t1;
	return x;
}

string personaToDebug(Persona x)
{
	stringstream sout;
	sout<< "[";
	sout << x.dni;
	sout << ",";
	sout << x.nom;
	sout<< "]";
	return sout.str();
}

string personaToDebug(string mssg,Persona x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << x.dni;
	sout << ",";
	sout << x.nom;
	sout<< "]";
	return sout.str();
}

Persona persona(int dni,string nom)
{
	Persona a;
	a.dni = dni;
	a.nom = nom;
	return a;
}

bool personaEquals(Persona a,Persona b)
{
	if(a.dni!=b.dni) return false;
	if(a.nom!=b.nom) return false;
	return true;
}

#endif
