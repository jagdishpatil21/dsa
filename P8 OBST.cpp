#include <iostream>
#include <limits.h>
using namespace std;
#define SIZE 15

class OBST {
    int prob[SIZE] = {};
    int keys[SIZE] = {};
    int weight[SIZE][SIZE] = {};
    int cost[SIZE][SIZE] = {};
    int root[SIZE][SIZE] = {};
    int n;
public:
    void get_data();
    int Min_Value(int, int);
    void build_OBST();
    void build_tree();
    void print(int [][SIZE], int);
};

void OBST::get_data() {
    int i;
    cout << "\nOptimal Binary Search Tree \n\nEnter the number of nodes: ";
    cin >> n;
    cout << "\nEnter " << n << " nodes: ";
    for (i = 1; i <= n; i++)
        cin >> keys[i];

    cout << "\nEnter " << n << " probabilities: ";
    for (i = 1; i <= n; i++)
        cin >> prob[i];

}


int OBST::Min_Value(int i, int j) {
    int l, k;
    int minimum = INT_MAX;
    for (l = root[i][j - 1]; l <= root[i + 1][j]; l++) {
        if ((cost[i][l - 1] + cost[l][j]) < minimum) {
            minimum = cost[i][l - 1] + cost[l][j];
            k = l;
        }
    }
    return k;
}


void OBST::build_OBST() {
    int i, j, k, l;
    for (i = 0; i < n; i++) {
        weight[i][i] = root[i][i] = cost[i][i] = 0;
        weight[i][i + 1] = cost[i][i + 1] = prob[i + 1];
        root[i][i + 1] = i + 1;
    }
    weight[n][n] = root[n][n] = cost[n][n] = 0;
    for (l = 2; l <= n; l++) {
        for (i = 0; i <= n - l; i++) {
            j = i + l;
            weight[i][j] = weight[i][j - 1] + prob[j];
            k = Min_Value(i, j);
            cost[i][j] = weight[i][j] + cost[i][k - 1] + cost[k][j];
            root[i][j] = k;
        }
    }

    cout << "\nCost are: \n";
    print(cost, n);

    cout << "\nRoot are: \n";
    print(root, n);
}

void OBST::build_tree() {
    int i, j, k;
    int queue[20], front = -1, rear = -1;
    cout << "\nThe Optimal Binary Search Tree For the Given Nodes Is…\n";
    cout << "\nThe Root of this OBST is:: " << keys[root[0][n]];
    cout << "\nThe Cost of this OBST is:: " << cost[0][n];
    cout << "\n\n\tNODE\tLEFT CHILD\tRIGHT CHILD";
    cout << "\n";
    queue[++rear] = 0;
    queue[++rear] = n;
    while (front != rear) {
        i = queue[++front];
        j = queue[++front];
        k = root[i][j];
        cout << "\n\t" << keys[k];
        if (root[i][k - 1] != 0) {
            cout << "\t\t" << keys[root[i][k - 1]];
            queue[++rear] = i;
            queue[++rear] = k - 1;
        }
        else
            cout << "\t\t";
        if (root[k][j] != 0) {
            cout << "\t" << keys[root[k][j]];
            queue[++rear] = k;
            queue[++rear] = j;
        }
        else
            cout << "\t";
    }
    cout << "\n";
}

void OBST::print(int arr[][SIZE], int n) {
    int i, j;
    for(i = 0; i <= n; i++) {
        for(j = 0; j <= n; j++)
            cout << arr[i][j] << '\t';
        cout << '\n';
    }
}

int main() {
    OBST obj;
    obj.get_data();
    obj.build_OBST();
    obj.build_tree();
    return 0;
}









































