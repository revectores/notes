# Graph

The definition and basic concept of graph is disscussed in DiscreteMathematics, we only introduce the implementation of algorithm of graph.


### 1. Representation

There're two approaches to represent a graph in computer: adjacent matrix or adjacent table. The adjacent matrix representation is already discussed in DisreteMathematrix so we'll omit the details, when there're lots of nodes but few edges, or adjacent matrix is so-called sparse, the space loss of matrix matrix will be undorable. In this case the adjacent table is introduced.

The main structure of a adjacent table is an array, and the element of the array is a header of a linked list, which represents all the nodes that the element connnected to (or in directed case, points to). i.e. for the adjacent matrix

$$
1 1 0
1 1 1
0 1 0
$$ 

The correspondent adjacent table can be represented as

```
1 [1]->[2]
2 [1]->[2]->[3]
3 [2]
```

The conversion is implemented in ``.



### 2. Traverse

Two method included for traverse among a graph: **Deep First Searching (DFS)** and **Breadth First Searching (BFS)**. The idea of DFS is to keep going to some other points based on the current step until there's no where to go, persicely, no node is connected to current node, or all the nodes connected to it are already visited, in this case we're go back and find whether the upper node have some other way out. This seems difficult but easy to implement by recursion(or manually maintaining a stack).

```c
bool adj_mat[NODE_NUM][NODE_NUM];
bool visited[NODE_NUM];

void dfs(int node){
	visited[node] = true;
	printf("%d", node);
	for(int i=0; i < NODE_NUM; i++)
		if(i != node && !visited[i] && adj_mat[node][i])
			dfs[i];
}
```

By maintaining a global visited mark array visited[], we hide the traceback process in the recursion. When the program reaches one node and there's no where to go, the statement of for-loop will not be executed and the program will go to the upper level to countinue searching.

Another way to traverse the graph is BFS. As a matter of fact, the level-order traversal from the root of tree IS EXACTLY BFS of graph, since tree is actually a special grap, since tree is actually a special graph. We build a quque to store the nodes and enqueue all the connectives when a node dequeues:

```c
bool adj_mat[NODE_NUM][NODE_NUM];
bool visited[NODE_NUM];

void bfs(int node){
	int queue[NODE_NUM];
	int head = 0;
	int tail = 0;	
	
	queue[tail++] = node;
	visited[head] = true;	

	while(head < tail){
		head_node = queue[head++];
		
		for(int i=0; i<NODE_NUM; i++){
			if(adj_mat[node][i] && !visited[i]){
				visited[i] = true;
				printf("%d", i);
				queue[tail++] = i;
			}
		}
}
```

The only differenece from level-traversal of tree is that we're required to record a `vistsed[]` mark array in case we traverse a node twice.

The implementation under the adjacent table is similar.






### Shortest Path

##### # Introduction

In the weighted graph, an significant problem is to find out a path with the minimum cost between two nodes, i.e. if the map represents a road-map in the real world, then we usually want to find out the shortest path between two locations. Or, if the map represents a router-map in the network, then we want to find out which pathway has the shortest time-delay.

In this chapter we introduce four classical design of shortest-path algorithm: Dijkstra, Floyd, Bellman-Ford and SPFA as a improvement of it.



##### # Single Source Shortest Path: Dijkstra Algorithm

The dijkstra algorithm is used to find out the shortest path from a specific source node to all the other nodes in the graph.

The core idea of dijkstra is maintaining a distance list and keep selecting the shortest path as the potential midnode to update the distance list, until all the nodes are selected as the midnode. To illustrate this idea intuitively, consider about the simple map following:

```map
 [0]      [1]
  | \    / |
  |  10 /  |
  |   \/   |
  2   /\   1
  |  /  \  |
  | 10   \ |
  |/      \|
 [3]--5---[2]

```

Consider we set node0 as the source, wanting to know the shortest path from node0 to node `1,2,3`. First we initialize the distance array with the cost from source node:

```c
dist[] = {0, +inf, 10, 2};
```

