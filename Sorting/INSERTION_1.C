#include<stdio.h>
#include<conio.h>
#define SZ 5
int i,j,arr[SZ];
void insertionSort()
{
	int temp;
	for(i=0;i<SZ;i++)
	{
		printf("\n Array[%d] : ",i);
		scanf("%d",&temp);
		for(j=i-1; j>=0 && arr[j]>temp ;j--)
		{
			arr[j+1]=arr[j];
		}
		arr[j+1]=temp;
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
void main()
{
	clrscr();
	printf("\n Insertion Sort Program ");
	insertionSort();
	display();
	getch();
}