#include <iostream>

bool isPrime(int x)
{
    int i = 2;
    if(x == 1 || x == 2)
    {
        return 1; //1 = Prime Number. The program already knows that both 1 and 2 are prime numbers.
    }
    else
    {
        while(i < x)
        {

            if(x % i == 0)
            {
                return 0; //0 = Not Prime Number. Hence, the number is divisible by a number evenly at least once.
            }
            i++;
        }
        return 1; //Prime Number. The program was not able to come up with a divisible factor for the number.
    }
}

void listSmallPrimes(int y)
{
    using namespace std;
    int i = 2; //Starts i at 2, since 0 and 1 are determined to be prime
    cout << "Here are other prime numbers up until " << y << ": ";
    while(i < y)//Less than y to make sure that it doesn't include itself, only the smaller prime numbers.
    {
        if(isPrime(i) == 1)
        {
            cout << i << " ";
        }
        i++;
    }
}

int main()
{
    using namespace std;
    int t;
    cout << "Input a 1 to run the program.\nInput a 0 to terminate the program.\n\n";
    cin >> t;
    if(t == 1)
    {
        int a;
        cout << "\nInput a positive whole number, and I will tell you if it is prime or not.  ";
        cin >> a;

        if(isPrime(a) == 1)
            {
                cout << "\nThe number you inputted:  " << a << ", is a prime number.\n\n";
                listSmallPrimes(a);
            }
        else
            {
                cout << "\nThe number you inputted:  " << a << ", is not a prime number.\n\n";
            }
    }
    else
    {
        return 0;
    }
}
