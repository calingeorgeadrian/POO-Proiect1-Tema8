#include "Vector.h"

Vector::Vector()
{
    //constructor de initializare
    a=new int[0];
}

Vector::Vector(int* x)
{
    //constructor parametrizat

    a=new int [x[0]+1];
    for(int i=0;i<=a[0];i++)
        a[i]=0;
}

Vector::Vector(const Vector& other)
{
    //copy constructor
    a=new int[other.a[0]+1];
    for(int i=0;i<=a[0];i++)
        a[i]=other.a[i];
}

Vector::~Vector()
{
    //destructor
    delete[] a;
}

istream& operator>>(istream &in, Vector& rhs)
{
    int n;
    cout<<"Numar cifre:"; in>>n;
    rhs.a=new int[n+1];
    rhs.a[0]=n;
    for(int i=1;i<=rhs.a[0];i++)
    {
        cout<<"v["<<i<<"]=";
        in>>rhs.a[i];
    }
    return in;
}

ostream& operator<<(ostream &out, Vector& rhs)
{
    for(int i=1;i<=rhs.a[0];i++)
        out<<rhs.a[i]<<" ";
    return out;
}

Vector& Vector::operator=(const Vector& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    if(a[0]!=rhs.a[0])
    {
        delete[] a;
        a=new int[rhs.a[0]+1];
    }
    for(int i=0;i<=a[0];i++)
        a[i]=rhs.a[i];
    return *this;
}
