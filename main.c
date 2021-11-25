#include<stdio.h>
#include<string.h>

int actual =0;    //account
float percentage = 0;

typedef struct {
    char name [100];
    char lastname [100];
    char ID[10];
    float balance;
}ld;

ld arrUsers[50];

//////////////////////////////////////////////////////////////////
void menu(){
    printf("-----------------WELCOME TO CENTRAL BANK OF MOROCCO------------------ \n");
    printf("\t1 - CREATE AN ACCOUNT. \n ");
    printf("\t2 - CREATE SEVERAL ACCOUNT. \n ");
    printf("\t3 - WOULD YOU LIKE TO DEPOSIT? \n");
    printf("\t4 - WOULD YOU LIKE TO WITHDRAW? \n");
    printf("\t5 - CHECK YOUR BALANCE. \n");
    printf("\t6 - (TRI ASCENDANT). \n"); //BANK ACCOUNTS WITH A HIGHER AMOUNT.
    printf("\t7 - (TRI DESCENDANT). \n"); //BANK ACCOUNTS WITH A LOWER AMOUNT.
    printf("\t8 - client list. \n");
    printf("\t9 - customer loyalty. \n");
    printf("\t0 - Exit. \n");
}

//////////////////////////////////////////////////////////////////
void user(){
    printf(" Enter your name please : ");
    scanf("%s",arrUsers[actual].name);
    printf(" Enter your lastname : ");
    scanf("%s",arrUsers[actual].lastname);
    printf(" Enter your ID : ");
    scanf("%s",arrUsers[actual].ID);
    printf(" Enter your Balance: ");
    scanf("%f",&arrUsers[actual].balance);
    actual++;
}

//////////////////////////////////////////////////////////////////
void multi_user(){
    int i;
    int accounts_num;
    printf("how many accounts do you want to create: ");
    scanf("%d",&accounts_num);
    for(i=0; i<accounts_num; i++){
        user();
    }
}

//////////////////////////////////////////////////////////////////
int searchForUser(char ID[50]){
    int i;
    if(actual > 0)
        for(i=0 ; i < actual ; i++){
            if(strcmp(arrUsers[i].ID,ID)  == 0){

                return i;
            }
        }
    else{
        return -1;
    }

        return -1;
}
//////////////////////////////////////////////////////////////////
void showAccount(int position){
    printf("***********************************************\n");
    printf("*\t\t\t\t\t Name : %s \n",arrUsers[position].name);
    printf("*\t\t\t\t\t Last Name : %s \n",arrUsers[position].lastname);
    printf("*\t\t\t\t\t ID (CIN) : %s \n",arrUsers[position].ID);
    printf("*\t\t\t\t\t Balance : %.2f \n",arrUsers[position].balance);
    printf("***********************************************\n");
}
//////////////////////////////////////////////////////////////////
void AllUsers(){
    for (int i = 0; i < actual ; i++) {

        printf("*************************************************************************\n");
        printf("*\t\t\t\t\t Name : %s \n",arrUsers[i].name);
        printf("*\t\t\t\t\t Last Name : %s \n",arrUsers[i].lastname);
        printf("*\t\t\t\t\t ID (CIN) : %s \n",arrUsers[i].ID);
        printf("*\t\t\t\t\t Balance : %.2f \n",arrUsers[i].balance);
        printf("**************************************************************************\n");

    }
}
//////////////////////////////////////////////////////////////////
void deposit(){
    char searchID[10];
    int position ;
    float dep;
    printf(" Enter your ID. ");
    scanf("%s", searchID);

    position = searchForUser(searchID);

    if(position != -1){
        printf("\tWELCOME\n");
        showAccount(position);
        printf(" How much you want to deposit?\n");
        scanf("%f",&dep);

        printf("The operation is completed successfully.\n ");
        printf("You made a deposit of %.2f\n",dep);

        arrUsers[position].balance += dep;


        showAccount(position);

    }
}
/////////////////////////////////////////////////////////////////
void withdrawal(){
    char searchID[10];
    int position ;
    float withdraw;
    printf(" Enter your ID. ");
    scanf("%s", searchID);

    position = searchForUser(searchID);


    if(position != -1){
        printf(" How much you want to withdraw ? ");
        scanf("%f",&withdraw);
        if(arrUsers[position].balance >= withdraw){
            arrUsers[position].balance -= withdraw;
            printf(" The operation is completed successfully.\n ");
            printf(" You made a withdrawal of  %.2f.\n", withdraw);

            showAccount(position);
        }else
            printf("Sorry you can t make a withdrawal because you don't have this balance .");
    }
    else
        printf("Sorry we don't find this account.");
}
/////////////////////////////////////////////////////////////////
void  tri_Ascendant(){
    int   i,j;
    ld account[50];

    for(i = 0; i < actual -1 ; i++){
        for( j = i+1 ; j < actual ; j++ )
            if(arrUsers[i].balance > arrUsers[j].balance){
                account[0] = arrUsers[i];
                arrUsers[i] = arrUsers[j];
                arrUsers[j] = account[0];

            }
    }
    for ( i=0 ; i < actual ; i++)
    {
        printf("%s  |   %s |   %s  |  %.2f\n",arrUsers[i].name,arrUsers[i].lastname,arrUsers[i].ID,arrUsers[i].balance);
    }
}
/////////////////////////////////////////////////////////////////
void tri_Descendant (){

    int   i,j;
    ld account[50];

    for(i = 0; i < actual -1 ; i++){
        for( j = i+1 ; j < actual ; j++ )
            if(arrUsers[i].balance < arrUsers[j].balance){
                account[0] = arrUsers[i];
                arrUsers[i] = arrUsers[j];
                arrUsers[j] = account[0];

            }
    }
    for ( i=0 ; i < actual ; i++)
    {
        printf("%s  |   %s |   %s  |  %.2f\n",arrUsers[i].name,arrUsers[i].lastname,arrUsers[i].ID,arrUsers[i].balance);
    }
}
/////////////////////////////////////////////////////////////////
void getBalance(){
    char ID[50];
    int position;
    printf("Enter ID : ");
    scanf("%s",ID);
    position = searchForUser(ID);
    if(position != -1){
        printf("Your Balance is : %.2f \n",arrUsers[position].balance);
    }
}
/////////////////////////////////////////////////////////////////

int main() {

    int choice;
    int actual = 0, accounts_num;
    do {
        menu();
        printf(" Enter your choice. ");
        scanf("%d", &choice);
        switch (choice) {
            case 1 :
                user(actual);
                actual++;
                break;
            case 2 :
                multi_user(actual);
                actual += accounts_num;
                break;
            case 3 :
                deposit();
                break;
            case 4 :
                withdrawal();
                break;
            case 5:
                getBalance();
                break;
            case 6:
                 tri_Ascendant();
                break;
            case 7:
                tri_Descendant();
                break;
            case 8:
                AllUsers();
                break;
            case 9:
                tri_Descendant();
                for(int i=0;i<3;i++){
                    percentage=0;
                    percentage=(arrUsers[i].balance*1.3)/100;
                    arrUsers[i].balance=  arrUsers[i].balance+percentage;
                    printf("\n\n\n\n");
                    printf("%s\t,%s\t,%s\t,%.2f\n",arrUsers[i].name,arrUsers[i].lastname,arrUsers[i].ID, arrUsers[i].balance);
                }
                break;
            case 0:
                printf(" GOOD BYE! ");
                break;
            default:
                printf(" Sorry you can t access ");

        }
    } while (choice != 0);

    return 0;
}
