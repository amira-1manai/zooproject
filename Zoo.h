#ifndef ZOO_H
#define ZOO_H
#include "Animal.h"
#include "Lion.h"
#include "Medecin_Veterinaire.h"
#include <typeinfo>

class Zoo
{
    public:
        Zoo();
        Zoo(list<Medecin_Veterinaire>,list<Animal*>,string);
        //Régles de trois
        ~Zoo();
        Zoo(const Zoo&);
        Zoo& operator=(const Zoo &);
        //Traitements demandés
        list<Animal*>::iterator chercherAnimal(int);
        bool ajouterAnimal(const Animal&);
        bool ajouterAnimal(const Lion&);
        bool ajouterDateAnimal(int,string);
        list<Medecin_Veterinaire>::iterator chercherMedecin(int);
        bool ajouterMedecin(const Medecin_Veterinaire&);
        void affecterAnimalMedecin(int mat,int id);
        void afficherNombreTotalAnimauxMedecins();

        void afficher()const;
        list<Medecin_Veterinaire> Getmedecin() { return medecin; }
        void Setmedecin(list<Medecin_Veterinaire> val) { medecin = val; }
        list<Animal*> Getanimaux() { return animaux; }
        void Setanimaux(list<Animal*> val) { animaux = val; }
        string Getadresse() { return adresse; }
        void Setadresse(string val) { adresse = val; }

    protected:

    private:
        list<Medecin_Veterinaire> medecin;
        list<Animal*> animaux;
        string adresse;
};

#endif // ZOO_H
