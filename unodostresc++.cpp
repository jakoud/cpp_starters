#include <iostream>
#include <cmath>
using namespace std;

class punkt
{
    float a, b, c, d;
public:
    punkt(float x=0, float b=0, float c=0, float d=0):a(x), b(b), c(c), d(d)
    {

    }

    //punkt();
    void wypisz();
    //punkt(float, float, float, float);
    void haslo_a(float);
    void haslo_b(float);
    void haslo_c(float);
    void haslo_d(float);
    void haslo(float, float, float, float);
    float dist();
};

int main()
{
    punkt A, B(1,1,1,-1), C(2,-2);
    A.wypisz();
    B.wypisz();
    C.wypisz();
    cout<<"\nPodaj wspolrzedne: "<<endl;
    float xxxx;
    cin>>xxxx;
    C.haslo_c(xxxx);
    C.wypisz();
    cout<<"\nodleglosc punktu B od srodka ukladu to:  "<<B.dist()<<endl;

    punkt D;
    D.wypisz();
    D=B;
    D.wypisz();
    B.wypisz();
    B.haslo_d(200);
    B.wypisz();
    D.wypisz();
    return 0;
}
/*
punkt::punkt()
{
    a=0;
    b=0;
    c=0;
    d=0;
}*/

void punkt::wypisz()
{
    cout<<'('<<a<<','<<b<<','<<c<<','<<d<<')';
    return;
}

/*punkt::punkt(float a, float b, float c, float d)
{
    this->a=a;
    this->b=b;
    this->c=c;
    this->d=d;
}*/
void punkt::haslo_a(float a)
{
    this->a=a;
}
void punkt::haslo_b(float b)
{
    this->b=b;
}
void punkt::haslo_c(float c)
{
    this->c=c;
}
void punkt::haslo_d(float d)
{
    this->d=d;
}
void punkt::haslo(float a, float b, float c, float d)
{
    this->haslo_a(a);
    this->haslo_b(b);
    this->haslo_c(c);
    this->haslo_d(d);
}
float punkt::dist()
{
    return sqrt(a*a+b*b+c*c+d*d);
}
