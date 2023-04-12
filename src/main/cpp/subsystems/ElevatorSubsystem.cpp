#include "subsystems/ElevatorSubsystem.h"

ElevatorSubsystem::ElevatorSubsystem() : 
    motors{ElevatorConstants::motorId, rev::CANSparkMax::MotorType::kBrushless} {}

void ElevatorSubsystem::Periodic() {}

void ElevatorSubsystem::LiftElevator(double speed) {
    motors.Set(speed);
}