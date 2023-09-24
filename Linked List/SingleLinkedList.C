/******************************************************************

	TITLE : LINKED LIST BY STORING ADDRESS OF NEXT NODE
	CODER : RAHUL BARAIYA
	 DATE : 19/07/2023

	----------------------------------------
	THIS PROGRAM SUPPORT FOLLOWING OPERATION
	----------------------------------------

		[1] : INSERTION AT BEGINING
		[2] : INSERTION AT ENDING
		[3] : INSERTION AFTER PARTICULAR NODE
		[4] : DELETION OF FIRST NODE
		[5] : DELETION OF LAST NODE
		[6] : DELETION OF ANY NODE
		[7] : SEARCH DATA
		[8] : UPDATION DATA
		[9] : DISPLAY DATA
		[A] : REVERSING THE LIST


*******************************************************************/
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include<stdlib.h>

// node structure
struct node
{
	int data;
	struct node *next;
} *start, *end, *temp, *dummy = '\0';

int isFound=0,srch;
// insertion before first node
void insertAtBegin()
{
	temp = (struct node *)malloc(sizeof(struct node));
	printf("\n\t\t\tEnter Data : ");
	scanf("%d", &temp->data);
	temp->next = start;
	if (end == '\0')
		end = temp;
	start = temp;
	printf("\t\t\tInseterd Successfully !");
}
// insertion after last node
void insertAtEnd()
{
	temp = (struct node *)malloc(sizeof(struct node));
	printf("\n\t\t\tEnter Data : ");
	scanf("%d", &temp->data);
	temp->next = '\0';
	if (start == '\0')
		start = temp;
	else
		end->next = temp;
	end = temp;
	printf("\t\t\tInseterd Successfully !");
}
// boolean function for searching
// objective of this function is to make search(), update() & insertAfter() easier !
int isDataFound()
{
	printf("\n\t\t\tEnter Value Of Node :  ");
	scanf("%d", &srch);
	for (temp = start; temp != '\0'; temp = temp->next)
	{
		if (srch == temp->data)
		{
			return 1;
		}
	}
	return 0;
}
// insertion after particular node
void insertAfter()
{
	if (start == '\0')
		printf("\n\t\t\t List Dosen't Exist !");
	else
	{
		if (isDataFound() == 1)
		{
			if (srch == end->data)
				insertAtEnd();
			else
			{
				dummy = (struct node *)malloc(sizeof(struct node));
				printf("\t\t\t Enter Data : ");
				scanf("%d", &dummy->data);
				dummy->next = temp->next;
				temp->next = dummy;
				printf("\t\t\t Inserted Successfully !");
			}
		}
		else
			printf("\t\t\t Data Not Found !");
	}
}
// delition of first node
void deleteFirst()
{
	if (start == '\0')
		printf("\n\t\t\t List Dosen't Exist !");
	else
	{
		temp = start;
		start = start->next;
		free(temp);
		printf("\n\t\t\t Deleted Successfully !");
	}
}
// delition of last node
void deleteLast()
{
	if (start == '\0')
		printf("\n\t\t\t List Dosen't Exist !");
	else
	{
		if (start->next == '\0')
		{
			deleteFirst();
		}
		else
		{
			for (temp = start; temp->next->next != '\0'; temp = temp->next);
			end = temp;
			free(end->next);
			end->next = '\0';
			printf("\n\t\t\t Deleted Successfully !");
		}
	}
}
// delition of any particular node
void deleteAny()
{
	if (start == '\0')
		printf("\n\t\t\t Link Dosen't Exist !");
	else
	{
		printf("\n\t\t\t Enter Value Of Node : ");
		scanf("%d", &srch);
		if (start->data == srch)
		{
			deleteFirst();
			isFound = 1;
		}
		else if (end->data == srch)
		{
			deleteLast();
			isFound = 1;
		}
		else
		{
			for (isFound = 0, temp = start; temp != '\0'; temp = temp->next)
			{
				if (srch == temp->next->data)
				{
					isFound = 1;
					dummy = temp->next;
					temp->next = dummy->next;
					free(dummy);
					printf("\t\t\t Deleted Successfully !");
					break;
				}
			}
			if (isFound == 0)
				printf("\t\t\t Data Not Found !");
		}
	}
}
// updation of any particular node
void update()
{
	if (start == '\0')
		printf("\n\t\t\t List Dosen't Exist !");
	else
	{
		if (isDataFound() == 1)
		{
			printf("\n\t\t\t Enter New Data : ");
			scanf("%d", &temp->data);
			printf("\t\t\t Updated Successfully");
		}
		else
			printf("\n\t\t\t Element Not Found !");
	}
}
void reverseList()
{
	struct node *n;
	struct node *p;
	struct node *c;
	if(start=='\0' || start->next=='\0')
	{
		return;
	}
	else
	{
		// h
		// 11-> <-12  13-> 14-> 15->N
		// pc n
		p=start;
		c=p->next;
		while(c!='\0')
		{
			n=c->next;
			c->next=p;
			//updating
			p=c;
			c=n;
		}
		start->next='\0';
		start=p;
	}
}
// main search function
void searchNode()
{
	if (isDataFound() == 1)
	{
		printf("\n\t\t\t Element Found !");
		printf("\n\t\t\t [%u] [%d] -> [%u]", temp, temp->data, temp->next);
	}
	else
	{
		printf("\n\t\t\t Element Not Found !");
	}
}
// function for displaying data
void display()
{
	if (start == '\0')
		printf("\n\t\t\t Link Dosen't Exist !");
	else
	{
		printf("\n\t\t\t[BASE] [DATA] -> [NEXT]");
		printf("\n\t\t\t-----------------------");
		for (temp = start; temp != NULL; temp = temp->next)
		{
			printf("\n\t\t\t [%u] [%d] -> [%u]", temp, temp->data, temp->next);
		}
	}
}
int getCommand()
{
	char c;
	printf("\t\t\t----------------------------\n");
	printf("\t\t\t| COMMANDS MENU : LINKLIST |\n");
	printf("\t\t\t----------------------------\n");
	printf("\t\t\t| [1] : Insert_At_Begining |\n");
	printf("\t\t\t| [2] : Insert_At_Ending   |\n");
	printf("\t\t\t| [3] : Insert_After       |\n");
	printf("\t\t\t| [4] : Delete_First       |\n");
	printf("\t\t\t| [5] : Delete_Last        |\n");
	printf("\t\t\t| [6] : Delete_Any         |\n");
	printf("\t\t\t| [7] : Search             |\n");
	printf("\t\t\t| [8] : Update             |\n");
	printf("\t\t\t| [9] : DISPLAY            |\n");
	printf("\t\t\t| [A] : SORTLIST           |\n");
	printf("\t\t\t| [B] : REVERSELIST        |\n");
	printf("\t\t\t----------------------------\n");
	printf("\t\t\t| Enter Command : ");
	c=getche();
	clrscr();
	return c;
}
void main()
{
	char cmd;
	clrscr();
	do
	{
		cmd=getCommand();
		printf("\n\t\t\t-----------------------");
		switch(cmd)
		{
			case '0' : exit(0); break;
			case '1' : insertAtBegin(); break;
			case '2' : insertAtEnd(); break;
			case '3' : insertAfter(); break;
			case '4' : deleteFirst(); break;
			case '5' : deleteLast(); break;
			case '6' : deleteAny(); break;
			case '7' : searchNode(); break;
			case '8' : update(); break;
			case '9' : display(); break;
		 //	case 'A' : sortList(); break;
			case 'B' : reverseList(); break;
			default: break;
		}
		printf("\n\t\t\t-----------------------");
		getch();
		clrscr();
	}
	while(1);
}
