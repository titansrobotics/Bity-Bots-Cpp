#include "subsystems/ArmSubsystem.h"

ArmSubsystem::ArmSubsystem() :
    armMotor   {MotorConstants::armId, rev::CANSparkMax::MotorType::kBrushless},
    armEncoder {EncoderConstants::armId[0], EncoderConstants::armId[1]} {
        armEncoder.SetDistancePerPulse(EncoderConstants::armAnglePerPulse);
}

void ArmSubsystem::Periodic() {}

void ArmSubsystem::RaiseArm(double speed) {
    armMotor.Set(speed);
}

void ArmSubsystem::ResetEncoder() {
    armEncoder.Reset();
}

double ArmSubsystem::GetEncoderDistance() {
    return armEncoder.GetDistance();
}

frc::Encoder& ArmSubsystem::GetEncoder() {
    return armEncoder;
}