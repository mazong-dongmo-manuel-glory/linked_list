#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node *next;
};
class List{
    public:
    Node *head;
    int _length;
    init(int data){
        head = new Node();
        head->data = data;
        head->next = NULL;
        _length = 1;
    }
    void add(int data){
        Node *ptr,*new_node;
        ptr = head;
        while(ptr->next != NULL){
            ptr = ptr->next;
        }
        new_node = new Node();
        new_node->data = data;
        new_node->next = NULL;
        ptr->next=new_node;
        _length += 1;
    }
    void print(){
        Node *ptr;
        ptr = head;
        while(ptr != NULL){
            cout << "[" << ptr->data << "]->";
            ptr = ptr->next;
        }
        cout << " ";
    }
    void insertstart(int data){
        Node *ptr = head;
        Node *new_node = new Node();
        new_node->data = data;
        new_node->next = ptr;
        head = new_node;
        _length += 1;
    }
    void sortAsc(){
        Node *ptr,*iMin,*i,*j;
        i = head;
        while(i != NULL){
            j = i->next;
            iMin = i;
            while(j != NULL){
                if(j->data<iMin->data){
                    iMin =j;
                }
                j = j->next;
            }
            int temp = iMin->data;
            iMin->data = i->data;
            i->data = temp;
            i = i->next;
        }
    }
    void sortDesc(){
        Node *ptr,*iMax,*i,*j;
        i = head;
        while(i != NULL){
            j = i->next;
            iMax = i;
            while(j != NULL){
                if(j->data>iMax->data){
                    iMax =j;
                }
                j = j->next;
            }
            int temp = iMax->data;
            iMax->data = i->data;
            i->data = temp;
            i = i->next;
        }
    }
    bool isEmpy(){
        return head != NULL ? true:false;
    }
    void deleteFirst(){
        if(head->next != NULL){
            Node *ptr = head->next;
            delete head;
            head = ptr;
            _length -= 1;
        }
    }
    void reverse(){
        Node *j,*ptr; 
        ptr = head;
        while(ptr != NULL){
            j = ptr->next;
            while(j != NULL){
                int temp = j->data;
                j->data = ptr->data;
                ptr->data = temp;
                j = j->next;
            }
            ptr = ptr->next;
        }

    }
    int length(){
        return _length;
    }
};

int main(){
    List l = List();
    l.init(0);
    l.add(2);
    l.add(3);
    l.add(4);
    l.add(5);
    l.add(6);
    l.add(7);
    l.print();
    cout<<endl;
    l.reverse();
    l.print();
    cout<<endl;
    l.sortDesc();
    l.print();
    cout << endl;
    cout << l.isEmpy();
    return 0;
}