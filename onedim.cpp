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

double general_partition(one_dim_fun obj, double segment_begin, double segment_end, double precision, double proportion, unsigned *iters)
{
    ASSERT(segment_end > segment_begin, "Segment length must be positive.");
    
    double left_bound  = segment_begin, right_bound = segment_end;
    double left_probe  = left_bound + proportion * (right_bound - left_bound);
    double right_probe = left_bound + right_bound - left_probe;
    double left_mean   = obj(left_probe);
    double right_mean  = obj(right_probe);
    
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
        *iters += 1;
    }
    
    return left_probe;
}

double gss(one_dim_fun obj, double segment_begin, double segment_end, double precision, unsigned *iters)
{
    double proportion = (3 - std::sqrt(5)) / 2;
    return general_partition(obj, segment_begin, segment_end, precision, proportion, iters);
}

double fib(one_dim_fun obj, double segment_begin, double segment_end, double precision, unsigned *iters)
{
    auto fibs = fib([=](unsigned f){ return (segment_end - segment_begin) / f <= precision; });
    double proportion = 1 - (double)fibs[0] / fibs[1];
    return general_partition(obj, segment_begin, segment_end, precision, proportion, iters);
}