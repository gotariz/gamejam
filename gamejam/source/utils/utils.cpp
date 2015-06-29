#include "utils.h"

float utils::toAngle(float rotation)
{
	int intAngle = rotation;
	float safe_angle = rotation - intAngle;
	safe_angle += intAngle % 360;

	if (safe_angle < 0) safe_angle += 360;

	return safe_angle;
}