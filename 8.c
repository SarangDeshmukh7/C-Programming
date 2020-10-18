#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10

typedef struct
{
    int num;
    char name[40];
    char genres[50];
} movie_info;

movie_info movie[SIZE];

typedef struct node
{
    movie_info arr[SIZE];
    int data;
    struct node *next; //self-referential pointer
} node_t;

//create an empty list
node_t *head = NULL;

node_t *create_node(int data, char name[40], char genres[50]);
void add_node_at_last_position(int data, char name[40], char genres[50]);
void display_list(void);
int count_nodes(void);
void searchbyname(void);
void searchbygenres(void);

enum menu_options
{
    EXIT,
    ADDLAST,
    DISP,
    BYNAME,
    BYGENRES
};

int menu(void)
{
    int choice;

    printf("\nSingly linear linked list operations\n");
    printf("0. exit\n");
    printf("1. load elements of csv into linked list\n");
    printf("2. display list\n");
    printf("3. search movie by movie name\n");
    printf("4. search movie by genre\n");

    printf("enter the choice: ");
    scanf("%d", &choice);

    return choice;
}

//entry point function
int main(void)
{
    int i;
    int pos;
    int number;
    char name[40];
    char genres[50];
    char str[1000];
    char *tok;

    FILE *fp = fopen("file.csv", "r");

    if (fp == NULL)
    {
        printf("File not found.\n");
        exit(1);
    }

    while (fgets(str, sizeof(str), fp) != NULL)
    {
        tok = strtok(str, ",");
        movie[i].num = atoi(tok);

        tok = strtok(NULL, ",");
        strcpy(movie[i].name, tok);

        tok = strtok(NULL, ",");
        strcpy(movie[i].genres, tok);

        //printf("index i= %i  ID: %i, %s, %s \n", i, movie[i].num, movie[i].name, movie[i].genres);

        i++;
    }

    while (1)
    {
        int choice = menu();
        switch (choice)
        {
        case EXIT:
            exit(0);

        case ADDLAST:
            for (i = 0; i < SIZE; i++)
            {
                number = movie[i].num;
                strcpy(name, movie[i].name);
                strcpy(genres, movie[i].genres);
                add_node_at_last_position(number, name, genres);
            }
            break;

        case DISP:
            display_list();
            break;

        case BYNAME:
            searchbyname();
            break;

        case BYGENRES:
            searchbygenres();
            break;
        }
    }
    fclose(fp);
    return 0;
}

node_t *create_node(int num, char name[40], char genres[50])
{
    //1. allocate memory dynamically for a node
    node_t *temp = (node_t *)malloc(sizeof(node_t));
    if (temp == NULL)
    {
        printf("malloc() failed !!!\n");
        exit(1);
    }

    //2. initialize members of the node
    temp->arr->num = num;
    strcpy(temp->arr->name, name);
    strcpy(temp->arr->genres, genres);
    temp->next = NULL;

    //3. return starting addr of dynamically allocated node to the calling function
    return temp;
}

void add_node_at_last_position(int num, char name[40], char genres[50])
{
    //step1: create a new node
    node_t *newnode = create_node(num, name, genres);

    //step2: if list is empty --> attach newly created node to the head
    if (head == NULL)
    {
        //store an addr of newly created node into the head
        head = newnode;
    }
    else //step3: if list is not empty
    {
        //start traversal from first node
        node_t *trav = head;

        //traverse the list till last node
        while (trav->next != NULL)
        {
            trav = trav->next; //moves trav pointer towards its next node
        }

        //attach newly created node to the last node
        //i.e. store an addr of newly created node into the next part of last node
        trav->next = newnode;
    }
}

int count_nodes(void)
{
    int cnt = 0;
    //if list is not empty
    if (head != NULL)
    {
        //start traversal from the first node
        node_t *trav = head;
        //traverse the list and increment counter
        while (trav != NULL)
        {
            cnt++;
            trav = trav->next;
        }
    }

    return cnt;
}

void display_list(void)
{
    //if list is not empty
    if (head != NULL)
    {
        //start traversal from first node
        node_t *trav = head;

        //traverse the list till last node
        printf("no. of nodes in a list are: %d\n", count_nodes());
        printf("head\n");
        while (trav != NULL)
        {
            //display data part of the node
            printf("-> %d,%s,%s", trav->arr->num, trav->arr->name, trav->arr->genres);
            //move trav towards its next node
            trav = trav->next;
        }
        printf("\n->null\n");
    }
    else
    {
        printf("list is empty !!!\n");
    }
}

void searchbyname()
{
    node_t *trav = head;
    char name[40];
    int i = 0, mark = 0;

    if (trav == NULL)
    {
        printf("\nEmpty List\n");
    }
    else
    {
        scanf("%*c");
        printf("Enter the Movie name which you want to search: ");
        scanf("%[^\n]%*c", name);
        while (trav != NULL)
        {
            if (strstr(trav->arr->name, name))
            {
                printf("Movie with name \"%s\" found in linked list at location %d.\n", name, i + 1);
                printf("\n\t%d. %s- %s\n", trav->arr->num, trav->arr->name, trav->arr->genres);
                mark = 1;
                break;
            }
            i++;
            trav = trav->next;
        }
        if (mark == 0)
        {
            printf("Movie with name \"%s\" not found in linked list.\n", name);
        }
    }
}

void searchbygenres()
{
    node_t *trav = head;
    char genres[50];
    int i = 0, mark = 0;

    if (trav == NULL)
    {
        printf("\nEmpty List\n");
    }
    else
    {
        scanf("%*c");
        printf("\nEnter genre which movie you want to search: ");
        scanf("%[^\n]%*c", genres);
        while (trav != NULL)
        {
            if (strstr(trav->arr->genres, genres))
            {
                printf("Movie with genre \"%s\" found in linked list at location %d.\n", genres, i + 1);
                printf("\n\t%d. %s- %s\n", trav->arr->num, trav->arr->name, trav->arr->genres);
                mark = 1;
            }
            i++;
            trav = trav->next;
        }
        if (mark == 0)
        {
            printf("Movie with genre \"%s\" not found in linked list\n", genres);
        }
    }
}