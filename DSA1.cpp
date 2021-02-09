#include<stdio.h>
#include<math.h>
#include<iostream>
#include<fstream>
#include<string>
using std::endl;
using std::cout;
using std::cin;
using std::string;
using std::ifstream;

struct node
{
    string cityName;
    double xPos;
    double yPos;
    node *next;
};
node *head = NULL;

class City
{
private:
    string cityName;
    double xPos;
    double yPos;
public:
    // Default Constructor
    City()
    {
        cityName = "EMPTY";
        xPos = 0.0;
        yPos = 0.0;
    }
    // Deconstructor
    ~City()
    {

    }
    // Getter for cityName
    string getCity()
    {
        return cityName;
    }
    // Setter for cityName
    void setCity(string newCityName)
    {
        cityName = newCityName;
    }
    // Getter for xPos
    double getXPos()
    {
        return xPos;
    }
    // Setter for xPos
    void setXPos(double newXPos)
    {
        xPos = newXPos;
    }
    // Getter for yPos
    double getYPos()
    {
        return yPos;
    }
    // Setter for yPos
    void setYPos(double newYPos)
    {
        yPos = newYPos;
    }
};
//FUNCTION PROTYPES
void showMenu(int &choice, char &choice1);
void menuOption(node *&head, node *&last, int &choice, char &choice1, City *ArrayOfCities[]);
long double dec_to_rad(long double degree);

//LINK LIST FUNCTION PROTYPES
void insertNode(node *&head, node *&last, string cityName, double xPos, double yPos);
void removeNode(node *&head, node *&last);
void showList(struct node *current);
bool isEmpty(node *head);
bool isRepeated(struct node *current, string cityName);
bool isRepeated(struct node *current, double xPos, double yPos);
void searchByTitle(struct node *current, string cityName);
void searchByCoordinates(struct node *current);
void deleteByTitle(struct node *current);
void deleteByCoordinates(struct node *current);
void printWithRange(struct node *current);

//ARRAY FUNCTION PROTOYPES
void beginArray(City *ArrayOfCities[]);
void menuOption(City *ArrayOfCities[], int &choice, char &choice1);
void insertRecord(City *ArrayOfCities[]);
void searchByName(City *ArrayOfCities[]);
void searchByCoord(City *ArrayOfCities[]);
void deleteByName(City *ArrayOfCities[]);
void deleteByCoord(City *ArrayOfCities[]);
void printInRange(City *ArrayOfCities[]);
void printAllRecords(City *ArrayOfCities[]);
void shiftForwards(City *ArrayOfCities[], int spot);

//*************************************************************
//Pre-Condition: Function was called with correct parameters
//Post-Condition: Function runs the program, gives the user options, and closes the program
//*************************************************************
int main()
{
    node *head = NULL;
    node *last = NULL;
    string cityName;
    double xPos, yPos;

    int choice;
    char choice1;
    string line, firstLine, xPosTest, yPosTest;
    char fileName[20] = "TestData.txt";

    City *ArrayOfCities[1000];
    beginArray(ArrayOfCities);

    // Checks to See if the File is Open/Exists
    ifstream inputFile;
    inputFile.open(fileName);
    if(!inputFile)
    {
        cout << "Error: File does not exist." << endl;
        system("pause");
        return 0;
    }

    // Stores the First Line into firstLine
    getline(inputFile, firstLine);
    for(int i = 0; i < 20; i ++)
    {
        // Used to Transfer TestData.txt
        getline(inputFile, line);
        std::size_t s = line.find(":");
        std::size_t t = line.find(",");
        cityName = line.substr(0, s);       // cityName = City Name
        xPosTest = line.substr((s + 2), t);
        xPos = stod(xPosTest);              // xPos = X Coordinate
        yPosTest = line.substr(t + 2);
        yPos = stod(yPosTest);              // yPos = Y Coordinate

        insertNode(head, last, cityName, xPos, yPos);
        ArrayOfCities[i]->setCity(cityName);
        ArrayOfCities[i]->setXPos(xPos);
        ArrayOfCities[i]->setYPos(yPos);
    }

        do{
            showMenu(choice, choice1);
            menuOption(head, last, choice, choice1, ArrayOfCities);
        }while(choice != 8);

    inputFile.close();
}

