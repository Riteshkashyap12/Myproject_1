#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct contact
    {
        char first_name[30];
        char last_name[30];
        char phone_no1[12];
        char phone_no2[12];
        char whatsapp_no[12];
        char email_id[40];
        char date_of_birth[15];


    };

    void menu();
    void add_info();
    void list_info();
    void search_info();
    void update_info();
    void delete_info();

    int main()
    {
        menu();
        return 0;
    }
    void menu()                                             // MENU
    {
        int choice;
        system("cls");
        printf("\t*************WELCOME TO PHONE-BOOK************");
        printf("\n\n\t**MAIN MENU**");
        printf("\n\n\t1. ADD CONTACT");
        printf("\n\t2. LIST CONTACT");
        printf("\n\t3. SEARCH CONTACT");
        printf("\n\t4. MODIFY CONTACT");
        printf("\n\t5. DELETE CONTACT");
        printf("\n\t6. EXIT");
        printf("\n\tEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                add_info();
                break;
            case 2:
                list_info();
                break;
            case 3:
                search_info();
                break;
            case 4:
                update_info();
                break;
            case 5:
                delete_info();
                break;
            case 6:
                exit(0);
                break;
            default :
                printf("\n\tInvalid choice. Please try again.");
                printf("\n\t");
                system("pause");

                menu();
        }

    }
    void add_info()                                         // ADD CONTACT
    {
        FILE*files;
        struct contact c1;
        system("cls");

        files=fopen("contact","ab+");
        printf("\tTO ADD NEW RECORD :\n\n");
        printf("\tEnter first Name : ");
        fflush(stdin);
        gets(c1.first_name);
        printf("\tEnter last Name : ");
        fflush(stdin);
        gets(c1.last_name);
        printf("\tEnter phone NO-1 : ");
        scanf("%d",&c1.phone_no1);
        fflush(stdin);
        printf("\tEnter phone NO-2( Optional) : ");
        fflush(stdin);
        gets(c1.phone_no2);
        if(strcmp(c1.phone_no2,"")==0);
             strcmp(c1.phone_no2,"Nil");
        
        printf("\tEnter WhatsApp No (optional):");
        gets(c1.whatsapp_no);
        if(strcmp(c1.whatsapp_no,"")==0);
              strcmp(c1.whatsapp_no,"Nil");
        
         printf("\tEnter E-mail ID: ");
         gets(c1.email_id);
         printf("\tEnter Date-of-Birth(Optional) :");
         gets(c1.date_of_birth);
         if(strcmp(c1.date_of_birth,"")==0);
           strcmp(c1.date_of_birth,"Nil");
        fwrite(&c1,sizeof(c1),1,files);

        fflush(stdin);

        printf("\n\tRECORD ADDED SUCCESSFULLY");
        fclose(files);
        printf("\n\t");
        system("pause");
        system("cls");
        menu();
           


    }
    void list_info()                                       // LIST CONTACT
    {
        int n=1;
        struct contact c1;
        FILE*files;
        files=fopen("contact","rb");
        if(files==NULL)
         {
            printf("\n\tFile opening error.");
            exit(0);
         }
        while(fread(&c1,sizeof(c1),1,files)==1)
         {
            system("cls");
            printf("\n\tCONTACT-%d INFORMATION :\n",n++);
            printf("\n\tFirst Name : %s",c1.first_name);
            printf("\n\tLast Name : %s",c1.last_name);
            printf("\n\tPhone NO-1 : %d",c1.phone_no1);
            printf("\n\tPhone NO-2 : %d",c1.phone_no2);
            printf("\n\tWhatsApp No : %s",c1.whatsapp_no);
            printf("\n\tE-mail ID : %s",c1.email_id);
            printf("\n\tDate of Birth : %s",c1.date_of_birth);
            printf("\n\tNext contact====>\n\t");
            system("pause");
         }
        fclose(files);

        system("cls");
        printf("\n\tEnd contacts.");
        printf("\n\t");
        system("pause");
        system("cls");
        menu();


    }
    void search_info()                                   // SEARCH CONTACT
    {
        struct contact c1;
        FILE*files;
        char name[35];
        int found=0;
        files=fopen("contact","rb");
        if(files==NULL)
        {
            printf("\n\tFile opening error.");
            exit(1);
        }
        system("cls");
        printf("\n\t TO SEARCH RECORD :\n");
        fflush(stdin);
        printf("\n\tEnter the first name of person : ");
        gets(name);
        while(fread(&c1,sizeof(c1),1,files)==1)
        {
            if(strcmp(c1.first_name,name)==0)
            {
                printf("\tCONTACT INFORMATION :\n");
                printf("\n\tFirst Name : %s",c1.first_name);
                printf("\n\tLast name : %s",c1.last_name);
                printf("\n\tPhone n0-1 :%s",c1.phone_no1);
                printf("\n\tPhone n0-2 :%s",c1.phone_no2);
                printf("\n\t Email id :%s",c1.email_id);
                printf("\n\tDate of birth :%s",c1.date_of_birth);

                found=1;
            }
        }
        if(found==0)
             printf("\n\tRecord not found.");
             fclose(files);
             system("pouse");
             system("cls");
             menu();



    }
    void update_info()                                  // UPDATE CONTACT
    {
        int pos=0;
        FILE*files;
        int found=0;
        struct contact c1,c2;
        char name[35];
        files=fopen("contact","rb+");
        if(files==NULL)
         {
            printf("\n\tCONTACT DATA NOT ADDED YET.");
            exit(1);
         }
        else
        {
            system("cls");
            printf("\n\t TO UPDATE RECORD :\n");
            fflush(stdin);
            printf("\n\tEnter the first name of person : ");
            gets(name);
            while(fread(&c1,sizeof(c1),1,files)==1)
            {
                if(strcmp(c1.first_name,name)==0)
                {
                    printf("\n\tEnter first name :");
                    gets(c2.first_name);
                    printf("\n\tEnter last name :");
                    gets(c2.last_name);
                    printf("\n\tEnter phone no-1 :");
                    gets(c2.phone_no1);
                    printf("\n\tEnter phone no-2(Optional) :");
                    gets(c2.phone_no2);
                        if(strcmp(c2.phone_no2,"")==0)
                        strcpy(c2.phone_no2,"Nil");
                    printf("\n\tEnter whatsapp number :");
                    gets(c2.whatsapp_no);
                      if(strcmp(c2.whatsapp_no,"")==0)
                         strcpy(c2.whatsapp_no,"Nil");
                    printf("\n\tEnter email id :");
                    gets(c2.email_id);
                    printf("\n\tDate of birth :");
                    gets(c2.date_of_birth);
                    if(strcmp(c2.date_of_birth,"")==0)
                      strcpy(c2.date_of_birth,"Nil");
                    fseek(files,pos,0);
                    fwrite(&c2,sizeof(c2),1,files);
                    found=1;
                    break;
                }
                pos=ftell(files);
                fflush(stdin);
            }
                if(found==1)
                {
                    printf("\n\tRECORD ADDED SUCESSFULLY.");
                }
                else{
                    printf("\n\tData not found.");
                }
                fclose(files);
        }
            printf("\n\t");
            system("pause");
            system("cls");
            menu();
                  
    }
    void delete_info()                                  // DELETE CONTACT
    {
        struct contact c1;
        FILE*files,*files_temp;
        int found;
        char name[35];
        files=fopen("contact","rb");
        if(files==NULL)
        {
            printf("\n\tCONTACT DATA NOT FOND YET.");
        }
        else
        {
            files_temp=fopen("temp","wb+");
            if(files_temp==NULL)
                printf("\n\tFILE OPENING ERROR");   
            else
            {
                system("cls");
                printf("\tTO DELETE CONTAT :\n");
                fflush(stdin);
                printf("\n\tEnter first name :");
                gets(name);
                fflush(stdin);
                while(fread(&c1,sizeof(c1),1,files)==1)
                 {
                    if(strcmp(c1.first_name,name)!=0)
                      fwrite(&c1,sizeof(c1),1,files_temp);
                    if(strcmp(c1.first_name,name)==0)
                      found==1;
                 }
                 fclose(files);
                 fclose(files_temp);
                 if(found!=1)
                  {
                    printf("\n\tRECORD NOT FOUND TO DELETE.");
                    remove("temp");
                  }
                else{
                    remove("contact");
                    rename("temp","contact");
                    printf("\n\tRECORD DELETED SUCCESSFULLY.");
                }
            }
        }
        printf("\n\t");
        system("pouse");
        system("cls");
        menu();

    }


