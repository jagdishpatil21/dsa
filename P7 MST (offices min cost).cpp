#include <iostream>
#include <limits.h>
using namespace std;

class Office {
    int n;
    int adjacent[10][10];
    string office[10];

public:
    void input ();
    void display ();
    void Prims ();
};

void Office::input () {
    cout << "\nEnter no. of offices: ";
    cin >> n;
    cout << "\nEnter the names of offices: ";
    for (int i = 0 ; i < n ; i++)
        cin >> office[i];

    cout << "\nEnter the cost to connect the offices: \n";
    for (int i = 0 ; i < n ; i++)
        for (int j = i ; j < n ; j++) {
            if (i == j) {
                adjacent[i][j] = 0;
                continue;
            }

            cout << "Enter the cost to connect " << office[i] <<" and " << office[j]<< " : ";
            cin >> adjacent[i][j];
            adjacent[j][i] = adjacent[i][j];
        }
}

void Office::display () {

    for (int i = 0 ; i < n ; i++) {
        cout << "\n";
        for (int j = 0 ; j < n ; j++) {
            cout << adjacent[i][j] << "\t";
        }
   }
}

void Office::Prims () {
    int visit[n], minCost = 0, count = n - 1, minIndex, cost = 0;
    for (int i = 0 ; i < n ; i++)
        visit[i] = 0;

    cout << "\n\nShortest path: ";
    visit[0]=1;
    cout << office[0] << " -> ";

    while (count--) {
        minCost = INT_MAX;
        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < n ; j++) {
                if (visit[i] == 1 && adjacent[i][j] != 0 && adjacent[i][j] < minCost && visit[j] == 0) {
                    minCost = adjacent[i][j];
                    minIndex = j;
                }
            }
        }
        visit[minIndex]=1;
        cout << office[minIndex] << " -> ";
        cost = cost + minCost;
    }
    cout << "End";

    cout << "\nMinimum cost: "<<cost;

}

int main () {
    Office o1;
    int choice;
    do {
        cout << "\n\nMINIMUM SPANNING TREE"
             << "\n1. Input data"
             << "\n2. Display data"
             << "\n3. Calculate minimum cost"
             << "\nEnter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                o1.input ();
                break;
            case 2:
                o1.display ();
                break;
            case 3:
                o1.Prims ();
                break;
        }
    } while (choice != 4);
    return 0;
}









































