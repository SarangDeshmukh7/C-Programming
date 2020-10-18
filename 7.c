#include <stdio.h>
#include <stdlib.h>
#include<string.h>
struct node
{
    struct acc
    {
        int id;
        char type[10];
        int balance;
    } account;

    struct acc_holder
    {
        char name[20];
        char address[10];
        char contact[13];
    } a_holder;
    struct node *prev;
    struct node *next;
    int data;
};
struct node *head;
void insertion_beginning();
void insertion_last();
void deletion_beginning();
void deletion_last();
void display();
void displayrev();
void searchbyid();
void searchbyname();
void main()
{
    int choice = 0;
    while (choice != 9)
    {
        printf("\n~*Coded_by_Sarang_Deshmukh*~\n");
        printf("\n*********Main Menu*********\n");
        printf("\nChoose one option from the following list ...\n");
        printf("\n===============================================\n");
        printf("\n1.Insert in begining");
        printf("\n2.Insert at last");
        printf("\n3.Delete from Beginning");
        printf("\n4.Delete from last");
        printf("\n5.Search by ID");
        printf("\n6.Search by account holder name");
        printf("\n7.Display Forward order");
        printf("\n8.Display in Reverse order");
        printf("\n9.Exit\n");
        
        printf("\nEnter your choice?\n");
        scanf("\n%d", &choice);
        switch (choice)
        {
        case 1:
            insertion_beginning();
            break;
        case 2:
            insertion_last();
            break;
        case 3:
           deletion_beginning();
            break;
        case 4:
            deletion_last();
            break;
        case 5:
            searchbyid();
            break;
        case 6:
            searchbyname();
            break;
        case 7:
            display();
            break;
        case 8:
            displayrev();
            break;    
        case 9:
            exit(0);
            break;
        default:
            printf("Please enter valid choice..");
        }
    }
}
void insertion_beginning()
{
    struct node *ptr;
    int item;
    int i,id,bal;
    char typ[10]={}, name[20]={}, address[10]={}, cont[13]={};
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("\nOVERFLOW");
    }

    else
    {
        //printf("\nEnter Item value");
        //scanf("%d", &item);

        printf("\nEnter id:");
        scanf("%d", &id);

        printf("\nEnter type:");
        scanf("%s", typ);

        printf("\nEnter balance:");
        scanf("%d", &bal);

        printf("\nEnter name:");
        scanf("%s", name);

        printf("\nEnter address:");
        scanf("%s", address);
        
        printf("\nEnter contact:");
        scanf("%s", cont);

        if (head == NULL)
        {
            ptr->next = NULL;
            ptr->prev = NULL;
            
            //ptr->data = item;

            ptr->account.id = id;
            ptr->account.balance = bal;
            for(i=0;i<20;i++)
            {
                ptr->a_holder.name[i] = name[i];
            }
            for(i=0;i<10;i++)
            {
                ptr->account.type[i] = typ[i];
            }
            for(i=0;i<10;i++)
            {
                ptr->a_holder.address[i] = address[i];
            }
            for(i=0;i<13;i++)
            {
                ptr->a_holder.contact[i] = cont[i];
            }
            
            head = ptr;
        }
        else
        {
            //ptr->data = item;
            ptr->account.id = id;
            ptr->account.balance = bal;
            for(i=0;i<20;i++)
            {
                ptr->a_holder.name[i] = name[i];
            }
            for(i=0;i<10;i++)
            {
                ptr->account.type[i] = typ[i];
            }
            for(i=0;i<10;i++)
            {
                ptr->a_holder.address[i] = address[i];
            }
            for(i=0;i<13;i++)
            {
                ptr->a_holder.contact[i] = cont[i];
            }

            ptr->prev = NULL;
            ptr->next = head;
            head->prev = ptr;
            head = ptr;
        }
        printf("\nNode inserted\n");
    }
}
void insertion_last()
{
    struct node *ptr, *temp;
    int item;
    int i,id,bal;
    char typ[10]={}, name[20]={}, address[10]={}, cont[13]={};
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("\nOVERFLOW");
    }
    else
    {
        //printf("\nEnter value");
        //scanf("%d", &item);
        
        printf("\nEnter id:");
        scanf("%d", &id);

        printf("\nEnter type:");
        scanf("%s", typ);

        printf("\nEnter balance:");
        scanf("%d", &bal);

        printf("\nEnter name:");
        scanf("%s", name);

        printf("\nEnter address:");
        scanf("%s", address);
        
        printf("\nEnter contact:");
        scanf("%s", cont);

        //ptr->data = item;
        ptr->account.id = id;
        ptr->account.balance = bal;
        for(i=0;i<20;i++)
        {
            ptr->a_holder.name[i] = name[i];
        }
        for(i=0;i<10;i++)
        {
            ptr->account.type[i] = typ[i];
        }
        for(i=0;i<10;i++)
        {
            ptr->a_holder.address[i] = address[i];
        }
        for(i=0;i<13;i++)
        {
            ptr->a_holder.contact[i] = cont[i];
        }

        if (head == NULL)
        {
            ptr->next = NULL;
            ptr->prev = NULL;
            head = ptr;
        }
        else
        {
            temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = ptr;
            ptr->prev = temp;
            ptr->next = NULL;
        }
    }
    printf("\nnode inserted\n");
}

