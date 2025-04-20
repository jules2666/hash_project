#include "PasswordChecker.h"



double passwordTimeCalcul(char* password)
{
    char special_chars[] = "!@#$%^&*()-_=+[]{}|;:',.<>?/`~\"\\\0";
    char lowercase[]     = "abcdefghijklmnopqrstuvwxyz";
    char uppercase[]     = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char digits[]        = "0123456789";
    int strengthScore = 0;

   
    if(containValue(password,lowercase) == 1)
    {
        
        strengthScore += 26;
    }
    printf("\n  Verification of lower case processed \n");
    if(containValue(password,uppercase) == 1)
    {
       
        strengthScore += 26;
    }
    printf("  Verification of upper case processed \n");
    if(containValue(password,digits) == 1)
    {
        strengthScore += 10;
    }
    printf("  Verification of digits processed \n");
    if(containValue(password,special_chars) == 1)
    {
     
        strengthScore += 31;
    }
    printf(" Verification of special_chars processed \n");

    printf("\nfinal strength score %d   \n" , strengthScore);
    
    int lengthPass = (int)strlen(password);
    double possibilites = pow(strengthScore,lengthPass);
    double speed = 1e9; 
    double time = possibilites /speed;


    printf("length strings %d \n" , lengthPass);
    printf("time to crack in seconds %lf  \n \n" , time);

    return time;
}

int containValue(char* password, char* dictionaries)
{
    char* Ppassword = password;
    char* Pdictionaries = dictionaries;

    while (*Ppassword != '\0')
    {
        if (*Pdictionaries == *Ppassword)
        {
            printf("\rMatch found: dict: %c | pass: %c ✅\n", *Pdictionaries, *Ppassword);
            return 1;
        }

        if (*Pdictionaries == '\0')
        {
            Pdictionaries = dictionaries;
            Ppassword++;
        }

        printf("\rChecking: dict: %c | pass: %c", *Pdictionaries, *Ppassword);
        fflush(stdout);        // Force output immediately
        usleep(1000);        // Wait 100ms for animation effect
        Pdictionaries++;
    }

    printf("\rNo match found.\n");
    return 0;
}

void displayTimetoCrack(double time)
{
    if(time < 50 )
    {
        printf("Your password take %f milliseconds to be crack (Instant) \n" , time*1000);
    }
    else if (time > 50 && time < 600)
    {
        printf("Your password take %f seconds to be crack (Very Weak)\n " , time);
    }
    else if( time > 600 && time < 36000)
    {
        printf("Your password take %f minutes to be crack (Weak)\n " , time/60);
    }
    else if  ( time > 36000 && time < 144000 )
    {
        printf("Your password take %f hours to be crack  (Weak) \n" , time/3600);
    }
    else if (time > 144000 && time < 21000000)
    {
        printf("Your password take %f days to be crack  (Medium) \n" , time/86400);
    }
    else  if ( time < 518400000)
    {
        printf("Your password take %f months to be crack  (Strong) \n" , time/2592000);
    }
    else  if (time < 6220800000)
    {
        printf("Your password take %f years  to be crack  (Very Strong) \n" , time/31104000);
    }
    else
    {
        printf("Your password take %f millenium to be crack  (Unbreakable with actual computer) \n" , time/31104000000);
    }




}