/*
    COPYRIGHT (C) 2020 Allan Nash Jr. (4492867) All rights reserved.
    CSI Project Part A
    Author. Allan Nash
    an106@zips.uakron.edu
    Version. 1.01 10.31.2018
    Purpose: The program creates a virtual lab that the user can select options to
    log-in, log-off, search for a specific user, display a specific lab, or to
    quit the program.
*/
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::setw;
using std::string;
using std::srand;
using std::setfill;
using std::stringstream;

// GLOBAL CONSTANTS
const int NUMLABS = 8;                                               // Number of Computer Labs
const int LABSIZES[NUMLABS] = {19, 15, 24, 33, 61, 17, 55, 37};      // Number of Computers in Each Lab
                                                                     // Names of the University of Each Lab
const string UNIVERSITYNAMES[NUMLABS] =
    {
        "The University of Michigan",
        "The University of Pittsburgh",
        "Stanford University",
        "Arizona State University",
        "North Texas State University",
        "The University of Alabama, Huntsville",
        "Princeton University",
        "Duquesne University"
    };

// CLASS DECLARATION
class Labs
{
private:
    int userID = 00000;
    int time = 0;
    string name = " ";

public:
    // Default Constructor
    Labs()
    {
        userID = 00000;
        time = 0;
        name = " ";
    }
    // Setter for UserID
    void setUserID()
    {
        int user = (rand() % ((99999) + 1));
        userID = user;
    }
    // Getter for UserID
    int getUserID()
    {
        return userID;
    }
    // Setter for Name
    void setName(string newName)
    {
        name = newName;
    }
    // Getter for Name
    string getName()
    {
        return name;
    }
    // Setter for Time
    void setTime(int newTime)
    {
        time = newTime;
    }
    // Getter for Time
    int getTime()
    {
        return time;
    }
};

// FUNCTION PROTOTYPES
void beginArray(Labs *ptrToLabs[], const int LABSIZES[]);
void startMenu();
void printMenu(int &choice);
void menuOption(int &choice, Labs *ptrToLabs[]);
void userLogIn(Labs *ptrToLabs[], const int LABSIZES[]);
void userLogOff(Labs *ptrToLabs[], const int LABSIZES[]);
void userSearch(Labs *ptrToLabs[], const int LABSIZES[]);
void displayLab(Labs *ptrToLabs[], const int LABSIZES[]);
bool checkForRepeats(Labs *ptrToLabs[], int tempID, int labNum, int computerNum);

//*********************************************************************************************//
// Pre-Condition:  The Program Compiles with No Errors                                         //
// Post-Condition: The Program Outputs a Screen to the Display and Runs Programs with the Labs //
//*********************************************************************************************//
int main()
{
    // Declaring/Initializing a Counter Int and Array of Object(Labs) Type
    int choice = 1;
    Labs *ptrToLabs[NUMLABS];

    // Sets the Random Number
    srand(time(NULL));

    // Functions that Create the Copy Array and Display the Different Universities to the Output
    beginArray(ptrToLabs, LABSIZES);
    startMenu();

    // Loop to Continuously Run the Program Until the User Chooses to Exit
    while(choice != 5)
    {
        printMenu(choice);                  // Prompts the Menu with Options
        menuOption(choice, ptrToLabs);      // Runs Specific Functions Based on User's Input

        // Pauses to Allow the User to View the Results Before Looping Each Time
        system("pause");
    }
}

//*********************************************************************************************//
// Pre-Condition:  A Valid Array of Objects is Passed by and a Constant Variable is Predefined //
// Post-Condition: The Function Makes an Array of an Array of Objects in Each Array and Sets   //
//                 Each Object in Each Array as a Default Labs Object                          //
//*********************************************************************************************//
void beginArray(Labs *ptrToLabs[], const int LABSIZES[])
{
    for(int i = 0; i < NUMLABS; i++)
    {
        ptrToLabs[i] = new Labs[LABSIZES[i]];
        for(int j = 0; j < LABSIZES[i]; j++)
        {
            ptrToLabs[i][j] = Labs();       // Sets Each Object in the Array to the Default Constructor
        }
    }
}

