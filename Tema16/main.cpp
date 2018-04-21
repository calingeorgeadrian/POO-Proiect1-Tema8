#include <iostream>
#include "Vector.h"
#include "Nr_Natural_Mare.h"
#include "Numar_Intreg_Mare.h"

using namespace std;

void functie(Nr_Natural_Mare &x)
{
    x.afis();
}

void functie2(Nr_Natural_Mare &x)
{
    x.afis2();
}

int main()
{
    while(1){
        int op;
        cout<<"\nMENIU\n";
        cout<<"[1]Citire/stocare/afisare a n obiecte\n";
        cout<<"[2]Adunare, scadere, inmultire a doua numere naturale mari\n";
        cout<<"[3]Adunare, scadere, inmultire a doua numere intregi mari\n";
        cout<<"[4]Testare downcast\n";
        cout<<"[5]Iesire\n";
        cout<<"Optiune:";
        cin>>op;
        if(op<1 || op>5) break;
        switch(op){
            case 1:{
                Nr_Natural_Mare **b;
                int nrob,i,op2;

                cout<<"Cate obiecte doriti sa creati ?\n";
                cout<<"Numar obiecte: ";cin>>nrob;
                b=new Nr_Natural_Mare*[nrob];

                for(int i=0;i<nrob;i++)
                {
                    cout<<"\nTip obiect "<<i+1<<"\n";
                    cout<<"[1]Obiecte de tip Nr_Natural_Mare\n";
                    cout<<"[2]Obiecte de tip Numar_Intreg_Mare\n";
                    cout<<"Optiune:";
                    cin>>op2;
                    if(op2<1 || op2>2) {cout<<"Tip inexistent. Alegeti din nou.\n"; cout<<"Optiune:"; cin>>op2;}
                    switch(op2){
                    case 1:{
                        b[i]=new Nr_Natural_Mare;
                        b[i]->citire();
                        break;
                        }
                    case 2:{
                        b[i]=new Numar_Intreg_Mare;
                        b[i]->citire();
                        break;
                        }
                    }
                }

                cout<<"\nObiecte create:\n";
                for(int i=0;i<nrob;i++)
                    b[i]->afisare(), cout<<endl;
            break;
            }
            case 2:{
                Nr_Natural_Mare a,b;
                cout<<"NUMARUL A"<<endl;
                cin>>a;
                cout<<"NUMARUL B"<<endl;
                cin>>b;
                cout<<"A: "<<a<<endl;
                cout<<"B: "<<b<<endl;
                cout<<"A+B: "<<a+b<<endl;
                cout<<"A-B: "<<a-b<<endl;
                cout<<"A*B: "<<a*b<<endl;
                cout<<"Rezultatele sunt afisate in valoare absoluta."<<endl;
            break;
            }
            case 3:{
                Numar_Intreg_Mare a,b;
                cin>>a;
                cin>>b;
                cout<<"A: "<<a<<endl;
                cout<<"B: "<<b<<endl;
                cout<<"A+B: "<<a+b<<endl;
                cout<<"A-B: "<<a-b<<endl;
                cout<<"A*B: "<<a*b<<endl;
            break;
            }
            case 4:{
                Nr_Natural_Mare *b=new Numar_Intreg_Mare;
                Numar_Intreg_Mare *a= dynamic_cast<Numar_Intreg_Mare*>(b);
                functie(*a);
                functie2(*a);
            break;
            }
            case 5:
                {
                    return 0;
                }
        }
    }

    return 0;
}
