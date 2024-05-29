#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<windows.h>

typedef struct node
{

    float data;
    char foodname[50];
    int quantity;
    float price;
    struct node *next;

}node;
typedef struct head
{
    node *start;
}head;
void insertend(head *t, float data, char foodname[25], int quantity, float price)
{
    node *p, *q;
    p=(node *)malloc(sizeof(node));
    p->data=data;
    p->quantity=quantity;
    p->price=price;
    strcpy(p->foodname, foodname);
    p->next=NULL;
    if(t->start==NULL)
    {
        t->start=p;
    }
    else
    {
        q=t->start;
        while(q->next!=NULL)
        {
            q=q->next;
        }
        q->next=p;
    }
}

void ccolor(int clr)
{

    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, clr);

}
void foodlist(head *t)
{

    printf("\n\t"); ccolor(26);
    printf("_______________________________________________________");ccolor(100);
    printf("\n\t"); ccolor(26);
    printf("  Food Code       Food Name            Food Price");ccolor(100);
    printf("\n\t"); ccolor(26);
    printf("-------------------------------------------------------");ccolor(100);

    node *p;
    p=t->start;
    while(p!= NULL)
    {
        printf("\n\t");
        printf("  %0.1f   |  %-25s     |    %0.2f   ",p->data,p->foodname,p->price);
        ccolor(100);
        printf("\n\t");
        printf("-------------------------------------------------------");
        p=p->next;
    }
}
void foodlist1(head *t)
{
    printf("\n\t"); ccolor(26);
    printf("___________________________________________________________________");ccolor(100);
    printf("\n\t"); ccolor(26);
    printf("  Food Code     Food Name                    Quantity    Food Price");ccolor(100);
    printf("\n\t"); ccolor(26);
    printf("-------------------------------------------------------------------");ccolor(100);

    node *p;
    p=t->start;
    while(p!= NULL)
    {
        printf("\n\t");
        printf("  %0.1f   |  %-25s      |    %2d      |  %0.2f   ",p->data,p->foodname, p->quantity, p->price);
        printf("\n\t");
        printf("------------------------------------------------------------------");
        p=p->next;
    }
}
float getbill(head *t)
{
    node *p;
    float b=0;
    p=t->start;
    while(p!=NULL)
    {
        b=b+p->price;
        p=p->next;
    }
    return b;
}
void order(head *t, head *l, float fc, int qty)
{
    node *p;
    p=t->start;
    while(p->data!=fc)
    {
        p=p->next;
    }
    insertend(l, fc, p->foodname, qty, (p->price*qty));
    return;
}
void cls()
{
    system("cls");
}

