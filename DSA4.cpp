#include <iostream>
#include <iomanip>
#include <ctime>
#include <cmath>
using std::cin;
using std::cout;
using std::endl;
using std::setprecision;

//Function Prototypes
void menuOption(int &userAnswer, int &arraySize);
void swapValues(int *xVal, int *yVal);
void printArray(int arr[], int size);
void bubbleSort(int arr[], int sizeOfArray);
void insertionSort(int arr[], int sizeOfArray);
void selectionSort(int arr[], int sizeOfArray);
void startRace(int &userAnswer, int &arraySize);
void fillArrays(int a[], int b[], int c[], int &arraySize);
void mergeSort(int arr[], int l, int r) ;
void merge(int arr[], int l, int m, int r);
int firstPartition(int arr[], int zero, int arraySize);
void firstElementQuick(int arr[], int zero, int arraySize);
int middlePartition(int arr[], int zero, int arraySize);
void middleElementQuick(int arr[], int zero, int arraySize);

int main()
{
    //Declaration of Int Variables
    int userAnswer, arraySize;

    //Runs the Menu and Starts the Race with the User's Choices
    menuOption(userAnswer, arraySize);
    startRace(userAnswer, arraySize);

    return 0;
}

//*****************************************************************************//
//Pre-Condition: Function is Called with the Correct Parameters                //
//Post-Condition: Function Outputs a Menu to the Screen and Stores User Answers//
//*****************************************************************************//
void menuOption(int &userAnswer, int &arraySize)
{
    //Outputs a Menu Prompt to the Screen
    cout << "-----------------------------------------" << endl;
    cout << "      Allan's Sorting Method Racing      " << endl;
    cout << "-----------------------------------------" << endl;
    cout << "Select Which Type of Race: " << endl;
    cout << "\t1) O(n^2) Sorting Algorithms" << endl;
    cout << "\t2) O(nlogn) Soring Algorithms" << endl;
    cout << "-----------------------------------------" << endl;


    //Gets the Users Racing Selection and Validates Until a Correct Value is Selected
    cin >> userAnswer;
    while(userAnswer != 1 && userAnswer != 2)
    {
        cout << "Select a Valid Option(1 - 2):" << endl;
        cin >> userAnswer;
    }

    cout << "-----------------------------------------" << endl;
    cout << "Select What Size of Array: " << endl;
    cout << "\t1000" << endl;
    cout << "\t5000" << endl;
    cout << "\t10000" << endl;
    cout << "\t50000" << endl;
    cout << "\t75000" << endl;
    cout << "\t100000" << endl;
    cout << "\t500000" << endl;
    cout << "-----------------------------------------" << endl;
    cin >> arraySize;

    //Gets the Users Array Size and Validates Until a Correct Values is Selected
    while(arraySize != 1000 && arraySize != 5000 && arraySize != 10000 && arraySize != 50000 && arraySize != 75000 && arraySize != 100000 && arraySize != 500000)
    {
        cout << "Select a Valid Size(1000, 5000, 10000, 50000, 75000, 100000, or 500000):" << endl;
        cin >> arraySize;
    }
}

