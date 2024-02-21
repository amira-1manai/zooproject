#include "Zoo.h"

Zoo::Zoo() {
    //ctor
    adresse="XX";

}

Zoo::~Zoo() {
    //dtor
    cout<<endl;
    cout<<"######################################################"<<endl;
    cout<<"je suis le destructeur de la classe Bibliotheque"<<endl;
    list<Animal*>::iterator i ;
    for(i=animaux.begin(); i!=animaux.end(); i++) {
        delete (*i);
    }
    cout<<endl;
    cout<<"======================================================"<<endl;
}
Zoo::Zoo(const Zoo& Z) {
    adresse= Z.adresse;
    medecin=Z.medecin;
    Animal*p;
    for(list<Animal*>::const_iterator i=Z.animaux.begin(); i != Z.animaux.end(); i++) {
        if(typeid(**i)==typeid(Animal)) {
            p=new Animal(**i);
        } else {
            p=new Lion(static_cast<const Lion&>(**i));
        }
        animaux.push_back(p);
    }
}
Zoo& Zoo::operator=(const Zoo & Z) {
    if(this!=&Z) {
        list<Animal*>::iterator i ;
        for(i=animaux.begin(); i!=animaux.end(); i++) {
            delete (*i);
        }
        animaux.clear();
        medecin.clear();
        adresse= Z.adresse;
        medecin=Z.medecin;
        Animal*p;
        for(list<Animal*>::const_iterator i=Z.animaux.begin(); i != Z.animaux.end(); i++) {
            if(typeid(**i)==typeid(Animal)) {
                p=new Animal(**i);
            } else {
                p=new Lion(static_cast<const Lion&>(**i));
            }
            animaux.push_back(p);
        }
    }
    return (*this);
}
list<Animal*>::iterator Zoo::chercherAnimal(int mat) {
    list<Animal*>::iterator i ;
    for(i=animaux.begin(); i!=animaux.end(); i++) {
        if(mat==(*i)->Getmat())
            return i;
    }
    return animaux.end();
}
bool Zoo::ajouterAnimal(const Animal& A) {
    list<Animal*>::iterator i =chercherAnimal(A.Getmat()) ;
    if(i==animaux.end()) {
        Animal *p=new Animal(A);
        animaux.push_back(p);
        return true;
    } else {
        cout<<"Animal existe!!"<<endl;
        return false;
    }

}
bool Zoo::ajouterAnimal(const Lion&L) {
    list<Animal*>::iterator i =chercherAnimal(L.Getmat()) ;
    if(i==animaux.end()) {
        Animal *p=new Lion(L);
        animaux.push_back(p);
        return true;
    } else {
        cout<<"Lion existe!!"<<endl;
        return false;
    }
}
bool Zoo::ajouterDateAnimal(int mat,string dat) {

    list<Animal*>::iterator i =chercherAnimal(mat) ;
    if(i!=animaux.end()) {
        if((*i)->verifierDateVaccin(dat)) {
            cout<<"Date existe pour cet animal!!"<<endl;
            return false;
        } else {
            list<string> dates=(*i)->Getdate_vaccin();
            dates.push_back(dat);
            (*i)->Setdate_vaccin(dates);
            return true;
        }


    } else {
        cout<<"Animal n existe pas!!"<<endl;
        return false;
    }
}
list<Medecin_Veterinaire>::iterator Zoo::chercherMedecin(int id) {
    for(list<Medecin_Veterinaire>::iterator it=medecin.begin(); it!=medecin.end(); it++) {
        if(id==it-> Getid())
            return it;
    }

    return medecin.end();
}
bool Zoo::ajouterMedecin(const Medecin_Veterinaire& med) {
    list<Medecin_Veterinaire>::iterator it=chercherMedecin(med.Getid());

    if(it!=medecin.end()) {
        medecin.push_back(med);
        return true;
    } else {
        cout<<"Medecin existe!!"<<endl;
        return false;
    }

}

void Zoo::affecterAnimalMedecin(int mat,int id){

list<Animal*>::iterator itAn=chercherAnimal(mat);
list<Medecin_Veterinaire>::iterator itVt=chercherMedecin(id);
try
    {
        if(itVt!=medecin.end() && itAn!=animaux.end()&& !itVt->verifierAnimalMedecin(mat))
            {
                vector<int> matricules = itVt->Getmat_anim();
                matricules.push_back(mat);
                itVt->Setmat_anim(matricules);
                //itVt->Setmat_anim((itVt->Getmat_anim()).push_back(mat))
            }
        else
            throw string("Animal ou Veterinaire inexistant ou bien animal deja affecte au veterinaire\n");

    }
    catch (string const& ch)
    {
        cerr<<ch<<endl;
    }
}
void Zoo::afficherNombreTotalAnimauxMedecins(){
list<Medecin_Veterinaire>::iterator it;
Medecin_Veterinaire med;
for(it=medecin.begin();it!=medecin.end();it++)
    med+=(*it);
unsigned total=(med.Getmat_anim()).size();
cout<<"Total des animaux pris en charge: "<<total<<endl;

}

