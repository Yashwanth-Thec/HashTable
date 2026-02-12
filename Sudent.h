File Edit Options Buffers Tools C++ Help
#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <cstring>

using namespace std;

class Student{
 public:
  Student(char firstInput[], char lastInput[], int idInput, float gpaIn);

  char* getFirst();
  char* getLast();
  int getID();
  float getGPA();

 private:
  char first[100];
  char last[100];
  int id;
  float gpa;
};

#endif















