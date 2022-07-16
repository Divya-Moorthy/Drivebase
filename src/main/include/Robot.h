// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once
//Only runs once
//basically an init function
#include <frc/TimedRobot.h>
#include <rev/CANSparkMax.h>
#include <frc/Joystick.h>
#include <iostream>
#include <cmath>
#include <frc/smartdashboard/SmartDashboard.h>
//#include <units.h>
//#include <units/voltage.h>

//class robot, established in robot.cpp
class Robot : public frc::TimedRobot {
 public:
  
  //all functions also in Robot.cpp
  void RobotInit() override;
  void RobotPeriodic() override;

  void AutonomousInit() override;
  void AutonomousPeriodic() override;

  void TeleopInit() override;
  void TeleopPeriodic() override;

  void DisabledInit() override;
  void DisabledPeriodic() override;

  void TestInit() override;
  void TestPeriodic() override;
  
  int rightLeadMotorID = 9;
  int leftLeadMotorID = 15;

  float deadzone;
  double leftStick;
  double rightStick;
  int ySign, xSign;
  double prcX, prcY;
  double yMovement, xMovement;

  int counter;
  
//motor id's 
//you can change them

  double turnSensitivity;

  
  
  //Joysticks 
  frc::Joystick * joystick = new frc::Joystick(0); // assign to port 0
//port is left or right joystick



//library rev, init function/class CANSparkMax, rightLeadMotor is a variable storing the class CANSparkMax

  rev::CANSparkMax *rightLeadMotor = new rev::CANSparkMax(rightLeadMotorID, rev::CANSparkMax::CANSparkMaxLowLevel::MotorType::kBrushless);
  rev::CANSparkMax *leftLeadMotor = new rev::CANSparkMax(leftLeadMotorID, rev::CANSparkMax::CANSparkMaxLowLevel::MotorType::kBrushless);
 };