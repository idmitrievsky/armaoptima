//
//  main.cpp
//  armaoptima
//
//  Created by Ivan Dmitrievsky on 28/03/14.
//  Copyright (c) 2014 Ivan Dmitrievsky. All rights reserved.
//

#include "util.h"
#include "multidim.h"

int main(int argc, const char * argv[])
{
    arma::vec coeffs;
    coeffs.load(ROOT + "obj.mat", arma::arma_ascii);
    init_obj(coeffs);
    
    auto min_point = grad_descent(obj_val, obj_grad_val, arma::vec({20, -10}), 0.01);
    LOG(min_point);
    LOG(obj_val(min_point));
    
    return 0;
}