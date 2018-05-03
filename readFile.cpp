#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>
using namespace std;

void outputLine(int , const string&, double);

int main()
{
    ifstream inClientFile("client.txt", ios::in);

    if (!inClientFile)
    {
        cerr << "File could not be opened";
        exit(EXIT_FAILURE);
    }

    int account;
    string name;
    double balance;

    cout << left << setw(10) << "Account" << setw(13)
    << "Name" << "Balance" << endl << fixed << showpoint;

    while (inClientFile >> account >> name >> balance )
        outputLine(account, name, balance);
}

void outputLine(int account, const string &name, double balance)
{
    cout << left << setw(10) << account << setw(13) << name
    << setw(7) << setprecision(2) << right << balance << endl;
}
