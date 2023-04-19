// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#ifndef ROBOT_CONTAINER_H
#define ROBOT_CONTAINER_H

#include <frc/Joystick.h>
#include <frc2/command/button/JoystickButton.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <frc2/command/CommandPtr.h>

#include "Constants.h"
#include "commands/Autos.h"
#include "subsystems/ArmSubsystem.h"
#include "subsystems/ClawSubsystem.h"
#include "subsystems/DriveSubsystem.h"
#include "subsystems/ElevatorSubsystem.h"

class RobotContainer {
 public:
 RobotContainer();

 frc2::CommandPtr GetAutonomousCommand();

 private:

 frc::Joystick driverController {OIConstants::driverJoystickId};
 frc::Joystick armController    {OIConstants::armJoystickId};

 frc2::JoystickButton elevatorRaiseButton {&armController, OIConstants::elevatorRaiseId};
 frc2::JoystickButton elevatorLowerButton {&armController, OIConstants::elevatorLowerId};
 frc2::JoystickButton clawGrabButton      {&armController, OIConstants::clawGrabId};
 frc2::JoystickButton clawEjectButton     {&armController, OIConstants::clawEjectId};

 ArmSubsystem arm;
 ClawSubsystem claw;
 DriveSubsystem drive;
 ElevatorSubsystem elevator;

 //setup autos before adding auto selector
 //Use sendable chooser to get selected auto
 
 void ConfigureBindings();
};

#endif