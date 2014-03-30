//
//  onedim.h
//  armaoptima
//
//  Created by Ivan Dmitrievsky on 28/03/14.
//  Copyright (c) 2014 Ivan Dmitrievsky. All rights reserved.
//

#ifndef __armaoptima__onedim__
#define __armaoptima__onedim__

#include <functional>
#include "util.h"

typedef std::function<double (double)> one_dim_fun;

double general_shrink(one_dim_fun obj, double segment_begin, double segment_end, double precision, double proportion = DEFAULT_PRECISION,
                         unsigned *calls = 0);

double gss(one_dim_fun obj, double segment_begin, double segment_end, double precision = DEFAULT_PRECISION, unsigned *calls = 0);
double fib(one_dim_fun obj, double segment_begin, double segment_end, double precision = DEFAULT_PRECISION, unsigned *calls = 0);

#endif /* defined(__armaoptima__onedim__) */
