#include <iostream>
#include <fstream>
using namespace std;

class Record {
    int rollno;
    string name;
    int division;
    string address;

public:
    Record();
    int getRollno();
    void getData();
    void putData();
};

Record::Record() {
    rollno = 0;
    name = ' ';
    address = ' ';
    division = 0;
}

int Record::getRollno() {
    return (rollno);
}

void Record::getData() {
    cout << "\nEnter Details: ";
    cout << "\nRoll no: ";
    cin >> rollno;
    cout << "Name: ";
    cin >> name;
    cout << "Division Code: ";
    cin >> division;
    cin.ignore();
    cout << "Address: ";
    cin >> address;
}

void Record::putData() {
    cout << "\nRoll No.: ";
    cout << rollno;
    cout << "\t\tName: ";
    cout << name;
    cout << "\nDivision Code: ";
    cout << division;
    cout << "\tAddress: ";
    cout << address;
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
    fout.open("StudentDB", ios::ate | ios::app | ios::binary);
    fout.write(reinterpret_cast<const char *>(&r), sizeof(r));
    fout.close();
}

void File::display() {
    fin.open("StudentDB", ios::binary);
    if (!fin) {
        cout << "Error opening file.";
        return;
    }

    Record r;
    while (fin.read(reinterpret_cast<char *>(&r), sizeof(r))) {
        r.putData();
    }

    fin.close();
}

