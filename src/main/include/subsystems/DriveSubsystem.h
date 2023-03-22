#ifndef DRIVE_SUBSYSTEM_H
#define DRIVE_SUBSYSTEM_H

#include <frc/drive/DifferentialDrive.h>
#include <ctre/phoenix/motorcontrol/can/VictorSPX.h>
#include <frc2/command/SubsystemBase.h>

#include "Constants.h"


class DriveSubystem : public frc2::SubsystemBase{
    public:

    DriveSubystem();

    void Periodic() override;

    void ArcadeDrive(double fwd, double rot);

    void ResetEncoders();

    double GetAverageEncoderDistance();

    frc::Encoder& GetLeftEncoder();
    frc::Encoder& GetRightEncoder();

    void SetMaxOutput(double maxOutput);
};

#endif