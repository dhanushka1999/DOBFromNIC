#include <stdio.h>

#define MAX_NIC_LENGTH 12
#define OLD_NIC 2
#define NEW_NIC 4


int getLength(char char_array[]);
int getYear(char char_array[], int count);
int getIntFromChar(char c);
int getDays(char char_array[], int start);
int getSex(int days);
int * getMonthAndDay(int day);
void display(char char_array[], int year, int month, int day, int sex);

int main()
{
    char nic[MAX_NIC_LENGTH];
    int sex, year, month, day, l_nic;
    int *date_and_month;

    printf("\nEnter Your NIC No: ");
    scanf("%s", &nic);

    l_nic = getLength(nic);

    if ( l_nic== 9 || l_nic == 12)
    {
        if (l_nic == 9)
        {
            year = getYear(nic, OLD_NIC);
            day = getDays(nic, OLD_NIC);    
        }
        else
        {
            year = getYear(nic, NEW_NIC);
            day = getDays(nic, NEW_NIC);
        }

        sex = getSex(day);
        if (day > 500)
        {
            day -= 500;
        }

        if (day < 367 && day > 0)
        {
            date_and_month = getMonthAndDay(day);

            month = date_and_month[0];
            day = date_and_month[1];   

            display(nic, year, month, day, sex);         
        }
        else
        {
            printf("Invalid NIC!\n");
        }
    }
    else
    {
        printf("Invalid NIC!\n");
    }
    
    return 0;
}

int getLength(char char_array[])
{
    int count;
    for (count = 0; count < MAX_NIC_LENGTH; count++)
    {
        if (char_array[count] == '\0')
        {
            break;
        }  
    }

    return count;
}

int getIntFromChar(char c)
{
    return (int) (c - '0');
}

int getYear(char char_array[], int type)
{
    int year = 0;
    if (type == OLD_NIC)
    {
        year = getIntFromChar(char_array[0]) * 10 + getIntFromChar(char_array[1]) + 1900;
    }
    
    else
    {
        year = getIntFromChar(char_array[0]) * 1000 + getIntFromChar(char_array[1]) * 100 + getIntFromChar(char_array[2]) * 10 + getIntFromChar(char_array[3]);
    }

    return year;    
}

int getSex(int days)
{
    if (days < 500)
    {
        return 1;
    }

    return 0;    
}

int getDays(char char_array[], int start)
{
    int x = getIntFromChar(char_array[start]) * 100 + getIntFromChar(char_array[start + 1]) * 10 + getIntFromChar(char_array[start + 2]);

    return x;
}

int * getMonthAndDay(int day)
{
    static int result[2];
    int month;
    if (day > 335)
    {
        month = 11;
        day = day - 335;
    }
    else if (day > 305)
    {
        month = 10;
        day = day - 305;
    }
    else if (day > 274)
    {
        month = 9;
        day = day - 274;
    }
    else if (day > 244)
    {
        month = 8;
        day = day - 244;
    }
    else if (day > 213)
    {
        month = 7;
        day = day - 213;
    }
    else if (day > 182)
    {
        month = 6;
        day = day - 182;
    }
    else if (day > 152)
    {
        month = 5;
        day = day - 152;
    }
    else if (day > 121)
    {
        month = 4;
        day = day - 121;
    }
    else if (day > 91)
    {
        month = 3;
        day = day - 91;
    }
    else if (day > 60)
    {
        month = 2;
        day = day - 60;
    }
    else if (day > 31)
    {
        month = 1;
        day = day - 31;
    }
    else
    {
        month = 0;
    }
    result[0] = month;
    result[1] = day;
    return result;    
}

void display(char nic[], int year, int month, int day, int sex)
{
    char months[12][10] = {
        {"January"},
        {"February"},
        {"March"},
        {"April"},
        {"May"},
        {"June"},
        {"July"},
        {"August"},
        {"September"},
        {"October"},
        {"November"},
        {"December"}
    };

    char sexs[2][6] = {
        {"Female"},
        {"Male"}
    };

    printf("\nNIC: %s\nYour birthday is %d %s %d.\nAnd you are %s.\n", nic, year, months[month], day, sexs[sex]);
    
}
