/******************************************************************

	TITLE : Doubled Linked List
	CODER : Rahul Baraiya
	create: 27/07/2023
	Update: 03/03/2023
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


*******************************************************************/
#include<stdio.h>
#include<conio.h>
// Node structure...
struct dlink
{
	int data;
	struct dlink *next;
	struct dlink *prev;
}*start,*end,*temp;
int srch;

// Inserting Node After End Node
void insertAtEnding()
{
	temp=(struct dlink*)malloc(sizeof(struct dlink));
	printf("\n Data For Last Node : ");
	scanf("%d",&temp->data);
	temp->prev=end;
	temp->next='\0';
	if(start=='\0')
	{
		start=temp;
	}
	else
	{
		end->next=temp;
	}
	end=temp;
}

// Inserting Node Before Start Node
void insertAtBegining()
{
	temp=(struct dlink*)malloc(sizeof(struct dlink));
	printf("\n Data For First Node : ");
	scanf("%d",&temp->data);
	temp->next=start;
	temp->prev='\0';
	if(end=='\0')
	{
		end=temp;
	}
	else
	{
		start->prev=temp;
	}
	start=temp;
}
void insertAny(int flag)
{
	if(start=='\0')
	{
		printf("\t\t\t\t List Is Empty !");
	}
	else
	{
		if(isDataFound()==1)
		{
			if(srch==end->data)
			{
				insertLast();
			}
			else if(start->data==srch)
			{
				insertAtBegin();
			}
			else
			{
				dummy=(struct dlink*)malloc(sizeof(struct dlink));
				printf("\t\t\t Enter Data : ");
				scanf("%d",&dummy->data);
				if(flag==1)
				{
					dummy->prev=temp;
					dummy->next=temp->next;
					temp->next->prev=dummy;
					temp->next=dummy;
				}
				else
				{
					dummy->next=temp;
					dummy->prev=temp->prev;
					temp->prev->next=dummy;
					temp->prev=dummy;
				}
			}
		}
		else
		{
			printf("\t\t\t Data Not Found!");
		}
	}
}
void deleteFirst()
{
	if(end=='\0')
	{
		printf("\t\t\t\t List Is Empty !");
	}
	else
	{
		temp=start;
		if(start==end)
		{
			start=end='\0';
		}
		else
		{
			start=start->next;
			start->prev='\0';
		}
		free(temp);
	}
}
void deleteLast()
{
	if(end=='\0')
	{
		printf("\t\t\t\t List Is Empty !");
	}
	else
	{
		temp=end;
		if(start==end)
		{
			end=start='\0';
		}
		else
		{
			end=end->prev;
			end->next='\0';
		}
		free(temp);
	}
}
void deleteAny()
{
	if(start=='\0')
	{
		printf("\n\t\t\t List Is Empty !");
	}
	else
	{               t
		// 12  13  14  15  16
		if(isDataFound()==1)
		{
			if(start->data==srch)
			{
				deleteFirst();
			}
			else if(end->data==srch)
			{
				deleteLast();
			}
			else
			{
				temp->next->prev=temp->prev;
				temp->prev->next=temp->next;
				free(temp);
			}
		}
		else
		{
			printf("\n\t\t\t Data Not Found !");
		}
	}
}
// Display Node
void display()
{
	printf("\n\t\t\t [PREV]<- [BASE][DATA]  ->[NEXT]");
	for(temp=start;temp!='\0';temp=temp->next)
	{
		printf("\n\t\t\t [%4u]<-  [%u][%d]  ->[%4u]",temp->prev,temp,temp->data,temp->next);
	}
}
int isDataFound()
{
	printf("Enter Data : ");
	scanf("%d",&srch);
	for(temp=start;temp!='\0';temp=temp->next)
	{
		if(srch==temp->data)
		{
			return 1;
		}
	}
	return 0;
}
void search()
{
	if(start=='\0')
	{
		printf("\t\t\t\t List is Empty !");
	}
	else
	{
		if(isDataFound()==1)
		{
			printf("\t\t\t Data Found !");
			printf("\n\t\t\t [%4u]<-  [%u][%d]  ->[%4u]",temp->prev,temp,temp->data,temp->next);
		}
		else
		{
			printf("\t\t\t Data Not Found !");
		}
	}
}
void update()
{
	if(start=='\0')
	{
		printf("\t\t\t\t List is Empty !");
	}
	else
	{
		if(isDataFound()==1)
		{
			printf("\t\t\t Enter Updating Data : ");
			scanf("%d",&temp->data);
			printf("\t\t\t Updated Successfully");
		}
		else
		{
			printf("\t\t\t Element Not Found !");
		}
	}
}
// MENU FU
char getCommand()
{
	char c;
	printf("\t\t--------------------------------------------\n");
	printf("\t\t\t| COMMANDS MENU : LINKLIST |\n");
	printf("\t\t--------------------------------------------\n");
	printf("\t\t\t| [1] : Insert_At_Begining |\n");
	printf("\t\t\t| [2] : Insert_At_Ending   |\n");
	printf("\t\t\t| [3] : Insert_Any         |\n");
	printf("\t\t\t| [4] : Delete_First       |\n");
	printf("\t\t\t| [5] : Delete_Last        |\n");
	printf("\t\t\t| [6] : Delete_Any         |\n");
	printf("\t\t\t| [7] : Search             |\n");
	printf("\t\t\t| [8] : Update             |\n");
	printf("\t\t\t| [9] : DISPLAY            |\n");
	printf("\t\t--------------------------------------------\n");
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
		printf("\t\t\t----------------------------------\n");
		switch(cmd)
		{
			case '0' : exit(); break;
			case '1' : insertAtBegining(); break;
			case '2' : insertAtEnding(); break;
  //			case '3' : insertAny(); break;

			case '4' : deleteFirst(); break;
			case '5' : deleteLast(); break;
 /*			case '6' : deleteAny(); break;
			case '7' : searchNode(); break;
			case '8' : update(); break; */
			case '9' : display(); break;
			default: break;
		}
		printf("\n\t\t\t----------------------------------");
		getch();
		clrscr();
	}
	while(1);
}

