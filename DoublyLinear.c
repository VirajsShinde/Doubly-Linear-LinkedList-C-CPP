#include<stdio.h>
#include<stdlib.h>

////////////////////////////////////////////////////////////////////////////////////////
//Linear Data Structure  //github.com/VirajsShinde

//Linked List --> Doubly->Linear.c (C)  

////////////////////////////////////////////////////////////////////////////////////////

#pragma pack(1)
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

//////////////////////////////////////////////////////////////////////////

void InsertLast(PPNODE first,int iNo)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));
    
    PNODE temp = *first;

    newn->data = iNo;
    newn->next = NULL;
    newn->prev = NULL;

    if(*first == NULL)
    {
        *first = newn;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->prev = temp;
    }
}

///////////////////////////////////////////////////////////////////////////

void InsertFirst(PPNODE first, int iNo)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));
    
    newn->data = iNo;
    newn->next = NULL;
    newn->prev = NULL;

    if(*first == NULL)
    {
        *first = newn;
    }
    else
    {
        newn->next = *first;
        (*first)->prev = newn;
        *first = newn;
    }
}

/////////////////////////////////////////////////////////////////////////

void DeleteFirst(PPNODE first)
{
    if(*first == NULL)
    {
        printf("Linked List is Empty \n");
        return;
    }
    else if((*first)->next == NULL)
    {
        free(*first);
        *first = NULL;
    }
    else
    {
        (*first) = (*first)->next;
        free((*first)->prev);
        (*first)->prev = NULL;
    }
}

/////////////////////////////////////////////////////////////////////////

void DeleteLast(PPNODE first)
{
    PNODE temp = *first;

    if(*first == NULL)
    {
        printf("Linked List is Empty \n");
        return;
    }
    else if((*first)->next == NULL)
    {
        free(*first);
        *first = NULL;
    }
    else
    {
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        free(temp->next);

        temp->next = NULL;
    }
}

/////////////////////////////////////////////////////////////////////////

int Count(PNODE first)
{
    int iCnt = 0;

    PNODE temp = first;

    while(temp != NULL)
    {
        iCnt++;
        temp = temp->next;
    }
    return iCnt;
}

/////////////////////////////////////////////////////////////////////////

void Display(PNODE first)
{
    PNODE temp = first;

    while(temp != NULL)
    {
        printf("| %d |->",temp->data);
        temp = temp->next;
    }
    printf("| NULL |\n");
}

////////////////////////////////////////////////////////////////////////

void InsertAtPosition(PPNODE first,int iNo,int iPos)
{
    int CountNode = 0;

    PNODE temp = NULL;

    CountNode = Count(*first);

    if((iPos < 1) || (iPos > CountNode+1))
    {
        printf("Invalid Position \n");
        return;
    }
    if(iPos == 1)
    {
        InsertFirst(first,iNo);
    }
    else if(iPos == CountNode+1)
    {
        InsertLast(first,iNo);
    }
    else
    {
       PNODE newn = (PNODE)malloc(sizeof(NODE));
    
        newn->data = iNo;
        newn->next = NULL;
        newn->prev = NULL; 

        temp = *first;

        for(int iCnt = 1; iCnt < iPos-1; iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next->prev = newn;

        newn->prev = temp;
        temp->next = newn;
    }
}

/////////////////////////////////////////////////////////////////////////

void DeleteAtPosition(PPNODE first,int iPos)
{
    int CountNode = 0;

    PNODE temp1 = NULL;
    PNODE temp2 = NULL;

    CountNode = Count(*first);

    if((iPos < 1) || (iPos > CountNode+1))
    {
        printf("Invalid Position \n");
        return;
    }
    if(iPos == 1)
    {
        DeleteFirst(first);
    }
    else if(iPos == CountNode+1)
    {
        DeleteLast(first);
    }
    else
    {
        temp1 = *first;
        
        for(int iCnt = 1; iCnt < iPos-1; iCnt++)
        {
            temp1 = temp1->next;
        }

        temp2 = temp1->next;

        temp1->next = temp1->next->next;
        temp2->next->prev = temp1;

        free(temp2);
    }   
}
//////////////////////////////////////////////////////////////////////////

void Options()
{
    printf("-------------------------------------------------------------------\n");

        printf("Please Select Desire Option : \n");
        printf("1 : Insert First \n");
        printf("2 : Insert Last \n");
        printf("3 : Insert At given Position\n");
        printf("4 : Delete First\n");
        printf("5 : Delete Last\n");
        printf("6 : Delete At given Position\n");
        printf("7 : Display the contents of Linked List\n");
        printf("8 : Count Number of Nodes from Linked List\n");
        printf("9 : Options\n");
        printf("10 : EXIT\n");
        printf("-------------------------------------------------------------------\n");
}

int main()
{
    PNODE Head = NULL;

    int iChioce = 0, iPos = 0, iRet = 0, iNo = 0;

    printf("\n Welcome --DS--> Doubly->Linear.c | github.com/VirajsShinde\n");

    Options();

    while(1)
    {
        printf("Enter Number : ");
        scanf("%d",&iChioce);

        switch(iChioce)
        {
            case 1: 
                printf("Enter the data that you want to insert first : \n");
                scanf("%d",&iNo);

                InsertFirst(&Head, iNo);
                Display(Head);
                break;
            
            case 2:
                printf("Enter the data that you want to insert last : \n");
                scanf("%d",&iNo);

                InsertLast(&Head, iNo);
                Display(Head);
                break;

            case 3:
                printf("Enter the data that you want to insert at position : \n");
                scanf("%d",&iNo);
                printf("Enter the Position : \n");
                scanf("%d",&iPos);

                InsertAtPosition(&Head,iNo,iPos);
                Display(Head);
                break;

            case 4:
                DeleteFirst(&Head);
                Display(Head);
                break;

            case 5:
                DeleteLast(&Head);
                Display(Head);
                break;

            case 6:
                printf("Enter the Position : \n");
                    scanf("%d",&iPos);
                    
                    DeleteAtPosition(&Head, iPos);
                    Display(Head);
                    break;

            case 7:
                Display(Head);
                break;

            case 8:
                iRet = Count(Head);
                printf("Number of Elemnets are : %d\n\n",iRet);
                break;

            case 9:
                Options();
                break;

            case 10:
                printf("Thank you for using this application\n");
                printf("--------------------------------------------------------------------\n");
                return 0;

            default:
                printf("Invalid Position\n");
                break;
        }
        printf("\n");
        printf("--------------------------------------------------------------------\n");
    }
    return 0;
}