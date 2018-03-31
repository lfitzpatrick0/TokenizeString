#include <iostream>
#include <string>
#include <fstream>
using namespace std;

string getLast(string a)
{
    size_t i = 0;
    string token;
    while((i = a.rfind(" ")) != string::npos)
    {
        token = a.substr(i,string::npos);
        a.erase(0,i+1);
    }
    return a;
}

string trim(const string& str)
{
    size_t first = str.find_first_not_of(' ');
    if (string::npos == first)
    {
        return str;
    }
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}

int main()
{
    ifstream fd;
    fd.open("src/data.txt");

    string s;
    string delimiter = " ";
    string last, token;

    while(getline(fd,s))
    {
        last = getLast(s);
        size_t index = 0;
        while ((index = s.find(delimiter)) != string::npos) {
            token = s.substr(0, index + 1);
            token = trim(token);
            cout << token << endl;
            s.erase(0, index + delimiter.length());
        }
        cout << last << endl;
    }

    return 0;
}