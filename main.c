#include <stdio.h>
#include <stdlib.h>


int dayFlag,febDay=28,nextMonthDay;
FILE *fp;

void printSpace(int monthday , int *setD)
{
    int i;
    for(i=1 ; i< monthday ; i++)
       {
            printf("    ");
            fprintf(fp,"    ");
           ++(*setD);
       }
}

int firstDayOfYear(int year)
{
    int x= (((year-1)*365+(year-1)/4-(year-1)/100+(year-1)/400)+1)%7;
    if (x==0)
        return 7;
    return x;
}

int ifleapyear(int year)
{
    return (((year % 4 == 0) && (year % 100 != 0)) ||
             (year % 400 == 0)); // 0 for normal and 1 for a leap year
}


void print4months(int firstDayOfMonth, int callcount)
{
    int j=1,c,d,k,l;
    int month1date=1,month2date=1,month3date=1,month4date=1;
    int month1end,month2end, month3end,month4end;
    int month1day,month2day,month3day,month4day;
    month1day = firstDayOfMonth;
    switch(callcount)  //finding 4 months parameter
    {
    case 1:
        month1end = 31;
        month2end = febDay;
        month3end = 31;
        month4end = 30;



        break;
    case 2:
        month1end = 31;
        month2end = 30;
        month3end = 31;
        month4end = 31;


        break;
    case 3:
        month1end = 30;
        month2end = 31;
        month3end = 30;
        month4end = 31;


        break;

    }
    month2day = ((month1end)%7+ month1day)%7;
        if(month2day==0)
            month2day =7;
        month3day = ((month2end)%7+ month2day)%7;

        if(month3day==0)
            month3day =7;
        month4day = ((month3end)%7+ month3day)%7;

        if(month4day==0)
            month4day =7;
        nextMonthDay = ((month4end)%7+ month4day)%7;

        if(nextMonthDay==0)
            nextMonthDay=7;

    while(j<7)// for 5 lines
    {k=0;
        for(c=1;c<5;c++) // for 4 months
        {l=1;
            for(d=0 ; d< 7 ; d++)
            {
                if (j ==1&&l==1)           //to print space when month begins
                { l--;

                    switch(c)
                    {
                    case 1: printSpace(month1day,&d); break;
                    case 2: printSpace(month2day,&d); break;
                    case 3: printSpace(month3day,&d); break;
                    case 4: printSpace(month4day,&d); break;

                    }
                }

                switch(c)           //starting to print date
                {
                case 1:
                    if(month1date<=month1end)
                    {
                        printf("%4d", month1date);
                        fprintf(fp,"%4d", month1date);
                        ++month1date;
                    }
                    else
                    {
                        printf("    ");
                        fprintf(fp,"    ");
                    }
                    break;
                case 2:
                    if(month2date<=month2end)
                    {
                        printf("%4d", month2date);
                        fprintf(fp,"%4d", month2date);
                        ++month2date;
                    }
                    else
                    {
                        printf("    ");
                        fprintf(fp,"    ");
                    }
                    break;
                case 3:
                    if(month3date<=month3end)
                    {
                        printf("%4d", month3date);
                        fprintf(fp,"%4d", month3date);
                        ++month3date;
                    }
                    else
                    {
                        printf("    ");
                        fprintf(fp,"    ");
                    }
                    break;
                case 4:
                    if(month4date<=month4end)
                    {
                        printf("%4d", month4date);
                        fprintf(fp,"%4d", month4date);
                        ++month4date;
                    }
                    else
                    {
                        printf("    ");
                        fprintf(fp,"    ");
                    }
                    break;

                }

            }

            if(k<3)
             {
                printf("\t\t    ");
                fprintf(fp,"\t\t    ");
                ++k;
             }

        }


        printf("\n");
        fprintf(fp,"\n");

        ++j;
    }




}

int main()
{
    fp= fopen("calenderRecords.txt","a");
    int i,j,year;
    printf("Enter a year (1950 - 2100):\n");
    fprintf(fp,"Enter a year (1950 - 2100):\n");
    scanf("%d",&year);
    fprintf(fp,"%d\n",year);
    dayFlag=firstDayOfYear(year);
    if(ifleapyear(year))
    {
        ++febDay;
    }
    printf("\t\t\t        \t\t\t\t\t\tYEAR:%d\n", year);
    fprintf(fp,"\t\t\t        \t\t\t\t\t\tYEAR:%d\n", year);
    for(i=0;i<3;i++)
    {
        switch(i) // writes month tag
        {
            case 0: printf("            JANUARY                                     FEBRUARY                                         MARCH                                          APRIL          \n");
                    fprintf(fp,"            JANUARY                                     FEBRUARY                                         MARCH                                          APRIL          \n");
                    break;
            case 1: printf("              MAY                                         JUNE                                            JULY                                         AUGUST          \n");
                    fprintf(fp,"              MAY                                         JUNE                                            JULY                                         AUGUST          \n");
                    break;
            case 2: printf("           SEPTEMBER                                    OCTOBER                                         NOVEMBER                                      DECEMBER         \n");
                    fprintf(fp,"           SEPTEMBER                                    OCTOBER                                         NOVEMBER                                      DECEMBER         \n");
                    break;
        }

        for(j=0;j<3;j++)
        {
            printf("   M   T   W   T   F   S   S\t\t    ");         //for first 3 month in a line
            fprintf(fp,"   M   T   W   T   F   S   S\t\t    ");         //for first 3 month in a line
        }
        printf("   M   T   W   T   F   S   S\n" );
        fprintf(fp,"   M   T   W   T   F   S   S\n" );


        /*
        Writing the Days
        */
         switch(i) // writes month tag
        {
            case 0: print4months(dayFlag,1);
                    printf("\n");
                    fprintf(fp,"\n");
                    break;
            case 1: print4months(nextMonthDay,2);
                    printf("\n");
                    fprintf(fp,"\n");
                    break;
            case 2: print4months(nextMonthDay,3);
                    printf("\n");
                    fprintf(fp,"\n");
                    break;
        }
    }
    fclose(fp);

    return 0;
}


