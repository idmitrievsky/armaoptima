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

double gss(std::function<double (double)> obj, double segment_begin, double segment_end, double precision = DEFAULT_PRECISION);

#endif /* defined(__armaoptima__onedim__) */
