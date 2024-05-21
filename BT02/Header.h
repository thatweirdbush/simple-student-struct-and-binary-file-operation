#pragma once
#include <iostream>
#include <fstream>

using namespace std;

static const char* nameList[] = {
	"Alice", "Bob", "Charlie", "David", "Eva", "Frank", "Grace", "Helen", "Ivy", "Jack",
	"Kate", "Liam", "Mia", "Nina", "Oscar", "Paul", "Quinn", "Ruth", "Sam", "Tina",
	"Uma", "Vince", "Wendy", "Xander", "Yara"
};

static const char* idList[] = {
	"21120001", "21120002", "21120003", "21120004", "21120005", "21120006", "21120007", "21120008", "21120009", "21120010",
	"21120011", "21120012", "21120013", "21120014", "21120015", "21120016", "21120017", "21120018", "21120019", "21120020",
	"21120021", "21120022", "21120023", "21120024", "21120025"
};

struct Student
{
	char name[31];
	char id[9];
	float gpa;
};

struct Class
{
	Student* studentList;
	int size;
};

// Initialize and manual input class
void initClass(Class& c, int n);
void inputClass(Class& c);

// Print class to console with specific mode using function pointer
typedef void(*PrintMode)(Student);
void printName(Student s);
void printNameAndID(Student s);
void printFullInfo(Student s);
void printClass(Class c, PrintMode printMode);

// Read and write class to binary file
void readClassFromFile(Class& c, const char* path);
void writeClassToFile(Class c, const char* path);

// Compare functions using function pointer
typedef int(*StudentPtr)(Student, Student);
int compareName(Student a, Student b);
int compareID(Student a, Student b);
int compareGPA(Student a, Student b);

void sortClass(Class& c, StudentPtr compare);
void popClass(Class& c, char* id);
void popClass(Class& c, float minGPA);
void deleteClass(Class& c);

// Add student to class with specific mode (by id, name, or gpa) using function pointer
typedef void(*AddMode)(Class&, Student);
void addStudent(Class& c, Student s, StudentPtr addMode);

void splitClass(Class& c, Class& c1, Class& c2);
void mergeClass(Class& c, Class c1, Class c2);

// Generate class with random students
void generateClass(Class& c, int n);

// Check if student with specific id is existed in class
bool isExisted(Class c, char* id);
