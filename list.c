#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node *next;

};
void add(struct Node *n,int data){
    struct Node *ptr,*new_node;
    new_node = malloc(sizeof(struct Node));
    ptr = n;
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    new_node->data = data;
    new_node->next = NULL;
    ptr->next = new_node;
}
void printListAge(struct Node *n){
    struct Node *ptr;
    ptr = n;
    while(ptr != NULL){
        printf("[%d]->",ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}
void sortAsd(struct Node *n){
    struct Node *iMin,*j,*i;
    int temp;
    j = n;
    while(j != NULL){
        i = j->next;
        iMin = j;
        while(i != NULL){
            if(i->data<iMin->data){
                iMin = i;
            }
            i = i->next;
        }
        temp = iMin->data;
        iMin->data = j->data;
        j->data = temp;
        j = j->next;
    }
}
void sortDesc(struct Node *n){
    struct Node *j,*i,*iMax;
    j = n;
    while(j != NULL){
        i = j->next;
        iMax = j;
        while(i != NULL){
            if(i->data>iMax->data){
                iMax = i;
            }
            i = i->next;
        }
        int temp = iMax->data;
        iMax->data = j->data;
        j->data = temp;
        j = j->next;
    }
}
int isEmpty(struct Node *n){
    struct Node *ptr;
    ptr = n;
    while(ptr != NULL){
        return 1;
    }
    return 0;
}
int length(struct Node *n){
    struct Node *ptr;
    ptr = n;
    int cpt = 0;
    while(ptr != NULL){
        cpt += 1;
        ptr = ptr->next;
    }
    return cpt;
}
struct Node *insertFirst(struct Node *n,int data){
    struct Node *new_node = malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = n;
    n = new_node;
    return n;
}
void reverse(struct Node *n){
    struct Node *ptr,*j;
    ptr =n;
    while(ptr!=NULL){
        j = ptr->next;
        while(j!=NULL){
            int temp = j->data;
            j->data = ptr->data;
            ptr->data = temp;
            j = j->next;
        }
        ptr = ptr->next;
    }
}
int find(struct Node *n,int data){
    struct Node *ptr;
    ptr = n;
    while(ptr!=NULL){
        if(ptr->data==data){
            return 1;
        }
        ptr = ptr->next;
    }
    return 0;
}
struct Node *deleteFirst(struct Node *n){
    struct Node *temp;
    temp = n->next;
    n = temp;
}
int main(){
    struct Node *L = malloc(sizeof(struct Node));
    L->data = 10;
    L->next = NULL;
    add(L,34);
    add(L,10);
    add(L,1);
    printListAge(L);
    if(find(L,1)==1){
        printf(" true ");
    }
    sortAsd(L);
    printListAge(L);
    sortDesc(L);
    printListAge(L);
    reverse(L);
    printListAge(L);
    printf("\n%d",length(L));
    return 0;
}