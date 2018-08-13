#include<stdio.h>
#include<string.h>
int main()
{
    char s[1000];
    int i, j;
    printf("Enter the string: ");
    scanf("%s", s);

    int l= strlen(s);

    for(i=0; i<l; i++)
    {
      if(s[i]== s[i+1])
      {
          j=i;
          while(j < l)
         {
             s[j+1]= s[j+2];
             j++;
         }

          l--;;
      }
      else
      {
          i++;
      }
    }
    if(l > 0)
        printf("The string is: %s\n", s);

    else
        printf("Empty String");

    return 0;
}