//*********************************************************************************************//
// Pre-Condition: The Function is Called and Compiles Correctly                                //
// Post-Condition: The Display Outputs the Lab Numbers and Their Corresponding University      //
//*********************************************************************************************//
void startMenu()
{
    // Outputs all of the Universities Given from the Initially Declared Constants
    cout << "\tWelcome - List of the Available Labs While Running this Program:" << endl << endl;
    for(int i = 0; i < NUMLABS; i++)
    {
        cout << "\t\t\tLab #" << (i + 1) << " - " << UNIVERSITYNAMES[i] << endl;
    }
}

//*********************************************************************************************//
// Pre-Condition: The Function is Called  with Correct Parameters, and Compiles Correctly      //
// Post-Condition: The Display Outputs a User Interface Screen and Asks for the User's Choice  //
//*********************************************************************************************//
void printMenu(int &choice)
{
    // Prints the Menu to the Display to Show the Owner of the Program, as Well as the User's Options During the Program
    cout << std::internal << endl;
    cout << " " << setfill ('_') << setw (79) << " " << endl;
    cout << "|" << setfill ('_') << setw (79) << "|" << endl;
    cout << "|" << setfill (' ') << setw (79) << "|" << endl;
    cout << "|" << setfill (' ') << setw (30) << " " << "Allan Nash Incorporated" << setfill (' ') << setw (26) << "|" << endl;
    cout << "|" << setfill (' ') << setw (32) << " " << "Computer Lab System" << setfill (' ') << setw (28) << "|"<< endl;
    cout << "|" << setfill ('_') << setw (79) << "|" << endl;
    cout << "|" << setfill ('_') << setw (79) << "|" << endl;
    cout << "|" << setfill (' ') << setw (79) << "|" << endl;
    cout << "|" << setfill (' ') << setw (34) << " " << "MAIN MENU" << setfill (' ') << setw (36) << "|" << endl;
    cout << "|" << setfill (' ') << setw (31) << " " << "1) Simulate Log-In" << setfill (' ') << setw (30) << "|" << endl;
    cout << "|" << setfill (' ') << setw (31) << " " << "2) Simulate Log-Off" << setfill (' ') << setw (29) << "|" << endl;
    cout << "|" << setfill (' ') << setw (31) << " " << "3) Search" << setfill (' ') << setw (39) << "|" << endl;
    cout << "|" << setfill (' ') << setw (31) << " " << "4) Display a Lab" << setfill (' ') << setw (32) << "|" << endl;
    cout << "|" << setfill (' ') << setw (31) << " " << "5) Quit" << setfill (' ') << setw (41) << "|"  << endl;
    cout << "|" << setfill ('_') << setw (79) << "|" << endl << endl;
    cout << " " << setfill (' ') << setw (31) << " " << "Select Option: ";
    cin >> choice;

    // Tests to Make Sure that the User Inputted a Valid Choice and Loops Until a Valid Choice is Inputted
    if(choice <= 0 || choice > 5)
    {
        while(choice <= 0 || choice > 5)
        {
            cout << "   Invalid Option, Please Re-Select an Option: ";
            cin >> choice;
        }
    }
}

//*********************************************************************************************//
// Pre-Condition: The Function is Called  with Correct Parameters, and Compiles Correctly      //
// Post-Condition: The Function Chooses What Other Functions to Call Based on User's Choice    //
//*********************************************************************************************//
void menuOption(int &choice, Labs *ptrToLabs[])
{
    switch (choice)
    {
        // User Selected Log-In
        case 1:
            userLogIn(ptrToLabs, LABSIZES);
            break;
        // User Selected Log-Off
        case 2:
            userLogOff(ptrToLabs, LABSIZES);
            break;
        // User Selected Search
        case 3:
            userSearch(ptrToLabs, LABSIZES);
            break;
        // User Selected Display Labs
        case 4:
            displayLab(ptrToLabs, LABSIZES);
            break;
        // User Selected Quit
        case 5:
            cout << "Exiting Program..." << endl;
            break;
    }
}

