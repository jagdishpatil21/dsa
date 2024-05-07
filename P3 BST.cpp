#include <iostream>
#include <climits>

using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BST {
public:
    TreeNode* root;

    BST() : root(nullptr) {}

    void insert(int value) {
        root = insertRecursive(root, value);
    }

    TreeNode* insertRecursive(TreeNode* current, int value) {
        if (current == nullptr) {
            return new TreeNode(value);
        }

        if (value < current->data) {
            current->left = insertRecursive(current->left, value);
        } else {
            current->right = insertRecursive(current->right, value);
        }

        return current;
    }

    int longestPathLength() {
        return longestPathLengthRecursive(root);
    }

    int longestPathLengthRecursive(TreeNode* current) {
        if (current == nullptr) {
            return 0;
        }

        int leftPathLength = longestPathLengthRecursive(current->left);
        int rightPathLength = longestPathLengthRecursive(current->right);

        return 1 + max(leftPathLength, rightPathLength);
    }

    int findMin() {
        return findMinRecursive(root);
    }

    int findMinRecursive(TreeNode* current) {
        if (current == nullptr) {
            return INT_MAX;
        }

        int minValue = current->data;
        int leftMin = findMinRecursive(current->left);
        int rightMin = findMinRecursive(current->right);

        return min(minValue, min(leftMin, rightMin));
    }

    void swapLeftRight() {
        swapLeftRightRecursive(root);
    }

    void swapLeftRightRecursive(TreeNode* current) {
        if (current == nullptr) {
            return;
        }

        swap(current->left, current->right);

        swapLeftRightRecursive(current->left);
        swapLeftRightRecursive(current->right);
    }

    bool search(int value) {
        return searchRecursive(root, value);
    }

    bool searchRecursive(TreeNode* current, int value) {
        if (current == nullptr) {
            return false;
        }

        if (value == current->data) {
            return true;
        } else if (value < current->data) {
            return searchRecursive(current->left, value);
        } else {
            return searchRecursive(current->right, value);
        }
    }

    void displayInorder() {
        inorderTraversal(root);
        cout << endl;
    }

    void inorderTraversal(TreeNode* current) {
        if (current != nullptr) {
            inorderTraversal(current->left);
            cout << current->data << " ";
            inorderTraversal(current->right);
        }
    }
};

void displayMenu() {
    cout << "\nMenu:" << endl;
    cout << "a. Insert new node" << endl;
    cout << "b. Find number of nodes in longest path" << endl;
    cout << "c. Minimum data value found in the tree" << endl;
    cout << "d. Change a tree so that the roles of the left and right pointers are swapped at every node" << endl;
    cout << "e. Search a value" << endl;
    cout << "Enter 'q' to quit" << endl;
}

int main() {
    BST bst;
    char choice;
    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 'a': {
                int value;
                cout << "Enter value to insert: ";
                cin >> value;
                bst.insert(value);
                break;
            }
            case 'b': {
                cout << "Number of nodes in longest path from root: " << bst.longestPathLength() << endl;
                break;
            }
            case 'c': {
                cout << "Minimum data value in the tree: " << bst.findMin() << endl;
                break;
            }
            case 'd': {
                bst.swapLeftRight();
                cout << "Left and right pointers swapped at every node." << endl;
                break;
            }
            case 'e': {
                int value;
                cout << "Enter value to search: ";
                cin >> value;
                if (bst.search(value)) {
                    cout << value << " found in the tree." << endl;
                } else {
                    cout << value << " not found in the tree." << endl;
                }
                break;
            }
            case 'q': {
                cout << "Exiting..." << endl;
                break;
            }
            default:
                cout << "Invalid choice. Please enter a valid choice." << endl;
        }
    } while (choice != 'q');

    return 0;
}


































