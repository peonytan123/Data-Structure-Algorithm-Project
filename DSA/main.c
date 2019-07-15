#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
struct ticket
{
    int flight;
    char name[99];
    int seat;
    char book_date[15];
    int phone_no;
    struct ticket *ptrnext;
};
struct ticket *headptr, *newptr, *curptr, *prevptr,*ptrnext,*min;

void flightlist();
int read();
void enqueue();
void deletea();
void sortbyflight();
int i;
int r;
int main()
{
    /*Main Menu*/
    char ch;
    int choic=TRUE;
    headptr=NULL;
    system("cls");
    printf("\t\t-------------------------------------------------\n");
    printf("\t\t\tHappy Booking\n");
    printf("\t\tAirline Reservation System\n");
    printf("\t\t-------------------------------------------------\n");
    printf("\n Press any key to continue");
    getch();
    Menu:
    printf(" \nWelcome to Happy Booking\n");
    printf("\n");
    for(i=0;i<80;i++)
    printf("-");
    while(choic==TRUE)
    {
        system("cls");
        printf(" \n A Book a flight");
        printf(" \n B View flight");
        printf(" \n C Cancel flight ");
        printf(" \n D Search ");
        printf(" \n E Sort by flight ");
        printf(" \n F Exit");
        printf("\n\n\n\n\t\tPlease enter your choice:\n\n");
        ch=getche();
        switch(toupper(ch))
        {
            case 'A':
            r=read();

            if(r==1)
            {
              enqueue();
            }
            break;
            case 'B':
            list();
            break;
            case 'C':
            deletea();break;
            case 'D':
            search();break;
            case 'E':
            sortbyflight();break;
            case 'F':
            system("cls");
            printf("\n\n\t *THANK YOU*");
            exit(0);
            break;
            default:
            system("cls");
            printf("Wrong Input");
            printf("\n Press try again");
            goto Menu;
        }
    }
}


void flightlist()
{
    printf("\n");
    printf("\n\t\tFlight List ");
    printf("\n\t Flight No \t Destination \t Price(RM) \t Time");
    printf("\n\t 01 \t Thailand \t 309 \t 0300");
    printf("\n\t 02 \t Thailand \t 309 \t 1900");
    printf("\n\t 03 \t Singapore \t 150 \t 0600");
    printf("\n\t 04 \t Singapore \t 150 \t 2000");
    printf("\n\t 05 \t Sabah \t 300 \t 0900");
    printf("\n\t 06 \t Sabah \t 300 \t 2100");
    printf("\n\t 07 \t Indonesia \t 234 \t 1200");
    printf("\n\t 08 \t Indonesia \t 234 \t 2200");
}

int read()
{
    int exist = 0;
    system("cls");
    flightlist();
    newptr = (struct ticket*)malloc(sizeof(struct ticket));
    printf("\n Enter flight:");
    scanf("%d",&newptr->flight);
        if(newptr->flight>=1 && newptr->flight<=8)
    {
        printf("\nSeat Number(1-60): ");
        scanf("%d",&newptr->seat);

        curptr=headptr;
        while(curptr != NULL)
        {
            if (curptr->flight == newptr->flight && curptr->seat == newptr->seat)
            {
                printf("The flight has been booked.");
                exist=1;
                break;
            }
            curptr=curptr->ptrnext;
        }
        if (exist==1)
        {
          return;
        }
        if(newptr->seat >60)
        {
            printf("\nThis seat is not available.");
        }
        else if(newptr->seat >0 && newptr->seat <= 60)
        {
            printf("Name: ");
            scanf("%s",&newptr->name);
            printf("Enter ticket date(dd/mm/yyyy): \n");
            scanf("%s",&newptr->book_date);
            printf("Phone number: ");
            scanf("%d",&newptr->phone_no);
            printf("\n\n1 Your flight is successfully booked!!");
        }
        return 1;
    }
    else
    {
        printf("\nFlight not found!");
        return 0;
    }
    getch();
    system("cls");
}

void enqueue()
{
    if (headptr==NULL)
    {
        headptr=newptr;
        newptr->ptrnext=NULL;
    }
    else
    {
        curptr=headptr;
        while(curptr->ptrnext!=NULL)
        {
            curptr=curptr->ptrnext;
        }
    curptr->ptrnext=newptr;
    newptr->ptrnext=NULL;
    }
}

void list()
{
    system("cls");
    printf("\n Press any key to continue");
    getche();
    printf("\n");
    printf(" Flight Booking List ");
    printf("\n");
    for(i=0;i<118;i++)
    {
        printf("-");
    }
    printf("\n");
    printf("\n\tFlight\t");
    printf("\tName\t");
    printf("\tSeat\t");
    printf("\tTicket Date ");
    printf("\t\tPhone Number\n ");
    if (headptr==NULL)
    {
        for(i=0;i<118;i++)
        printf("-");
        printf("\n\nEmpty list.\n");
    }
    else
    {
        curptr=headptr;
        while(curptr!=NULL)
        {
            //prevptr=curptr;
            printf("\t%d\t\t",curptr->flight);
            printf("%s\t\t", curptr->name);
            printf("%d\t\t",curptr->seat);
            printf("%s\t\t",curptr->book_date);
            printf("\t%d\t\t\n",curptr->phone_no);
            curptr=curptr->ptrnext;
        }
    }
    printf("\n Press any key to continue");
    getch();
    system("cls");
}

void deletea()
{
    int seatdlt;
    int flight;
    if (headptr==NULL)
    {
        printf("\n\nThe list is empty , cannot delete!!!");
    }
    else
    {
        printf("Which flight you wan to delete:");
        scanf("%d",&flight);
        printf("\nWhat seat you want to delete: ");
        scanf("%d",&seatdlt);
        curptr=headptr;
        while(curptr != NULL)
        {
            if (curptr->flight == flight && curptr->seat == seatdlt)
            {
                prevptr->ptrnext=curptr->ptrnext;
                free(curptr);
                break;
            }
            else
            {
                prevptr=curptr;
                curptr=curptr->ptrnext;
            }
        }
    }
}

void search()
{
    int flightno;
    printf("\n\n\nWhat flight you want to search: ");
    scanf("%d",&flightno);
    curptr=headptr;
    if(curptr != NULL)
    {
        if (curptr->flight == flightno)
        {
            printf("\n\n\nRecord is found!!!");
            printf("\n\n\nFlight: %d", curptr->flight);
            printf("\nName: %s", curptr->name);
            printf("\nSeat: %d",curptr->seat);
            printf("\nticket Date:%s",curptr->book_date);
            printf("\nPhone No:%d\n\n\n\n",curptr->phone_no);
            printf("\n Press any key to continue");
            getche();
        }
        else
        {
            prevptr=curptr;
            curptr=curptr->ptrnext;
        }
    }
    else
    {
        printf("No record found in this flight!");
        printf("\n Press any key to continue");
        getche();
    }
}

void sortbyflight()
{
    {
        curptr = headptr;
        while(curptr->ptrnext)
        {
            min = curptr;
            newptr = curptr->ptrnext;
            while(newptr)
            {
                if( min->flight > newptr->flight )
                {
                min = newptr;
                }
                newptr = newptr->ptrnext;
            }
            int temp = curptr->flight;
            curptr->flight = min->flight;
            min->flight = temp;
            curptr = curptr->ptrnext;
        }
    }
}
