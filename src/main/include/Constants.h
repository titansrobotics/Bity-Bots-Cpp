#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <numbers>

namespace OIConstants {

constexpr int driverJoystickId {0};
constexpr int armJoystickId    {1};

}

namespace MotorConstants {

constexpr int leftDriveId  {1};
constexpr int rightDriveId {3};

constexpr int elevatorId {8};

constexpr int armId {9};

constexpr int leftClawId  {7};
constexpr int rightClawId {5};

}

namespace EncoderConstants {

constexpr int leftDriveId[2]  {0, 1};
constexpr int rightDriveId[2] {2, 3};
constexpr int armId[2]        {4, 5};

constexpr double driveCountsPerRevolution {2048};
constexpr double driveDiameter            {6};
constexpr double driveDistancePerPulse    {driveDiameter*std::numbers::pi/driveCountsPerRevolution};
//Assuming Encoder is on the shaft

constexpr double armCountsPerRevolution {0};
constexpr double armAnglePerPulse       {2*std::numbers::pi/armCountsPerRevolution};
}

#endif