void File::search(int rollno) {
    Record r;
    int flag = 0;
    fin.open("StudentDB", ios::binary);
    if (!fin) {
        cout << "Error opening file.";
        return;
    }
    while (fin.read(reinterpret_cast<char *>(&r), sizeof(r))) {
        if (r.getRollno() == rollno) {
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

int File::Delete(int rollno) {
    Record r;
    int flag = 0;
    fin.open("StudentDB", ios::binary);
    if (!fin) {
        cout << "Error opening file.";
        return 0;
    }
    fout.open("Temp", ios::ate | ios::app | ios::binary);
    if (!fout) {
        cout << "Error opening file.";
        fin.close();
        return 0;
    }
    while (fin.read(reinterpret_cast<char *>(&r), sizeof(r))) {
        if (r.getRollno() == rollno) {
            flag = 1;
        }
        else {
            fout.write(reinterpret_cast<const char *>(&r), sizeof(r));
        }
    }
    fin.close();
    fout.close();
    remove("StudentDB");
    rename("Temp", "StudentDB");
    return flag;
}

int File::edit(int rollno) {
    Record r;
    int flag = 0;
    fs.open("StudentDB", ios::in | ios::out | ios::binary);
    if (!fs) {
        cout << "Error opening file.";
        return 0;
    }
    while (fs.read(reinterpret_cast<char *>(&r), sizeof(r))) {
        if (r.getRollno() == rollno) {
            flag = 1;
            cout << "\nEnter New Details: ";
            r.getData();
            fs.seekp((int)fs.tellg() - sizeof(r), ios::beg);
            fs.write(reinterpret_cast<const char *>(&r), sizeof(r));
        }
    }
    fs.close();
    return flag;
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
                cout << "\nEnter Roll No of Student Whose Record is to be Deleted: ";
                cin >> n;
                cin.ignore();
                i = f.Delete(n);
                if (i == 1)
                    cout << "\nRecord Deleted Successfully";
                else
                    cout << "\nRecord not Found";
                break;
            case 5:
                cout << "\nEnter Roll No of Student Whose Record is to be Edit: ";
                cin >> n;
                cin.ignore();
                i = f.edit(n);
                if (i == 1)
                    cout << "\nRecord Modified Successfully";
                else
                    cout << "\nRecord not Found";
                break;
            case 6:
                cout << "\nEnter Roll No of Student Whose Record is to be Searched: ";
                cin >> n;
                cin.ignore();
                f.search(n);
                break;
            case 7:
                break;
            default:
                cout << "\nEnter Valid Choice.....";
        }
    } while (ch != 7);
    return 0;
}










































/*
CODE EXPLATION

Header File Inclusion: Includes necessary header files for input/output operations and file handling. The using namespace std; directive allows using elements from the standard namespace without prefixing them with std::.
Record Class Definition: Defines a class named Record to represent student records. Private member variables include rollno, name, division, and address. Public member functions consist of a constructor Record(), getRollno() to retrieve the roll number, getData() to input record details, and putData() to display record details.
Constructor Initialization: The constructor Record::Record() initializes member variables rollno, name, address, and division to default values.
getRollno Function: The Record::getRollno() function retrieves and returns the roll number of the record.
getData Function: The Record::getData() function prompts the user to input record details such as roll number, name, division code, and address. It also clears the input buffer to prevent issues.
putData Function: The Record::putData() function displays the details of the record, including roll number, name, division code, and address.
File Class Definition: Defines a class named File to handle file operations such as insertion, display, search, deletion, and editing of records.
Insert Function: The File::insert() function inserts a new record into the file. It prompts the user to input record details and writes them to the file in binary mode.
Display Function: The File::display() function displays all records stored in the file. It reads each record from the file and calls putData() to display the details.
Search Function: The File::search(int rollno) function searches for a record with the given roll number in the file. It reads each record and compares the roll number to the specified value.
Delete Function: The File::Delete(int rollno) function deletes a record with the specified roll number from the file. It reads each record from the file, skips the record to be deleted, and writes the remaining records to a temporary file.
Edit Function: The File::edit(int rollno) function edits a record with the specified roll number in the file. It reads each record from the file, finds the record to be edited, updates its details, and writes it back to the file.
Main Function: The main() function serves as the entry point of the program. It creates an instance of the File class and presents a menu to the user for various operations like building a master table, listing the table, inserting, deleting, editing, searching records, and quitting the program.




Theory questions
Compare sequential file organization with direct access file organization:
Sequential File Organization: Data is stored in sequential order, and records are accessed sequentially from the beginning to the end. Accessing records randomly is inefficient.
Direct Access File Organization: Data is stored in such a way that records can be accessed directly using their physical location or address. This allows for quick random access to records, but it may require additional overhead for maintenance.
Short Notes:

Factors affecting file organization:
Record size, access patterns, storage medium characteristics, processing requirements, and security considerations influence the choice of file organization.
Indexed Sequential Files:
Combines characteristics of sequential and direct access methods. Records are stored sequentially, but an index is maintained for quick direct access to specific records.
Indexing Techniques:

Techniques like single-level indexing, multi-level indexing, and hash indexing are used to create and manage indexes for efficient record retrieval.
Basic Types of File Organization with Examples:
Sequential File Organization: Data is stored sequentially, and records are accessed in the order they are stored. Example: a text file containing a list of student names.
Direct Access File Organization: Data is stored in such a way that records can be accessed directly using their physical location or address. Example: a database file indexed by unique employee ID numbers.

Advantages, Disadvantages, and Primitive Operations of Sequential Files:
Advantages:
Simple to implement and maintain.
Efficient for applications with predominantly sequential access patterns.
Disadvantages:
Inefficient for random access operations.
Insertions and deletions may require extensive file reorganization.
Primitive Operations:

Time complexity
Sequential File Organization:
Read Operation: O(1) for accessing the next record sequentially.
Write Operation: O(1) for appending a record to the end of the file.
Search Operation: O(n) for searching a record by sequentially scanning the file.
Direct Access File Organization:
Read Operation: O(1) for accessing a record directly by its physical location or address.
Write Operation: O(1) for writing a record directly to its specified location.
Search Operation: O(1) if indexed, O(n) if searching without an index.
Indexed Sequential Files:
Read Operation: O(log n) for accessing a record using binary search on the index.
Write Operation: O(log n) for updating the index and inserting a new record.
Search Operation: O(log n) for searching a record using binary search on the index.
Indexing Techniques:
Single-level Indexing: O(log n) for searching using binary search on a single index.
Multi-level Indexing: O(log m) for searching using binary search on multiple levels of indexes.
Hash Indexing: O(1) for searching if the hash function provides constant-time access to the index.



Here's the algorithm for the provided code:

Record Class:
Define a class named Record to represent student records.
Declare private member variables rollno, name, division, and address.
Define public member functions: constructor Record() to initialize member variables, getRollno() to retrieve the roll number, getData() to input record details, and putData() to display record details.
File Class:
Define a class named File to handle file operations.
Declare private member variables fin, fout, and fs for file streams.
Define public member functions: insert() to insert a new record into the file, display() to display all records, search() to search for a record by roll number, Delete() to delete a record by roll number, and edit() to edit a record by roll number.
Insert Function (File::insert()):
Create a Record object and call getData() to input record details.
Open the file in append mode and write the record to the file.
Close the file.
Display Function (File::display()):
Open the file and seek to the beginning.
Read records from the file using a loop and call putData() to display each record.
Close the file.
Search Function (File::search()):
Open the file and seek to the beginning.
Read records from the file using a loop and compare the roll number with the given roll number.
If found, call putData() to display the record.
Close the file.
Delete Function (File::Delete()):
Open the file for reading and create a temporary file for writing.
Read records from the file using a loop.
If the roll number matches the given roll number, skip writing the record to the temporary file.
Close both files, delete the original file, and rename the temporary file to the original file name.
Edit Function (File::edit()):
Open the file for reading and writing.
Read records from the file using a loop.
If the roll number matches the given roll number, call getData() to input new record details and write the updated record to the file.
Close the file.
Main Function (main()):
Create an instance of the File class.
Present a menu to the user for various operations: insert, display, search, delete, edit, and quit.
Perform the selected operation based on user input until the user chooses to quit.
*/
