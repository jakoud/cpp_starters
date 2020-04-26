class stos{
	private:
		int szczyt;
		int tab[10];
	public:
		stos();
		int pusty();
		void wstaw(int x);
		int zwroc();
		void usun();
		~stos();
};

stos::stos(){
	szczyt=-1;
}

int stos::pusty(){
	if(szczyt==-1) return 1;
	return 0;
}

void stos::wstaw(int x){
	if(szczyt<9){
		tab[++szczyt]=x;
	}
}

int stos::zwroc(){
	if(!pusty()){
		return tab[szczyt];
	}
}

void stos::usun(){
	if(!pusty()){
		--szczyt;
	}
}

stos::~stos(){
	while(!pusty()){
		usun();
	}
}

struct el_stosu{
	int klucz;
	el_stosu *nast;	
};

class stos{
	private:
		el_stosu *szczyt;
	public:
		stos();
		int pusty();
		void wstaw(int x);
		int zwroc();
		void usun();
		~stos();
};

stos::stos(){
	szczyt=NULL;
}

int stos::pusty(){
	if(szczyt==NULL) return 1;
	return 0;
}

void stos::wstaw(int x){
	el_stosu *nowy;
	nowy=new el_stosu;
	if(nowy!=NULL){
		nowy->klucz=x;
		nowy->nast=szczyt;
		szczyt=nowy;
	}
}

int stos::zwroc(){
	if(!pusty()){
		return szczyt->klucz;
	}
}

void stos::usun(){
	if(!pusty()){
		el_stosu *pom;
		pom=szczyt;
		szczyt=szczyt->nast;
		delete pom;
	}
}

stos::~stos(){
	while(!pusty()){
		usun();
	}
}

class kolejka{
	private:
		int poczatek, koniec, tab[10];
	public:
		kolejka();
		int pusta();
		void wstaw(int x);
		int zwroc();
		void usun();
		~kolejka();
};

kolejka::kolejka(){
	poczatek=koniec=0;
}

int kolejka::pusta(){
	if(poczatek==koniec) return 1;
	return 0;
}

void kolejka::wstaw(int x){
	if((koniec+1)%10!=poczatek){
		tab[koniec]=x;
		koniec=(koniec+1)%10;
	}
}

int kolejka::zwroc(){
	if(!pusta()){
		return tab[poczatek];
	}
}

void kolejka::usun(){
	if(!pusta()){
		poczatek=(poczatek+1)%10;
	}
}

kolejka::~kolejka(){
	while(!pusta()){
		usun();
	}
}

struct el_kolejki{
	int klucz;
	el_kolejki *nast;
};

class kolejka{
	private:
		el_kolejki *poczatek, *koniec;
	public:
		kolejka();
		int pusta();
		void wstaw(int x);
		int zwroc();
		void usun();
		~kolejka();
};

kolejka::kolejka(){
	poczatek=koniec=NULL;
}

int kolejka::pusta(){
	if(poczatek==NULL) return 1;
	return 0;
}

void kolejka::wstaw(int x){
	el_kolejki *nowy;
	nowy=new el_kolejki;
	if(nowy!=NULL){
		nowy->klucz=x;
		if(pusta()){
			poczatek=koniec=nowy;
		}
		else{
			nowy->nast=koniec;
			koniec=nowy;
		}
	}
}

int kolejka::zwroc(){
	if(!pusta()){
		return poczatek->klucz;
	}
}

void kolejka::usun(){
	if(!pusta()){
		el_kolejki *pom;
		pom=poczatek;
		if(poczatek==koniec){
			poczatek=koniec=NULL;
		}
		else{
			poczatek=poczatek->nast;
		}
		delete pom;
	}
}

kolejka::~kolejka(){
	while(!pusta()){
		usun();
	}
}

struct el_listy{
	int klucz;
	el_listy *nast;
};

class lista{
	private:
		el_listy *glowa;
	public:
		lista();
		int pusta();
		void wstaw(el_listy *poz, int x);
		void wypisz_liste();
		el_listy *wyszukaj(int x);
		int zwroc(el_listy *poz);
		void usun(el_listy*poz);
		el_listy *nastepnik(el_listy*poz);
		el_listy *poprzednik(el_listy*poz);
		~lista();
};

lista::lista(){
	glowa=NULL;
}

int lista::pusta(){
	if(glowa==NULL) return 1;
	return 0;
}

void lista::wstaw(el_listy *poz, int x){
	el_listy *nowy;
	nowy=new el_listy;
	if(nowy!=NULL){
		nowy->klucz=x;
		if(poz==NULL){
			nowy->nast=glowa;
			glowa=nowy;
		}
		else{
			nowy->nast=poz->nast;
			poz->nast=nowy;
		}
	}
}

void lista::wypisz_liste(){
	el_listy *pom;
	pom=glowa;
	while(pom!=NULL){
		cout<<pom->klucz<<endl;
		pom=pom->nast;
	}
}

el_listy *lista::wyszukaj(int x){
	el_listy *pom;
	pom=glowa;
	if(glowa->klucz==x){
		return NULL;
	}
	while(pom->nast!=NULL&&pom->nast->klucz!=x){
		pom=pom->nast;
	}
	return pom;
}

int lista::zwroc(el_listy*poz){
	if(!pusta()&&poz!=NULL){
		return poz->klucz;
	}
}

void lista::usun(el_listy *poz){
	if(!pusta()){
		el_listy *pom;
		if(poz==NULL){
			pom=glowa;
			glowa=glowa->nast;
			delete pom;
		}
		else{
			pom=poz->nast;
			poz->nast=pom->nast;
			delete pom;
			
		}
	}
}
el_listy *lista::nastepnik(el_listy *poz){
	if(poz==NULL){
		return glowa;
	}
	else{
		return poz->nast;
	}
}

