#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef enum MENU
{
    EXIT = 0,
    DISP,
    ADD,
    DEL,
    MAX,
    MIN,
    SUM
} menuchoice;

int menu();
int add_number(int *);
void delete_number(int *);
void max_number(int *);
void min_number(int *);
void sum_numbers_in_array(int *);
void display_available_indexes(int *);

int main()
{
    int arr[10] = {};

    while (1)
    {
        int choice = menu();

        switch (choice)
        {
        case EXIT:
            exit(0);

        case DISP:
            display_available_indexes(arr);
            break;

        case ADD:
            add_number(arr);
            break;

        case DEL:
            delete_number(arr);
            break;

        case MAX:
            max_number(arr);
            break;

        case MIN:
            min_number(arr);
            break;

        case SUM:
            sum_numbers_in_array(arr);
            break;

        default:
            break;
        }
    }

    return (0);
}

int menu()
{
    int choice;
    printf("\n\nMenu Operations:");
    printf("\n\t 0. Exit ");
    printf("\n\t 1. Display Array Elements ");
    printf("\n\t 2. Add number ");
    printf("\n\t 3. Delete number ");
    printf("\n\t 4. Find max number (along with its index) ");
    printf("\n\t 5. Find min number (along with its index) ");
    printf("\n\t 6. Sum of numbers \n");
    printf("\nEnter number which operation to be performed: ");
    scanf("%d", &choice);

    return choice;
}

void display_available_indexes(int *disp_array)
{
    int i;
    
    printf("\nArray Elements:\n{\t");
    for (i = 0; i < 10; i++)
    {
        printf("%d\t", disp_array[i]);
    }
    printf("}\n");

    printf("\t");
    for (i = 0; i < 10; i++)
    {
        printf("%d\t", i);
    }
    printf("\n");
}

int add_number(int *a_array)
{
    int index, temp, i, j = 0;

    printf("\nAvailable indexes are");
    for (i = 0; i < 10; i++)
    {
        if (a_array[i] == 0)
            printf("%8d", i);
            
        else
            continue;
    };

    for (i = 0; i < 10; i++)
    {
        if (a_array[i] != 0)
            ++j;
        if (j == 10)
            return printf("\n\n\tIndex's Full..!! Try deleting any of these index's.\n");
    }
    do
    {
        printf("\n\tEnter index number where to add number: ");
        scanf("%d", &index);
    } while (!(index >= 0 && index <= 9));

    do
    {
        printf("\n\tEnter number to add: ");
        scanf("%d", &temp);
    } while (!(temp > 0));

    a_array[index] = temp;
    display_available_indexes(a_array);
}

void delete_number(int *d_array)
{
    int index;

    display_available_indexes(d_array);

    do
    {
        printf("\n\tEnter index number where to delete number: ");
        scanf("%d", &index);
    } while (!(index >= 0 && index <= 9));

    d_array[index] = 0;

    display_available_indexes(d_array);
}

void max_number(int *m_array)
{
    int i = 0, j = 0;
    int key = m_array[i];

    for (i = 1; i < 10; i++)
    {
        if (key < m_array[i])
        {
            key = m_array[i];
            j = i;
        }
    }
    printf("\nMaximum Number: %d at Index: %d", key, j);
}

void min_number(int *m_array)
{
    int i = 0, j = 0;
    int key = m_array[i];

    for (i = 0; i < 10; i++)
    {
        if (key != 0)
        {
            if (key > m_array[i])
            {
                key = m_array[i];
                j = i;
            }
        }
        else
            break;
    }
    printf("\nMainimum Number: %d at index: %d", key, j);
}

void sum_numbers_in_array(int *s_array)
{
    int i, add = 0;
    for (i = 0; i < 10; i++)
    {
        add = add + s_array[i];
    }
    printf("\nSum of numbers in Array: %d", add);
}