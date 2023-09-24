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
		for(j=0;j<SZ-i-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				arr[j+1] = arr[j] + arr[j+1];
				arr[j] = arr[j+1] - arr[j];
				arr[j+1] = arr[j+1] - arr[j];
			}
		}
	}
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