void main()
{
    head x, s, m, d, o;
    x.start=s.start=m.start=d.start=o.start=NULL;
    float fcode;
    int qty, lo;
    ccolor(100);
    
    insertend(&s, 1.1, "Popcorn", 1, 70);
    insertend(&s, 1.2, "Chicken Burger", 1, 150);
    insertend(&s, 1.3, "Chicken Roll", 1, 100);
    insertend(&s, 1.4, "Pav Bhaji", 1, 100);
    insertend(&s, 1.5, "Gobi Manchurian", 1, 90);
    insertend(&s, 1.6, "Pani Puri", 1, 50);
    insertend(&s, 1.7, "Kachori", 1, 30);
    insertend(&s, 1.8, "Samosa", 1, 25);
    insertend(&s, 1.9, "Grilled Cheese Sandwich", 1, 70);

    insertend(&m, 2.1, "Gujarat Thali", 1, 300);
    insertend(&m, 2.2, "Mutton Dum biryani", 1, 250);
    insertend(&m, 2.3, "Chicken Dum Biryani", 1, 150);
    insertend(&m, 2.4, "North Indian Special", 1, 200);
    insertend(&m, 2.5, "South Indian Special", 1, 180);
    insertend(&m, 2.6, "Fish Fry", 1, 120);
    insertend(&m, 2.7, "Egg Curry", 1, 100);
    insertend(&m, 2.8, "Veg Pulao", 1, 60);
    insertend(&m, 2.9, "Mutton Bone Soup", 1, 150);

    insertend(&d, 3.1, "Orea Shake", 1, 150);
    insertend(&d, 3.2, "Chikoo", 1, 60);
    insertend(&d, 3.3, "Chocolate Cake", 1, 100);
    insertend(&d, 3.4, "Red Velevet Cake", 1, 220);
    insertend(&d, 3.5, "Strawberry Cake", 1, 90);
    insertend(&d, 3.6, "Mixed Fruit Juice", 1, 150);
    insertend(&d, 3.7, "Fruit Milkshake", 1, 80);
    insertend(&d, 3.8, "Banana Shake", 1, 55);
    insertend(&d, 3.9, "Watermelon Juice", 1, 40);
    //login
    char uid[20], pwd[20], uid1[20], pwd1[20], c=' ', k=' ';
    int i=0, ch, num[30];
    while(1)
    {
        cls();

  printf("              ==============================          \n");
  time_t t;   // not a primitive datatype
  time(&t);
  printf("\t\t %s", ctime(&t));
  printf("              ==============================          \n\n");
 mainscr:
  printf("              ==============================          \n");
  printf("                Food Ordering System - ABGN         \n ");
  printf("             ==============================          \n\n");
 
 
smallmain:    printf("\n\n Enter Choice:    1. Login     2.New User    3.Exit\n");
        scanf("%d", &ch);
        if(ch==3)
            break;
    //register new user
        if(ch==2)
        {
            
            printf(" \n\n                  ENTER PHONE NUM :-");
            scanf("%s", &num);
            printf(" \n\n                  ENTER USERNAME:-");
            scanf("%s", &uid1);
            printf(" \n\n                  ENTER PASSWORD:-");
            while(i<20)
            {
                pwd1[i]=getch();
                c=pwd1[i];
                if(c=='\r') break;
                else printf("*");
                i++;
            }
            pwd1[i]='\0';
  
            printf("\n\n            Registered Successfully...!\n");
            Sleep(2000);
        }
        else
        {
            printf("\n  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  ");
            printf(" \n\n                  ENTER USERNAME:-");
            scanf("%s", &uid);
            printf(" \n\n                  ENTER PASSWORD:-");
            c=' '; i=0;
            while(i<20)
            {
                pwd[i]=getch();
                c=pwd[i];
                if(c=='\r') break;
                else printf("*");
                i++;
            }
            pwd[i]='\0';

            //USERMENU
            if(strcmp(uid,uid1)==0&&strcmp(pwd,pwd1)==0)
            {
                printf("\n\n            LOGIN SUCCESFULL...!");
           
                Sleep(2000);
                cls();
                int i, ch;
      mainmenu: printf("Enter choice:   1.View Food Menu   2.View Previous Order   3.Log Out\n");
                scanf("%d", &ch);
                if(ch==2)
                {
                    if(o.start==NULL)
                    {
                        printf("Previous Order does not exist..!\n");
                        Sleep(2000);
                        cls();
                        goto mainmenu;
                    }
                    else
                    {
                        cls();
                        foodlist1(&o);
                        printf("\nPress 0 to continue.\n");
                        scanf("%d", &ch);
                        if(ch==0)
                        {
                            goto mainmenu;
                        }
                    }

                }
                else if(ch==1)
                {
             order: printf("Enter Choice:\n");
                    printf(" 1.Munch\n 2.Main Dish\n 3.Mocktail\n");
                    scanf("%d", &ch);
                    while(1){
                    switch(ch)
                    {
                        case 1: foodlist(&s);
                                printf("\n");
                             printf("Enter Food Code:\n");
                                scanf("%f", &fcode);
                                printf("Enter Quantity of Food:\n");
                                scanf("%d", &qty);
                                order(&s, &o, fcode, qty);
                                foodlist1(&o);
                                break;
                        case 2: foodlist(&m);
                                printf("\n");
                                printf("Enter Food Code:\n");
                                scanf("%f", &fcode);
                                printf("Enter Quantity of Food:\n");
                                scanf("%d", &qty);
                                order(&m, &o, fcode, qty);
                                foodlist1(&o);
                                break;
                        case 3: foodlist(&d);
                                printf("\n");
                                printf("Enter Food Code:\n");
                                scanf("%f", &fcode);
                                printf("Enter Quantity of Food:\n");
                                scanf("%d", &qty);
                                order(&d, &o, fcode, qty);
                                foodlist1(&o);
                                break;
                        default: printf("Invalid Choice.\n");
                    }
        afterorder: printf("\n\n");
                    printf("\n\t\tEnter Choice: \n\t\t  1.Hungry For More? \n\t\t  2.View Order \n\t\t  3.Confirm Order?\n");
                    scanf("%d", &ch);
                    if(ch==1)
                    {
                        cls();
                        goto order;
                    }
                    else if(ch==2)
                    {
                        cls();
                        printf("Current Order:\n");
                        foodlist1(&o);
                        goto afterorder;
                    }
                    //billing
                    else if(ch==3)
                    {
                        cls();
                        foodlist1(&o);
                        printf("\nTotal amount to pay: %0.2f\n", getbill(&o));
                        printf("\nEnjoy Your Meal!\n");
                        printf("\nYour Order Will be in 5Min\n");
                        printf("\nPress 0 to continue.\n");
                        scanf("%d", &ch);
                        if(ch==0)
                        {
                            cls();
                            goto mainmenu;
                        }
                        else 
                        {
                            cls();
                            goto smallmain;
                        }
                    }
                }
                }
                else if(ch==3)
                {
                    cls();
                    goto mainscr;
                }
                else
                    printf("\nInvalid Choice.\n");
            }
            //admin
            else if(strcmp(uid,"ABGN")==0&&strcmp(pwd,"123456")==0)
            {
                printf("\n\n            WELCOME ADMIN......");
                Sleep(3000);
                cls();
                int adch;
        admin:  printf("\n\n            Enter Choice:\n");
                printf("            1. View Food Menu\n");
                printf("            2. Update Food Menu\n");
                printf("            3. View Recent Order\n");
                printf("            4. Log Out\n");
                scanf("%d", &adch);
                cls();
                if(adch==4)
                    goto mainscr;
                switch(adch)
                {
                    case 1:cls();
                        printf("\nMunch:\n");
                        foodlist(&s);
                        Sleep(3000);
                        printf("\nMain Dish:\n");
                        foodlist(&m);
                        Sleep(3000);
                        printf("\nMocktail:\n");
                        foodlist(&d);
                        printf("\nPress 0 to continue.\n");
                        scanf("%d", &ch);
                        if(ch==0)
                        {
                            goto admin;
                        }
                        break;
                    case 3: //Sleep(3000);
                        cls();
                        printf("Recent Order:\n");
                        foodlist1(&o);

                        printf("\t\t %s", ctime(&t));
                        printf(" \t\t                                    Username: %s ",uid1);
                        printf("\n");
                        printf(" \t\t                                    Password: %s ",pwd1);
                        printf("\n");
                        printf(" \t\t                                    Phone num : %s ",num);
                        printf("\n");
                        
                        printf("\nPress 0 to continue.\n");
                        scanf("%d", &ch);
                        if(ch==0)
                        {
                            goto admin;
                        }

                        break;
                    case 2:
                        cls();
                        float fcu, pu;
                        char fnameu[50];
                        printf("UPDATE MENU\n");
                        printf("What do you want to update?\n");
                        printf("Enter Choice:\n");
                        printf("1.Munch\n2.Main Dish\n3.Mocktail\n");
                        scanf("%d", &ch);
                        switch(ch)
                        {
                            case 1: printf("\nEnter Food Code:\n");
                                    scanf("%f", &fcu);
                                  printf("\nEnter Food name:\n");
                                    scanf("%s", &fnameu);
                                    printf("\nEnter price:\n");
                                    scanf("%f", &pu);
                                    insertend(&s, fcu, fnameu, 1, pu);
                                    printf("\nMENU UPDATED\n");
                                    foodlist(&s);
                                    break;
                            case 2: printf("\nEnter Food Code:\n");
                                    scanf("%f", &fcu);
                                    printf("\nEnter Food name:\n");
                                    scanf("%s", &fnameu);
                                    printf("\nEnter price:\n");
                                    scanf("%f", &pu);
                                    insertend(&m, fcu, fnameu, 1, pu);
                                    printf("\nMENU UPDATED\n");
                                    foodlist(&m);
                                    break;
                            case 3: printf("\nEnter Food Code:\n");
                                    scanf("%f", &fcu);
                                    printf("\nEnter Food name:\n");
                                    scanf("%s", &fnameu);
                                    printf("\nEnter price:\n");
                                    scanf("%f", &pu);
                                    insertend(&d, fcu, fnameu, 1, pu);
                                    printf("\nMENU UPDATED\n");
                                    foodlist(&d);
                                    break;

                        }
                        goto admin;
                        break;

                default:printf("\nInvalid Choice\n");
                }
            }
            else
            {
                printf("\n\n        INCORRECT USERNAME OR PASSWORD");
                Sleep(2000);
            }
    }
}
}


