#include "Medecin_Veterinaire.h"

Medecin_Veterinaire::Medecin_Veterinaire() {
    id=0;
    nom="";
    prenom="";

}

Medecin_Veterinaire::Medecin_Veterinaire(int id,string nom,string prenom,vector<int> mat) {
    this->id=id;
    this->nom=nom;
    this->prenom=prenom;
    this->mat_anim=mat;
}

void Medecin_Veterinaire::afficher()const {
    cout<<"id: "<<id<<endl;
    cout<<"nom: "<<nom<<endl;
    cout<<"prenom: "<<prenom<<endl;

    cout<<"vector mat_anim: "<<endl;
    for(vector<int>::const_iterator i=mat_anim.begin(); i!=mat_anim.end(); ++i)
        cout<<*i<<endl;

}

Medecin_Veterinaire::~Medecin_Veterinaire() {
    //dtor
}
bool  Medecin_Veterinaire::verifierAnimalMedecin(int mat) {

    for(unsigned i=0; i<mat_anim.size(); i++) {
        if(mat_anim[i]==mat)
            return true;
    }
    return false;
}
Medecin_Veterinaire& Medecin_Veterinaire::operator+=(const Medecin_Veterinaire& med){

for(vector<int>::const_iterator it=med.mat_anim.begin();it!=med.mat_anim.end();it++)
{
    mat_anim.push_back((*it));
}
return(*this);

}

