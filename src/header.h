#include <iostream>		//for i/o.
#include <string>		//for string library.
#include <cctype>		//for isdigit(), isalnum(), etc.
using namespace std;

bool isValid(string &str)
{
    bool valid = true;
    if(isdigit(str[0]))
        valid = false;
    if(str.empty())
        valid = false;
    if(valid)
    {
        for(int i = 0; i < str.length(); i++)
        {
            while(str[i] == '_')
                i++;
            while(isalnum(str[i]))
                i++;
            if(isspace(str[i]) || (ispunct(str[i]) && str[i] != '_'))
                valid = false;
            else if(str[i] == '_')
                i++;
        }
    }
    return valid;
}