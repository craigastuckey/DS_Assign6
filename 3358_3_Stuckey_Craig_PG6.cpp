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
void TableOfSquares(int [], int);
void PowerFunction(int, int);
long long int SumOfSquares(int);
void MinMaxNum(int [], int);
void BubbleSort(int*, int);
bool IsMember(int [], int, int);
void IsPrime(int [], int);

int main() 
{
    bool verify = false;
    int size;
    char choice;

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
        verify = false;

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

            int arr[size];
            srand(time(NULL));

            for(int i=0; i<size; i++)
                arr[i] = (rand() % 475) + 25;

            DisplayArr(arr, size);
            TableOfSquares(arr, size);
            PowerFunction(arr[0], 2);
            cout << "\nSum of squares between 0 and " << arr[size-2] << " is: ";
            cout << SumOfSquares(size-2) << endl;
            MinMaxNum(arr, size);
            BubbleSort(arr, size);
            IsMember(arr, size, arr[3]);
            IsMember(arr, size, 600);
            IsPrime(arr, size);
        }
        else
            verify = true;
    }
    while(!verify);
}

void DisplayArr(int arr[], int size)
{
    cout << "\nThe generated array is: ";
    for(int i=0; i<size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void TableOfSquares(int arr[], int size){}
void PowerFunction(int val, int pow){}
long long int SumOfSquares(int cap){}
void MinMaxNum(int arr[], int size){}
void BubbleSort(int* arr, int size){}
bool IsMember(int arr[], int size, int val){}
void IsPrime(int arr[], int size){}
