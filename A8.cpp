#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::stringstream;

string pigLatin(const string &word);        //Function Prototype

//Precondition: The user runs the program and is compiled with no errors
//
//Postcondition: The program reads in an input file, converts to pig latin,
//               then outputs to the display
//
int main()
{
    ifstream inputFile;
    inputFile.open("A8.txt");     //Opens up the given text file

    string line;        //Variable to use for the getline function to read in a line of strings
    string word;        //Variable to use with wordstream to set the value to a string/word

    if(inputFile)       //Makes sure the file is open/there
    {
        while(getline(inputFile,line))      //Reads in one line at a time
        {
            stringstream wordstream(line);      //Coverts the line to wordstream to make it multiple strings of words
            while(wordstream >> word)       //While there's a word, it passes it to the pigLatin function
            {
                    cout << pigLatin(word) << " ";
            }
            cout << endl;       //Adds a new line to the output, before the while loop reads in a new line
        }
        inputFile.close();
    }
    return 0;
}

//Precondition: The program was called with a valid parameter
//
//Postcondition: The function takes the sets the first letter to
//               string variable, then sets the rest of the word
//               to another string variable, then returns the
//               rest of the word + first letter + "ay"
//
string pigLatin(const string &word)        // converts the input string to PigLatin way.
{
    string firstLetter = word.substr(0,1);
    string restOfWord = word.substr(1, word.size()-1);
    return restOfWord + firstLetter + "ay";
}
