#include <memory>
#include <map>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <math.h>
#include <stdlib.h>
#include <cmath>

std::vector<int64_t> prime_sieve( int64_t max_number )
{
    std::vector<int64_t> result;
    
    int64_t max_number_sqrt = static_cast<int64_t>( sqrt( max_number ) );
    std::vector<bool> compositions;
    compositions.resize( max_number + 1 );
    
    for (int64_t i = 2; i <= max_number_sqrt; i++)
    {
        if (!compositions[i])
        {
            result.push_back(i);
            for ( int64_t j = i * i; j <= max_number; j += i )
                compositions[j] = true;
        }
    }
    
    for (int64_t i = max_number_sqrt + 1; i <= max_number; i++ )
    {
        if (!compositions[i])
            result.push_back(i);
   }
    
    return result;
}