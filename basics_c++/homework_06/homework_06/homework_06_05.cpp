
#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

namespace fs = std::filesystem;
using namespace std;

int checkForFile(string fileName);
void searchContent(string fw, string fn);


int main() {

	cout << "Enter a word to search:" << endl;
	string wordToFound;
	getline(cin, wordToFound);
	
	cout << "\nEnter file name without (.txt):" << endl;
	string fileName;
	getline(cin, fileName);

	if (checkForFile(fileName)) {
		return 0;
	};

	searchContent(wordToFound, fileName);
	
	cout << "\n\nPress Enter to exit..." << endl;
	cin.get();
	return 0;
}

int checkForFile(string fileName) {

	if (fs::exists((fileName + ".txt"))) {
		cout << "\nFile \"" + fileName + ".txt\" is located." << endl;
		return 0;
	}
	else {
		cout << "\n\nFile not found!\n\n\nPress Enter to exit..." << endl;
		cin.get();
		return 1;
	}

};

void searchContent(string fw, string fn) {

	ifstream fin((fn + ".txt"), ios_base::in);
	if (fin.is_open()) {

		string buf;
		while (!fin.eof()) {
			getline(fin, buf);

			if (buf.find(fw) != string::npos) {
				buf = fw;
				break;
			}
		}
		if (buf == fw) {
			cout << "\nWord \"" << fw << "\" is contained in this file." << endl;
			buf = fw;
		}
		else {
			cout << "\nWord \"" << fw << "\" not found." << endl;
		}
		fin.close();
	}
};