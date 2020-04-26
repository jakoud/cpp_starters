#include<iostream>
using namespace std;
void wypisz(int A[], int n)
{
	for(int i=0;i<n;i++)
		cout<<A[i];
	cout<<endl;
}
void proste_wstawianie(int A[], int n)
{
	int i,j,x;
	for(i=1;i<n;i++)
	{
		x=A[i];
		for(j=i-1;j>=0;j--)
		{
			if(A[j]>x)
				A[j+1]=A[j];
			else
				break;
		}
		A[j+1]=x;
		wypisz(A,n);
	}
}
main()
{
	int tab[10]={5,7,2,1,3,4,6,9,8,0};
	wypisz(tab,10);
	proste_wstawianie(tab,10);
}
