#include "subsystems/ArmSubsystem.h"

ArmSubsystem::ArmSubsystem() :
    motor   {ArmConstants::motorId, rev::CANSparkMax::MotorType::kBrushless},
    encoder {ArmConstants::encoderId[0], ArmConstants::encoderId[1]} {
        encoder.SetDistancePerPulse(ArmConstants::anglePerPulse);
        motor.SetInverted(true);
}

void ArmSubsystem::Periodic() {}

void ArmSubsystem::RaiseArm(double speed) {
    motor.Set(speed);
}

void ArmSubsystem::ResetEncoder() {
    encoder.Reset();
}

double ArmSubsystem::GetEncoderDistance() {
    return encoder.GetDistance();
}

frc::Encoder& ArmSubsystem::GetEncoder() {
    return encoder;
}