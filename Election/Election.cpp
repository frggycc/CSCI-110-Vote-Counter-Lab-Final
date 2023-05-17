/*************************************************************
* Program: Dynamically Allocated Array
* Author : Charlie Cardenas
* Class  : CSCI TTH Afternoon Class
* Date   : October 25th, 2022
* Description: This program will store information about
* votes for a canidate into a dynamically allocated array.
*
* I certify that the code below is my own work.
*   Exception(s) : N / A
**************************************************************/

// System Libraries
#include <iostream>
#include <iomanip>

using namespace std;

// Function Prototypes
void InputData(int*, int, int&, int&);
int ElectionResults(int*, int);

// Execution Starts Here
int main()
{
    // Declaration of Variables
    int numOfCan, winner;
    int valid = 0; 
    int invalid = 0;
    int i;

    // Author
    cout << right << setw(35) << "Author: Charlie Cardenas" << endl;
    cout << setfill('-') << setw(55) << "" << endl;

    // Input Variables
    cout << "Enter number of Canidates --> ";
    cin >> numOfCan;

    // Allocate array
    int* election = new int[numOfCan] {0};

    // Input information
    InputData(election, numOfCan, valid, invalid);

    // Calculate election results
    winner = ElectionResults(election, numOfCan);

    // Output Results
    cout << "There are " << valid << " votes and ";
    cout << invalid << " invalid votes." << endl;

    cout << "Candidate " << winner << " won the election ";
    cout << "with " << election[winner - 1] << " votes." << endl;

    // Delete array
    delete[] election;

    // Exit Program
    return 0;
}

void InputData(int* array, int size, int& valid, int& invalid) {
    int vote;

    cout << "Enter votes --> ";
    do {
        cin >> vote;
        if (vote == 0) {}
        else if (vote >= 1 && vote <= size)
        {
            array[vote - 1]++;
            valid++;
        }
        else
            invalid++;
        
    } while (vote != 0);
}

int ElectionResults(int* array, int size) {
    int mostVotes = array[0];
    int winner = 1;

    for (int i = 1; i < size; i++)
    {
        if (array[i] >= mostVotes)
        {
            mostVotes = array[i];
            winner = i + 1;
        }
    }

    return winner;
}