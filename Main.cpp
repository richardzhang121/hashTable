//Zhang, Richard; This program implements the hashing algorithm and handles collisions
#include <iostream>
#include <cstring>
#include "HashTable.hpp"
#include "randomStudent.hpp"

using namespace std;

int main(){
  char input[25];
  cout << "Welcome to the Hash Table!" << endl;
  cout << "To begin, enter a command. (add, print, delete, random, quit)" << endl;
  HashTable hashtable;
  RandomStudents randomstudents("firstnames.txt", "lastnames.txt");//implements the files for random generated students
  bool running = true;
  while (running == true){
    cin.get(input, 25);
    cin.ignore();
    if(!strcmp(input, "add")){//when you want to add a student
      char firstname[30];
      char lastname[30];
      int id;
      float gpa;
      cout << "Please enter your student's first name" << endl;//firstname
      cin.get(firstname, 30);
      cin.ignore();
      cout << "Please enter your student's last name" << endl;//lastname
      cin.get(lastname, 30);
      cin.ignore();
      cout << "Please enter your student's ID" << endl;//ID
      cin >> id;
      cin.ignore();
      cout << "Please enter your student's gpa" << endl;//GPA
      cin >> gpa;
      cin.ignore();
      hashtable.addStudent(firstname, lastname, id, gpa);
      cout << "Student successfully added!" << endl;
      cout << "Enter a command. (add, print, delete, random, quit)" << endl;
    }
    else if(!strcmp(input, "print")){//when you want to print out the student list
      hashtable.print();
      cout << endl;
      cout << "Enter a command. (add, print, delete, random, quit)" << endl;
    }
    else if(!strcmp(input, "delete")){//deleting a student
      int id;
      cout << "Please enter the ID of the student you would like to eliminate" << endl;
      cin >> id;
      cin.ignore();
      if(hashtable.deleteStudent(id)){
	cout << "Student successfully deleted!" << endl;
      }
      else{
	cout << "Try again. The student is not in the hash table." << endl;
      }
      cout << "Enter a command. (add, print, delete, random, quit)" << endl;
    }
    else if(!strcmp(input, "random")){//generates a random student with a select number of students
      int count;
      cout << "Enter the amount of students you would like to add." << endl;
      cin >> count;
      cin.ignore();
      for(int i = 0; i < count; i++){
	hashtable.addStudent(randomstudents.getFirstname(), randomstudents.getLastname(), randomstudents.getID(), randomstudents.getGPA());
      }
      cout << "Students successfully added." << endl;
      cout << "Enter a command. (add, print, delete, random, quit)" << endl;
    }
    else if(!strcmp(input, "quit")){//quits the program
      running = false;
    }
    else{//if the command is not found
      cout << "Invaild command. Try again por favor." << endl;
    }
  }
}