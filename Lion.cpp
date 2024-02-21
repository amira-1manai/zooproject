#include "Lion.h"

Lion::Lion()
{
    qt_viander=0;
}

Lion::Lion(string esp,int m,list<string> date,float q):Animal(esp,m,date)
{
    qt_viander=q;
}

void Lion::afficher()const{
Animal::afficher();
cout<<"Quantite de viande: "<<qt_viander<<endl;
}
Lion::~Lion()
{
    //dtor
}
