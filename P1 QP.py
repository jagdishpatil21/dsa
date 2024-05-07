import array as hashTable

size = 7
hashTable = hashTable.array('l', [-1] * size)

def display():
    for i in range(0, 7):
        print("Index[", i, "]=", hashTable[i])

def insertHash(value):
    key = value % size
    if hashTable[key] == -1:
        hashTable[key] = value
        print(value, "inserted at arr", key)
    else:
        print("Collision : arr", key, "has element", hashTable[key], "already!")
        i = 0
        count = 0
        while i < 7:
            if hashTable[i] != -1:
                count += 1
            i += 1
        if count == 7:
            print("Hash Table Is Full Hence", value, "Can not Be Inserted")
            display()
        else:
            for i in range(0, 7):
                key1 = (key + i * i) % size
                if hashTable[key1] == -1:
                    hashTable[key1] = value
                    print(value, "inserted at arr", key1)
                    break

def search(value):
    key = value % size
    if hashTable[key] == value:
        print(value, "Found at", key, "th Index location")
    else:
        print(value, "Not Found at", key, "th Index location")

def delHash(value):
    key = value % size
    if hashTable[key] == value:
        print(value, "Successfully deleted from hash table")
        hashTable[key] = -1
    else:
        print(value, "Not Found at", key, "th Index location")

def initial():
    display()

def menu():
    print("\n\n\t-----MENU-----")
    print("1. Display Hash Table")
    print("2. Insert a Number")
    print("3. Search a Number")
    print("4. Delete a Number")
    print("5. Quit")

initial()

while True:
    menu()
    choice = int(input("Enter your choice: "))
    if choice == 1:
        display()
    elif choice == 2:
        num = int(input("Enter Telephone number to insert into Hash table: "))
        insertHash(num)
    elif choice == 3:
        num = int(input("Enter Telephone number to search in Hash table: "))
        search(num)
    elif choice == 4:
        num = int(input("Enter Telephone number to delete from Hash table: "))
        delHash(num)
    elif choice == 5:
        break
    else:
        print("Invalid choice. Please enter a number between 1 and 5.")






























