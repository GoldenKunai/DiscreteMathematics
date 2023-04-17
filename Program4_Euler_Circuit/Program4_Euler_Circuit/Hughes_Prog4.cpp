#include <iostream>
#include <iomanip>
#include <fstream> 
using namespace std; 


// Purpose: Opens input and output files
// Receives: Requires some input and output file
// and reads in the data.
// Returns: Returns nothing
void openFiles(ifstream& infile, ofstream& outfile);


// Purpose: Opens input and output files
// Receives: Requires some input and output file
// and reads in the data.
// Returns: Returns nothing
void printEuler(ofstream& outfile, int &graphCount);


int main() {
    // Sets inputfile reserve word to infile
    ifstream infile;
    // Sets outfile reserve word to outfile
    ofstream outfile;
    // call to open files
    openFiles(infile, outfile);





    infile.close();
    outfile.close();
    return 0;
};

// Prototyped at the top of file
void openFiles(
    ifstream& infile,
    ofstream& outfile) { 
    // reads in input file as an array of 40 chars
    char inFileName[40];
    // reads in output file as an array of 40 chars
    char outFileName[40];
    // Prompts the user to enter input file
    cout << "Enter the input file name: ";
    // Where the user enters the name of the input file
    cin >> inFileName;
    // Opens input file
    infile.open(inFileName);
    // Prompts the user to enter output file
    cout << "Enter the output file name: ";
    // Where the user enters theo output file name
    cin >> outFileName;
    // open output file name
    outfile.open(outFileName);
}

void printEuler(ofstream& outfile, int &graphCount) {
    outfile << "Delton Hughes" << endl;
    outfile << "Euler Circuit: There are " << graphCount << " Graphs" << endl;
}