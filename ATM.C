#include <stdio.h>
#include<string.h>
#define MAX_TRANSACTIONS 100
struct user
{
    int pass;
    int balance;
}a={5341,0};

struct Transaction {
    char type[20];
    int amount;
};
struct Transaction history[MAX_TRANSACTIONS];
int transactionCount = 0;
void deposit();
void withdrawal();
void balanceEnquiry();
void pinChange();
void transactionHistory();
int main() {
    while(1)
    {
        printf("\n        Welcome to ATM machine\n");
        printf("\n1.Deposit");
        printf("\n2.Withdrawal");
        printf("\n3.Balance Enquiry");
        printf("\n4.Transaction History");
        printf("\n5.Pin Change");
        printf("\n6.Exit\n");
        int ch;
        printf("\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:deposit();
                   break;
            case 2:withdrawal();
                   break;
            case 3:balanceEnquiry();
                   break;
            case 4:transactionHistory();
                   break;
            case 5:pinChange();
                   break;
            case 6:return 0;
            default:printf("\nInvalid choice");
        }
    }

    return 0;
}
void deposit()
{
    int pin,amount,z;
    z:printf("\nEnter your pin:");
    scanf("%d",&pin);
    if(pin==a.pass)
        printf("\nAuthentication successful\n");
    else{
        printf("\nIncorrect pin\n");
        goto z;
    }
    printf("\nEnter the amount:");
    scanf("%d",&amount);
    a.balance+=amount;
    if (transactionCount < MAX_TRANSACTIONS) {
         strcpy(history[transactionCount].type, "Deposit");
         history[transactionCount].amount = amount;
         transactionCount++;
    }
    printf("Deposit Successful\n");
    printf("\n\n\n\n\n");
}
void withdrawal()
{
    int pin,amount,z;
    z:printf("\nEnter your pin:");
    scanf("%d",&pin);
    if(pin==a.pass)
        printf("\nAuthentication successful\n");
    else{
        printf("\nIncorrect pin\n");
        goto z;  
    }      
    printf("\nEnter the amount:");
    scanf("%d",&amount);
    if(amount>a.balance)
        printf("\nInsufficient money");
    else{
        a.balance-=amount;
        if (transactionCount < MAX_TRANSACTIONS) {
        strcpy(history[transactionCount].type, "Withdrawal");
        history[transactionCount].amount = amount;
        transactionCount++;
    }
        printf("\nThe cash is out,take it");   
    }
    printf("\n\n\n\n\n");
}   
void balanceEnquiry()
{
    int pin,z;
    z:printf("\nEnter your pin:");
    scanf("%d",&pin);
    if(pin==a.pass)
        printf("\nAuthentication successful\n");
    else{
        printf("\nIncorrect pin\n");
        goto z;
    }        
    printf("\nYour balance is %d rupees",a.balance);
    printf("\n\n\n\n\n");
}
void transactionHistory() 
{
    printf("\nEnter your pin:");
    int pin;
    scanf("%d",&pin);
    
    if (pin !=a.pass) {
        printf("\nIncorrect pin\n");
        return;
    }
    printf("\nAuthentication successful\n");

    if (transactionCount==0) {
        printf("\nNo transactions yet.\n");
    } else {
        printf("\nTransaction History:\n");
        for (int i =0; i<transactionCount;i++) {
            printf("%d. %s: %d rupees\n", i + 1, history[i].type, history[i].amount);
        }
    }
    printf("\n");
}
void pinChange()
{
    int currPin,newPin,conPin,y,z;
    z:printf("\nEnter your current pin:");
    scanf("%d",&currPin);
    if(currPin==a.pass)
    {
        y:printf("\nEnter your new pin:");
        scanf("%d",&newPin);
        printf("\nConfirm your pin:");
        scanf("%d",&conPin);
        if(newPin==conPin){
            a.pass=newPin;
            printf("\nPin changed successfully\n");
        }
        else{
            printf("\nTry again\n");
            goto y;
        }  
    }
    else{
        printf("\nPin is incorrect\n");
        goto z;
    }
}
