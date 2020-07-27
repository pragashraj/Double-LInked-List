#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *right;
    struct node *left;
};

struct node *head=NULL;

void insertInEnd(int element){
    struct node *temp,*p;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=element;
    temp->left=NULL;
    temp->right=NULL;

    if(head==NULL){
        head=temp;
    }
    else{
        p=head;
        while(p->right!=NULL){
            p=p->right;
        }
        temp->left=p;
        p->right=temp;
    }
}


void insertInFront(int element){
    struct node *temp,*p;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=element;
    temp->left=NULL;
    temp->right=NULL;

    if(head==NULL){
        head=temp;
    }
    else{
        p=head;
        temp->right=p;
        p->left=temp;
        head=temp;

    }
}


void deleteInEnd(){
    if(head==NULL){
        printf("No Elements in the List to Delete\n");
        return;
    }

    struct node *p,*q;
    p=head;
    q=head;
    while(p->right!=NULL){
        p=p->right;
    }

    q=p->left;
    p->left=NULL;
    q->right=NULL;

    free(p);

}


void deleteInFront(){
    if(head==NULL){
        printf("No Elements in the List to Delete\n");
        return;
    }

    struct node *p;
    p=head;
    head=p->right;
    p->right->left=NULL;
    p->right=NULL;
}


void displayList(){
    if(head==NULL){
        printf("No Elements in the List\n");
        return;
    }

    struct node *p;
    p=head;
    while(p!=NULL){
        printf("%d \t",p->data);
        p=p->right;
    }
    printf("\n");
}


int main()
{
    insertInEnd(10);
    insertInEnd(20);
    insertInEnd(30);
    insertInEnd(40);
    displayList();

    deleteInEnd();
    displayList();

    insertInFront(5);
    displayList();

    deleteInFront();
    displayList();

    return 0;
}
