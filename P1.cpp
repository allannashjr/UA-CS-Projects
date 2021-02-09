#include <iostream>
#include <iomanip>
#include <limits>

//Function used to calculate the government tax of a called upon value
double getGovTax(double x)
{
    return ((.06) * x);
}
//Function used to calculate the captain's tax of a called upon value
double getCaptTax(double y)
{
    return ((.08) * y);
}
//Function used to calculate the tip for the mate of a called upon value
double getMateTip(double z)
{
    return ((.10) * z);
}
//Function used to calculate the retirement fund of a called upon value
double getRetirementFund(double r)
{
    return ((.005) * r);
}
//Function used to calculate the total ducats of a called upon value
double getPaymentTotal(double s)
{
    int tot = s;
    int x = 1;
    int i = 0;
    while(x == 1)
    {
        if(tot <= 6)
        {
            x = 0;
            i++;
            return i;
        }
        else
        {
            tot = tot - 6;
            i++;
        }
    }
}
//Function used to determine whether the called upon values are valid or not
bool validateInput(double userChoice, double range1, double range2)
{
    using namespace std;
    bool yesOrNo = true;
    if((cin.fail()) ||((userChoice < range1) || (userChoice > range2)))
    {
        yesOrNo = false;
    }
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return yesOrNo;
}
//Function used to ask the user for how much the food was, and then return the value
double getFood()
{
    using namespace std;
    double doof;
    bool check = true;
    do
    {
        cout << "How much did your food cost? $";
        cin >> doof;
        check = validateInput(doof, 0, 9999.99);
        if(!check)
        {
            cout << "The input was invalid, make sure that this is a valid number!\n";
        }
    }
    while(!check);
    return doof;
}
//Function used to ask the user for how many pints, and then return the value
double getPints()
{
    using namespace std;
    double stnip;
    bool check = true;
    do
    {
        cout << "How many number of pints of ale did you drink? ";
        cin >> stnip;
        check = validateInput(stnip, 0, 9999.99);
        if(!check)
        {
            cout << "The input was invalid, make sure that this is a valid number!\n";
        }
    }
    while(!check);
    return stnip;
}
//Function used to display the receipt, could of also been placed into to main
void getReceipt()
{
    using namespace std; //Made variables with values using logic/math for more efficient usage when calling for them later on
    double food = getFood();
    double pints = getPints();
    double pintsTotalPrice = (4.50 * pints);
    double subTotal = pintsTotalPrice + food;
    double govTax = getGovTax(subTotal);
    double captTax = getCaptTax(pintsTotalPrice);
    double mateTip = getMateTip(food);
    double retirementFund = getRetirementFund(subTotal);
    double total = ((subTotal) + (getGovTax(subTotal)) + (getCaptTax(pintsTotalPrice)) + (getMateTip(food)) + (getRetirementFund(subTotal)));
    double payment = getPaymentTotal(total);

    //Displays a mock-up of a receipt with how much the user owes in each category
    cout << "Here is your receipt:\n\n"
         << "---------------------------------\n"
         << "\t  The Gallery of\nThe Feared Raider of the Cuyahoga\n"
         << "---------------------------------\n"
         << setprecision(2) << fixed << showpoint << endl; //Set the receipt to 2 decimals

    //Set a "setw" on each line to align the wording, then used an "internal" class to align the decimal points up
    cout << "Meal" << setw(24) << "$ " << setw(5) << internal << right << food << endl;
    cout << "Ale" << setw(25) << "$ " << setw(5) << internal << pintsTotalPrice << endl;
    cout << setw(34) << "-------\n";
    cout << "Subtotal" << setw(20) << "$ " << setw(5) << internal << subTotal << endl;
    cout << "Gov. Tax" << setw(20) << "$ " << setw(5) << internal << govTax << endl;
    cout << "Capt. Tax" << setw(19) << "$ " << setw(5) << internal << right << captTax << endl;
    cout << "Mate Tip" << setw(20) << "$ " << setw(5) << internal << mateTip << endl;
    cout << "Retirement Fund" << setw(13) << "$ " << setw(5) << internal << retirementFund << endl;
    cout << setw(34) << "-------\n" << endl;
    cout << "Total" << setw(23) << "$ " << setw(5) << internal << total << endl;
    cout << setprecision(0) << fixed << setw(5) << internal << noshowpoint << endl;
    cout << "---------------------------------\n";
    cout << "Payment: " << payment << " Ducats" << endl;
    cout << "---------------------------------\n\n\n";
}
//Main function that calls functions which call more functions, all inside of a loop that stops the program after being ran ten times
int main()
{
    using namespace std;
    int j = 1;
    int i = 0;
    int stop;
    while(j == 1)
    {
        getReceipt();
        i++;
        if(i == 10)
        {
            cout << "You have ran the program ten times. Program is now ending...";
            return 0;
            j = 0;
        }
        cout << "Enter 1 to run the program again, or press zero to terminate the program. ";
        cin >> stop;
        if(stop == 0)
        {
            return 0;
        }
    }
    return 0;
}
