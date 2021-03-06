///////////////HEADERS////////////////////////////////

#include <iostream>
#include <string>
#include <limits>

///////////////NAMESPACES/////////////////////////////

using namespace std;

///////////////Function Declaration///////////////////

double askInputAndValidate();

double * arrayOfNumbers(int size);

void enterNumbers(double a[], int b);

void printNumbers(double a[], int b);

int * askSizeAndValidate(int * a);

void switchNumber(double * a, double * b);

char askSortOrder();

void bubbleSort(double arr[], int a, char b);

//////////////////////Body of the program/////////////////////

int main() 
{
	int sizeOfArray=*askSizeAndValidate(&sizeOfArray);//set the size of array
	double *arrOfNum = arrayOfNumbers(sizeOfArray);//creates a dynamic array
	enterNumbers(arrOfNum, sizeOfArray);//asks input for every element of the array 
	printNumbers(arrOfNum, sizeOfArray);
	char sort = askSortOrder();//ask if you want and how to sort the numbers 
	bubbleSort(arrOfNum, sizeOfArray, sort);//

	delete[]arrOfNum;
	return 0;
}

/////////////////FUNCTION DEFINITION///////////////////////

double askInputAndValidate()
{
	double a;
	string b;

	while (!(cin>>b)||b.find_first_not_of("0123456789.-") != string::npos)//checks if are typed other char than the ones in parenthesis
	// and when founds one gives error and cleans the input	
		{
			system("cls");
			cout << "Error not a number" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}	
	string::size_type st;
	a= stod(b, &st);//converts string to float number of type double

	return a;
}
double *arrayOfNumbers(int size)//set a dynamic memory for the array
{
	double*a = new double[size];
	return a;
}
void enterNumbers(double a[], int b) //ask to enter numbers for every element in the array
{
	for (int i = 0; i < b; i++)
	{
		cout << "Enter number " << i + 1 << ":";
		a[i] = askInputAndValidate();
	}
}
void printNumbers(double a[], int b) //prints every element of the array
{
	for (int i = 0; i < b; i++)
	{
		cout << "The number " << i + 1 << " you printed is : ";
		cout << a[i] << endl;
	}
}
int * askSizeAndValidate(int * a)//ask size of the array
{
	while (!(2 <= *a && *a <= 20))//executes again if numbers are not between 2 and 20
	{
		system("cls");
		cout << "How many numbers do you want to enter (in a range of 2 to 20):\n"
			<< "(Note is you enter a decimal number will count only numbers before decimal point)" << endl;
		*a = askInputAndValidate();
	}
	return a;
}
void switchNumber(double *a, double *b)//switches 2 numbers
{
	double temp = *a;
	*a = *b;
	*b = temp;
}
char askSortOrder()//asks if you want to sort the numbers and for sorting type (+ ascending , - descending)
{
	char a = '+', b;
	do
	{
		cout << "Do you want to sort the numbers Y/N or D(default)?(default sort is ascending)\n";
		cin >> b;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	} while (!(b == 'Y' || b == 'y') && !(b == 'n' || b == 'N')&&!(b=='D'||b=='d'));

	if (b == 'Y' || b == 'y')
	{
		do
		{
			cout << "How do you want to sort your numbers?('-' descending , '+' ascending)\n";
			cin >> a;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		} while (!(a == '+' || a == '-'));
		return a;
	}
	else if (b == 'n' || b == 'N')
	{
		return 0;
	}
	else if (b == 'd' || b == 'D')
	{
		return a;
	}
}
void bubbleSort(double arr[], int a, char b)
{
	for (int i = 0; i < a - 1; i++)
	{
		for (int j = 0; j < a - 1; j++)
		{
			if ((b == '-') && (arr[j] < arr[j + 1]))
				switchNumber(&arr[j], &arr[j + 1]);
			else if ((b == '+') && (arr[j]>arr[j + 1]))
				switchNumber(&arr[j], &arr[j + 1]);
		}
	}
	printNumbers(arr, a);
}
