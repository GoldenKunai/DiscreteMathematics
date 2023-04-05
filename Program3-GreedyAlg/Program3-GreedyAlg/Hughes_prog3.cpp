/*******************************************************************
 *
 *  Author:           Delton Hughes
 *  Email:            dlhughes0129@my.msutexas.edu
 *  Label:            Program 3
 *  Title:            Greeding Scheduling
 *  Course:           CMPS 2433
 *  Semester:         Spring 2023
 *
 *  Description:The goal of this program is to read in a given set
 *   of data, sort the finish time in increasing order, and
 *   lastly using a greedy algorithm we find the earliest starting
 *   time and the according finish time thats attached we will use
 *   that number and find a starting time thats greater than or equal
 *   to the start that is next in line.
 *  Files:   Hughes_prog3.cpp
 *           greedydata.txt
 *           output.dat
 *           test.txt
 *           test.dat
 *
 ******************************************************************/
#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

/***********************************************************
 * Schedule
 *
 * Description:
 *      - Allows us to make an instance of a schedule and
 *     sort the given set of data in a infile and print to
 *     an outfile to be manipulated.
 *
 * Private Members:
 *      - int startTime
 *      - int length
 *      - int finishTime
 * Public Methods:
 *      - Schedule()
 *      - Schedule(int s, int l, int f)
 *      - Schedule(vector<Schedule> temp, int locate)
 *      - void readFile(ifstream& infile, vector<Schedule>&temp)
 *      - void sortIncreasing(vector<Schedule>& temp)
 *      - int greedyAlg(vector<Schedule>& temp,vector<Schedule>& temp2)
 *      - void print(ofstream& outfile, vector<Schedule>temp, int count)
 **************************************************************/
class Schedule {
private:
    // creating variables for start, length, and finish time
    int startTime;
    int length;
    int finishTime;

public:
    // Purpose: Makes a default constructor for
    // setting them to zero.
    // Receives: Receives nothing
    // Returns: Returns nothing
    Schedule() {
        // sets each variable to 0
        startTime = 0;
        length = 0;
        finishTime = 0;
    }
    // Purpose:Assigns s,l,f to the member variables
    // startTime, length, finishTime.
    // Receives: 3 ints s,l,f
    // Returns: Returns nothing
    Schedule(int s, int l, int f) {
        startTime = s;
        length = l;
        finishTime = f;
    }
    // Purpose:Is allowing us to use a vector of schedules later
    // Receives: Requires vector<Schedule>, and locate
    // Returns: Returns nothing
    Schedule(vector<Schedule> temp, int locate) {
        // assigns the location in the vector of Schedules to temp
        // and assigns it to length
        length = temp[locate].length;
        // assigns the location in the vector of Schedules to temp
        // and assigns it to startTime
        startTime = temp[locate].startTime;
        // assigns the location in the vector of Schedules to temp
        // and assigns it to finishTime
        finishTime = temp[locate].finishTime;
    }

    // Purpose: Reads in the data from the input file
    // Receives: Requires input file, vector<Schedule>
    // Returns: Returns nothing
    void readFile(ifstream& infile, vector<Schedule>& temp) {
        int dataSize;
        int num, num2, num3;
        //read in the size of the data
        infile >> dataSize;
        //iterate through the data
        for (int d = 0; d < dataSize; ++d) {
            //read first row(start time)
            infile >> num;
            //read in second row (length)
            infile >> num2;
            //add the first second row make it equal to num3(finishTime)
            num3 = num + num2;
            //Make a list of vectors in the form of a Schedule 
            temp.push_back(Schedule(num, num2, num3));
        }
    }
    // Purpose: Sorts the finish times in increasing order
    // Receives: Requires vector<Schedule>
    // Returns: Returns nothing
    void sortIncreasing(vector<Schedule>& temp) {
        // These for loops will iterate over the vector
        // Compares it to ever element after it
        for (int i = 0; i < temp.size(); ++i) {
            for (int j = i + 1; j < temp.size(); ++j) {
                // As long as the index of i is greater than the index
                // of j than we will swap
                if (temp[i].finishTime > temp[j].finishTime) {
                    // creating copy of a Schedule object
                    Schedule temp1 = temp[i];
                    // moving i to j
                    temp[i] = temp[j];
                    // putting temp
                    temp[j] = temp1;
                }
            }
        }
    }

