#ifndef CLAW_SUBSYSTEMS_H
#define CLAW_SUBSYSTEMS_H

#include <rev/CANSparkMax.h>
#include <frc2/command/SubsystemBase.h>

#include "Constants.h"

class ClawSubsystem : public frc2::SubsystemBase {
    public:

    ClawSubsystem();

    void Periodic() override;

    void MoveClaw(double speed);

    
    private:

    rev::CANSparkMax leftMotor;
    rev::CANSparkMax rightMotor;
};

#endif