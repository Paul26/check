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
		exit(1);
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

	while (!in.eof())
	{
		string column1;  //****************************** refers to deposits and check numbers
		getline(in, column1, ':');
		cout <<  left << setw(15) << column1;

		string column2;  //******************************* refers to deposit date and check written date
		getline(in, column2, ':');
		cout << setw(15) << column2;

		string column3;  //****************************** refers to dash and recipient
		getline(in, column3, ':');
		cout << setw(15) << column3;

		string column4;  //****************************** refers to deposit amount and check amount
		string::size_type sz;
		getline(in, column4);
		double amount = stod(column4, &sz);
		cout << right << setw(8) << "$" << setw(10) << amount << endl;




		//string column4;
		//getline(in, column4);
		//column4 = stod(column4);  //************************************************** causes weird symbols
		//cout << right << setw(15) << setw(5) << "$" << column4 << endl;
	}


	for (int i = 0; i < 63; i++)
	{
		cout << '-';
	}
	cout << endl;
	cout << setw(53) << "Balance: $" << endl;

	system("pause");
	return 0;
}