//*****************************************************************************//
//Pre-Condition: Function is Called with the Correct Parameters                //
//Post-Condition: Function Outputs the Different Sorted Times in Order from    //
//                Fastest to Slowest to the Display                            //
//*****************************************************************************//
void startRace(int &userAnswer, int &arraySize)
{
    //Declares Three Arrays and Set them All Equal to Each Other
    int a[arraySize], b[arraySize], c[arraySize];
    fillArrays(a, b, c, arraySize);

    //O(n^2) Sorting Functions
    if(userAnswer == 1)
    {
        //Declaring Time Variables
        clock_t time_req1, time_req2, time_req3;
        float time1 = 0.00000;
        float time2 = 0.00000;
        float time3 = 0.00000;

        //Tracks the Time it Takes to Run the Bubble Sort Function
        time_req1 = clock();
        bubbleSort(a, arraySize);
        time_req1 = clock() - time_req1;
        time1 = (float)time_req1/CLOCKS_PER_SEC;

        //Tracks the Time it Takes to Run the Insertion Sort Function
        time_req2 = clock();
        insertionSort(b, arraySize);
        time_req2 = clock() - time_req2;
        time2 = (float)time_req2/CLOCKS_PER_SEC;

        //Tracks the Time it Takes to Run the Selection Sort Function
        time_req3 = clock();
        selectionSort(c, arraySize);
        time_req3 = clock() - time_req3;
        time3 = (float)time_req3/CLOCKS_PER_SEC;

        //Bubble Sort is Slower than Insertion Sort
        if(time1 > time2)
        {
            //Bubble Sort is Slower than Selection Sort
            if(time1 > time3)
            {
                //Insertion Sort is Slower than Selection Sort
                if(time2 > time3)
                {
                    cout << "-----------------------------------------" << endl;
                    cout << setprecision(5) << "Scoring Results: " << endl;
                    cout << "\t1) Selection Sort - " << time3 << "s" << endl;
                    cout << "\t2) Insertion Sort - " << time2 << "s" << endl;
                    cout << "\t3) Bubble Sort - " << time1 << "s" << endl;
                    cout << "-----------------------------------------" << endl;
                }

                //Selection Sort is Slower than Insertion Sort
                else
                {
                    cout << "-----------------------------------------" << endl;
                    cout << setprecision(5) << "Scoring Results: " << endl;
                    cout << "\t1) Insertion Sort - " << time2 << "s" << endl;
                    cout << "\t2) Selection Sort - " << time3 << "s" << endl;
                    cout << "\t3) Bubble Sort - " << time1 << "s" << endl;
                    cout << "-----------------------------------------" << endl;
                }

            }

            //Selection Sort is Slower than Bubble Sort
            else
            {
                cout << "-----------------------------------------" << endl;
                cout << setprecision(5) << "Scoring Results: " << endl;
                cout << "\t1) Insertion Sort - " << time2 << "s" << endl;
                cout << "\t2) Bubble Sort - " << time1 << "s" << endl;
                cout << "\t3) Selection Sort - " << time3 << "s" << endl;
                cout << "-----------------------------------------" << endl;
            }
        }

        //Bubble Sort is Faster than Insertion Sort
        else if(time1 < time2)
        {
            //Bubble Sort is Faster than Selection Sort
            if(time1 < time3)
            {
                //Insertion Sort is Faster than Selection Sort
                if(time2 < time3)
                {
                    cout << "-----------------------------------------" << endl;
                    cout << setprecision(5) << "Scoring Results: " << endl;
                    cout << "\t1) Bubble Sort - " << time1 << "s" << endl;
                    cout << "\t2) Insertion Sort - " << time2 << "s" << endl;
                    cout << "\t3) Selection Sort - " << time3 << "s" << endl;
                    cout << "-----------------------------------------" << endl;
                }

                //Selection Sort is Faster than Insertion Sort
                else
                {
                    cout << "-----------------------------------------" << endl;
                    cout << setprecision(5) << "Scoring Results: " << endl;
                    cout << "\t1) Bubble Sort - " << time1 << "s" << endl;
                    cout << "\t2) Selection Sort - " << time3 << "s" << endl;
                    cout << "\t3) Insertion Sort - " << time2 << "s" << endl;
                    cout << "-----------------------------------------" << endl;
                }
            }

            //Selection Sort is Faster than Bubble Sort
            else
            {
                cout << "-----------------------------------------" << endl;
                cout << setprecision(5) << "Scoring Results: " << endl;
                cout << "\t1) Selection Sort - " << time3 << "s" << endl;
                cout << "\t2) Bubble Sort - " << time1 << "s" << endl;
                cout << "\t3) Insertion Sort - " << time2 << "s" << endl;
                cout << "-----------------------------------------" << endl;
            }

        }

        //Bubble Sort and Insertion Sort are the Same Speed
        else
        {
            //Bubble Sort is Faster than Selection Sort
            if(time1 < time3)
            {
                cout << "-----------------------------------------" << endl;
                cout << setprecision(5) << "Scoring Results: " << endl;
                cout << "\t1) Bubble Sort - " << time1 << "s" << endl;
                cout << "\t2) Insertion Sort - " << time2 << "s" << endl;
                cout << "\t3) Selection Sort - " << time3 << "s" << endl;
                cout << "-----------------------------------------" << endl;
            }

            //Selection Sort is Faster than Bubble Sort
            else
            {
                cout << "-----------------------------------------" << endl;
                cout << setprecision(5) << "Scoring Results: " << endl;
                cout << "\t1) Selection Sort - " << time3 << "s" << endl;
                cout << "\t2) Bubble Sort - " << time1 << "s" << endl;
                cout << "\t3) Insertion Sort - " << time2 << "s" << endl;
                cout << "-----------------------------------------" << endl;
            }
        }
    }

    //O(nlogn) Sorting Functions
    else if(userAnswer == 2)
    {
        //Declaring Time Variables
        clock_t time_req1, time_req2, time_req3;
        float time1 = 0.00000;
        float time2 = 0.00000;
        float time3 = 0.00000;

        //Tracks the Time it Takes to Run the Merge Sort Function
        time_req1 = clock();
        mergeSort(a, 0, arraySize);
        time_req1 = clock() - time_req1;
        time1 = (float)time_req1/CLOCKS_PER_SEC;

        //Tracks the Time it Takes to Run the Quick Sort(1st Element) Function
        time_req2 = clock();
        firstElementQuick(b, 0, arraySize);
        time_req2 = clock() - time_req2;
        time2 = (float)time_req2/CLOCKS_PER_SEC;

        //Tracks the Time it Takes to Run the Quick Sort(Middle Element) Function
        time_req3 = clock();
        middleElementQuick(c, 0, arraySize);
        time_req3 = clock() - time_req3;
        time3 = (float)time_req3/CLOCKS_PER_SEC;

        //Merge Sort is Slower than Quick Sort(1st Element)
        if(time1 > time2)
        {
            //Merge Sort is Slower than Quick Sort(Middle Element)
            if(time1 > time3)
            {
                //Quick Sort(1st Element) is Slower than Quick Sort(Middle Element)
                if(time2 > time3)
                {
                    cout << "-----------------------------------------" << endl;
                    cout << setprecision(5) << "Scoring Results: " << endl;
                    cout << "\t1) Quick Sort(Middle Element) - " << time3 << "s" << endl;
                    cout << "\t2) Quick Sort(1st Element) - " << time2 << "s" << endl;
                    cout << "\t3) Merge Sort - " << time1 << "s" << endl;
                    cout << "-----------------------------------------" << endl;
                }

                //Quick Sort(Middle Element) is Slower than Insertion Sort
                else
                {
                    cout << "-----------------------------------------" << endl;
                    cout << setprecision(5) << "Scoring Results: " << endl;
                    cout << "\t1) Quick Sort(1st Element) - " << time2 << "s" << endl;
                    cout << "\t2) Quick Sort(Middle Element) - " << time3 << "s" << endl;
                    cout << "\t3) Merge Sort - " << time1 << "s" << endl;
                    cout << "-----------------------------------------" << endl;
                }

            }

            //Quick Sort(Middle Element) is Slower than Merge Sort
            else
            {
                cout << "-----------------------------------------" << endl;
                cout << setprecision(5) << "Scoring Results: " << endl;
                cout << "\t1) Quick Sort(1st Element) - " << time2 << "s" << endl;
                cout << "\t2) Merge Sort - " << time1 << "s" << endl;
                cout << "\t3) Quick Sort(Middle Element) - " << time3 << "s" << endl;
                cout << "-----------------------------------------" << endl;
            }
        }

        //Merge Sort is Faster than Quick Sort(1st Element)
        else if(time1 < time2)
        {
            //Merge Sort is Faster than Quick Sort(Middle Element)
            if(time1 < time3)
            {
                //Quick Sort(1st Element) is Faster than Quick Sort(Middle Element)
                if(time2 < time3)
                {
                    cout << "-----------------------------------------" << endl;
                    cout << setprecision(5) << "Scoring Results: " << endl;
                    cout << "\t1) Merge Sort - " << time1 << "s" << endl;
                    cout << "\t2) Quick Sort(1st Element) - " << time2 << "s" << endl;
                    cout << "\t3) Quick Sort(Middle Element) - " << time3 << "s" << endl;
                    cout << "-----------------------------------------" << endl;
                }

                //Quick Sort(Middle Element) is Faster than Quick Sort(1st Element)
                else
                {
                    cout << "-----------------------------------------" << endl;
                    cout << setprecision(5) << "Scoring Results: " << endl;
                    cout << "\t1) Merge Sort - " << time1 << "s" << endl;
                    cout << "\t2) Quick Sort(Middle Element) - " << time3 << "s" << endl;
                    cout << "\t3) Quick Sort(1st Element) - " << time2 << "s" << endl;
                    cout << "-----------------------------------------" << endl;
                }
            }

            //Quick Sort(Middle Element) is Faster than Merge Sort
            else
            {
                cout << "-----------------------------------------" << endl;
                cout << setprecision(5) << "Scoring Results: " << endl;
                cout << "\t1) Quick Sort(Middle Element) - " << time3 << "s" << endl;
                cout << "\t2) Merge Sort - " << time1 << "s" << endl;
                cout << "\t3) Quick Sort(1st Element) - " << time2 << "s" << endl;
                cout << "-----------------------------------------" << endl;
            }

        }

        //Merge Sort and Quick Sort(1st Element) are the Same Speed
        else
        {
            //Merge Sort is Faster than Quick Sort(Middle Element)
            if(time1 < time3)
            {
                cout << "-----------------------------------------" << endl;
                cout << setprecision(5) << "Scoring Results: " << endl;
                cout << "\t1) Merge Sort - " << time1 << "s" << endl;
                cout << "\t2) Quick Sort(1st Element) - " << time2 << "s" << endl;
                cout << "\t3) Quick Sort(Middle Element) - " << time3 << "s" << endl;
                cout << "-----------------------------------------" << endl;
            }

            //Quick Sort(Middle Element) is Faster than Merge Sort
            else
            {
                cout << "-----------------------------------------" << endl;
                cout << setprecision(5) << "Scoring Results: " << endl;
                cout << "\t1) Quick Sort(Middle Element) - " << time3 << "s" << endl;
                cout << "\t2) Merge Sort - " << time1 << "s" << endl;
                cout << "\t3) Quick Sort(1st Element) - " << time2 << "s" << endl;
                cout << "-----------------------------------------" << endl;
            }
        }
    }

    else
    {
        cout << "Error Occurred!" << endl;
    }
}

