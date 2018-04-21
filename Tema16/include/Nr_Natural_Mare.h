#ifndef NR_NATURAL_MARE_H
#define NR_NATURAL_MARE_H

#include "Vector.h"

class Nr_Natural_Mare
{
    public:
        Nr_Natural_Mare(); ///constructor de initializare
        Nr_Natural_Mare(int); ///constructor paramtrizat 1
        Nr_Natural_Mare(int,Vector); ///constructor parametrizat 2
        Nr_Natural_Mare(const Nr_Natural_Mare& other); ///constructor de copiere
        virtual ~Nr_Natural_Mare(); ///destructor
        friend istream& operator>>(istream&, Nr_Natural_Mare&); ///citire
        friend ostream& operator<<(ostream&, Nr_Natural_Mare&); ///afisare
        Nr_Natural_Mare& operator=(const Nr_Natural_Mare& other); ///atribuire
        Nr_Natural_Mare& operator+(const Nr_Natural_Mare& other); ///adunare
        Nr_Natural_Mare& operator-(const Nr_Natural_Mare& other); ///scadere
        Nr_Natural_Mare& operator*(const Nr_Natural_Mare& other); ///inmultire

        void Setnr_cif(int val) { nr_cif = val; }
        void SetV(Vector val) { V = val; }
        int Getnr_cif(){ return nr_cif; }
        Vector GetV() {return V; }

        bool checkBiggerNumber(Nr_Natural_Mare,Nr_Natural_Mare);
        virtual void citire() { cin>>*this; }
        virtual void afisare() { cout<<*this; }
        void afis(){ cout<<"Baza\n"; }
        virtual void afis2() { cout<<"Baza 2\n"; }

    protected:
        int nr_cif;
        Vector V;

    private:
};

#endif // NR_NATURAL_MARE_H
