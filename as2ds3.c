#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct BankMgmt {
    int AccNumber;
    char CustName[50];
    float AvlBalance;
    char AccType[20];
};
//withydraw ka function
void withdraw(struct BankMgmt *account) {
    float amount;
    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);

    
    if (account->AvlBalance >= amount) {
        account->AvlBalance -= amount;
        printf("Withdrawal successful. New balance: %.2f\n", account->AvlBalance);
    } else {
        printf("Insufficient balance.\n");
    }
}
//deposit  ka function
void deposit(struct BankMgmt *account) {
    float amount;
    printf("Enter amount to deposit: ");
    scanf("%f", &amount);
    
    account->AvlBalance += amount;
    printf("Deposit successful. New balance: %.2f\n", account->AvlBalance);
}
//balance display karne ke liye
void displayBalance(struct BankMgmt *account) 
{
    printf("Account Number: %d\n", account->AccNumber);
    printf("Customer Name: %s\n", account->CustName);
    printf("Available Balance: %.2f\n", account->AvlBalance);
    printf("Account Type: %s\n", account->AccType);
}

int main() {
    struct BankMgmt account;
    int choice;
    
   
    account.AccNumber = 100155;
    strcpy(account.CustName, "VenkatKrishna");
    account.AvlBalance = 4500.00;
    strcpy(account.AccType, "Saving");

    do {
        printf("\nMenu:\n");
        printf("1. Withdrawal\n");
        printf("2. Deposit\n");
        printf("3. Display Balance\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                withdraw(&account);
                break;
            case 2:
                deposit(&account);
                break;
            case 3:
                displayBalance(&account);
                break;
            case 4:
                printf("Exiting the application.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);
    
return 0;
}