    // Purpose: Picks the data with the earliest starting time first
    // then looks at its finish time, then finds the next in line start
    // time that is greater or equal to the previous finish time so on.
    // Receives: Requires two vector<schedule>
    // Returns: Returns int count, which is a incremented counter
    int greedyAlg(vector<Schedule>& temp, vector<Schedule>& temp2) {
        int count = 0;
        //sort vector in increasing order
        sortIncreasing(temp);
        //sdd the first activity to temp2 and push it back
        temp2.push_back(temp[0]);
        //Iterate through
        for (int i = 1; i < temp.size(); ++i) {
            //does start time come after or before the current activity
            if (temp[i].startTime >= temp2[count].finishTime) {
                //adding number to list
                temp2.push_back(temp[i]);
                //incrementing count
                count++;
            }
        }
        //returning the increment count
        return count;
    }

    // Purpose: Prints to output file and console the sorted and
    // selected data.
    // Receives: Requires output file, vector of Schedule, and a
    // integer count
    // Returns: Returns nothing
    void print(ofstream& outfile, vector<Schedule> temp, int count) {
        // count starts at zero so we compensate for that and increase
        //  it by one so we get the correct output.
        count = count + 1;
        cout << "Start Time" << setw(10);
        outfile << "Start Time" << setw(10);
        cout << setw(7) << "Length";
        outfile << setw(7) << "Length";
        cout << setw(16) << "Finish Time" << endl;
        outfile << setw(16) << "Finish Time" << endl;
        // runs through the final data set
        for (int i = 0; i < count; ++i) {
            // prints the start time number to console and output file
            cout << temp[i].startTime << setw(10) << " ";
            outfile << temp[i].startTime << setw(10) << " ";
            // prints the length number to console and output file
            cout << temp[i].length << setw(10) << " ";
            outfile << temp[i].length << setw(10) << " ";
            // prints the finishTime number to console and output file
            cout << temp[i].finishTime << setw(10) << " ";
            outfile << temp[i].finishTime << setw(10) << " ";
            cout << endl;
            outfile << endl;
        }
        cout << "Maximum number of activities scheduled is " << count << "."
            << endl;
        outfile << "Maximum number of activities scheduled is " << count << "."
            << endl;
    }
};

// Purpose: Opens input and output files
// Receives: Requires some input and output file
// and reads in the data.
// Returns: Returns nothing
void openFiles(ifstream& infile, ofstream& outfile);

// Purpose: Prints header to console and output file
// Receives: Requires output file
// Returns: Returns nothing
void printHeader(ofstream& outfile);

int main() {
    // Sets inputfile reserve word to infile
    ifstream infile;
    // Sets outfile reserve word to outfile
    ofstream outfile;
    // Created instance of a schedule
    Schedule a;
    // create instances of vectors to pass in
    vector<Schedule> g1;
    vector<Schedule> g2;
    // creating count variable to increment later
    int count;
    // call to open files
    openFiles(infile, outfile);
    // Printing of the header to output file
    printHeader(outfile);
    // reads in the file and puts data in g1 vector
    a.readFile(infile, g1);
    // sorts g1 data
    a.sortIncreasing(g1);
    // set the selected data which is sorted as well and puts
    // the data into g2 from g1.
    // sets it equal to count because this function returns
    // an int which counts the amount of times the conditional was met
    count = a.greedyAlg(g1, g2);
    // print the selected and sorted data using the greedy alg info
    // also prints out count
    a.print(outfile, g2, count);
    // prints the sorted list, was just checking data was properly sorted
    //a.print(outfile, g1, g1.size());

    infile.close();
    outfile.close();
    return 0;
}

// Prototyped at the top of file
void openFiles(
    ifstream& infile,
    ofstream& outfile) { // reads in input file as an array of 40 chars
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

// Prototyped at the top of file
void printHeader(ofstream& outfile) {
    // prints the header to console and outfile
    cout << "Delton Hughes" << endl;
    outfile << "Delton Hughes" << endl;
    cout << "Program 3: Greedy Scheduling/Sorting Program" << endl;
    outfile << "Program 3: Greedy Scheduling/Sorting Program" << endl;
    cout << endl;
    outfile << endl;
}
