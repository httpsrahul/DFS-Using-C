#include<stdio.h>
#include<conio.h>
void insert(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("Enter Data : ");
		scanf("%d",&a[i]);
	}
}
void display(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("\n %d",a[i]);
	}
}
void merge(int arr[],int l,int m,int r)
{
	int i,j,k;
	int n1=m-l+1;
	int n2=r-m;
	int *a1=(int*)malloc(sizeof(int)*n1);
	int *a2=(int*)malloc(sizeof(int)*n2);
	for(i=0;i<n1;i++)
		a1[i]=arr[l+i];
	for(j=0;j<n2;j++)
		a2[j]=arr[m+1+j];
	i=j=0;
	k=l;
	while(i<n1 && j<n2)	{
		if(a1[i]<=a2[j]) {
			arr[k++]=a1[i++];
		} else {
			arr[k++]=a2[j++];
		}
	}
	while(i<n1) {
	    arr[k++]=a1[i++];
	}
	while(j<n2) {
	    arr[k++]=a2[j++];
	}
}
void mergeSort(int arr[],int l,int r) {
	int m;
	if(l<r) {
		m=(l+r)/2;
		mergeSort(arr,l,m);
		mergeSort(arr,m+1,r);
		merge(arr,l,m,r);
	}
}
void main()
{
	int arr[5];
	int n=(sizeof(arr)/sizeof(arr[0]));
	clrscr();
	insert(arr,n);
	display(arr,n);
	mergeSort(arr,0,n-1);
	display(arr,n);
	getch();
}
