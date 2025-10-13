#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next;
}Node;

void append(Node **r,int data)
{
   Node *newNode=(Node*)malloc(sizeof(Node));
   newNode->data=data;
   newNode->next=NULL;

   if((*r) == NULL)
   (*r)=newNode;

   else
   {
    Node *temp=(*r);
    while(temp->next != NULL)
        temp=temp->next;
        temp->next=newNode;
   }
}


void insertFirst(Node **r,int data)
{
    Node *newNode=(Node *)malloc(sizeof(Node));
    newNode->data=data;
    
    newNode->next=(*r);
    (*r)=newNode;
}

void display(Node *head)
{
    while(head != NULL)
    {
       printf("%d\n",head->data);
       head=head->next;
    }

}

void deleteFirst(Node **r)
{
    if((*r)==NULL)
    return;

   Node *del=(*r);
   (*r)=(*r)->next;
   del->next=NULL;
   free(del);
}

void deleteLast(Node **r)
{
    if((*r) == NULL)
      return;
    
      if((*r)->next==NULL)
      (*r)=NULL;
    else
    {
        Node* temp=(*r);
        while(temp->next->next != NULL)
             temp=temp->next;

            // free(temp->next);
            temp->next=NULL;
    }
}

void insertByPosition(Node *head,int pos,int data)
{
    int i;
    Node *newNode=(Node *)malloc(sizeof(Node));
    newNode->data=data;
    Node *temp=head;

    for(i=2;i<pos;i++)
    {
       temp=temp->next;
    }
       newNode->next=temp->next;
       temp->next=newNode;
}

 void deleteByPosition(Node *head,int pos){
    int i;
    Node *del;
    Node *temp=head;

    for(i=2;i<pos;i++)
    {
       temp=temp->next;  
    }
       del=temp->next;
       temp->next=del->next;
       del->next=NULL;
       free(del);

 }

 int count(Node *head)
 {
    int cnt=0;
    while(head)
    {
        head=head->next;
        cnt++;
    }
    return cnt;
 }

 int search(Node *head,int data){
    int index=1;
    while(head!=NULL)
    {
        if(head->data==data)
          return index;
          head=head->next;
          index++;
    }
    // return (head==NULL)?-1:index;
    return -1;
 }

  void deleteByValue(Node *head,int data){
        Node *temp=head;
        Node *del;

        while(temp->next->data!=data){
              temp=temp->next;
        if(temp->next==NULL)
            return;
        }

        del=temp->next;
        temp->next=del->next;
        del->next=NULL;
        free(del);
     }

int main()
{
    Node *head=NULL;
    int data,pos;
    int ch,result;

    while(1)
    {
        printf("\n\n1.Append\n2.Insert First\n3.Display\n4.Delete First\n5.Delete Last\n6.Insert By Position\n7.Delete By Position\n8.Count\n9.Search\n10.Delete By Value\n11.Exit\nEnter Your Choice:");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                printf("Enter A Data:");
                scanf("%d",&data);
                append(&head,data);
                break;
            
            case 2:
                 printf("Enter A Data:");
                scanf("%d",&data);
                insertFirst(&head,data);
                break;

            case 3:
                display(head);
                 break;

            case 4:
                 deleteFirst(&head);
                 break;
                 
            case 5:
                  deleteLast(&head);
                  break;
            
            case 6:
                  printf("enter pos:");
                  scanf("%d",&pos);

                  printf("enter data:");
                  scanf("%d",&data);

              if(pos == 1)
                  insertFirst(&head,data);

              else if(pos == count(head)+1)
                  append(&head,data);

              else if(pos > 1 && pos <= count(head))
                  insertByPosition(head,pos,data);
               else
                  printf("INVALID");
                  break;
         
                     
            case 7:
                   printf("enter position:");
                   scanf("%d",&pos);

              if(pos==1)
                  deleteFirst(&head);

             else if(pos == count(head))
                  deleteLast(&head);

             else if(pos >1 && pos < count(head))
                  deleteByPosition(head,pos);
             else
                 printf("invalid");
                 break;
           
            case 8:
                  printf("\nCount is %d\n",count(head));
                  break;

            case 9:
                    printf("Enter a Data:");
                    scanf("%d",&data);
                    result=search(head,data);
                 if(result!=-1)
                   printf("FOUND at %d",result);
                 else
                     printf("NOT FOUND!!");
                     break;      
          
             case 10:
                    printf("Enter a Data:");
                    scanf("%d",&data);
               if(head->data == data)
                   deleteFirst(&head);

              else if(count(head)==1)
                   printf("NOT FOUND");

              else
                  deleteByValue(head,data);
                  break;

            case 11:
                return 0;
                break;

        default:
        printf("INVALID CHOICE !!");
        break;    

        }
    }
}