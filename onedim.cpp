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
    
    double segment = segment_end - segment_begin;
    double segment_prop_part = proportion * segment, step_from_bound = segment - segment_prop_part;
    
    double left_bound  = segment_begin, right_bound = segment_end;
    double left_probe  = left_bound + step_from_bound;
    double right_probe = right_bound - step_from_bound;
    double left_mean   = obj(left_probe);
    double right_mean  = obj(right_probe);
    unsigned _calls = 2;
    
    for (;;)
    {
        if (segment_prop_part < precision)
            break;
        
        segment = segment_prop_part;
        segment_prop_part = step_from_bound;
        step_from_bound = segment - segment_prop_part;
        if (left_mean < right_mean)
        {
            right_bound = right_probe;
            right_probe = left_probe;
            right_mean  = left_mean;
            left_probe  = left_bound + step_from_bound;
            left_mean   = obj(left_probe);
        }
        else
        {
            left_bound  = left_probe;
            left_probe  = right_probe;
            left_mean   = right_mean;
            right_probe = right_bound - step_from_bound;
            right_mean  = obj(right_probe);
        }
        _calls += 1;
    }
    if (calls) *calls = _calls;
    
    return left_bound + segment / 2;
}

double gss(one_dim_fun obj, double segment_begin, double segment_end, double precision, unsigned *calls)
{
    double proportion = (std::sqrt(5) - 1) / 2;
    return general_shrink(obj, segment_begin, segment_end, precision, proportion, calls);
}

double fib(one_dim_fun obj, double segment_begin, double segment_end, double precision, unsigned *calls)
{
    auto fibs = fib([=](unsigned F){ return (segment_end - segment_begin) / F <= precision; });
    double proportion = (double)fibs[0] / fibs[1];
    return general_shrink(obj, segment_begin, segment_end, precision, proportion, calls);
}