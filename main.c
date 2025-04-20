#include "main.h"
#include "Display.h"
#include "PasswordChecker.h"
#include "Hash.h"



int main(char args[])
{

char choice = display();


    switch(choice)
    {
        case '1':
            char password[16];
            char* hashPass;
            printf("Enter your password to process the  hash (maximum length 16 and ASCII characters , no space)\n");
            scanf("%s",password);
            printf("ici");
            hashPass = hashing(password);
            printf("Your password is %s and his hash version is %s \n",password,hashPass);
            break;

        case '2':
            unsigned long hashFolder = hash_fichier_unique("/home/jules/C/Hash_Project/test.txt");
            unsigned long lastHashFolder;
            printf("Put the last hash recorded \n");
            scanf("%lu" , &lastHashFolder);
            printf("The signature of your folder is %lu \n" , hashFolder);

            if(hashFolder == lastHashFolder)
            {
                printf("The folder was not modified \n");
            }
            else 
            {
            printf("The folder was modified \n");
            }
            
            break;
        case '3':
            printf("Enter your password to process the checking (maximum length 16 and ASCII characters , no space)\n");
            char pass[16];
            scanf("%s",pass);
            printf("%s", pass);
            long double time = passwordTimeCalcul(pass);
            displayTimetoCrack(time);
            break;
        default:
            printf("Invalid entry , exit program \n");
            exit(-1);
    }

}