void deletion_beginning()
{
    struct node *ptr;
    if (head == NULL)
    {
        printf("\n UNDERFLOW");
    }
    else if (head->next == NULL)
    {
        head = NULL;
        free(head);
        printf("\nnode deleted\n");
    }
    else
    {
        ptr = head;
        head = head->next;
        head->prev = NULL;
        free(ptr);
        printf("\nnode deleted\n");
    }
}
void deletion_last()
{
    struct node *ptr;
    if (head == NULL)
    {
        printf("\n UNDERFLOW");
    }
    else if (head->next == NULL)
    {
        head = NULL;
        free(head);
        printf("\nnode deleted\n");
    }
    else
    {
        ptr = head;
        if (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->prev->next = NULL;
        free(ptr);
        printf("\nnode deleted\n");
    }
}

void display()
{
    struct node *ptr;
    printf("\n printing values...\n");
    ptr = head;
        printf("\"Acc ID\"\t");
        printf("\"Balance\"\t");
        printf("\"Acc Type\"\t"); 
        printf("\"Name\"\n");
        printf("\n==========================================================\n");

    while (ptr != NULL)
    {
        //printf("%d\t", ptr->data);
        printf("%10d\t", ptr->account.id);
        printf("%10d\t", ptr->account.balance);
        printf("%10s\t", ptr->account.type); 
        printf("%10s\n", ptr->a_holder.name);
        ptr = ptr->next;
    }
}

void displayrev()
{
    struct node *ptr;       

    printf("\n printing values...\n");
    ptr = head;
        printf("\"Acc ID\"\t");
        printf("\"Balance\"\t");
        printf("\"Acc Type\"\t"); 
        printf("\"Name\"\n");
        printf("\n==========================================================\n");
    
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }

    while (ptr != head)
    {
        //printf("%d\t", ptr->data);
        printf("%10d\t", ptr->account.id);
        printf("%10d\t", ptr->account.balance);
        printf("%10s\t", ptr->account.type); 
        printf("%10s\n", ptr->a_holder.name);
        ptr = ptr->prev;
    }
        printf("%10d\t", ptr->account.id);
        printf("%10d\t", ptr->account.balance);
        printf("%10s\t", ptr->account.type); 
        printf("%10s\n", ptr->a_holder.name);

}

void searchbyid()
{
    struct node *ptr;
    int item, i = 0, flag;
    ptr = head;
    if (ptr == NULL)
    {
        printf("\nEmpty List\n");
    }
    else
    {
        printf("\nEnter id which you want to search?\n");
        scanf("%d", &item);
        while (ptr != NULL)
        {
            if (ptr->account.id == item)
            {
                printf("\nAccount ID found at location %d \n", i + 1);
                printf("\"Acc ID\"\t");
                printf("\"Balance\"\t");
                printf("\"Acc Type\"\t"); 
                printf("\"Name\"\n");
                printf("\n==========================================================\n");
                printf("%10d\t", ptr->account.id);
                printf("%10d\t", ptr->account.balance);
                printf("%10s\t", ptr->account.type); 
                printf("%10s\n", ptr->a_holder.name);
                flag = 0;
                break;
            }
            else
            {
                flag = 1;
            }
            i++;
            ptr = ptr->next;
        }
        if (flag == 1)
        {
            printf("\nAccount ID not found\n");
        }
    }
}

void searchbyname()
{
    struct node *ptr;
    char name[20], i = 0, flag;
    ptr = head;
    if (ptr == NULL)
    {
        printf("\nEmpty List\n");
    }
    else
    {
        printf("\nEnter name which you want to search?\n");
        scanf("%s", name);
        
        while (ptr != NULL)
        {
            if ( strcmp( ptr->a_holder.name, name)==0)
            {
                printf("\nAcount name found at location %d \n", i + 1);
                printf("\"Acc ID\"\t");
                printf("\"Balance\"\t");
                printf("\"Acc Type\"\t"); 
                printf("\"Name\"\n");
                printf("\n==========================================================\n");
                printf("%10d\t", ptr->account.id);
                printf("%10d\t", ptr->account.balance);
                printf("%10s\t", ptr->account.type); 
                printf("%10s\n", ptr->a_holder.name);
                flag = 0;
                break;
            }
            else
            {
                flag = 1;
            }
            i++;
            ptr = ptr->next;
        }
        if (flag == 1)
        {
            printf("\nAccount name not found\n");
        }
    }
}