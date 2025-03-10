#include <stdio.h>

struct node {
    char data;
    struct node* prev;
    struct node* next;
};
typedef struct node Node;
typedef Node* Node_ptr;
const int NODE_SIZE = sizeof(Node);


Node_ptr new_node(char data);
Node_ptr new_dllist(char datas[], int length);
Node_ptr repr(Node_ptr head);
Node_ptr find(Node_ptr head, char v);
Node_ptr insert(Node_ptr head, char insert_after, char inserted_value);
Node_ptr delete(Node_ptr head char);



int main(int argc, const char * argv[]) {
    char datas[5] = {'1','2','3','4','5'};
    Node_ptr dllist = new_dllist(datas, 5);
    repr(dllist);
    
    // Test case for ddlist structure.
    Node_ptr node2 = find(dllist, '2');
    printf("%c", node2->prev->next->prev->data); printf("\n");
    
    
    // Test case for insertion.
    
    return 0;
}



Node_ptr new_node(char data){
    Node_ptr node = malloc(NODE_SIZE);
    node->data = data;
    return node;
}


Node_ptr new_dllist(char datas[], int length){
    Node_ptr head = new_node(0);
    head->prev = NULL;
    head->next = NULL;
    
    Node_ptr cur = head;
    
    for(int i=0; i<length; i++){
        Node_ptr suc_node = new_node(datas[i]);
        suc_node->next = NULL;
        
        cur->next = suc_node;
        suc_node->prev = cur;
        
        cur = cur->next;
    }
    
    return head;
}


void repr(Node_ptr head){
    Node_ptr cur = head;
    
    while(cur != NULL){
        if(!cur->data) printf("\\0 ");
        else printf("%c ", cur->data);
        cur = cur->next;
    }
    
    printf("\n");
}


Node_ptr find(Node_ptr head, char v){
    Node_ptr cur = head;
    
    while(cur!=NULL){
        if(cur->data == v) return cur;
        cur = cur->next;
    }
    
    return NULL;
}
