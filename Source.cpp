#include<iostream>
using namespace std;

const int MAX_ROWS = 30;
const int MAX_REGNO = 5;
const int MAX_NAME = 20;

char calculateGrade(int);
void inputData(char[][MAX_REGNO], char[][MAX_NAME], int[], char[], int);
void printData(char[][MAX_REGNO], char[][MAX_NAME], int[], char[], int, char);
void printData(char[][MAX_REGNO], char[][MAX_NAME], int[], char[], int);




int main() {

	char regNo[MAX_ROWS][MAX_REGNO];
	char name[MAX_ROWS][MAX_NAME];
	int marks[MAX_ROWS];
	char grade[MAX_ROWS];

	int n, choice;
	bool isRepeat = true;
	char grd;


	cout << "Enter no of Students :";
	cin >> n;
	inputData(regNo, name, marks, grade, n);
	while (isRepeat)
	{
		cout << "1.Print Data" << endl << "2.Grade Filter" << endl << "3.Quit" << endl << "Choice: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			printData(regNo, name, marks, grade, n);
			break;
		case 2:
			cout << "Enter Students Grade A-F:";
			cin >> grd;
			while (grd<'A' || grd>'F')
			{
				cout << "Invalid \n Enter Students Grade A-F:";
				cin >> grd;
			}
			printData(regNo, name, marks, grade, n, grd);
		case  3:
			isRepeat = false;
		default:
			cout << "Invalid Choice" << endl;
		}
	}

}

void inputData(char regNo[][MAX_REGNO], char name[][MAX_NAME], int marks[], char grades[], int n) {
	char grade;
	for (int i = 0; i < n; i++) {
		
		cout << i + 1 << ". Enter Reg No: ";
		cin.getline(regNo[i], MAX_REGNO, '\n');
		cin.ignore(MAX_REGNO, '\n');
		cout << i + 1 << ". Enter Name: ";
		cin.getline(name[i], MAX_NAME, '\n');

		cout << i + 1 << ". Enter marks: ";
		cin >> marks[i];
		grade = calculateGrade(marks[i]);
		grades[i] = grade;
		

	}
}



char calculateGrade(int num) {
	if (num >= 90)
		return 'A';
	else if (num >= 80)
		return 'B';
	else if (num >= 70)
		return 'C';
	else if (num >= 60)
		return 'D';
	else if (num >= 50)
		return 'E';

	return 'F';
}

void printData(char regNo[][MAX_REGNO], char name[][MAX_NAME], int marks[], char grades[], int n) {

	cout << "No." << '\t' << "Reg NO." << '\t' << "Name" << "\t\t" << "Marks" << '\t' << "Grade" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << i + 1 << '\t' << regNo[i] << '\t' << name[i] << "\t\t" << marks[i] << '\t' << grades[i] << endl;
	}
}

void printData(char regNo[][MAX_REGNO], char name[][MAX_NAME], int marks[], char grades[], int n, char ch) {
	cout << "No." << '\t' << "Reg NO." << '\t' << "Name" << "\t\t" << "Marks" << '\t' << "Grade" << endl;
	for (int i = 0; i < n; i++)
	{
		if (grades[i] == ch)
			cout << i + 1 << '\t' << regNo[i] << '\t' << name[i] << "\t\t" << marks[i] << '\t' << grades[i] << endl;
	}
}