//*********************************************************************************************//
// Pre-Condition: The Function is Called  with Correct Parameters, and Compiles Correctly      //
// Post-Condition: The Function Give the User a Name, ID, and Time at a Set Lab and Computer   //
//*********************************************************************************************//
void userLogIn(Labs *ptrToLabs[], const int LABSIZES[])
{
    // Declaring and Initializing Variables
    int labFull = 0;
    int time, labNum, computerNum, labCheck;
    string firstName, lastName, fullName;
    bool validTime = false;

    // User Selects Which Lab They Are Logging Into
    cout << "Enter the Lab Number the User is Logging in From (1-8): ";
    cin >> labNum;

    // Tests to Make Sure the Lab Isn't Already Full and if so, Then Tells the User and Returns to the Main Menu
    labCheck = labNum;
    for(int i = 0; i < LABSIZES[labNum - 1]; i++)
    {
        if(ptrToLabs[labNum - 1][i].getUserID() != 00000)
        {
            labFull++;
        }
    }

    if(labFull == LABSIZES[labNum - 1])     // If the Amount of Users in the Lab = the Amount of Computers in that Lab
    {
        while(labCheck == labNum)
        {
            cout << "That Lab is Full, You Will Be Redirected to the Main Menu" << endl;
            system("pause");
            return;
        }
    }

    // User Selects Which Computer Station They Are Logging Into
    cout << "Enter the Computer Station the User is Logging in From (1-" << LABSIZES[labNum - 1] << "): ";
    cin >> computerNum;

    // Tests to Make Sure the Computer Station isn't Already Taken
    if(ptrToLabs[labNum - 1][computerNum - 1].getUserID() != 00000)
    {
        while(ptrToLabs[labNum - 1][computerNum - 1].getUserID() != 00000)
        {
            cout << "That Computer Station is Taken, Please Select Another Station: ";
            cin >> computerNum;
        }
    }

    // Gives the User a Randomly Generated ID
    ptrToLabs[labNum - 1][computerNum - 1].setUserID();
    int tempID = ptrToLabs[labNum - 1][computerNum - 1].getUserID();

    // Checks to Make Sure the ID Isn't Already Being Used and Outputs the Unused ID
    while(checkForRepeats(ptrToLabs, tempID, labNum, computerNum) == false)
    cout << endl << endl << "User ID: " << setfill('0') << setw(5) << ptrToLabs[labNum - 1][computerNum - 1].getUserID() << endl;

    // User Inputs Their First and Last Name and the Two Strings/Names are Added/Saved as One String/Name
    cout << "Enter the First and Last Name of the User: ";
    cin >> firstName >> lastName;
    fullName = firstName + " " + lastName;

    // Tests to Make Sure that the Name is Under 35 Letters/Characters Long
    while(fullName.length() >= 35)
    {
        cout << "That Name was Too Long. Please Input a Fist and Last Name, No More than 35 Letters Long: ";
        cin >> firstName >> lastName;
        fullName = firstName + " " + lastName;
    }

    // Sets the Name of the User to the Name of the Person/Object Logged Into that Computer Station, in that Lab
    ptrToLabs[labNum - 1][computerNum - 1].setName(fullName);

    // User Inputs How Long They Will be on That Computer
    cout << "Enter the Amount of Minutes of Use for the Work Station (15/30/45/60): ";
    cin >> time;

    // Checks to Make Sure that the Time Was a Valid Amount
    while(validTime == false)
    {
        if(time == 15 || time == 30 || time == 45 || time == 60)
        {
            validTime = true;
        }
        else
        {
            cout << "Invalid Time, Please Re-Select One of the Four Options: ";
            cin >> time;
        }
    }

    // Sets the Amount/Time to the Time of the Person/Object Logged Into the Computer Station, in that Lab
    ptrToLabs[labNum - 1][computerNum - 1].setTime(time);
}

//*********************************************************************************************//
// Pre-Condition: The Function is Called  with Correct Parameters, and Compiles Correctly      //
// Post-Condition: The Function Sets the User's Spot in the Lab to the Default Constructor     //
//*********************************************************************************************//
void userLogOff(Labs *ptrToLabs[], const int LABSIZES[])
{
    // Declaring Variables
    int userID;

    // User Inputs ID to Whom is Logging Off
    cout << "Enter the User ID of the User Logging off: ";
    cin >> userID;

    // Checks the Array of Objects for the Matching ID, then Sets that Object to the Default Constructor
    for(int i = 0; i < NUMLABS; i++)
    {
        for(int j = 0; j < LABSIZES[i]; j++)
        {
            if(ptrToLabs[i][j].getUserID() == userID)
            {
                ptrToLabs[i][j] = Labs();
            }
        }
    }
}

