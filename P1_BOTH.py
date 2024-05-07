table, tableq = {}, {}
totl, totq = 0, 0

def create(b):
  for i in range(b):
    table[i] = None
    tableq[i] = None

def linsert(key, b):
  global totl
  hash = key % b
  flag = 0
  if table[hash] == None:
    table[hash] = key
  else:
    for i in range(0, b):
      hash = (key + i) % b
      if table[hash] == None:
        table[hash] = key
        totl += 1
        flag += 1
        break
    if flag == 0:
      print("Table Full or Key not probed.")

def qinsert(key, b):
  global totq
  hash = key % b
  flag = 0
  if tableq[hash] == None:
    tableq[hash] = key
  else:
    for i in range(0, int((b - 1) / 2)):
      hash = (key + (i * i)) % b
      if tableq[hash] == None:
        tableq[hash] = key
        totq += 1
        flag += 1
        break
    if flag == 0:
      print("Table Full or Key not probed.")

def lsearch(key, b):
  hash = key % b
  flag = 0
  if table[hash] == None:
    print("Key:", key, " is not present.")
  else:
    for i in range(0, b):
      hash = (key + i) % b
      if table[hash] == None:
        print("Key:", key, " is not present.")
        flag += 1
        break
      elif table[hash] == key:
        print("Key:", key, " is present at location:", hash)
        flag += 1
        break
    if flag == 0:
      print("Key:", key, " is not present.")

def qsearch(key, b):
  hash = key % b
  flag = 0
  if tableq[hash] == None:
    print("Key:", key, " is not present.")
  else:
    for i in range(0, int((b - 1) / 2)):
      hash = (key + (i * i)) % b
      if tableq[hash] == None:
        print("Key:", key, " is not present.")
        flag += 1
        break
      elif tableq[hash] == key:
        print("Key:", key, " is present at location:", hash)
        flag += 1
        break
    if flag == 0:
      print("Key:", key, " is not present.")

def printtable(t1, b):
  print("Probed Table:")
  for i in range(b):
    print(t1[i], end="|")
  print("")

b = int(input("Enter the table size: "))
create(b)
while(1):
  ch = int(input("Enter 1-LP | 2-QP | 0-EXIT: "))
  if ch == 1:
    while(1):
      ch2 = int(input("Enter 1-Insert | 2-Search | 0-Back: "))
      if ch2 == 1:
        if totl == b:
          print("The table is already full.")
        else:
          key = int(input("Enter the key to be inserted in the table: "))
          linsert(key, b)
      elif ch2 == 2:
        key = int(input("Enter the key to be searched in the table: "))
        lsearch(key, b)
      elif ch2 == 0:
        print("GOING BACK")
        break
      printtable(table, b)
  elif ch == 2:
    while(1):
      ch2 = int(input("Enter 1-Insert | 2-Search | 0-Back: "))
      if ch2 == 1:
        if totq == b:
          print("The table is already full.")
        else:
          key = int(input("Enter the key to be inserted in the table: "))
          qinsert(key, b)
      elif ch2 == 2:
        key = int(input("Enter the key to be searched in the table: "))
        qsearch(key, b)
      elif ch2 == 0:
        print("GOING BACK")
        break
      printtable(tableq, b)
  elif ch == 0:
    print("EXITED")
    break


































'''
Sure, let's go through the code line by line:

1. `table, tableq = {}, {}`: Initializes two dictionaries `table` and `tableq` to represent hash tables.

2. `totl, totq = 0, 0`: Initializes two variables `totl` and `totq` to keep track of the total number of elements inserted into each hash table.

3. `def create(b):`: Defines a function named `create` that takes a parameter `b`.

4. `for i in range(b):`: Loops through numbers from 0 to `b - 1`.

5. `table[i] = None` and `tableq[i] = None`: Initializes each index of both hash tables to `None`.

6. `def linsert(key, b):`: Defines a function named `linsert` to insert elements into the linear probing hash table.

7. `def qinsert(key, b):`: Defines a function named `qinsert` to insert elements into the quadratic probing hash table.

8. `def lsearch(key, b):`: Defines a function named `lsearch` to search for elements in the linear probing hash table.

9. `def qsearch(key, b):`: Defines a function named `qsearch` to search for elements in the quadratic probing hash table.

10. `def printtable(t1, b):`: Defines a function named `printtable` to print the contents of a hash table.

11. `b = int(input("Enter the table size: "))`: Takes user input for the size of the hash tables.

12. `create(b)`: Calls the `create` function to initialize the hash tables with the specified size.

13. `while(1):`: Enters an infinite loop to continuously execute the program until explicitly exited.

14. `ch = int(input("Enter 1-LP | 2-QP | 0-EXIT: "))`: Takes user input to choose between linear probing, quadratic probing, or exiting the program.

15. `if ch == 1:`: Checks if the user chose linear probing.

16. `if ch == 2:`: Checks if the user chose quadratic probing.

17. `if ch == 0:`: Checks if the user chose to exit the program.

18. `while(1):`: Enters another infinite loop to perform operations based on the chosen probing method.

19. `ch2 = int(input("Enter 1-Insert | 2-Search | 0-Back: "))`: Takes user input to choose between insertion, search, or going back to the previous menu.

20. `if ch2 == 1:`: Checks if the user chose to insert an element into the hash table.

21. `if ch2 == 2:`: Checks if the user chose to search for an element in the hash table.

22. `if ch2 == 0:`: Checks if the user chose to go back to the previous menu.

23. `printtable(table, b)`: Calls the `printtable` function to print the contents of the linear probing hash table.

24. `printtable(tableq, b)`: Calls the `printtable` function to print the contents of the quadratic probing hash table.



Insertion (linear probing and quadratic probing):
Best-case: O(1)
Worst-case: O(n), where n is the size of the hash table.
Best-case: O(1)
Worst-case: O(n), 
Printing the hash table:
O(n), where n is the size of the hash table. This operation requires iterating through all elements in the hash table to print them.





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