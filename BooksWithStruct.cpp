#include <iostream>
#include <string>

using namespace std;

struct auth 
{
	string name;
	string surname;
};

struct book
{
	string title;
	auth author;
	short yearOfPub;
};

void fillbooksInfo(book [], int );
void printbooksInfo(book [], int);

int main()
{
	book books[3];
	fillbooksInfo(books, 3);
	printbooksInfo(books, 3);
}
void fillbooksInfo(book a[], int b)
{
	for (int i = 0; i < b; i++)
	{
		cout << "Book " << i + 1 << " : \n";
		cout << "Enter book title\n";
		getline(cin,a[i].title);
		cout << "Enter book author name\n";
		getline(cin, a[i].author.name);
		cout << "Enter book author surname\n";
		getline(cin , a[i].author.surname);
		cout << "Enter book year of publication\n";
		cin >> a[i].yearOfPub;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
}
void printbooksInfo(book a[], int b)
{
	for (int i = 0; i < b; i++)
	{
		cout << "Book " << i + 1 << " : \n";
		cout <<"        "<< "Title :                              " << a[i].title<<"\n";
		cout <<"        "<< "Name of the author :                 " << a[i].author.name << "\n";
		cout <<"        "<< "Surname of the author :              " << a[i].author.surname << "\n";
		cout <<"        "<< "Year when the book was published :   " << a[i].yearOfPub << "\n";
	}
}
