/*
    Allan Nash Jr.(an106), 4492867, A5 for DS
*/
#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <queue>
#include <set>
using namespace std;

//FUNCTION PROTOTYPES
void fillAdjList(vector<vector<string>> &adjList);
void menuOption(vector<vector<string>> adjList, int choice);
void topTenUsers(vector<vector<string>> adjList);
void medianFollowers(vector<vector<string>> adjList);
void averageFollowers(vector<vector<string>> adjList);
void shortestPath(vector<vector<string>> adjList);
void displayAdjList(vector<vector<string>> adjList);

//Main Function
int main(){
    //Created a Vector of Vectors, of Strings, for an Adjacency List
    vector<vector<string>> adjList;

    fillAdjList(adjList);

    int choice = 0;
    while(choice != 6){
        cout << "==========================================================" << endl;
        cout << "\tAllan's Users/Followers Program" << endl;
        cout << "==========================================================" << endl;
        cout << "1) Display the Top Ten Users with the Most Followers" << endl;
        cout << "2) Display the Median Number of Followers for Each User" << endl;
        cout << "3) Display the Average Amount of Followers for Each User" << endl;
        cout << "4) Display the Shortest Amount of Followers Between Users" << endl;
        cout << "5) Display a List of the Users and Their Followers" << endl << endl;
        cout << "6) Exit the Program" << endl;
        cout << "==========================================================" << endl;

        cout << "Option: ";
        cin >> choice;

        while(choice < 1 || choice > 6){
            cout << "Please Select a Valid Choice(1 - 6): ";
            cin >> choice;
        }

        menuOption(adjList, choice);
    }

    return 0;
}

//Function to Create Adjacency List(From a Vector of Vectors, of Strings)
void fillAdjList(vector<vector<string>> &adjList){
    //Declares ifstream and string Variable for getline's
    ifstream myFile;
    string line;

    //Opens the A5File.txt and Skips the First Line
    myFile.open("A5File.txt");
    getline(myFile, line);

    //While Loop That Reads Each Line
    while(getline(myFile, line))
    {
        vector<string>temp;
        bool testCase = true;

        string follower = line.substr(0, line.find(' '));
        string user1 = line.substr(9);
        string user = user1.substr(0, user1.find(' '));

        //Empty Adjacency List
        if(adjList.size() == 0){
            temp.push_back(user);
            temp.push_back(follower);
            adjList.push_back(temp);
        }

        else{
            for(int i = 0; i < adjList.size(); i++){
                if(adjList[i][0] == user){
                    adjList[i].push_back(follower);
                    i = adjList.size() - 1;
                    testCase = false;
                }
            }

            if(testCase){
                temp.push_back(user);
                temp.push_back(follower);
                adjList.push_back(temp);
            }
        }
    }
}

//Function for Switching to the User's Choice and Running the Corresponding Function
void menuOption(vector<vector<string>> adjList, int choice){
    switch(choice){
    case 1:
        cout << "==========================================================" << endl;
        cout << "\tTop Ten Users" << endl;
        cout << "==========================================================" << endl;
        topTenUsers(adjList);
        break;
    case 2:
        cout << "==========================================================" << endl;
        cout << "\tMedian Followers" << endl;
        cout << "==========================================================" << endl;
        medianFollowers(adjList);
        break;
    case 3:
        cout << "==========================================================" << endl;
        cout << "\tAverage Followers" << endl;
        cout << "==========================================================" << endl;
        averageFollowers(adjList);
        break;
    case 4:
        cout << "==========================================================" << endl;
        cout << "\tShortest Path Between Followers" << endl;
        cout << "==========================================================" << endl;
        shortestPath(adjList);
        break;
    case 5:
        cout << "==========================================================" << endl;
        cout << "\tUsers and Their Followers" << endl;
        cout << "==========================================================" << endl;
        displayAdjList(adjList);
    case 6:
        cout << "==========================================================" << endl;
        cout << "\tExiting Program..." << endl;
        cout << "==========================================================" << endl;
        break;
    }
}

//Function for Computing and Displaying the Top Ten Users with the Most Followers
void topTenUsers(vector<vector<string>> adjList){
    vector<int>temp1;
    vector<string>temp2;

    for(int i = 0; i < adjList.size(); i++){
        temp1.push_back(adjList[i].size());
        temp2.push_back(adjList[i][0]);
    }

    int count = 0;
    while(count < 10){
        int maxUsers = temp1[0];
        for(int a = 0; a < temp1.size(); a++){
            if(temp1[a] >= maxUsers){
                maxUsers = temp1[a];
            }
        }

        for(int b = 0; b < temp1.size(); b++){
            if(temp1[b] == maxUsers){
                cout << (count + 1) << ") " << temp2[b] << " with " << (temp1[b] - 1) << " Followers" << endl;
                temp1.erase(temp1.begin() + b);
                temp2.erase(temp2.begin() + b);

                b = temp1.size();
            }
        }

        count++;
    }
}

//Function for Computing and Displaying the Median Amount of Followers
void medianFollowers(vector<vector<string>> adjList){
    int test;
    int temp[adjList.size()];

    for(int i = 0; i < adjList.size(); i++){
        temp[i] = adjList[i].size() - 1;
    }

    for(int i = 0; i < adjList.size(); i++){
        for(int j = i + 1; j < adjList.size(); j++){
            if(temp[i] > temp[j]){
                test = temp[i];
                temp[i] = temp[j];
                temp[j] = test;
            }
        }
    }

    cout << "User's Median Followers: ";

    if(adjList.size() % 2 == 0){
        cout << (temp[(adjList.size() - 1) / 2] + temp[((adjList.size() - 1) / 2) - 1]) / 2 << endl;
    }

    else{
        cout << temp[(adjList.size() - 1) / 2] << endl;
    }
}

//Function for Computing and Displaying the Average Amount of Followers
void averageFollowers(vector<vector<string>> adjList){
    int total = adjList.size();
    double sum = 0;

    for(int i = 0; i < adjList.size(); i++){
        sum += (adjList[i].size() - 1);
    }

    cout << "User's Average Followers: " << (sum / total) << endl;
}

//Function for Computer and Displaying the Shortest Path Between Two Followers
void shortestPath(vector<vector<string>> adjList){
    string user1, user2;

    cout << "Input Two Numbers Separated By a Space: ";
    cin >> user1 >> user2;

    for(int i = 0; i < adjList.size(); i++){
        if(adjList[i][0] == user1){
            for(int j = 0; j < adjList[i].size(); j++){
                if(adjList[i][j] == user2){
                    cout << "Shortest Path: " << user1 << "->" << user2 << endl;
                }
            }
        }
    }

}

//Function for Displaying the Adjacency List
void displayAdjList(vector<vector<string>> adjList){
    for(int i = 0; i < adjList.size(); i++){
        cout << adjList[i][0] << "'s Followers: ";
        for(int j = 0; j < adjList[i].size(); j++){
            if(j != 0 && j == adjList[i].size() - 1){
                cout << adjList[i][j];
            }

            else if(j != 0){
                cout << adjList[i][j] << "->";
            }
        }

        if(i != adjList.size() - 1){
            cout << endl << "Total Followers: " << (adjList[i].size() - 1) << endl << endl;
        }

        else{
            cout << endl << "Total Followers: " << (adjList[i].size() - 1) << endl;
        }
    }
}
