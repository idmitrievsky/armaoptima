//
//  multidim.h
//  armaoptima
//
//  Created by Ivan Dmitrievsky on 28/03/14.
//  Copyright (c) 2014 Ivan Dmitrievsky. All rights reserved.
//

#ifndef __armaoptima__multidim__
#define __armaoptima__multidim__

#define  ARMA_DONT_USE_WRAPPER
#include "armadillo"

double obj(double x, double y, arma::vec const *_coeffs = 0);

#endif /* defined(__armaoptima__multidim__) */
