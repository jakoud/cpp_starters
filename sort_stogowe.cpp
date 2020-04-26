#include<iostream>
using namespace std;
void wypisz(int A[], int n)
{
	for(int i=0;i<n;i++)
		cout<<A[i];
	cout<<endl;
}
void przesiewanie(int l, int p, int A[], int n)
{
	int i,j,x;
	x=A[l];
	i=l;
	j=2*i+1;
	while(j<=p)
	{
		if(j!=p && A[j]<A[j+1])
			j++;
		if(x<A[j])
		{
			A[i]=A[j];
			i=j;
			j=2*i+1;
		}
		else
			break;
	}
	A[i]=x;
	wypisz(A,n);
}
void budujstog(int A[], int n)
{
	for(int i=(n-2)/2;i>=0;i--)
		przesiewanie(i,n-1,A,n);
}
void stogowe(int A[], int n)
{
	budujstog(A,n);
	for(int i=n-1;i>=1;i--)
	{
		int x=A[0];
		A[0]=A[i];
		A[i]=x;
		przesiewanie(0,i-1,A,n);
	}
}
main()
{
	int tab[10]={5,7,2,1,3,4,6,9,8,0};
	wypisz(tab,10);
	stogowe(tab,10);
}
