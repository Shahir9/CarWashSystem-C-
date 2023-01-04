#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <ctype.h>

#define TRUE 1
#define FALSE 0
#define MAXSTACK 15

//Staff Stack
int top=-1;
char stackStaffName[MAXSTACK][20];
int stackStaffID[MAXSTACK];
float stackStaffSalary[MAXSTACK];
int stackStaffYear[MAXSTACK];

//Function
int login();
void adminMenu();
void employeeMenu();

//Car Function
void addCar();
void listCar();
void deleteCar();

//Employee Management Function
void pushStaff();
void popStaff();
void viewStaff();
void findStaff();
void bubbleSort();
void exchange(int,int);

//Analytic
void viewAnalysis();

//CAR STRUCTURE
typedef struct cust
{
    char custName[20];
    char phoneNumber[20];
};

typedef struct car
{
    char plateNum[10];
    char model[20];
    int type;
    char package;
    double price;
    struct cust cust_detail;
    struct car *link;
}NODE;
NODE *front,*rear,*delNode;

//Global Variable
float totalCar = 0;
int carCount = 0;
float totalMPV = 0;
int MPVcount = 0;
float totalSUV = 0;
int SUVcount = 0;
float totalProfit;

int main(){
    time_t t;
	time(&t);
    printf("\t*************************************************\n");
	printf("\t*                                               *\n");
	printf("\t*         -----------------------------         *\n");
	printf("\t*           CAR WASH MANAGEMENT SYSTEM          *\n");
	printf("\t*         -----------------------------         *\n");
	printf("\t*                                               *\n");
	printf("\t*************************************************\n\n\n");
    for(int i=0;i<65;i++)
    printf("-");
    printf("\nCurrent date and time : %s",ctime(&t));
    for(int i=0;i<65;i++)
    printf("-");

    int access = login();
    if(access == 1)
        adminMenu();
    else
        employeeMenu();
}

int login(){
    int access = 0;
	int a=0,i=0;
    char uname[10],c=' ';
    char pword[10],code[10];
    char admin[10]      = "admin";
    char adminPass[10]  = "password";
    char emp[10]        = "user";
    char empPass[10]    = "pass";

    do
    {
        printf("\n\n  **************************  LOGIN  **************************  ");
        printf(" \n\n                ENTER USERNAME: ");
        scanf("%s", &uname);
        printf(" \n                ENTER PASSWORD: ");
        while(i<10)
        {
            pword[i]=getch();
            c=pword[i];
            if(c==13) break;
            else printf("*");
            i++;
        }
        pword[i]='\0';

        i=0;

		if(strcmp(uname,admin)==0 && strcmp(pword,adminPass)==0)
        {
            printf("\n\n\n             LOGIN IS SUCCESSFUL!");
            printf("\n              LOGGED IN AS ADMIN");
            access = 1;
            return access;
        }
        else if(strcmp(uname,emp)==0 && strcmp(pword,empPass)==0)
        {
            printf("\n\n\n             LOGIN IS SUCCESSFUL!");
            printf("\n              LOGGED IN AS STAFF");
            access = 2;
            return access;
        }
        else
        {
            printf("\n\n\n                 SORRY !!!!  LOGIN IS UNSUCESSFUL");
            a++;
            getch();
        }
    }
	while(a<=2);
	if (a>2)
	{
		printf("\nSorry you have entered the wrong username and password for four times!!!");
		getch();
    }
    system("cls");
}

