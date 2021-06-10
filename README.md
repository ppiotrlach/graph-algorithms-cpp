# graph-algorithms-cpp

### Implementation of Prim (MST) and Bellman-Ford algorithms for 4th semester of IT studies

snippet:

```bash
SELECT THE NUMBER OF THE OPERATION YOU ARE INTERESTED IN
_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_

1. Read graph from file
2. Print weight graph and adjency list
3. MST - Prim's algorithm
4. Shortest Path - Bellman-Ford algorithm
5. End program

>1
1.Load own data
2.Load creator data (you can just edit graph.txt, its attached to the project)
>2
Graph loaded


SELECT THE NUMBER OF THE OPERATION YOU ARE INTERESTED IN
_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_

1. Read graph from file
2. Print weight graph and adjency list
3. MST - Prim's algorithm
4. Shortest Path - Bellman-Ford algorithm
5. End program

>2
Directed graph
-----------
Adjency list:
0 -> [1,5] -> [2,4] -> [3,2]
1 -> [3,3] -> [2,6]
2 -> [3,2] -> [4,2] -> [6,1]
3 -> [5,4]
4 -> [5,3]
5 -> [6,2]
6 -> 

Weight matrix:
i 5 4 2 i i i 
i i 6 3 i i i 
i i i 2 2 i 1 
i i i i i 4 i 
i i i i i 3 i 
i i i i i i 2 
i i i i i i i 


Undirected graph
-----------
Adjency list:
0 -> [1,5] -> [2,4] -> [3,2]
1 -> [0,5] -> [3,3] -> [2,6]
2 -> [0,4] -> [1,6] -> [3,2] -> [4,2] -> [6,1]
3 -> [0,2] -> [1,3] -> [2,2] -> [5,4]
4 -> [2,2] -> [5,3]
5 -> [3,4] -> [4,3] -> [6,2]
6 -> [2,1] -> [5,2]

Weight matrix:
i 5 4 2 i i i 
5 i 6 3 i i i 
4 6 i 2 2 i 1 
2 3 2 i i 4 i 
i i 2 i i 3 i 
i i i 4 3 i 2 
i i 1 i i 2 i 


SELECT THE NUMBER OF THE OPERATION YOU ARE INTERESTED IN
_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_

1. Read graph from file
2. Print weight graph and adjency list
3. MST - Prim's algorithm
4. Shortest Path - Bellman-Ford algorithm
5. End program

>4
1.Weight matrix
2.Adjency list
>1
Bellman-Ford algorithm - weight matrix
Path from source [0] to 
dest [0] : cost = 0 : path :  -> 0
dest [1] : cost = 5 : path :  -> 0 -> 1
dest [2] : cost = 4 : path :  -> 0 -> 2
dest [3] : cost = 2 : path :  -> 0 -> 3
dest [4] : cost = 6 : path :  -> 0 -> 2 -> 4
dest [5] : cost = 6 : path :  -> 0 -> 3 -> 5
dest [6] : cost = 5 : path :  -> 0 -> 2 -> 6


```
