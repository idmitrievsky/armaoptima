//
//  multidim.cpp
//  armaoptima
//
//  Created by Ivan Dmitrievsky on 28/03/14.
//  Copyright (c) 2014 Ivan Dmitrievsky. All rights reserved.
//

#include "util.h"
#include "multidim.h"

double obj(double x, double y, arma::vec const *_coeffs)
{
    static bool obj_inited = false;
    static arma::vec coeffs(5, arma::fill::zeros);
    if (_coeffs)
    {
        ASSERT(_coeffs->n_elem == 5, "Vector of objective function coefficients must be of size 5.");
        coeffs = *_coeffs;
        obj_inited = true;
    }
    ASSERT(obj_inited, "Objective function wasn't inited.");
    
    arma::vec args = {x * x, x * y, y * y, x, y};
    return arma::dot(coeffs, args);
}