#include <iostream>
#include <fstream>
using namespace std;

class Record {
    int id;
    string name;
    int salary;
    string designation;

public:
    Record();
    int getIdno();
    void getData();
    void putData();
};

Record::Record() {
    id = 0;
    name = ' ';
    designation = ' ';
    salary = 0;
}

int Record::getIdno() {
    return (id);
}

void Record::getData() {
    cout << "\nEnter Details: ";
    cout << "\nId no: ";
    cin >> id;
    cout << "Name: ";
    cin >> name;
    cout << "Salary: ";
    cin >> salary;
    cout << "Designation: ";
    cin >> designation;
}

void Record::putData() {
    cout << "\nId No.: ";
    cout << id;
    cout << "\t\tName: ";
    cout << name;
    cout << "\nSalary: ";
    cout << salary;
    cout << "\tDesignation: ";
    cout << designation;
}

class File {
    ifstream fin;
    ofstream fout;
    fstream fs;

public:
    void insert();
    void display();
    void search(int);
    int Delete(int);
    int edit(int);
};

void File::insert() {
    Record r;
    r.getData();
    fout.open("EmployeeDB", ios::ate | ios::app);
    fout.write((char *)&r, sizeof(r));
    fout.close();
}

void File::display() {
    Record r;
    fin.open("EmployeeDB");
    fin.seekg(0, ios::beg);
    while (fin.read((char *)&r, sizeof(r)))
        r.putData();

    fin.close();
}

void File::search(int id) {
    Record r;
    int flag = 0;
    fin.open("EmployeeDB");
    fin.seekg(0, ios::beg);
    while (fin.read((char *)&r, sizeof(r))) {
        if (r.getIdno() == id) {
            flag = 1;
            break;
        }
    }

    fin.close();
    if (flag == 1) {
        cout << "\nRecord Found:";
        r.putData();
    }
    else
        cout << "\nRecord not Found ";
}

int File::Delete(int id) {
    Record r;
    int flag = 0;
    fin.open("EmployeeDB");
    fout.open("Temp", ios::ate | ios::app);
    fin.seekg(0, ios::beg);
    while (fin.read((char *)&r, sizeof(r))) {
        if (r.getIdno() == id) {
            flag = 1;
        }
        else {
            fout.write((char *)&r, sizeof(r));
        }
    }
    fin.close();
    fout.close();
    remove("EmployeeDB");
    rename("Temp", "EmployeeDB");
    return (flag);
}

int File::edit(int id) {
    Record r;
    int flag = 0;
    fs.open("EmployeeDB");
    fs.seekg(0, ios::beg);
    while (fs.read((char *)&r, sizeof(r))) {
        if (r.getIdno() == id) {
            flag = 1;
            cout << "\nEnter New Details: ";
            r.getData();
            fs.seekp((int)fs.tellg() - sizeof(r), ios::beg);
            fs.write((char *)&r, sizeof(r));
        }
    }
    fs.close();
    return (flag);
}

int main() {
    File f;
    int ch, n, i, flag = 0;
    do {
        cout << "\n\n\t-----M E N U-----";
        cout << "\n\n1. Build A Master Table";
        cout << "\n2. List A Table";
        cout << "\n3. Insert a New Entry";
        cout << "\n4. Delete Old Entry";
        cout << "\n5. Edit an Entry";
        cout << "\n6. Search for a Record";
        cout << "\n7. Quit";
        cout << "\nEnter your Choice: ";
        cin >> ch;
        switch (ch) {
            case 1:
                if (flag == 0) {
                    cout << "\nEnter No of Records to insert : ";
                    cin >> n;
                    for (i = 0; i < n; i++) {
                        f.insert();
                    }
                    flag = 1;
                }
                else {
                    cout << "\nSorry.. Table is Already build... \n If want to add record please select Insert a New Entry in option.....";
                }
                break;
            case 2:
                f.display();
                break;
            case 3:
                f.insert();
                break;
            case 4:
                cout << "\nEnter Id No of Employee Whose Record is to be Deleted: ";
                cin >> n;
                i = f.Delete(n);
                if (i == 1)
                    cout << "\nRecord Deleted Successfully";
                else
                    cout << "\nRecord not Found";
                break;
            case 5:
                cout << "\nEnter Id No of Employee Whose Record is to be Edit: ";
                cin >> n;
                i = f.edit(n);
                if (i == 1)
                    cout << "\nRecord Modified Successfully";
                else
                    cout << "\nRecord not Found";
                break;
            case 6:
                cout << "\nEnter Id No of Employee Whose Record is to be Searched: ";
                cin >> n;
                f.search(n);
                break;
            case 7:
                break;
            default:
                cout << "\nEnter Valid Choice.....";
        }
    } while (ch != 7);
    return (0);
}































