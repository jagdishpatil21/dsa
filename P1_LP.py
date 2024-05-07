import array as hashTable

def initialize(size):
    global hashTable
    hashTable = hashTable.array('i', [-1] * size)
    print("Empty Hash Table: ", hashTable)

def insertHash(value, size):
    key = value % size
    if hashTable[key] == -1:
        hashTable[key] = value
        print(value, "inserted at index", key)
    else:
        print("Collision: index", key, "has element", hashTable[key], "already!")
        print("Unable to insert", value, "into hash table")
        count = sum(1 for x in hashTable if x != -1)
        if count == size:
            print("Hash Table Is Full. Unable to insert", value)
            print(hashTable)
        else:
            i = key
            while hashTable[i] != -1:
                i = (i + 1) % size
            hashTable[i] = value
            print(value, "inserted at index", i)

def search(value, size):
    key = value % size
    if hashTable[key] == value:
        print(value, "found at index", key)
    else:
        print(value, "not found")

def delHash(value, size):
    key = value % size
    if hashTable[key] == value:
        hashTable[key] = -1
        print(value, "successfully deleted from hash table")
    else:
        print(value, "not found")

def printHashTable(size):
    for i, val in enumerate(hashTable):
        print("Index[", i, "] =", val)

def menu():
    print("\nMenu:")
    print("1. Insert")
    print("2. Search")
    print("3. Delete")
    print("4. Print Hash Table")
    print("5. Exit")

size = int(input("Enter size of hash table: "))
initialize(size)
while True:
    menu()
    choice = int(input("Enter your choice: "))
    if choice == 1:
        value = int(input("Enter value to insert: "))
        insertHash(value, size)
    elif choice == 2:
        value = int(input("Enter value to search: "))
        search(value, size)
    elif choice == 3:
        value = int(input("Enter value to delete: "))
        delHash(value, size)
    elif choice == 4:
        printHashTable(size)
    elif choice == 5:
        print("Exiting...")
        break
    else:
        print("Invalid choice")



























































''' explanation 

Sure, let's break down the code step by step:

1. import array as hashTable: This line imports the array module and aliases it as hashTable. The array module provides a way of creating arrays with specific data types.

2. size=7: This line sets the variable size to 7, indicating the size of the hash table array.

3. hashTable = hashTable.array('i',[-1]*size): This line creates an array named hashTable of size 7, initialized with -1 values. It uses the alias hashTable for the array module.

4. def initial():: This line defines a function named initial() which will print the initial state of the hash table.

5. print(hashTable): This line prints the initial state of the hash table.

6. def insertHash(value):: This line defines a function named insertHash() which is used to insert values into the hash table.

7. key = value % size;: This line calculates the key where the value will be inserted in the hash table using the modulo operator to ensure it fits within the size of the table.

8. if(hashTable[key] == -1):: This line checks if the calculated key is empty in the hash table.

9. hashTable[key] = value;: If the key is empty, this line inserts the value at the calculated key in the hash table.

10. print("Collision : arr",key,"has element",hashTable[key],"already!"): If there's a collision (i.e., the key is already occupied), this line prints a collision message.

11. i=0;count=0;: Initializes variables for counting elements in the hash table.

12. while(i<size):: Begins a loop to count the number of elements in the hash table.

13. if(count==size):: Checks if the hash table is full.

14. print("Hash Table Is Full Hence ",value," Can not Be Inserted"): Prints a message indicating that the hash table is full.

15. else:  #logic of linear probing: If the hash table is not full, this line initiates linear probing to find an empty slot for insertion.

16. for i in range(key, size):: This line starts a loop from the calculated key to the end of the hash table size for linear probing.

17. key1=(i+1)%size;: Calculates the next key using linear probing.

18. if(hashTable[key1] == -1):: Checks if the calculated key using linear probing is empty.

19. hashTable[key1] = value;: If the key is empty, inserts the value at the calculated key using linear probing.

20. print(hashTable): Prints the hash table along with data after insertion.

21. def search(value):: Defines a function named search() for searching values in the hash table.

22. if(hashTable[key]==value):: Checks if the value is found at the calculated key in the hash table.

23. print(value, "Found at", key,"th Index location"): Prints a message if the value is found.

24. def delHash(value):: Defines a function named delHash() for deleting values from the hash table.

25. if(hashTable[key]==value):: Checks if the value is found at the calculated key in the hash table for deletion.

26. hashTable[key]=-1;: If the value is found, sets the key to -1 to indicate deletion.

27. The rest of the code involves function calls and printing messages for inserting, searching, and deleting values in the hash table. 

Insertion (insertHash):
Best-case: O(1)
Worst-case: O(n)
Search (search):
Best-case: O(1)
Worst-case: O(n)
Deletion (delHash):
Best-case: O(1)
Worst-case: O(n)
Print Hash Table (printHashTable):
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
