/*
    COPYRIGHT(C) - 2020 Allan Nash Jr.(an106) All Rights Reserved.
    File Name - A#2 an106
    Author - Allan Nash Jr
             an106@zips.uakron.edu
    Version - 1.01 09/27/2020
    Purpose: - To Practice Recursive Functions and to Better Understand
               the Logic of Word Trees/Trees in Containers
*/

#include <set>
#include <queue>
#include <iostream>
#include <fstream>
using std::cin;
using std::set;
using std::cout;
using std::endl;
using std::queue;
using std::string;
using std::ifstream;

//FUNCTION PROTOTYPES
bool isInDict(string word2);
bool isInSet(string word2, set<string> wordS);
void startScreen(string &word1, string &word2);
void validWords(string &word1, string &word2);
void fillValidWords(string word1, string word2, set<string> &wordS);
void printQueue(queue<string> &wordQ);
void mergeSetandQueue(set<string> &wordS, queue<string> &wordQ);
void makeWordLadder(string word1, string word2, string initWord, set<string> &wordS, queue<string> &testWords, int &count);

//*****************************************************************************//
//Precondition: The Program is Called with the Correct Parameters and Compiles Correctly
//Postcondition: The Program Prompts the User for Two Valid Words and Displays Their Word Ladder
//*****************************************************************************//
int main()
{
    //Declaration of Variables
    string word1, word2; //Store the Start and Target Word
    set<string> wordS; //Stores the Dictionary.txt Contents
    queue<string> testWords; //Stores the Valid Words Already Tested
    int count = 0; //Counter Variable to Test for Invalid Ladders

    //Prints Start Screen to the Output and Asks for Start and Target Words
    startScreen(word1, word2);

    //Makes Sure the User Inputted Words are Valid
    validWords(word1, word2);

    //Fills the Set with Valid Words Based on the Words Chosen
    fillValidWords(word1, word2, wordS);

    //Displays the Word Ladder to the Output
    cout << "Program May Load for a Few Minutes Before Solving!" << endl;
    cout << "==================================================" << endl;
    cout << "Word Ladder for (" << word1 << " -> " << word2 << ")" << endl;
    cout << "==================================================" << endl;
    cout << "-> " << word1 << endl;

    //Stores Initial Word, Erases Initial Word from the Set, and Runs the makeWordLadder Function
    string initWord = word1;
    wordS.erase(word1);
    makeWordLadder(word1, word2, initWord, wordS, testWords, count);

    return 0; //Ends the Program
}

//*****************************************************************************//
//Precondition: The Function is Called with the Correct Parameters and Compiles Correctly
//Postcondition: The Function Outputs the Start of the Word Ladder and Prompts the User for Inputs
//*****************************************************************************//
void startScreen(string &word1, string &word2)
{
    //Program Title/Header
    cout << "==================================================" << endl;
    cout << "             Allan Nash - Word Ladder             " << endl;
    cout << "==================================================" << endl;

    //Gets Start and Target Word
    cout << "Input the Start and Target Words" << endl;
    cout << ">> Start Word(Valid English Word): ";
    cin >> word1;
    cout << ">> Target Word(Valid Dictionary Word): ";
    cin >> word2;
    cout << "==================================================" << endl;
}