//*************************************************************
//Pre-Condition: Function was called with correct parameters
//Post-Condition: Function displays a menu to the output
//*************************************************************
void showMenu(int &choice, char &choice1)
{
    cout << "*********************************************************" << endl;
    cout << "Implementation Options: " << endl;
    cout << "A. Use an Array-Based List Implementation" << endl;
    cout << "B. Use a Linked-List Implementation" << endl;
    cout << "---------------------------------------------------------" << endl;
    cout << "Operation Options: " << endl;
    cout << "1. Insert a Record" << endl;
    cout << "2. Search for a Record by Name" << endl;
    cout << "3. Search for a Record by Coordinate" << endl;
    cout << "4. Delete a Record by Name" << endl;
    cout << "5. Delete a Record by Coordinate" << endl;
    cout << "6. Print Records Within a Given" << endl;
    cout << "   Distance of a Specified Location" << endl;
    cout << "7. Print all Records" << endl;
    cout << "8. Exit" << endl << endl;

    cout << "Enter your Implementation Option: ";
    cin >> choice1;

    cout << "Enter your Operation Option: ";
    cin >> choice;
    cout << endl;
}

//*************************************************************
//Pre-Condition: Function was called with correct parameters
//Post-Condition: Function runs the corresponding functions to the user's choices
//*************************************************************
void menuOption(node *&head, node *&last, int &choice, char &choice1, City *ArrayOfCities[])
{
    string cityName;
    double xPos, yPos;

    if(choice1 == 'A')
    {
        switch(choice)
        {
        case 1:
            insertRecord(ArrayOfCities);
            break;
        case 2:
            searchByName(ArrayOfCities);
            break;
        case 3:
            searchByCoord(ArrayOfCities);
            break;
        case 4:
            deleteByName(ArrayOfCities);
            break;
        case 5:
            deleteByCoord(ArrayOfCities);
            break;
        case 6:
            printInRange(ArrayOfCities);
            break;
        case 7:
            printAllRecords(ArrayOfCities);
            break;
        case 8:
            cout << "Exiting Program..." << endl;
            break;
        }
    }

    if(choice1 == 'B')
    {
        switch(choice)
        {
        case 1:
            cout << "Enter the Name of City: ";
            cin >> cityName;

            cout << "Enter X Coordinate: ";
            cin >> xPos;
            cout << "Enter Y Coordinate: ";
            cin >> yPos;

            insertNode(head, last, cityName, xPos, yPos);
            cout << "Record Successfully Inserted!" << endl;
            break;
        case 2:
            cout << "Enter the Name of the City: ";
            cin >> cityName;

            if(isRepeated(head, cityName) == true)
            {
                searchByTitle(head, cityName);
                break;
            }
            else
            {
                cout << "City Not Found in Records!" << endl;
                break;
            }
        case 3:
            searchByCoordinates(head);
            break;
        case 4:
            deleteByTitle(head);
            break;
        case 5:
            deleteByCoordinates(head);
            break;
        case 6:
            printWithRange(head);
            break;
        case 7:
            showList(head);
            break;
        case 8:
            cout << "Exiting Program..." << endl;
            break;
        }
    }
}

//*************************************************************
//Pre-Condition: Function was called with correct parameters
//Post-Condition: Function turns degrees into radians
//*************************************************************
long double dec_to_rad(long double degree)
{
    long double M_PI = 3.1415926535;
    return (degree * (M_PI / 180.0));
}

//LINKED LIST FUNCTIONS
//*************************************************************
//Pre-Condition: Function was called with correct parameters
//Post-Condition: Function inserts the 1st element into a list
//*************************************************************
void insertAsFirstElement(node *&head, node *&last, string cityName, double xPos, double yPos)
{
    node *temp = new node;
    temp->cityName = cityName;
    temp->xPos = xPos;
    temp->yPos = yPos;
    head = temp;
    last = temp;
}

//*************************************************************
//Pre-Condition: Function was called with correct parameters
//Post-Condition: The function inserts an element into a list
//*************************************************************
void insertNode(node *&head, node *&last, string cityName, double xPos, double yPos)
{
    if(isEmpty(head))
    {
        insertAsFirstElement(head, last, cityName, xPos, yPos);
    }
    else
    {
        node *temp = new node;
        temp->cityName = cityName;
        temp->xPos = xPos;
        temp->yPos = yPos;
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }
}

