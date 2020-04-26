#include<iostream>
using namespace std;
void wypisz(int A[], int n)
{
	for(int i=0;i<n;i++)
		cout<<A[i];
	cout<<endl;
}
void babelkowe(int A[], int n)
{
	int i,j,x;
	for(i=0;i<n-1;i++)
	{
		for(j=n-1;j>i;j--)
		{
			if(A[j-1]>A[j])
			{
				x=A[j-1];
				A[j-1]=A[j];
				A[j]=x;
				wypisz(A,n);
			}
		}
	}
}
main()
{
	int tab[10]={5,7,2,1,3,4,6,9,8,0};
	wypisz(tab,10);
	babelkowe(tab,10);
}