/*
void main()
{
	char cmd;
	clrscr();
	do
	{
		printf("\t\t\t [0] : Exit");
		printf("\t\t\t [1] : Insert");
		printf("\t\t\t [2] : Delete");
		printf("\t\t\t [3] : Update");
		printf("\t\t\t [4] : Search");
		printf("\t\t\t [5] : Display");
		printf("\t\t\t Enter Choice : ");
		cmd=getche();
		switch(cmd)
		{
			case '0' :  exit(0);
			case '1' :
					printf("\t\t\t [1] : Insert At Begining");
					printf("\t\t\t [2] : Insert At Ending");
					printf("\t\t\t [3] : Insert Before");
					printf("\t\t\t [4] : Insert After");
					printf("\t\t\t Enter Choice : ");
					cmd=getche();
					switch(cmd)
					{
						case '1' :
								insertAtBegining();
								break;
						case '2' :
								insertAtEnding();
								break;
						case '3' :
								insertAny(1);
								break;
						case '4' :
								insertAny(0);
								break;
						default : break;
					}
					break;
			case '2' :
					printf("\t\t\t [0] : Back ");
					printf("\t\t\t [1] : Delete First ");
					printf("\t\t\t [2] : Delete Last");
					printf("\t\t\t [3] : Delete Any");
					printf("\t\t\t Enter Choice : ");
					cmd=getche();
					switch(cmd)
					{
						case '1' :
								deleteFirst();
								break;
						case '2' :
								deleteLast();
								break;
						case '3' :
								deleteAny();
								break;
						default:
								break;
					}
			case '3' :
			case '4' :
			case '5' :
					printf("\t\t\t [0] : Back");
					printf("\t\t\t [1] : First To Last");
					printf("\t\t\t [2] : Last To First");
					break;
		}
	}
	while(1)
}
*/