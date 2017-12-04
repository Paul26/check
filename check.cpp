#include <iostream>
#include <fstream>
#include <iomanip>  
#include <string>

using namespace std;

int main()  // (int argc, char* argv[])
{
	string inputFile;
	
	cout << "Please enter a file name to be parsed: " << endl;
	cin >> inputFile;

	ifstream in(inputFile);

	if (!in.good())
	{
		cerr << "Unable to open file " << inputFile << endl;
		exit(1);
	}

	//string line;

	//while (getline(in, line))
	//{
	//	cout << line << endl;
	//}

	for (int i = 0; i < 80; i++)
	{
		cout << '-';
	}

	cout << endl;

	cout.setf(ios::fixed);
	cout.precision(2);


	int amount;

	while (!in.eof())
	{
		string column1;
		getline(in, column1, ':');
		cout <<  left << setw(15) << column1;

		string column2;
		getline(in, column2, ':');
		cout << setw(15) << column2;

		string column3;
		getline(in, column3, ':');
		cout << setw(15) << column3;

		string column4;
		string::size_type sz;
		getline(cin, column4, ':');
		double amount = stod(column4, &sz);
		cout << setw(15) << amount << endl;
	}



	for (int i = 0; i < 80; i++)
	{
		cout << '-';
	}
	cout << endl;

	system("pause");
	return 0;
}