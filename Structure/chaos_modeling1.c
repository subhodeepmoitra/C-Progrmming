#include<stdio.h>
#include<math.h>

#define G 9.81

typedef struct{
    double angle;
    double angular_velocity;
    double mass;
    double length;
} PendulumArm;

typedef struct{
    PendulumArm arm1;
    PendulumArm arm2;
    double time_step;
    double time;
} DoublePendulum;

DoublePendulum simulate_step(DoublePendulum current){
    double a1 = current.arm1.angle;
    double a2 = current.arm2.angle;
    double av1 = current.arm1.angular_velocity;
    double av2 = current.arm2.angular_velocity;
    double m1 = current.arm1.mass;
    double m2 = current.arm2.mass;
    double l1 = current.arm1.length;
    double l2 = current.arm2.length;
    double dt = current.time_step;

    double num1 = -G*(2*m1+m2)*sin(a1)-m2*G*sin(a1-2*a2)-2*sin(a1-a2)*m2*(av2*av2*l2+av1*av1*l1*cos(a1-a2));
    double den1 = l1*(2*m1+m2-m2*cos(2*a1-2*a2));
    double a_accel1 = num1/den1;

    double num2 = 2*sin(a1-a2)*(av1*av1*l1*(m1+m2)+G*(m1+m2)*cos(a1)+av2*av2*l2*m2*cos(a1-a2));
    double den2 = l2*(2*m1+m2-m2*cos(2*a1-2*a2));
    double a_accel2 = num2/den2;

    //Now updating the angular velocity and angle using Euler's method
    DoublePendulum next = current;
    next.arm1.angular_velocity += a_accel1*dt;
    next.arm2.angular_velocity += a_accel2*dt;
    next.arm1.angle += next.arm1.angular_velocity*dt;
    next.arm2.angle += next.arm2.angular_velocity*dt;
    next.time += dt;

    return next;
}

int main(){
    DoublePendulum pendulum;

    pendulum.arm1.mass=1.0;
    pendulum.arm1.length=1.0;
    pendulum.arm1.angle=1.57;
    pendulum.arm1.angular_velocity=0.0;

    pendulum.arm2.mass=1.0;
    pendulum.arm2.length=1.0;
    pendulum.arm2.angle=1.57;
    pendulum.arm2.angular_velocity=0.0;

    pendulum.time_step=0.001;
    pendulum.time=0.0;

    printf("Time | Arm1 angle (rad.) | Arm2 angle (rad.) \n");
    for (int i = 0; i < 5000; i++)
    {
        pendulum=simulate_step(pendulum);
        if (i%100==0)
        {
            printf("%f | %f | %f \n", pendulum.time, pendulum.arm1.angle, pendulum.arm2.angle);
        }
        
    }
    return 0;
}