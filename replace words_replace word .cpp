#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main() {
    ifstream myfile("hamna.txt");
    ofstream tempFile("temp.txt");
    string line, word, newWord = "NEW_WORD";
    string target = "TARGET_WORD"; // word to be replaced

    if (myfile.is_open() && tempFile.is_open()) {
        while (getline(myfile, line)) {
            stringstream ss(line);
            while (ss >> word) {
                if (word == target) {
                    tempFile << newWord << " ";
                } else {
                    tempFile << word << " ";
                }
            }
            tempFile << endl;
        }
        myfile.close();
        tempFile.close();
        
        // Replace original file with updated file
        remove("hamna.txt");
        rename("temp.txt", "hamna.txt");

        cout << "Word replaced successfully." << endl;
    } else {
        cout << "Unable to open file" << endl;
    }

    return 0;
}