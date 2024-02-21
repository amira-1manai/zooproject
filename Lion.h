#ifndef LION_H
#define LION_H

#include "Animal.h"


class Lion : public Animal
{
    public:
        Lion();
        Lion(string,int,list<string>,float);
        ~Lion();
        void afficher()const;
        float Getqt_viander() { return qt_viander; }
        void Setqt_viander(float val) { qt_viander = val; }

    protected:

    private:
        float qt_viander;
};

#endif // LION_H
