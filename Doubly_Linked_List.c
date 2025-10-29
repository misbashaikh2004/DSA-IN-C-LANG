#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next,*pre;
}Node;

void append(Node **r,int data)
{
    Node *newNode=(Node *)malloc(sizeof(Node));
    newNode->data=data;
    newNode->pre=NULL;
    newNode->next=NULL;

    if((*r) == NULL)
    (*r)=newNode;

    else
    {
        Node *temp=(*r);
        while(temp->next != NULL)
              temp=temp->next;
          temp->next=newNode;
          newNode->pre=temp;
    }
}

void insertFirst(Node **r,int data)
{
    Node *newNode=(Node *)malloc(sizeof(Node));
    newNode->data=data;
    newNode->next=NULL;
    newNode->pre=NULL;

    if((*r) == NULL)
       (*r)=newNode;
    else
    {
        newNode->next=(*r);
        (*r)->pre=newNode;
        (*r)=newNode;
    }
}

void display(Node *head)
{
    while(head != NULL)
    {
        printf("%d\n",head->data);
        head=head->next;
    }
}

Node* search(Node *r,int data)
{
    while(r != NULL)
    {
       if(r->data == data)
          return r;
          r=r->next;
    }
    return NULL;
}

int count(Node *head)
{
    int cnt=0;
    while(head != NULL)
    {
        cnt++;
        head=head->next;
    }
    return cnt;
}

void deleteFirst(Node **r)
{
  if((*r)->next==NULL)
     (*r)=NULL;

  else
  {
    Node *del=(*r);
    (*r)=(*r)->next;
    del->next=NULL;
    (*r)->pre=NULL;
    free(del);
  }
}

void deleteLast(Node **r)
{
    if((*r)->next==NULL)
       (*r)=NULL;
    else
    {
        Node *temp=(*r);
        while(temp->next->next!=NULL)
             temp=temp->next;
             temp->next->pre=NULL;
             temp->next=NULL;
    }
}
void insertByPosition(Node *head,int pos,int data){
    int i;
    Node *newNode=(Node *)malloc(sizeof(struct Node));
      newNode->data=data;
      Node *temp=head;

      for(i=2;i<pos;i++)
         temp=temp->next;

        newNode->next=temp->next;
        newNode->pre = temp; 
        temp->next->pre = newNode;
        temp->next=newNode;

}

void deleteByPosition(Node *head,int pos){
    Node *temp=head;
    Node *del;
    int i;
    for(i=2;i<pos;i++)
    temp=temp->next;

    del=temp->next;

    temp->next=del->next;
    del->next->pre=temp;

    del->next=del->pre=NULL;
    free(del);

}

void deleteByValue(Node *head,int data){
    Node *result=search(head,data);
    Node *del;

    if(result == NULL){
        printf("NOT FOUND !!");
        return;
    }
        del=result;
        result=result->pre;
        result->next=del->next;

    if(del->next !=NULL)
        del->next->pre=result;
        del->next=del->pre=NULL;
        free(del);


}

int main()
{
    Node *head=NULL;
    int data,result,pos;
    int ch,pre;
    Node *temp;

    while(1)
    {
        printf("\n\n1.Append\n2.Insert First\n3.Display\n4.Search\n5.Count\n6.Delete First\n7.Delete Last\n8Insert By Position\n9.Delete By Position\n10.Delete By Value\n11.Exit\nEnter Your Choice:");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                  printf("Enter a Data:");
                  scanf("%d",&data);
                  append(&head,data);
                  break;

            case 2:
                  printf("Enter a Data:");
                  scanf("%d",&data);
                  insertFirst(&head,data);
                  break;
            case 3:
                  display(head);
                  break;
                  
            case 4:
                  printf("Enter a Data:");
                  scanf("%d",&data);
                  temp=search(head,data);

                if(temp==NULL)
                     printf("NOT FOUND !!");
                else
                    printf("FOUND !!");
                break;

            case 5:
                   printf("Count is %d",count(head));
                   break;
                   
            case 6:
                if(head==NULL)
                {
                    printf("\nLINKED LIST IS EMPTY !!\n");
                    continue;
                }
                    deleteFirst(&head);
                    break;
                
            case 7:
                if(head==NULL)
                {
                    printf("\nLINKED LIST IS EMPTY !!\n");
                    continue;
                }
                    deleteLast(&head);

            case 8:
                printf("Enter a position:");
                scanf("%d",&pos);

                if(pos>0 && pos<=count(head)+1)
             {
                 printf("Enter  a Data:");
                 scanf("%d",&data);
                if(pos == 1)
                 insertFirst(&head,data);

                 else if(pos==count(head)+1)
                append(&head,data);

                else
                 insertByPosition(head,pos,data);
            }
                else
                 printf("INVALID POSITION!!");
                break;
            
            case 9:
                 if(head==NULL)
              {
                  printf("empty");
                  continue;
              }

                  printf("Enter a position:");
                  scanf("%d",&pos);

                if(pos > 0 && pos<=count(head))
              {

                if(pos == 1)
                  deleteFirst(&head);

                else if(pos==count(head))
                  deleteLast(&head);
                else
                   deleteByPosition(head,pos);
        
              }
                 else
                    printf("INVALID POSITION !!");
                    break;

               case 10:
                     if(head==NULL)
              {
                       printf("empty");
                      continue;
              }
                       printf("Enter a data:");
                       scanf("%d",&data);
                    if(head->data == data)
                       deleteFirst(&head);

                    else
                         deleteByValue(head,data);
                         break;

                  case 11:
                         exit(0);
                          break;

            default:
                    printf("INVALID CHOICE !!");
                    break;
        }
    }
}