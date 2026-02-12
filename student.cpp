#include "Student.h"

Student::Student(char firstIn[], char lastIn[], int idInput, float gpaIn){
  strcpy(first, firstIn);
  strcpy(last, lastIn);
  id = idInput;
  gpa = gpaIn;
}

char* Student::getFirst(){
  return first;


}

char* Student::getLast(){
  return last;
}

int Student::getID(){
  return id;
}

float Student::getGPA(){
  return gpa;
}

