#ifndef MEDECIN_VETERINAIRE_H
#define MEDECIN_VETERINAIRE_H
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Medecin_Veterinaire
{
    public:
        Medecin_Veterinaire();
        Medecin_Veterinaire(int,string,string,vector<int>);
        ~Medecin_Veterinaire();

        void afficher()const;
        int Getid() const{ return id; }
        void Setid(int val) { id = val; }
        string Getnom() { return nom; }
        void Setnom(string val) { nom = val; }
        string Getprenom() { return prenom; }
        void Setprenom(string val) { prenom = val; }
        vector<int> Getmat_anim() { return mat_anim; }
        void Setmat_anim(vector<int> val) { mat_anim = val; }
        Medecin_Veterinaire& operator+=(const Medecin_Veterinaire&);

        bool verifierAnimalMedecin(int);
    protected:

    private:
        int id;
        string nom;
        string prenom;
        vector<int> mat_anim;
};

#endif // MEDECIN_VETERINAIRE_H
