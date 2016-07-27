#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <list>

using namespace std;

string getRun(const string& str)
{
    string::const_iterator strIt         = str.begin();

    string::const_iterator strItRunBegin = str.begin();
    string::const_iterator strItRunEnd   = str.begin() + 1;

    string::const_iterator strItRunTmp   = str.begin();
    
    long longestRun = 1;
    long currentRun = 0;
 
    while (true)
    {
        strIt++;
        if( *strIt != *strItRunTmp ||
            strIt == str.end() )
        {
            currentRun = strIt - strItRunTmp;
            if (currentRun > longestRun)
            {
                longestRun = currentRun;
                strItRunBegin = strItRunTmp;
                strItRunEnd   = strIt;
            }
            strItRunTmp   = strIt;
        }
        
        if (strIt == str.end())
            break;
    }
    
    return string( strItRunBegin, strItRunEnd );
}

int main()
{
    string str1 = getRun("a");
    string str2 = getRun("aab");
    string str3 = getRun("aa");
    string str4 = getRun("abbbbbc");
    string str5 = getRun("abbccccc");
    
    
    return 1;
}