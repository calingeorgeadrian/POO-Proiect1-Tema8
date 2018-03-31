#include <iostream>

using namespace std;

class Nod{
    char info;
    Nod* next;
public:
//constructori
    Nod();
    Nod(char,Nod*);
    Nod(Nod&);
//destructori
    ~Nod();
//getter
    char get_info();
    Nod* get_next();
//setter
    void set_info(char);
    void set_next(Nod*);
};

class Coada_de_caractere{
    Nod* prim;
    Nod* ultim;
public:
//constructori
    Coada_de_caractere(Nod*,Nod*);
    Coada_de_caractere(Coada_de_caractere&);
//destructori
    ~Coada_de_caractere();
//getter
    char get_prim();
    char get_ultim();
//setter
    void set_prim(Nod*);
    void set_ultim(Nod*);
//metode
    void push(Nod*);
    void pop();
    bool isempty();
    friend ostream& operator<<(ostream&,Coada_de_caractere&);
    friend istream& operator>>(ostream&,Coada_de_caractere&);
    Coada_de_caractere& operator+(Coada_de_caractere&);
    Coada_de_caractere& operator-(Coada_de_caractere&);
};
Nod::Nod(){info=' ';next=NULL;} //constructor de initializare
Nod::Nod(char c, Nod*p = NULL){info = c;next = p;} //constructor parametrizat
Nod::Nod(Nod &p){info=p.info; next=p.next;} //constructor de copiere
Nod::~Nod(){next=NULL;} //destructor
char Nod::get_info(){return info;}
Nod* Nod::get_next(){return next;}
void Nod::set_info(char a){info=a;}
void Nod::set_next(Nod* b){next=b;}

Coada_de_caractere::Coada_de_caractere(Nod* a=NULL,Nod* b=NULL){prim=a;ultim=b;}
Coada_de_caractere::Coada_de_caractere(Coada_de_caractere &ob){prim=ob.prim; ultim=ob.ultim;}
Coada_de_caractere::~Coada_de_caractere()
{
    Nod* node=prim;
    Nod* next;
    while(node)
    {
        next=node->get_next();
        delete node;
        node=next;
    }
}
char Coada_de_caractere::get_prim(){if (prim) return prim->get_info(); else return '0';}
char Coada_de_caractere::get_ultim(){if (ultim) return ultim->get_info();else return '0';}
void Coada_de_caractere::set_prim(Nod* a){prim=a;}
void Coada_de_caractere::set_ultim(Nod* a){ultim=a;}
void Coada_de_caractere::push(Nod* a)
{
    if(!this->isempty()) //daca coada nu este goala, ultim devine a
    {
        ultim->set_next(a);
        ultim=a;
        ultim->set_next(NULL);
    }
    else //daca coada este goala, prim si ultim devin a
    {
        prim=ultim=a;
        prim->set_next(NULL);
        ultim->set_next(NULL);
    }
}

void Coada_de_caractere::pop()
{
    if(prim) //daca exista elemente in coada executam pop
        {
            if(prim==ultim) //daca exista un singur element in coada, golim coada
                this->set_ultim(NULL);
            this->set_prim(prim->get_next());
         }
 }

bool Coada_de_caractere::isempty(){if(!prim) return 1; else return 0;}

ostream& operator<<(ostream &out,Coada_de_caractere &c)
{
    while(!c.isempty())
    {
        out<<c.prim->get_info();
        c.pop();
    }
    return out;
}

istream& operator>>(istream&in,Coada_de_caractere &c)
{
    Nod *p;
    char a;
    in>>a;
    while(a!='~') //citirea se realizeaza pana la intalnirea caracterului ~
    {
        p=new Nod;
        p->set_info(a);
        c.push(p);
        in>>a;
    }
    return in;
}

