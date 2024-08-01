#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include "month_struc.h"

int days (const struct month * fp, int index);
char *s_gets (char * st, int n);
void to_lower (const char * source, char * dest);

const char *  month_arr[] = {"january", "february", "march", "april", "may", "june", "july", "august", "september", "october", "november", "december"};

// A program that returns the total amount of days in the year (including the month)
int main (void)
{
    char input[LEN], temp[LEN];
    int month_num, result;

    printf("Please enter the name of the month [empty line to exit]:\n");
    while((s_gets(input, LEN)) != NULL && input[0] != '\0')
    {
        to_lower(input, temp);
        
        int index;
        for (index = 0; index < 12; index++)
        {
            month_num = strcmp(temp, month_arr[index]);
            
            if (month_num == 0)
                break;
        }

        if (month_num == 0)
        {
            result = days(year, index);
            printf("\nThere are %d days up until the month of %s\n", result, month_arr[index]);
        }

        else
        {
            printf("\nMonth not found.\n");
        }
        
        printf("Please enter the name of the month [empty line to exit]:\n");
    }    

    return 0;
}

int days (const struct month * fp, int index)
{
    int total = 0;

    if (index < 0 || index > 12)
        total = -1;

    else
    {
        int count = 0;

        while (count <= index)
        {
            total += fp[count].days;
            count++;
        }
    }
    
    return total;
}

char *s_gets (char * st, int n)
{
    char * ret_val;
    int i = 0;

    ret_val = fgets (st, n, stdin);
    
    if (ret_val)
    {
        while (st[i] != '\n' && st[i] != '\0')
            i++;

        if (st[i] == '\n')
            st[i] = '\0';

        else
            while (getchar() != '\n')
                continue;
    }

    return ret_val;
}

void to_lower (const char * source, char * dest)
{
    int length = strlen(source);

    for (int i = 0; i <= length; i++)
    {
        dest[i] = tolower(source[i]);
    }
}
