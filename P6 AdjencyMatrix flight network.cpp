#include <iostream>
#include <queue>
using namespace std;

int adj_mat[50][50] = {0, 0};
int visited[50] = {0};

void dfs(int s, int n, string arr[])
{
    visited[s] = 1;
    cout << arr[s] << " ";
    for (int i = 0; i < n; i++)
    {
        if (adj_mat[s][i] && !visited[i])
            dfs(i, n, arr);

    }
}

void bfs(int s, int n, string arr[])
{
    bool visited[n];
    for (int i = 0; i < n; i++)
        visited[i] = false;
    int v;
    queue<int> bfsq;
    if (!visited[s])
    {
        cout << arr[s] << " ";
        bfsq.push(s);
        visited[s] = true;
        while (!bfsq.empty())
        {
            v = bfsq.front();
            for (int i = 0; i < n; i++)
            {
                if (adj_mat[v][i] && !visited[i])
                {
                    cout << arr[i] << " ";
                    visited[i] = true;
                    bfsq.push(i);
                }
            }
            bfsq.pop();
        }
    }
}

int main()
{
    cout << "Enter no. of cities: ";
    int n, u;
    cin >> n;
    string cities[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter city #" << i << " (Airport Code): ";
        cin >> cities[i];
    }

    cout << "\nYour cities are: " << endl;
    for (int i = 0; i < n; i++)
        cout << "city #" << i << ": " << cities[i] << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            cout << "Enter distance between " << cities[i] << " and " << cities[j] << " : ";
            cin >> adj_mat[i][j];
            adj_mat[j][i] = adj_mat[i][j];
        }
    }
    cout << endl;

    for (int i = 0; i < n; i++)
        cout << "\t\t" << cities[i] ;
    for (int i = 0; i < n; i++)
    {
        cout << "\n"<<cities[i];
        for (int j = 0; j < n; j++)
            cout << "\t" << adj_mat[i][j] << "\t";
        cout << endl;
    }
    cout << "Enter Starting Vertex: ";
    cin >> u;
    cout << "DFS: ";
    dfs(u, n, cities);
    cout << endl;
    cout << "BFS: ";
    bfs(u, n, cities);
    return 0;
}






































