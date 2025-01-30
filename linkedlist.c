// singly linked list implimentation by me
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;

node* head=NULL;
void insertion_beg(int data){
    node* newnode;
    newnode=(node*)malloc(sizeof(node));
    newnode->data=data;
    newnode->next=NULL;
    if(head==NULL){
        head=newnode;
        return;
    }
    newnode->next=head;
    head=newnode;
}

void delete_beg(){
    if(head==NULL)
    { printf("Empty list");
        return ;}
    node *ptr=head;
    head=head->next;
    free(ptr);
}

void insertion_last(int data){
    node* newnode;
    node* ptr;
    newnode=(node*)malloc(sizeof(node));
    newnode->data=data;
    newnode->next=NULL;
    if(head==NULL){
        head=newnode;
        return;
    }
    ptr=head;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next=newnode;
}

void delete_last(){
    node* tmp;
    if(head==NULL)
    { printf("Empty list");
        return ;
        }
    node* ptr=head;

    if(head->next==NULL){
        head=NULL;
        free(ptr);
        return ;
    }
    while(ptr->next!=NULL){
        tmp=ptr;
        ptr=ptr->next;
    }
    tmp->next=NULL;
    free(ptr);
}

void insert_at_pos(int pos,int data){
    node* newnode;
    node* ptr;
    node* temp;
    newnode=(node*)malloc(sizeof(node));
    newnode->data=data;
    newnode->next=NULL;
    ptr=head;

    if(head==NULL){
        printf("Empty list");
        return ;
    }

    if(pos==1){
        newnode->next=head;
        head=newnode;
        return;
    }

    for(int i=0;i<pos-1;i++){

        if(ptr==NULL){
            printf("Can't find position\n");
            return ;
        }

        temp=ptr;
        ptr=ptr->next;
    }
    newnode->next=temp->next;
    temp->next=newnode; 

 }

 void delete_at_pos(int pos){ 
    if(head==NULL){
        printf("Empty list");
        return ;
    }

    node* ptr=head;
    node* temp;

    if(pos==1){
        head=head->next;
        free(ptr);
    }

for(int i=0;i<pos-1;i++){

    if(ptr==NULL){
        printf("Can't find position\n");
        return ;
    }
    temp=ptr;
    ptr=ptr->next;
}
    temp->next=ptr->next;
    free(ptr);
 }


void display(){
        if(head==NULL){
        printf("Empty list\n");
        return;
    }
    node* ptr=head;

    while(ptr!=NULL){
        printf("%d\t",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}

int main(){
    insertion_beg(5);
    insertion_beg(6);
    insertion_beg(7);
    display();
    insertion_last(9);
    insertion_last(10);
    display();
    insert_at_pos(1,15);
    insert_at_pos(1,10);
   // insert_at_pos(8,20);
    display();
    delete_beg();
    display();
    delete_last();
    display();
    delete_at_pos(5);
    display();
    return 0;
}
