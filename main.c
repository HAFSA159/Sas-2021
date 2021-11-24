#include<stdio.h>
#include<string.h>

int actuelle =0;    //nbr des comptes

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
    printf("\t4 - WOULD YOU LIKE TO WITHDRAWAL? \n");
    printf("\t5 - CHECK YOUR BALANCE. \n");
    printf("\t6 - (TRI ASCENDANT). \n"); //BANK ACCOUNTS WITH A HIGHER AMOUNT.
    printf("\t7 - (TRI DESCENDANT). \n"); //BANK ACCOUNTS WITH A LOWER AMOUNT.
    printf("\t8 - client list. \n");
    printf("\t9 - Exit. \n");
}

//////////////////////////////////////////////////////////////////
void user(){
    printf(" Enter your name please : ");
    scanf("%s", arrUsers[actuelle].name);
    printf(" Enter your lastname : ");
    scanf("%s",  arrUsers[actuelle].lastname);
    printf(" Enter your ID : ");
    scanf("%s",  arrUsers[actuelle].ID);
    printf(" Enter your Balance: ");
    scanf("%f", & arrUsers[actuelle].balance);
    actuelle++;
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
    if(actuelle > 0)
        for(i=0 ; i < actuelle ; i++){
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
void showCompt(int position){
    printf("***********************************************\n");
    printf("*\t\t\t\t\t Name : %s \n",arrUsers[position].name);
    printf("*\t\t\t\t\t Last Name : %s \n",arrUsers[position].lastname);
    printf("*\t\t\t\t\t ID (CIN) : %s \n",arrUsers[position].ID);
    printf("*\t\t\t\t\t Balance : %.2f \n",arrUsers[position].balance);
    printf("***********************************************\n");
}

//////////////////////////////////////////////////////////////////
void AllUsers(){
    for (int i = 0; i <= actuelle ; i++) {

        printf("***********************************************\n");
        printf("*\t\t\t\t\t Name : %s \n",arrUsers[i].name);
        printf("*\t\t\t\t\t Last Name : %s \n",arrUsers[i].lastname);
        printf("*\t\t\t\t\t ID (CIN) : %s \n",arrUsers[i].ID);
        printf("*\t\t\t\t\t Balance : %.2f \n",arrUsers[i].balance);
        printf("***********************************************\n");

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
        showCompt(position);
        printf(" How much you want to deposit?\n");
        scanf("%f",&dep);

        printf("The operation is completed successfully.\n ");
        printf("You made a deposit of %.2f\n", dep);

        arrUsers[position].balance += dep;

        showCompt(position);

    }
}
/////////////////////////////////////////////////////////////////
void withdrawal(){
    char searchID[10];
    int position ;
    float retrait;
    printf(" Enter your ID. ");
    scanf("%s", searchID);

    position = searchForUser(searchID);


    if(position != -1){
        printf(" How much you want to withdrawal?");
        scanf("%f",&retrait);
        if(arrUsers[position].balance >= retrait){
            arrUsers[position].balance -= retrait;
            printf(" The operation is completed successfully.\n ");
            printf(" You made a withdrawal of  %d.\n", retrait);

            showCompt(position);
        }else
            printf("Sorry you can t make a withdrawal because you don't have this balance .");
    }
    else
        printf("Sorry we don't find this account.");
}
/////////////////////////////////////////////////////
void TRI_Ascendant (){

    int   i,j;
    ld compt[50];

    for(i = 0; i < actuelle -1 ; i++){
        for( j = i+1 ; j < actuelle ; j++ )
            if(arrUsers[i].balance < arrUsers[j].balance){
                compt[0] = arrUsers[i];
                arrUsers[i] = arrUsers[j];
                arrUsers[j] = compt[0];

            }
    }
    for ( i=0 ; i < actuelle ; i++)
    {
        printf("%.2f \n",arrUsers[i].balance);
    }
}
/////////////////////////////////////////////////////////////////

void  TRI_Descendant(){
    int   i,j;
    ld compt[50];

    for(i = 0; i < actuelle -1 ; i++){
        for( j = i+1 ; j < actuelle ; j++ )
            if(arrUsers[i].balance > arrUsers[j].balance){
                compt[0] = arrUsers[i];
                arrUsers[i] = arrUsers[j];
                arrUsers[j] = compt[0];

            }
    }
    for ( i=0 ; i < actuelle ; i++)
    {
        printf("%.2f \n",arrUsers[i].balance);
    }
}
/////////////////////////////////////////////////////////////////

void getBalnce(){
    char ID[50];
    int position;
    printf("Enter ID : ");
    scanf("%s",ID);
    position = searchForUser(ID);
    if(position != -1){
        printf("Your Balance is : %.2f \n",arrUsers[position].balance);
    }


}
int main() {

    int choice;
    int actuelle = 0, accounts_num;
    do {
        menu();
        printf(" Enter your choice. ");
        scanf("%d", &choice);
        switch (choice) {
            case 1 :
                user(actuelle);
                actuelle++;
                break;
            case 2 :
                printf("Enter YOUR CHOICE ");
                multi_user(actuelle);
                actuelle += accounts_num;
                break;
            case 3 :
                deposit();
                break;
            case 4 :
                withdrawal();
                break;
            case 5:
                getBalnce();
                break;
            case 6:
                TRI_Ascendant();
                break;
            case 7:
                TRI_Descendant();
                break;
            case 8:
                AllUsers();
                break;
            case 9:
                printf(" GOOD BYE! ");
                break;
            default:
                printf(" Sorry you cant access ");

        }
    } while (choice != 9);

    return 0;
}