//MENU
void adminMenu(){
    int choice;

    while (1){
    system("cls");
    for(int i=0;i<65;i++)
    printf("-");
    printf("\n\t\tCAR WASH MANAGEMENT SYSTEM\n");
    for(int i=0;i<65;i++)
    printf("-");

    printf("\nLOGGED IN AS ADMIN");
    printf("\n*Please select*:");
    printf("\n\n");

    printf("CAR WASH QUEUE MANAGEMENT");
    printf(" \n 1 -> Add Car into Queue");
    printf("\n----------------------------------");
    printf(" \n 2 -> View Car Queue");
    printf("\n----------------------------------");
    printf(" \n 3 -> Remove Car from Queue");
    printf("\n-----------------------------------");
    printf("\n\nSTAFF MANAGEMENT");
    printf(" \n 4 -> Add Employee");
    printf("\n----------------------------------");
    printf(" \n 5 -> Undo Register Employee");
    printf("\n----------------------------------");
    printf(" \n 6 -> View Employee");
    printf("\n----------------------------------");
    printf(" \n 7 -> Search Employee");
    printf("\n-----------------------------------");
    printf("\n\nANALYTIC");
    printf(" \n 8 -> View Analysis");
    printf("\n----------------------------------");
    printf("\nSYSTEM");
    printf(" \n 9 -> Log Out");
    printf("\n----------------------------------");
    printf("\nEnter Option: ");
    choice=getche();
    choice=toupper(choice);

    switch(choice)
    {
        case '1':
            addCar();break;
        case '2':
            listCar();break;
        case '3':
            deleteCar();break;
        case '4':
            enterStaff();break;
        case '5':
            popStaff();break;
        case '6':
            viewStaff();break;
        case '7':
            findStaff();break;
        case '8':
            viewAnalysis();break;
        case '9':
            system("cls");
            time_t t;
            time(&t);
            printf("\n\n\t *****SUCCESSFULLY LOGGED OUT FROM THE SYSTEM*****\n");
            for(int i=0;i<65;i++)
                printf("-");
            printf("\n\t\t %s \n",ctime(&t));
            for(int i=0;i<65;i++)
                printf("-");
            exit(0);
            break;
        default:
            system("cls");
            printf("Incorrect Input");
            printf("\n Press any key to continue");
            getch();
		}
    }
}

void employeeMenu(){
    char choice;

    while (1){
        system("cls");
        for(int i=0;i<65;i++)
            printf("-");
        printf("\n\t\tCAR WASH MANAGEMENT SYSTEM\n");
        for(int i=0;i<65;i++)
            printf("-");
        printf("\nLOGGED IN AS STAFF");
        printf("\n*Please select*:");
		printf("\n\n");
		printf(" \n 1 -> Add Car into Queue");
		printf("\n----------------------------------");
		printf(" \n 2 -> View Car Queue");
		printf("\n----------------------------------");
		printf(" \n 3 -> Remove Car from Queue");
		printf("\n-----------------------------------");
		printf(" \n 4 -> Log Out");
		printf("\n-----------------------------------");
		printf("\n");
        printf("\nEnter Option: ");
		choice=getche();
		choice=toupper(choice);

		switch(choice)
		{
			case '1':
				addCar();break;
			case '2':
				listCar();break;
			case '3':
				deleteCar();break;
			case '4':
				system("cls");
				time_t t;
                time(&t);
				printf("\n\n\t *****SUCCESSFULLY LOGGED OUT FROM THE SYSTEM*****\n");
				for(int i=0;i<65;i++)
                    printf("-");
                printf("\n\t\t %s \n",ctime(&t));
                for(int i=0;i<65;i++)
                    printf("-");
				exit(0);
				break;
			default:
				system("cls");
				printf("Incorrect Input");
				printf("\n Press any key to continue");
				getch();
		}
	}
}

