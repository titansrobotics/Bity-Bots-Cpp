#ifndef CONSTANTS_H
#define CONSTANTS_H

#define M_PI 3.14159265358979323846

namespace DriveConstants {

constexpr int leftMotorId  {1};
constexpr int rightMotorId {3};

constexpr int leftEncoderId[2]  {0, 1};
constexpr int rightEncoderId[2] {2, 3};

constexpr double countsPerRevolution {2048};
constexpr double wheelDiameter       {6};
constexpr double distancePerPulse    {wheelDiameter*M_PI/countsPerRevolution};
//Assuming Encoder is on the shaft

}


namespace ElevatorConstants {

constexpr int motorId {8};

}


namespace ArmConstants {

constexpr int motorId {9};

constexpr int encoderId[2] {4, 5};

constexpr double countsPerRevolution {1};
constexpr double anglePerPulse       {2*M_PI/countsPerRevolution};

}


namespace ClawConstants {

constexpr int leftMotorId  {7};
constexpr int rightMotorId {5};

}


namespace SpeedConstants {

constexpr double driveForwardPercentage  {0.6};
constexpr double driveRotationPercentage {0.3};

constexpr double armPercentage {0.5};

constexpr double elevatorPercentage {0.3};

constexpr double clawPercentage {0.3};

}


namespace OIConstants {

constexpr int driverJoystickId    {0};
constexpr int driveForwardAxisId  {1};
constexpr int driveRotationAxisId {2};

constexpr int armJoystickId   {1};
constexpr int armAxisId       {1};
constexpr int elevatorRaiseId {5};
constexpr int elevatorLowerId {3};
constexpr int clawGrabId      {1};
constexpr int clawEjectId     {2};

}

#endif