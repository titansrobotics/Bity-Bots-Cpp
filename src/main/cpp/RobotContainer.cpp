// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"

#include <frc2/command/Commands.h>

RobotContainer::RobotContainer() {
  ConfigureBindings();


  drive.SetDefaultCommand(frc2::cmd::Run(
    [this] {
        drive.ArcadeDrive(
        -driverController.GetRawAxis(OIConstants::driveForwardAxisId) * SpeedConstants::driveForwardPercentage,
        driverController.GetRawAxis(OIConstants::driveRotationAxisId) * SpeedConstants::driveRotationPercentage);
    },
    {&drive}));

  
  arm.SetDefaultCommand(frc2::cmd::Run(
    [this] {
        arm.RaiseArm(armController.GetRawAxis(OIConstants::armAxisId) * SpeedConstants::armPercentage);
    },
    {&arm}));
}

void RobotContainer::ConfigureBindings() {
    elevatorRaiseButton
    .OnTrue(frc2::cmd::RunOnce([this] { elevator.LiftElevator(SpeedConstants::elevatorPercentage); }, {}))
    .OnFalse(frc2::cmd::RunOnce([this] { elevator.LiftElevator(0); }, {}));

    elevatorLowerButton
    .OnTrue(frc2::cmd::RunOnce([this] { elevator.LiftElevator(-SpeedConstants::elevatorPercentage); }, {}))
    .OnFalse(frc2::cmd::RunOnce([this] { elevator.LiftElevator(0); }, {}));

    clawGrabButton
    .OnTrue(frc2::cmd::RunOnce([this] { claw.MoveClaw(SpeedConstants::clawPercentage); }, {}))
    .OnFalse(frc2::cmd::RunOnce([this] { claw.MoveClaw(0); }, {}));

    clawEjectButton
    .OnTrue(frc2::cmd::RunOnce([this] { claw.MoveClaw(-SpeedConstants::clawPercentage); }, {}))
    .OnFalse(frc2::cmd::RunOnce([this] { claw.MoveClaw(0); }, {}));
}

frc2::CommandPtr RobotContainer::GetAutonomousCommand() {
  return frc2::cmd::Print("No autonomous command configured");
}
