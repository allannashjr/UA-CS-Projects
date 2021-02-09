#include <iostream>
#include <memory>

using std::cout;
using std::endl;
using std::unique_ptr;

//Function Prototype
unique_ptr<char[]> deleteRepeats(char arr[], int counter);

//Global Constant for Predetermined Test Array Size
const int SIZE = 10;

//Pre-Condition: The Program is Compiled and Working Correctly, with the Correct
//Variables Being Used from the Test Code
//Post-Condition: The Program is Ran, Calling other Functions to Delete the Repeating
//Characters and Keeping Track of the Amount of Duplicates
int main()
{
    int counter = 0;    //Counter Variable

    //Test Code to Run in the Program
    char originalArray[SIZE];
    originalArray[0] = 'a';
    originalArray[1] = 'b';
    originalArray[2] = 'b';
    originalArray[3] = 'c';
    originalArray[4] = 'a';
    originalArray[5] = 'c';
    originalArray[6] = 'a';
    originalArray[7] = 'c';
    originalArray[8] = 'b';
    originalArray[9] = 'c';

    //Made a New Pointer of an Array of Character Type to Pass Through the
    //deleteRepeats Function, as well as the counter variable store the amount
    //of repeats
    unique_ptr<char[]> noRepeats = deleteRepeats(originalArray, counter);

    //For loop for changing the repeats to a dash, and counting the amount
    //of repeats
    for(int j = 0; j < 10; j++)
    {
        if(originalArray[j] == '-')
        {
            counter++;  //Adds one to counter to store the amount of repeated characters
        }
    }

    //For loop to print to the output the new dynamic array that is only the size
    //of the non-repeated character and prints out each character in the array
    for(int i = 0; i < SIZE-counter; i ++)
    {
        cout << noRepeats[i] << endl;

    }

    //Prints out the number of repeated character to the output
    cout << endl << "Number of Repeats: " << counter << endl << endl;
    return 0;
}

//Pre-Condition: Reads in an array of character type with correct values/variables.
//Post-Condition: The duplicates are deleted and the non-repeated characters are
//outputted onto another array, and a count for the duplicates is made.
unique_ptr<char[]> deleteRepeats(char arr[], int counter)
{
    for(int i = 0; i < 9; i++)
    {
        if(arr[i] != '-')
        {
            for(int j = i + 1; j < 10; j++)
            {
                if(arr[i] == arr[j])
                {
                    arr[j] = '-';   //Replaces the repeats with a dash to use in the future
                                    //by using the non-dashes for the new array
                }

            }
        }
    }
    //Made a new Pointer Array of Character Type Made to Return. Should Just be the Actual
    //Size of the Amount of the Non-Repeated Characters
    unique_ptr<char[]> newArr(new char[SIZE-counter]);
    int index = 0;
    for(int i = 0; i < SIZE; i++)
    {
        if(arr[i] != '-')
        {
            newArr[index++] = arr[i];   //Fills in all of the non-dashes into the new array
                                        //Assuming that the previous steps were correct, this should
                                        //make the array full with non-repeats to the exact amount
        }
    }
    return newArr;  //Returns the array of non-repeats
}
