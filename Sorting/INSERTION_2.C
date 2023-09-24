#include<stdio.h>
#include<conio.h>
#define SZ 5
int i,j,arr[SZ];
void insert()
{
	for(i=0;i<SZ;i++)
	{
		printf("\n Array[%d] : ",i);
		scanf("%d",&arr[i]);
	}

}

void display()
{
	printf("\n Array Elements\n");
	for(i=0;i<SZ;i++)
	{
		printf(" %d",arr[i]);
	}
}

void sort()
{
	int temp;
	for(i=1;i<SZ;i++)
	{
		temp=arr[i];
		for(j=i-1;j>=0 && arr[j]>temp;j--)
		{
			arr[j+1]=arr[j];
		}
		arr[j+1]=temp;
	}
	printf("\n Sorted Successfully ! \n");
}
void main()
{
	clrscr();
	printf("\n Insertion Sort Program");
	insert();
	display();
	sort();
	display();
	getch();
}