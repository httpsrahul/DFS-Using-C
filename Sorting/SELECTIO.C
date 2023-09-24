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
	printf("\nArray Elements\n");
	for(i=0;i<SZ;i++)
	{
		printf("%d ",arr[i]);
	}
}

void sort()
{
	for(i=0;i<SZ-1;i++)
	{
		for(j=i+1;j<SZ;j++)
		{
			if(arr[i] > arr[j])
			{
				arr[j] = arr[j] + arr[i];
				arr[i] = arr[j] - arr[i];
				arr[j] = arr[j] - arr[j];
			}
		}
	}
	printf("\nSorted Successfully !\n");
}
void main()
{
	clrscr();
	insert();
	display();
	sort();
	display();
	getch();
}

