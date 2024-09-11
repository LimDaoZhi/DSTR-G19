//100 numbers (random numbers)
//unique (cannot duplicate)
//range from 0 - 500
#include <iostream>
#include <cstdlib>  // Used for c programming of the random number 
#include <ctime>    // For time()
using namespace std;

const int MAXSIZE = 100;  // Number of unique random numbers
const int RANGE = 501;    // Range from 0 to 500

int main() {
    int array1[MAXSIZE];
    srand(time(NULL));  //Make sure everything restart program so that it can change the starting random number //based time

    for (int i = 0; i < MAXSIZE; i++) {
        int randomNumber = rand() % RANGE;  // rand() is used to generate a random number between 0 and 500
        
        // Check for duplicates
        for (int j = 0; j < i; j++) {
            while (array1[j] == randomNumber) {
                randomNumber = rand() % RANGE;  // Generate a new random number
                j = 0;  // Restart comparison from the beginning
            }
        }
        array1[i] = randomNumber;  // Store the unique random number
    }

    // Display the array of unique random numbers
    cout << "Unique random numbers: ";
    for (int i = 0; i < MAXSIZE; i++) {
        cout << array1[i];
        if (i < MAXSIZE - 1) {
            cout << ", ";
        }
    }
    cout << endl;

    return 0;
}

void insertionsort(int array1[], int size)
{
    int round = 0;
    for(int index = 1; index < size; index++)
    {
        int comparekey = array1[index];
        int emptycolIndex = index;

        while(emptycolIndex > 0 && comparekey < array1[index - 1])
        {
            array1[emptyccolIndex] = array1[emptyccolIndex - 1];
            emptyccolIndex--;
        }
        array1[emptyccolIndex] = comparekey;
        round++;
    }
    cout << "Total round for running the process: " << round << endl;
}