//CAR FUNCTION
void addCar(){
    system("cls");
	char type;
	char package;

    NODE *temp;
    temp=(NODE *)malloc(sizeof(NODE));
    if(temp == NULL)
        printf("---OVERFLOW---");
    else
    {
        for(int i=0;i<65;i++)
            printf("-");
        printf("\n\t\tCAR WASH MANAGEMENT SYSTEM\n");
        for(int i=0;i<65;i++)
            printf("-");
        printf("\nENTER NEW CAR INTO QUEUE");

        printf("\n\nEnter Car Plate Number: ");
        scanf(" %[^\n]",&temp->plateNum);

        printf("Enter Car Model: ");
        scanf(" %[^\n]",&temp->model);

        int result = 0;
        do{
        printf("Enter Car Type(C-Car, S-SUV, M-MPV) : ");
        fflush(stdin);
        scanf("%c", &type);

        if(type=='C' || type=='S' || type=='M')
            {
                fflush(stdin);
                temp->type = type;
                result = 1;
            }
        else
            printf("\nInvalid Input, Please Re-Enter\n");
        }while(result!=1);

        printf("\n\n        ---CAR WASH PACKAGES---");
        printf("\n============== PACKAGES A ==============");
        printf("\nCar Wash + Vacuum (Saloon)");
        printf("\nFull Carpet Anti-Odour Spray");
        printf("\nNano Mist (Interior Anti-Bacterial Trt)");
        printf("\n\nPRICE CAR : RM 39.00");
        printf("\n\nPRICE SUV : RM 45.00");
        printf("\n\nPRICE MPV : RM 49.00");
        printf("\n==========================================");

        printf("\n\n============== PACKAGES B ==============");
        printf("\nCar Wash + Vacuum (Saloon)");
        printf("\nWindscreen Treatment Spray");
        printf("\nWater Wax");
        printf("\n\nPRICE CAR : RM 39.00");
        printf("\n\nPRICE SUV : RM 45.00");
        printf("\n\nPRICE MPV : RM 49.00");
        printf("\n==========================================");

        printf("\n\n============== PACKAGES C ==============");
        printf("\nCar Wash + Vacuum (Saloon)");
        printf("\nFull Carpet Anti-Odour Spray");
        printf("\nNano Mist (Interior Anti-Bacterial Trt)");
        printf("\nWater Wax");
        printf("\n\nPRICE CAR : RM 49.00");
        printf("\n\nPRICE SUV : RM 59.00");
        printf("\n\nPRICE MPV : RM 69.00");
        printf("\n==========================================");

        printf("\n\n============== PACKAGES D ==============");
        printf("\nCar Wash + Vacuum (Saloon)");
        printf("\nWindscreen Treatment");
        printf("\nFull Carpet Anti-Odour Spray");
        printf("\nMeguiar's Wax");
        printf("\n\nPRICE CAR : RM  99.00");
        printf("\n\nPRICE SUV : RM 119.00");
        printf("\n\nPRICE MPV : RM 139.00");
        printf("\n==========================================");
        result = 0;
        do{
        printf("\nEnter Car Wash Package: ");
        fflush(stdin);
        scanf("%c", &package);

            if(package=='A')
                {
                temp->package = package;
                    if(type=='C'){
                        totalCar += 39;
                        carCount++;
                        temp->price = 39;
                    }
                    else if(type=='S'){
                        totalSUV+=45;
                        SUVcount++;
                        temp->price = 45;
                    }
                    else{
                        totalMPV+=49;
                        MPVcount++;
                        temp->price = 49;
                    }
                result = 1;
            }
            else if(package=='B')
                {
                temp->package = package;
                    if(type=='C'){
                        totalCar += 39;
                        carCount++;
                        temp->price = 39;
                    }
                    else if(type=='S'){
                        totalSUV+=45;
                        SUVcount++;
                        temp->price = 45;
                    }
                    else{
                        totalMPV+=49;
                        MPVcount++;
                        temp->price = 49;
                    }
                result = 1;
            }
            else if(package=='C')
                {
                temp->package = package;
                    if(type=='C'){
                        totalCar += 49;
                        carCount++;
                        temp->price = 49;
                    }
                    else if(type=='S'){
                        totalSUV+=59;
                        SUVcount++;
                        temp->price = 59;
                    }
                    else{
                        totalMPV+=69;
                        MPVcount++;
                        temp->price = 69;
                    }
                result = 1;
            }
            else if(package=='D')
                {
                temp->package = package;
                    if(type=='C'){
                        totalCar += 99;
                        carCount++;
                        temp->price = 99;
                    }
                    else if(type=='S'){
                        totalSUV+=119;
                        SUVcount++;
                        temp->price = 119;
                    }
                    else{
                        totalMPV+=139;
                        MPVcount++;
                        temp->price = 139;
                    }
                result = 1;
            }
            else
                printf("Invalid Input, Please Re-Enter");
        }while(result!=1);

        printf("\nEnter Customer Name: ");
        fflush(stdin);
        scanf(" %[^\n]",&temp->cust_detail.custName);
        fflush(stdin);
        printf("\nEnter Customer Phone Number: ");
        fflush(stdin);
        scanf(" %[^\n]",&temp->cust_detail.phoneNumber);
        fflush(stdin);
        temp->link=NULL;
        if(front == NULL)
            front = rear = temp;
        else
            rear->link=temp; rear = temp;
        printf("\n\n ===NEW CAR HAS BEEN ENTERED INTO QUEUE TO WASH=== ");
    }
    printf("\n Press any key to continue");
    getch();
}

