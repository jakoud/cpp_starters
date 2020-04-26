#include<iostream>
using namespace std;
struct wezel
{
	int klucz;
	wezel *ojciec, *lewy, *prawy;
};
class BST
{
	wezel *korzen;
	public:
		BST();
		wezel* minimum();
		wezel* maksimum();
		wezel* znajdz(int x);
		void wstaw(int x);
		wezel* nastepnik(wezel *wsk);
		wezel* poprzednik(wezel *wsk);
		void preorder();
		void inorder();
		void postorder();
		void preorder(wezel *wsk);
		void inorder(wezel *wsk);
		void postorder(wezel *wsk);
		void usun(wezel *wsk);
		int wysokosc(wezel *wsk);
		int wysokosc();
		void potomkowie(wezel *wsk);
		void przodkowie(wezel *wsk);
		int CzyPotomek(wezel *p, wezel *w);	// czy p jest potomkiem w
		int CzyPrzodek(wezel *p, wezel *w);	// czy p jest przodkiem w
		~BST();
};
BST::BST()
{
	korzen=NULL;
}
wezel* BST::minimum()
{
	wezel *pom;
	pom=korzen;
	if(pom==NULL)
		return pom;
	while(pom->lewy!=NULL)
		pom=pom->lewy;
	return pom;
}
wezel* BST::maksimum()
{
	wezel *pom;
	pom=korzen;
	if(pom==NULL)
		return pom;
	while(pom->prawy!=NULL)
		pom=pom->prawy;
	return pom;
}
wezel* BST::znajdz(int x)
{
	wezel *pom;
	pom=korzen;
	while(pom!=NULL && pom->klucz!=x)
	{
		if(x>pom->klucz)
			pom=pom->prawy;
		else
			pom=pom->lewy;
	}
	return pom;
}
void BST::wstaw(int x)
{
	wezel *pom, *wsk, *r;
	pom=new wezel;
	if(pom!=NULL)
	{
		pom->klucz=x;
		pom->lewy=NULL;
		pom->prawy=NULL;
		if(korzen==NULL)
		{
			pom->ojciec=NULL;
			korzen=pom;
		}
		else
		{
			wsk=korzen;
			while(wsk!=NULL)
			{
				r=wsk;
				if(x>wsk->klucz)
					wsk=wsk->prawy;
				else
					wsk=wsk->lewy;
			}
			pom->ojciec=r;
			if(x>r->klucz)
				r->prawy=pom;
			else
				r->lewy=pom;
		}
	}
}
wezel* BST::nastepnik(wezel *wsk)
{
	wezel *pom;
	pom=wsk;
	if(pom->prawy!=NULL)
	{
		pom=pom->prawy;
		while(pom->lewy!=NULL)
			pom=pom->lewy;
		return pom;
	}
	while(pom->ojciec!=NULL && pom->ojciec->prawy==pom)
		pom=pom->ojciec;
	return pom->ojciec;
}
wezel* BST::poprzednik(wezel *wsk)
{
	wezel *pom;
	pom=wsk;
	if(pom->lewy!=NULL)
	{
		pom=pom->lewy;
		while(pom->prawy!=NULL)
			pom=pom->prawy;
		return pom;
	}
	while(pom->ojciec!=NULL && pom->ojciec->lewy==pom)
		pom=pom->ojciec;
	return pom->ojciec;
}
void BST::preorder()
{
	preorder(korzen);
}
void BST::inorder()
{
	inorder(korzen);
}
void BST::postorder()
{
	postorder(korzen);
}
void BST::preorder(wezel *wsk)
{
	if(wsk!=NULL)
	{
		cout<<wsk->klucz<<", ";
		preorder(wsk->lewy);
		preorder(wsk->prawy);
	}
}
void BST::inorder(wezel *wsk)
{
	if(wsk!=NULL)
	{
		inorder(wsk->lewy);
		cout<<wsk->klucz<<", ";
		inorder(wsk->prawy);
	}
}
void BST::postorder(wezel *wsk)
{
	if(wsk!=NULL)
	{
		postorder(wsk->lewy);
		postorder(wsk->prawy);
		cout<<wsk->klucz<<", ";
	}
}
void BST::usun(wezel *wsk)
{
	if(wsk->lewy==NULL && wsk->prawy==NULL)	// nie ma synów
	{
		if(wsk==korzen)
			korzen=NULL;
		else
		{
			if(wsk->ojciec->lewy==wsk)
				wsk->ojciec->lewy=NULL;
			else
				wsk->ojciec->prawy=NULL;
		}
		delete wsk;
	}
	wezel *pom;
	if(wsk->lewy!=NULL && wsk->prawy==NULL)	// ma lewego syna
	{
		pom=wsk->lewy;
		pom->ojciec=wsk->ojciec;
		if(wsk==korzen)
			korzen=pom;
		else
		{
			if(wsk->ojciec->lewy==wsk)
				wsk->ojciec->lewy=pom;
			else
				wsk->ojciec->prawy=pom;
		}
		delete wsk;
	}
	if(wsk->lewy==NULL && wsk->prawy!=NULL)	// ma prawego syna
	{
		pom=wsk->prawy;
		pom->ojciec=wsk->ojciec;
		if(wsk==korzen)
			korzen=pom;
		else
		{
			if(wsk->ojciec->lewy==wsk)
				wsk->ojciec->lewy=pom;
			else
				wsk->ojciec->prawy=pom;
		}
		delete wsk;
	}
	if(wsk->lewy!=NULL && wsk->prawy!=NULL)	//ma obu synów
	{
		pom=poprzednik(wsk);	// pom jest w lewym poddrewie wsk i nie ma prawego syna
		if(pom->ojciec==wsk)	// poprzednik jest synem wsk
		{
			pom->ojciec=wsk->ojciec;
			if(wsk==korzen)
				korzen=pom;
			else
			{
				if(wsk->ojciec->lewy==wsk)
					wsk->ojciec->lewy=pom;
				else
					wsk->ojciec->prawy=pom;
			}
			pom->prawy=wsk->prawy;
			wsk->prawy->ojciec=pom;
			delete wsk;
		}
		else
		{
			pom->ojciec->prawy=pom->lewy;
			if(pom->lewy!=NULL)
				pom->lewy->ojciec=pom->ojciec;
			pom->ojciec=wsk->ojciec;
			if(wsk==korzen)
				korzen=pom;
			else
			{
				if(wsk->ojciec->lewy==wsk)
					wsk->ojciec->lewy=pom;
				else
					wsk->ojciec->prawy=pom;
			}
			pom->lewy=wsk->lewy;
			wsk->lewy->ojciec=pom;
			pom->prawy=wsk->prawy;
			wsk->prawy->ojciec=pom;
			delete wsk;
		}
	}
}
int BST::wysokosc(wezel *wsk)
{
	if(wsk->prawy==NULL && wsk->lewy==NULL)
		return 0;	// wsk jest liœciem
	int l=0, p=0, w;	// l- wysokosc lewego poddrzewa, p- prawego, w-wysokosc wsk
	if(wsk->prawy!=NULL)
		p=wysokosc(wsk->prawy);
	if(wsk->lewy!=NULL)
		l=wysokosc(wsk->lewy);
	if(l>p)
		w=l;
	else
		w=p;
	return 1+w;
}
int BST::wysokosc()
{
	return wysokosc(korzen);
}
void BST::potomkowie(wezel *wsk)
{
	inorder(wsk->lewy);
	inorder(wsk->prawy);
}
void BST::przodkowie(wezel *wsk)
{
	wezel *pom;
	pom=wsk->ojciec;
	while(pom!=NULL)
	{
		cout<<pom->klucz;
		pom=pom->ojciec;
	}
}
int BST::CzyPotomek(wezel *p, wezel *w)
{
	return CzyPrzodek(w,p);
}
int BST::CzyPrzodek(wezel *p, wezel *w)
{
	wezel *pom;
	pom=w->ojciec;
	while(pom!=NULL)
	{
		if(pom==p)
			return 1;
		pom=pom->ojciec;
	}
	return 0;
}
BST::~BST()
{
	while(korzen!=NULL)
		usun(korzen);
}

main()
{
	BST t;
	t.wstaw(7);
	t.wstaw(2);
	t.wstaw(8);
	t.wstaw(3);
	t.wstaw(1);
	t.wstaw(5);
	t.wstaw(9);
	t.wstaw(0);
	t.wstaw(6);
	t.wstaw(4);
	
	t.preorder();
	cout<<endl;
	t.inorder();
	cout<<endl;
	t.postorder();
	cout<<endl<<endl;
	
	t.usun(t.znajdz(5));
	t.preorder();
	cout<<endl;
	t.inorder();
	cout<<endl;
	t.postorder();
	cout<<endl<<endl;
	
	t.usun(t.znajdz(2));
	t.preorder();
	cout<<endl;
	t.inorder();
	cout<<endl;
	t.postorder();
	cout<<endl<<endl;
}
