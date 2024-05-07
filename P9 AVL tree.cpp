#include <iostream>
#include <string>
using namespace std;

struct AVLnode {
    string cWord;
    string cMean;
    AVLnode *left,*right;
    int iHt;
};

class AVLtree {
public:
    AVLnode *Root;
    AVLtree () {
        Root = NULL;
    }
    AVLnode* insert (AVLnode*, string, string);
    AVLnode* deletE (AVLnode*, string);
    AVLnode* LL (AVLnode*);
    AVLnode* RR (AVLnode*);
    AVLnode* LR (AVLnode*);
    AVLnode* RL (AVLnode*);
    int height (AVLnode*);
    int bFactor (AVLnode*);
    void inOrder (AVLnode*);
    void preOrder (AVLnode*);
};


AVLnode* AVLtree::insert (AVLnode *root, string nWord, string nMean) {
    if (root == NULL) {
        root = new AVLnode;
        root -> left = root -> right = NULL;
        root -> cWord = nWord;
        root -> cMean = nMean;
        root -> iHt = 0;
    }

    else if (root -> cWord != nWord) {
        if (root -> cWord > nWord)
            root -> left = insert (root -> left, nWord, nMean);
        else
            root -> right = insert (root -> right, nWord, nMean);
    }

    else
        cout << "\nRedundant AVLnode\n";

    root -> iHt = max(height(root -> left), height(root -> right)) + 1;

    if (bFactor (root) == 2) {
        if (root -> left -> cWord > nWord)
            root = RR (root);
        else
            root = LR (root);
    }

    if (bFactor (root) == -2) {
        if (root -> right -> cWord > nWord)
            root = RL (root);
        else
            root = LL (root);
    }

    return root;
}

AVLnode *AVLtree::deletE (AVLnode *curr, string x) {
    AVLnode *temp;
    if (curr == NULL) {
        cout << "\nWord not present!\n";
        return curr;
    }

    else if (x > curr -> cWord)
        curr -> right = deletE (curr -> right, x);

    else if (x < curr -> cWord)
        curr -> left = deletE (curr -> left, x);

    else if (curr -> right == NULL || curr -> left == NULL) {
        curr = curr -> left ? curr -> left : curr -> right;
        cout << "\nWord deleted Successfully!\n";
    }

    else {
        temp = curr -> right;
        while (temp -> left)
            temp = temp -> left;
        curr -> cWord = temp -> cWord;
        curr -> right = deletE (curr -> right, temp -> cWord);
    }

    if (curr == NULL) return curr;

    curr -> iHt = max(height(curr -> left), height(curr -> right)) + 1;

    if (bFactor (curr) == 2) {
        if (bFactor (curr -> left) >= 0)
            curr = RR (curr);
        else
            curr = LR (curr);
    }

    if (bFactor (curr) == -2) {
        if (bFactor (curr -> right) <= 0)
            curr = LL (curr);
        else
            curr = RL (curr);
    }

    return (curr);
}


int AVLtree::height (AVLnode* curr) {
    if (curr == NULL)
        return -1;
    else
        return curr -> iHt;
}


int AVLtree::bFactor (AVLnode* curr) {
    int lh = 0, rh = 0;
    if (curr == NULL)
        return 0;
    else
        return height(curr -> left) - height(curr -> right);
}


AVLnode* AVLtree::RR (AVLnode* curr) {
    AVLnode* temp = curr -> left;
    curr -> left = temp -> right;
    temp -> right = curr;
    curr -> iHt = max(height(curr -> left), height(curr -> right)) + 1;
    temp -> iHt = max(height(temp -> left), height(temp -> right)) + 1;
    return temp;
}


AVLnode* AVLtree::LL (AVLnode* curr) {
    AVLnode* temp = curr -> right;
    curr -> right = temp -> left;
    temp -> left = curr;
    curr -> iHt = max(height(curr -> left), height(curr -> right)) + 1;
    temp -> iHt = max(height(temp -> left), height(temp -> right)) + 1;
    return temp;
}


AVLnode* AVLtree::RL (AVLnode* curr) {
    curr -> right = RR (curr -> right);
    return LL (curr);
}


AVLnode* AVLtree::LR (AVLnode* curr) {
    curr -> left = LL (curr -> left);
    return RR (curr);
}


void AVLtree::inOrder (AVLnode* curr) {
    if (curr != NULL) {
        inOrder (curr -> left);
        cout << "\n\t" << curr -> cWord << "\t" << curr -> cMean;
        inOrder (curr -> right);
    }
}
void AVLtree::preOrder (AVLnode* curr) {
    if (curr != NULL) {
        cout << "\n\t" << curr -> cWord << "\t" << curr -> cMean;
        preOrder (curr -> left);
        preOrder (curr -> right);
    }
}


