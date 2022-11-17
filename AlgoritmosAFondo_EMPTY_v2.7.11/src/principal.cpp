#include <iostream>
#include "biblioteca/funciones/strings.hpp"
#include "biblioteca/funciones/tokens.hpp"
#include "biblioteca/funciones/files.hpp"
#include "biblioteca/tads/Array.hpp"
#include "biblioteca/tads/Map.hpp"
#include "biblioteca/tads/List.hpp"
#include "biblioteca/tads/Stack.hpp"
#include "biblioteca/tads/Queue.hpp"
#include "biblioteca/tads/Coll.hpp"
#include "principal.hpp"
using namespace std;



int main()
{
Node<int>* p = NULL;
add<int>(p,2);
add<int>(p,6);
add<int>(p,3); // p->{2,1,3}
sort<int>(p,cmpInt); // p->{1,2,3}

while (p!=NULL)
{
cout << p->info << endl; // Salida: 2

}

return 0;

}