/*

Sure, here's a line-by-line explanation of the provided code:

1. `#include <iostream>`: Includes the input/output stream library for handling input and output operations.
2. `#include <limits.h>`: Includes the limits library to access the `INT_MAX` constant, representing the maximum value for an `int`.
3. `using namespace std;`: Declares that the program will use the standard namespace, allowing the usage of standard C++ functions and objects without specifying their namespace.
4. `class Office { ... };`: Defines a class named `Office` to represent an office network.
5. `int n;`: Declares an integer variable `n` to store the number of offices.
6. `int adjacent[10][10];`: Declares a 2D array named `adjacent` to store the costs of connecting offices.
7. `string office[10];`: Declares an array of strings named `office` to store the names of the offices.
8. `void input ();`: Declares a member function `input` to input office details.
9. `void display ();`: Declares a member function `display` to display office details.
10. `void Prims ();`: Declares a member function `Prims` to find the minimum spanning tree using Prim's algorithm.
11. `void Office::input () { ... }`: Definition of the member function `input` to input office details.
12. `cout << "\nEnter no. of offices: ";`: Outputs a prompt to enter the number of offices.
13. `cin >> n;`: Inputs the number of offices provided by the user.
14. `for (int i = 0 ; i < n ; i++) ...`: Loop to input the names of the offices.
15. `cout << "\nEnter the cost to connect the offices: \n";`: Outputs a prompt to enter the costs of connecting offices.
16. `for (int i = 0 ; i < n ; i++) ...`: Nested loop to input the costs of connecting offices.
17. `void Office::display () { ... }`: Definition of the member function `display` to display office details.
18. `for (int i = 0 ; i < n ; i++) ...`: Nested loop to display the costs of connecting offices.
19. `void Office::Prims () { ... }`: Definition of the member function `Prims` to find the minimum spanning tree using Prim's algorithm.
20. `int visit[n], minCost = 0, count = n - 1, minIndex, cost = 0;`: Declares variables for tracking visited offices, minimum cost, count of remaining offices, minimum index, and total cost.
21. `for (int i = 0 ; i < n ; i++) ...`: Initializes the `visit` array to mark all offices as unvisited.
22. `cout << "\n\nShortest path: ";`: Outputs a message to indicate the shortest path.
23. `visit[0]=1;`: Marks the first office as visited.
24. `while (count--) { ... }`: Loop to find the minimum spanning tree.
25. `minCost = INT_MAX;`: Initializes `minCost` to the maximum possible integer value.
26. `for (int i = 0 ; i < n ; i++) ...`: Nested loop to find the minimum cost edge connecting visited and unvisited offices.
27. `visit[minIndex]=1;`: Marks the office with the minimum cost edge as visited.
28. `cout << "End";`: Outputs a message to indicate the end of the shortest path.
29. `cout << "\nMinimum cost: "<<cost;`: Outputs the minimum cost of the spanning tree.
30. `int main () { ... }`: Definition of the `main` function.
31. `Office o1;`: Creates an object `o1` of class `Office`.
32. `int choice;`: Declares a variable `choice` to store the user's menu choice.
33. `do { ... } while (choice != 4);`: Executes a menu-driven loop until the user chooses to exit.
34. `switch (choice) { ... }`: Switch statement to perform actions based on the user's choice.
35. `case 1: o1.input (); break;`: Calls the `input` function to input office details.
36. `case 2: o1.display (); break;`: Calls the `display` function to display office details.
37. `case 3: o1.Prims (); break;`: Calls the `Prims` function to find the minimum spanning tree.
38. `return 0;`: Indicates successful completion of the program execution.


Theory :

// 1. **Question**: What is a spanning tree?
//   - **Answer**: A spanning tree of a connected graph is a subgraph that includes all the vertices of the original graph and is a tree (i.e., acyclic and connected).

// 2. **Question**: What is the minimum spanning tree (MST) problem?
//   - **Answer**: The minimum spanning tree problem is to find a spanning tree of a weighted graph with the minimum possible total edge weight.

// 3. **Question**: How do you find the minimum spanning tree of a graph?
//   - **Answer**: There are several algorithms to find the minimum spanning tree, including Prim's algorithm and Kruskal's algorithm.

// 4. **Question**: Explain Prim's algorithm.
//   - **Answer**: Prim's algorithm starts with an arbitrary vertex and grows the minimum spanning tree by adding the minimum weight edge that connects a visited vertex to an unvisited vertex. It continues until all vertices are visited.

// 5. **Question**: Describe Kruskal's algorithm.
//   - **Answer**: Kruskal's algorithm sorts all the edges in increasing order of weight and iteratively adds the smallest edge that does not form a cycle in the current set of edges. It stops when all vertices are connected.

// 6. **Question**: What is the difference between Prim's and Kruskal's algorithms?
//   - **Answer**: Prim's algorithm grows the tree from a single vertex, while Kruskal's algorithm builds the tree by adding the smallest available edge at each step. Prim's is typically implemented with a priority queue, while Kruskal's often uses a disjoint-set data structure.

// 7. **Question**: How do you represent a graph in memory?
//   - **Answer**: A graph can be represented using an adjacency matrix or an adjacency list. An adjacency matrix is a 2D array where each cell represents the presence or absence of an edge between two vertices. An adjacency list is a collection of lists where each list represents the neighbors of a vertex.

// 8. **Question**: What is the time complexity of Prim's and Kruskal's algorithms?
//   - **Answer**: Both algorithms have a time complexity of O(E log V), where E is the number of edges and V is the number of vertices. This complexity arises from the sorting step in Kruskal's algorithm and the priority queue operations in Prim's algorithm.

// 9. **Question**: What is the purpose of the minimum spanning tree?
//   - **Answer**: The minimum spanning tree connects all the vertices of a graph with the minimum possible total edge weight. It is useful in various applications such as network design, circuit design, and clustering.

// 10. **Question**: Can you give an example where finding the minimum spanning tree is useful?
//     - **Answer**: Finding the minimum spanning tree is useful in designing efficient and cost-effective network layouts, such as connecting cities with minimal cost in a telecommunications network or designing a low-cost electrical grid.



// algorithm

Here's the algorithm for the provided C++ code:

### Algorithm:

1. **Office Class Definition:**
   - Define a class named `Office` to represent the office network.
   - Declare private data members `n`, `adjacent`, and `office` to store office details and connection costs.
   - Declare public member functions `input()`, `display()`, and `Prims()`.

2. **Input Function (`input()`):**
   - Prompt the user to enter the number of offices (`n`) and their names.
   - Prompt the user to enter the connection costs between each pair of offices.
   - Store the input data in the `adjacent` matrix and `office` array.

3. **Display Function (`display()`):**
   - Display the adjacency matrix `adjacent`, which represents connection costs between offices.
   - Display the names of offices stored in the `office` array.

4. **Prim's Algorithm Function (`Prims()`):**
   - Initialize an array `visit[]` to track visited offices and variables `minCost`, `count`, `minIndex`, and `cost`.
   - Start with the first office and mark it as visited.
   - Iterate `count` times, where `count = n - 1` (total offices - 1).
   - In each iteration, find the minimum cost edge connecting a visited office to an unvisited office.
   - Update the `minCost`, `minIndex`, and `cost`.
   - Mark the selected office as visited and print the path.
   - Repeat until all offices are visited.
   - Print the minimum cost of the spanning tree.

5. **Main Function:**
   - Declare an object `o1` of the `Office` class.
   - Implement a menu-driven interface:
     - Prompt the user to choose an operation (input data, display data, or calculate minimum cost).
     - Call the corresponding member function based on the user's choice.
     - Repeat until the user chooses to exit.

6. **Menu Interface:**
   - Display a menu with options to input office data, display data, calculate minimum cost, or exit.
   - Take user input for the chosen operation.
   - Execute the selected operation and continue until the user chooses to exit.

### Time Complexity:
-  O(n^2).

## Space complexity :
-  O(1)

*/
