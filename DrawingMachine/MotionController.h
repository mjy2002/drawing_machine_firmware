#ifndef MOTION_H
#define MOTION_H

#include <AccelStepper.h>
#include <MultiStepper.h>

#include "Configuration.h"

class MotionController{
  private:
    float position_x_;
    float position_y_;
    float position_e_;

    bool relative_mode_;
    int8_t pen_state_;

    void moveDirect_(float x, float y, float e);

    MultiStepper *steppers_;
    AccelStepper *linear_stepper_;
    AccelStepper *rotary_stepper_;

    enum PenState{UP, DOWN};
  public:
    void init();
    void setPosition(float x, float y, float e);

    void move(float x, float y, float e);
    
    void home();
    
    void enable();
    void disable();

    void setPenState(PenState state);
    
    void relative();
    void absolute();

    float getStationaryX();
    float getStationaryY();
    float getStationaryE();
    float getX();
    float getY();
    float getE();
};

#endif MOTION_H