void listCar(){
    system("cls");
    for(int i=0;i<65;i++)
            printf("-");
        printf("\n\t\tCAR WASH MANAGEMENT SYSTEM\n");
        for(int i=0;i<65;i++)
            printf("-");
        printf("\nCAR WASH QUEUE");
    NODE *t;

    if(front == NULL) printf("\nEmpty Queue\n");
    else
    {
        t=front;
        while(t)
        {
            printf("\n\n\nPlate Number: %s" ,t->plateNum);
            printf("\nCar Brand   : %s" ,t->model);
            printf("\nPackage     : %c" ,t->package);
            printf("\nName        : %s" ,t->cust_detail.custName);
            printf("\nPhone Number: %s" ,t->cust_detail.phoneNumber);
            t=t->link;
        }
    }
    printf("\n Press any key to continue");
    getch();
}

void deleteCar(){
    system("cls");
    for(int i=0;i<65;i++)
            printf("-");
        printf("\n\t\tCAR WASH MANAGEMENT SYSTEM\n");
        for(int i=0;i<65;i++)
            printf("-");
        printf("\nPROCESSING CAR QUEUE");
    if(front == NULL){
        printf("\n\nThe Queue is Empty");
    }
    else{
        delNode = front;
        front = front->link;
        free(delNode);
        printf("\n\nFront Car has been successfully PROCESSED");
    }
    printf("\nPress any key to continue");
    getch();
}

//STAFF MANAGEMENT FUNCTION
void enterStaff(){
    system("cls");
    for(int i=0;i<65;i++)
        printf("-");
    printf("\n\t\tCAR WASH MANAGEMENT SYSTEM\n");
    for(int i=0;i<65;i++)
        printf("-");
    printf("\nNEW STAFF REGISTRATION\n\n");

    if(top+1==MAXSTACK){
        printf("\n");
		printf("\n!!! stack OVERFLOW - can't push stack !!!");
        return;
	}
	else{
        top++;
        printf("Enter Staff Name: ");
        fflush(stdin);
        gets(stackStaffName[top]);
        printf("Enter Staff ID: ");
        scanf("%d",&stackStaffID[top]);
        printf("Enter Staff Salary: ");
        scanf("%f",&stackStaffSalary[top]);
        printf("Enter Year Joined: ");
        scanf("%d",&stackStaffYear[top]);
	}
    printf("\nNEW EMPLOYEE REGISTERED!!!\n");
    printf("\n\nPress any key to continue...");
    getch();
}

void viewStaff(){
	system("cls");
    for(int i=0;i<65;i++)
        printf("-");
    printf("\n\t\tCAR WASH MANAGEMENT SYSTEM\n");
    for(int i=0;i<65;i++)
        printf("-");
    printf("\nSTAFF LIST\n\n");
    if(top==-1){
		printf("\nNO STAFF REGISTERED!!");
		printf("\n\nPress any key to continue");
        getch();
	}
    else{
		for (int i=0;i<=top;i++){
            printf("\n\n--Staff %d--",i+1);
            printf("\nStaff Name : %s",stackStaffName[i]);
            printf("\nStaff ID     : %d",stackStaffID[i]);
            printf("\nJoined Since : %d",stackStaffYear[i]);
            printf("\nStaff Salary : RM%.2f",stackStaffSalary[i]);
		}
    bubbleSort();
    printf("\n\nPress any key to continue");
    getch();
    }
}

void bubbleSort(){
    for(int i=0;i<top-1;i++){
        for(int j=top;j>i;j--)
		{
			if(stackStaffSalary[j] > stackStaffSalary[j-1])
			{
                exchange(j,j-1);
			}
		}
    }
}

void exchange(int index1,int index2){
    float sortSalary[MAXSTACK];
    float tempSalary;

    for(int i=0;i<=top;i++)
    {
        sortSalary[i]=stackStaffSalary[i];
    }

    tempSalary=sortSalary[index1];
    sortSalary[index1]=sortSalary[index2];
    sortSalary[index2]=tempSalary;

    printf("\n\nSORT OF SALARY (Descending)");
    for (int i=0;i<=top;i++){
        printf("\nRM%.2f",sortSalary[i]);
		}
}

