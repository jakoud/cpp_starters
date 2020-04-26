#include<iostream>
using namespace std;
void wypisz(int A[], int n)
{
	for(int i=0;i<n;i++)
		cout<<A[i];
	cout<<endl;
}
void scalanie(int l, int p, int A[], int n)
{
	int k;
	int *B;
	B= new int [p-l+1];
	k=(l+p)/2;
	if(k>l)
		scalanie(l,k,A,n);
	if(k+1<p)
		scalanie(k+1,p,A,n);
	int i,j,m;
	i=l;
	j=k+1;
	m=0;
	while(i<=k && j<=p)
	{
		if(A[i]<A[j])
		{
			B[m]=A[i];
			i++;
			m++;
		}
		else
		{
			B[m]=A[j];
			j++;
			m++;
		}
	}
	while(i<=k)
	{
		B[m]=A[i];
		i++;
		m++;
	}
	while(j<=p)
	{
		B[m]=A[j];
		j++;
		m++;
	}
	for(i=0;i<m;i++)
	{
		A[l+i]=B[i];
	}
	wypisz(A,n);
}
void scalanie(int A[], int n)
{
	scalanie(0,n-1,A,n);
}
main()
{
	int tab[10]={1,5,2,7,8,4,3,9};
	wypisz(tab,8);
	scalanie(tab,8);
}
