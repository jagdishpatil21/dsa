#include <iostream>
#include <map>
using namespace std;

map<string, string> dictionary;

void AddKeyword() {
    string word, meaning;
    cout << "Enter keyword: ";
    cin >> word;
    cout << "Enter meaning: ";
    cin >> meaning;
    dictionary[word] = meaning;
    cout << "Keyword added successfully.\n";
}

void DeleteKeyword() {
    string word;
    cout << "Enter keyword to delete: ";
    cin >> word;
    if (dictionary.erase(word) == 1) {
        cout << "Keyword deleted successfully.\n";
    } else {
        cout << "Keyword not found.\n";
    }
}

void UpdateKeyword() {
    string word, meaning;
    cout << "Enter keyword to update: ";
    cin >> word;
    if (dictionary.find(word) != dictionary.end()) {
        cout << "Enter new meaning: ";
        cin >> meaning;
        dictionary[word] = meaning;
        cout << "Meaning updated successfully.\n";
    } else {
        cout << "Keyword not found.\n";
    }
}

void DisplayAscending() {
    cout << "Dictionary in Ascending Order:\n";
    for (auto it = dictionary.begin(); it != dictionary.end(); ++it) {
        cout << it->first << ": " << it->second << endl;
    }
}

void DisplayDescending() {
    cout << "Dictionary in Descending Order:\n";
    for (auto it = dictionary.rbegin(); it != dictionary.rend(); ++it) {
        cout << it->first << ": " << it->second << endl;
    }
}

void FindMaxComparisons() {
    string word;
    cout << "Enter keyword to find maximum comparisons: ";
    cin >> word;
    auto it = dictionary.find(word);
    if (it != dictionary.end()) {
        cout << "Maximum comparisons required: " << distance(dictionary.begin(), it) + 1 << endl;
    } else {
        cout << "Keyword not found.\n";
    }
}

int main() {
    int choice;
    do {
        cout << "\nDictionary Operations:\n";
        cout << "1. Add Keyword\n";
        cout << "2. Delete Keyword\n";
        cout << "3. Update Meaning\n";
        cout << "4. Display in Ascending Order\n";
        cout << "5. Display in Descending Order\n";
        cout << "6. Find Maximum Comparisons\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                AddKeyword();
                break;
            case 2:
                DeleteKeyword();
                break;
            case 3:
                UpdateKeyword();
                break;
            case 4:
                DisplayAscending();
                break;
            case 5:
                DisplayDescending();
                break;
            case 6:
                FindMaxComparisons();
                break;
            case 7:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 7);

    return 0;
}




































