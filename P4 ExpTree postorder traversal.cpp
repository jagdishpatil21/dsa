#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
    char data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(char val) : data(val), left(nullptr), right(nullptr) {}
};

bool isOperand(char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

TreeNode* constructExpressionTree(string prefix) {
    stack<TreeNode*> stk;
    int n = prefix.length();
    for (int i = n - 1; i >= 0; i--) {
        char ch = prefix[i];
        TreeNode* newNode = new TreeNode(ch);
        if (isOperand(ch)) {
            stk.push(newNode);
        } else {
            newNode->left = stk.top(); stk.pop();
            newNode->right = stk.top(); stk.pop();
            stk.push(newNode);
        }
    }
    return stk.top();
}

void postOrderTraversal(TreeNode* root) {
    if (!root) return;
    stack<TreeNode*> stk;
    TreeNode* prev = nullptr;
    do {
        while (root) {
            stk.push(root);
            root = root->left;
        }
        while (!root && !stk.empty()) {
            root = stk.top();
            if (root->right == nullptr || root->right == prev) {
                cout << root->data << " ";
                stk.pop();
                prev = root;
                root = nullptr;
            } else {
                root = root->right;
            }
        }
    } while (!stk.empty());
}

void deleteTree(TreeNode* root) {
    if (root) {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
}

int main() {
    string prefix = "+--a*bc/def";

    TreeNode* root = constructExpressionTree(prefix);

    cout << "Post-order traversal: ";
    postOrderTraversal(root);
    cout << endl;

    deleteTree(root);

    return 0;
}













































/*
Theory :
time and Space complexity is O(n)

// 1. **Expression Trees**:
//     - Expression trees are binary trees used to represent expressions.
//     - In an expression tree, each internal node represents an operator, and each leaf node represents an operand.
//     - The expression tree preserves the precedence and associativity of the operators.
//     - Expression trees can be constructed from infix, prefix, or postfix expressions.

// 2. **Prefix Expression**:
//     - In a prefix expression, the operator precedes its operands.
//     - For example, in the prefix expression "+AB", "+" is the operator, and "A" and "B" are the operands.
//     - Prefix expressions are also known as Polish notation.

// 3. **Construction of Expression Trees from Prefix Expressions**:
//     - To construct an expression tree from a prefix expression, we start from the beginning of the expression and work our way to the end.
//     - We use a stack data structure to store the operands and intermediate results.
//     - When encountering an operator, we pop the top two operands from the stack, create a new node with the operator as the data, and push this new node back onto the stack.
//     - After processing the entire expression, the root of the expression tree is at the top of the stack.

// 4. **Post-order Traversal**:
//     - Post-order traversal is a depth-first traversal method used to visit the nodes of a tree.
//     - In post-order traversal, we recursively traverse the left subtree, then the right subtree, and finally visit the root node.
//     - Post-order traversal is commonly used to evaluate expressions stored in expression trees.
//     - It produces the postfix notation of the expression.

// 5. **Non-recursive Post-order Traversal**:
//     - Non-recursive post-order traversal uses a stack to simulate the recursive behavior.
//     - We start from the root node and traverse down the left subtree, pushing nodes onto the stack as we go.
//     - When we reach a leaf node or a node with both children visited, we pop it from the stack and process it.
//     - We keep track of the previously visited node to ensure we don't visit the same node twice.
//     - This process continues until the stack becomes empty.


Line by line explaination :

Here's a line-by-line explanation of the provided C++ code:

1. `#include <iostream>`: This line includes the input/output stream library for handling input and output operations.

2. `#include <stack>`: This line includes the stack container adapter from the standard template library (STL).

3. `using namespace std;`: This line brings the entire `std` namespace into the current scope, allowing the usage of standard library components without prefixing them with `std::`.

4. `struct TreeNode { ... };`: This defines a structure named `TreeNode`, representing a node in a binary tree. It contains three members: `data` to store the data of the node, `left` and `right` pointers to point to the left and right child nodes, respectively. The constructor initializes the node with the given data and sets both child pointers to `nullptr`.

5. `bool isOperand(char ch) { ... }`: This defines a function named `isOperand` that checks if a character is an operand (a letter). It returns `true` if the character is within the range 'a' to 'z' or 'A' to 'Z', indicating an operand.

6. `TreeNode* constructExpressionTree(string prefix) { ... }`: This function constructs an expression tree from the given prefix expression. It takes a string `prefix` as input and returns a pointer to the root of the constructed expression tree.

7. `stack<TreeNode*> stk;`: This line declares a stack named `stk` to store tree nodes.

8. `int n = prefix.length();`: This line calculates the length of the prefix expression string.

9. `for (int i = n - 1; i >= 0; i--) { ... }`: This loop iterates through the characters of the prefix expression string from right to left.

10. `char ch = prefix[i];`: This line retrieves the character at the current index `i` in the prefix expression string.

11. `TreeNode* newNode = new TreeNode(ch);`: This line creates a new tree node with the character `ch` as its data.

12. `if (isOperand(ch)) { ... } else { ... }`: This conditional statement checks if the current character is an operand or an operator.

13. `stk.push(newNode);`: If the current character is an operand, the node is pushed onto the stack.

14. `newNode->left = stk.top(); stk.pop();`: If the current character is an operator, the top two nodes from the stack are popped and assigned as the left and right children of the new node, respectively.

15. `return stk.top();`: After processing all characters, the root of the expression tree is obtained from the top of the stack and returned.

16. `void postOrderTraversal(TreeNode* root) { ... }`: This function performs post-order traversal of the expression tree in a non-recursive manner. It takes the root of the tree as input.

17. `if (!root) return;`: This line checks if the root is null. If so, the function returns immediately.

18. `stack<TreeNode*> stk;`: This line declares a stack named `stk` to store tree nodes.

19. `TreeNode* prev = nullptr;`: This line declares a pointer `prev` to keep track of the previously visited node during traversal.

20. `do { ... } while (!stk.empty());`: This loop iterates until the stack becomes empty.

21. `while (root) { ... }`: This inner loop traverses the left subtree of the current node and pushes nodes onto the stack.

22. `while (!root && !stk.empty()) { ... }`: This inner loop processes nodes when the left subtree is fully traversed or the stack is not empty.

23. `if (root->right == nullptr || root->right == prev) { ... } else { ... }`: This conditional statement checks if the right subtree has been visited or not. If the right subtree is visited or absent, the current node is printed, and its pointer is popped from the stack. Otherwise, the right subtree is traversed.

24. `void deleteTree(TreeNode* root) { ... }`: This function deletes the entire tree to free up memory. It takes the root of the tree as input.

25. `if (root) { ... }`: This conditional statement checks if the root is not null.

26. `deleteTree(root->left); deleteTree(root->right); delete root;`: This line recursively deletes the left and right subtrees of the current node and then deletes the current node itself.

27. `int main() { ... }`: This is the main function where the program execution begins.

28. `string prefix = "+--a*bc/def";`: This line initializes a string `prefix` with the prefix expression.

29. `TreeNode* root = constructExpressionTree(prefix);`: This line constructs the expression tree from the prefix expression and assigns the root node to `root`.

30. `cout << "Post-order traversal: ";`: This line prints a message indicating that the post-order traversal is being performed.

31. `postOrderTraversal(root);`: This line calls the `postOrderTraversal` function to perform post-order traversal of the expression tree.

32. `deleteTree(root);`: This line deletes the entire expression tree to free up memory.

33. `return 0;`: This line indicates successful termination of the program.


Algorithm :
Here's the algorithm for the provided code:

1. **Structure Definition**:
   - Define a structure `TreeNode` representing a node in the expression tree. It contains three members: `data` to store the character data, `left` and `right` pointers to the left and right child nodes.

2. **isOperand Function**:
   - Define a function `isOperand` to check if a character is an operand (a letter). It returns `true` if the character is within the range 'a' to 'z' or 'A' to 'Z'.

3. **Expression Tree Construction**:
   - Define a function `constructExpressionTree` that constructs an expression tree from the given prefix expression string.
   - Initialize an empty stack to store tree nodes.
   - Iterate through the characters of the prefix expression string from right to left.
     - Create a new node with the current character as its data.
     - If the character is an operand, push the node onto the stack.
     - If the character is an operator, pop the top two nodes from the stack, assign them as the left and right children of the new node, and then push the new node onto the stack.
   - After processing all characters, the root of the expression tree is obtained from the top of the stack.

4. **Post-order Traversal (Non-recursive)**:
   - Define a function `postOrderTraversal` to perform post-order traversal of the expression tree in a non-recursive manner.
   - Initialize an empty stack to store tree nodes and a pointer `prev` to keep track of the previously visited node.
   - Start a do-while loop that iterates until the stack becomes empty.
     - While the current node is not null, traverse the left subtree and push nodes onto the stack.
     - While the current node is null and the stack is not empty, process nodes:
       - If the right subtree has been visited or is absent, print the current node, pop it from the stack, update `prev`, and set the current node to null.
       - Otherwise, traverse the right subtree.
   - Perform post-order traversal until all nodes are processed.

5. **Tree Deletion**:
   - Define a function `deleteTree` to delete the entire expression tree and free up memory.
   - If the root is not null, recursively delete the left and right subtrees of the current node and then delete the current node itself.

6. **Main Function**:
   - Initialize a prefix expression string.
   - Construct the expression tree from the prefix expression.
   - Perform post-order traversal of the expression tree.
   - Delete the entire tree to free up memory.

7. **End of Program**:
   - Return 0 to indicate successful termination of the program.

*/
