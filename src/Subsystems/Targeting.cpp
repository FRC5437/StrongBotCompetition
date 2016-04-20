#include "Targeting.h"
#include "../RobotMap.h"

const double FOCAL_LENGTH = 583.515625;	//pixels; not calculated, but estimated
const double TARGET_WIDTH = 20.0;	//inches

const double FOCAL_TARGET_WIDTH = FOCAL_LENGTH * TARGET_WIDTH; //pixel-inches; should be 14961.50

Targeting::Targeting() : Subsystem("Targeting") {
	targetx = 0.0;
	grip = NetworkTable::GetTable("GRIP");
}

void Targeting::InitDefaultCommand() {
}

double* Targeting::GetTarget() {
	static double results[4];
	auto areas = grip->GetNumberArray("myContoursReport/area", llvm::ArrayRef<double>()),
		 centerX = grip->GetNumberArray("myContoursReport/centerX", llvm::ArrayRef<double>()),
		 centerY = grip->GetNumberArray("myContoursReport/centerY", llvm::ArrayRef<double>()),
		 width = grip->GetNumberArray("myContoursReport/width", llvm::ArrayRef<double>()),
		 height = grip->GetNumberArray("myContoursReport/height", llvm::ArrayRef<double>());

	double targetWidth = -1.0;
	int index = -1;
	for (uint i = 0; i < areas.size(); i++) {
		if (areas[i] > targetWidth) {
			targetWidth = areas[i];
			index = i;
		}
	}

	if (targetWidth >= 0.0) {
		results[0] = centerX[index];
		results[1] = centerY[index];
		results[2] = width[index];
		results[3] = height[index];
	}
	return results;
}

double Targeting::GetHeight() {
	auto widths = grip->GetNumberArray("myContoursReport/width", llvm::ArrayRef<double>()),
			centerY = grip->GetNumberArray("myContoursReport/centerY", llvm::ArrayRef<double>());

	double targetWidth = -1.0, temp = 0.0;
	for (uint i = 0; i < widths.size(); i++) {
		if (widths[i] > targetWidth) {
			targetWidth = widths[i];
			temp = centerY[i];
		}
	}

	if (targetWidth >= 0.0) {
		targetx = temp;
	}
	return targetx;
}

double Targeting::GetDistance() {
	auto widths = grip->GetNumberArray("myContoursReport/width", llvm::ArrayRef<double>()),
			targetHeights = grip->GetNumberArray("myContoursReport/height", llvm::ArrayRef<double>());

	double widthPixels = -1.0;
	double heightPixels = 0.0;
	for (uint i = 0; i < widths.size(); i++) {
		if (widths[i] > widthPixels) {
			widthPixels = widths[i];
			heightPixels = targetHeights[i];
		}
	}

	//double distHypotenuse = ((FOCAL_LENGTH * AdjustTargetWidthForSkew(widthPixels, heightPixels)) / widthPixels); // distance calculation
	double distGround =  144; //sqrt((pow(distHypotenuse, 2.0)) - pow(92.75, 2.0)); //92.75 is the approximate distance in inches from the camera's height to the target's height
	SmartDashboard::PutNumber("Distance from target", distGround);
	return distGround;
}

double Targeting::AdjustTargetingBasedOnArea( double width, double height) {
	double area = width * height;
	double baseline_area = 3500; //TODO determine the real baseline

	double elevator_adjustment = (area - baseline_area) * 0.02;

	return elevator_adjustment;
}

bool Targeting::OnTargetX( double centerX ) {
	return abs(centerX - TargetX()) < 3;
}

double Targeting::TargetX() {
	return GetTarget()[0];
}

double Targeting::TargetY() {
	return GetTarget()[1];
}

bool Targeting::HasTarget() {
	auto widths = grip->GetNumberArray("myContoursReport/width", llvm::ArrayRef<double>());
	if (widths.size() == 0) {
		return false;
	} else {
		return true;
	}
}