//*****************************************************************************//
//Precondition: The Function is Called with the Correct Parameters and Compiles Correctly
//Postcondition: The Function Tests the User's Inputs and Displays Errors if Words are Invalid
//*****************************************************************************//
void validWords(string &word1, string &word2)
{
    //Checks to Make Sure Words Chosen are Valid
    while(word1.size() != word2.size() || word1 == word2 || isInDict(word2) == false)
    {
        //Checks to Make Sure Word1(Start Word) and Word2(Target Word) are the Same Size
        if(word1.size() != word2.size())
        {
            //Prints Error of Different Sized Words, and Asks for Start and Target Word Again
            cout << "ERROR: Words Must be the Same Size!" << endl;
            cout << ">> Start Word(Valid English Word): ";
            cin >> word1;
            cout << ">> Target Word(Valid Dictionary Word): ";
            cin >> word2;
            cout << "==================================================" << endl;
        }

        //Checks to Make Sure Word1(Start Word) and Word2(Target Word) aren't the Same Word
        if(word1 == word2)
        {
            //Prints Error of Same Words, and Asks for Start and Target Word Again
            cout << "ERROR: Words Can't be the Same Word!" << endl;
            cout << ">> Start Word(Valid English Word): ";
            cin >> word1;
            cout << ">> Target Word(Valid Dictionary Word): ";
            cin >> word2;
            cout << "==================================================" << endl;
        }

        //Checks to Make Sure Word2(Target Word) is Found in the Dictionary.txt
        while(isInDict(word2) == false)
        {
            //Prints Error of Word Not Found in Dictionary, and Asks for Start and Target Word Again
            cout << "ERROR: Target Word Not Found in Dictionary!" << endl;
            cout << ">> Start Word(Valid English Word): ";
            cin >> word1;
            cout << ">> Target Word(Valid Dictionary Word): ";
            cin >> word2;
            cout << "==================================================" << endl;
        }
    }
}

//*****************************************************************************//
//Precondition: The Function is Called with the Correct Parameters and Compiles Correctly
//Postcondition: The Function Fills a Set with Words of the Same Size as the User's Inputs
//*****************************************************************************//
void fillValidWords(string word1, string word2, set<string> &wordQ)
{
    //Declaration of String Variable and Input File to Use for Copying to Set
    string testWord;
    ifstream inputFile;

    inputFile.open("Dictionary.txt"); //Opens the Input File/Dictionary.Txt File

    //Loop to Read Through Text File
    while(getline(inputFile, testWord))
    {
        //Makes Sure the Word Copied from the Text File is the Same Size but isn't the Same Word
        if(testWord.size() == word1.size())
        {
            wordQ.insert(testWord); //Inserts the Same Sized, Non-Repeating Word, to the Set
        }
    }

    inputFile.close(); //Closes the Input File/Dictionary.txt File
}

//*****************************************************************************//
//Precondition: The Function is Called with the Correct Parameters and Compiles Correctly
//Postcondition: The Function Returns True or False, Depending on if the Word is in the Dictionary
//*****************************************************************************//
bool isInDict(string word2)
{
    //Declaration of String Variable and Input File to Use for Copying to Set
    string testWord;
    ifstream inputFile;

    inputFile.open("Dictionary.txt"); //Opens the Input File/Dictionary.Txt File

    //Loop to Read Through Text File
    while(getline(inputFile, testWord))
    {
        if(testWord == word2)
        {
            return true; //Word Found in Dictionary
        }
    }
    return false; //Word Not Found in Dictionary

    inputFile.close(); //Closes the Input File/Dictionary.Txt File
}

//*****************************************************************************//
//Precondition: The Function is Called with the Correct Parameters and Compiles Correctly
//Postcondition: The Function Returns True or False, Depending on if the Word is in the Set
//*****************************************************************************//
bool isInSet(string word2, set<string> wordS)
{
    //If Word is Found in the Set
    if(wordS.find(word2) != wordS.end())
    {
        return true;
    }

    //Word Not Found in Set
    else
    {
        return false;
    }
}

//*****************************************************************************//
//Precondition: The Function is Called with the Correct Parameters and Compiles Correctly
//Postcondition: The Function Inserts All Words in the Queue, Besides the Last/Newest One
//*****************************************************************************//
void mergeSetandQueue(set<string> &wordS, queue<string> &testWords)
{
    //While Loop to Loop Through the Queue
    while(!testWords.empty())
    {
        //If There's Only One Word in the Queue
        if(testWords.front() == testWords.back())
        {
            testWords.pop(); //Pop/Delete the One Element in the Queue
        }

        //If There's More Than One Word in the Queue
        else
        {
            wordS.insert(testWords.front()); //Inserts the Top Word into the Set
            testWords.pop(); //Pops/Deletes the Top Word in the Queue
        }
    }
}

