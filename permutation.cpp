#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <deque>
#include <queue>

typedef std::vector<int>  Sequence;

void permutate( const Sequence& sequence,
                Sequence& permutation )
{
    if ( permutation.size() == sequence.size() )
    {
        for (int i = 0; i < permutation.size(); i++ )
        {
            std::cout << sequence[ permutation[i] ] << '|';
        }
        
        std::cout << std::endl;
        return;
    }
    
    for (int i = 0; i < sequence.size(); i++ )
    {
        if ( std::find( permutation.begin(), permutation.end(), i ) == permutation.end() )
        {
            permutation.push_back( i );
            permutate( sequence, permutation );
            permutation.pop_back();
        }
    }
}

int main()
{
    Sequence sequence;
    
    sequence.push_back( 1 );
    sequence.push_back( 2 );
    sequence.push_back( 3 );
    sequence.push_back( 4 );
    
    Sequence permutation;
    permutate( sequence, permutation );
}


//______________________


#include <chrono>
#include <thread>
#include <iostream>
#include <vector>

using Sequence = std::vector<int>;

void permutate_proc( const Sequence& seq,
                     Sequence& permutation )
{
    if ( permutation.size() == seq.size() )
    {
        std::copy( permutation.begin(), permutation.end(), std::ostream_iterator<int>( std::cout, "|") );
        std::cout << std::endl;
    }

    for( auto value: seq )
    {
        if ( std::find( permutation.begin(), permutation.end(), value) == permutation.end() )
        {
            permutation.push_back( value );
            permutate_proc( seq, permutation );
            permutation.pop_back();
        }
    }
}


int main()
{
    auto sequence    = Sequence{};
    auto permutation = Sequence{};
 
    sequence.push_back(1);
    sequence.push_back(2);
    sequence.push_back(3);
    sequence.push_back(4);
    
    permutate_proc( sequence, permutation );
    
}