int main () {
    int ch;
    AVLtree avl;
    AVLnode *temp = NULL;
    string word;
    string mean;

    cout << "\n--------------------------------------";
    cout << "\n\tAVL TREE IMPLEMENTATION";
    cout << "\n--------------------------------------";
    do {
        cout << "\n\t\tMENU";
        cout << "\n1.Insert 2.Inorder 3.Delete 4.Exit";
        cout << "\n--------------------------------";
        cout << "\nEnter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "\nEnter Word: ";
                cin >> word;
                cout << "\nEnter Meaning: ";
                cin >> mean;
                avl.Root = avl.insert (avl.Root, word, mean);
                break;
            case 2:
                cout << "\nInorder Traversal:\n\tWORD\tMEANING";
                avl.inOrder (avl.Root);
                cout << "\n\nPreorder Traversal:\n\tWORD\tMEANING";
                avl.preOrder (avl.Root);
                cout << '\n';
                break;
            case 3:
                cout << "\nEnter the word to be deleted : ";
                cin >> word;
                avl.Root = avl.deletE (avl.Root, word);
                break;
            case 4:
                exit (0);
        }
    } while (ch != 4);

    return 0;
}































/*
Comlexity :

The time and space complexity of AVL tree operations are as follows:

1. **Time Complexity:**

   - **Insertion:** \( O(\log n) \)
   - **Deletion:** \( O(\log n) \)
   - **Search:** \( O(\log n) \)
   - **Rotation Operations:** \( O(1) \) (constant time complexity per rotation)
   - **Traversals (In-order, Pre-order):** \( O(n) \) (visiting each node once)

2. **Space Complexity:**

   - **Worst-case Space:** \( O(n) \)
   - **Average-case Space:** \( O(n) \)



Theory :

Sure, here's a theoretical overview of the provided code in a question-answer format:

**Question:** What is an AVL tree and what is its significance?

**Answer:** An AVL tree, named after its inventors Adelson-Velsky and Landis, is a self-balancing binary search tree. It maintains a balanced structure by ensuring that the heights of the left and right subtrees of any node differ by at most one. This balance property helps in keeping the tree height logarithmic, ensuring efficient search, insertion, and deletion operations.

**Question:** How does the insertion operation work in the AVL tree?

**Answer:** In the AVL tree insertion operation, a new node is added to the tree while maintaining its balance property. Initially, the node is inserted similar to a regular binary search tree insertion. After insertion, the heights of the nodes along the path from the newly inserted node to the root are updated, and rotations are performed if necessary to restore the balance.

**Question:** What are rotations in the context of AVL trees, and why are they necessary?

**Answer:** Rotations in AVL trees are operations used to maintain the balance of the tree after insertion or deletion. There are four types of rotations: Right Rotation (RR), Left Rotation (LL), Right-Left Rotation (RL), and Left-Right Rotation (LR). These rotations help in adjusting the structure of the tree to ensure that it remains balanced according to the AVL property, thus preventing skewed trees and maintaining efficient performance.

**Question:** How does the deletion operation work in the AVL tree?

**Answer:** In the AVL tree deletion operation, a node is removed from the tree while maintaining its balance property. Similar to insertion, the node is deleted as in a regular binary search tree. After deletion, the heights of the nodes along the path from the deleted node to the root are updated, and rotations are performed if necessary to restore the balance.

**Question:** Can you explain the concept of balance factor and how it is used in AVL trees?

**Answer:** The balance factor of a node in an AVL tree is the difference between the heights of its left and right subtrees. It indicates whether the tree is balanced at that node. A balance factor of 0, -1, or 1 indicates a balanced tree, while a balance factor outside this range indicates an unbalanced tree. Balance factors are used to determine which rotations to perform to restore balance after insertion or deletion operations.

**Question:** How are traversal operations performed in the AVL tree?

**Answer:** Traversal operations in the AVL tree, such as in-order and pre-order traversals, are performed recursively. In the in-order traversal, nodes are visited in ascending order, recursively visiting the left subtree, the current node, and then the right subtree. In the pre-order traversal, nodes are visited in the order of the current node, followed by the left subtree, and then the right subtree. These traversals provide different sequences for accessing nodes in the tree.

**Question:** What are the advantages of using an AVL tree over a regular binary search tree?

**Answer:** The advantages of using an AVL tree include guaranteed logarithmic time complexity for search, insert, and delete operations, even in the worst-case scenario. Additionally, AVL trees maintain a balanced structure, preventing degeneration into highly unbalanced trees that could lead to worst-case time complexity scenarios in regular binary search trees. Thus, AVL trees ensure efficient performance in dynamic search applications.





line by line explanation :

Sure, let's go through the code line by line:

1. `#include <iostream>`: This line includes the input/output stream library, which provides functions like `cin` and `cout` for input and output operations.
2. `#include <string>`: This line includes the string library, which provides functionalities for handling strings.
3. `using namespace std;`: This line declares that the code will use the standard namespace `std` by default, allowing the use of functions and objects from the standard library without explicitly specifying the namespace.
4. `struct AVLnode { ... };`: Defines a structure `AVLnode` representing a node in the AVL tree. It contains fields for a word (`cWord`), its meaning (`cMean`), pointers to left and right children (`left` and `right`), and the height of the node (`iHt`).
5. `class AVLtree { ... };`: Defines a class `AVLtree` representing the AVL tree. It contains methods for insertion, deletion, and traversal operations on the AVL tree.
6. `AVLnode* AVLtree::insert (AVLnode*, string, string) { ... }`: Method definition for inserting a node into the AVL tree. It takes a pointer to the root node, a word, and its meaning as arguments.
7. `AVLnode *AVLtree::deletE (AVLnode*, string) { ... }`: Method definition for deleting a node from the AVL tree. It takes a pointer to the root node and a word to be deleted as arguments.
8. `int AVLtree::height (AVLnode*) { ... }`: Method definition for calculating the height of a node in the AVL tree.
9. `int AVLtree::bFactor (AVLnode*) { ... }`: Method definition for calculating the balance factor of a node in the AVL tree.
10. `AVLnode* AVLtree::RR (AVLnode*) { ... }`: Method definition for performing a right rotation at a given node in the AVL tree.
11. `AVLnode* AVLtree::LL (AVLnode*) { ... }`: Method definition for performing a left rotation at a given node in the AVL tree.
12. `AVLnode* AVLtree::RL (AVLnode*) { ... }`: Method definition for performing a right-left rotation at a given node in the AVL tree.
13. `AVLnode* AVLtree::LR (AVLnode*) { ... }`: Method definition for performing a left-right rotation at a given node in the AVL tree.
14. `void AVLtree::inOrder (AVLnode*) { ... }`: Method definition for performing an in-order traversal of the AVL tree.
15. `void AVLtree::preOrder (AVLnode*) { ... }`: Method definition for performing a pre-order traversal of the AVL tree.
16. `int main () { ... }`: Main function definition.
17. `AVLtree avl;`: Creates an instance of the `AVLtree` class named `avl`.
18. `AVLnode *temp = NULL;`: Declares a pointer `temp` and initializes it to `NULL`.
19. `string word;`: Declares a variable `word` of type `string` to store the word input by the user.
20. `string mean;`: Declares a variable `mean` of type `string` to store the meaning input by the user.
21. `do { ... } while (ch != 4);`: Initiates a do-while loop to display the menu and execute operations based on the user's choice until the user chooses to exit.
22. Inside the `switch` statement, different cases are handled based on the user's choice (insertion, traversal, deletion, or exit).
23. `return 0;`: Indicates successful execution of the program and exits the main function.



Algorithm :

Here's a high-level algorithm for an AVL tree:

**Algorithm: AVL Tree Operations**

1. **Structure Definition:**
   - Define a structure for AVL nodes containing:
     - Data fields (e.g., key, value)
     - Pointers to left and right children
     - Height of the node

2. **Class Definition:**
   - Define a class for AVL tree operations:
     - Include methods for insertion, deletion, rotations, height calculation, balance factor calculation, and traversals (in-order, pre-order).

3. **Insertion Operation:**
   - Begin with the root node.
   - Insert the new node recursively according to the binary search tree property.
   - Update the height of each node along the insertion path.
   - Check the balance factor of each node and perform rotations if necessary to maintain balance.
     - If balance factor > 1 or < -1:
       - Perform appropriate rotation (LL, RR, LR, RL) to restore balance.
   - Repeat until the new node is inserted and the tree remains balanced.

4. **Deletion Operation:**
   - Begin with the root node.
   - Delete the node recursively according to the binary search tree property.
   - Update the height of each node along the deletion path.
   - Check the balance factor of each node and perform rotations if necessary to maintain balance.
     - If balance factor > 1 or < -1:
       - Perform appropriate rotation (LL, RR, LR, RL) to restore balance.
   - Repeat until the node is deleted and the tree remains balanced.

5. **Rotation Operations:**
   - Perform rotations to maintain or restore the balance of the tree:
     - Right Rotation (RR)
     - Left Rotation (LL)
     - Right-Left Rotation (RL)
     - Left-Right Rotation (LR)
   - Update the heights of affected nodes after rotation.

6. **Traversal Operations:**
   - In-Order Traversal:
     - Recursively traverse the left subtree.
     - Visit the current node.
     - Recursively traverse the right subtree.
   - Pre-Order Traversal:
     - Visit the current node.
     - Recursively traverse the left subtree.
     - Recursively traverse the right subtree.

7. **Testing and Validation:**
   - Test the AVL tree operations with various input scenarios to ensure correctness and efficiency.
   - Validate the tree's balance property and height after each operation.

8. **Conclusion:**
   - The AVL tree operations maintain a balanced binary search tree structure, ensuring efficient search, insert, and delete operations with logarithmic time complexity in the worst-case scenario.

   */

