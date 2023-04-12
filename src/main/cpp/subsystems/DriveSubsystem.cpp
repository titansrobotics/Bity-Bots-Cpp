#include "subsystems/DriveSubsystem.h"

DriveSubsystem::DriveSubsystem() : 
    leftDriveMotors   {DriveConstants::leftMotorId},
    rightDriveMotors  {DriveConstants::rightMotorId},
    leftDriveEncoder  {DriveConstants::leftEncoderId[0], DriveConstants::leftEncoderId[1]},
    rightDriveEncoder {DriveConstants::rightEncoderId[0], DriveConstants::rightEncoderId[1]} {

        rightDriveMotors.SetInverted(true);

        leftDriveEncoder.SetDistancePerPulse(DriveConstants::distancePerPulse);
        rightDriveEncoder.SetDistancePerPulse(DriveConstants::distancePerPulse);
}

void DriveSubsystem::Periodic() {}

void DriveSubsystem::ArcadeDrive(double fwd, double rot){
    leftDriveMotors.Set(ctre::phoenix::motorcontrol::VictorSPXControlMode::PercentOutput, fwd + rot);
    rightDriveMotors.Set(ctre::phoenix::motorcontrol::VictorSPXControlMode::PercentOutput, fwd - rot);
}

void DriveSubsystem::ResetEncoders() {
    leftDriveEncoder.Reset();
    rightDriveEncoder.Reset();
}

double DriveSubsystem::GetAverageEncoderDistance() {
    return (leftDriveEncoder.GetDistance() + rightDriveEncoder.GetDistance()) / 2.0;
}

frc::Encoder& DriveSubsystem::GetLeftEncoder() {
    return leftDriveEncoder;
}

frc::Encoder& DriveSubsystem::GetRightEncoder() {
    return rightDriveEncoder;
}