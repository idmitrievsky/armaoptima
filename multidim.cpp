//
//  multidim.cpp
//  armaoptima
//
//  Created by Ivan Dmitrievsky on 28/03/14.
//  Copyright (c) 2014 Ivan Dmitrievsky. All rights reserved.
//

#include "util.h"
#include "multidim.h"

static arma::vec obj_coeffs(5, arma::fill::zeros);
static arma::mat obj_grad_coeffs(2, 3, arma::fill::zeros);
static bool obj_inited = false;

void init_obj(arma::vec const &_obj_coeffs)
{
    if (!obj_inited)
    {
        ASSERT(_obj_coeffs.n_elem == 5, "Vector of objective function coefficients must be of size 5.");
        obj_coeffs = _obj_coeffs;
        obj_grad_coeffs.row(0) = arma::rowvec({2 * obj_coeffs(0), obj_coeffs(1), obj_coeffs(3)});
        obj_grad_coeffs.row(1) = arma::rowvec({obj_coeffs(1), 2 * obj_coeffs(2), obj_coeffs(4)});
        obj_inited = true;
    }
}

double obj_val(arma::vec arg)
{
    ASSERT(obj_inited, "Objective function wasn't inited.");
    ASSERT(arg.n_elem == 2, "Point must be from E2");
    double x = arg(0), y = arg(1);
    
    arma::vec args = {x * x, x * y, y * y, x, y};
    return arma::dot(obj_coeffs, args);
}

double obj_val(double x, double y)
{
    return obj_val(arma::vec({x, y}));
}

arma::vec obj_grad_val(arma::vec arg)
{
    ASSERT(obj_inited, "Objective function wasn't inited.");
    ASSERT(arg.n_elem == 2, "Point must be from E2");
    double x = arg(0), y = arg(1);
    
    arma::vec args = {x, y, 1};
    
    return obj_grad_coeffs * args;
}

arma::vec obj_grad_val(double x, double y)
{
    return obj_grad_val(arma::vec({x, y}));
}