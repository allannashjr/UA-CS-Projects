/*
COPYRIGHT(C) - 2020 Allan Nash Jr.(an106) All Rights Reserved.
File Name - A#3-an106
Author - Allan Nash Jr
            an106@zips.uakron.edu
Version - 1.01 10/15/2020
Purpose: - To Practice Recursive Functions and Binary Search Trees/Nodes
*/
#include <iostream>
#include <stack>
#include "functions.h"
using std::endl;
using std::cin;
using std::cout;
using std::stack;
using std::max;

int main()
{
    //Declaring Data, Choice, and Root Variables
    int data;
    int choice = 0;
    BSTNode *root = NULL;

    //Asks the User for the Root Value
    cout << "Input a Value to Start the BST: ";
    cin >> data;

    //Creates a Node Called Root from the User's Input
    root = createNode(data);

    //Choice Isn't to Exit the Program
    while(choice != 7)
    {
        DisplayMenu(root, choice);
    }

    //Choice is to Exit the Program
    if(choice == 7)
    {
        cout << "Exiting Program..." << endl;
    }
    return 0;
}

//**************************************************************//
//Precondition - Function was Called with the Correct Parameters
//Postcondition - Function Displays a Menu that Helps Run the Program
//**************************************************************//
void DisplayMenu(BSTNode *root, int &choice)
{
    cout << "====================================================" << endl;
    cout << "                Allan's BST Program                 " << endl;
    cout << "====================================================" << endl;
    cout << "1) Search for a Node" << endl;
    cout << "2) Insert a New Node" << endl;
    cout << "3) Delete an Existing Node" << endl;
    cout << "4) Display all Nodes in Tree Format" << endl;
    cout << "5) Print all Nodes from Highest to Lowest" << endl;
    cout << "6) Print Most Expensive Path" << endl;
    cout << "7) Exit the Program" << endl;
    cout << "====================================================" << endl;

    //Asks for the User's Input
    cout << "Enter a Valid Option(1-7): ";
    cin >> choice;

    //While Choice is Not a Valid Option, Loop Until a Valid Option is Made
    while(choice < 1 || choice > 7)
    {
        cout << "Enter a Valid Option(1-7): ";
        cin >> choice;
    }
    cout << "====================================================" << endl;

    //Use the User's Choice to Pick the Correct Function(s)
    MenuOption(root, choice);
}

//**************************************************************//
//Precondition - Function was Called with the Correct Parameters
//Postcondition - Function Calls the Correct Corresponding Functions
//**************************************************************//
void MenuOption(BSTNode *root, int &choice)
{
    //Declaring Int Variables and Stack Variable
    int data;
    int count = 0;
    int test = 0;
    stack<int> finalQ;

    //Switch for the User's Choice
    switch(choice)
    {
    //Search for a Node
    case 1:
        //Prompts for a Value to Search for
        cout << "Input a Value to Search for: ";
        cin >> data;

        //Search Returns True
        if(Search(root, data))
        {
            cout << data << " Was Found in the BST" << endl;
        }

        //Search Returns False
        else
        {
            cout << data << " Was Not Found in the BST" << endl;
        }
        break;
    //Insert a New Node
    case 2:
        //Prompts for a Value to Insert
        cout << "Input a Value to Insert: ";
        cin >> data;

        //Inserts that Value
        insertNode(root, data);
        break;
    //Delete an Existing Node
    case 3:
        //Prompts for a Value to Delete
        cout << "Input a Value to Delete: ";
        cin >> data;

        //Search Returns True
        if(Search(root, data))
        {
            deleteNode(root, data);   //Delete the Value
            cout << "Deleting " << data << " from the BST" << endl;
        }

        //Search Returns False
        else
        {
            cout << "Unable to Delete an Non-Existing Value" << endl;   //Value Doesn't Exist
        }
        break;
    //Display all Nodes in Tree Format
    case 4:
        //Search Returns True
        if(Search(root, root->data))
        {
            cout << "BST in Tree Format: " << endl;
            displayTree(root, test);    //Prints BST
            cout << endl;
        }

        //Search Returns False
        else
        {
            cout << "Unable to Print an Empty Tree" << endl;    //Empty BST
        }
        break;
    //Prints all Nodes from Highest to Lowest
    case 5:
    {
        //Search Returns True
        if(Search(root, root->data))
        {
            cout << "All Keys in the BST in Largest to Smallest Order: " << endl;
            displayAllNode(root, finalQ);

            //Prints the Values from the Queue
            while(!finalQ.empty())
            {
                cout << finalQ.top() << endl;
                finalQ.pop();
            }
        }

        //Search Returns False
        else
        {
            cout << "Unable to Print from an Empty Tree" << endl; //Empty BST
        }
        break;
    }
    //Prints Most Expensive Tree Path
    case 6:
        //Search Returns True
        if(Search(root, root->data))
        {
            printMaxSum(root);
        }

        //Search Returns False
        else
        {
            cout << "Unable to Print from an Empty Tree" << endl;   //Empty BST
        }
        break;
    }
}

//**************************************************************//
//Precondition - Function was Called with the Correct Parameters
//Postcondition - Function Creates a New Node, Sets as Null, and Returns that Node
//**************************************************************//
BSTNode *createNode(int data)
{
    //Creating New Node
    BSTNode *temp = new BSTNode();

    //Setting Data to User's Value and the Children to NULL
    temp->data = data;
    temp->right = temp->left = NULL;

    return temp;
}

