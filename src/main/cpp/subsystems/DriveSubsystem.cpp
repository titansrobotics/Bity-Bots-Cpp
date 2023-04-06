#include "subsystems/DriveSubsystem.h"

DriveSubsystem::DriveSubsystem() : 
    leftDriveMotors   {MotorConstants::leftDriveId},
    rightDriveMotors  {MotorConstants::rightDriveId},
    leftDriveEncoder  {EncoderConstants::leftDriveId[0], EncoderConstants::leftDriveId[1]},
    rightDriveEncoder {EncoderConstants::rightDriveId[0], EncoderConstants::rightDriveId[1]} {

        rightDriveMotors.SetInverted(true);

        leftDriveEncoder.SetDistancePerPulse(EncoderConstants::driveDistancePerPulse);
        rightDriveEncoder.SetDistancePerPulse(EncoderConstants::driveDistancePerPulse);
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