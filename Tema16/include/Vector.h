#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>

using namespace std;

class Vector
{
    public:
        Vector(); ///constructor de initializare
        Vector(int*); ///constructor parametrizat
        Vector(const Vector& other); ///constructor de copiere
        virtual ~Vector(); ///destructor
        friend istream& operator>>(istream&,Vector&); ///citire
        friend ostream& operator<<(ostream&,Vector&); ///afisare
        Vector& operator=(const Vector& other); ///atribuire

        int* Get_a() { return a; }
        void Set_a(int* val) { a=val; }

    protected:

    private:
        int* a;
};

#endif // VECTOR_H
