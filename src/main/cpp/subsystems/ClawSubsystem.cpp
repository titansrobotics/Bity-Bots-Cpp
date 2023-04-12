#include "subsystems/ClawSubsystem.h"

ClawSubsystem::ClawSubsystem() :
    leftMotor{ClawConstants::leftMotorId, rev::CANSparkMax::MotorType::kBrushless},
    rightMotor{ClawConstants::rightMotorId, rev::CANSparkMax::MotorType::kBrushless} {
        
        rightMotor.SetInverted(true);
}

void ClawSubsystem::Periodic() {}

void ClawSubsystem::MoveClaw(double speed) {
    leftMotor.Set(speed);
    rightMotor.Set(speed);
}