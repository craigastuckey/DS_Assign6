//******************************************************************************
//
//
//******************************************************************************
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <cmath>

using namespace std;

void DisplayArr(int [], int);
void TableOfSquares(int, int);
int PowerFunction(int, int);
long long int SumOfSquares(int, int, long long int);
void MinMaxNum(int [], int, int, int&, int&);
void BubbleSort(int*, int, int);
bool IsMember(int [], int, int, int);
bool IsPrime(int, int);

int main() 
{
    bool verify = false;
    int size;
    char choice;
    int it = 0;
    int minIndex = 0;
    int maxIndex = 0;

    cout << "Thinking Recursively\n\nThe function of this program is to\nuse ";
    cout << "to :~\n\n\t\t1.\tDisplay squares of integers in ascending\n\t\t\t";
    cout << "order from 1 to the last element in the array\n\t\t2.\tRaise the ";
    cout << "first number to a power of\t2\n\t\t3.\tReturn the sums of squares";
    cout << " of the numbers\n\t\t\tfor 0 to a the fifth element in the array";
    cout << "\n\t\t4.\tSearch the array for the array's min and max values\n";
    cout << "\t\t5.\tSort the array in ascending order\n\t\t6.\tSearch the ";
    cout << "array for the first value in the array\n\t\t7.\tSearch the array ";
    cout << "for the number 600\n\t\t8.\tDetermine if a number is prime ";
    cout << "(processes all array values)\n\n";

    do
    {
        while(!verify)
        {
            cout << "\nSelect from the following menu\nA.\tEnter Array Size ";
            cout << "that is > 4.\nX.\tTerminate the Program.\t";

            cin >> choice;
            cin.clear();
            cin.ignore(120, '\n');

            if(choice!='X'&&choice!='x'&&choice!='A'&&choice!='a')
                cout << "*** Invalid Option ***\n";
            else
                verify = true;
        }

        verify = false;

        if(choice == 'A' || choice == 'a')
        {
            cout << "\nEnter Array Size: ";
            
            while(!verify)
            {
                cin >> size;

                if(size < 4)
                {
                    cout << "*** Invalid Array Size Value ***\n*** Enter Array";
                    cout << " Size That is > 4: ";
                }
                else if(cin.fail())
                {
                    cout << "*** Invalid Array Size Value ***\n*** Enter an ";
                    cout << "integer not a char: ";
                }
                else
                    verify = true;

                cin.clear();
                cin.ignore(120, '\n');
            }

            verify = false;

            //populating array
            int arr[size];
            srand(time(NULL));

            for(int i=0; i<size; i++)
                arr[i] = (rand() % 475) + 25;

            //displaying array
            DisplayArr(arr, size);

            //table of squares
            cout << "\nTable of square values 1 - " << arr[size-1] << "\n\nN\t";
            cout << "N Squared";
            TableOfSquares(arr[size-1], it);

            //power function
            cout << "\n\nPower Function:\n" << arr[0] << " raised to the ";
            cout << "second power is: " << PowerFunction(arr[0], it) << endl;

            //sum of squares
            cout << "\nSum of squares between 0 and " << arr[size-2] << " is: ";
            cout << SumOfSquares(arr[size-2], it, 0) << endl;

            //min/max
            MinMaxNum(arr, size, it, minIndex, maxIndex);
            cout << "\nMin Number of ( ";
            for(int i=0; i<size; i++)
            {
                cout << arr[i];
                if(i < size-1)
                    cout << " , ";
                else
                    cout << " ";
            }
            cout << ") is : " << arr[minIndex] << "\nMax Number of ( ";
            for(int i=0; i<size; i++)
            {
                cout << arr[i];
                if(i < size-1)
                    cout << " , ";
                else
                    cout << " ";
            }
            cout << ") is : " << arr[maxIndex] << endl;

            //bubble sort
            BubbleSort(arr, size, it);
            cout << "\nSorted array\n";
            for(int i=0; i<size; i++)
                cout << arr[i] << " ";

            //is/is not member
            cout << "\n\nMember Functions:\nDoes the array: ";
            for(int i=0; i<size; i++)
                cout << arr[i] << " ";
            cout << "have the number " << arr[3] << "? ";
            cout << (IsMember(arr, size, arr[3], it) ? "YES":"NO");
            cout << "\nDoes the array: ";
            for(int i=0; i<size; i++)
                cout << arr[i] << " ";
            cout << "have the number 600? ";
            cout << (IsMember(arr, size, 600, it) ? "YES":"NO") << endl;

            //is prime
            cout << "\nIs it prime:\n";
            for(int i=0; i<size; i++)
            {
                cout << "The number " << arr[i];
                cout << (IsPrime(arr[i], it+2) ? " is ": " is Not ");
                cout << "Prime\n";
            }
        }
        else
            verify = true;
    }
    while(!verify);

    cout << "\nCraig Stuckey and DeVante Walls\nApril 2017";

    return 0;
}

void DisplayArr(int arr[], int size)
{
    cout << "\nThe generated array is: ";
    for(int i=0; i<size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void TableOfSquares(int cap, int it)
{
    if(cap == it)
        return;
    cout << endl << it + 1 << '\t' << (it+1) * (it+1);
    TableOfSquares(cap, it+1);
}
int PowerFunction(int val, int it)
{
    if(it == 1)
        return val;

    return val * PowerFunction(val, it+1); 
}
long long int SumOfSquares(int cap, int it, long long int sum)
{
    if(it > cap)
        return sum;

    sum += it * it;
    
    return SumOfSquares(cap, it+1, sum);
}
void MinMaxNum(int arr[], int size, int it, int& minIndex, int& maxIndex)
{
    if(it == size)
        return;
    else if(arr[it] < arr[minIndex])
        minIndex = it;
    else if(arr[it] > arr[maxIndex])
        maxIndex = it;
    MinMaxNum(arr, size, it+1, minIndex, maxIndex);
}
void BubbleSort(int* arr, int size, int it)
{
    int temp;

    if(it == size-1)
        return;
    if(arr[it] < arr[it+1])
    {
        temp = arr[it];
        arr[it] = arr[it+1];
        arr[it+1] = temp;
    }

    BubbleSort(arr, size, it+1);
}
bool IsMember(int arr[], int size, int val, int it)
{
    if(it == size)
        return false;
    else if(arr[it] == val)
        return true;
    return IsMember(arr, size, val, it+1);
}
bool IsPrime(int val, int it)
{
    if(it == val)
        return true;
    else if(val % it == 0)
        return false;
    
    return IsPrime(val, it+1); 
}