/*

**Theory**:

Time Comlexity : The time complexity of the Optimal Binary Search Tree (OBST) algorithm is O(n^3)

1. **Binary Search Tree (BST)**:
   - A binary search tree is a binary tree where each node has at most two children: a left child and a right child.
   - For any node in the tree, the value of nodes in the left subtree is less than the node's value, and the value of nodes in the right subtree is greater than the node's value.
   - This property ensures that searching for an element in a BST has a time complexity of O(log n) on average, where n is the number of nodes in the tree.

2. **Optimality Criteria**:
   - In an OBST, the optimality criterion is to minimize the expected search cost, which is the weighted sum of the depths of all nodes, weighted by their probabilities of being accessed.
   - The expected search cost is calculated by summing the product of each node's depth and its corresponding probability.

3. **Dynamic Programming**:
   - The construction of an OBST involves dynamic programming techniques.
   - Dynamic programming breaks down the problem into smaller subproblems and computes the optimal solution by combining the solutions to these subproblems.
   - In the case of OBST, dynamic programming is used to compute the optimal cost and root values for subtrees of varying sizes.

4. **Algorithm**:
   - The algorithm for constructing an OBST involves computing the optimal cost, root, and weight matrices.
   - It iterates through all possible subtrees of increasing sizes, calculating the optimal cost and root for each subtree based on probabilities and previously computed values.
   - The optimal root values are used to build the OBST tree structure.

5. **Application**:
   - OBSTs are commonly used in compilers for optimizing symbol table lookups, in database systems for optimizing query processing, and in data compression algorithms for constructing Huffman trees.
   - By arranging frequently accessed elements closer to the root, OBSTs reduce the average search time, leading to efficient data retrieval and processing.


line by line explanation:

Sure, here's a detailed explanation of each line of code:

1. `#include <iostream>`: This line includes the iostream standard library, which provides functionality for input and output operations.

2. `#include <limits.h>`: This line includes the limits.h header file, which defines various macros for representing the limits of various data types.

3. `using namespace std;`: This line declares that symbols defined in the std namespace are to be used directly, saving us from having to prefix them with std:: in our code.

4. `#define SIZE 15`: This line defines a macro SIZE with a value of 15, which is later used to specify the size of arrays.

6. `class OBST {`: This line starts the definition of a class named OBST, which encapsulates functionality related to Optimal Binary Search Trees (OBST).

7. `int prob[SIZE] = {};`: This line declares an integer array `prob` of size SIZE and initializes all its elements to zero. It represents the probabilities with which we search for elements.

8. `int keys[SIZE] = {};`: This line declares an integer array `keys` of size SIZE and initializes all its elements to zero. It stores the elements from which the OBST is to be built.

9. `int weight[SIZE][SIZE] = {};`: This line declares a 2D integer array `weight` of size SIZE × SIZE and initializes all its elements to zero. It represents the weight of keys tree having root root[i][j].

10. `int cost[SIZE][SIZE] = {};`: This line declares a 2D integer array `cost` of size SIZE × SIZE and initializes all its elements to zero. It represents the cost of keys tree having root root[i][j].

11. `int root[SIZE][SIZE] = {};`: This line declares a 2D integer array `root` of size SIZE × SIZE and initializes all its elements to zero. It represents the root of the keys tree.

12. `int n;`: This line declares an integer variable `n`, which will store the number of nodes in the OBST.

13. `public:`: This line declares that the following member functions and variables are public and can be accessed from outside the class.

14. `void get_data();`: This line declares a member function `get_data()` without a return type. It is used to accept input data for constructing the OBST.

15. `int Min_Value(int, int);`: This line declares a member function `Min_Value()` that returns an integer. It calculates the minimum value of keys in a given range such that the cost is minimized.

16. `void build_OBST();`: This line declares a member function `build_OBST()` without a return type. It builds the OBST by computing cost, root, and weight values.

17. `void build_tree();`: This line declares a member function `build_tree()` without a return type. It builds the tree from the tables made by the `build_OBST()` function.

18. `void print(int [][SIZE], int);`: This line declares a member function `print()` without a return type. It is used to print a 2D array.

21. `void OBST::get_data() {`: This line defines the member function `get_data()` of the `OBST` class.

22. `int i;`: This line declares an integer variable `i`.

23. `cout << "\nOptimal Binary Search Tree \n\nEnter the number of nodes: ";`: This line outputs a message asking the user to enter the number of nodes for the OBST.

24. `cin >> n;`: This line reads the number of nodes entered by the user and stores it in the variable `n`.

25. `cout << "\nEnter " << n << " nodes: ";`: This line outputs a message asking the user to enter the values of the nodes.

26. `for (i = 1; i <= n; i++)`: This line starts a for loop that iterates from 1 to `n` (inclusive), prompting the user to enter the values of each node.

27. `cin >> keys[i];`: This line reads the value of the `i`-th node entered by the user and stores it in the `keys` array.

28. `cout << "\nEnter " << n << " probabilities: ";`: This line outputs a message asking the user to enter the probabilities associated with each node.

29. `for (i = 1; i <= n; i++)`: This line starts a for loop similar to line 26 but for entering the probabilities associated with each node.

30. `cin >> prob[i];`: This line reads the probability of the `i`-th node entered by the user and stores it in the `prob` array.

37. `int OBST::Min_Value(int i, int j) {`: This line defines the member function `Min_Value()` of the `OBST` class.




Algorithm :

### Optimal Binary Search Tree (OBST) Algorithm:

1. **Input:**
   - `keys[]`: Array of keys.
   - `prob[]`: Array of probabilities associated with each key.
   - `n`: Number of keys.

2. **Initialize:**
   - Initialize 2D arrays `weight[][]`, `cost[][]`, and `root[][]` of size `(n+1) x (n+1)` to zero.
   - Initialize arrays `prob[]` and `keys[]` with actual probabilities and keys, respectively.

3. **Compute Weight and Cost:**
   - For each key `k[i]`:
     - Initialize weight, cost, and root for the single node trees.
   - For each subtree size `l` from 2 to `n`:
     - For each `i` from 0 to `n-l`:
       - Calculate `j = i + l`.
       - Compute the weight of subtree `weight[i][j]`.
       - Find the root of the subtree `root[i][j]`.
       - Compute the cost of subtree `cost[i][j]`.

4. **Build Tree:**
   - Construct the tree recursively from the `root[][]` table:
     - Start from `root[0][n]` which represents the root of the entire tree.
     - For each root node `root[i][j]`, recursively construct left and right subtrees.
     - Print the keys and their children.

5. **Output:**
   - Print the Optimal Binary Search Tree structure.
   - Print the total cost of the Optimal Binary Search Tree.

### Time Complexity:
- The time complexity of constructing an OBST is O(n^3) where `n` is the number of keys.

### Space Complexity:
- The space complexity is O(n^2) due to the space required to store the weight, cost, and root tables.

*/

