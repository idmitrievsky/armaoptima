//
//  main.cpp
//  armaoptima
//
//  Created by Ivan Dmitrievsky on 28/03/14.
//  Copyright (c) 2014 Ivan Dmitrievsky. All rights reserved.
//

#include <cmath>
#include "util.h"
#include "onedim.h"

int main(int argc, const char * argv[])
{
    unsigned calls = 0;
    auto obj = [](double arg){ return std::sqrt(1 + arg * arg) + std::exp(-2*arg); };
    
    LOG(gss(obj, 0, 1, 1e-3, &calls));
    LOG(calls);
    calls = 0;
    LOG(fib(obj, 0, 1, 1e-3, &calls));
    LOG(calls);
    
    return 0;
}