#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    ifstream fd;
    fd.open("src/data.txt");

    string line;

    while(getline(fd,line))
    {
        cout << line << endl;
    }

    return 0;
}