//*****************************************************************************//
//Precondition: The Function is Called with the Correct Parameters and Compiles Correctly
//Postcondition: The Function Loops Through a Queue and Displays its Contents
//*****************************************************************************//
void printQueue(queue<string> &wordQ)
{
    //While Loop to Loop Through Queue
    while(!wordQ.empty())
    {
        cout << "-> " << wordQ.front() << endl; //Prints the Top Element
        wordQ.pop(); //Pops the Top Element
    }
}

//*****************************************************************************//
//Precondition: The Function is Called with the Correct Parameters and Compiles Correctly
//Postcondition: The Function Uses Recursion to Call Itself Until the Word Ladder is Solved/Displayed or an Error Occurs
//*****************************************************************************//
void makeWordLadder(string word1, string word2, string initWord, set<string> &wordS, queue<string> &testWords, int &count)
{
    //Declaration of String Variables
    string testWord = word1; //Stores the Starting Word for Testing
    string copyLetter = ""; //Empty String to Determine Fail Cases
    string originalWord = initWord; //Stores the Original Word for Replacing

    //For Loop to Iterate Through Each Spot in testWord
    for(int i = word2.size() - 1; i >= 0; i--)
    {
        string origWord = testWord; //Is Set as the Last Valid Word, Starts with Original(Valid) Word

        int var = 97; //Sets Var to 97, 97 = 'a' and 123 = 'z'
        //Loops From 'a' to 'z' in While Loop
        while(var < 124)
        {
            testWord.at(i) = (char)var; //Sets testWord.at(i) to the Next Character/Letter

            //If testWord with the New Character/Letter is in the Set/Dictionary
            if(isInSet(testWord, wordS))
            {
                count = 0; //Sets/Resets Count to 0, Since Current Word is Valid
                origWord = testWord; //Sets the Last Valid Word
                copyLetter = testWord; //Fills Copy Letter to Show Current Word Can Make a Word Tree
                wordS.erase(testWord); //Erases the Current Word from the Set to Prevent Repeats
                testWords.push(testWord); //Pushes the Current Word onto a Queue of Already Tested/Used Valid Words

                //If the Word Equals the Target Word
                if(testWord == word2)
                {
                    //Prints the Queue and Ladder to the Display
                    printQueue(testWords);
                    cout << "==================================================" << endl;
                    cout << "Ladder Solved: " << initWord << " - " << word2 << endl;
                    cout << "==================================================" << endl;
                    return; //Ends the Function/Recursion
                }

                //If the Corresponding Letters to the testWord and the Target Word are Equal
                else if(testWord.at(i) == word2.at(i))
                {
                    var = 124; //Ends the While Loop so the Letter Doesn't Change
                }
            }

            //testWord with the New Character/Letter is Not in the Set/Dictionary
            else
            {
                testWord = origWord; //Sets testWord to origWord/Last Valid Word
            }

            var++; //Keeps the While Loop Going
        }
    }

    //If the Two Embedded Loops Finish with an Empty String More Than Once in a Row
    if(copyLetter == "" && count > 0)
    {
        cout << "-> " << word2 << endl;
        cout << "==================================================" << endl;
        cout << "ERROR: Invalid Word Pairs for a Word Ladder!" << endl;
        cout << "==================================================" << endl;
        return; //Ends the Function/Recursion
    }

    //If the Two Embedded Loops Finish with an Empty String
    else if(copyLetter == "")
    {
        count++; //Adds One to Count(Total is Now 1)
        mergeSetandQueue(wordS, testWords); //Adds All of the Tested Words Back into the Set, Besides the Last Valid Word
        wordS.erase(testWord); //Deletes the Last Valid Word from the Set

        //Recalls the Function with the Last Valid Word Delete, Since That Word is Not Apart of the Valid Word Ladder/Tree
        makeWordLadder(originalWord, word2, initWord, wordS, testWords, count);
    }

    //Valid Words Have Been Made, But the For and While Loops Have Ended
    else
    {
        //Continuously Recalls the Function Until an Error Occurs/Solution is Found
        makeWordLadder(testWord, word2, initWord, wordS, testWords, count);
    }
}
