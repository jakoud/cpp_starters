#include<iostream>
using namespace std;
void wypisz(int A[], int n)
{
	for(int i=0;i<n;i++)
		cout<<A[i];
	cout<<endl;
}
void szybkie(int l, int p, int A[], int n)
{
	int i,j,k,x;
	i=l;
	j=p;
	k=A[(l+p)/2];
	while(i<=j)
	{
		while(A[i]<k)
			i++;
		while(A[j]>k)
			j--;
		if(i<=j)
		{
			x=A[i];
			A[i]=A[j];
			A[j]=x;
			cout<<A[i]<<"	"<<A[j]<<"	";
			wypisz(A,n);
			i++;
			j--;
		}
	}
	if(j>l)
		szybkie(l,j,A,n);
	if(i<p)
		szybkie(i,p,A,n);
}
void szybkie(int A[], int n)
{
	szybkie(0, n-1, A, n);
}
main()
{
	int tab[10]={4,8,1,7,2,6,3,5};
	wypisz(tab,8);
	szybkie(tab,8);
}
