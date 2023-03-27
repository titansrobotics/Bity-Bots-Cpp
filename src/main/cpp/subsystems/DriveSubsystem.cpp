#include "subsystems/DriveSubsystem.h"

DriveSubsystem::DriveSubsystem()
    : leftMotors{MotorConstants::leftDriveId},
      rightMotors{MotorConstants::rightDriveId},
      leftEncoder{EncoderConstants::leftDriveId[0], EncoderConstants::leftDriveId[1]},
      rightEncoder{EncoderConstants::rightDriveId[0], EncoderConstants::rightDriveId[1]} {

    rightMotors.SetInverted(true);

    leftEncoder.SetDistancePerPulse(EncoderConstants::distancePerPulse);
    rightEncoder.SetDistancePerPulse(EncoderConstants::distancePerPulse);
}

void DriveSubsystem::Periodic() {}

void DriveSubsystem::ArcadeDrive(double fwd, double rot){

}