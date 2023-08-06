/*
Create a C++ program that reads integers from the file named MidtermExam.txt and performs the following actions:

Define a function named calculateFileStats that reads all the integers from the file and displays the following on the console:
The total sum of all numbers in the file
The minimum value of the numbers in the file
The maximum value of the numbers in the file
The average value with 2 decimal places.
If the program fails to access the file, display an error message to the user and terminate the program.
Close the file once you have finished reading from it.
Call the function calculateFileStats in main
Note: I did not forget to attach an input file.
You can use the one in lecture 6's module if you want, or create dummy file yourself.
I am interested in your code.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

void calculateFileStats(const string& filename);

int main()
{
    string filename = "MidtermExam.txt";
    calculateFileStats(filename);

    return 0;
}

void calculateFileStats(const string& filename)
{
    ifstream InputFile(filename);
    if (!InputFile)
    {
        cout << "Error opening file.\n";
        exit(EXIT_FAILURE);
    }


    int minValue = INT_MAX;
    int maxValue = INT_MIN;
    int totalSum = 0;

    int count = 0;
    int num = 0;

    double average = 0;

    while (InputFile >> num)
    {
        if (num < minValue)
        {
            minValue = num;
        }
        if (num > maxValue)
        {
            maxValue = num;
        }

        totalSum += num;
        count++;
    }

    average = (totalSum * 1.00) / count;

    InputFile.close();

    cout << "Total: " << totalSum << endl;
    cout << "Minimum: " << minValue << endl;
    cout << "Maximum: " << maxValue << endl;
    cout << fixed << setprecision(2) << "Average: " << average << endl;

    return;
}

// 47 minutes
