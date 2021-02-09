/*
    COPYRIGHT (C) 2017Student Name (UANETID ) All rights reserved.
    CSI Assignment 7
    Author.  Allan Nash Jr.
        an106@zips.uakron.edu
    Version. 1.01 07.09.2017
    Purpose: This program open up a stats array and allow the user to
    input values and output the corresponding process/answer
*/
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

//Function Prototypes
void storeFrequency(int freq[], int size, int number);
void storeSum(int freq[], int size);
void storeAverage(int freq[], int size);
void storeBiggestNum(int freq[], int size);
void storeMostFrequent(int freq[], int size);
void storeAmount(int freq[], int size);
void storeMedian(int freq[], int size);
void endProgram(int freq[], int size);

//Variables used in for the functions
char input;                 //Variable for the first input from the user
int number;                 //Variable for the second input from the user
int count = 0;              //Variable used for a counter
bool trueOrFalse = true;    //Variable used to help terminate program when wanted
int freq[100] = {0};        //Array used for frequency

//Precondition: The user inputs set characters, followed by any necessary numbers
//
//Postcondition: The program will call the necessary function and output the correct
//corresponding values
int main()
{
    cout << "Welcome to the Stats Array!" << endl;
    cout << "These are your choices: " << endl;
    cout << "N - Numbers" << endl;
    cout << "S - Sum of All" << endl;
    cout << "A - Average of All" << endl;
    cout << "B - Biggest of All" << endl;
    cout << "F - Most Frequent of All" << endl;
    cout << "H - How Many Numbers" << endl;
    cout << "M - Median of All" << endl;
    cout << "Q - Quit" << endl;

    while(trueOrFalse)
    {
        cin >> input;

        switch(input)
        {
        case 'N':   //Takes the user's input and displays whether it is OK or an Invalid Number
        {
            cin >> number;
            storeFrequency(freq, count, number);
            count++;//Count should only be truly added in this case, other cases may use count
                    //but shouldn't do so permanently
            break;
        }
        case 'S':   //Displays the sum of the user's inputs
        {
            storeSum(freq, count);
            break;
        }
        case 'A':   //Displays the average of the user's inputs
        {
            storeAverage(freq, count);
            break;
        }
        case 'B':   //Displays the biggest number of the user's inputs
        {
            storeBiggestNum(freq, count);
            break;
        }
        case 'F':   //Displays the most frequent number of the user's inputs
        {
            storeMostFrequent(freq, count);
            break;
        }
        case 'H':   //Displays the amount of the user's inputs
        {
            storeAmount(freq, count);
            break;
        }
        case 'M':   //Displays the median of the user's inputs
        {
            storeMedian(freq, count);
            break;
        }
        case 'Q':   //Displays END, and ends the program
        {
            endProgram(freq, count);
            trueOrFalse = false;
        }
        }
    }
    cin.clear();
}

//Precondition: The user inputs an array, variable for count, and number that was inputted, as
//well as the function was called by inputted a character 'N'
//
//Postcondition: The function outputs if the number is valid or not, and the frequency is stored
void storeFrequency(int freq[], int count, int number)
{
    if(number < 0 || number > 99)
    {
        cout << "Invalid Number" << endl;
    }
    else
    {
        freq[number] += 1; //Adds one to value in freq[number], for future use in frequency
        cout << "OK" << endl;
    }
}

//Precondition: The user had inputted numbers already, or zero is outputted to the display, as
//well as the function was called by inputted a character 'S'
//
//Postcondition: The function adds up all of the user's inputs and displays the sum
void storeSum(int freq[], int size)
{
    int sum = 0;
    if(count == 0)
    {
        cout << sum << endl;
    }
    else
    {
        for(int i = 0; i < 100; i++)
        {
            sum = sum + (freq[i] * i);
        }
        cout << sum << endl;
    }
}

//Precondition: The user had inputted numbers already, or ERROR is outputted to the display, as
//well as the function was called by inputted a character 'A'
//
//Postcondition: The function adds up all of the user's inputs, divides by the amount of
//inputs, and displays the average
void storeAverage(int freq[], int size)
{
    if(count == 0)
    {
        cout << "ERROR" << endl;
    }
    else
    {
        int sum = 0;
        for(int i = 0; i < 100; i++)
        {
            sum = sum + (freq[i] * i);
        }
        cout << (float)sum/count << endl;
    }
}

//Precondition: The user had inputted numbers already, or ERROR is outputted to the display, as
//well as the function was called by inputted a character 'B'
//
//Postcondition: The function goes through each number stored in copy array, and compares
//each value in that array and displays the largest value
void storeBiggestNum(int freq[], int size)
{
    int test = 1;
    if(count == 0)
    {
        cout << "ERROR" << endl;
    }
    else if(count == 1)
    {
        for(int i = 99; i - 0; i--)
            {
                if(freq[i] > 0)
                {
                cout << i << endl;
                }
            }
    }
    else
    {
        for(int i = 100; i > 0; i--)
        {
            if(freq[i-1] > 0)
            {
                cout << (i - 1) << endl;
                i = 0;
            }
        }
    }
}

//Precondition: The user had inputted numbers already, or ERROR is outputted to the display, as
//well as the function was called by inputted a character 'F'
//
//Postcondition: The function goes through each number in the array, and find the largest value,
//if there are more than one value that is repeated the same amount, the smallest value is
//outputted since the function compares from the first number to the last number
void storeMostFrequent(int freq[], int size)
{
    if(count == 0)
    {
        cout << "ERROR" << endl;
    }
    else
    {
        int f = 0;
        for(int i = 0; i < 99; i++)
        {
            if(freq[i] > f)
            {
                f = i;
            }
        }
        cout << f << endl;
    }
}

//Precondition: The user has, or has not inputted numbers already, as well as the function
//was called by inputted a character 'H'
//
//Postcondition: The function see the amount of times that the user has inputted
//numbers into the program and store this as count, then output to the display count
void storeAmount(int freq[], int size)
{
    cout << count << endl;
}

//Precondition: The user had inputted numbers already, or ERROR is outputted to the display, as
//well as the function was called by inputted a character 'M'
//
//Postcondition: The function outputs the median by outputting the only number, or the number
//that's one spot larger than the middle if it's an even number, or outputs the middle number
//to the display
void storeMedian(int freq[], int size)
{
    int j = 0;
    int k = 0;
    if(count == 0)
    {
        cout << "ERROR" << endl;
    }
    else if(count == 1 || count == 2)
    {
        for(int i = 0; i < 100; i++)
        {
            if(freq[i] == 2)
            {
                cout << i << endl;
                i = 100;
            }
            else
            {
                if(freq[i] == 1)
                {
                    cout << i << endl;
                    i = 100;
                }
            }
        }
    }
    else
    {
        int j = 0;
        for(int i = 0; i < 100; i++)
        {
            if(freq[i] != 0)
            {
                j += freq[i];
            }
            if(j > (count / 2))
            {
                cout << j << endl;
                i = 100;
            }

        }
    }
}

//Precondition: The user called the function by inputting a character 'Q'
//
//Postcondition: The function outputs END to the display and terminates the program
void endProgram(int freq[], int size)
{
    cout << "END" << endl;
}