//*********************************************************************************************//
// Pre-Condition: The Function is Called  with Correct Parameters, and Compiles Correctly      //
// Post-Condition: The Function Searches for and Outputs Where the User is Located at          //
//*********************************************************************************************//
void userSearch(Labs *ptrToLabs[], const int LABSIZES[])
{
    // Declaring and Initializing Variables
    int userID, a, b;
    bool foundUser = false;

    // User Inputs the ID Number to Search For
    cout << "Enter the 5 Digit ID Number of the User to Search for: ";
    cin >> userID;

    // Checks to Make Sure that the ID is Valid
    if(userID == 00000)
    {
        while(userID == 00000)
        {
            cout << "Please Input a Valid ID#, Not '00000': ";
            cin >> userID;
        }
    }

    // Checks to Make Sure that the ID is Logged Into a Computer, and Stores the Location
    for(int i = 0; i < NUMLABS; i++)
    {
        for(int j = 0; j < LABSIZES[i]; j++)
        {
            if(ptrToLabs[i][j].getUserID() == userID)
            {
                foundUser = true;
                a = i;          // Variables to Where the Location is Stored
                b = j;          // Variables to Where the Location is Stored
            }
        }
    }

    if(foundUser == false)      // Displays if the User Wasn't Found
    {
        cout << "User Isn't Logged-In" << endl;
    }
    else            // User was Found
    {
        cout << "User ID: " << setw(5) << setfill('0') << userID << " is in Lab #" << (a + 1) << " at Computer Station - " << (b + 1) << endl;
    }
}

//*********************************************************************************************//
// Pre-Condition: The Function is Called  with Correct Parameters, and Compiles Correctly      //
// Post-Condition: The Function Displays to the Output all Users in the Computers of Each Lab  //
//*********************************************************************************************//
void displayLab(Labs *ptrToLabs[], const int LABSIZES[])
{
    // Declaring and Initializing Variables
    int labNum;
    int count = 0;

    // User Inputs Which Lab to Display
    cout << "Enter Which Lab to Display: ";
    cin >> labNum;

    // Checks to Make Sure is a Valid Number
    while(labNum <= 0 || labNum > NUMLABS)
    {
        cout << "Invalid Lab#. Please Reselect a Valid Lab#: ";
        cin >> labNum;
    }

    // Outputs the Lab Status of the Lab Determined by the Existing Constants
    cout << endl << "LAB STATUS" << endl;
    cout << "Lab #" << labNum << " for " << UNIVERSITYNAMES[labNum - 1] << endl;
    cout << "Computer Stations";

    // Checks Whether the Station is Empty or Not and Outputs Either Empty or the Station's User's ID
    for(int j = 0; j < LABSIZES[labNum - 1]; j++)
    {
        if(count % 5 == 0)          // Used to Format Output to Make a New Line After 5 Outputs
        {
            cout << endl;
        }

        cout << std::left << setw(2) << (j + 1) << ": ";            // Sets Width and Alignment of Output

        // Checks Each Station, If The Station Has No Time Set, Then No User is in that Lab, So Outputs Empty
        if(ptrToLabs[labNum - 1][j].getTime() == 0)
        {
            cout << "Empty ";
        }

        // Outputs the User's ID in that Station and Adds 0's if needed
        else
        {
            cout << setw(5) << std::right << ptrToLabs[labNum - 1][j].getUserID() << " ";
        }
        count++;            // Adds One to Counter for Better Formatting
    }
    cout << endl << endl;           // Adds a New Line Before Program Pauses
}

//*********************************************************************************************//
// Pre-Condition: The Function is Called  with Correct Parameters, and Compiles Correctly      //
// Post-Condition: The Function Checks to Make Sure that the ID Doesn't Match an Existing One  //
//*********************************************************************************************//
bool checkForRepeats(Labs *ptrToLabs[], int tempID, int labNum, int computerNum)
{
    // For Loop to Test the ID of Each Existing User and Compare it with the User's ID Being Created
    for(int i = 0; i < NUMLABS; i++)
    {
        for(int j = 0; j < LABSIZES[i]; j++)
        {
            // Makes Sure the Loop Doesn't Test Itself
            if(ptrToLabs[i][j].getUserID() != ptrToLabs[labNum][computerNum].getUserID())
            {
                // Checks if the Existing ID Equals the Created ID
                if(tempID == ptrToLabs[i][j].getUserID())
                {
                    ptrToLabs[i][j].setUserID();            // Resets the ID for the New User
                    return false;                           // Returns False to Continue the Loop Until the ID is Unique
                }
            }
        }
    }
    return true;                                            // Returns True, Stops Loop, When the ID is Unique
}
