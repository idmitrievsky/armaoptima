//
//  util.h
//  armaoptima
//
//  Created by Ivan Dmitrievsky on 28/03/14.
//  Copyright (c) 2014 Ivan Dmitrievsky. All rights reserved.
//

#ifndef armaoptima_util_h
#define armaoptima_util_h

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
            std::cout << #message << " = " << val << std::endl; \
        } while (false)
#else
    #define ASSERT(condition, message) do { } while (false)
    #define LOG(message) do { } while (false)
#endif

#endif