//*****************************************************************************//
//*****************************************************************************//
// Array and Quick Sort Functions
//*****************************************************************************//
//*****************************************************************************//

//*****************************************************************************//
//Pre-Condition: Function is Called with the Correct Parameters                //
//Post-Condition: Function Fills Three Arrays with the Same Random Values      //
//*****************************************************************************//
void fillArrays(int a[], int b[], int c[], int &arraySize)
{
    //Initializes Random Seed
    srand(time(NULL));

    //Sets Each Number in the Array to a Random Number and Matches All Three Arrays
    for(int i = 0; i < arraySize; i ++)
    {
        a[i] = rand() % arraySize + 1;
        b[i] = a[i];
        c[i] = a[i];
    }
}

//*****************************************************************************//
//Pre-Condition: Function is Called with the Correct Parameters                //
//Post-Condition: Function Swaps the Values of the Two Integers                //
//*****************************************************************************//
void swapValues(int *xVal, int *yVal)
{
    //Declares/Stores the Value of Temp as xVal
    int temp = *xVal;

    //Sets the Value of xVal to yVal
    *xVal = *yVal;

    //Sets the Value of yVal to temp(xVal)
    *yVal = temp;
}

//*****************************************************************************//
//Pre-Condition: Function is Called and Used for Testing                       //
//Post-Condition: Function Outputs the Array to the Screen                     //
//*****************************************************************************//
void printArray(int arr[], int arraySize)
{
    //Loops the Length of the arraySize
    for(int i = 0; i < arraySize; i++)
    {
        //Prints the Value of arr[i]
        cout << arr[i] << " ";
    }
    //Prints a New Line
    cout << endl;
}

