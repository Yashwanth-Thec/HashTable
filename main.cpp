#include<iostream>
#include<ctring>
#include<ctime>
#include<fstream>
#include<cstdlib>

using namespace std;

void add(Node*& head, Node* newNode);
void print(Node* head);
void remove(Node*& head, int id);
void average(Node* head, float& sum, int& count);
void quit(Node*& head);

//Prototype of the Hash Table
unsigned int hashID(int id, int tableSize);
int chainLength(Node* head);

Node** makeTable(int size);
void rehash(Node**& table, int& tableSize, int newSize);
void freeTable(Node**& table, int& newSize);

// Prototypes for the random generators
bool loadName(const char* filename, char** outArr, int& outCount);
void freeNames(char* arr, int count);
float randomGPA();
void generateStudents(Node**& table, int& tableSize, char** firtArr, int firstCount,char** lastArr, int lastCount, int& nextID, int howMany);

struct Student{
  char first[100]
  char last[100]
  int id;
  float gpa;
  Student* next;
}

int main(){
  int tableSize = 100;
  Node** table = makeTable(tableSize);


  while(running){
    if (strcmp(command, "ADD") == 0){
      cout << "First Name: ";
      cin >> first;

      cout <<"Last Name: ";
      cin >> last;

      cout << "ID: ";
      cin >> id;

      cout<<"GPA: ";
      cin>> gpa;

      Student* s = new Student(first, last, id, gpa);
      Node* newNode = new Node(s, nullptr);

      unsigned int idx = hashID(id, tableSize);

      while(chainLength(table[idx]) >=3){
	rehash(table, tableSize, tableSize*2);
	idx =hashID(id, tableSize);
      }

      add(table[idx], n);
      cout << "Student added." << endl;

    }

    
    
    else if(strcmp(command, "PRINT") ==0){

      bool empty = true;
      for (int i= 0; i < tableSize; i++){
	if(table[i] != nullptr){

	}

      if(head == nullptr){
	cout << "List is empty.";

      }
      else{
	print(head);
      }
	    
    }



    else if(strcmp(command, "DELETE") == 0){
      if (head ==  nullptr){
	cout << "List is empty.";
      }
      else {
	ind id;
	cout << "Enter the student ID to delete: ";
	cind >> id;

	remove(head, id);
      }

    }

    else if(strcmp(command, "AVERAGE") == 0){
      if (head == nullptr) {
	cout << "List is empty";
      }
      else {
	float sum = 0.0f;
	int count = 0;

	average(had, sum, count);

	cout << fixed << setprecision(2);
	cout << "Average GPA: " << (sum/count) << endl;
      }

    }
    else if(strcmp(command, "GENERATE") == 0) {
      int howMany;
      cout << "How many students do you want to generate: ";
      cin >> howMany;

      generateStudents(table, tableSize,firstCount, firstArr, lastCount, lastArr,nextGeneratedID, howMany );
    }

    else if(strcmp(command, "QUIT") == 0) {
      for(int i = 0; i < tableSize; i++) {
	if(table[i] != nullptr){
	  quit(table[i]);

	}

      }

      delete table[];
      freeNames(firstArr, firstCount);
      freeNames(lastArr, lastCount);

      running(false);


    }
    else{
      cout << "Invalid input";
    }

  }

    return 0;


}

unsigned int hasId(int id, int tableSize){
  unsigned int x = (unsigned int)id;
  unsigned int h = x * 2654435761u;
  return (unsigned int)(h%(unsigned int)tableSize);

}

Node** makeTable(int size){
  Node** t = new Node*[size];
  for (int i = 0; i <size; i++) t[i] = nullptr;
  return t;
}
void rehash(Node**& table, int& tableSize, int newSize) {
  Node** newTable = makeTable(newSize);

  for (int i =0; i < tableSize; i++) {
    Node* cur = table[i];
    while (cur != nullptr){
      Node* nxt = cur->get_next();
      cur->set_next(nullptr);

      int id = cur->get_value()->getID();
      unsigned int idx = hashID(id, newSize);

      add(newTable[idx], cur);
      cur = nxt;

    }
    table[i] = nullptr;

  }
  delete table[];
  table = newTable;
  tableSize = newSize;

  cout << "This has been Rehashed. The new table size is " << tableSize << endl;
}

 void freeTable(Node**& table, int& tableSize){
   if (!table) return;
   for (int i = 0; i < tableSize; i++){
     if table[i] != nullptr) quit(table[i]);
   }
   delete[] table;
   table =nullptr;
   tableSize = 0;
 

}

bool loadNames(const char* filename, char** outArr,  int& outCount){
  ifstram fin(filename);
  if(!fin) return false;

  chat line[250];
  outCount = 0;

  while (fin.getline(line, 250)){
    if(strlen(line) > 0) outCount++;

  }
  fin.clear();
  fin.seekg(0);

  if (outCount == 0) reutrn false;

  char** arr new char*[outCount];
}

// This is the recursion for adding
void add(Node*& head, Node* newNode) {
  if (head == nullptr || newNode->get_value()->getID() < head->get_value()->getID()) {
      newNode->set_next(head);
      head = newNode;
      return;
  }

  Node* nextNode = head->get_next();
  add(nextNode, newNode);
  head->set_next(nextNode);
}




//Recursion for printing
void print(Node* head) {
  if (head == nullptr) return;

  Student* s = head->get_value();
  cout << s->getFirst() << " " << s->getLast()
       << ", " << s->getID() << ", "
       << fixed << setprecision(2) << s->getGPA() << endl;

  print(head->get_next());
}

void remove(Node*& head, int id) {
  if (head == nullptr) {
      cout << "ID not found.\n";
      return;
  }

  if (head->get_value()->getID() == id) {
      Node* temp = head;
      head = head->get_next();

      delete temp->get_value(); // This deletes the Student
      delete temp;              // This deletes Node by calling destructor

      cout << "Deleted.\n";
      return;
  }

  Node* nextNode = head->get_next();
  remove(nextNode, id);
  head->set_next(nextNode);
}
//This is the recursion for Average
void average(Node* head, float& sum, int& count) {
  if (head == nullptr) return;

  sum += head->get_value()->getGPA();
  count++;

  average(head->get_next(), sum, count);
}

//This is the recursion for Quiting
void quit(Node*& head) {
  if (head == nullptr) return;

  Node* nextNode = head->get_next();

  delete head->get_value();
  delete head;
  head = nullptr;

  quit(nextNode);
}

