/*******************************************************************
 *
 *  Author:           Delton Hughes
 *  Email:            dlhughes0129@my.msutexas.edu
 *  Label:            Program 3
 *  Title:            Greeding Scheduling
 *  Course:           CMPS 2433
 *  Semester:         Spring 2023
 *
 *  Description:
 *      
 *
 *
 *  Usage:
 *
 *
 *  Files:   source.cpp
 *           greedydata.txt
 *           output.dat
 *
 ******************************************************************/
#include <iostream>
#include <fstream>
#include <vector> 
using namespace std;

struct Schedule {
    int start_time;
    int length;
    int end_time;
    int max_num = 0;

    Schedule(int s=0, int l=0) {

        end_time = s + l; 
    }
};



// Purpose: Opens input and output files
// Receives: Requires some input and output file
// and reads in the data.
// Returns: Returns nothing
void openFiles(ifstream& infile, ofstream& outfile);

// Purpose: Prints to outfile
// Receives: Requires output file
// Returns: Returns nothing
void printHeader(ofstream& outfile);


// Purpose: Prints to outfile
// Receives: Requires output file
// Returns: Returns nothing
void greedySched(ifstream& infile, ofstream& outfile);



int main() {
    // Sets inputfile reserve word to infile
    ifstream infile;
    // Sets outfile reserve word to outfile
    ofstream outfile;
    //Created instance of a schedule
    Schedule a;
    // call to open files
    openFiles(infile, outfile);
    //Printing of the header to output file
    printHeader(outfile);

    greedySched(infile, outfile);

    infile.close();
    outfile.close();
    return 0;
}

//Prototyped at the top of file
void openFiles(ifstream& infile, ofstream& outfile)
{   //reads in input file as an array of 40 chars
    char inFileName[40];
    //reads in output file as an array of 40 chars
    char outFileName[40];
    //Prompts the user to enter input file
    cout << "Enter the input file name: ";
    //Where the user enters the name of the input file
    cin >> inFileName;
    //Opens input file
    infile.open(inFileName);
    //Prompts the user to enter output file
    cout << "Enter the output file name: ";
    //Where the user enters theo output file name
    cin >> outFileName;
    //open output file name 
    outfile.open(outFileName);

}

//Prototyped at the top of file
void printHeader(ofstream& outfile) {
    cout << "Delton Hughes" << endl;
    outfile << "Delton Hughes" << endl;
    cout << "Program 3: Greedy Scheduling/Sorting Program" << endl;
    outfile << "Program 3: Greedy Scheduling/Sorting Program" << endl;

}

void printGreedy(ofstream& outfile) {

}

//Prototyped at the top of file
void greedySched(ifstream& infile, ofstream& outfile) 
{
    int dataSize;



    infile >> dataSize;
    vector<int> startTime(dataSize);
    vector<int> length(dataSize);
    vector<int> finalTime; 
    for (int i = 0; i < dataSize; i++) 
    {
  
        infile >> startTime[i] >> length[i];
        finalTime.push_back(startTime[i] + length[i]);
        cout << startTime[i] << " " << length[i] <<
            " " << finalTime[i] << endl;
    }
    
}

