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
    arma::vec coeffs = {1, 1, 1, 1, 1};
    LOG(obj(2, 2, &coeffs));
    
    return 0;
}