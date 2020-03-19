#include <stdio.h>
#include <stdlib.h>
#define MAX 100

struct node {
    char data;
    struct node* next;
};
typedef struct node Node;
typedef Node* Node_ptr;
typedef int* int_ptr;

const int node_size = sizeof(Node);


// Node constructor
Node_ptr new_node(char data){
    Node_ptr node = (Node_ptr) malloc(node_size);
    node->data = data;
    return node;
}


// Initialize a linked list.
Node_ptr new_linked_list(int data_src[], int length){
    Node_ptr head = new_node(0);
    
    Node_ptr cur = head;
    
    for(int i=0; i<length; i++){
        Node_ptr suc_node = new_node(data_src[i]);
        cur->next = suc_node;
        cur = cur->next;
    }
    
    cur->next = NULL;
    
    return head;
}


// print all the elements of a linked list.
void repr(Node_ptr head){
    Node_ptr cur = head;
    
    while(cur != NULL){
        cur->data ? printf("%c ", cur->data) : printf("\\0 ");
        cur = cur->next;
    }
}


// search specific data v in linked list, if not found, return NULL pointer.
Node_ptr search(Node_ptr head, char v){
    Node_ptr cur = head;
    
    while(cur != NULL){
        if(cur->data == v) return cur;
        cur = cur->next;
    }
    
    return NULL;
}


// Insert value after a specific value(first occurance).
// Why not implement inserting value after a specific subscript? Go using your array XD.
// return 0 if insert operation succeeded.
int insert_after(Node_ptr head, char inserted_after, char inserted_value){
    Node_ptr cur_node = search(head, inserted_after);
    Node_ptr suc_node = cur_node -> next;
    
    Node_ptr inserted_node = new_node(inserted_value);
    
    cur_node->next = inserted_node;
    inserted_node->next = suc_node;
    
    return 0;
}


// Insert value before a specific value(first occurance).
int insert_before(Node_ptr head, char inserted_before, char inserted_value){
    Node_ptr pre_node = head;
    Node_ptr cur = head->next;
    
    while(cur != NULL){
        if(cur->data == inserted_before){
            Node_ptr inserted_node = new_node(inserted_value);
            
            pre_node->next = inserted_node;
            inserted_node->next = cur;
            return 0;
        }
        pre_node = cur;
        cur = cur->next;
    }
    
    return -1;
}


// Another implementation of insert before using helper function `find_precedent`.
// int insert_before_v2(Node_ptr head, char inserted_before, char inserted_value)


// Delete a specific value(first occurance).
int delete(Node_ptr head, char deleted_value){
    Node_ptr pre_node = head;
    Node_ptr cur = head->next;
    
    while(cur != NULL){
        if(cur->data == deleted_value){
            pre_node->next = cur->next;
            free(cur);
            return 0;
        }
        pre_node = cur;
        cur = cur->next;
    }
    
    return -1;
}


void join(Node_ptr head1, Node_ptr head2){
    Node_ptr cur = head1;
    
    while(cur->next != NULL) cur = cur->next;
    cur->next = head2->next;
}


int main(int argc, const char * argv[]) {
    int data_src[MAX] = {'a','b','c','d','e'}; int length = 5;
    Node_ptr head = new_linked_list(data_src, length);
    repr(head); printf("\n");
    
    // Test case for search operation.
    Node_ptr c_node = search(head, 'c');
    printf("%c\n", c_node->data);

    // Test case for insert_after operation.
    insert_after(head, 'c', 'v');
    repr(head); printf("\n");
    
    // Test case for insert_before operation.
    insert_before(head, 'v', 'm');
    repr(head); printf("\n");

    // Test case for delete operation.
    delete(head, 'm');
    repr(head); printf("\n");
    delete(head, 'v');
    repr(head); printf("\n");
    
    // Test case for join operation.
    int data_src2[MAX] = {'f', 'g'}; int length2 = 2;
    Node_ptr head2 = new_linked_list(data_src2, length2);
    join(head, head2);
    repr(head); printf("\n");
    
    return 0;
}
