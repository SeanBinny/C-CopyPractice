#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

int main()
{
    ofstream outClientFile("client.txt" , ios::out);
    if (!outClientFile)
    {
        cerr << "File could not be opened";
        exit(EXIT_FAILURE);
    }
    cout << "Enter the account, name, and balance " << endl
    << "Enter end-of-file to end input.\n? ";

    int    account;
    string name;
    double balance;
    while (cin >> account >> name >> balance)
    {
        outClientFile << account << ' ' << name << ' ' << balance << endl;
        cout << "? ";
    }
    cout << "Hello world!" << endl;
    return 0;
}
