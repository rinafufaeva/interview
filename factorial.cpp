#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <list>

using namespace std;

template <int i>
struct Factorial {
    enum
    {
        Val = i * Factorial< i - 1>::Val
    };
    
    void print()
    {
        cout << i << "! = " << Val << "|";
        Factorial<i-1>().print();
    }
};

template <>
struct Factorial<0> {
    enum
    {
        Val = 1
    };
    
    void print()
    {
        cout << 0 << "! = " << Val << "|";
    }
};

int straight()
{
    auto value = int{3};
    auto tmp   = int{1};
    
    std::vector<int> printout;
    printout.reserve(value);
    
    for( auto i = 1; i <= value; i++ )
    {
        tmp *= i;
        printout.emplace_back( tmp );
    }
    
    auto it = printout.rbegin();
    
    
    std::for_each( it, printout.rend(), [](int& value)
                   {
                       std::cout << value << " ";
                   } );


    std::cout << std::endl;
    
    
    std::copy( printout.rbegin(), printout.rend(), std::ostream_iterator<int>( std::cout, "|") );
}

int main()
{
    Factorial<5> factorial5;
    factorial5.print();
    return 0;
}