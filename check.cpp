#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

int main()  
{
	string inputFile;
	
	cout << "Please enter a file name to be parsed: " << endl;
	cin >> inputFile;

	ifstream in(inputFile);

	if (!in.good())
	{
		cerr << "Unable to open file \"inputFile\"" << endl;
		//exit(1);
	}

	//string line;
	//while (getline(in, line))
	//{
	//	cout << line << endl;
	//}

	for (int i = 0; i < 63; i++)
	{
		cout << '-';
	}

	cout << endl;

	cout.setf(ios::fixed);
	cout.precision(2);

	double balance = 0;

	while (!in.eof())
	{
		string column1;  //****************************** refers to deposits and check numbers
		getline(in, column1, ':');
		cout <<  left << setw(15) << column1;

		string column2;  //******************************* refers to deposit and check written dates
		getline(in, column2, ':');
		cout << setw(15) << column2;

		string column3;  //****************************** refers to dash and recipients
		getline(in, column3, ':');
		cout << setw(15) << column3;

		string column4;  //****************************** refers to deposit and check amount
		string::size_type sz;
		getline(in, column4);
		double amount = stod(column4, &sz);
		cout << right << setw(8) << "$" << setw(10) << amount << endl;


		if (column1 == "deposit")
		{
			balance += amount;
		}
		else
		{
			balance -= amount;
		}
	}


	for (int i = 0; i < 63; i++)
	{
		cout << '-';
	}
	cout << endl;
	cout << right << setw(52) << "Balance: " << "$" << setw(10) << balance << endl;


	system("pause");
	return 0;
}