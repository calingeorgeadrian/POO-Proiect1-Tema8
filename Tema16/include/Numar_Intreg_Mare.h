#ifndef NUMAR_INTREG_MARE_H
#define NUMAR_INTREG_MARE_H

#include "Nr_Natural_Mare.h"


class Numar_Intreg_Mare : public Nr_Natural_Mare
{
    public:
        Numar_Intreg_Mare(); ///constructor de initializare
        Numar_Intreg_Mare(char); ///constructor parametrizat 1
        Numar_Intreg_Mare(char,int); ///constructor parametrizat 2
        Numar_Intreg_Mare(char,int,Vector); ///constructor parametrizat 3
        Numar_Intreg_Mare(const Numar_Intreg_Mare& other); ///constructor de copiere
        virtual ~Numar_Intreg_Mare(); ///destructor
        friend istream& operator>>(istream&,Numar_Intreg_Mare&); ///citire
        friend ostream& operator<<(ostream&,Numar_Intreg_Mare&); ///afisare
        Numar_Intreg_Mare& operator=(const Numar_Intreg_Mare& other); ///atribuire
        Numar_Intreg_Mare& operator+(Numar_Intreg_Mare& other); ///adunare
        Numar_Intreg_Mare& operator-(Numar_Intreg_Mare& other); ///scadere
        Numar_Intreg_Mare& operator*(Numar_Intreg_Mare& other); ///inmultire

        char Getsemn() { return semn; }
        void Setsemn(char val) { semn = val; }

        void citire() { cin>>*this; }
        void afisare() { cout<<*this; }
        void afis() { cout<<"Derivata\n"; }
        void afis2() { cout<<"Derivata 2\n"; }

    protected:

    private:
        char semn;
};

#endif // NUMAR_INTREG_MARE_H
