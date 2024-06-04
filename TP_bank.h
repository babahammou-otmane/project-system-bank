//*###############  structs  ###############
typedef struct date{
  unsigned short int hour;
  unsigned short int day;
  unsigned short int month;
  unsigned short int year;
}date;
typedef struct client{
  //* the client inforamtions */
  unsigned int Id;
  char *Name;
  date date_of_birth;
  char* _Address_;
  unsigned int phone_number;
}client;
typedef struct Account{
  //* this is the client account */
  client _Id_;
  char account_type;
  float balance;
  int password; 
  unsigned short int block;
  struct Account* next;
}Account;
typedef struct account_operation{ 
  char* operation_date;
  // char action_type;
  unsigned int send_ID;
  unsigned int receive_ID;
  float sent_monery;
  struct account_operation *next;
}account_operation;

// ##########################################################################################
int count_size(Account* head){
  if(head == NULL )
   return 0;
  return 1+count_size(head->next);
}
Account* position(Account* head,unsigned int x){
  if(head == NULL)
   return NULL;
  if(head->_Id_.Id == x)
   return head;
  return position(head->next,x);
}
int count_size_position(Account* head,Account* p){
  int s= 1;
  while(head != p){
   s++;
   head= head->next;
  }
 return s;
}
int  search(Account* head,unsigned int x){
  if(head == NULL)
   return 0;
  if(head->_Id_.Id == x)
   return 1;
  return search(head->next,x);
}
//#############  delete  ##############
Account* delete_head(Account* head){
  Account* p= head;
  if(head != NULL){
   head= head->next;
   free(p);
  }
  return head;
}
Account* delete_fin(Account* head){
  Account* p;
  if(count_size(head) > 0){
    p= head;
   while(p->next->next != NULL)
    p= p->next;
    free(p->next);
  }
  return head;
}
Account* delete_mu(Account* head,unsigned int x){
  Account* p;
  Account* s;
  if(head != NULL){
    s= head;
    p= head;
    while(s->_Id_.Id != x)
     s= s->next;
     while(p->next != s)
       p= p->next;
       p->next = s->next;
       free(s);
  }
 return head;
}
Account* delete_a(Account* head,unsigned int id){
  if(search(head,id) == 1){
    if(count_size_position(head,position(head,id)) == 1 && count_size(head) == 1)
     free(head);
    if(count_size_position(head,position(head,id)) == count_size(head) && count_size(head) > 1)
     return delete_fin(head);
    if(count_size_position(head,position(head,id)) == 1 && count_size(head) > 1)
     return delete_head(head);
    if(count_size_position(head,position(head,id)) != 1 && count_size(head) > 1)
     return delete_mu(head,id);
  }
 return head;
}
// ############  modification  ###########


//################### all the system menu's ######################
void menu_show(){
 printf("  \tthe avelable acts of show\n");
 printf("1 show all system account's.\n");
 printf("2 show all active account's.\n");
 printf("3 show all blocked account's.\n");
 printf("4 show a specifique account.\n");
 printf("5 go back.\n");
}
void menu_info(){
  printf("  \twelcome\n");
  printf("1 add accont. \n");
  printf("2 delete accont. \n");
  printf("3 modtif accont. \n");
  printf("4 show account's. \n");
  printf("5 exit. \n");
}
void menu_modtif(){
  printf("  \tmodtiftion\n");
  printf("1 name modtifcation. \n");
  printf("2 address modetifcation. \n");
  printf("3 date of birth modification. \n");
  printf("4 phone number modification. \n");
  printf("5 stut modification. \n");
  printf("6 go back. \n");
}
void start(){
  printf("  \twelcome of page\n");
  printf("1 manger part. \n");
  printf("2 client part. \n");
}
/*##################################*/
  //! thats the function that creat and add the accounts -we shoose it to be and add by head function- 
