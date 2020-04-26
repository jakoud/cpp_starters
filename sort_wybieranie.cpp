#include<iostream>
using namespace std;
void wypisz(int A[], int n)
{
	for(int i=0;i<n;i++)
		cout<<A[i];
	cout<<endl;
}
void proste_wybieranie(int A[], int n)
{
	int i, j, min;
	for(i=0;i<n-1;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			if(A[j]<A[min])
				min=j;
		}
		j=A[min];
		A[min]=A[i];
		A[i]=j;
		wypisz(A,n);
	}
}
main()
{
	int tab[10]={5,7,2,1,3,4,6,9,8,0};
	wypisz(tab,10);
	proste_wybieranie(tab,10);
}
