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
#include "util.h"

void init_obj(arma::vec const &obj_coeffs);

double obj_val(arma::vec arg);
double obj_val(double x, double y);

arma::vec obj_grad_val(arma::vec arg);
arma::vec obj_grad_val(double x, double y);

arma::vec grad_frac_step(double (*obj)(arma::vec), arma::vec (*obj_grad)(arma::vec),
                         arma::vec start, double lambda, double eps, double precision = DEFAULT_PRECISION);

arma::vec grad_descent(double (*obj)(arma::vec), arma::vec (*obj_grad)(arma::vec),
                       arma::vec start, double precision = DEFAULT_PRECISION);

#endif /* defined(__armaoptima__multidim__) */
