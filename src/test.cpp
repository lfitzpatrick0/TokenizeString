#include <iostream>
#include <string>
#include <fstream>
using namespace std;

string getLast(const string& b)
{
    string a = b;
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

void checkAssignment(const string& t)
{
    string str = t;
    string first, last, spec;
    size_t index;

    index = str.find("=");

    if(index != string::npos)
    {
        first = str.substr(0, index);
        last  = str.substr(index + 1);
        spec = str.back();

        cout << first << "\t\t\tIDENTIFIER" << endl;
        cout << last.substr(0, last.length()-1) << "\t\t\tNUMBER" << endl;
        cout << spec << "\t\t\tSPECIAL CHARACTER" << endl;
    }
    else
    {
        cout << trim(str.substr(0, str.length()-1));
        if(str.length() < 9)
            cout << "\t\t\tIDENTIFIER" << endl;
        else
            cout << "\t\tIDENTIFIER" << endl;
        if(str.back() == ';' || str.back() == ',')
        {
            cout << str.back() << "\t\t\tSPECIAL CHARACTER" << endl;
        }
    }
}

void checkToken(const string& t)
{
    if(t == "int" || t == "float")
        cout << t << "\t\t\tRESERVED WORD" << endl;
    else if(t.back() == ',' || t.back() == ';')
    {
        checkAssignment(t);
    }
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
            checkToken(token);
            s.erase(0, index + delimiter.length());
        }
        checkToken(last);
    }

    return 0;
}