Coada_de_caractere& Coada_de_caractere::operator+(Coada_de_caractere &c)
{
    Nod *p;
    Coada_de_caractere *f;
    f=new Coada_de_caractere;
    while(!this->isempty()) //adaugam elementele cozii this in coada f
    {
        p=new Nod;
        p->set_info(this->get_prim());
        f->push(p);
        this->pop();
    }

    while(!c.isempty()) //adaugam elementele cozii c in coada f
    {
        p=new Nod;
        p->set_info(c.get_prim());
        f->push(p);
        c.pop();
    }
    return (*f); //returnam cele doua cozi concatenate prin coada f
}

Coada_de_caractere& Coada_de_caractere::operator-(Coada_de_caractere &c)
{
    Nod *h;
    Coada_de_caractere *p;
    p=new Coada_de_caractere;

    while(!this->isempty() && !c.isempty())
    {
        if(this->get_prim() > c.get_prim())
        {
            h=new Nod;
            h->set_info(this->get_prim());
            p->push(h);
        }
        else
        {
            h=new Nod;
            h->set_info(c.get_prim());
            p->push(h);
        }
        c.pop();
        this->pop();
    }
    return (*p);
}

int main()
{
    Coada_de_caractere a;

    while(1){
        int op;
        cout<<"\nMENIU\n";
        cout<<"[1]Citire/stocare/afisare a n obiecte\n";
        cout<<"[2]Operatii pe clasa initiala\n";
        cout<<"[3]Operatii pe clasa principala\n";
        cout<<"[4]Iesire\n";
        cout<<"Optiune:";
        cin>>op;
        if(op<1 || op>4) break;
        switch(op){
            case 1:{
                int i,n;
                Coada_de_caractere m[100];
                cout<<"N=";cin>>n;
                for(i=0;i<n;i++)
                    {
                        cout<<"Coada "<<i+1<<":";
                        cin>>m[i];
                    }
                for(i=0;i<n;i++)
                    cout<<m[i]<<endl;
            break;
            }
            case 2:{
                Nod x;
                char a;
                while(1)
                {
                    int op2;
                    cout<<"\nMENIU 2\n";
                    cout<<"[1]Citire nod\n";
                    cout<<"[2]Afisare nod\n";
                    cout<<"[3]Copiere si afisare nod\n";
                    cout<<"Optiune:";
                    cin>>op2;
                    if(op2<1 || op2>3) break;
                    switch(op2){
                        case 1:{cout<<"Nod X: ";cin>>a;x.set_info(a);break;}
                        case 2:{cout<<"Nod X: "<<x.get_info()<<endl;break;}
                        case 3:{Nod y=x;cout<<"Nod Y: "<<y.get_info()<<endl;break;}
                    }
                }
            break;
            }
            case 3:{
                while(1)
                {
                    int op3;
                    cout<<"\n\nMENIU 3\n";
                    cout<<"[1]Citire coada (citirea se incheie cu caracterul ~)\n";
                    cout<<"[2]Afisare coada (necesita citire in prealabil)\n";
                    cout<<"[3]Copiere si afisare coada (necesita citire in prealabil)\n";
                    cout<<"[4]Supraincarcare operator +\n";
                    cout<<"[5]Supraincarcare operator -\n";
                    cout<<"Optiune:";
                    cin>>op3;
                    if(op3<1 || op3>5) break;
                    switch(op3){
                        case 1:{cout<<"Coada: ";cin>>a;break;}
                        case 2:{cout<<"Coada: "<<a<<endl;break;}
                        case 3:{Coada_de_caractere b=a; cout<<"Coada: "<<b<<endl;break;}
                        case 4:{
                            Coada_de_caractere a,b,c;
                            cout<<"Coada A: ";cin>>a;
                            cout<<"Coada B: ";cin>>b;
                            c=a+b;
                            cout<<"Coada C: ";cout<<c<<endl;
                            break;
                        }
                        case 5:{
                            Coada_de_caractere a,b,c;
                            cout<<"Coada A: ";cin>>a;
                            cout<<"Coada B: ";cin>>b;
                            c=a-b;
                            cout<<"Coada C: ";cout<<c<<endl;
                            break;
                        }
                    }
                }
            break;
            }
            case 4:{
                return 0;
            }
        }
    }

    return 0;
}
