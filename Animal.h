#ifndef ANIMAL_H
#define ANIMAL_H
#include <string>
#include <list>
#include <iostream>

using namespace std;
class Animal
{
    public:
        Animal();
        Animal(string,int,list<string>);
        virtual void afficher()const;
        virtual ~Animal();
        bool verifierDateVaccin(string);

        string Getespece() { return espece; }
        void Setespece(string val) { espece = val; }
        int Getmat()const { return mat; }
        void Setmat(int val) { mat = val; }
        list<string> Getdate_vaccin() { return date_vaccin; }
        void Setdate_vaccin(list<string> val) { date_vaccin = val; }

    protected:
        string espece;
        int mat;
        list<string> date_vaccin;
};

#endif // ANIMAL_H
