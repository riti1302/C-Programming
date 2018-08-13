#include<stdio.h>
#include<string.h>
int main()
{
    char* string = (char *)malloc(512000 * sizeof(char));
    int n, k, i=0, x, y;
    printf("Enter the length of the string:- ");
    scanf("%d", &n);
    printf("Enter the string:- ");
    scanf("%s", string);
    printf("Enter the number of letters to rotate the alphabet by:- ");
    scanf("%d", &k);
    printf("The string is: %s", string);

    while(i<n)
    {
        if((string[i]>=65 && string[i]<=90)  ||  (string[i]>=97 && string[i]<=122))
        {
            if(string[i]+k > 90 && string[i]<=90)
            {
               x= k- (90- string[i]);
               if(x %26 == 0)
                string[i]= 90;
               else
               string[i]= 64+ (x% 26);
            }
            else if(string[i]+k > 122 && string[i]<=122)
            {
               y= k- (122- string[i]);
               if(y %26 == 0)
                string[i]= 122;
               else
               string[i]= 96+ (y% 26);
            }

           else
           string[i]+=k;
        }
        i++;
    }
     printf("\nThe ciphered text is: %s\n",string);
     return 0;
}
