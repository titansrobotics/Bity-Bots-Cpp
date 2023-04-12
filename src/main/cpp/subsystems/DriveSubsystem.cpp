#include "subsystems/DriveSubsystem.h"

DriveSubsystem::DriveSubsystem() : 
    leftMotors   {DriveConstants::leftMotorId},
    rightMotors  {DriveConstants::rightMotorId},
    leftEncoder  {DriveConstants::leftEncoderId[0], DriveConstants::leftEncoderId[1]},
    rightEncoder {DriveConstants::rightEncoderId[0], DriveConstants::rightEncoderId[1]} {

        rightMotors.SetInverted(true);

        leftEncoder.SetDistancePerPulse(DriveConstants::distancePerPulse);
        rightEncoder.SetDistancePerPulse(DriveConstants::distancePerPulse);
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