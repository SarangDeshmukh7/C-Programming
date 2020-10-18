#include <stdio.h>
#include <stdlib.h>

struct employee
{
    int id;
    char name[10];
    char address[20];
    int salary;
};

void findAge(int current_date, int current_month, int current_year, int past_date, int past_month, int past_year);
int isLeap(int y);
int offsetDays(int d, int m, int y);
void addDays(int d1, int m1, int y1, int x);


int main(void)
{
    struct employee e;
    struct dates
    {
        int date;
        int month;
        int year;
    }birth, join, curr, calc={};

    /*struct employee e = {1, "hrishi", "shirur", 100};
    struct date birth = {27, 3, 1998};
    struct date join = {27, 3, 2010};
    struct date curr = {27, 3, 2020};
    struct date calc = {};*/

    printf("Enter Employee ID:");
    scanf("%d", e.id);
    
    printf("Enter Employee Name:");
    scanf("%s", e.name);
    
    printf("Enter Employee Address:");
    scanf("%s", e.address);
    
    printf("Enter Employee Salary:");
    scanf("%d", e.salary);

    printf("Enter Birth Date (DD/MM/YYY):");
    scanf("%d/%d/%d", &birth.date, &birth.month, &birth.year);

    printf("Enter Joining Date (DD/MM/YYY):");
    scanf("%d/%d/%d", &join.date, &join.month, &join.year);

    printf("Enter Todays Date (DD/MM/YYY):");
    scanf("%d/%d/%d", &curr.date, &curr.month, &curr.year);

    printf("\nAge at time of joining: ");
    findAge(join.date, join.month, join.year, birth.date, birth.month, birth.year);
    
    printf("Experience: ");
    findAge(curr.date, curr.month, curr.year, join.date, join.month, join.year);

    int x = 90;
    addDays(join.date, join.month, join.year, x);

    return 0;
}

void findAge(int current_date, int current_month, int current_year, int past_date, int past_month, int past_year)
{

    int month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (past_date > current_date)
    {
        current_date = current_date + month[past_month - 1];
        current_month = current_month - 1;
    }

    if (past_month > current_month)
    {
        current_year = current_year - 1;
        current_month = current_month + 12;
    }

    int calculated_date = current_date - past_date;
    int calculated_month = current_month - past_month;
    int calculated_year = current_year - past_year;

    printf(" %d Years\n", calculated_year);
}

int isLeap(int y)
{
    if (y % 100 != 0 && y % 4 == 0 || y % 400 == 0)
        return 1;

    return 0;
}

int offsetDays(int d, int m, int y)
{
    int offset = d;

    switch (m - 1)
    {
    case 11:
        offset += 30;
    case 10:
        offset += 31;
    case 9:
        offset += 30;
    case 8:
        offset += 31;
    case 7:
        offset += 31;
    case 6:
        offset += 30;
    case 5:
        offset += 31;
    case 4:
        offset += 30;
    case 3:
        offset += 31;
    case 2:
        offset += 28;
    case 1:
        offset += 31;
    }

    if (isLeap(y) && m > 2)
        offset += 1;

    return offset;
}

void revoffsetDays(int offset, int y, int *d, int *m)
{
    int month[13] = {0, 31, 28, 31, 30, 31, 30,
                     31, 31, 30, 31, 30, 31};

    if (isLeap(y))
        month[2] = 29;

    int i;
    for (i = 1; i <= 12; i++)
    {
        if (offset <= month[i])
            break;
        offset = offset - month[i];
    }

    *d = offset;
    *m = i;
}

void addDays(int d1, int m1, int y1, int x)
{
    int offset1 = offsetDays(d1, m1, y1);
    int remDays = isLeap(y1) ? (366 - offset1) : (365 - offset1);

    int y2, offset2;
    if (x <= remDays)
    {
        y2 = y1;
        offset2 = offset1 + x;
    }

    else
    {
        x -= remDays;
        y2 = y1 + 1;
        int y2days = isLeap(y2) ? 366 : 365;
        while (x >= y2days)
        {
            x -= y2days;
            y2++;
            y2days = isLeap(y2) ? 366 : 365;
        }
        offset2 = x;
    }

    int m2, d2;
    revoffsetDays(offset2, y2, &d2, &m2);

    printf("Date when his probation period is over:", d2);
    printf("%d/", d2);
    printf("%d/", m2);
    printf("%d", y2);
}