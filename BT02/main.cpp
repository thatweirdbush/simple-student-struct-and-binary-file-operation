#include "Header.h"

int main() {
	Class c;
	int n = 0;
	initClass(c, n);

	srand(unsigned int(time(NULL)));
	n = rand() % 10 + 10;
	cout << "Innit class with " << n << " students!\n";
	generateClass(c, n);

	cout << "\nPrint class with name mode:\n";
	printClass(c, printName);
	cout << "\nPrint class with name and id mode:\n";
	printClass(c, printNameAndID);
	cout << "\nPrint class with full info mode:\n";
	printClass(c, printFullInfo);

	cout << "\nWrite class to file:\n";
	const char* path = "output.bin";
	writeClassToFile(c, path);

	cout << "\nRead class from file:\n";
	readClassFromFile(c, path);
	printClass(c, printFullInfo);

	cout << "\nSort class by name:\n";
	sortClass(c, compareName);
	printClass(c, printName);

	cout << "\nSort class by ID:\n";
	sortClass(c, compareID);
	printClass(c, printNameAndID);

	cout << "\nSort class by GPA:\n";
	sortClass(c, compareGPA);
	printClass(c, printFullInfo);

	char id[9];
	do {
		strcpy_s(id, idList[rand() % 25]);
	} while (isExisted(c, id));

	cout << "\nPop students with ID " << id << endl;
	popClass(c, id);
	printClass(c, printFullInfo);

	float minGPA = 5.0;
	cout << "\nPop students with GPA < " << minGPA << endl;
	popClass(c, minGPA);
	printClass(c, printFullInfo);

	cout << "\nAdd student with ID " << id << " to class, sort by ID:\n";
	Student s;
	strcpy_s(s.id, id);
	strcpy_s(s.name, nameList[rand() % 25]);
	s.gpa = rand() % 101 / 10.0;
	addStudent(c, s, compareID);
	printClass(c, printNameAndID);


	Student s1;
	do {
		strcpy_s(s1.id, idList[rand() % 25]);
	} while (isExisted(c, s1.id));
	strcpy_s(s1.name, nameList[rand() % 25]);
	s1.gpa = rand() % 101 / 10.0;

	cout << "\nAdd student with ID " << s1.id << ", name " << s1.name << " to class, sort by name:\n";
	addStudent(c, s, compareName);
	printClass(c, printNameAndID);


	Student s2;
	do {
		strcpy_s(s2.id, idList[rand() % 25]);
	} while (isExisted(c, s2.id));
	strcpy_s(s2.name, nameList[rand() % 25]);
	s2.gpa = rand() % 101 / 10.0;

	cout << "\nAdd student with ID " << s2.id << ", GPA " << s2.gpa << " to class, sort by GPA:\n";
	addStudent(c, s, compareGPA);
	printClass(c, printFullInfo);


	cout << "\nSplit class...";
	Class c1, c2;
	splitClass(c, c1, c2);
	cout << "\nClass 1:\n";
	printClass(c1, printFullInfo);
	cout << "\nClass 2:\n";
	printClass(c2, printFullInfo);

	cout << "\nMerge class 1 & class 2:\n";
	Class c4;
	mergeClass(c4, c1, c2);
	printClass(c4, printFullInfo);

	cout << "\nDelete classes...\n";
	deleteClass(c);
	deleteClass(c1);
	deleteClass(c2);
	deleteClass(c4);

	system("pause");
	return 0;
}