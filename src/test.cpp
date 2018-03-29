#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    ifstream handle;
    handle.open("src/data.txt");

    string line;

    while(getline(handle,line))
    {
        cout << line << endl;
    }

    return 0;
}