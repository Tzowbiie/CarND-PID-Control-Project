#include "PID.h"

/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
  /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   */
  Kp = Kp_;
  Ki = Ki_;
  Kd = Kd_;
  
  //Errors = 0 at the beginning
  p_error = 0;
  i_error = 0;
  d_error = 0;

}

void PID::UpdateError(double cte) {
  /**
   * TODO: Update PID errors based on cte.
   */
  double pre_cte = p_error;

  p_error  = cte;
  i_error += cte;
  d_error  = cte - pre_cte;

}

double PID::TotalError() {
  /**
   * TODO: Calculate and return the total error
   */
  return 0.0;  // TODO: Add your total error calc here!
}
/**
 * Calculates the output value according to the PID control
 * @return the control value
 */
double PID::ControlOutput() {

  double value = -Kp*p_error - Ki*i_error - Kd*d_error;
  
  // steering must be in the [-1, 1] interval
  if (value > 1){
    return 1;
  }
  else if (value < -1){
    return -1;
  }
  
  return value;
}
