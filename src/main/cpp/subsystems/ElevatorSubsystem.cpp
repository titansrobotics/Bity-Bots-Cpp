#include "subsystems/ElevatorSubsystem.h"

ElevatorSubsystem::ElevatorSubsystem() : 
    elevatorMotor{MotorConstants::elevatorId, rev::CANSparkMax::MotorType::kBrushless} {}

void ElevatorSubsystem::Periodic() {}

void ElevatorSubsystem::LiftElevator(double speed) {
    elevatorMotor.Set(speed);
}