/*Sure, let's break down the code:

1. `#include <iostream>` and `#include <climits>`: These are preprocessor directives that include input/output stream and limits library respectively, allowing you to use input/output functionality and access constants for integer limits.

2. `using namespace std;`: This line declares that all symbols in the `std` namespace (standard namespace) can be used in the code without explicitly qualifying them.

3. `class TreeNode { ... };`: This class defines the structure of a node in a binary search tree (BST). It has three members: `data` (integer value of the node), `left` (pointer to the left child node), and `right` (pointer to the right child node).

4. `class BST { ... };`: This class represents the Binary Search Tree (BST) data structure. It has a pointer to the root node of the tree and various member functions to perform operations on the tree, such as insertion, search, traversal, etc.

5. `BST() : root(nullptr) {}`: This is the constructor for the BST class, which initializes the root pointer to `nullptr` (indicating an empty tree).

6. `void insert(int value) { ... }`: This function inserts a new node with the given value into the BST.

7. `TreeNode* insertRecursive(TreeNode* current, int value) { ... }`: This is a helper function for insertion that recursively inserts a new node into the BST.

8. `int longestPathLength() { ... }`: This function calculates and returns the number of nodes in the longest path from the root to a leaf node in the BST.

9. `int longestPathLengthRecursive(TreeNode* current) { ... }`: This is a helper function for calculating the longest path length recursively.

10. `int findMin() { ... }`: This function finds and returns the minimum value stored in the BST.

11. `int findMinRecursive(TreeNode* current) { ... }`: This is a helper function for finding the minimum value recursively.

12. `void swapLeftRight() { ... }`: This function swaps the left and right child pointers of each node in the BST.

13. `void swapLeftRightRecursive(TreeNode* current) { ... }`: This is a helper function for swapping left and right pointers recursively.

14. `bool search(int value) { ... }`: This function searches for a value in the BST and returns true if found, otherwise false.

15. `bool searchRecursive(TreeNode* current, int value) { ... }`: This is a helper function for searching recursively.

16. `void displayInorder() { ... }`: This function displays the BST in inorder traversal order.

17. `void inorderTraversal(TreeNode* current) { ... }`: This is a helper function for inorder traversal recursively.

18. `void displayMenu() { ... }`: This function displays the menu options for interacting with the BST.

19. `int main() { ... }`: This is the main function where the program starts its execution. It creates an instance of the BST class and provides a menu-driven interface for performing various operations on the BST.

The main function repeatedly displays the menu, reads the user's choice, and executes the corresponding operation until the user chooses to quit.

Let me know if you need further clarification on any specific part!


Theory :

Average time complexity of BST is O(logn) and worst is O(n)
The space complexity for a BST is O(n)

// 1. **Definition**:
//   - A Binary Search Tree (BST) is a binary tree data structure where each node has at most two children, referred to as the left child and the right child.
//   - In a BST, for every node:
//      - All nodes in the left subtree have values less than the node's value.
//      - All nodes in the right subtree have values greater than the node's value.
//      - This property holds recursively for every node in the tree.

// 2. **Ordering Property**:
//   - The ordering property of BSTs enables efficient searching, insertion, and deletion operations.
//   - Because of this property, BSTs are often used for searching and sorting operations.

// 3. **Operations**:
//   - **Search**: To search for a value in a BST, we start at the root and compare the value with the current node's value.
//      - If the value matches, we have found the node.
//      - If the value is less than the current node's value, we search in the left subtree.
//      - If the value is greater than the current node's value, we search in the right subtree.
//      - We repeat this process recursively until we find the node or reach a null pointer.

//   - **Insertion**: To insert a new value into a BST, we start at the root and traverse the tree to find the appropriate position for the new node.
//      - If the value is less than the current node's value, we move to the left subtree.
//      - If the value is greater than the current node's value, we move to the right subtree.
//      - We repeat this process until we find an empty spot, where we insert the new node.

//   - **Deletion**: Deleting a node from a BST can be a bit more complex. There are three cases to consider:
//      - If the node to be deleted is a leaf node (has no children), we can simply remove it.
//      - If the node to be deleted has only one child, we can replace the node with its child.
//      - If the node to be deleted has two children, we can either replace it with the maximum node in its left subtree or the minimum node in its right subtree.

// 4. **Balanced vs. Unbalanced Trees**:
//   - In a balanced BST, the height of the tree is kept relatively low, ensuring efficient operations.
//   - In an unbalanced BST, the height of the tree can become skewed, leading to inefficient operations.
//   - Techniques such as AVL trees and Red-Black trees are used to maintain balance in BSTs.

// 5. **Applications**:
//   - BSTs are commonly used in:
//      - Database systems for indexing and searching.
//      - Symbol tables in compilers and interpreters.
//      - Implementations of map and set data structures in programming languages.


Algorithm :

1. **Node Structure Definition**:
   - Define a structure `Node` representing a node in a binary search tree (BST) containing an integer data value, and pointers to the left and right child nodes.

2. **Create Node Function**:
   - Define a function `createNode()` to create a new node with a given integer value.
   - Allocate memory for the new node and initialize its data and child pointers.
   - Return a pointer to the newly created node.

3. **Insert Node Function**:
   - Define a function `insertNode()` to insert a new node with a given value into the BST.
   - If the tree is empty (`root == nullptr`), create a new node with the given value and return it.
   - If the value is less than the root node's value, recursively insert the value into the left subtree.
   - If the value is greater than the root node's value, recursively insert the value into the right subtree.
   - Return the root node after insertion.

4. **Longest Path Function**:
   - Define a function `longestPath()` to find the number of nodes in the longest path from the root to a leaf node in the BST.
   - If the root is null, return 0.
   - Recursively calculate the length of the longest path by finding the maximum of the lengths of the left and right subtrees, plus 1 for the current node.
   - Return the maximum length.

5. **Minimum Value Function**:
   - Define a function `minValue()` to find the minimum value in the BST.
   - Traverse the left child pointers until reaching the leftmost node (smallest value).
   - Return the data value of the leftmost node.

6. **Swap Pointers Function**:
   - Define a function `swapPointers()` to swap the left and right child pointers of all nodes in the BST.
   - If the root is null, return null.
   - Swap the left and right child pointers of the current node.
   - Recursively swap pointers for the left and right subtrees.
   - Return the root node after swapping.

7. **Search Function**:
   - Define a function `search()` to search for a value in the BST.
   - If the root is null, return false.
   - If the value matches the root's data, return true.
   - If the value is less than the root's data, recursively search in the left subtree.
   - If the value is greater than the root's data, recursively search in the right subtree.

8. **Inorder Traversal Function**:
   - Define a function `inorderTraversal()` to perform an inorder traversal of the BST.
   - If the root is not null, recursively traverse the left subtree, print the root's data, and recursively traverse the right subtree.

9. **Main Function**:
   - Initialize the root of the BST to null.
   - Insert values into the BST using the `insertNode()` function.
   - Print the inorder traversal of the original BST.
   - Perform various operations on the BST:
     - Insert a new node.
     - Find the number of nodes in the longest path.
     - Find the minimum value.
     - Swap left and right pointers.
     - Search for a value in the BST.

*/
