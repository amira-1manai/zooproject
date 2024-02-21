#include "Animal.h"

Animal::Animal()
{
    espece="EE";
    mat=0;
}

Animal::Animal(string esp,int m,list<string> date)
{
    espece=esp;
    mat=m;
    date_vaccin=date;
}

void Animal::afficher()const{
    cout<<"espece: "<<espece<<endl;
        cout<<"matricue: "<<mat<<endl;

            for(list<string>::const_iterator i=date_vaccin.begin();i!=date_vaccin.end();++i)
                cout<<*i<<endl;

}
bool Animal::verifierDateVaccin(string date){
 for(list<string>::iterator i=date_vaccin.begin();i!=date_vaccin.end();++i){
    if((*i)==date)
        return true;
 }
 return false;

}

Animal::~Animal()
{
    //dtor
}