el_listy *lista::poprzednik(el_listy *poz){
	el_listy *pom;
	pom=glowa;
	if(pusta()) return NULL;
	else{
		if(poz==glowa) return NULL;
		else{
			while(pom!=NULL&&pom->nast!=poz){
				pom=pom->nast;
			}
			return pom;
		}
	}
}

lista::~lista(){
	while(!pusta()){
		usun(NULL);
	}
}

class lista{
	private:
		int n;
		int tab[10];
	public:
		lista();
		int pusta();
		int pelna();
		void wstaw(int indeks, int x);
		void wypisz_liste();
		int zwroc(int indeks);
		int wyszukaj(int x);
		void usun(int indeks);
		int poprzednik(int indeks);
		int nastepnik(int indeks);
		~lista();
};

lista::lista(){
	n=-1;
}

int lista::pusta(){
	if(n==-1) return 1;
	return 0;
}

int lista::pelna(){
	if(n==9){
		return 1;
	}
	return 0;
}
void lista::wstaw(int indeks, int x){
	if(!pelna()){
		for(int i=n;i>=indeks;--i){
			tab[i+1]=tab[i];
		}
		tab[indeks]=x;
		++n;
	}
}

void lista::wypisz_liste(){
	for(int i=0;i<n+1;++i){
		cout<<tab[i]<<endl;
	}
}

int lista::zwroc(int indeks){
	if(!pusta()&&indeks!=-1){
		return tab[indeks];
	}
}
int lista::wyszukaj(int x){
		for(int i=0;i<n+1;++i){
			if(tab[i]==x){
				return i;
			}
		}
		return -1;
}

void lista::usun(int indeks){
	if(!pusta()&&indeks!=-1){
		for(int i=indeks;i<n;++i){
			tab[i]=tab[i+1];
		}
		--n;
	}
}

int lista::poprzednik(int indeks){
	if(indeks>-1){
		return indeks-1;
	}
	else return -1;
}

int lista::nastepnik(int indeks){
	if(indeks<9){
		return indeks+1;
	}
	else return -1;
}

lista::~lista(){
	while(!pusta()){
		usun(n);
	}
}

struct el_listy2{
	int klucz;
	el_listy2 *nast, *pop;
};

class lista2{
	private:
		el_listy2 *glowa, *ogon;
	public:
		lista2();
		int pusta();
		void wstaw(el_listy2*poz, int x);
		int zwroc(el_listy2*poz);
		void usun(el_listy2*poz);
		void wypisz_glowa();
		void wypisz_ogon();
		el_listy2 *wyszukaj(int x);
		el_listy2 *nastepnik(el_listy2*wsk);
		el_listy2 *poprzednik(el_listy2*wsk);
		~lista2();
};

lista2::lista2(){
	glowa=ogon=NULL;
}

int lista2::pusta(){
	if(glowa==NULL){
		return 1;
	}
	else return 0;
}

void lista2::wstaw(el_listy*poz, int x){
	el_listy2 *nowy;
	nowy=new el_listy2;
	if(nowy!=NULL){
		nowy->klucz=x;
		if(pusta()){
			glowa=ogon=nowy;
		}
		else{
			if(poz==NULL){
				nowy->nast=glowa;
				glowa->pop=nowy;
				glowa=nowy;
				glowa->pop=NULL;
			}
			else{
				if(poz==ogon){
					ogon->nast=nowy;
					nowy->pop=ogon;
					ogon=nowy;
					ogon->nast=NULL;
				}
				else{
					nowy->nast=poz->nast;
					poz->nast->pop=nowy;
					nowy->pop=poz;
					poz->nast=nowy;
				}
			}
		}
	}
}

int lista2::zwroc(el_listy2*poz){
	if(poz!=NULL){
		return poz->klucz;
	}
}

void lista2::usun(el_listy2*poz){
	if(poz!=NULL){
		if(glowa==ogon){
			glowa=ogon=NULL;
			delete poz;
		}
		else{
			if(poz==glowa){
				glowa=glowa->nast;
				glowa->pop=NULL;
			}
			else{
				if(poz==ogon){
					ogon=ogon->pop;
					ogon->nast=NULL;
				}
				else{
					poz->nast->pop=poz->pop;
					poz->pop->nast=poz->nast;
				}
			}
			delete poz;
		}
	}
}

void lista2::wypisz_glowa(){
	el_listy2 *pom;
	pom=glowa;
	while(pom!=NULL){
		cout<<pom->klucz<<endl;
		pom=pom->nast;
	}
}

void lista2::wypisz_ogon(){
	el_listy2 *pom;
	pom=ogon;
	while(pom!=NULL){
		cout<<pom->klucz<<endl;
		pom=pom->pop;
	}
}

el_listy2*lista2::wyszukaj(int x){
	if(pusta()) return NULL;
	else{
		el_listy2 *pom;
		pom=glowa;
		while(pom!=NULL&&pom->klucz!=x){
			pom=pom->nast;
		}
		return pom;
	}
}

el_listy2* lista2::nastepnik(el_listy2*poz){
	if(!pusta()){
		if(poz!=ogon){
			return poz->nast;
		}
		else return NULL;
	}
}

el_listy2*lista2::poprzednik(el_listy2*poz){
	if(!pusta()){
		if(poz!=glowa){
			return poz->pop;
		}
		else return NULL;
	}
}

lista2::~lista2(){
	while(!pusta()){
		usun(ogon);
	}
}
