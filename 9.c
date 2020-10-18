#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int menu();
void additem();
void display();
void update();
void delete ();

typedef struct
{
    char name[40];
    int id;
    float price;
    int quant;
} item;

int main(void)
{
    int choice, size;
    //open file
    FILE *fptr = fopen("inventory.bin", "ab+");
    if (fptr == NULL)
    {
        printf("\nFile not found.");
        exit(1);
    }

    if (NULL != fptr)
    {
        fseek(fptr, 0, SEEK_END);
        size = ftell(fptr);
        if (0 == size)
        {
            printf("file is empty\n");
        }
        else
        {
            display();
        }
    }

    fclose(fptr);

    while (1)
    {
        choice = menu();

        switch (choice)
        {
        case 0:
            exit(0);

        case 1:
            additem();
            break;

        case 2:
            display();
            break;

        case 3:
            update();
            break;

        case 4:
            delete ();
            break;
        }
    }
}

int menu()
{
    int num;
    printf("\n1. Add item in inventory\n");
    printf("2. display items from inventory\n");
    printf("3. Modify item from inventory\n");
    printf("4. Delete item from inventory\n");
    printf("0. Exit\n");
    printf("Enter operation to be performed:\n");
    scanf("%d", &num);
    return num;
}

void additem()
{
    item i;
    int size, id = 0;
    FILE *fptr = fopen("inventory.bin", "ab+");
    if (NULL != fptr)
    {
        fseek(fptr, 0, SEEK_END);
        size = ftell(fptr);
        if (0 == size)
        {
            printf("Enter id:");
            scanf("%d", &i.id);
        }
        else
        {
            rewind(fptr);
            while (fread(&i, sizeof(item), 1, fptr))
            {
                id = i.id + 1;
            }
            i.id = id;
            fseek(fptr, 0, SEEK_END);
        }

        printf("Enter item name: ");
        scanf("%*c");
        gets(i.name);

        printf("Enter price: ");
        scanf("%f", &i.price);

        printf("Enter Quantity: ");
        scanf("%d", &i.quant);

        fwrite(&i, sizeof(item), 1, fptr);
        fclose(fptr);
    }

    printf("\nItem added to inventory\n");
}

void display()
{
    item i;
    FILE *fptr = fopen("inventory.bin", "ab+");
    rewind(fptr);
    printf("\nInventory:");
    printf("\n=======================================================");
    printf("\nName\t\t     id\t   price\t   quant");
    printf("\n=======================================================");
    while (fread(&i, sizeof(item), 1, fptr))
        printf("\n%-20s %-5d %-15f %-5d", i.name, i.id, i.price, i.quant);
    printf("\n=======================================================");
    fclose(fptr);
}

void update()
{
    item i, temp;
    int size = sizeof(item);
    FILE *fptr = fopen("inventory.bin", "rb+");

    printf("\nEnter item name to update: ");
    scanf("%*c");
    gets(temp.name);
    printf("%s", temp.name);

    rewind(fptr);
    while (fread(&i, sizeof(item), 1, fptr) == 1)
    {
        if (strcmp(temp.name, i.name) == 0)
        {
            printf("\nEnter new name: ");
            gets(i.name);
            //printf("%s",i.name);

            printf("\nEnter price: ");
            scanf("%f", &i.price);

            printf("\nEnter Quantity: ");
            scanf("%d", &i.quant);

            fseek(fptr, -size, SEEK_CUR);
            fwrite(&i, size, 1, fptr);
            break;
        }
    }
    fclose(fptr);
    printf("\nItem details updated..!!!");
}

void delete ()
{
    item i, temp;
    int size = sizeof(item);
    FILE *fptr = fopen("inventory.bin", "rb+");
    FILE *fptr1 = fopen("temp.bin", "ab+");

    printf("\nEnter name of item to delete ");
    scanf("%*c");
    gets(temp.name);
    printf("%s", temp.name);
    rewind(fptr);
    while (fread(&i, size, 1, fptr))
    {
        if (strcmp(i.name, temp.name) != 0)
            fwrite(&i, size, 1, fptr1);
    }
    fclose(fptr);
    fclose(fptr1);
    remove("inventory.bin");
    rename("temp.bin", "inventory.bin");
    printf("\nItem with name %s deleted from inventory",temp.name);
}