#include "subsystems/ClawSubsystem.h"

ClawSubsystem::ClawSubsystem() :
    leftClawMotor{MotorConstants::leftClawId, rev::CANSparkMax::MotorType::kBrushless},
    rightClawMotor{MotorConstants::rightClawId, rev::CANSparkMax::MotorType::kBrushless} {
        
        rightClawMotor.SetInverted(true);
}

void ClawSubsystem::Periodic() {}

void ClawSubsystem::MoveClaw(double speed) {
    leftClawMotor.Set(speed);
    rightClawMotor.Set(speed);
}