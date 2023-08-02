#ifndef CONSTANTS_H
#define CONSTANTS_H

#define M_PI 3.14159265358979323846

namespace DriveConstants {

    constexpr int kLeftMotorId  {1};
    constexpr int kRightMotorId {3};

    constexpr int kLeftEncoderId[2]  {0, 1};
    constexpr int kRightEncoderId[2] {2, 3};

<<<<<<< HEAD
    constexpr double kCountsPerRevolution {2048};
    constexpr double kWheelDiameter       {6};
    constexpr double kDistancePerPulse    {kWheelDiameter*std::numbers::pi/kCountsPerRevolution};
    //Assuming the encoder is mounted directly on the wheel shaft
=======
constexpr double countsPerRevolution {2048};
constexpr double wheelDiameter       {6};
constexpr double distancePerPulse    {wheelDiameter*M_PI/countsPerRevolution};
//Assuming Encoder is on the shaft
>>>>>>> 6ed662358d71625d33495ffb93cd5a4fd67d4be0

}


namespace ElevatorConstants {

    constexpr int kMotorId {8};

}


namespace ArmConstants {

    constexpr int kMotorId {9};

    constexpr int kEncoderId[2] {4, 5};

<<<<<<< HEAD
    constexpr double kCountsPerRevolution {1};
    constexpr double kAnglePerPulse       {2*std::numbers::pi/kCountsPerRevolution};
=======
constexpr double countsPerRevolution {1};
constexpr double anglePerPulse       {2*M_PI/countsPerRevolution};
>>>>>>> 6ed662358d71625d33495ffb93cd5a4fd67d4be0

}


namespace ClawConstants {

    constexpr int kLeftMotorId  {7};
    constexpr int kRightMotorId {5};

}


namespace SpeedConstants {

<<<<<<< HEAD
    constexpr int kDriveForwardPercentage  {0.6};
    constexpr int kDriveRotationPercentage {0.3};

    constexpr int kArmPercentage {0.5};

    constexpr int kElevatorPercentage {0.3};

    constexpr int kClawPercentage {0.3};
=======
constexpr double driveForwardPercentage  {0.6};
constexpr double driveRotationPercentage {0.3};

constexpr double armPercentage {0.5};

constexpr double elevatorPercentage {0.3};

constexpr double clawPercentage {0.3};
>>>>>>> 6ed662358d71625d33495ffb93cd5a4fd67d4be0

}


namespace OIConstants {
    
    constexpr int kDriverJoystickId    {0}; //console controller
    constexpr int kDriveForwardAxisId  {1};
    constexpr int kDriveRotationAxisId {2};

    constexpr int kArmJoystickId   {1}; //flight stick
    constexpr int kArmAxisId       {1};
    constexpr int kElevatorRaiseId {5};
    constexpr int kElevatorLowerId {3};
    constexpr int kClawGrabId      {1};
    constexpr int kClawEjectId     {2};

}


#endif