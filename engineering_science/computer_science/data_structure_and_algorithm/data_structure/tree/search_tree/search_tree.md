### 1. General Binary Search Tree

##### # Defintion

A binary search tree is a binary tree that fits: for any given node, all the values of the nodes in left subtree is less than the value of it, and all the values of the nodes in right subtree is larger than the value of it. By constructing a binary tree like this, we'll be able to search a value by $O(\log n)$. We'll demonstrate how to do the operation of `find`, `insert` and `delete`, and analyse the time complex of these operations.




##### # Implementation

The idea of finding an element in a BST is quite simple that, you compare the value you want to search with the data of current node, if the value is smaller, go to the left subtree, instead if the value is larger, go to the right subtree. If the value is exactly the data of root, we'll say we find the node we want and return it.

The process about `NULL` pointer can be tricky and important, when the input node is `NULL`, since it's a recursive program, usually it traverse a long distance to here, and finally find out there's no way to go, in this case we return a `NULL` pointer which indicates that the required value is not found in out tree.

```c
Node_ptr find(Node_ptr root, int value){
	if(root == NULL) return NULL;	
	if(root->data > value) return find(root->left, value);
	if(root->data < value) return find(root->right, value);
	return root;
}
```

Finding the maximum and minimum value can be easily implemented by keep searching the right or left child until there's none:

```c
Node_ptr find_min(Node_ptr root){
	if(root == NULL) return NULL;
	if(root->left_child == NULL) return root;
	return find_min(root->left_child);
}
```

```c
Node_ptr find_max(Node_ptr root){
	if(root == NULL) return NULL;
	if(root->right_child == NULL) return root;
	return find_max(root->right_child);
}
```

The `insert` process is similar as the `find` function, while in this case, when we traversal into a `NULL` node, which means that's the position the value should be placed, so we'll create a new node and do the insertion by return it, and in the upper layer the child will be assigend.

```c
Node_ptr insert(Node_ptr root, int value){
	if(root == NULL){
		Node_ptr new_node = malloc(sizeof(Node));
		new_node->data = value;
		new_node->left_child = new_node->right_child = NULL;
		return root;
	}
	
	if(root->data > value)
		return root->left_child = insert(root->left_child, value);

	if(root->data < value)
		return root->right_child = insert(root->right_child, value);

	return root;
}
```

Finally the most complex operation is the deletion, we need to keep the BST still a BST after the deletion of nodes, multiple strategy can be applied for this propose, and many of them leads to more complicate tree structure. We'll introduce a simple one.

If the deleted node is the leave node, no adjustment is required; if it contains only one child, left or the right but not both, then we only need to replace the deleted node usingn its subnode.

The most complicate case is the deleted node contains both children, in this case we'll pick **the smallest one in the right subtree** as the replacement, and delete that picked one recursively. The recursive is in fact not so recursive: since the node we pick up is the smallest one in the right subtree, so there's no left-child of it, in this case, as mentioned above, add the "recursive" delete need to do is to raise the right child once.

The implementation based on the idea above:

```c
Node_ptr delete(Node_ptr root, int value){
	if(root == NULL) return NULL;
	if(root->data > value)
		return root->left_child = delete(root->left_child, value);
	if(root->data < value)
		return root->right_child = delete(root->right_child, value);

	if(root->data == value){
		if(root->left_child && root->right_child){
			Node_ptr right_min = find_min(root->right_child);
			root->data = right_min->data;
			root->right_child = delete(root->right_child, right_min->value);
		} else {
			Node_ptr src_space = root;
			if(root->left_child)  		root = root->left_child;
			else if(root->right_child) 	root = root->right_child;
			else root = NULL;	
			free(src_space);
		}
	}
}
```

The complete and executable demo with manually constructed tree is shown as `BinarySearchTree.c`.




##### # Complexity Analysis

Ideally, if the tree is balanced, i.e. the left subtree and the right subtree share almost the same nodes, then the query, insert and delete operation only requires $O(\log N)$. While in practice during the insertion and deletion the tree can be unbalanced, and even degenerates to the linked list, in which case the advantage of tree is no longer maintained and the time complexity will arise to $O(n)$.

To solve this problem, seversal limited tree structures are proposed, which limit the tree with given balance condition, which requires additional operations after the insertion and deletion to keep the given condition so the tree **balances itself**. We'll introduce three typical types of tree of them: AVL tree, B-tree and splay tree.






### 2. AVL Tree

As mentioned before, AVL Tree is a self-balanced binary serach tree. To introduce the limitation added to AVL tree, we'll define the balance rate of a tree first.

The balance rate of a node is defined as the height difference of the left subtree and the right subtree, notice that this is a number with sign, it's positive when the left subtree is higher. We define a tree is balanced, if the absoluate value of balance rate of all nodes are less or equal than 1.







