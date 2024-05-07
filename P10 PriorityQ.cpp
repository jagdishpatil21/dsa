#include <queue>
#include <string>
#include <iostream>

using namespace std;

struct Patient {
  string name;
  int priority;

  Patient(const string& name, int priority) : name(name), priority(priority) {}
};

int main() {
  auto comparePatients = [](const Patient& p1, const Patient& p2) {
    return p1.priority > p2.priority;
  };

  priority_queue<Patient, vector<Patient>, decltype(comparePatients)> patientQueue(comparePatients);

  int numPatients;
  cout << "Enter the number of patients: ";
  cin >> numPatients;
  cin.ignore();

  for (int i = 0; i < numPatients; ++i) {
    string name;
    int priority;

    cout << "Enter name of patient " << i+1 << ": ";
    getline(cin, name);

    cout << "Enter priority of patient " << i+1 << " (1 for Serious, 2 for Non-serious, 3 for General Checkup): ";
    cin >> priority;
    cin.ignore();

    patientQueue.emplace(name, priority);
  }

  cout << "\nTreating patients:\n";
  while (!patientQueue.empty()) {
    Patient nextPatient = patientQueue.top();
    patientQueue.pop();

    string priorityStr;
    if (nextPatient.priority == 1)
        priorityStr = "Serious";
    else if (nextPatient.priority == 2)
        priorityStr = "Non-serious";
    else
        priorityStr = "General Checkup";

    cout << "Name: " << nextPatient.name << ", Priority: " << priorityStr << endl;
  }

  return 0;
}



