//*****************************************************************************//
//*****************************************************************************//
//                            Sorting Method Functions
//*****************************************************************************//
//*****************************************************************************//

//*****************************************************************************//
//Pre-Condition: Function is Called with the Correct Parameters                //
//Post-Condition: Function Bubble Sorts the Array                              //
//*****************************************************************************//
void bubbleSort(int arr[], int sizeOfArray)
{
    //Loops Through the Entire Array
    for(int i = 0; i < sizeOfArray - 1; i++)
    {
        //Loops Through the Entire Array - 1 Each Time
        for(int j = 0; j < sizeOfArray - i - 1; j++)
        {
            //The Current Value is Less Than the Next Value in the Array
            if(arr[j] > arr[j + 1])
            {
                //Swaps the Values so That They are In-Order
                swapValues(&arr[j], &arr[j + 1]);
            }
        }
    }
}

//*****************************************************************************//
//Pre-Condition: Function is Called with the Correct Parameters                //
//Post-Condition: Function Insertion Sorts the Array                           //
//*****************************************************************************//
void insertionSort(int arr[], int sizeOfArray)
{
    //Declaration of Variables
    int j, temp;

    //Loops Through the Entire Array
    for(int i = 1; i < sizeOfArray; i++)
    {
        //Sets Temp to the Ith Value in the Array and J to 1 Minus I
        temp = arr[i];
        j = i - 1;

        //Swaps Values in the Array That are Greater Than Temp to Sort the Array
        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = temp;
    }
}

