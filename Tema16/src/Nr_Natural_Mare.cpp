#include "Nr_Natural_Mare.h"

Nr_Natural_Mare::Nr_Natural_Mare()
{
    //constructor de initializare
    nr_cif=0;
    V.Set_a(new int[0]);
}

Nr_Natural_Mare::Nr_Natural_Mare(int x)
{
    //constructor parametrizat 1
    nr_cif=x;
    V.Set_a(new int[nr_cif+1]);
}

Nr_Natural_Mare::Nr_Natural_Mare(int x,Vector v)
{
    //constructor parametrizat 2
    nr_cif=x;
    V=v;
}

Nr_Natural_Mare::Nr_Natural_Mare(const Nr_Natural_Mare& other)
{
    //copy constructor
    nr_cif=other.nr_cif;
    V.Set_a(new int[nr_cif+1]);
    V=other.V;
}

Nr_Natural_Mare::~Nr_Natural_Mare()
{
    //destructor
    delete[] V.Get_a();
}

istream& operator>>(istream &in, Nr_Natural_Mare& rhs)
{
    cout<<"Numar cifre: "; in>>rhs.nr_cif;
    int *v;
    v=new int[rhs.nr_cif+1];
    v[0]=rhs.nr_cif;
    for(int i=1;i<=rhs.nr_cif;i++)
        in>>v[i];
    rhs.V.Set_a(v);
    return in;
}

ostream& operator<<(ostream &out, Nr_Natural_Mare& rhs)
{
    int* v;
    v=rhs.V.Get_a();
    for(int i=1;i<=rhs.nr_cif;i++)
        out<<v[i];
    return out;
}

Nr_Natural_Mare& Nr_Natural_Mare::operator=(const Nr_Natural_Mare& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator

    if (this!=&rhs)
    {
        nr_cif = rhs.nr_cif;
        V = rhs.V;
    }

    return *this;
}

bool Nr_Natural_Mare::checkBiggerNumber(Nr_Natural_Mare a,Nr_Natural_Mare b)
{
    int i;
    for(i=1;i<=a.nr_cif;i++)
        if(a.V.Get_a()[i]>b.V.Get_a()[i])
            return 1; // se poate realiza scaderea in mod normal
        else if(a.V.Get_a()[i]<b.V.Get_a()[i])
            return 0; // se face scaderea invers
}

Nr_Natural_Mare& Nr_Natural_Mare::operator+(const Nr_Natural_Mare& rhs)
{
    static Nr_Natural_Mare x;
    static Nr_Natural_Mare y;
    x=*this;
    y=rhs;
    int carry=0;
    int cifre=0;
    int dif=0;
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
        if(x.nr_cif>=y.nr_cif)
        {
            cifre=x.nr_cif;
            dif=cifre-y.nr_cif;
            //cout<<"CAZ 1"<<endl;
            for(int i=0;i<=cifre;i++)
                v[i]=x.V.Get_a()[i];
            /*for(int j=1;j<=nr_cif;j++)
                cout<<x.V.Get_a()[j];
            cout<<endl;
            cout<<cifre<<" CIFRE"<<endl;*/
            for(int i=cifre;i>dif;i--)
            {
                //cout<<V.Get_a()[i]<<" "<<y.V.Get_a()[i-dif]<<" "<<carry<<endl;
                v[i]=(x.V.Get_a()[i] + y.V.Get_a()[i-dif] + carry)%10;
                carry=(x.V.Get_a()[i] + y.V.Get_a()[i-dif] + carry)/10;
                //cout<<V.Get_a()[i]<<" "<<y.V.Get_a()[i-dif]<<" "<<v[i]<<endl;
                //cout<<"REST "<<carry<<endl;
            }
            if(carry!=0)
            {
                cifre++;
                for(int i=cifre;i>=1;i--)
                    v[i]=v[i-1];
                v[1]=carry;
            }
        }
        else
        {
            cifre=y.nr_cif;
            dif=cifre-x.nr_cif;
            //cout<<"CAZ 2"<<endl;
            for(int i=0;i<=cifre;i++)
                v[i]=y.V.Get_a()[i];
            /*for(int j=1;j<=y.nr_cif;j++)
                cout<<y.V.Get_a()[j];
            cout<<endl;
            cout<<cifre<<" CIFRE"<<endl;*/
            for(int i=cifre;i>dif;i--)
            {
                //cout<<x.V.Get_a()[i-dif]<<" "<<y.V.Get_a()[i]<<" "<<carry<<endl;
                v[i]=(x.V.Get_a()[i-dif] + y.V.Get_a()[i] + carry)%10;
                carry=(x.V.Get_a()[i-dif] + y.V.Get_a()[i] + carry)/10;
                //cout<<x.V.Get_a()[i-dif]<<" "<<y.V.Get_a()[i]<<" "<<v[i]<<endl;
                //cout<<"REST "<<carry<<endl;
            }
            if(carry!=0)
            {
                cifre++;
                for(int i=cifre;i>=1;i--)
                    v[i]=v[i-1];
                v[1]=carry;
            }
        }

        /*for(int h=1;h<=cifre;h++)
            cout<<v[h];
        cout<<'\n';*/

        w= new int[cifre+1];
        w[0]=cifre;
        for(int h=1;h<=cifre;h++)
            w[h]=v[h];
    }

    /*for(int h=1;h<=cifre;h++)
        cout<<w[h];
    cout<<'\n';*/

    x.Setnr_cif(cifre);
    x.V.Set_a(new int[cifre+1]);
    x.V.Set_a(w);

    return x;
}

