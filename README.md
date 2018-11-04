

## PID Control

---
The aim of this project is learning how to use PID controller to control a vehicle.

### Algorithm of PID
d_error is the differential of error, i_error is the integral of error, and p_error is the the current error.

therefore,

    d_error = cte - prev_cte;
    prev_cte = cte;
    i_error += cte;
    p_error = cte;
    sterr_value = -Kp*p_error - Ki * i_error - Kd * d_error
    
### Effect of each term
P term: A greater proportional gain results in an unstable system. In contrast, a small gain results in a small control action. 

I term: Ki only results in overshot in this peoject. It accumulates the instantaneous error over time. It makes the car drive to outside of the road very fast.

D term: D term damps the effect of P term. It reduces the distance to the middle of the lane.

### Result
I tried (1.0, 0.0, 0.0), (0.0, 1.0, 0.0) and (0.0, 0.0, 1.0) to observe the specific influence of every term for the control. 
Then I tried to combine P and D term. For (1.0, 0.0, 1.0) the system is unstable, and moves left or right too much. Therefore I tried to reduce the parameter Kp. 
Then I found that around (0.5, 0.0, 2.0) there is only overshot in some part of the road with large curve. So I tried to tune Kp an Kd in small amount. Finally with (0.55, 0.0, 2.4) the car can keep in the track surface.  
