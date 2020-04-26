#include <iostream>
#include <ctime>
#include <cstdlib>


using namespace std;

class lista{
public:
	class element{
	public:
		int klucz;
		element *nastepny, *poprzedni;
		element(int x):klucz(x), nastepny(NULL), poprzedni(NULL){}
	};
	element *glowa, *ogon;
	lista():glowa(NULL), ogon(NULL){}
	void dodaj(element *za, element *kogo);
	element *zrob(int x){return new element(x);}
	element *usun(element *kogo);
	void anihiluj(element *kogo){delete usun(kogo);}
	~lista(){while(ogon)anihiluj(ogon);}
	bool czy_nalezy(element *ten);
	friend ostream &operator<<(ostream &out, lista &L);
};

void listSort_wstawianie(lista &L){
	if(L.glowa==NULL || L.glowa==L.ogon){
		return;
	}
	else{
		lista P;
		while(L.glowa){
			P.dodaj(P.ogon, L.usun(L.glowa));
		}
		lista::element *i;
		L.dodaj(NULL, P.usun(P.ogon));
		while(P.ogon){
			i=L.glowa;
			while(i){
				if(i->klucz>P.ogon->klucz){
					L.dodaj(i->poprzedni, P.usun(P.ogon));
					break;
				}
				else{
					i=i->nastepny;
				}
			}
			if(!i){
				L.dodaj(L.ogon, P.usun(P.ogon));
			}
		}
		return;
	}
}

int main(){
	srand(time(NULL));
	int ile;
	cout<<"ile liczb chcesz: ";
	cin>>ile;

	lista L;

	for(int i=0;i<ile;++i)
		L.dodaj(NULL, L.zrob(rand()%99+10));

	cout<<L<<endl;
	listSort_wstawianie(L);
	cout<<L<<endl;

	return 0;
}

void lista::dodaj(element *za, element *kogo){
	if(kogo){
		if(!za){
			if(!glowa){
				glowa=kogo;
				ogon=kogo;
				}
			else{
				kogo->nastepny=glowa;
				glowa->poprzedni=kogo;
				glowa=kogo;
			}
		}
		else if(za==ogon){
			kogo->poprzedni=ogon;
			ogon->nastepny=kogo;
			ogon=kogo;
		}
		else{
			kogo->nastepny=za->nastepny;
			kogo->poprzedni=za;
			kogo->nastepny->poprzedni=kogo;
			za->nastepny=kogo;
		}
	}
}
lista::element *lista::usun(element *kogo){
	if(czy_nalezy(kogo)){
		if(kogo==glowa){
			if(kogo==ogon){
				glowa=ogon=NULL;
			}
			else{
				glowa->nastepny->poprzedni=NULL;
				glowa=glowa->nastepny;
				kogo->nastepny=NULL;
			}
		}
		else if(kogo==ogon){
			ogon->poprzedni->nastepny=NULL;
			ogon=ogon->poprzedni;
			kogo->poprzedni=NULL;
		}
		else{
			kogo->nastepny->poprzedni=kogo->poprzedni;
			kogo->poprzedni->nastepny=kogo->nastepny;
			kogo->nastepny=NULL;
			kogo->poprzedni=NULL;
		}
		return kogo;
	}
	return NULL;
}

bool lista::czy_nalezy(element *ten){
	if(ten){
		element *pomocnik=glowa;
		while(pomocnik)
			if(pomocnik==ten)
				return true;
			else
				pomocnik=pomocnik->nastepny;
		return false;
	}
}

ostream &operator<<(ostream &out, lista &L){
if (L.ogon){
	lista::element *i=L.glowa;
	while(i){
		cout<<i->klucz<<' ';
		i=i->nastepny;
	}
}
return out;
}
