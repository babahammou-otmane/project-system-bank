#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"TP_bank.h" 
#include"date_vaid.h"
    //! those are all the functions that we did use in our project
// ###################################  the addition function and search featurs ############## 
/* 
Account* addb(Account* head,unsigned int id,int password ,char* name,unsigned short int day,unsigned short int month,unsigned short int year,char* ads,unsigned int phone_number,char s);
int count_size(Account* head);
Account* position(Account* head,unsigned int x);
int count_size_position(Account*head,Account*p);
int search(Account*head,unsigned int x);
int date_s(unsigned int day,unsigned int moth ,unsigned year);
///? ####################################  the function   dispaly ################################
void display_all_account(Account* head);
void display_account_active(Account* head);
void display_account_blocked(Account* head);
void display_account(Account* head);
///?#####################################   the function  detele ################################
Account* delete_head(Account* head);
Account* delete_mu(Account* head,unsigned int x);
Account* delete_fin(Account* head);
Account* delete_a(Account* head,unsigned int id);
///?######################################   the all menu in system #############################
void menu_show();
void menu_info();
void startup_menu(Account**head,account_operation**oper);
*/
//######################################
Menu_home(){
 printf("  \twelcome to our bank system  \n");
 printf("1 manager part. \n ");
 printf("2 client part. \n");
 printf("3 exit. \n");
}
int main(){
 unsigned short int s,sat= 0;
 Account* head= load_From_File();
 account_operation* oper= load_Operations_From_File();
 /*             //! this is the bank account   
 head= addb(head,1000,123000000000,2342,"BANK",9,5,2024,"ouagle",06474,'C');
        ///! some of our important customers     8)
 head= addb(head,'1100,1000000,1235,"google",9,5,2024,"USA",06433,'C');
 head= addb(head,1200,2300400,4533,"facebook",9,5,2024,"USA",06424,'C');
 */
    while(sat != 1){ 
     //!the main menu function 
     Menu_home();
     printf("enter your choice: "); scanf("%hu",&s);
        switch(s){  
        case 1: //? part manger 
         startup_menu(&head);
         sleep(3);
        break; 
        case 2 : //? part account 
         acount_t(&head,&oper);
         sleep(3);
        break;
        case 3 ://? exit
         save_To_File(head);
         save_Operations_To_File(oper);
         sleep(3); 
         exit(0);
        break;
        default://? if he enter any othe input we'll tell hem reenter he's choice 
         printf("enter a valid choice please. \n");
        break;       
        }
    }
 return 0;
}