//*****************************************************************************//
//Pre-Condition: Function is Called with the Correct Parameters                //
//Post-Condition: Function Selection Sorts the Array                           //
//*****************************************************************************//
void selectionSort(int arr[], int sizeOfArray)
{
    //Declaring the Minimum Value
    int minNum;

    //Loops Through the Entire Array
    for(int i = 0; i < sizeOfArray - 1; i++)
    {
        minNum = i;

        //Loops Through the Array, Skipping the Beginning on by I Each Time
        for(int j = i + 1; j < sizeOfArray; j++)
        {
            //If Current Value is Less Than minNum
            if(arr[j] < arr[minNum])
            {
                //Sets the Current Value to minNum
                minNum = j;
            }
        }

        //Swaps the Values so That the Minimum Value is in the Beginning of the Array
        swapValues(&arr[minNum], &arr[i]);
    }
}

//*****************************************************************************//
//Pre-Condition: Function is Called with the Correct Parameters                //
//Post-Condition: Function Splits into Two Sections, Puts Each Section in      //
//                Order, and Function Combines the Two Sections                //
//*****************************************************************************//
void merge(int arr[], int zero, int middle, int arraySize)
{
    //Declaring Variables for the First and Second Half of the Array
    int firstHalf = middle - zero + 1;
    int secondHalf = arraySize - middle;

    //Create Temporary Arrays
    int L[firstHalf], R[secondHalf];

    //Copy all of the Data up to the Half Size
    for(int i = 0; i < firstHalf; i++)
    {
        L[i] = arr[zero + i];
    }

    for(int j = 0; j < secondHalf; j++)
    {
        R[j] = arr[middle + 1 + j];
    }

    //Declaring Variables for the Sub-Array Index
    int a = 0;
    int b = 0;
    int c = zero;

    //Merges the Temp Arrays Back into Arr[]
    while(a < firstHalf && b < secondHalf)
    {
        if(L[a] <= R[b])
        {
            arr[c] = L[a];
            a++;
        }
        else
        {
            arr[c] = R[b];
            b++;
        }
        c++;
    }

    //Copies the Elements of L[]
    while(a < firstHalf)
    {
        arr[c] = L[a];
        a++;
        c++;
    }

    //Copies the Elements of R[]
    while(b < secondHalf)
    {
        arr[c] = R[b];
        b++;
        c++;
    }
}

