# Tree

### 1. Tree Data Structure

##### # Basic Concepts

A **Tree** is a set constructs from multiple nodes, which satisifies:

1. A Tree has a special node called **Root Node**.
2. All other nodes can be divided into multiple individual finite set, which are all trees individually, and named as the **SubTree** of integral tree.

The maxmium number of children a node have called the **Degree** of a tree.

The cluster of trees is called **Forest**.

The tree structure is extremely useful data representation in computer science, as also other domains. The most common tree structure is the dictionary tree in computer, we use this to organize our files to keep them in order. The content of a book can be also modeled as a tree, the sections are the subnodes of chapters. 



##### # Representation of Tree

Based on the structure of trees, all we need to store are the nodes and the `parent-child` relationship between nodes. There're two approaches to accomplish this:

1. For each node, store all its children. This is called as the **Standard Form** of Tree.
2. For each node, store its parent. This is named as the **Reversed Form** of Tree.

It's trivial to prove that all the information will be preserved in this two storage stragey. Standard Form is easy to get the childrens of node in $O(1)$ complexity, but have to implement an search algorithm to find the parent. The Reversed Form is on the contrary. To avoid the searching process, we can also combine the two approach, which is named as the **Extended Standard Form** of Tree.

All these three form must keep a special pointer pointed to the root of tree, otherwise we can't identify and find tree at all. Now we implement these three approaches through C language, for conciseness we assume the data stored in the node is `char`, and set the degree as 3.

```c
# define DEGREE 3

// Standard Form of Tree
struct node {
    char data;
    struct node* child[DEGREE];
}

typedef struct node Node;
Node* root;
```

```c
// Reversed Form of Tree
struct node {
    char data;
    struct node* parent;
}

typedef struct node Node;
Node* root;
```

```c
// Extended Standard Form of Tree
struct node {
    char data;
    struct node* child[DEGREE];
    struct node* parent;
}

typedef struct node Node;
Node* root;
```

In the standard or extended form of represetation, iof one node has $s < K$ subnodes, the rightmost $K - s$ nodes are leaved as `NULL` pointer. We can use this property to find out how many children a node has.

This concludes three main representations of tree: standard form, reverse form, and extended standard form.



##### # Linear Storage of Tree

The three representation of tree can be easily expressed and understanded by the computer, but it's hard to construct a tree from input by manual through this way, which required we link each node to its parent(child) by hard code.

Like the index-representation of linked list, we can also use the index to play to role of pointer. Practically, we use an array of `struct index_node` to represents a tree, and the element of the array represents a node, constructed by two fields: `data` and `parent_index`:

```c
struct index_node{
	char data;
	int parent_index;
}
typedef struct index_node IndexNode;
```

i.e. Given the tree following:

```tree
    A
   / \
  B   C
 / \   \
D   E   F
```

The parent_index field of the correspondent array is `index_node_array = {-1, 0, 0, 1, 1, 2}`, where we set the parent_index of root node as -1. 'B', 'C' are both the child of 'A', whose index is 0, so the value of `index_node_array[1]` and `index_node_array[2]` are both 0, and the same as the following values.

Plus, if we want to access the children more easily, we can also included another field `Node_ptr children_index[3]` to stored the indexes of children.

We can construct the extended standard representation from this liner representation, the code is avaliabe in `tree_structure.c`

Normally in this expression we list the parent-index increamentally, by which the nodes in the array fit the order of level travseral.



##### # Represent Set By Tree

If we ignore the relations between parent-child in a tree, it's a good representation carrier of set. E.G. the set $\{0,6,7,8\}$ can be expressed as differenet trees, since the specific relation is omitted:

==TODO: Insert sets representation trees here.==

The operations of set is now reduced as the operation on tree. We focus on two operations here:

1. Union Of Set.
2. Element Search (From a tree-represented set forest, find out which tree contains the given specific element).

The union calculation between sets is quite trivial, the only operation we have to do is to repoint the root node of one tree to **any node** of another tree, since the relation is never matter. To reduce the depth of tree that represents the merged set, and keep conciseness and simplity, we usually repoint one root into **another root**, since a tree is always passed based on the root node:

```c
void union(Node* rootA, Node* rootB){
	rootB -> parent = rootA;
}
```

==TODO: finish the element search part==

This concludes that how to represent set through tree structure, as long as the design of union and element search operation in this implementation.







### 2. Iteration Algorithms

##### # Classification

Tree is a type of non-linear data structure, which causes that the implementation of its traversal can be complex and tricky. Three approaches are introduced for this target.

As we know the tree structure is defined by recursion, the natural way of iteration is also the recursive approach: **Preorder Traversal** and **Postorder Traversal**. An non-recursive method, **Level Order Traversal** is also introduced.

1. **Pre-Order Traversal**. Access the root of tree first, then access each subtree connected to the root by Preorder Traversal also.
2. **Post-Order Traversal**. Access those subtrees connected to root by Postorder Traversal also, then access the root of tree in the last.
3. **Level-Order Traversal**. Access elements level by level.

We're going to introduce the implementation of these three methods detailedly.



##### # Pre-Order and Post-Order Traversal

```c
/* Recursive Implementation */
void preorder_traversal(Node_ptr root){
    if(root == NULL) return;
    printf(root->data);
    for(int i=0; i<DEGREE; i++)
		preorder_traversal(root->child[i]);
}
```

And the post-order travseral is almost the same, the only change we need to make is to adjust the sequence of print and iterate children:

```c
void postorder_travseral(Node_ptr root){
	if(root == NULL) return;
	for(int i=0; i<DEGREE; i++)
		postorder_travseral(root->child[i]);
	printf(root->data);
}
```

As we know the bottom implementation of recursion is the stack of functions' call. We can also create and control the "stack" manually. Here we re-implement the `preorder_travseral` function as example:

```c
/* Non-Recursive(Stack) Implementation */
void preorder_travseral_stack(Node_ptr root){
	Node_ptr stack[NODE_NUM];
	int top = 0;   // top points to the upper index of the real top element.
	
	stack[top] = root;
	top++;

	while(top > 0){
		Node_ptr pop_node = stack[top-1];
		top--;
		printf("%c", pop_node->data);

		Node_ptr child;
		for(int i=DEGREE-1; i>=0; i--)
			if((child = pop_node->children[i]) != NULL)
				stack[top++] = child;
	}
}
```

Notice that we use a backward for loop to make the subnode push from the right to the left, since the property of stack when print out it'll be from left to right.



##### # Level-Order Traversal

We can implement the level-order traversal by buliding a queue, first inqueue the root node into the queue, and then keep dequeue the first element then enqueue all its children, loop this process until the queue is empty.

```c
void levelorder_traversal(Node_ptr root){
	Node_ptr queue[NODE_NUM];
	Node_ptr child;
	int head = 0;
	int tail = 0;

	queue[head] = root;
	tail++;

	while(head < tail){
		printf("%c", queue[head]->data);
	
		int i = 0;
		while((child = queue[head]->children[i++]) != NULL)
			queue[tail++] = child;
		head++;
	}
}	
```

By implement a queue, we can make sure that the children of node will not be first print out before the node itself, which is, promise that it's travseral level-by-level. Besides, if the children are stored in order, then they will be ordered in the final results.

The codes of implementation of iteration is also avaliable in the `tree_structrue.c` file.






### 3. Binary Tree

##### # Basic Concept 

Binary tree is a tree with degree 2. Since there're at most 2 children a node has, we usually one in the left and another one in the right, and they're so-called left-child and right-child.



##### # Classification

We introduce three different types of binary tree here:

- A **Perfect Binary Tree** is the binary tree that each non-leave node has two children, and all the leaves are at the same level. It's the most dense tree, every location is filled. A perfect binary tree with height `h` must got $2^(h+1)-1$ nodes.

- A **Complete Binary Tree** is a binary tree that every level is filled possibly expect the last level, and the leave nodes in the last level must be as left as possible.

- A **Full Binary Tree** is a binary tree that each node has two children.

Apparently, inclusion relation exists in these three types:

Full Tree < Complete Tree < Perfect Tree




##### # Conversion

Any tree can be converted to a binary tree. The method is describe as two principle:

1. The brother node place in the right-subtree.

