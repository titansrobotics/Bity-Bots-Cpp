#include "subsystems/DriveSubsystem.h"

DriveSubsystem::DriveSubsystem() : 
    leftMotors{MotorConstants::leftDriveId},
    rightMotors{MotorConstants::rightDriveId},
    leftEncoder{EncoderConstants::leftDriveId[0], EncoderConstants::leftDriveId[1]},
    rightEncoder{EncoderConstants::rightDriveId[0], EncoderConstants::rightDriveId[1]} {

        rightMotors.SetInverted(true);

        leftEncoder.SetDistancePerPulse(EncoderConstants::distancePerPulse);
        rightEncoder.SetDistancePerPulse(EncoderConstants::distancePerPulse);
}

void DriveSubsystem::Periodic() {}

void DriveSubsystem::ArcadeDrive(double fwd, double rot){
    leftMotors.Set(ctre::phoenix::motorcontrol::VictorSPXControlMode::PercentOutput, fwd + rot);
    rightMotors.Set(ctre::phoenix::motorcontrol::VictorSPXControlMode::PercentOutput, fwd - rot);
}

void DriveSubsystem::ResetEncoders() {
    leftEncoder.Reset();
    rightEncoder.Reset();
}

double DriveSubsystem::GetAverageEncoderDistance() {
    return (leftEncoder.GetDistance() + rightEncoder.GetDistance()) / 2.0;
}

frc::Encoder& DriveSubsystem::GetLeftEncoder() {
    return leftEncoder;
}

frc::Encoder& DriveSubsystem::GetRightEncoder() {
    return rightEncoder;
}

// void DriveSubsystem::SetMaxOutput(double maxOutput) {}