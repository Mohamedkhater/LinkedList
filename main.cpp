#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string>
using namespace std;
struct node
{
    int data;
    struct node* next;

};
struct linkedlist{
    node* head;
    node* tail;

};
void initLinkedlist(linkedlist* ll){
   ll->head= nullptr;
    ll->tail= nullptr;


}
node*  CreateNode(int val){
    node* a=(node *)malloc(sizeof(node));
    a->data=val;
    a->next= nullptr;
    return a;

}

void addBegining(linkedlist* ll,int val){
    if (ll->head!= nullptr){
        node* a=CreateNode(val);
        a->next=ll->head;
        ll->head=a;
        ll->head->next=a->next;


    }
    else{                                //list is empty
        node* temp=CreateNode(val);
       ll->head=temp;
        ll->tail=temp;

    }

}
void addLast(linkedlist* ll,int val){
    node* s=CreateNode(val);
    node* temp=ll->head;
    if (temp){
        while(temp->next!= nullptr){
            temp=temp->next;
        }
        temp->next=s;
        ll->tail=s;

    }
    else{
        ll->head=s;
        ll->tail=s;
    }


}
void DeleteBegining(linkedlist* s){

    s->head=s->head->next;


}
void DeleteEnd(linkedlist* ll){
    if (ll->head==ll->tail){
        node* tmp=ll->head;
        node* tmp2=ll->tail;
        ll->head= nullptr;
        ll->tail= nullptr;
        free(tmp);
        free(tmp2);
    }

    node* temp=ll->head;
    while(temp->next->next){
        temp=temp->next;

    }
    ll->tail=temp;

    free(temp->next);
}
void DeleteNode(node* s){
    s->data=0;
    s->next=NULL;

}
int gethead(linkedlist* ll){
    printf("the head is: ");
    return ll->head->data;
}
int gettail(linkedlist* ll){
    if (ll->tail){
        printf("the tail is: ");
        return ll->tail->data;


    }
    else {
        printf("list is empty\n");
    }
}


void PrintLinkedlist(linkedlist* ll){
    if (ll->head!= nullptr){
        node* temp=ll->head;
        while(temp){
            printf("%d\n",temp->data);
            temp=(node*)temp->next;

        }
        //cout << temp->data<< endl;
    }
    else
        cout << "invalid List name"<< endl;
}




int main (int argc,char** argv){
    linkedlist ll;

    initLinkedlist(&ll);
    cout << "hei"<< endl;

    addBegining(&ll,3);
    //PrintLinkedlist(&ll);
    addBegining(&ll,4);
   // PrintLinkedlist(&ll);
    addBegining(&ll,88);
    addLast(&ll,555);

    PrintLinkedlist(&ll);
    int headd=gethead(&ll);
    cout << headd<< endl;
    printf("\n");
    int taill=gettail(&ll);
    cout << taill<< endl;
    printf("\n");
    DeleteBegining(&ll);
     headd=gethead(&ll);
    cout << headd<< endl;
    printf("\n");
   taill=gettail(&ll);
    cout << taill<< endl;
    printf("\n");
    DeleteEnd(&ll);
    headd=gethead(&ll);
    cout << headd<< endl;
    printf("\n");
    taill=gettail(&ll);
    cout << taill<< endl;
    printf("\n");


    return 0;}
