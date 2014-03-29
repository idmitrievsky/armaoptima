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

static std::vector<unsigned> fib(int n)
{
    ASSERT(n > 0, "Number of fib nums must be positive.");
    
    std::vector<unsigned> fibs(n);
    fibs[0] = 0; fibs[1] = 1;
    int m = n - 2;
    
    while (m > 0)
    {
        fibs[n - m] = fibs[n - m - 1] + fibs[n - m - 2];
        m--;
    }
    
    return fibs;
}

double gss(std::function<double (double)> obj, double segment_begin, double segment_end, double precision)
{
    ASSERT(segment_end > segment_begin, "Segment length must be positive.");
    
    double proportion  = (3 - std::sqrt(5)) / 2;
    double left_bound  = segment_begin, right_bound = segment_end;
    double left_probe  = left_bound + proportion * (right_bound - left_bound);
    double right_probe = left_bound + right_bound - left_probe;
    double left_mean   = obj(left_probe);
    double right_mean  = obj(right_probe);
    int iterations = 0;
    
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
        iterations += 1;
    }
    
    return left_probe;
}