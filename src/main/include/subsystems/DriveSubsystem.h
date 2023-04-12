#ifndef DRIVE_SUBSYSTEM_H
#define DRIVE_SUBSYSTEM_H

#include <frc/Encoder.h>
#include <ctre/phoenix/motorcontrol/can/VictorSPX.h>
#include <frc2/command/SubsystemBase.h>

#include "Constants.h"


class DriveSubsystem : public frc2::SubsystemBase {
    public:

    DriveSubsystem();

    void Periodic() override;

    void ArcadeDrive(double fwd, double rot);

    void ResetEncoders();

    double GetAverageEncoderDistance();

    frc::Encoder& GetLeftEncoder();
    frc::Encoder& GetRightEncoder();


    private:

    ctre::phoenix::motorcontrol::can::VictorSPX leftMotors;
    ctre::phoenix::motorcontrol::can::VictorSPX rightMotors;

    frc::Encoder leftEncoder;
    frc::Encoder rightEncoder;
};

#endif