void findStaff(){
    system("cls");
    for(int i=0;i<65;i++)
        printf("-");
    printf("\n\t\tCAR WASH MANAGEMENT SYSTEM\n");
    for(int i=0;i<65;i++)
        printf("-");
    printf("\nSEARCH STAFF\n\n");

    int searchStaffID;
    printf("Enter Staff ID: ");
    scanf("%d",&searchStaffID);

    for(int i=0;i<=top;i++)
	{
	    if(stackStaffID[i]==searchStaffID)
		{
			printf("\nSearch Staff Found!");
            printf("\n\nStaff Name   : %s",stackStaffName[i]);
            printf("\nStaff ID     : %d",stackStaffID[i]);
            printf("\nJoined Since : %d",stackStaffYear[i]);
            printf("\nStaff Salary : RM%.2f",stackStaffSalary[i]);
            printf("\n\nPress any key to continue");
            getch();
            return;
		}
	}
    printf("\nSorry, no match found");
    printf("\n\nPress any key to continue");
    getch();
}

void popStaff(){
    system("cls");
    for(int i=0;i<65;i++)
        printf("-");
    printf("\n\t\tCAR WASH MANAGEMENT SYSTEM\n");
    for(int i=0;i<65;i++)
        printf("-");
    printf("\nUNDO STAFF REGISTRATION\n\n");

	if (top<0){
        printf("\nNO STAFF REGISTERED!!!");
        return;
	}
	else{
		top=top-1;
		printf("\nNEW STAFF REGISTRATION CANCELLED");
        return;
	}
	printf("\n\nPress any key to continue");
    getch();
}

//ANALYTIC FUNCTION
void viewAnalysis(){
    totalProfit = totalCar + totalMPV + totalSUV;
    system("cls");
    time_t t;
	time(&t);
    for(int i=0;i<65;i++)
    printf("-");
    printf("\n\t\tCAR WASH MANAGEMENT SYSTEM\n");
    for(int i=0;i<65;i++)
    printf("-");
    printf("\nANALYSIS");
    printf("\nGenerated on: %s",ctime(&t));
    for(int i=0;i<65;i++)
    printf("-");
    printf("\nNUMBER OF CAR : %d",carCount);
    printf("\nNUMBER OF MPV : %d",MPVcount);
    printf("\nNUMBER OF SUV : %d\n",SUVcount);
    for(int i=0;i<65;i++)
    printf("-");
    printf("\nAMOUNT FROM CAR : RM%.2f",totalCar);
    printf("\nAMOUNT FORM MPV : RM%.2f",totalMPV);
    printf("\nAMOUNT FROM SUV : RM%.2f\n",totalSUV);
    for(int i=0;i<65;i++)
    printf("=");
    printf("\nTOTAL AMOUNT: RM%.2f\n",totalProfit);
    for(int i=0;i<65;i++)
    printf("=");
    printf("\n\nAN INVOICE HAS BEEN SUCCESSFULLY GENERATED...");

    //FILE OPERATION

    FILE *Analysis;
    Analysis = fopen("Analysis.txt","w");
    fprintf(Analysis,"ANALYSIS\n");
    for(int i=0;i<65;i++)
        fprintf(Analysis,"-");
    fprintf(Analysis,"\nNUMBER OF CAR : %d",carCount);
    fprintf(Analysis,"\nNUMBER OF MPV : %d",MPVcount);
    fprintf(Analysis,"\nNUMBER OF SUV : %d\n",SUVcount);
    for(int i=0;i<65;i++)
        fprintf(Analysis,"-");
    fprintf(Analysis,"\nAMOUNT FROM CAR : RM%.2f",totalCar);
    fprintf(Analysis,"\nAMOUNT FORM MPV : RM%.2f",totalMPV);
    fprintf(Analysis,"\nAMOUNT FROM SUV : RM%.2f\n",totalSUV);
    for(int i=0;i<65;i++)
        fprintf(Analysis,"=");
    fprintf(Analysis,"\nTOTAL AMOUNT: RM%.2f\n",totalProfit);
    for(int i=0;i<65;i++)
        fprintf(Analysis,"=");
    fprintf(Analysis,"\nGENERATED ON: %s",ctime(&t));
    fclose(Analysis);
    printf("\n Press any key to continue");
    getch();
}
