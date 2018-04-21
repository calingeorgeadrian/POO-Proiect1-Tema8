#include "Numar_Intreg_Mare.h"

Numar_Intreg_Mare::Numar_Intreg_Mare():Nr_Natural_Mare()
{
    //constructor de initializare
    semn='+';
}

Numar_Intreg_Mare::Numar_Intreg_Mare(char s):Nr_Natural_Mare()
{
    //constructor parametrizat 1
    semn=s;
}

Numar_Intreg_Mare::Numar_Intreg_Mare(char s,int n):Nr_Natural_Mare(n)
{
    //constructor parametrizat 2
    semn=s;
}

Numar_Intreg_Mare::Numar_Intreg_Mare(char s,int n, Vector v):Nr_Natural_Mare(n,v)
{
    //constructor parametrizat 3
    semn=s;
}

Numar_Intreg_Mare::Numar_Intreg_Mare(const Numar_Intreg_Mare& other):Nr_Natural_Mare(other)
{
    //copy constructor
    semn=other.semn;
}

Numar_Intreg_Mare::~Numar_Intreg_Mare()
{
    //destructor
    delete[] V.Get_a();
}

istream& operator>>(istream &in, Numar_Intreg_Mare& rhs)
{
    char s;
    cout<<"Semn: "; in>>s;
    if(s=='+' || s=='-')
        rhs.semn=s;
    else while(s!='+' && s!='-')
    {
        cout<<"Semn invalid.\n";
        cout<<"Semn: "; in>>s;
    }
    in>>(Nr_Natural_Mare&)rhs;
    return in;
}

ostream& operator<<(ostream &out, Numar_Intreg_Mare& rhs)
{
    out<<rhs.semn;
    out<<(Nr_Natural_Mare&)rhs;
    return out;
}

Numar_Intreg_Mare& Numar_Intreg_Mare::operator=(const Numar_Intreg_Mare& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator

    if (this!=&rhs)
    {
        nr_cif=rhs.nr_cif;
        V=rhs.V;
        semn=rhs.semn;
    }

    return *this;
}

Numar_Intreg_Mare& Numar_Intreg_Mare::operator+(Numar_Intreg_Mare& rhs)
{
    static Numar_Intreg_Mare x;
    static Numar_Intreg_Mare y;
    x=*this;
    y=rhs;
    int carry=0;
    int cifre=0;
    int v[100];
    int *w;

    if(this == &rhs)
    {
        for(int i=x.nr_cif;i>=1;i--)
        {
            v[i]=(x.V.Get_a()[i]*2 + carry)%10;
            carry=(x.V.Get_a()[i]*2 + carry)/10;
        }

        if(carry!=0)
        {
            x.nr_cif+=1;
            for(int j=x.nr_cif;j>=2;j++)
                v[j]=v[j-1];
            v[1]=carry;
        }

        w= new int[x.nr_cif+1];
        w[0]=nr_cif;
        for(int h=0;h<=x.nr_cif;h++)
            w[h]=v[h];
    }
    else
    {
        //cout<<x.nr_cif<<" "<<y.nr_cif<<endl;
        if(x.semn==y.semn)
        {
			Nr_Natural_Mare a, b, c;
			a.Setnr_cif(x.nr_cif);
			b.Setnr_cif(y.nr_cif);
			a.SetV(x.V);
			b.SetV(y.V);
			c=a+b;
			x.nr_cif=c.Getnr_cif();
			x.V=c.GetV();
			return x;
        }
		else if(x.nr_cif>=y.nr_cif && x.semn!=y.semn)
		{
			Nr_Natural_Mare a, b, c;
			a.Setnr_cif(x.nr_cif);
			b.Setnr_cif(y.nr_cif);
			a.SetV(x.V);
			b.SetV(y.V);
			c=a-b;
			x.nr_cif=c.Getnr_cif();
			x.V=c.GetV();
			return x;
		}
        else if(x.nr_cif<y.nr_cif && x.semn!=y.semn)
        {
			Nr_Natural_Mare a, b, c;
			a.Setnr_cif(x.nr_cif);
			b.Setnr_cif(y.nr_cif);
			a.SetV(x.V);
			b.SetV(y.V);
			c=b-a;
			x.semn=y.semn;
			x.nr_cif=c.Getnr_cif();
			x.V=c.GetV();
			return x;
        }
    }

    x.Setnr_cif(cifre);
    x.V.Set_a(new int[cifre+1]);
    x.V.Set_a(w);

    return x;
}


