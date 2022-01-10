#include<stdio.h>
#include<stdlib.h>
#include"moviedetails.c"
#include"decleration.c" 
#include<strings.h>
struct moviedetails person[300];
int count=0;
int id2=1000;
int price=500;
int **seat, selection, x;

void target(int choice){
    choice=choice1();
    switch(choice)
    {
        case 1:
            price=changeprize(price);
            break;
        case 2:
            details();
            break;
        case 3:
            selection=movie();
            reservation(seat[selection-1],price,selection);
            count++;
            break;
        case 4:
            selection=cmovie();
            cancel(seat[selection-1]);
            break;
        case 5:
            x=5;
            break;
        default:
            printf("Choice not available\n");
            break;

    }

}
int main()
{
	int choice, i;
	seat=(int **)calloc(101,sizeof(int *));
	for (i=0;i<3;i++)
		*(seat+i)=(int *)calloc(101,sizeof(int ));
	while(x!=5)
	{
		target(choice);
	}
}
int changeprize(int prize)
{
	char pw[10],pass[10]="pps";
	printf(" Enter the password: ");
	scanf("%s",&pw);
	if (strcmp(pw,pass)==0)
	{
		printf(" Enter new price: ");
		scanf("%d",&prize);
		system("PAUSE");
		system("CLS");
	}
	else 
		printf("Wrong Password! \n");
	return prize;
}
void reservation(int *a,int price,int slection)
{          
		int l,m;
		printf("\n                                SCREEN\n\n\n");
		for (l=1;l<=100;l++)
		{
			if (a[l]==0)
				printf("%d\t",l);
			else 
				printf("*\t",l);	
			if(l%10==0)
				printf("\n\n");
		}
		printf("NAME: ");
		scanf(" %19[^\n]%*[^\n]",&person[count].name);
		printf("PHONE NUMBER: ");
		scanf("%u",&person[count].phone);
		printf("ENTER THE SEAT NUMBER YOU WANT ");
		scanf("%d",&m);
		if (m>100||m<1)
			{
				printf("UNAVAILABLE\nI REQUEST YOU TO RE-ENTER THE SEAT NUMBER: ");
				scanf("%d",&m);
			}
		if (a[m]==1)
			{
				printf("SORRY, THIS TICKET IS ALREADY BOOKED\n");
				printf("PLEASE CHOOSE ANOTHER SEAT\n");
				scanf("%d",&m);
			}
		else			
			a[m]=1;
		person[count].seat=m;
		if (slection==1)
			ticket1(m,person[count].name,id2,price);
		else if (slection==2) 	
			ticket2(m,person[count].name,id2,price);
		else 
			ticket3(m,person[count].name,id2,price);			
		id2++;	
}
int choice1(void)
{
	int choice;
	printf("\n\t MOVIE TICKET BOOKING SYSTEM \t\n");
    char pattern[60]={"*------------------------------------------*"};
	int i;
	for(i=1;i<12;i++)
	{
		if(i%2!=0)
		printf("%s\n",pattern);
		else
		{
			switch(i)
			{
			case 2: printf("| 1 - To edit price of tickets(only admin):|\n"); break;
			case 4: printf("| 2 - To view reserved tickets(only admin):|\n"); break;
			case 6: printf("| 3 - To puchase ticket:                   |\n"); break;
			case 8: printf("| 4 - To cancel the seat:                  |\n"); break;
			case 10: printf("| 5 - Exit system:                         |\n"); break;
		    }
		}
	}
	printf("\n  Enter your choice: ");
	scanf("%d",&choice);
	return choice;
}
void cancel(int *array)
{
      int s,i,stop;
	  printf("Enter ID number of ticket: ");
	  scanf("%d",&s);
	  for (i=0;i<300;i++)
	  {
	  		if(s==person[i].id)
	  		{
					 stop=5;
					 system("cls");
					 printf("%s, your seat %d is cancelled",person[i].name,person[i].seat);
					 array[person[i].seat]=0;
					 i=300;
	  		}
	  }
	  if (stop!=5)	
	  		printf("Incorrect Ticket ID Number! Please enter the right one to cancel ticket: \n");
}
void ticket1(int choice,char name[10],int id2,int price)
{
		system("cls");
		printf("\n\n");
        printf("\t-------------------------TICKET------------------------\n");
        printf("\t============================================================\n");
        printf("\t Booking ID : %d \t\t\tShow Name : Avengers: EndGame\n",id2);
        printf("\t Customer  : %s\n",name);
        printf("\t\t\t                              Date      : 29-04-2019\n");
        printf("\t                                              Time      : 08:00pm\n");
        printf("\t                                              Hall      : 02\n");
        printf("\t                                              seats No. : %d  \n",choice);
        printf("\t                                              price . : %d  \n\n",price);
		person[count].id=id2;
        printf("\t============================================================\n");
        return;
}
void details(void)
{
	int i;
	char pw[10],pass[10]="pps";
	printf("  Enter the password: ");
	scanf("%s",&pw);
	if (strcmp(pw,pass)==0)
	{
		for (i=0;i<count;i++)
		{
			printf("seat no: %d is booked by %s booking id is %d\n",person[i].seat,person[i].name,person[i].id);
		}
	}
	else                                                 
		printf("Wrong password! \n");
		system("PAUSE");
		system("CLS");
	
}             
int movie(void)
{
	int i;
	system("cls");
	printf("\n\t\t\tWhich movie do you want to see?\n");
	printf("\n\t\t\tPRESS: \n");
	printf("\t\t\t1 - Avengers: EndGame\n\n");
	printf("\t\t\t2 - Captain Marvel\n\n");
	printf("\t\t\t3 - Spider-Man: Far From Home\n");
	scanf("%d",&i);
	system("cls");
	return i;
}
void ticket2(int choice,char name[10],int id2,int price)
{
		system("cls");
		printf("\n\n");
        printf("\t-------------------------TICKET------------------------\n");
        printf("\t============================================================\n");
        printf("\t Booking ID : %d \t\t\tShow Name : Captain Marvel\n",id2);
        printf("\t Customer  : %s\n",name);
        printf("\t\t\t                              Date      : 17-12-2021\n");
        printf("\t                                              Time      : 07:00pm\n");
        printf("\t                                              Hall      : 03\n");
        printf("\t                                              seats No. : %d  \n",choice);
        printf("\t                                              price . : %d  \n\n",price);
        person[count].id=id2;
        printf("\t============================================================\n");
        return;
}
int cmovie(void)
{
	int i;
	printf("\n\t\t\tWhich movie do you want to cancel\n");
	printf("\n\t\t\tPRESS: \n");
	printf("\t\t\t1 - Avengers: EndGame\n\n");
	printf("\t\t\t2 - Captain Marvel\n\n");
	printf("\t\t\t3 - Spider-Man: Far From Home\n");
	scanf("%d",&i);
	return i;		
}
void ticket3(int choice,char name[10],int id2,int price)
{
		system("cls");
		printf("\n\n");
        printf("\t-------------------------TICKET------------------------\n");
        printf("\t============================================================\n");
        printf("\t Booking ID : %d \t\t\tShow Name : Spider-Man: No Way Home \n",id2);
        printf("\t Customer  : %s\n",name);
        printf("\t\t\t                              Date      : 17-12-2021\n");
        printf("\t                                              Time      : 10:00am\n");
        printf("\t                                              Hall      : 04\n");
        printf("\t                                              seats No. : %d  \n",choice);
        printf("\t                                              price . : %d  \n\n",price);
        person[count].id=id2;
        printf("\t============================================================\n");
        return;
}
