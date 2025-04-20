#include "main.h"
#include "Display.h"
#include "PasswordChecker.h"



int main(char args[])
{

char choice = display();


    switch(choice)
    {
        case '1':
            printf("Hash a password");
            break;

        case '2':
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