Account* addb(Account* head,unsigned int id,float balance,int password,char* name,unsigned short int day,unsigned short int month,unsigned short int year,char* ads,unsigned int phone_number,char s){
  Account* new;
  new= (Account*)malloc(sizeof(Account));
  new->_Id_.Id= id;
  new->balance= balance;
  new->_Id_.Name= name;
  new->_Id_.date_of_birth.day= day;
  new->_Id_.date_of_birth.month= month;
  new->_Id_.date_of_birth.year= year;
  new->_Id_._Address_= ads;
  new->_Id_.phone_number= phone_number;
  new->password= password;
  new->account_type= s;
  new->block= 1;
  new->next= head;
  head= new;
  return head;
}
// #####################################  display ########################
void display_all_account(Account* head){

 printf(" here are all the system accounts: \n ");
 
  while(head != NULL){
   printf("------------------------------ \n");
   printf(" Id: %d\n name: %s\n date of birth: %hu/%hu/%hu\n",head->_Id_.Id,head->_Id_.Name,head->_Id_.date_of_birth.day,head->_Id_.date_of_birth.month,head->_Id_.date_of_birth.year);
   printf(" account type: %c\n",head->account_type);
   head= head->next; 
  }
 printf("----------------------------- \n");
 printf("finshed. \n");
}
void display_account(Account*head){
 printf(" display the searched account:\n");
 printf("------------------------------ \n");
 printf(" Id: %d\n name: %s\n date of birth: %hu/%hu/%hu\n",head->_Id_.Id,head->_Id_.Name,head->_Id_.date_of_birth.day,head->_Id_.date_of_birth.month,head->_Id_.date_of_birth.year);
 printf(" account type: %c\n",head->account_type);
 printf("------------------------------ \n");
}
void display_account_active(Account* head){
  char type_account;
  printf("enter the account type: "); scanf(" %c",&type_account);
  printf(" here are all the (%c) active account in the system: \n ",type_account);
  while(head != NULL){
    if( head->account_type == type_account && head->block ==1){
      printf("------------------------------ \n");
      printf(" Id: %d\n name: %s\n date of birth: %u/%u/%u\n",head->_Id_.Id,head->_Id_.Name,head->_Id_.date_of_birth.day,head->_Id_.date_of_birth.month,head->_Id_.date_of_birth.year);
      printf("balance: %f\n",head->balance);   
    }
   head= head->next;
  }
  printf("------------------------------ \n");
  printf("finshed. \n");
}
void display_account_blocked(Account* head){
  char type_account;
  printf("enter the account type: "); scanf("%c",&type_account);
  printf(" here are all th (%c) Blocked account in the system: \n ",type_account);
  while(head != NULL){
    if( head->account_type == type_account && head->block == 0){
     printf("------------------------------ \n");
     printf(" Id: %d \n name: %s \n date of birth: %u/%u/%u \n",head->_Id_.Id,head->_Id_.Name,head->_Id_.date_of_birth.day,head->_Id_.date_of_birth.month,head->_Id_.date_of_birth.year);
     printf("balance: %f \n",head->balance); 
    }
   head= head->next;
  }
  printf("------------------------------ \n");
  printf("finshed. \n");
}
//*#################### the part of save and load the account to and from a file ##################
Account* load_From_File(){
  //* opening a file if 
 FILE* file= fopen("accounts.dat","rb");
    if(file == NULL){
     printf("Error in opening file for read!! \n");
     return NULL;
    }
    Account* head= NULL;
    Account* tail= NULL;
    while(1){
     Account* newAccount= (Account*)malloc(sizeof(Account));
        if(newAccount == NULL){
         printf("error in the memory allocation!! \n");
         fclose(file);
         return NULL;
        }
        if(fread(&newAccount->_Id_.Id,sizeof(unsigned int),1,file) != 1){
         free(newAccount);
         break; 
        }
     unsigned int nameLength;
      fread(&nameLength,sizeof(unsigned int),1,file);
     newAccount->_Id_.Name= (char*)malloc(nameLength* sizeof(char));
      fread(newAccount->_Id_.Name,sizeof(char),nameLength,file);
      fread(&newAccount->_Id_.date_of_birth,sizeof(date),1,file);
     unsigned int addressLength;
      fread(&addressLength,sizeof(unsigned int),1,file);
     newAccount->_Id_._Address_= (char*)malloc(addressLength* sizeof(char));
      fread(newAccount->_Id_._Address_,sizeof(char),addressLength,file);
      fread(&newAccount->_Id_.phone_number,sizeof(unsigned int),1,file);
      fread(&newAccount->account_type,sizeof(char),1,file);
      fread(&newAccount->balance,sizeof(float),1,file);
      fread(&newAccount->password,sizeof(int),1,file);
      fread(&newAccount->block,sizeof(unsigned short int),1,file);
     newAccount->next= NULL;
        if (head == NULL) {
         head= newAccount;
         tail= newAccount;
        }
        else{
         tail->next= newAccount;
         tail= newAccount;
        }
    }
 fclose(file);
 return head;
}
void save_To_File(Account* head){
    FILE* file= fopen("accounts.dat","wb");
    if(file == NULL){
     printf("Error in opening file for writing!! \n");
     return;
    }
 Account* current= head;
    while(current != NULL){
      fwrite(&current->_Id_.Id,sizeof(unsigned int),1,file);
     unsigned int nameLength= strlen(current->_Id_.Name) + 1;
      fwrite(&nameLength,sizeof(unsigned int),1,file);
      fwrite(current->_Id_.Name,sizeof(char),nameLength,file);
      fwrite(&current->_Id_.date_of_birth,sizeof(date),1,file);
     unsigned int addressLength= strlen(current->_Id_._Address_) + 1;
      fwrite(&addressLength,sizeof(unsigned int),1,file);
      fwrite(current->_Id_._Address_,sizeof(char),addressLength,file);
      fwrite(&current->_Id_.phone_number,sizeof(unsigned int),1,file);
      fwrite(&current->account_type,sizeof(char),1,file);
      fwrite(&current->balance,sizeof(float),1,file);
      fwrite(&current->password,sizeof(int),1,file);
      fwrite(&current->block,sizeof(unsigned short int),1,file);

     current= current->next;
    }
 fclose(file);
 printf("The account is saved to the file successfully. \n");
}
account_operation* load_Operations_From_File(){
 FILE* file= fopen("operations.dat","rb");
    if (file == NULL) {
     printf(" Error in opening file for read!! \n");
     return NULL;
    }
 account_operation* head= NULL;
 account_operation* tail= NULL;
    while(1){
     account_operation* newOperation= (account_operation*)malloc(sizeof(account_operation));
        if(newOperation == NULL){
         printf("error in the memory allocation!! \n");
         fclose(file);
         return NULL;
        }
      unsigned int dateLength;
      fread(&dateLength,sizeof(unsigned int),1,file);
      newOperation->operation_date= (char*)malloc(dateLength* sizeof(char));
      fread(newOperation->operation_date,sizeof(char),dateLength,file);
      fread(&newOperation->send_ID,sizeof(unsigned int),1,file);
      fread(&newOperation->receive_ID,sizeof(unsigned int),1,file);
      fread(&newOperation->sent_monery,sizeof(float),1,file);
      newOperation->next= NULL;
        if(head == NULL){
         head= newOperation;
         tail= newOperation;
        } 
        else{
         tail->next= newOperation;
         tail= newOperation;
        }   
        if(feof(file)){
         break;
        }
    }
 fclose(file);
 return head;
}
void save_Operations_To_File(account_operation* head){
 FILE* file= fopen("operations.dat","wb");
    if(file == NULL){
     printf("Error in opening file for read!! \n");
     return;
    }
    account_operation* current= head;
    while(current != NULL){
      fwrite(current->operation_date,sizeof(char),strlen(current->operation_date) + 1,file);
      fwrite(&current->send_ID,sizeof(unsigned int),1,file);
      fwrite(&current->receive_ID,sizeof(unsigned int),1,file);
      fwrite(&current->sent_monery,sizeof(float),1,file);
     current= current->next;
    }
 fclose(file);
}
// #####################   account operation   #####################
void menu_info_clint(){
  //* this is the client's account operation menu 
  printf("  \taccount operations\n");
  printf("1 send to another account.\n");
  printf("2 send to you account. \n");
  printf("3 withdraw money form account. \n");
  printf("4 show your account operations. \n");
  printf("5 delete your account. \n");
  printf("6 go back to home page. \n");
  printf("7 exit. \n");
}
void display_operation_account(Account* accouts,account_operation**head){
  account_operation* p= *head;
  //*Account *accouts enter the position of this account 
  printf(" display account operations: \n");
  while(p != NULL){
   if(accouts->_Id_.Id == p->send_ID || accouts->_Id_.Id == p->receive_ID ){
     printf("------------------------------\n");
     printf(" sender: %u\n receiver: %u\n date: %s\n the sended amount: %f\n",p->send_ID,p->receive_ID,p->operation_date,p->sent_monery);
     printf("------------------------------\n");
    }
   p= p->next;
  }
  printf("that's it, not a lot? maybe you're broke 8). \n");
}
account_operation* new_opration(account_operation*oper,char date[10],unsigned int send_ID,unsigned int receive_ID,float solid){
  account_operation* new= NULL;
  //! if send_ID == 0 || receive_ID == 0 => means a one account operation 
  new= (account_operation*)malloc(sizeof(account_operation));
  new->send_ID= send_ID;
  new->receive_ID= receive_ID;
  new->operation_date= date;
  new->sent_monery= solid;
  new->next= oper;
  oper= new;
  return oper;
}
void acount_t(Account**head,account_operation**operations){
  Account* sender= NULL; 
  Account* insender= NULL; 
  int password;
  float solid,soild_ax;
  char date[10];
  unsigned int send_Id,Id_account,s; 
  printf("enter your ID: "); scanf("%u",&Id_account);
  printf("enter your password: "); scanf("%d",&password);
  sender= position(*head,Id_account);
  if(search(*head,Id_account) == 1 && sender->password == password){  
   unsigned short int bools= 0; 
    while(bools == 0){
      menu_info_clint();
      printf("enter your choice: "); scanf("%u",&s);
      switch(s){
      case 1:  //? trans 
       printf("enter the ID that you'll send to: "); scanf("%u",&send_Id);
       insender= position(*head,send_Id);
        if(search(*head,send_Id) != 1){
         printf("this ID is incorrect double check it please!! \n");
        }
        else{
         printf("enter how much you'll send: "); scanf("%f",&solid);
          if(sender->balance >= solid){
           printf("enter todays date: "); scanf("%s",&date);
           sender->balance= sender->balance - solid;
           insender->balance += solid;
           *operations= new_opration(*operations,date,Id_account,send_Id,solid);
           printf("done. \n");
          }
          else{
           printf(" we are sorry you can't sent an amount that you don't have!! \n");
          }
        }
      break;
      case 2: //? send to an account 
       printf("how much mony you want to send: "); scanf("%f",&soild_ax);
       printf("enter todays date: "); scanf("%s",&date);
       sender->balance= sender->balance + soild_ax;
       *operations= new_opration(*operations,date,sender->_Id_.Id,0,soild_ax);
       printf("dane.\n"); 
       sleep(3);
       system("clear");
      break;
      case 3: //  
       printf("how much mony : "); scanf("%f",&soild_ax);
        if(sender->balance < soild_ax){
         printf(" we are sorry you can't sent an amount that you don't have!!\n");
        }
        else{
         printf("enter todays date : "); scanf("%s",&date);      
         sender->balance= sender->balance - soild_ax ;
         *operations= new_opration(*operations,date,sender->_Id_.Id,0,soild_ax);
         printf("dane.\n"); 

        }
       sleep(3);
      break;
      case 4: //? show account actions 
       display_operation_account(sender,operations);
       sleep(3);
       system("clear");
      break;
      case 5: //? delete account 
       *head=  delete_a(*head,Id_account);
       printf("done the account is deleted.\n");
       bools= 1;
       sleep(3);
       system("clear");
      break;
      case 6: //? go back to home page 
       bools= 1;  
      break;
      case 7: //? exit 
       save_To_File(*head);
       save_Operations_To_File(*operations);
       exit(0);
      break;
       system("clear");
      }
    }
  
  }   
  else{
   printf("double check the ID and the password then try again please.\n");
  }  
 system("clear");
}