Nr_Natural_Mare& Nr_Natural_Mare::operator-(const Nr_Natural_Mare& rhs)
{
    static Nr_Natural_Mare x;
    static Nr_Natural_Mare y;
    x=*this;
    y=rhs;
	int borrow=0;
	int cifre=0;
	int dif=0;
	int v[100];
	int *w;

	if(this == &rhs)
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
        if(x.nr_cif<y.nr_cif) {Nr_Natural_Mare aux=x; x=y; y=aux;}
        if(x.nr_cif>=y.nr_cif && checkBiggerNumber(x,y))
        {
            cifre=x.nr_cif;
            dif=cifre-y.nr_cif;
            cout<<"CAZ 1"<<endl;
            for(int i=0;i<=cifre;i++)
                v[i]=x.V.Get_a()[i];
            for(int j=1;j<=cifre;j++)
                cout<<x.V.Get_a()[j];
            cout<<endl;
            cout<<cifre<<"CIFRE"<<endl;
            for(int i=cifre;i>dif;i--)
            {
                if(x.V.Get_a()[i]-borrow>=y.V.Get_a()[i-dif])
                {
                    cout<<"CAZ 1.1"<<endl;
                    cout<<x.V.Get_a()[i]<<" "<<y.V.Get_a()[i-dif]<<" "<<borrow;cout<<endl;
                    v[i]=x.V.Get_a()[i]-y.V.Get_a()[i-dif]-borrow;
                    borrow=0;
                    cout<<x.V.Get_a()[i]<<" "<<y.V.Get_a()[i-dif]<<" "<<v[i];cout<<endl;
                }
                else
                {
                    cout<<"CAZ 1.2"<<endl;
                    cout<<x.V.Get_a()[i]<<" "<<y.V.Get_a()[i-dif];cout<<endl;
                    v[i]=x.V.Get_a()[i]+10-y.V.Get_a()[i-dif]-borrow;
                    borrow=1;
                    cout<<x.V.Get_a()[i]<<" "<<y.V.Get_a()[i-dif]<<" "<<v[i];cout<<endl;
                }
            }
            if(borrow!=0)
            {
                //cout<<"V[DIF]="<<v[dif]<<endl;
                if(v[dif]!=0)
                v[dif]--;
                else if(v[dif]==0 && v[dif-1]!=0)
                {
                    v[dif]=9;
                    v[dif-1]--;
                }
                else
                {   int i=1;
                    while(v[dif-i]==0)
                    {
                        v[dif]=9;
                        v[dif-i]=9;
                        i++;
                    }
                    v[dif-i]--;
                }
            }
        }
        else
        {
			cifre=y.nr_cif;
            dif=cifre-x.nr_cif;
            cout<<"CAZ 2"<<endl;
            for(int i=0;i<=cifre;i++)
                v[i]=y.V.Get_a()[i];
            for(int j=1;j<=cifre;j++)
                cout<<y.V.Get_a()[j];
            cout<<endl;
            for(int i=cifre;i>dif;i--)
            {
                if(y.V.Get_a()[i]-borrow>=x.V.Get_a()[i-dif])
                {
                    cout<<"CAZ 2.1"<<endl;
                    cout<<y.V.Get_a()[i-dif]<<" "<<x.V.Get_a()[i]<<" "<<borrow;cout<<endl;
                    v[i]=y.V.Get_a()[i-dif]-x.V.Get_a()[i]-borrow;
                    borrow=0;
                    cout<<y.V.Get_a()[i-dif]<<" "<<x.V.Get_a()[i]<<" "<<v[i];cout<<endl;
                }
                else
                {
                    cout<<"CAZ 2.2"<<endl;
                    cout<<y.V.Get_a()[i-dif]<<" "<<x.V.Get_a()[i];cout<<endl;
                    v[i]=y.V.Get_a()[i-dif]+10-x.V.Get_a()[i]-borrow;
                    borrow=1;
                    cout<<y.V.Get_a()[i-dif]<<" "<<x.V.Get_a()[i]<<" "<<v[i];cout<<endl;
                }
            }
            if(borrow!=0)
            {
                //cout<<"V[DIF]="<<v[dif]<<endl;
                if(v[dif]!=0)
                v[dif]--;
                else if(v[dif]==0 && v[dif-1]!=0)
                {
                    v[dif]=9;
                    v[dif-1]--;
                }
                else
                {   int i=1;
                    while(v[dif-i]==0)
                    {
                        v[dif]=9;
                        v[dif-i]=9;
                        i++;
                    }
                    v[dif-i]--;
                }
            }
        }

        /*for(int h=1;h<=cifre;h++)
            cout<<v[h];
        cout<<endl;*/

        w=new int[cifre+1];
        w[0]=cifre;
        for(int h=1;h<=cifre;h++)
            w[h]=v[h];
    }

	/*for(int h=1;h<=cifre;h++)
            cout<<w[h];
    cout<<'\n';*/

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

    //cout<<'\n';

    x.Setnr_cif(cifre);
    x.V.Set_a(new int[cifre+1]);
    x.V.Set_a(w);

    return x;
}

Nr_Natural_Mare& Nr_Natural_Mare::operator*(const Nr_Natural_Mare& rhs)
{
    static Nr_Natural_Mare x;
    static Nr_Natural_Mare y;
    static Nr_Natural_Mare z;
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

    x.Setnr_cif(x.nr_cif+y.nr_cif-1);
    x.V.Set_a(new int[x.nr_cif+y.nr_cif]);
    x.V.Set_a(v);

    return x;
}