//*************************************************************
//Pre-Condition: Function was called with correct parameters
//Post-Condition: The function uses the city title to delete a node in the list
//*************************************************************
void deleteByTitle(struct node *current)
{
    string cityName;
    cout << "Enter the Name of the City: ";
    cin >> cityName;

    // Empty List
    if(isEmpty(current))
    {
        cout << "The List is Already Empty!" << endl;
    }
    // Only One Item in List
    else if(current->next == NULL)
    {
        delete current;
        current = NULL;
        cout << "Successfully Deleted Record!" << endl;
    }
    // More Than One Item in List
    else
    {
        node *p = new node;
        node *q = new node;
        q = current;
        p = current->next;

        if(q->cityName == cityName)
        {
            head = p;
            delete(q);
        }
        else
        {
            while(p->cityName != cityName)
            {
                p = p->next;
                q = q->next;
            }
            if(p->next == NULL)
            {
                q->next = NULL;
                delete(p);
            }
            else
            {
                q->next = p->next;
                delete(p);
            }
        }
        cout << "Successfully Deleted Record!" << endl;
    }
}

//*************************************************************
//Pre-Condition: Function was called with correct parameters
//Post-Condition: The function uses the city's coordinates to delete a node in the list
//*************************************************************
void deleteByCoordinates(struct node *current)
{
    double xPosTest, yPosTest;
    bool testFail = true;
    node *temp;
    temp = current;

    cout << "Enter the X Coordinate: ";
    cin >> xPosTest;
    cout << "Enter the Y Coordinate: ";
    cin >> yPosTest;

    while(temp != NULL)
    {
        if(temp->xPos == xPosTest)
        {
            testFail = false;
        }
        temp = temp->next;
    }

    if(testFail == false)
    {
        // Empty List
        if(isEmpty(current))
        {
            cout << "The List is Already Empty!" << endl;
        }
        // Only One Item in List
        else if(current->next == NULL)
        {
            delete current;
            current = NULL;
            cout << "Successfully Deleted Record!" << endl;
        }
        // More Than One Item in List
        else
        {
            node *p = new node;
            node *q = new node;
            q = current;
            p = current->next;

            if(q->xPos == xPosTest && q->yPos == yPosTest)
            {
                head = p;
                delete(q);
            }
            else
            {
                while(p->xPos != xPosTest && p->yPos != yPosTest)
                {
                    p = p->next;
                    q = q->next;
                }
                if(p->next == NULL)
                {
                    q->next = NULL;
                    delete(p);
                }
                else
                {
                    q->next = p->next;
                    delete(p);
                }
            }
            cout << "Successfully Deleted Record!" << endl;
        }
    }
    else
    {
        cout << "Coordinates Not Found in Records!" << endl;
    }
}

//*************************************************************
//Pre-Condition: Function was called with correct parameters
//Post-Condition: Function outputs the list to the display
//*************************************************************
void showList(struct node *current)
{
    if(isEmpty(current))
    {
        cout << "The List is Empty!" << endl;
    }
    else
    {
        cout << "The List Contains: " << endl;
        while(current != NULL)
        {
            cout << current->cityName << ": (" << current->xPos << ", " << current->yPos << ")" << endl;
            current = current->next;
        }
    }
}

//*************************************************************
//Pre-Condition: Function was called with correct parameters
//Post-Condition: Function outputs the location of the user inputted city name
//*************************************************************
void searchByTitle(struct node *current, string cityName)
{
    while(current != NULL)
    {
        if(current->cityName == cityName)
        {
            cout << cityName << ": (" << current->xPos << ", " << current->yPos << ")" << endl;
        }
        current = current->next;
    }
}

//*************************************************************
//Pre-Condition: Function was called with correct parameters
//Post-Condition: Function outputs the name of the city by using the user's inputted coordinates
//*************************************************************
void searchByCoordinates(struct node *current)
{
    bool testFail = true;
    double xPosTest, yPosTest;

    cout << "Enter the X Coordinate: ";
    cin >> xPosTest;
    cout << "Enter the Y Coordinate: ";
    cin >> yPosTest;

    while(current != NULL)
    {
        if(current->xPos == xPosTest)
        {
            cout << current->cityName << "(" << current->xPos << ", " << current->yPos << ")" << endl;
            testFail = false;
        }
        current = current->next;
    }

    if(testFail == true)
    {
        cout << "Coordinates Don't Match any City on Record" << endl;
    }
}

//*************************************************************
//Pre-Condition: Function was called with correct parameters
//Post-Condition: Function outputs the cities within the user's range
//*************************************************************
void printWithRange(struct node *current)
{
    bool testFail = true;
    string cityName;
    double distance, totalRange;
    double lat1, long1, lat2, long2;

    node *temp;
    temp = current;

    cout << "Enter Name of Location: ";
    cin >> cityName;
    cout << "Enter the Distance Range: ";
    cin >> distance;

    while(temp != NULL)
    {
        if(temp->cityName == cityName)
        {
            lat1 = dec_to_rad(temp->xPos);
            long1 = dec_to_rad(temp->yPos);
        }
        temp = temp->next;
    }

    while(current != NULL)
    {
        lat2 = dec_to_rad(current->xPos);
        long2 = dec_to_rad(current->yPos);
        totalRange = (3963.191) * acos(sin(lat1) * sin(lat2) + cos(lat1) * cos(lat2) * cos(long2 - long1));

        if(totalRange <= distance)
        {
            cout << current->cityName << ": (";
            cout << current->xPos << ", ";
            cout << current->yPos << ")" << endl;
            testFail = false;
        }
        current = current->next;
    }
    if(testFail == true)
    {
        cout << "No Cities Found in That Range." << endl;
    }
}