Numar_Intreg_Mare& Numar_Intreg_Mare::operator-(Numar_Intreg_Mare& rhs)
{
    static Numar_Intreg_Mare x;
    static Numar_Intreg_Mare y;
    x=*this;
    y=rhs;
	int cifre=0;
	int v[100];
	int *w;

	if(this == &rhs)
	{
	    x.Setnr_cif(1);
        w=new int[2];
        w[0]=1;
        w[1]=0;
        x.GetV().Set_a(w);
		return x;
	}
	else
    {
        if(x.semn==y.semn && ((x.nr_cif==y.nr_cif && checkBiggerNumber(x,y)) || (x.nr_cif>y.nr_cif)))
        {
            //cout<<"CAZ 1"<<endl;
			Nr_Natural_Mare a, b, c;
			a.Setnr_cif(x.nr_cif);
			b.Setnr_cif(y.nr_cif);
			a.SetV(x.V);
			b.SetV(y.V);
			c=a-b;
			x.nr_cif=c.Getnr_cif();
			x.V=c.GetV();
			return x;
        }
        else if(x.semn==y.semn && x.nr_cif==y.nr_cif && !checkBiggerNumber(x,y))
        {
            //cout<<"CAZ 2"<<endl;
			Nr_Natural_Mare a, b, c;
			a.Setnr_cif(x.nr_cif);
			b.Setnr_cif(y.nr_cif);
			a.SetV(x.V);
			b.SetV(y.V);
			c=a-b;
			if(x.semn=='+')
                x.semn='-';
            else x.semn='+';
			x.nr_cif=c.Getnr_cif();
			x.V=c.GetV();
			return x;
        }
        else if(x.semn==y.semn && x.nr_cif<y.nr_cif)
        {
            //cout<<"CAZ 3"<<endl;
			Nr_Natural_Mare a, b, c;
			a.Setnr_cif(x.nr_cif);
			b.Setnr_cif(y.nr_cif);
			a.SetV(x.V);
			b.SetV(y.V);
			c=b-a;
			if(x.semn=='+')
                x.semn='-';
            else x.semn='+';
			x.nr_cif=c.Getnr_cif();
			x.V=c.GetV();
			return x;
        }
        else
        {
            //cout<<"CAZ 4"<<endl;
			Nr_Natural_Mare a, b, c;
			a.Setnr_cif(x.nr_cif);
			b.Setnr_cif(y.nr_cif);
			a.SetV(x.V);
			b.SetV(y.V);
			c=a+b;
			x.nr_cif=c.Getnr_cif();
			x.V=c.GetV();
			return x;
        }
    }

    int ok=0,k;
    for(int h=1;h<=cifre;h++)
        if(v[h]!=0)
        {
            ok=1;
            k=h;
            break;
        }

    if(ok==0)
    {
        x.Setnr_cif(1);
        w=new int[2];
        w[0]=1;
        w[1]=0;
        x.V.Set_a(w);
        return x;
    }
    else
    {
        int u[100];
        for(int i=k;i<=cifre;i++)
            u[i-k+1]=v[i];
        w=new int[cifre-k+2];
        w[0]=cifre-k+1;
        for(int i=1;i<=cifre-k+1;i++)
            w[i]=u[i];
        x.Setnr_cif(cifre-k+1);
        x.V.Set_a(w);
        return x;
    }

    x.Setnr_cif(cifre);
    x.V.Set_a(new int[cifre+1]);
    x.V.Set_a(w);

    return x;
}

Numar_Intreg_Mare& Numar_Intreg_Mare::operator*(Numar_Intreg_Mare& rhs)
{
    static Numar_Intreg_Mare x;
    static Numar_Intreg_Mare y;
    static Numar_Intreg_Mare z;
	x=*this;
    y=rhs;
	int *v;
	v=new int[x.nr_cif+y.nr_cif];

	for(int i=0;i<=x.nr_cif+y.nr_cif;i++)
		v[i]=0;
    v[0]=x.nr_cif+y.nr_cif;

	for(int i=x.nr_cif;i>=1;i--)
	{
		for(int j=y.nr_cif;j>=1;j--)
		{
			v[i+j-1]+=x.V.Get_a()[i]*y.V.Get_a()[j];
		}
	}

	for(int i=x.nr_cif+y.nr_cif-1;i>=2;i--)
	{
		if(v[i]>=10)
		{
			v[i-1]+=v[i]/10;
			v[i]%=10;
		}
	}

	if(x.semn!=y.semn)
        x.semn='-';

    x.Setnr_cif(x.nr_cif+y.nr_cif-1);
    x.V.Set_a(new int[x.nr_cif+y.nr_cif]);
    x.V.Set_a(v);

    return x;
}
