// singly linked list implementation by supersekhar
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


typedef struct Node{
    int info;
    struct Node* prev;
    struct Node* next;
}Node;

Node* head=NULL;

void display(){
    Node* ptr=head;
    printf("\nOur linkedlist is\n");
    printf("Start:\t");
    while(ptr!=NULL){
        printf("%d\t",ptr->info);
        ptr=ptr->next;
    }
    printf("\t");
}

void insertatbeg(int data){
    Node* newnode;
    newnode=(Node*)malloc(sizeof(Node));
    newnode->info=data;
    newnode->next=NULL;
    newnode->prev=NULL;
    if(head==NULL){
        head=newnode;
        return;
    }
    head->prev=newnode;
    newnode->next=head;
    head=newnode;
}

void deleteatbeg(){
    if(head==NULL){
        printf("Empty Linked list can't delete");
        return;
    }

    Node* ptr=head;

    head->next->prev=NULL;
    head=head->next;
    printf("\nDeleted data %d \n",ptr->info);
    free(ptr);
}

void deleteatlast(){
    if(head==NULL){
        printf("Empty Linked list can't delete");
        return;
    }
    Node* ptr=head;

    if(head->next==NULL){
        head==NULL;
        free(ptr);
        return ;
    }
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    
    ptr->prev->next=NULL;
    printf("\nDeleted data %d \n",ptr->info);
    free(ptr);
}


void insertatlast(int data){
    Node* newnode;
    Node* ptr=head;
    newnode=(Node*)malloc(sizeof(Node));
    newnode->info=data;
    newnode->next=NULL;
    newnode->prev=NULL;
    if(head==NULL){
        head=newnode;
        return;
    }
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next=newnode;
    newnode->prev=ptr;
}

void insertatpos(int data,int pos){
    Node* newnode;
    Node* ptr=head;
    newnode=(Node*)malloc(sizeof(Node));
    newnode->info=data;
    newnode->next=NULL;
    newnode->prev=NULL;
    if(head==NULL && pos>1){
        printf("The list is empty");
        return ;
    }

    if(pos==1){
    head->prev=newnode;
    newnode->next=head;
    head=newnode;
    return ;
    }

    for(int i=1;i<pos-1;i++){
        if(ptr==NULL){
            printf("\nPosition not found");
            return ;
        }
        ptr=ptr->next;
    }

    newnode->next=ptr->next;
    newnode->prev=ptr;
    if(ptr->next!=NULL) ptr->next->prev=newnode;
    ptr->next=newnode;
}
void update(int newdata,int pos){
    Node* ptr=head;
    if(head==NULL){
        printf("empty list ");
        return ;
    }
    if(pos<1){
        printf("position can't be less than one");
        return ;
    }

    for(int i=1;i<pos;i++){
        if(ptr==NULL){
            printf("\nPosition not found");
            return ;
        }
        ptr=ptr->next;
    }
    ptr->info=newdata;

}
void deletetatpos(int pos){

    if(head==NULL){
        printf("list is empty");
        return ;
    }
    Node* ptr=head;

    if(pos==1){
    head->next->prev=NULL;
    head=head->next;
    return ;
    }

    for(int i=1;i<pos;i++){
        if(ptr==NULL){
            printf("\nPosition not found");
            return ;
        }
        ptr=ptr->next;
    }

    ptr->prev->next=ptr->next;
    if(ptr->next!=NULL) ptr->next->prev=ptr->prev;
    printf("\ndeleted data %d",ptr->info);
    free(ptr);
}


int main(){
    insertatbeg(4);
    insertatbeg(5);
    insertatbeg(6);
    insertatlast(1);
    insertatlast(10);
    display();
    deleteatbeg();
    display();
    deleteatlast();
    display();
    insertatpos(22,3);
    display();
    insertatpos(24,3);
    display();
    deletetatpos(5);
    display();
    insertatpos(28,5);
    display();
    insertatpos(29,6);
    display();
    update(31,2);
    display();
    return 0;
}
