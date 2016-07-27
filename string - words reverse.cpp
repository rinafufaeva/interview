#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <list>

using namespace std;

int main()
{
    std::string str("lazy  drunk fox");
    std::string::iterator itBegin = str.begin();
    std::string::iterator itEnd   = str.end();
    
    std::reverse(itBegin, itEnd);
    
    std::string::iterator it = str.begin();
    while (true)
    {
        if (it == str.end() ||
            *it == ' ')
        {
            std::reverse(itBegin, it);
            
            if (it == str.end())
                break;
            
            itBegin = it + 1;
        }
        it++;
    }
    return 0;
}