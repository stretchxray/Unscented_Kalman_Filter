#include <iostream>
#include "tools.h"

using Eigen::VectorXd;
using Eigen::MatrixXd;
using std::vector;

Tools::Tools() {}

Tools::~Tools() {}

VectorXd Tools::CalculateRMSE(const vector<VectorXd> &estimations,
                              const vector<VectorXd> &ground_truth) {
    
    /**
     TODO:
     * Calculate the RMSE here.
     */
    
    // From Extended Kalman Filters Project
    
    VectorXd rmse(4);
    rmse << 0,0,0,0;
    
    //compare estimation & ground truth
    if(estimations.size() != ground_truth.size() || estimations.size() == 0){
        cout << "CalculateRMSE () - Error: Invalid estimation or ground_truth values" << endl;
        return rmse;
    }
    
    //squared residuals
    for(int i=0; i < estimations.size(); ++i){
        VectorXd residual = estimations[i] - ground_truth[i];
        residual = residual.array()*residual.array();
        rmse += residual;
    }
    
    rmse = rmse/estimations.size();
    rmse = rmse.array().sqrt();
    
    return rmse;
}