2. The subnode place in the left-subtree.

For example, given a tree with degree 3:

```tree
     A
   / | \
  B  E  F
 / \   / \
C   D G   H
```

Applied the first principle, B, E, F are the subnodes of A, so they should be place in the left subtree of A, while since A can only has one left-child, so we can pick any of them as the direct left-child, i.e. we pick B, and then since E, F is the brother node of B, they should be place as the right-subtree, we also pick anyone, like E, and F will become the right-child of E.

After a series of similar process, we got the correspondent binary tree:

```tree
		A
      /
     B
    /  \
   C    E
    \    \
     D    F
         /
        G
		 \
		  H	
```

Notice that since the root A has no brother node, the right subtree of A will always be empty, while if we're required to convert a forest to a binary tree, we should consider the roots from different trees as the brothers(shared a virtual root), in this case the right child will be the root of another tree.



##### # Traversal and Its Application

Since binary tree is the special case of normal tree, the three basic traversal method also apply to binary tree, the codes can be easily written by referring the general case. Besides, binary tree got a special travsal method called mid-order traversal, in this method we first travseral the left-child, then the node itself, and then the right-child:

```c
void binary_midorder_traversal(BNode_ptr root){
	if(root == NULL) return;
	binary_midorder_traversal(root->left_child);
	printf("%c", root->data);
	binary-midorder_traversal(root->right_child);
}
```

Again, since the definition of tree is recursive, many operations of tree can be also implemented by recursion function, and usually we can adjust the travseral algorithm to build useful function. Here we give two examples: tree copy and equivalence check.

```c
BNode_ptr binary_copy_tree(BNode_ptr root){
	if(root == NULL) return;
	BNode_ptr root_copy = malloc(sizeof(BNode));

	root_copy->data = root->data;
	root_copy->left_child = binary_copy_tree(root->left_child);
	root_copy->right_child = binary_copy_tree(root->right_child);	

	return root_copy
}
```

```c
#include <stdbool.h>

bool binary_tree_check_equiv(BNode_ptr root1, BNode_ptr root2){
	if(root1 == NULL && root2 == NULL) return true;
	if(root1 != NULL && root2 != NULL)
		return root1->data == root2->data
			&& binary_tree_check_equiv(root1->left_child, root2->left_child)
			&& binary_tree_check_equiv(root1->right_child, root2->right_child);
	return false;
}
```

This two implementation can be considered a adjustment of preorder travseral since we process the root node first. Change the order of expression makes it midorder or postorder.



##### # Sequence Storage of Binary Tree

We've mentioned a linear storage of general tree, which use a index-pointer to pointer the index where the parent stored, and also might included the children-index field. In binary-tree case, since there're only two children, we can build some more tricky and elegant strategy to build the linear stroage:

One of them is to place elements as the preorder sequence, so the left-child of each node is simple: if it exists, it must be the next element, we use a tag to mark whether a node has left-child, and add the information of the index of right-child for each node to make the right-child accessible. This approach can be even more simple that we achieve the right-child through saerching instead store the index. Both implementation and the conversion algorithm are avaliable in `tree_structure.c`.

At last, Another simple way to store a binary tree is to consider it as a complete binary tree. The empty children are considered virtual nodes. After doing filling, since there're no indent in the upper levels, we can use a number as the subscript to mark every location. i.e.

```tree
      A
     / \
    B   C
   /
  D
 /
E    
```

After filled:

```tree
        A
       / \
      /   \
     /     \
    B       C
   / \     / \
  D   X   X   X
 /     \
E       X
```

Notice that based on the definition of complete tree, we must fill all the nodes except the last level. Then we mark each location as the sequence of level-order(i.e. up-down and left-right):

```tree
        0
       / \
      /   \
     /     \
    1       2
   / \     / \
  3   4   5   6
 /     \
7       8
```

Now this binary tree can be stored in a sequence `binary_tree_array = {'A', 'B', 'C'. 'D', 'X', 'X', 'X', 'E', 'X'}`. No extra parent-child relation is required to store because they're implicit included in the index relation.

This approach is simple but quite space-wasting, especially when the tree is almost empty in each level. 








# 4. Threaded Tree

As notice, the





