#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
  PID::Kp = Kp;
  PID::Ki = Ki;
  PID::Kd = Kd;

  p_error = 0;
  d_error = 0;
  i_error = 0;

  prev_cte = 0;
}

void PID::UpdateError(double cte) {
  d_error = cte - prev_cte;
  prev_cte = cte;
  i_error += cte;
  p_error = cte;
  
}

double PID::TotalError() {
  double error = -Kp*p_error-Ki*i_error-Kd*d_error;
  return error > 1.0 ? 1.0 : (error < -1.0 ? -1.0 : error);
}

