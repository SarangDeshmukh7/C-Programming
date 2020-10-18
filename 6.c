#include<stdio.h>
#include<stdlib.h>

#define SIZE 5

typedef struct 
{
    int roll;
    char name[10];
    int std;
    char subject_name[6][10];
    int subject_marks[6];
}student;

typedef struct queue
{
    student arr[ SIZE ];
    int rear;
    int front;
}queue_t;

void init_queue(queue_t *pq);
int is_queue_full(queue_t *pq);
int is_queue_empty(queue_t *pq);
void enqueue(queue_t *pq, int roll ,char n[10],int  s,char s_name[1][10],int s_marks[1]);
int get_front(queue_t *pq);
void dequeue(queue_t *pq);

int menu(void)
{
    int choice;

    printf("circular queue\n");
    printf("0. exit\n");
    printf("1. enqueue\n");
    printf("2. dequeue\n");

    printf("enter the choice :");
    scanf("%d", &choice);

    return choice;
}

enum menu_options{ EXIT, ENQUEUE, DEQUEUE };

int main(void)
{
    queue_t q;
    int roll,i;
    char name[10];
    int std;
    char subject_name[6][10];
    int subject_marks[6];

    init_queue(&q);

    while(1)
    {
        int choice = menu();
        
        switch(choice)
        {
            case EXIT:
                exit(0);

            case ENQUEUE:

                if( !is_queue_full(&q) )
                {
                    printf("enter roll no: ");
                    scanf("%d", &roll);

                    printf("enter name: ");
                    scanf("%s", &name);

                    printf("enter std: ");
                    scanf("%d", &std);

                    for(i=0;i<5;i++)
                    {
                        printf("enter subject name: ");
                        scanf("%s", &subject_name[i]);

                        printf("enter subject marks: ");
                        scanf("%d", &subject_marks[i]);
                    }
                    enqueue(&q, roll,name,std,subject_name,subject_marks);
                    printf("Student with roll: %d details inserted into the queue...\n",roll);
                }
                else
                {
                    printf("queue is full !!!\n");
                }
                
                break;

            case DEQUEUE:

                if( !is_queue_empty(&q) )
                {
                    roll = get_front(&q);
                    dequeue(&q);
                    printf("student with roll: %d deleted from the queue....\n", roll);
                }
                else
                {
                    printf("queue is empty !!!\n");
                }
                
                break;
        }
    }

    return 0;   
}

void init_queue(queue_t *pq)
{
    /*
    int index;

    for( index = 0 ; index < SIZE ; index++ )
        pq->arr[ index ] = 0;
    */

    pq->rear = -1;
    pq->front = -1;
}

int is_queue_full(queue_t *pq)
{
    return ( pq->front == ( pq->rear + 1 ) % SIZE );
}

int is_queue_empty(queue_t *pq)
{
    return ( pq->rear == -1 && pq->front == pq->rear );
}

void enqueue(queue_t *pq, int roll ,char n[10],int  s,char s_name[1][10],int s_marks[1])
{

    pq->rear = ( pq->rear + 1 ) % SIZE;
    pq->arr[ pq->rear ].roll = roll;
    pq->arr[ pq->rear ].name[10] = n[10];
    pq->arr[ pq->rear ].std = s;
    pq->arr[ pq->rear ].subject_name[pq->rear][10] = s_name[1][10];
    pq->arr[ pq->rear ].subject_marks[pq->rear] = s_marks[1];

    if( pq->front == -1 )
        pq->front = 0;
}

int get_front(queue_t *pq)
{
    return ( pq->arr[ pq->front ].roll );
}

void dequeue(queue_t *pq)
{
    

    if( pq->front == pq->rear )     //we are deleting last element
        pq->front = pq->rear = -1;
    else
        pq->front = (pq->front + 1 ) % SIZE; /* step2: increment the value of front by 1
		                                        [ i.e. we are popping an ele from the queue ]*/
}
