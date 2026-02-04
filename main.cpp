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

      add(head, newNode);

    }

    else if(strcmp(command, "PRINT") ==0){

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
  }




}
