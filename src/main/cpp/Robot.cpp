// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"


void Robot::RobotInit() {
  rightLeadMotor->RestoreFactoryDefaults();
  rightFollowMotor->RestoreFactoryDefaults();
  leftLeadMotor->RestoreFactoryDefaults(); 
  leftFollowMotor->RestoreFactoryDefaults();

  rightLeadMotor->SetInverted(false);
  rightFollowMotor->Follow(*rightLeadMotor, false);
  leftLeadMotor->SetInverted(true);
  leftFollowMotor->Follow(*leftLeadMotor, false);
}

void Robot::RobotPeriodic() {

}

void Robot::AutonomousInit() {}
void Robot::AutonomousPeriodic() {}

void Robot::TeleopInit() {}
void Robot::TeleopPeriodic() {
  rightLeadMotor->Set(l_Joystick->GetRawAxis(1)); // left stick y-axis
  leftLeadMotor->Set(l_Joystick->GetRawAxis(1));
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



