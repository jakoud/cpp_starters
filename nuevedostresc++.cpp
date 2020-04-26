#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

class drzewo{
public:
	class wezel{
	public:
		int klucz;
		wezel *ojciec, *lewySyn, *prawySyn;
		wezel(int x=0):klucz(x), ojciec(NULL), lewySyn(NULL), prawySyn(NULL){}
	};
	wezel *korzen;
	drzewo():korzen(NULL){}
	void dodaj(int n);
	void wypiszIO(wezel*);
	void pali(wezel*);
	~drzewo(){pali(korzen);}
	wezel *najwiekszy(wezel*);
	wezel *poprzednik(wezel*);
	void usun(wezel*);
	void wszerz(wezel *);
};

class kolejka{
public:
	class el{
	public:
		drzewo::wezel *klucz;
		el *nast;
		el(drzewo::wezel *x):klucz(x), nast(NULL){}
	};
	el *glowa, *ogon;
	kolejka():glowa(NULL), ogon(NULL){}
	void dodaj(drzewo::wezel *x);
	drzewo::wezel *usun();
};

int main (){
	srand(time(NULL));
	int ile;
	cout<<"ile wylosowac:	";
	cin>>ile;
	drzewo Buk;
	int los;
	for(int i=0; i<ile; i++){
		los=rand()%50+1;
		cout<<los<<", ";
		Buk.dodaj(los);
	}
	cout<<endl;
	Buk.wypiszIO(Buk.korzen);
	cout<<endl;
	Buk.wszerz(Buk.korzen);
	return 0;
}


void drzewo::dodaj(int n){
	wezel *nowy=new wezel(n);
	if(korzen==NULL){
		korzen=nowy;
	}
	else{
		wezel *i=korzen;
		while(true){
			if(nowy->klucz<i->klucz){
				if(i->lewySyn){
						i=i->lewySyn;
					}
				else{
					i->lewySyn=nowy;
					nowy->ojciec=i;
					break;
				}
			}
			else{
				if(i->prawySyn){
					i=i->prawySyn;
					}
				else{
					i->prawySyn=nowy;
					nowy->ojciec=i;
					break;
				}
			}
		}
	}
}

void drzewo::wypiszIO(wezel *startowy){
	if(startowy !=NULL){
		wypiszIO(startowy->lewySyn);
		cout<<startowy->klucz<<", ";
		wypiszIO(startowy->prawySyn);
	}
}

void drzewo::pali(wezel *startowy){
if(startowy!=NULL){
		pali(startowy->lewySyn);
		pali(startowy->prawySyn);
		delete startowy;
	}
}

drzewo::wezel *drzewo::najwiekszy(wezel*ten){
	if(ten){
		wezel *badany=ten;
		while(badany->prawySyn){
			badany=badany->prawySyn;
		}
		return badany;
	}
	return NULL;
}

drzewo::wezel *drzewo::poprzednik(wezel *ten){
	if(ten){
		if(ten->lewySyn){
			return najwiekszy(ten->lewySyn);
		}
		else{
			wezel *badany=ten;
			while(badany->ojciec&&badany->ojciec->lewySyn==badany){
				badany=badany->ojciec;
			}
			return badany->ojciec;
		}
	}
	return NULL;
}

void drzewo::usun(wezel*ten){
	if(ten){
		if(!ten->lewySyn&&!ten->prawySyn){
			if(ten->ojciec){
				if(ten->ojciec->lewySyn==ten){
					ten->ojciec->lewySyn=NULL;
				}
				else{
					ten->ojciec->prawySyn=NULL;
				}
			}
			else{
				korzen=NULL;
			}
			delete ten;
		}
		else if(!(ten->lewySyn&&ten->prawySyn)){
				wezel *syn=(ten->lewySyn)?ten->lewySyn:ten->prawySyn;
				if(ten->ojciec){
					if(ten->ojciec->lewySyn==ten){
						ten->ojciec->lewySyn=syn;
					}
					else{
						ten->ojciec->prawySyn=syn;
					}
				}
				else{
					korzen=syn;
					syn->ojciec=ten->ojciec;
				}
				delete ten;
			}
			else{
				wezel *pop=poprzednik(ten);
				ten->klucz-pop->klucz;
				usun(pop);
			}
		}
	}

void kolejka::dodaj(drzewo::wezel *x){
	if(x){
		el *nowy=new el(x);
		if(!glowa){
			glowa=nowy;
			ogon=nowy;
		}
		else{
			ogon->nast=nowy;
			ogon=nowy;
		}
	}
}

drzewo::wezel *kolejka::usun(){
	if(!glowa){
		return NULL;
	}
	else if(glowa==ogon){
			drzewo::wezel *pomoc=glowa->klucz;
			glowa=ogon=NULL;
			delete glowa;
			return pomoc;
		}
		else{
			drzewo::wezel *pomoc=glowa->klucz;
			el *usuwany=glowa;
			glowa=glowa->nast;
			delete usuwany;
			return pomoc;
		}
}

void drzewo::wszerz(wezel *skad){
	if(skad){
		kolejka K;
		K.dodaj(skad);
		wezel *ten;
		while(K.glowa!=NULL){
			ten=K.usun();
			K.dodaj(ten->lewySyn);
			K.dodaj(ten->prawySyn);
			cout<<ten->klucz<<", ";
		}
	}
}