/*Sure, here's the explanation in a numbered line format:

#include <queue>: Includes the library for using queues.
#include <string>: Includes the library for using strings.
#include <iostream>: Includes the library for input/output operations.
struct Patient {: Defines a structure named Patient to hold patient information.
std::string name;: Declares a string member name in the Patient struct to store the patient's name.
int priority;: Declares an integer member priority in the Patient struct to store the patient's priority.
Patient(const std::string& name, int priority) : name(name), priority(priority) {}: Defines a constructor for the Patient struct that initializes its members with the provided values.
int main() {: Begins the main function, the entry point of the program.
auto comparePatients = [](const Patient& p1, const Patient& p2) {: Declares a lambda function comparePatients to define the comparison logic for the priority queue.
return p1.priority > p2.priority; }: Returns true if the priority of p1 is greater than the priority of p2.
std::priority_queue<Patient, std::vector<Patient>, decltype(comparePatients)> patientQueue(comparePatients);: Declares a priority queue named patientQueue that holds Patient objects and uses the custom comparison function comparePatients.
int numPatients;: Declares an integer variable numPatients to store the number of patients.
std::cout << "Enter the number of patients: ";: Displays a message prompting the user to enter the number of patients.
std::cin >> numPatients;: Reads the number of patients entered by the user and stores it in numPatients.
std::cin.ignore();: Ignores any remaining characters in the input buffer.
for (int i = 0; i < numPatients; ++i) {: Starts a loop to input patient data based on the number of patients.
std::string name;: Declares a string variable name to store the patient's name.
int priority;: Declares an integer variable priority to store the patient's priority.
std::cout << "Enter name of patient " << i+1 << ": ";: Displays a message prompting the user to enter the name of the patient.
std::getline(std::cin, name);: Reads the name of the patient entered by the user and stores it in name.
std::cout << "Enter priority of patient " << i+1 << " (1 for Serious, 2 for Non-serious, 3 for General Checkup): ";: Displays a message prompting the user to enter the priority of the patient.
std::cin >> priority;: Reads the priority of the patient entered by the user and stores it in priority.
std::cin.ignore();: Ignores any remaining characters in the input buffer.
patientQueue.emplace(name, priority);: Adds the patient to the priority queue with the entered name and priority.
std::cout << "\nTreating patients:\n";: Displays a message indicating the start of patient treatment.
while (!patientQueue.empty()) {: Starts a loop to treat patients until the priority queue is empty.
Patient nextPatient = patientQueue.top();: Gets the highest priority patient from the priority queue.
patientQueue.pop();: Removes the treated patient from the priority queue.
std::string priorityStr;: Declares a string variable priorityStr to store the priority as a string.
if (nextPatient.priority == 1): Checks if the priority of the patient is 1 (Serious).
priorityStr = "Serious";: Sets priorityStr to "Serious" if the patient's priority is 1.
else if (nextPatient.priority == 2): Checks if the priority of the patient is 2 (Non-serious).
priorityStr = "Non-serious";: Sets priorityStr to "Non-serious" if the patient's priority is 2.
else: Executes if the patient's priority is not 1 or 2.
priorityStr = "General Checkup";: Sets priorityStr to "General Checkup" for all other priorities.
std::cout << "Name: " << nextPatient.name << ", Priority: " << priorityStr << std::endl;: Displays the name and priority of the treated patient.
return 0;: Indicates successful execution of the program.


Time complexity: O(n log n)
Explanation: The priority queue operations involve inserting 'n' patients and treating them. Each insertion into the priority queue takes O(log n) time in the worst case, where 'n' is the number of elements in the priority queue. Since there are 'n' patients to insert, the total time complexity for inserting all patients is O(n log n). Additionally, treating each patient involves popping from the priority queue, which also takes O(log n) time per operation. Therefore, treating 'n' patients also takes O(n log n) time.


Topic Theory
Priority queue is an abstract data type in computer programming that supports the following three
operations:
1. insertWithPriority: add an element to the queue with an associated priority
2. getNext: remove the element from the queue that has the highest priority, and return it (also known
as &quot;PopElement(Off)&quot;, or &quot;GetMinimum&quot;)
3. peekAtNext (optional): look at the element with highest priority without removing it.
The rule that determines who goes next is called a queueing discipline. The simplest queueing discipline
is called FIFO, for &quot;first-in-first-out.&quot; The most general queueing discipline is priority queueing, in which
each customer is assigned a priority, and the customer with the highest priority goes first, regardless of
the order of arrival. The reason I say this is the most general discipline is that the priority can be based on
anything: what time a flight leaves, how many groceries the customer has, or how important the customer
is. Of course, not all queueing disciplines are &quot;fair,&quot; but fairness is in the eye of the beholder.
Priority Queue (as the name suggests) uses the priority queueing policy. As with most ADTs, there are a
number of ways to implement queues. Since a queue is a collection of items, we can use any of the basic
mechanisms for storing collections: arrays, lists, or vectors. Our choice among them will be based in part
on their performance--- how long it takes to perform the operations we want to perform--- and partly on
ease of implementation.
Implementation
A priority queue can be implemented using data structures like arrays, linked lists, or heaps. The array
can be ordered or unordered.
Using an ordered array
The item is inserted in such a way that the array remains ordered i.e. the largest item is always in the end.
The insertion operation is illustrated in figure 1.



The item with priority 7 is inserted between the items with priorities 6 and 8. We can insert it at the end of
the queue. If we do so the array becomes unordered. Since we must scan through the queue in order to
find the appropriate position to insert the new item, the worst-case complexity of this operation is O(n).
Since the item with the highest priority is always in the last position, the dequeue and peek operation
takes a constant time.
Using an unordered array
We insert the item at the end of the queue. While inserting, we do not maintain the order. The complexity
of this operation is O(1). Since the queue is not ordered, we need to search through the queue for the item
with maximum priority. Once we remove this item, we need to move all the items after it one step to the
left. The dequeue operation is illustrated in figure 2.
It is obvious that the complexity of dequeue and peek operation is O(n).

Using a linked list
The linked can be ordered or unordered just like the array. In the ordered linked list, we can insert item so
that the items are sorted and the maximum item is always at the end (pointed by head or tail). The
complexity of enqueue operation is O(n) and dequeue and peek operation is O(1).

In an unordered linked list, we can insert the item at the end of the queue in constant time. The dequeue
operation takes linear time (O(n)) because we need to search through the queue in order to find the item
with maximum priority.


Using a binary heap
In above implementations using arrays and linked lists, one operation always takes linear time i.e. O(n).
Using binary heaps, we can make all the operations faster (in logarithmic time). Please read about the
binary heaps before using them in a priority queue.

Using a binary heap, the enqueue operation is insert operation in the heap. It takes O(log n) time in the
worst case. Similarly, the dequeue operation is the extract-max or remove-max operation which also takes
O(log n) time. The peek operation is a constant time operation. In this way, the binary heap makes the
priority queue operations a way faster.

ALGORITHM
ertainly! Here's a more technical algorithm corresponding to the provided C++ code:

Input Gathering Algorithm:
Prompt the user to input the number of patients.
Create an empty priority queue to store patients.
For each patient:
Prompt the user to input the patient's name and priority.
Create a Patient object with the provided name and priority.
Insert the Patient object into the priority queue.
Priority Queue Operations Algorithm:
The priority queue is implemented using a min-heap data structure.
The comparison function ensures that patients with higher priority values are placed closer to the root of the heap.
Inserting a patient into the priority queue involves maintaining the heap property by rearranging elements if necessary.
Removing a patient from the priority queue involves retrieving the root element (patient with the highest priority) and rearranging the heap to maintain its properties.
Treatment Algorithm:
Display a message indicating the start of patient treatment.
While the priority queue is not empty:
Retrieve the patient with the highest priority from the priority queue.
Remove the patient from the priority queue.
Determine the priority level of the treated patient.
Print out the name and priority of the treated patient.
*/




