// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"


void Robot::RobotInit() {
  rightLeadMotor->RestoreFactoryDefaults();
  leftLeadMotor->RestoreFactoryDefaults(); 

  rightLeadMotor->SetInverted(false);
  leftLeadMotor->SetInverted(true);
}

void Robot::RobotPeriodic() {

}

void Robot::AutonomousInit() {}
void Robot::AutonomousPeriodic() {}

void Robot::TeleopInit() {}
void Robot::TeleopPeriodic() {
  double leftStick = l_Joystick->GetRawAxis(1);
  double rightStick = l_Joystick->GetRawAxis(4);
  // double yMovement = leftStick - rightStick;
  // double xMovement = leftStick + rightStick;

  double prcX, prcY;

  prcY = stickTrans(fabs(rightStick));
  prcX = stickTrans(fabs(rightStick)); // og: rightStick

  copysignf(prcY, rightStick);
  copysignf(prcX, leftStick);
  if (fabs(rightStick) <= deadzone) {
    prcY = 0;
  }
  if (fabs(leftStick) <= deadzone) {
    prcX = 0;
  }
    rightLeadMotor->Set(prcX - prcY);
    leftLeadMotor->Set(prcX + prcY);
  
    
// xSign * (1/(1 - deadzone) * (xMovement) - (deadzone/(1 - deadzone)))
  
}

void Robot::DisabledInit() {}
void Robot::DisabledPeriodic() {}

void Robot::TestInit() {}
void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() {
  return frc::StartRobot<Robot>();
}
#endif



