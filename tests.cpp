//
//  tests.cpp
//  armaoptima
//
//  Created by Ivan Dmitrievsky on 04/04/14.
//  Copyright (c) 2014 Ivan Dmitrievsky. All rights reserved.
//

#include "tests.h"

extern bool obj_inited;
extern double min_upper_bound, max_lower_bound;

void log_convergence_speed(vec_seq &point_sequence, arma::vec &min_point, double precision)
{
    ASSERT(obj_inited, "Objective function wasn't inited.");
    ASSERT(min_point.n_elem == 2, "Point must be from E2");
    
    double _a_ = 2 * (1 - precision) / min_upper_bound;
    double max_speed = 1 - precision * _a_ * (max_lower_bound + min_upper_bound) * max_lower_bound / min_upper_bound;
    arma::vec speed_vals((arma::uword)(point_sequence.size() - 1));
    
    double proportion = std::sqrt(2 / max_lower_bound) * std::sqrt(obj_val(point_sequence[0]) - obj_val(min_point));
    
    for (int k = 1; k < point_sequence.size(); ++k)
        speed_vals(k - 1) = std::pow(arma::norm(point_sequence[k] - min_point) / proportion, 2.0 / k);
    
    double min_speed = arma::max(speed_vals);
    LOG(min_speed);
    LOG(max_speed);
}