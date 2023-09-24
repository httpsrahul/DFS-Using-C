
#include<stdio.h>
#include<conio.h>
#define SZ 5
int i,arr[SZ];
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
	int swap,gap=SZ/2;
	do
	{
		do
		{
			swap=0;
			for(i=0;i<SZ-gap;i++)
			{
				if(arr[i] > arr[i+gap])
				{
					arr[i+gap] = arr[i+gap] + arr[i];
					arr[i] = arr[i+gap] - arr[i];
					arr[i+gap] = arr[i+gap] - arr[i];
					swap=1;
				}
			}
		}
		while(swap);
		gap/=2;
	}
	while(gap);
	printf("\n Sorted Successfully ! \n");
}
void main()
{
	clrscr();
	printf("\n Shell Sort Program");
	insert();
	display();
	sort();
	display();
	getch();
}