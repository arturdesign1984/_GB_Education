
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#pragma pack(push, 1)
struct Employe {

	uint32_t ID;
	string name;
	char gender;

};
#pragma pack(pop)

void saveToFile(Employe*);

int main()
{

	Employe* emp = new Employe;
	emp->ID = 100;
	emp->name = "Mandy";
	emp->gender = 'F';

	
	cout << "ID: " << emp->ID << " | Name: " << emp->name << " | Gender: " << emp->gender << " | size: " << sizeof(Employe) << endl;

	saveToFile(emp);

	return 0;
}

void saveToFile(Employe* emp) {

	ofstream fout;
	fout.open(emp->name + ".txt");
	fout << "ID: " << emp->ID << " | Name: " << emp->name << " | Gender: " << emp->gender << endl;
}