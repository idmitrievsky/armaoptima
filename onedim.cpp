//
//  onedim.cpp
//  armaoptima
//
//  Created by Ivan Dmitrievsky on 28/03/14.
//  Copyright (c) 2014 Ivan Dmitrievsky. All rights reserved.
//

#include <vector>
#include <cmath>
#include "onedim.h"

static std::vector<unsigned> fib(std::function<bool (unsigned)> predicate)
{
    std::vector<unsigned> fibs(2);
    fibs[0] = 0; fibs[1] = 1;
    
    while (!predicate(fibs.back()))
    {
        auto temp = fibs[0];
        fibs[0] = fibs[1];
        fibs[1] += temp;
    }
    
    return fibs;
}

double general_shrink(one_dim_fun obj, double segment_begin, double segment_end, double precision, double proportion, unsigned *calls)
{
    ASSERT(segment_end > segment_begin, "Segment length must be positive.");
    
    double left_bound  = segment_begin, right_bound = segment_end;
    double left_probe  = left_bound + proportion * (right_bound - left_bound);
    double right_probe = left_bound + right_bound - left_probe;
    double left_mean   = obj(left_probe);
    double right_mean  = obj(right_probe);
    unsigned _calls = 2;
    
    for (;;)
    {
        if (right_bound - left_bound < precision)
            break;
        
        if (left_mean < right_mean)
        {
            right_bound = right_probe;
            right_probe = left_probe;
            right_mean  = left_mean;
            left_probe  = left_bound + proportion * (right_bound - left_bound);
            left_mean   = obj(left_probe);
        }
        else
        {
            left_bound  = left_probe;
            left_probe  = right_probe;
            left_mean   = right_mean;
            right_probe = left_bound + right_bound - left_probe;
            right_mean  = obj(right_probe);
        }
        _calls += 1;
    }
    if (calls) *calls = _calls;
    
    return left_probe;
}

double gss(one_dim_fun obj, double segment_begin, double segment_end, double precision, unsigned *calls)
{
    double proportion = (3 - std::sqrt(5)) / 2;
    return general_shrink(obj, segment_begin, segment_end, precision, proportion, calls);
}

double fib(one_dim_fun obj, double segment_begin, double segment_end, double precision, unsigned *calls)
{
    double proportion = 1 - (double)fibs[0] / fibs[1];
    auto fibs = fib([=](unsigned F){ return (segment_end - segment_begin) / F <= precision; });
    return general_shrink(obj, segment_begin, segment_end, precision, proportion, calls);
}