/*

Time Complexity : O(log n)

Theory :


// 1. **Data Structure Choice**:
//   - The code utilizes the `std::map` container from the C++ Standard Library. You can discuss why `std::map` was chosen for this implementation and its advantages, such as automatic sorting by keys and efficient search, insertion, and deletion operations.

// 2. **Operations Complexity**:
//   - You can discuss the time complexity of various operations performed in the code. For instance, insertion, deletion, and search operations in `std::map` have a logarithmic time complexity, O(log n), where n is the number of elements in the map. This is because `std::map` is implemented as a balanced binary search tree.

// 3. **Error Handling**:
//   - The code includes basic error handling for cases like keyword not found during deletion or update. Discussing robust error handling strategies could be beneficial.

// 4. **Menu-Driven Interface**:
//   - The menu-driven interface provides users with a convenient way to interact with the dictionary. You can discuss the usability of such an interface and how it enhances user experience.

// 5. **Input Validation**:
//   - The code lacks input validation. Discussing the importance of input validation to handle invalid user input gracefully would be insightful.

// 6. **Memory Management**:
//   - Although the code handles memory management for the map container automatically, discussing memory allocation and deallocation in C++ and the role of smart pointers or manual memory management could add depth to the discussion.

// 7. **Alternative Implementations**:
//   - You can explore alternative implementations for the dictionary, such as using custom binary search tree implementations or other data structures like hash tables, and discuss their advantages and disadvantages compared to the current implementation.

// 8. **Optimization Opportunities**:
//   - Discussing potential optimizations, such as caching frequently accessed entries or optimizing search operations, could demonstrate a deeper understanding of the code and data structures.

// 9. **Testing and Debugging**:
//   - Discussing strategies for testing and debugging the code, such as writing test cases or using debugging tools, could showcase software development best practices.

// 10. **Scalability and Performance**:
//     - Considerations for scalability and performance, such as the impact of increasing the size of the dictionary or optimizing for memory usage or speed, could be discussed.


Line by line explaination :

Here's a line-by-line explanation of the provided code:

1. `#include <iostream>`: Includes the standard input/output stream library for handling input and output operations.

2. `#include <map>`: Includes the map library, which provides a container to store key-value pairs.

3. `using namespace std;`: Declares that entities from the `std` namespace are to be used by default, saving the need to prefix them with `std::`.

4. `map<string, string> dictionary;`: Declares a map named `dictionary` with key-value pairs of type `string`. Keys represent keywords, and values represent their meanings.

5. `void AddKeyword() { ... }`: Defines a function `AddKeyword()` to add a new keyword and its meaning to the dictionary.

6. `void DeleteKeyword() { ... }`: Defines a function `DeleteKeyword()` to delete a keyword and its corresponding meaning from the dictionary.

7. `void UpdateKeyword() { ... }`: Defines a function `UpdateKeyword()` to update the meaning of an existing keyword in the dictionary.

8. `void DisplayAscending() { ... }`: Defines a function `DisplayAscending()` to display the contents of the dictionary in ascending order of keys.

9. `void DisplayDescending() { ... }`: Defines a function `DisplayDescending()` to display the contents of the dictionary in descending order of keys.

10. `void FindMaxComparisons() { ... }`: Defines a function `FindMaxComparisons()` to find the maximum number of comparisons required to find a keyword in the dictionary.

11. `int main() { ... }`: Defines the main function, the entry point of the program.

12. Inside the `main` function, a menu-driven loop is implemented using a `do-while` loop to repeatedly display a menu of dictionary operations and execute the corresponding functions based on user input.

13. The menu options include adding a keyword (`AddKeyword()`), deleting a keyword (`DeleteKeyword()`), updating the meaning of a keyword (`UpdateKeyword()`), displaying the dictionary in ascending or descending order (`DisplayAscending()` and `DisplayDescending()`), finding the maximum comparisons to find a keyword (`FindMaxComparisons()`), and exiting the program.

14. The program terminates when the user chooses the exit option (`7`).



Algorithm :

Here's the algorithm for the provided code:

1. **Initialization**:
   - Include necessary libraries (`<iostream>` and `<map>`).
   - Declare a map named `dictionary` to store keyword-meaning pairs.

2. **Function Definitions**:
   - Define functions to perform dictionary operations:
     - `AddKeyword()`: Adds a new keyword and its meaning to the dictionary.
     - `DeleteKeyword()`: Deletes a keyword and its corresponding meaning from the dictionary.
     - `UpdateKeyword()`: Updates the meaning of an existing keyword in the dictionary.
     - `DisplayAscending()`: Displays the dictionary contents in ascending order of keys.
     - `DisplayDescending()`: Displays the dictionary contents in descending order of keys.
     - `FindMaxComparisons()`: Finds the maximum number of comparisons required to find a keyword in the dictionary.

3. **Main Function**:
   - Define the `main()` function, the entry point of the program.
   - Inside `main()`, implement a menu-driven loop using a `do-while` loop.
   - Display a menu of dictionary operations and prompt the user for input.
   - Based on the user's choice, execute the corresponding function to perform the selected operation.
   - Repeat the loop until the user chooses to exit the program.

4. **Menu Options**:
   - Each menu option corresponds to a specific dictionary operation:
     - `AddKeyword()`: Adds a keyword-meaning pair to the dictionary.
     - `DeleteKeyword()`: Deletes a keyword from the dictionary.
     - `UpdateKeyword()`: Updates the meaning of an existing keyword.
     - `DisplayAscending()`: Displays the dictionary contents in ascending order of keys.
     - `DisplayDescending()`: Displays the dictionary contents in descending order of keys.
     - `FindMaxComparisons()`: Finds the maximum number of comparisons required to find a keyword.
     - `Exit`: Terminates the program.

5. **Termination**:
   - The program terminates when the user chooses the exit option (`7`).
*/