Notice that since there's no pathway from node `0` to node `1`, so we consider the cost between them as infinity, in practice this should be set as a large number such as `INT_MAX`.

Now we check: which node is the nearest to the source, and haven't been selected now? Since we haven't trace any nodes(besides the source itself), the neartest, node `3` with distance `2` is the answer, so we pick it, use it as our first midnode to update our list:

```c
dist[] = {0, 12, 7, 2};
```

As noticed, we reached a tremendous progress by doing this. By checking if other nodes can be reached with lower cost through the new middle node, we made the unreachable node reachable, and the cost of reaching node2 is reduced from 10 to 7.

Then we select the next minimum after we update, remember that node3 is no longer considerable since it is already considered as the midnode, so we'll pick node2, and update the `dist[]` array:

```c
dist[] = {0, 8, 7, 2};
```

Notice that we update the dist to node1 again but the others are leaves as they are, since the distance to node `0, 3, 2` are already the shortest.

Why selecting the nearest node, instead any other, and why this approach must reach the shortest when the algorithm is finished? As we processed above, the nearest node must has been best optimized, i.e. we confirm that there're no other way which could provides a shorter path to the nearest destination. By confirming this, what we're updating is exactly the minimum when we considering this node as middle.

Since the nearest node is no longer update, the dijkstra algorithm cannot process the graphes with negative weights, in this case the Bellman-Ford Algorithm is proposed.

We implement dijkstra algorithm using C as following. 

```c
const int MAX_DIST = 999999;
int cost[NODE_NUM][NODE_NUM];
int dist[NODE_NUM];
int middles[NODE_NUM];


int find_nearest(){
	int nearest_node = -1;
	int shortest_dist = MAX_DIST;	

	for(int i=0; i<NODE_NUM; i++){
		if(!middles[i] && dist[i] < shortest_dist){
			nearest_node = i;
			shortest_dist = dist[i];
		}			
	}
}

void dijkstra(int src){
	for(int i=0; i<NODE_NUM; i++) dist[i] = MAX_DIST;
	dist[src] = 0;
	int nearest;

	int new_dist;
	while((nearest = find_nearest()) != -1)
		for(int i=0; i<NODE_NUM; i++)
			if((new_dist = dist[nearest] + cost[nearest][i]) < dist[i])
				dist[i] = new_dist;
}
```

Notice that during this progress, once one node is considered as the shortest, the distance of it is determined and will never be updated later, so if you only want to find out the shortest path from source to one node, you can stop it here to reduce the unnecessary process.

The complexity of dijkstra algorithm is $O(n^2)$, and if you want to find out the shortest path from all nodes to all nodes, you can simply apply dijkstra by all possible sources, and the complexity will be $O(n^3)$. Floyd algorithm, which will be introduced in the next section, using a similar perspective to get all shortest path with the same time complexity.




##### # All to All: Floyd Algorithm

Floyd algorithm use a similar perspective like dijkstra considering appending new avaliabe middle node for all source-destination.

```c
int cost[NODE_NUM][NODE_NUM];
int dist[NODE_NUM][NODE_NUM];

void floyd(){
	for(int src=0; src<NODE_NUM; src++)
		for(int tar=0; tar<NODE_NUM; tar++)
			dist[src][tar] = cost[src][tar];

	for(int mid=0; mid<NODE_NUM; mid++)
		for(int src=0; src<NODE_NUM; src++)
			for(int tar=0; tar<NODE_NUM; tar++)
				if(dist[src][mid] + dist[mid][tar] < dist[src][tar])
					dist[src][tar] = dist[src][mid] + dist[mid][tar];
}
```

The process progress of floyd algorithm can be described like this: Frist, we do not allow any nodes to be the middle node, so we initialize the `dist[][]` array exactly as `cost[][]` array. Then we allow the node `0, 1, 2, ..., NODE_NUM-1`, one by one, to be the middle node, and check whether this appending makes some nodes-pair more easily to arrive. After appending all the nodes as the middle nodes, we get the shortest path of all pairs. 




##### # Bellman-Floyd Algorithm




##### # SPFA






