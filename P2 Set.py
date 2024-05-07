set1 = set()
set2 = set()
print('Empty_set Data type=', type(set1))

def read_set():
    n = int(input("Enter how many elements you want to add in set A: "))
    for i in range(n):
        element = int(input("Enter a number: "))
        set1.add(element)
    
    n = int(input("Enter how many elements you want to add in set B: "))
    for i in range(n):
        element = int(input("Enter a number: "))
        set2.add(element)
    
    print("Set A =", set1)
    print("Set B =", set2)  

read_set()

op = 1
while op:
    print("---------- Menu ---------")
    print("1. Add (new Element) - Place a value into the set")
    print("2. Remove (element) - Remove the value")
    print("3. Contains (element) - Return true if element is in collection")
    print("4. Size () - Return number of values in collection")
    print("5. Intersection of two sets") 
    print("6. Union of two sets")
    print("7. Difference between two sets")
    ch = int(input("Enter your choice to perform an operation on the set: "))
    if ch == 1:
        x = int(input("Enter an element to add into set A: "))
        set1.add(x)
        print("After adding new data \nSet A =", set1)  # Print updated set1
    elif ch == 2:
        x = int(input("Enter an element to remove from set A: "))
        set1.remove(x)
        print("After removing the element \nSet A =", set1)  # Print updated set1
    elif ch == 3:
        x = int(input("Enter an element to check if it's in set A: "))
        if x in set1:
            print("Number Present in Set")
        else:
            print("Number is not Present in Set")
    elif ch == 4:
        print("Set A contains {} elements.".format(len(set1)))
    elif ch == 5:
        print(set1.intersection(set2), '----------', set1 & set2)
    elif ch == 6:
        print(set1.union(set2), '----------', set1 | set2)
    elif ch == 7:
        print(set1.difference(set2), '----------', set1 - set2)
        print(set1.symmetric_difference(set2), '----------', set1 ^ set2)
    op = int(input("Press 0 to exit and 1 to continue: "))































