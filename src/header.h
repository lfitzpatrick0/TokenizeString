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

bool isValidNum(string &str)
{
    bool valid = true;
    int i = 0;
    int j = 0;
    while(str[i])
    {
        if(isdigit(str[i]))
            i++;
        if(ispunct(str[i]))
        {
            j++; 
            i++; 
        }
        if(j > 1)
            valid = false;
    }
    return valid;
}