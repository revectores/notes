/* This file illustrates the method of construct new linked list. */
#include <stdio.h>
#include <stdlib.h>


//  Define the structure of node of the linked list with two fields included, `data` and `next`, the `next` field stores the pointer pointed to the next node of the linked list.
struct node{
    char data;
    struct node* next;
};



//  Since we usually get the handle of some node by the the `next` field of its previous, in the most cases we'll manipulate the `Node` strucutre by the pointer to `Node`, thus, we access the `data` and `next` by node->data, node->next.
typedef struct node Node;
typedef Node* Node_ptr;
const int Node_size = sizeof(Node);


// To avoid some problems caused by the operations assoicated with the first element, we'll add an special empty element called `head` in most cases, as the result, the actual meaningful first element is the next element of `head` element.
// The structure of `head` is the same as normal element, and the data field of `head` is customarily set as an meaningless value which won't occur in the normal data. e.g. set 0 in a linked list whose data fields are guaranteed to be positive.
// This feature(speciality of data field) allows `head` play some more important role:marked the "start" of the refined linked list structure like circular linked list. In this case if the `head` with special data field is not provided, it's not possible for a program to tell weather it reach the beginning of linked list.
Node_ptr new_linked_list(int num){
    Node_ptr head = malloc(Node_size);
    head->data = 0;
    
    Node_ptr cur_node = head;
    
    for(int i=0; i<num; i++){
        Node_ptr new_node = malloc(Node_size);
        scanf("%c", &(new_node->data));
        
        cur_node->next = new_node;
        cur_node = new_node;
    }
    cur_node->next = NULL;
    
    return head;
}


void repr_linked_list(Node_ptr head){
    Node_ptr cur_node = head;
    while(cur_node != NULL){
        printf("%c", cur_node->data);
        cur_node = cur_node->next;
    }
};


int main(){
    int num;
    scanf("%d ", &num);
    
    Node_ptr head = new_linked_list(num);
    repr_linked_list(head);
    
    return 0;
}