'''
Sure, here's an explanation of each line in the provided code:

1. `import array as hashTable`: Imports the array module and aliases it as `hashTable`.
2. `size=7`: Sets the size of the hash table to 7.
3. `hashTable = hashTable.array('l',[-1]*size)`: Creates an array named `hashTable` of size 7, initialized with -1 at each index.
4. `def initial():`: Defines a function named `initial`.
5. `display()`: Calls the `display` function.
6. `def display():`: Defines a function named `display`.
7. `for i in range(0,7):`: Loops through indices 0 to 6.
8. `print("Index[",i,"]=", hashTable[i])`: Prints the index and corresponding value from the hash table.
9. `def insertHash(value):`: Defines a function named `insertHash` that takes a value as input.
10. `key = value % size;`: Computes the key for the value using the modulo operator with the size.
11. `if(hashTable[key] == -1):`: Checks if the calculated key in the hash table is empty.
12. `hashTable[key] = value;`: Inserts the value into the hash table at the calculated key.
13. `print(value,"inserted at arr",key);`: Prints a message indicating successful insertion.
14. `else:`: If the key is not empty (collision occurred), enters the else block.
15. `print("Collision : arr",key,"has element",hashTable[key],"already!");`: Prints a collision message.
16. `i=0;count=0;`: Initializes variables for loop control and counting.
17. `while(i<7):`: Starts a loop iterating through indices 0 to 6.
18. `if(hashTable[i]!=-1):`: Checks if the current index in the hash table is not empty.
19. `count+=1;`: Increments the count of non-empty slots.
20. `i+=1;`: Moves to the next index in the hash table.
21. `if(count==7):`: Checks if the hash table is full.
22. `print("Hash Table Is Full Hence ",value," Can not Be Inserted");`: Prints a message indicating that the value cannot be inserted.
23. `display();`: Calls the `display` function to show the hash table.
24. `else:`: Enters this block if the hash table is not full.
25. `for i in range(0, 7):`: Starts a loop to perform quadratic probing.
26. `key1=(key+i*i)%size;`: Calculates the new key using quadratic probing.
27. `if(hashTable[key1] == -1):`: Checks if the new key is empty.
28. `hashTable[key1] = value;`: Inserts the value into the hash table at the new key.
29. `print(value,"inserted at arr",key1);`: Prints a message indicating successful insertion.
30. `break;`: Exits the loop after successful insertion.
31. `def search(value):`: Defines a function named `search` that takes a value as input.
32. `key = value % size;`: Computes the key for the value using the modulo operator with the size.
33. `if(hashTable[key]==value):`: Checks if the value is found at the calculated key in the hash table.
34. `print(value, "Found at", key,"th Index location");`: Prints a message indicating successful search.
35. `else:`: If the value is not found, enters the else block.
36. `print(value, "Not Found at", key,"th Index location");`: Prints a message indicating unsuccessful search.
37. `def delHash(value):`: Defines a function named `delHash` that takes a value as input.
38. `key = value % size;`: Computes the key for the value using the modulo operator with the size.
39. `if(hashTable[key]==value):`: Checks if the value is found at the calculated key in the hash table.
40. `print(value, "Sussfully deleted from hash table");`: Prints a message indicating successful deletion.
41. `hashTable[key]=-1;`: Deletes the value by setting the corresponding index in the hash table to -1.
42. `else:`: If the value is not found, enters the else block.
43. `print(value, "Not Found at", key,"th Index location");`: Prints a message indicating unsuccessful deletion.
44. `initial();`: Calls the `initial` function to start the execution of the code.
45. `option=1`: Initializes the option variable to 1.
46. `while(option==1):`: Starts a loop based on the option variable.
47. `num=int(input("Enter Telephine number to insert into Hash table"));`: Takes input from the user to insert a telephone number into the hash table.
48. `insertHash(num);`: Calls the `insertHash` function to insert the input number into the hash table.
49. `display();`: Calls the `display` function to show the updated hash table.
50. `option=int(input("Enter 0 to Exit and 1 to read more Telephine number=>"));`: Takes input from the user to continue or exit the loop.
51. `num=int(input("Enter Telephine number to search in Hash table"));`: Takes input from the user to search for a telephone number in the hash table.
52. `search(num)`: Calls the `search` function to search for the input number in the hash table.
53. `num=int(input("Enter Telephine number to deleted from Hash table"));`: Takes input from the user to delete a telephone number from the hash table.
54. `delHash(num)`: Calls the `delHash` function to delete the input number from the hash table.
55. `for i in range(0,7):`: Loops through indices 0 to 6.
56. `print("Index[",i,"]=", hashTable[i])`: Prints the index and corresponding value from the hash table.






Insertion (insertHash):
Best-case: O(1)
Worst-case: O(n)
Search (search):
Best-case: O(1)
Worst-case: O(n)
Deletion (delHash):
Best-case: O(1)
Worst-case: O(n)
Display (display):
O(n)


Hashing is a method of directly computing the address of the record with the help of a key by using a
suitable mathematical function called the hash function. A hash table is an array-based structure used to
store pairs. In this chapter, we will learn about hashing, hash functions, and other related aspects.

Hash function: Hash function is one that maps a key in the range [0 to Max − 1], the result of which is
used as an index (or address) in the hash table for storing and retrieving records
Bucket: A bucket is an index position in a hash table that can store more than one record
Probe: Each action of address calculation and check for success is called as a probe.
Collision: The result of two keys hashing into the same address is called collision.
Synonym: Keys that hash to the same address are called synonyms.
Collision Resolution Strategies:
1. Open Hashing
2. Separate Chaining or Linked List
3. Closed Hashing:
4. Linear Probing
5. Quadratic Probing
6. Double Hashing
7. Rehashing
Here we have implemented Linear Probing and Quadratic probing.

Linear Probing: A hash table in which a collision is resolved by placing the item in the next empty place
following the occupied place is called linear probing. This strategy looks for the next free location until it
is found.

(Hash(x)+ i) MOD Max

Quadratic Probing:
In quadratic probing, we add the offset as the square of the collision probe number. In quadratic probing,
the empty location is searched by using the following formula:
(Hash(Key) + i 2) MO D Max where i lies between 1 and (Max - 1)/2

ALGORITHM:
Function linear_probe(key, value):
i = key
for i in range(key, size):
key1 = (i + 1) % size # Calculating next empty location address using linear probing formula
if hashTable[key1] == -1: # If location is empty, insert data
hashTable[key1] = value
print(value, &quot;inserted at arr&quot;, key1)
break

Function quadratic_probe(key, value):
for i in range(key, size):
key1 = (key + i*i) % size # Quadratic Probing formula
if hashTable[key1] == -1:
hashTable[key1] = value
print(value, &quot;inserted at arr&quot;, key1)
break

'''
