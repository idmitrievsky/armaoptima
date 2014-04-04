//
//  util.h
//  armaoptima
//
//  Created by Ivan Dmitrievsky on 28/03/14.
//  Copyright (c) 2014 Ivan Dmitrievsky. All rights reserved.
//

#ifndef armaoptima_util_h
#define armaoptima_util_h

#include <iostream>
#include <string>
#include <cmath>

#ifndef NDEBUG
    #define ASSERT(condition, message) \
        do { \
            if (! (condition)) { \
                std::cerr << "Assertion `" #condition "` failed in " << __FILE__ \
                << " line " << __LINE__ << ": " << message << std::endl; \
                std::exit(EXIT_FAILURE); \
            } \
    } while (false)

    #define LOG(message) \
        do { \
            auto val = message; \
            std::cout << #message << " =" << std::endl << val << std::endl; \
        } while (false)
#else
    #define ASSERT(condition, message) do { } while (false)
    #define LOG(message) do { } while (false)
#endif

#define ROOT std::string("/Users/ivan/.supp/code/armaoptima/armaoptima/")
#define TRUE_ZEROS

inline bool almost_equal(double a, double b, double precision)
{
    if (std::isnan(a) || std::isnan(b))
        return false;
    
    if (std::fabs(a - b) < precision)
        return true;
    
    return false;
}

inline bool almost_zero(double val, double precision)
{
    return almost_equal(val, 0, precision);
}

inline short int sign(double val, double precision)
{
    if (almost_equal(val, 0, precision))
        return 0;
    
    return std::signbit(val) ? -1 : 1;
}

#endif