//*****************************************************************************//
//Pre-Condition: Function is Called with the Correct Parameters                //
//Post-Condition: Function Merge Sorts an Array                                //
//*****************************************************************************//
void mergeSort(int arr[], int zero, int arraySize)
{
    if (zero < arraySize)
    {
        //Storing the Value in the Middle of the Array
        int mid = zero + (arraySize - zero) / 2;

        //Merge Sorts the First Half
        mergeSort(arr, zero, mid);

        //Merges Sorts the Second Half
        mergeSort(arr, mid + 1, arraySize);

        //Combines the Two Sorted Halves
        merge(arr, zero, mid, arraySize);
    }
}

//*****************************************************************************//
//Pre-Condition: Function is Called with the Correct Parameters                //
//Post-Condition: Function Partitions the Array and Returns the Pivot          //
//*****************************************************************************//
int firstPartition(int arr[], int zero, int arraySize)
{
    //Declares/Sets the Values of Variables/Pivot
    int pivot = arr[zero];
    int i = zero;
    int j = arraySize;

    //Loop While the First Element Does Not Equal the Last Element
    while(i < j)
    {
        //Every Time arr[i] is Less Than the Pivot, I is Increased by 1
        do
        {
            i++;
        } while(arr[i] <= pivot);

        //Every Time arr[j] is More Than the Pivot, J is Decreased by 1
        do
        {
            j--;
        } while(arr[j] > pivot);

        //If I Didn't Change the Same Amount of Times as J
        if(i < j)
        {
            swapValues(&arr[i], &arr[j]);
        }
    }

    //Swaps the Values of the First Value and the J'th Value
    swapValues(&arr[zero], &arr[j]);
    return j;
}

//*****************************************************************************//
//Pre-Condition: Function is Called with the Correct Parameters                //
//Post-Condition: Function Quick Sorts the Array with the First Element as     //
//                Pivot                                                        //
//*****************************************************************************//
void firstElementQuick(int arr[], int zero, int arraySize)
{
    //The First Element is Less Than the Last Element
    if(zero < arraySize)
    {
        //Sets J to the Pivot
        int j = firstPartition(arr, zero, arraySize);

        //Quick Sorts the First Half of the Array
        firstElementQuick(arr, zero, j);

        //Quick Sorts the Second Half of the Array
        firstElementQuick(arr, j + 1, arraySize);
    }
}

//*****************************************************************************//
//Pre-Condition: Function is Called with the Correct Parameters                //
//Post-Condition: Function Quick Sorts the Array with the Middle Element as    //
//                Pivot                                                        //
//*****************************************************************************//
void middleElementQuick(int arr[], int zero, int arraySize)
{
    //Declares/Sets the Values of Variables/Pivot
    int i = zero;
    int j = arraySize;
    int temp;
    int pivot = arr[(zero + arraySize) / 2];

    //Finding the Partition
    while(i <= j)
    {
        //If the Value at I is Less Than the Pivot
        while(arr[i] < pivot)
        {
            i++;
        }

        //If the Value at J is Greater Than the Pivot
        while(arr[j] > pivot)
        {
            j--;
        }

        //If I is Less Than or Equal to J
        if(i <= j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }

    //Recursion if the First Value is Less than J
    if(zero < j)
    {
        middleElementQuick(arr, zero, j);
    }

    //Recursion if I is Less Than the Last Value
    if(i < arraySize)
    {
        middleElementQuick(arr, i, arraySize);
    }
}