//*************************************************************
//Pre-Condition: Function was called with correct parameters
//Post-Condition: Functions checks to see if list is empty
//*************************************************************
bool isEmpty(node *head)
{
    if(head == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//*************************************************************
//Pre-Condition: Function was called with correct parameters
//Post-Condition: Function checks for repeats of city names
//*************************************************************
bool isRepeated(struct node *current, string cityName)
{
    node *tp = new node;
    tp = current;
    while(tp != NULL)
    {
        if(tp->cityName == cityName)
        {
            return true;
        }
        tp = tp->next;
    }
    delete(tp);
    return false;
}

//*************************************************************
//Pre-Condition: Function was called with correct parameters
//Post-Condition: Function checks for repeats of coordinates
//*************************************************************
bool isRepeated(struct node *current, double xPos, double yPos)
{
    node *temp = new node;
    temp = head;
    while(temp != NULL)
    {
        if(temp->xPos == xPos && temp->yPos == yPos)
        {
            return true;
        }
        temp = temp->next;
    }
    delete(temp);
    return false;
}

//ARRAY FUNCTIONS
//*************************************************************
//Pre-Condition: Function was called with correct parameters
//Post-Condition: Function inserted a record into the array
//*************************************************************
void insertRecord(City *ArrayOfCities[])
{
    int spot;
    string cityName;
    bool copyCity = false;
    double xPos, yPos;

    cout << "Enter the Name of the City: ";
    cin >> cityName;

    cout << "Enter the X Coordinate of the City: ";
    cin >> xPos;
    cout << "Enter the Y Coordinate of the City: ";
    cin >> yPos;

    for(int i = 0; i < 25; i++)
    {
        if(ArrayOfCities[i]->getCity() == "EMPTY")
        {
            spot = i;
        }
    }

    for(int j = 0; j < 1000; j++)
    {
        if(ArrayOfCities[j]->getCity() == cityName)
        {
            cout << "No Need to Insert Existing Record." << endl << endl << endl;
            copyCity = true;
        }
    }

    if(copyCity == false)
    {
        ArrayOfCities[spot]->setCity(cityName);
        ArrayOfCities[spot]->setXPos(xPos);
        ArrayOfCities[spot]->setYPos(yPos);

        cout << "Record Inserted Successfully!" << endl << endl << endl;
    }
}

//*************************************************************
//Pre-Condition: Function was called with correct parameters
//Post-Condition: Function outputs the coordinates of user selected city name
//*************************************************************
void searchByName(City *ArrayOfCities[])
{
    int spot;
    string cityName;
    bool testFail = true;

    cout << "Enter the Name of the City: ";
    cin >> cityName;

    for(int i = 0; i < 1000; i++)
    {
        if(ArrayOfCities[i]->getCity() == cityName)
        {
            testFail = false;
            spot = i;
        }
    }

    if(testFail == false)
    {
        cout << cityName << ", (" << ArrayOfCities[spot]->getXPos();
        cout << ", " << ArrayOfCities[spot]->getYPos() << ")";
        cout << endl;
    }
    else
    {
        cout << "Not the Name of a City on Record." << endl;
    }
}

//*************************************************************
//Pre-Condition: Function was called with correct parameters
//Post-Condition: Function outputs the name of city of user selected coordinates
//*************************************************************
void searchByCoord(City *ArrayOfCities[])
{
    int spot;
    double xPos, yPos;
    bool testFail = true;
    cout << "Enter the X Coordinate: ";
    cin >> xPos;
    cout << "Enter the Y Coordinate: ";
    cin >> yPos;

    for(int i = 0; i < 1000; i++)
    {
        if(ArrayOfCities[i]->getXPos() == xPos && ArrayOfCities[i]->getYPos() == yPos)
        {
            testFail = false;
            spot = i;
        }
    }

    if(testFail == true)
    {
        cout << "Not the Coordinates of any City on Record." << endl;
    }
    else
    {
        cout << "Coordinates of: " << ArrayOfCities[spot]->getCity() << endl;
    }
}

//*************************************************************
//Pre-Condition: Function was called with correct parameters
//Post-Condition: Function deletes the city in an array
//*************************************************************
void deleteByName(City *ArrayOfCities[])
{
    int spot;
    bool testFail = true;
    string cityName;
    cout << "Enter the Name of the City: ";
    cin >> cityName;

    for(int i = 0; i < 1000; i++)
    {
        if(ArrayOfCities[i]->getCity() == cityName)
        {
            spot = i;
            testFail = false;
        }
    }

    if(testFail == true)
    {
        cout << "City Not Found in Records." << endl << endl << endl;
    }
    else
    {
        shiftForwards(ArrayOfCities, spot);
        cout << "Successfully Deleted!" << endl << endl << endl;
    }
}

//*************************************************************
//Pre-Condition: Function was called with correct parameters
//Post-Condition: Function deletes the coordinates in an array
//*************************************************************
void deleteByCoord(City *ArrayOfCities[])
{
    int spot;
    double xPos, yPos;
    bool testFail = true;
    cout << "Enter the X Coordinate: ";
    cin >> xPos;
    cout << "Enter the Y Coordinate: ";
    cin >> yPos;

    for(int i = 0; i < 1000; i++)
    {
        if(ArrayOfCities[i]->getCity() != "EMPTY")
        {
            double xPosTest = ArrayOfCities[i]->getXPos();
            if(xPos == xPosTest)
            {
                spot = i;
                testFail = false;
            }
        }
    }

    if(testFail == true)
    {
        cout << "Coordinates Not Found in Records." << endl;
    }
    else
    {
        shiftForwards(ArrayOfCities, spot);
        cout << "Successfully Deleted!" << endl;
    }
}

//*************************************************************
//Pre-Condition: Function was called with correct parameters
//Post-Condition: The function outputs the cities within the range
//*************************************************************
void printInRange(City *ArrayOfCities[])
{
    bool testFail = true;
    string cityName;
    double distance, totalRange;
    double lat1, long1, lat2, long2;

    cout << "Enter Name of Location: ";
    cin >> cityName;
    cout << "Enter the Distance Range: ";
    cin >> distance;

    for(int j = 0; j < 1000; j++)
    {
        if(ArrayOfCities[j]->getCity() == cityName)
        {
            lat1 = dec_to_rad(ArrayOfCities[j]->getXPos());
            long1 = dec_to_rad(ArrayOfCities[j]->getYPos());
            j = 1000;
        }
    }

    for(int i = 0; i < 1000; i++)
    {
        lat2 = dec_to_rad(ArrayOfCities[i]->getXPos());
        long2 = dec_to_rad(ArrayOfCities[i]->getYPos());
        totalRange = (3963.191) * acos(sin(lat1) * sin(lat2) + cos(lat1) * cos(lat2) * cos(long2 - long1));

        if(totalRange <= distance)
        {
            cout << ArrayOfCities[i]->getCity() << ": (";
            cout << ArrayOfCities[i]->getXPos() << ", ";
            cout << ArrayOfCities[i]->getYPos() << ")" << endl;
            testFail = false;
        }
    }
    if(testFail == true)
    {
        cout << "No Cities Found in That Range." << endl;
    }
    else
    {
        cout << endl;
    }
}

//*************************************************************
//Pre-Condition: Function was called with correct parameters
//Post-Condition: The function prints all record in the array
//*************************************************************
void printAllRecords(City *ArrayOfCities[])
{
    for(int i = 0; i < 1000; i++)
    {
        if(ArrayOfCities[i]->getCity() != "EMPTY")
        {
            cout << ArrayOfCities[i]->getCity() << " (";
            cout << ArrayOfCities[i]->getXPos() << ", ";
            cout << ArrayOfCities[i]->getYPos() << ")" << endl;
        }
    }
    cout << endl;
}

//*************************************************************
//Pre-Condition: Function was called with correct parameters
//Post-Condition: Function creates an array of size 1,000 of city objects
//*************************************************************
void beginArray(City *ArrayOfCities[])
{
    for(int i = 0; i < 1000; i++)
    {
        ArrayOfCities[i] = new City();
    }
}

//*************************************************************
//Pre-Condition: Function was called with correct parameters
//Post-Condition: The function shifts arrays forward to fill empty spots
//*************************************************************
void shiftForwards(City *ArrayOfCities[], int spot)
{
    for(int i = spot; ArrayOfCities[i]->getCity() != "EMPTY"; i++)
    {
        ArrayOfCities[i] = ArrayOfCities[i + 1];
    }
}