/*Sure, let's break down the code:

1. `#include <iostream>`: Includes the input-output stream library for C++.

2. `#include <fstream>`: Includes the file stream library for handling file operations.

3. `using namespace std;`: Specifies that names in the `std` namespace are to be used in this program without requiring explicit qualification.

4. `class Record { ... };`: Defines a class named `Record` to store information about an employee, including ID, name, salary, and designation.

5. `Record::Record() { ... }`: Defines the constructor for the `Record` class to initialize member variables.

6. `int Record::getIdno() { ... }`: Defines a member function to retrieve the ID number of a `Record` object.

7. `void Record::getData() { ... }`: Defines a member function to input data for a `Record` object from the user.

8. `void Record::putData() { ... }`: Defines a member function to display the data of a `Record` object.

9. `class File { ... };`: Defines a class named `File` to perform file operations on employee records.

10. `void File::insert() { ... }`: Defines a member function to insert a new employee record into a file.

11. `void File::display() { ... }`: Defines a member function to display all employee records stored in a file.

12. `void File::search(int id) { ... }`: Defines a member function to search for an employee record by ID.

13. `int File::Delete(int id) { ... }`: Defines a member function to delete an employee record from a file based on ID.

14. `int File::edit(int id) { ... }`: Defines a member function to edit an employee record in a file based on ID.

15. `int main() { ... }`: Defines the main function where the program execution begins.

16. `File f;`: Creates an object of the `File` class.

17. `int ch, n, i, flag = 0;`: Declares variables to store user choices, employee IDs, loop counters, and a flag.

18. `do { ... } while (ch != 7);`: Starts a do-while loop to display a menu and execute user-selected operations until the user chooses to quit.

19. `switch (ch) { ... }`: Switches based on the user's choice to perform different operations.

20. `case 1: ...`: Handles the case where the user chooses to build a master table by inserting employee records.

21. `case 2: ...`: Handles the case where the user chooses to list all employee records.

22. `case 3: ...`: Handles the case where the user chooses to insert a new employee record.

23. `case 4: ...`: Handles the case where the user chooses to delete an existing employee record.

24. `case 5: ...`: Handles the case where the user chooses to edit an existing employee record.

25. `case 6: ...`: Handles the case where the user chooses to search for an employee record by ID.

26. `case 7: ...`: Handles the case where the user chooses to quit the program.

27. `return 0;`: Indicates successful program termination.



The time complexity of the code is as follows:

1. Insertion: O(n)
2. Displaying: O(n)
3. Searching: O(n)
4. Deletion: O(n)
5. Editing: O(n)

Where 'n' is the number of records in the file.



Theory:

1. **Indexed Files:**
   - Indexed files use an index to facilitate random access to data records.
   - Example: A library catalog where books are indexed by their unique ISBN numbers, allowing users to quickly locate books by their ISBN without having to search through the entire catalog.
   - Comparison:
     - Sequential Access: Data is accessed sequentially from the beginning to the desired record.
     - Direct Access: Data can be accessed directly based on the record's index or key value, allowing for faster retrieval.

2. **Multi-Index File:**
   - A multi-index file contains multiple indexes, each providing a different key for accessing the data records.
   - Example: An employee database with indexes based on employee ID, name, and department. This allows users to search for employees using any of these attributes efficiently.

File organization refers to the relationship of the key of the record to the physical location of that record in
the computer file. File organization may be either physical file or a logical file. A physical file is a
physical unit, such as magnetic tape or a disk. A logical file on the other hand is a complete set of records
for a specific application or purpose. A logical file may occupy a part of physical file or may extend over
more than one physical file.

Some of the file organizations are
1. Sequential File Organization Heap File Organization
2. Hash/Direct File Organization
3. Indexed Sequential Access Method
4. B+ Tree File Organization
5. Cluster File Organization


ALGORITHM :

1. **Initialization**:
   - Define a `Record` class with attributes for employee details.
   - Define a `File` class with methods for file operations.

2. **Insertion**:
   - Create a new `Record` object and input data.
   - Append the record to the file.

3. **Display**:
   - Read each record from the file and display its data.

4. **Search**:
   - Search for a record with a given ID in the file.
   - Display the record if found.

5. **Deletion**:
   - Search for a record with a given ID in the file.
   - Delete the record if found.

6. **Editing**:
   - Search for a record with a given ID in the file.
   - Update the record with new data.

7. **Main Function**:
   - Create a `File` object.
   - Display a menu to the user with options.
   - Perform corresponding operations based on user input.
   - Repeat until the user chooses to quit.


*/


