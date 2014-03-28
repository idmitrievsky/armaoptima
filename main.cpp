//
//  main.cpp
//  armaoptima
//
//  Created by Ivan Dmitrievsky on 28/03/14.
//  Copyright (c) 2014 Ivan Dmitrievsky. All rights reserved.
//

#include <iostream>
#include "util.h"
#include "multidim.h"

int main(int argc, const char * argv[])
{
    arma::vec coeffs;
    coeffs.load(ROOT + "obj.mat", arma::arma_ascii);
    init_obj(coeffs);
    
    LOG(obj_val(2, 2));
    LOG(obj_grad_val(1/2.0, 3));
    
    return 0;
}