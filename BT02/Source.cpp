#include "Header.h"

void initClass(Class& c, int n) {
	c.size = n;
	c.studentList = new Student[n];
}

void inputClass(Class& c) {
	for (int i = 0; i < c.size; i++) {
		cout << "Student " << i + 1 << endl;
		cout << "Name: ";
		cin.getline(c.studentList[i].name, 31);
		cout << "ID: ";
		cin.getline(c.studentList[i].id, 9);
		cout << "GPA: ";
		cin >> c.studentList[i].gpa;
		cin.ignore();
	}
}

void printName(Student s) {
	cout << s.name << endl;
}

void printNameAndID(Student s) {
	cout << s.name << ", " << s.id << endl;
}

void printFullInfo(Student s) {
	cout << s.name << ", " << s.id << ", " << s.gpa << endl;
}

void printClass(Class c, PrintMode printMode) {
	for (int i = 0; i < c.size; i++) {
		cout << i + 1 << ". ";
		printMode(c.studentList[i]);
	}
}

void readClassFromFile(Class& c, const char* path) {
	ifstream fin(path, ios::binary);
	if (!fin.is_open()) {
		cout << "Cannot open file!" << endl;
		return;
	}
	fin.read((char*)&c.size, sizeof(int));
	c.studentList = new Student[c.size];
	for (int i = 0; i < c.size; i++) {
		fin.read(c.studentList[i].name, 31);
		fin.read(c.studentList[i].id, 9);
		fin.read((char*)&c.studentList[i].gpa, sizeof(float));

	}
	fin.close();
}

void writeClassToFile(Class c, const char* path) {
	ofstream fout(path, ios::binary);
	if (!fout.is_open()) {
		cout << "Cannot open file!" << endl;
		return;
	}
	fout.write((char*)&c.size, sizeof(int));
	for (int i = 0; i < c.size; i++) {
		fout.write(c.studentList[i].name, 31);
		fout.write(c.studentList[i].id, 9);
		fout.write((char*)&c.studentList[i].gpa, sizeof(float));
	}
	fout.close();
	cout << "Successfully! Filename is " << path << endl;
}

int compareName(Student a, Student b) {
	return strcmp(a.name, b.name);
}

int compareID(Student a, Student b) {
	return strcmp(a.id, b.id);
}

int compareGPA(Student a, Student b) {
	if (a.gpa < b.gpa) return -1;
	if (a.gpa > b.gpa) return 1;
	return 0;
}

void sortClass(Class& c, StudentPtr compare) {
	for (int i = 0; i < c.size - 1; i++) {
		for (int j = i + 1; j < c.size; j++) {
			if (compare(c.studentList[i], c.studentList[j]) > 0) {
				swap(c.studentList[i], c.studentList[j]);
			}
		}
	}
}

void popClass(Class& c, char* id) {
	for (int i = 0; i < c.size; i++) {
		if (strcmp(c.studentList[i].id, id) == 0) {
			for (int j = i; j < c.size - 1; j++) {
				c.studentList[j] = c.studentList[j + 1];
			}
			c.size--;
			i--;
		}
	}
}

void popClass(Class& c, float minGPA) {
	for (int i = 0; i < c.size; i++) {
		if (c.studentList[i].gpa < minGPA) {
			for (int j = i; j < c.size - 1; j++) {
				c.studentList[j] = c.studentList[j + 1];
			}
			c.size--;
			i--;
		}
	}
}

void deleteClass(Class& c) {
	delete[] c.studentList;
	c.studentList = nullptr;
	c.size = 0;
}

void addStudent(Class& c, Student s, StudentPtr addMode) {
	Student* temp = new Student[c.size + 1];
	for (int i = 0; i < c.size; i++) {
		temp[i] = c.studentList[i];
	}
	temp[c.size] = s;
	delete[] c.studentList;
	c.studentList = temp;
	c.size++;
	sortClass(c, addMode);
}

void splitClass(Class& c, Class& c1, Class& c2) {
	c1.size = c.size / 2;
	c2.size = c.size - c1.size;
	c1.studentList = new Student[c1.size];
	c2.studentList = new Student[c2.size];
	for (int i = 0; i < c1.size; i++) {
		c1.studentList[i] = c.studentList[i];
	}
	for (int i = 0; i < c2.size; i++) {
		c2.studentList[i] = c.studentList[c1.size + i];
	}
}

void mergeClass(Class& c, Class c1, Class c2) {
	c.size = c1.size + c2.size;
	c.studentList = new Student[c.size];
	for (int i = 0; i < c1.size; i++) {
		c.studentList[i] = c1.studentList[i];
	}
	for (int i = 0; i < c2.size; i++) {
		c.studentList[c1.size + i] = c2.studentList[i];
	}
}

void generateClass(Class& c, int n) {
	c.studentList = new Student[n];
	for (int i = 0; i < n; i++) {
		strcpy_s(c.studentList[i].name, nameList[rand() % 25]);

		// Generate unique id
		do {
			strcpy_s(c.studentList[i].id, idList[rand() % 25]);
		} while (isExisted(c, c.studentList[i].id));

		c.studentList[i].gpa = rand() % 101 / 10.0;
		c.size++;
	}
}

// Check if id is existed in class
bool isExisted(Class c, char* id) {
	for (int i = 0; i < c.size; i++) {
		if (strcmp(c.studentList[i].id, id) == 0) {
			return true;
		}
	}
	return false;
}