'''

Theory : 
time complexity is O(1)

# 1. **Set**:
#   - In mathematics and computer science, a set is a collection of distinct elements with no duplicate values.
#   - Sets are often represented using curly braces `{}`, and elements are separated by commas.
#   - Examples of sets: `{1, 2, 3}`, `{a, b, c, d}`, `{apple, banana, orange}`.

# 2. **Basic Set Operations**:
#   - **Union**: The union of two sets A and B, denoted as A ∪ B, is the set of all elements that are in A, in B, or in both.
#      - Example: If A = {1, 2, 3} and B = {3, 4, 5}, then A ∪ B = {1, 2, 3, 4, 5}.
   
#   - **Intersection**: The intersection of two sets A and B, denoted as A ∩ B, is the set of all elements that are in both A and B.
#      - Example: If A = {1, 2, 3} and B = {3, 4, 5}, then A ∩ B = {3}.

#   - **Difference**: The difference of two sets A and B, denoted as A - B (or A \ B), is the set of all elements that are in A but not in B.
#      - Example: If A = {1, 2, 3} and B = {3, 4, 5}, then A - B = {1, 2}.

#   - **Complement**: The complement of a set A with respect to a universal set U, denoted as A', is the set of all elements in U that are not in A.
#      - Example: If U = {1, 2, 3, 4, 5} and A = {1, 2, 3}, then A' = {4, 5}.

# 3. **Set Operations in Programming**:
#   - Most programming languages provide built-in data structures or libraries for working with sets.
#   - Sets are often implemented using hash tables or balanced trees for efficient operations.
#   - Common set operations include union, intersection, difference, and membership testing.

# 4. **Properties of Set Operations**:
#   - **Associativity**: (A ∪ B) ∪ C = A ∪ (B ∪ C) and (A ∩ B) ∩ C = A ∩ (B ∩ C)
#   - **Commutativity**: A ∪ B = B ∪ A and A ∩ B = B ∩ A
#   - **Distributivity**: A ∪ (B ∩ C) = (A ∪ B) ∩ (A ∪ C) and A ∩ (B ∪ C) = (A ∩ B) ∪ (A ∩ C)
#   - **Identity**: A ∪ ∅ = A and A ∩ U = A, where ∅ represents the empty set and U represents the universal set.

# 5. **Applications**:
#   - Set operations are widely used in various domains such as database querying, information retrieval, and data analysis.
#   - They are fundamental in solving problems involving data manipulation, filtering, and aggregation.





Line By Line Explanation:
Here's a line-by-line explanation of the provided code:

```python
# Create two empty sets and check their data type
set1 = set()
set2 = set()
print('Empty_set Data type=', type(set1))
```
1. `set1 = set()`: Creates an empty set named `set1`.
2. `set2 = set()`: Creates another empty set named `set2`.
3. `print('Empty_set Data type=', type(set1))`: Prints the data type of an empty set (`set`) to the console.

```python
def read_set():
    # Accepting elements for set1 and set2 from the user
    n = int(input("Enter how many elements you want to add in set A: "))
    for i in range(n):
        element = int(input("Enter a number: "))
        set1.add(element)
    
    n = int(input("Enter how many elements you want to add in set B: "))
    for i in range(n):
        element = int(input("Enter a number: "))
        set2.add(element)
    
    print("Set A =", set1)  # Print initial set1
    print("Set B =", set2)  # Print initial set2

read_set()
```
4. `def read_set():`: Defines a function named `read_set()` to read elements into `set1` and `set2`.
5. `n = int(input("Enter how many elements you want to add in set A: "))`: Prompts the user to enter the number of elements to add to `set1`.
6. `for i in range(n):`: Iterates `n` times.
7. `element = int(input("Enter a number: "))`: Prompts the user to enter an element.
8. `set1.add(element)`: Adds the entered element to `set1`.
9. Similar steps are repeated to read elements into `set2`.
10. `print("Set A =", set1)`: Prints the contents of `set1`.
11. `print("Set B =", set2)`: Prints the contents of `set2`.

```python
op = 1
while op:
    print("---------- Menu ---------")
    print("1. Add (new Element) - Place a value into the set")
    print("2. Remove (element) - Remove the value")
    print("3. Contains (element) - Return true if element is in collection")
    print("4. Size () - Return number of values in collection")
    print("5. Intersection of two sets") 
    print("6. Union of two sets")
    print("7. Difference between two sets")
    ch = int(input("Enter your choice to perform an operation on the set: "))
    if ch == 1:
        x = int(input("Enter an element to add into set A: "))
        set1.add(x)
        print("After adding new data \nSet A =", set1)  # Print updated set1
    elif ch == 2:
        x = int(input("Enter an element to remove from set A: "))
        set1.remove(x)
        print("After removing the element \nSet A =", set1)  # Print updated set1
    elif ch == 3:
        x = int(input("Enter an element to check if it's in set A: "))
        if x in set1:
            print("Number Present in Set")
        else:
            print("Number is not Present in Set")
    elif ch == 4:
        print("Set A contains {} elements.".format(len(set1)))
    elif ch == 5:
        print(set1.intersection(set2), '----------', set1 & set2)
    elif ch == 6:
        print(set1.union(set2), '----------', set1 | set2)
    elif ch == 7:
        print(set1.difference(set2), '----------', set1 - set2)
        print(set1.symmetric_difference(set2), '----------', set1 ^ set2)
    op = int(input("Press 0 to exit and 1 to continue: "))
```
12. `op = 1`: Initializes the variable `op` to 1.
13. `while op:`: Enters a while loop that continues as long as `op` is non-zero.
14. The following lines print the menu options for various set operations.
15. `ch = int(input("Enter your choice to perform an operation on the set: "))`: Prompts the user to enter a choice for set operation.
16. The `if`-`elif` statements perform different set operations based on the user's choice:
    - `1`: Add a new element to `set1`.
    - `2`: Remove an element from `set1`.
    - `3`: Check if an element is present in `set1`.
    - `4`: Print the size of `set1`.
    - `5`: Print the intersection of `set1` and `set2`.
    - `6`: Print the union of `set1` and `set2`.
    - `7`: Print the difference and symmetric difference of `set1` and `set2`.
17. `op = int(input("Press 0 to exit and 1 to continue: "))`: Prompts the user to continue or exit the program based on their choice.

This code allows the user to interactively perform various set operations on `set1` and `set2` using a menu-driven approach.



Algorithm :

Here's the algorithm for the provided Python code:

1. **Initialization**:
   - Initialize two empty sets, `set1` and `set2`.
   - Print the data type of an empty set to verify.

2. **Read Sets** (`read_set()` function):
   - Define a function `read_set()` to input elements into `set1` and `set2`.
   - Prompt the user to enter the number of elements for each set.
   - Iterate through the input process for each set:
     - Prompt the user to enter elements.
     - Add the entered elements to the respective sets.
   - Display the contents of `set1` and `set2`.

3. **Main Set Operations Loop**:
   - Initialize a loop with a flag variable `op` set to 1.
   - Display a menu of set operations.
   - Prompt the user to choose an operation.
   - Based on the user's choice (`ch`):
     - If `ch` is 1, add a new element to `set1`.
     - If `ch` is 2, remove an element from `set1`.
     - If `ch` is 3, check if an element is present in `set1`.
     - If `ch` is 4, print the size of `set1`.
     - If `ch` is 5, print the intersection of `set1` and `set2`.
     - If `ch` is 6, print the union of `set1` and `set2`.
     - If `ch` is 7, print the difference and symmetric difference of `set1` and `set2`.
   - Prompt the user to continue or exit the program by setting `op` accordingly.
'''