#include "Display.h"

char display()
{
char choice;   

    printf("\033[2J\033[H"); 
    

    printf("\033[1;32m");  
    printf("=================================================================================================================\n");
    printf("                                          WELCOME TO HASH PROJECT                                                \n");
    printf("=================================================================================================================\n");
    printf("\033[0m ");
    

    
    printf("\033[1;32m"); 
    printf("\t \t __ __  ____  _______ __      ____  ____   ___   ____   ___    __ ______ \n");
    printf("\t \t|  |  |/    |/ ___|  |  |    |    \\|    \\ /   \\ |    | /  _]  /  |      |\n");
    printf("\t \t|  |  |  o  (   \\_|  |  |    |  o  |  D  |     ||__  |/  [_  /  /|      |\n");
    printf("\t \t|  _  |     |\\__  |  _  |    |   _/|    /|  O  |__|  |    _]/  / |_|  |_|\n");
    printf("\t \t|  |  |  _  |/  \\ |  |  |    |  |  |    \\|     /  |  |   [_/   \\_  |  |  \n");
    printf("\t \t|  |  |  |  |\\    |  |  |    |  |  |  .  |     \\  `  |     \\     | |  |  \n");
    printf("\t \t|__|__|__|__| \\___|__|__|    |__|  |__|\\_|\\___/ \\____|_____|\\____| |__|  \n");
    printf("\033[0m \n \n \n \n "); 

    printf("\033[1;32m"); 
    printf(" \t\t\t\t Menu:\n \n \n \n");
    printf("1. Hash a password\n\n");
    printf("2. Integrity Tester\n\n");
    printf("3. Password Checker\n\n");
    printf("\033[0m \n \n");
    
    printf("\nEnter your choice: ");
    
    scanf("%c",&choice); // get the entry of the user
    
    
    return choice;
}

