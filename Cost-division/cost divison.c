#include<stdio.h>
#include<windows.h>
#include<stdlib.h>


void ClearConsoleToColors(int ForgC, int BackC)
{
     WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
     //This is used to get the handle to current output buffer.

     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     //This is used to reset the carat/cursor to the top left.

     COORD coord = {0, 0};
                      //This is a return value indicating how many characterss were written
                        //   It is not used but we need to capture this since it will be
                          //   written anyway (passing NULL causes an access violation).

     DWORD count;

                                   //This is a structure containing all the console info
                          // It is used here to find the size of the console.

     CONSOLE_SCREEN_BUFFER_INFO csbi;
                     //Now the current color will be set by this handle

     SetConsoleTextAttribute(hStdOut, wColor);

     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
                              //This fills the buffer with a given character (in this case 32=space).
          FillConsoleOutputCharacter(hStdOut, (TCHAR) 32, csbi.dwSize.X * csbi.dwSize.Y, coord, &count);

          FillConsoleOutputAttribute(hStdOut, csbi.wAttributes, csbi.dwSize.X * csbi.dwSize.Y, coord, &count );
                              //This will set our cursor position for the next print statement
          SetConsoleCursorPosition(hStdOut, coord);
     }
     return;
}


int welcome()
{
    int i, j;
    char box[60][80];
    char *W="WELCOME  TO  THE  COST  SPLITTER";
    printf("\n\n\n\n\n");
    for(i=0; i<10; i++)
    {
        for(j=0; j<90; j++)
        {
           if(i==0 || j==0 || i==9 || j==79 || j==1 || j==78)
            box[i][j]= 219;

            else
             box[i][j]= 32;
        }
    }
    for(j=20; j<53; j++)
    {
        i=5;
        box[i][j]= *W;
        W++;
    }



    for(i=0; i<10; i++)
        {
            printf("\t\t");
            for(j=0; j<80; j++)
            {
                printf("%c", box[i][j]);
            }
            printf("\n");
        }

    printf("\n");
    system("pause");
    return 0;
}

void clear()
{
    system("cls");
}




int calculation(int n, int m, int ID[], float amount[])
{
    clear();
    int i, j, k=0, b[50]={0}, t, flag=0;
    float  c[50]={0}, equal_, sum=0;
    for(i=0; i<n-1; i++)
    {
        for(j=0; j<k; j++)
        {
            for(t=0; t<n-i; t++)
            if(ID[i] == b[j])
              i++;
        }
        for(j=i+1; j<n; j++)
            if(ID[i] == ID[j])
                amount[i]+=amount[j];
        b[k]= ID[i];
        c[k]= amount[i];
        k++;
    }
    for(i=0; i<m; i++)
        if(ID[n-1]== b[i])
            flag=1;

        if(flag==0)
        {
            b[k]= ID[n-1];
            c[k]= amount[n-1];
        }


    for(i=0; i<m; i++)
    {
        sum+= c[i];
    }
    equal_= sum/m;

    printf("\n");
    for(i=0; i<120; i++)
        printf("%c", 219);
        printf("\n\n\n");

    printf("\t\t\t\t\t\tBILLING");
    printf("\n\n");
     for(i=0; i<120; i++)
        printf("*");
        printf("\n\n");

    printf("\t\tPerson ID\tTotal amount\n");
     for(i=0; i<m; i++)
    {
        printf("\t\t%d\t\t%f\n", b[i], c[i]);
    }

    printf("\n\n");
     for(i=0; i<120; i++)
        printf("*");

    for(i=0; i<m; i++)
    {
        if(c[i] > equal_)
        {
          c[i]= c[i]- equal_;
          printf("\n\n\t\t\t%d  will  Recieve  %f", b[i], c[i]);
        }

        else
        {
             c[i]= equal_ - c[i];
             printf("\n\n\t\t\t%d  will  Pay  %f", b[i], c[i]);
        }
    }
     printf("\n\n");
    for(i=0; i<120; i++)
        printf("%c", 219);
        printf("\n\n");

}




int main()
{
    ClearConsoleToColors(9,15);
    welcome();
    clear();
    int n, m, i, j, l, count, b[50]={0}, t=0, k, flag=0;
    float amount[50];
    int ID[50];

    for(i=0; i<120; i++)
    printf("-");
    printf("\n\n");
    ClearConsoleToColors(0,14);
    printf("\n\t\tNumber of transactions:-  ");
    scanf("%d", &n);
    while(n<=0)
    {
        printf("\n\t\tNumber of transactions should be greater than zero!\n\t\t\tEnter again\n\n");
        printf("\t\tNumber of transactions:- ");
        scanf("%d", &n);
    }
    printf("\n\t\tNumber of persons :- ");
    scanf("%d", &m);
    while(m<=0)
    {
        printf("\n\t\tNumber of person should be greater than one!\n\t\t\tEnter again\n\n");
        printf("\t\tNumber of persons :- ");
        scanf("%d", &m);
    }

     printf("\n\n");
     for(i=0; i<120; i++)
        printf("-");
        printf("\n\n");

        printf("\n\t\t\tNOTE: Person ID should not be zero\n\n");
        printf("\t\tPerson's ID:- ");
        scanf("%d", &ID[0]);
        printf("\t\tAmount paid:- ");
        scanf("%f", &amount[0]);
        printf("\n");

    t=1;
    b[0]= ID[0];
    for(i=1; i<n; i++)
    {
        count=0;
        printf("\t\tPerson's ID:- ");
        scanf("%d", &ID[i]);
        for(j=0; j<t; j++)
        {
          if(ID[i] != b[j])
            count++;
        }
        while(count>=m)
        {
            printf("\t\t\tERROR: Invalid person ID!  Number of persons exceed\n\n");
            printf("\t\tPerson's ID:- ");
            scanf("%d", &ID[i]);
            count=0;
            for(j=0; j<t; j++)
           {
              if(ID[i] != b[j])
                count++;
           }
        }
        printf("\t\tAmount paid:- ");
        scanf("%f", &amount[i]);
        printf("\n");

         for(k=0; k<t; k++)
        {
            if(ID[i] == b[k])
                flag=1;
        }

        if(flag==0)
        {
            b[t]= ID[i];
            t++;
        }
    }
    for(i=0; i<120; i++)
        printf("-");
        printf("\n\n");

    system("pause");
    ClearConsoleToColors(0,15);
    calculation(n, m, ID, amount);
    return 0;
}