//**************************************************************//
//Precondition - Function was Called with the Correct Parameters
//Postcondition - Function Returns the Lowest Value in the Tree
//**************************************************************//
BSTNode *minValue(BSTNode *node)
{
    //Creating New Node to Set as node
    BSTNode* current = node;

    //While Current Exists and Its Child Isn't NULL
    while(current && current->left != NULL)
    {
        current = current->left;
    }

    return current;
}

//**************************************************************//
//Precondition - Function was Called with the Correct Parameters
//Postcondition - Functions Deletes a Node with the User's Input
//**************************************************************//
BSTNode *deleteNode(BSTNode *root, int data)
{
    //BST Is Empty
	if(root == NULL)
    {
        return root;
    }

    //Node Being Deleted is Apart of the Left Children
	else if(data < root->data)
    {
        root->left = deleteNode(root->left,data);
    }

    //Node Being Deleted is Apart of the Right Children
	else if (data > root->data)
    {
        root->right = deleteNode(root->right,data);
    }

    //Root is Being Deleted
	else
    {
		//Root Has No Children
		if(root->left == NULL && root->right == NULL)
		{
		    root = NULL;
			delete root;
		}

		//Root Has One Child/Right
		else if(root->left == NULL)
		{
			BSTNode *temp = root;
			root = root->right;
			delete temp;
		}

		//Root Has One Child/Left
		else if(root->right == NULL)
		{
			BSTNode *temp = root;
			root = root->left;
			delete temp;
		}

		//Root Has Two Children
		else
		{
			BSTNode *temp = minValue(root->right);
			root->data = temp->data;
			root->right = deleteNode(root->right,temp->data);
		}
	}

	return root;
}

//**************************************************************//
//Precondition - Function was Called with the Correct Parameters
//Postcondition - Function Returns True if Value is Found and False if Value Isn't Found
//**************************************************************//
bool Search(BSTNode *root, int data)
{
    //Declares New BSTNode
	BSTNode *temp = new BSTNode;
	temp = root;

	//Run the Loop Until Loop Returns True or Temp Equals NULL
	while(temp != NULL)
	{
	    //Temp->Data Equals Value Trying to Find
		if(temp->data == data)
		{
			return true;
		}

		//Move to Left Child
		else if(temp->data > data)
        {
            temp = temp->left;
        }

		//Move to Right Child
		else
        {
            temp = temp->right;
        }
	}

	return false;
}

//**************************************************************//
//Precondition - Function was Called with the Correct Parameters
//Postcondition - Function Inserts a Node with the User's Inputted Value
//**************************************************************//
void insertNode(BSTNode *&root, int data)
{
    //Empty BST
    if(root == NULL)
    {
        root = createNode(data);    //Create a New Node at the Root
    }

    //If Root is Greater Than User's Inputted Data
    else if(root->data > data)
    {
        insertNode(root->left, data);   //Recall Program from the Left Child
    }

    //If Root is Less Than User's Inputted Data
    else
    {
        insertNode(root->right, data);  //Recall the Program from the Right Child
    }
}

//**************************************************************//
//Precondition - Function was Called with the Correct Parameters
//Postcondition - Function Pushes the Nodes onto a Stack
//**************************************************************//
void displayAllNode(BSTNode *root, stack<int> &finalQ)
{
    //If BST Isn't Empty
    if(root != NULL)
    {
        displayAllNode(root->left, finalQ); //Recall Program from the Left Child
        finalQ.push(root->data);            //Push Node/Value to Stack
        displayAllNode(root->right, finalQ);//Recall Program from the Right Child
    }
}

//**************************************************************//
//Precondition - Function was Called with the Correct Parameters
//Postcondition - Function Outputs the BST in Tree Format
//**************************************************************//
void displayTree(BSTNode *root, int test)
{
    //Declaring/Initializing Count Variable for Spacing
    int count = 5;

    //Empty Tree
    if(root == NULL)
    {
        return;
    }

    //Add Count to Test to Use in For Loop for Spacing
    test += count;

    //Recalls the Program from the Right Child
    displayTree(root->right, test);

    //For Loop to Add Spaces Between Values/Nodes
    for(int i = count; i < test; i++)
    {
        cout << " " ;
    }

    cout << root->data << endl;     //Outputs the Value/Data

    //Recalls the Program from the Left Child
    displayTree(root->left, test);
}

//**************************************************************//
//Precondition - Function was Called with the Correct Parameters
//Postcondition - Function Outputs the Maximum Sum of Tree Nodes
//**************************************************************//
void printMaxSum(BSTNode *root)
{
    //Sets the Value of Sum to the rootSum
    int sum = rootSum(root);

    //Outputs the Maximum Sum of Tree Nodes
    cout << "Maximum Sum: " << sum << endl;
}

//**************************************************************//
//Precondition - Function was Called with the Correct Parameters
//Postcondition - Function Returns the Maximum Root Path
//**************************************************************//
int rootSum(BSTNode *root)
{
    //BST is Empty
    if(root == NULL)
    {
        return 0;   //Size of Greatest Path is 0
    }

    //Figure Out the Maximum Sum for the Left-Child
    int left = rootSum(root->left);

    //Figure Out the Maximum Sum for the Right-Child
    int right = rootSum(root->right);

    //Figure Out Which Sum is Greater
    if(left > right)
    {
        return left + root->data;   //Add the Root's Data
    }
    else
    {
        return right + root->data;  //Add the Root's Data
    }
}