/*
Theory :

// 1. **Graph Representation**:
//   - A graph is a data structure consisting of a set of vertices (nodes) and a set of edges (connections between vertices).
//   - In computer science, graphs can be represented using adjacency matrices or adjacency lists.
//   - Adjacency matrix: A 2D array where the presence of an edge between two vertices is indicated by a non-zero value in the corresponding cell.
//   - Adjacency list: A collection of lists or arrays where each vertex maintains a list of adjacent vertices.

// 2. **Adjacency Matrix**:
//   - An adjacency matrix represents a graph as a square matrix where each row and column represent a vertex, and the presence of an edge between vertices is indicated by non-zero values.
//   - In the context of the problem statement, an adjacency matrix can be used to represent flight paths between cities, with the matrix cell containing the flight time or fuel amount.

// 3. **Adjacency List**:
//   - An adjacency list represents a graph as a collection of lists or arrays where each vertex maintains a list of its adjacent vertices.
//   - For the problem statement, an adjacency list can be used to represent flight paths between cities, with each city's list containing the destinations reachable from that city.

// 4. **Graph Connectivity**:
//   - A graph is connected if there is a path between every pair of vertices.
//   - Graph connectivity can be determined by traversing the graph using algorithms like DFS or BFS and checking if all vertices are reachable.
//   - In the problem statement, checking whether the flight network is connected ensures that there are no isolated cities without any flights.

// 5. **Depth-First Search (DFS)**:
//   - DFS is a graph traversal algorithm that explores as far as possible along each branch before backtracking.
//   - It can be implemented using recursion or a stack data structure.
//   - DFS can be used to check graph connectivity by visiting all reachable vertices from a starting vertex.

// 6. **Breadth-First Search (BFS)**:
//   - BFS is a graph traversal algorithm that explores all the neighbors of a vertex before moving on to the next level.
//   - It can be implemented using a queue data structure.
//   - BFS can also be used to check graph connectivity by visiting all reachable vertices from a starting vertex.

// 7. **Flight Network**:
//   - A flight network represents the routes between cities, where cities are represented as vertices and flight paths as edges.
//   - Representing the flight network as a graph allows for efficient traversal and analysis of flight connections between cities.

// 8. **Graph Traversal**:
//   - DFS and BFS traversal algorithms can be applied to the flight network graph to find flight paths between cities or determine connected components.
//   - These algorithms help in analyzing the connectivity and accessibility of cities within the flight network.

// 9. **Complexity Analysis**:
//   - The time complexity of DFS and BFS traversal algorithms is O(V + E), where V is the number of vertices and E is the number of edges.
//   - The space complexity depends on the implementation details, but typically it's O(V) for DFS and O(V) or O(V + E) for BFS.

// 10. **Optimization Techniques**:
//     - Optimization techniques such as memoization, pruning, or early termination can be applied to improve the performance of DFS and BFS algorithms.
//     - These optimizations can reduce redundant computations and improve the efficiency of graph traversal for large graphs or complex networks.



line by line explanation :

Here's the line-by-line explanation of the provided code:

1. `#include <iostream>`: This line includes the standard input-output stream header file for input-output operations.
2. `#include <queue>`: This line includes the queue header file for using the queue data structure.
3. `using namespace std;`: This line declares that elements of the standard C++ library are declared within the `std` namespace.
4. `int adj_mat[50][50] = {0, 0};`: This line declares a 2D array `adj_mat` of size 50x50 to represent the adjacency matrix for storing edge weights between cities. It initializes all elements to 0.
5. `int visited[50] = {0};`: This line declares an array `visited` of size 50 to mark visited cities during traversal. It initializes all elements to 0.
6. `void dfs(int s, int n, string arr[])`: This line defines a function `dfs` for depth-first search traversal. It takes the starting city index `s`, the total number of cities `n`, and an array `arr` containing city names as parameters.
7. `visited[s] = 1;`: This line marks the starting city `s` as visited.
8. `cout << arr[s] << " ";`: This line prints the name of the current city being visited.
9. `for (int i = 0; i < n; i++)`: This line starts a loop to traverse all cities.
10. `if (adj_mat[s][i] && !visited[i])`: This line checks if there is a direct edge from city `s` to city `i` and if city `i` is not already visited.
11. `dfs(i, n, arr);`: This line recursively calls the `dfs` function to visit the unvisited adjacent city `i`.
12. `void bfs(int s, int n, string arr[])`: This line defines a function `bfs` for breadth-first search traversal. It takes parameters similar to the `dfs` function.
13. `bool visited[n];`: This line declares a boolean array `visited` of size `n` to mark visited cities during BFS traversal.
14. `visited[i] = false;`: This line initializes all elements of the `visited` array to `false`.
15. `queue<int> bfsq;`: This line declares a queue `bfsq` to store cities for BFS traversal.
16. `if (!visited[s])`: This line checks if the starting city `s` is not already visited.
17. `cout << arr[s] << " ";`: This line prints the name of the starting city `s`.
18. `bfsq.push(s);`: This line pushes the starting city `s` into the queue.
19. `visited[s] = true;`: This line marks the starting city `s` as visited.
20. `while (!bfsq.empty())`: This line starts a loop until the queue is empty.
21. `v = bfsq.front();`: This line retrieves the front element of the queue.
22. `if (adj_mat[v][i] && !visited[i])`: This line checks if there is a direct edge from city `v` to city `i` and if city `i` is not already visited.
23. `bfsq.push(i);`: This line pushes the unvisited adjacent city `i` into the queue.
24. `bfsq.pop();`: This line removes the front element from the queue.
25. The rest of the code is for inputting city names, distances between cities, displaying the adjacency matrix, taking user input for the starting city, and calling the `dfs` and `bfs` functions to perform traversal.


Algorithm :

Here's the algorithm for the provided code:

1. **Input the Number of Cities and City Names:**
   - Prompt the user to input the number of cities.
   - Create an array `cities` to store the names of the cities.
   - Use a loop to input the names of the cities from the user.

2. **Input Distances Between Cities:**
   - Create an adjacency matrix `adj_mat` to store the distances between cities.
   - Use nested loops to input the distances between each pair of cities.
   - Prompt the user to input the distance between city `i` and city `j`, where `i` and `j` are the indices of the cities.

3. **Display the Adjacency Matrix:**
   - Output the adjacency matrix to display the distances between cities.

4. **Depth-First Search (DFS) Traversal:**
   - Implement the `dfs` function to perform depth-first search traversal.
   - Mark the starting city as visited.
   - Print the name of the starting city.
   - Recursively visit adjacent unvisited cities using DFS.

5. **Breadth-First Search (BFS) Traversal:**
   - Implement the `bfs` function to perform breadth-first search traversal.
   - Create a queue `bfsq` to store cities for BFS traversal.
   - Mark the starting city as visited and enqueue it.
   - While the queue is not empty, dequeue a city, print its name, and enqueue its unvisited adjacent cities.

6. **Main Function:**
   - Prompt the user to input the starting vertex for traversal.
   - Call the `dfs` function to perform DFS traversal and print the result.
   - Call the `bfs` function to perform BFS traversal and print the result.

7. **Output:**
   - Output the DFS traversal path and BFS traversal path.

This algorithm allows the user to input the number of cities, their names, and the distances between them. It then performs both depth-first search (DFS) and breadth-first search (BFS) traversals starting from a user-specified city and outputs the traversal paths.

*/