/*###############   part  start up     ###################*/
void startup_menu(Account**head){
  //* this is the home page of the system 
  system("clear");
  unsigned short int t_is,s,s_1,id_father,Id_motif,show_s;
  unsigned int id,tel,id_search;
  char name[30],ads[30];
  float balance;
  int password;
  char account_type;
  unsigned short int sd,day,month,year;
  Account* p= *head;   
  menu_info();   
  printf("choose an operation: "); scanf("%hu",&s);
  switch(s){
  case 1:  //? add account (creat a new one) 
   system("clear");
   printf("enter ID the client: "); scanf("%u",&id);
    if(search(*head,id) == 0){  //? seen if this ID is mentioned or it's not
     printf("\n enter your firt and last-name: \n"); scanf("%s",&name);
     printf("\n enter your address: "); scanf("%s",&ads);
     printf("\n enter your balance: "); scanf("%f",&balance);
     printf("\n enter your password: "); scanf("%d",&password);
     printf("\n enter your date_brith: "); scanf("%hu%hu%hu",&day,&month,&year);
      if(date_s(day,month,year) == 1){
       printf("\n enter your phone number: "); scanf("%u",&tel);
        if(2024-year <= 18){
         //? test if the input age is >= 18 if it's not we will search for the parent account to connect theme 
         printf("we can't created an account for you because your under age.\n");
         printf("but does your parent have an account in our bank?: \n1 yes. \n2 no. "); scanf("%hu",&s_1);
          if(s_1 == 1){
            printf(" well thats great enter your parent ID: "); scanf("%hu",&id_father);
            if(search(*head,id_father) == 1 ){ //? test if the parent account is mentioned or it's not 
             printf(" we find your parent accout so we'll creat an accout for you buddy. \n");
             account_type= 'M'; //? giving type account 
             *head= addb(*head,id,balance,password,name,day,month,year,ads,tel,account_type);
             printf("the creation of the (M) account is done successfully. \n");
             sleep(3);
            }
            else{  
             printf("sorry buddy but this account is not mentioned, we can't creat an account untill we have your parent account.\n");
             sleep(3);
            } 
          }
          else{
           printf("thank you for your time. \n");
           sleep(2);
          }
        }
        else{  //? if age <= 18 
         account_type= 'P';
         *head= addb(*head,id,balance,password,name,day,month,year,ads,tel,account_type);
         printf("the creation of the (P) account is done seccesfuly. \n");
         sleep(3);
        }
      } 
      else {  //? the input date faild in the test
       printf("the input date is not valid. \n");
       sleep(3);
      }
    }
    else {  
     printf("we can't creat an account becouse this ID is already in the system. \n");
     sleep(3);
    }
  break;
  case 2:  //?  delete an account
    system("clear");  
    unsigned int ids;
    printf("  \tdelete acconut\n");
    printf("for the delete of an account enter the ID of it: "); scanf("%u",&ids);
    if(search(*head,ids) == 1 && ids != 1000){  //? test if this account is mentioned in system 
     *head= delete_a(*head,ids); //? delete account
     printf("the accoutn is deleted.\n");
     sleep(3);
     system("clear");
    }
    else{  //? display this account is not mentioned in system 
     printf(" this account is not mentioned. \n");
     sleep(3);
     system("clear");
    }
  break;
  case 3:  //? account modification 
   system("clear");
   printf(" enter Id account will be moditftion: \n"); scanf("%hu",&Id_motif);
    if(search(*head,Id_motif) == 1 && Id_motif != 1000 ){
     menu_modtif();  //? show the modification menu 
      do{ 
       printf(" enter your choice: "); scanf("%hu",&sd);
       p= position(*head,Id_motif);  //?  p will take the position that contains this ID
        switch(sd){
        case 1:  //? name modification 
         printf("enter the new name: "); scanf("%s",&name);
         p->_Id_.Name= name;
         printf("dane. \n");
         sleep(3);
        break;
        case 2:  //? address modification 
         printf("enter the new address: "); scanf("%s",&ads);
         p->_Id_._Address_= ads;
         printf("dane. \n");
         sleep(3);
        break ;
        case 3:  //? date of bith modification
          unsigned short int count_v= 0; 
          do{
            printf("enter the new burth date: "); scanf("%hu%hu%hu",&day,&month,&year);
            if(count_v == 2){
             printf("you can't enter a date that makes you younger that must be a fault!! \n");
             startup_menu(head);
            }
           count_v++;
          }while(date_s(day,month,year) != 1); //? after scaning the date it'll test if age is < 18 
          if(2024-year >= 18){ //? done 
           p->_Id_.date_of_birth.day= day;
           p->_Id_.date_of_birth.month= month;
           p->_Id_.date_of_birth.year= year;
           printf("dane. \n");
           sleep(3);
          }
          else{  //? if age is < 18 we'll delete the account because of an unpropreat actions
           printf("you can't enter a date that makes you younger we'll delete this account because of some unpropreat actions.\n");
            *head= delete_a(*head,Id_motif);
            sleep(3);
          }
        break;
        case 4:  //? phone number modification
             printf("enter the new phone number: "); scanf("%u",&tel);
             p->_Id_.phone_number= tel;
             printf("dane. \n");
             sleep(3);
        break;
        case 5: //? actevate and bolck the account
          if(p->block == 1)
           p->block= 0;
          else 
           p->block= 1 ;
           printf("dane. \n");
           sleep(3);
        break;
        case 6:  //? go back to home page (startup)  
         sleep(3);
         //? startup_menu(head);
        break;
        default:  //? if client (user) entered an unvalid choice we'll tell hime te reenter a valid choice  
         printf("please reernter a valid choice! \n ");
         sleep(1);  
        break ;
        }
      }while(sd > 6);
    }
    else{  //?  if not find  account 
     printf("we didn't find this account double check the ID and retry!!\n");
     sleep(3);
    }
  break;
  case 4:  //? show account (search & display)
   system("clear");
    do{
     menu_show(); 
     printf("enter choose:\n"); scanf("%hu",&show_s);
     system("clear");
      switch(show_s){
      case 1:  //? dislpay all acounts 
       display_all_account(*head);
      break;
      case 2:  //? display all active acccunt  
       display_account_active(*head); 
      break; 
      case 3:  //? display all blocked account] 
       display_account_blocked(*head);
      break;
      case 4:  //? display a specifique account 
       printf("enter the account Id: "); scanf("%u",&id_search);
       system("clear");
        if(search(*head,id_search) == 1){  //? test if this account is mentioned in system 
         printf(" information Id is : \n"); 
         display_account(position(*head,id_search));  //? dispaly the account inforamtions   
        }
        else{
         printf("this account is not mentioned!!\n");
        }
      break;
      case 5:  //? go back to home page
       printf("we'll go back! \n");
       sleep(0);
      break;
      default:  //?  if client (user) entered an unvalid choice we'll tell hime te reenter a valid choice
       printf("please rernter a valid choice. \n ");
       sleep(1);
      break;
      }
    }while(show_s > 5);  
   sleep(5);
  break;
  case 5: //?  exit 
   save_To_File(*head);
   system("clear");
   printf("thank you for active with my . \n");
   exit(0);
   return;
  break;
  default:  //?  if client (user) entered an unvalid choice we'll tell hime te reenter a valide choice
   printf("please rernter a valid choice !.\n ");
   sleep(1);  
  break;
  }
 startup_menu(head);  //?  retry
}  
