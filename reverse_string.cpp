#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{
    char* str = strdup("lazy fox");
    
    unsigned int begin = 0;
    unsigned int end = strlen(str) - 1;
    
    char tmp = 0;
    while (begin < end)
    {
        tmp        = str[begin];
        str[begin] = str[end];
        str[end]   = tmp;
        begin++;
        end--;
    }
    
    delete str;
    return 0;
}