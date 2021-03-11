#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <cstdio>
using namespace std;

/*---variables---*/
char selection;
string name[3];
int age;
string username;
string birthday[3];
string password;
string password2;
string address[4];
int balance;
string container;
/*---Variables---*/


void ChangeAccountValues() {
	cout << "Input name\n";
	cout << "First name: ";
	cin >> name[0];
	cout << "Middle name: ";
	cin >> name[1];
	cout << "Last name: ";
	cin >> name[2];

	cout << "Input Birthday\n";
	cout << "Month: ";
	cin >> birthday[0];
	cout << "Day: ";
	cin >> birthday[1];
	cout << "Year: ";
	cin >> birthday[2];

	cout << "Input age: ";
	cin >> age;

	cout << "Input address\n";
	cout << "House number: ";
	cin >> address[0];
	cout << "Street: ";
	cin >> address[1];
	cout << "barangay: ";
	cin >> address[2];
	cout << "city: ";
	cin >> address[3];

	cout << "Input balance: ";
	cin >> balance;

	ofstream writeFile(username + ".txt");
	writeFile << password << "\n";
	writeFile << username << "\n";
	writeFile << "Name: ";
	for (int i = 0; i < 3; i++) {
		writeFile << name[i] << " ";
	}
	writeFile << "\n";
	writeFile << "Birthday: ";
	for (int i = 0; i < 3; i++) {
		writeFile << birthday[i] << " ";
	}
	writeFile << "\n";
	writeFile << "Age: " << age << "\n";
	writeFile << "Address: ";
	for (int i = 0; i < 4; i++) {
		writeFile << address[i] << " ";
	}
	writeFile << "\n";
	writeFile << "Balance: ";
	writeFile << balance << "\n";
	writeFile.close();

	cout << "Account values has been updated";
}

void print() {
	ifstream readFile(username + ".txt");

	string tempPassword;
	getline(readFile, tempPassword);
	password2 = tempPassword;

	string tempUsername;
	getline(readFile, tempUsername);

	string tempName;
	getline(readFile, tempName);

	string tempbirthday;
	getline(readFile, tempbirthday);

	string tempAge;
	getline(readFile, tempAge);
	
	string tempAddress;
	getline(readFile, tempAddress);

	string tempBalance;
	getline(readFile, tempBalance);
	

	cout << tempPassword << endl;
	cout << tempUsername << endl;
	cout << tempName << endl;
	cout << tempbirthday << endl;
	cout << tempAge << endl;
	cout << tempAddress << endl;
	cout << tempBalance << endl;
	readFile.close();
}

void Login() {
	cout << "Input username: ";
	cin >> username;
	string account = username + ".txt";

	ifstream readFile(username + ".txt");
	string tempPassword;
	getline(readFile, tempPassword);
	password2 = tempPassword;
	readFile.close();

	cout << "Input password: ";
	cin >> password;
	if (password == password2) {

		cout << "Please select a option below\n"
			"P - Print account values\n"
			"C - Change account values\n"
			"D - delete account\n";
		cin >> selection;
		switch (selection) {
		case 'p':
		case 'P':
			print();
			break;
		case 'c':
		case 'C':
			ChangeAccountValues();
			break;
		case 'd':
		case 'D':
			cout << "Are you sure you want to delete your account?\n"
				"[Y] - Yes\n"
				"[N] - No\n";
			cin >> selection;
			switch (selection) {
			case 'n':
			case 'N':
				break;
			case 'y':
			case 'Y':
				const char* c = account.c_str();
				remove(c);
				cout << "Your account has been deleted!";
				break;
			}
			break;
		default:
			cout << "Invalid input";
		}
	}
	else {
		cout << "Incorrect username/password or account does not exist";
	}
}

void Register() {
	cout << "Input username: ";
	cin >> username;

	cout << "Input password: ";
	cin >> password;

	cout << "Input name\n";
	cout << "First name: ";
	cin >> name[0];
	cout << "Middle name: ";
	cin >> name[1];
	cout << "Last name: ";
	cin >> name[2];

	cout << "Input age: ";
	cin >> age;

	cout << "Input Birthday\n";
	cout << "Month: ";
	cin >> birthday[0];
	cout << "Day: ";
	cin >> birthday[1];
	cout << "Year: ";
	cin >> birthday[2];

	cout << "Input address\n";
	cout << "House number: ";
	cin >> address[0];
	cout << "Street: ";
	cin >> address[1];
	cout << "barangay: ";
	cin >> address[2];
	cout << "city: ";
	cin >> address[3];

	cout << "Input balance: ";
	cin >> balance;

	ofstream writeFile(username + ".txt");
	writeFile << password << "\n";
	writeFile << username << "\n";
	writeFile << "Name: ";
	for (int i = 0; i < 3; i++) {
		writeFile << name[i] << " ";
	}
	writeFile << "\n";
	writeFile << "Birthday: ";
	for (int i = 0; i < 3; i++) {
		writeFile << birthday[i] << " ";
	}
	writeFile << "\n";
	writeFile << "Age: " << age << "\n";
	writeFile << "Address: ";
	for (int i = 0; i < 4; i++) {
		writeFile << address[i] << " ";
	}
	writeFile << "\n";
	writeFile << "Balance: ";
	writeFile << balance << "\n";
	writeFile.close();

	cout << "your account has been created!";
}

int main()
{
	cout << "Please choose an option: \n"
		"L - Login\n"
		"R - Register\n";
	cin >> selection;
	switch (selection) {
	case 'r':
	case 'R':
		Register();
		break;
	case 'l':
	case 'L':
		Login();
		break;
	default:
		cout << "Invalid input";
		break;
	}
}