/*
* Aircraft.cpp
*
* Version information v1.0
* Author: William Glover
* Date: 6/11/2017
* Description: Class definition .cpp file for Aircraft class
* Copyright notice
*/

#include "Aircraft.h"

//Default constructor, will create an empty aircraft object if no data is given.
Aircraft::Aircraft() {

}

//Custom constructor, will initialise the object with the data that is passed in.
Aircraft::Aircraft(std::string flightNumber, std::string airline, std::string aircraftType, 
	int groundSpeed, int altitude, std::string gridReference, int heading) 
	:flightNumber_{ flightNumber }, airline_{ airline }, aircraftType_{ aircraftType }, 
	groundSpeed_{ groundSpeed }, altitude_{ altitude }, gridReference_{ gridReference }, heading_{ heading } {
}

//The getters and setters for each of the data members.
void Aircraft::SetFlightNumber(std::string flightNumber) {
	flightNumber_ = flightNumber;
}
std::string Aircraft::GetFlightNumber() const {
	return flightNumber_;
}

void Aircraft::SetAirline(std::string airline) {
	airline_ = airline;
}
std::string Aircraft::GetAirline() const {
	return airline_;
}

void Aircraft::SetAircraftType(std::string aircraftType) {
	aircraftType_ = aircraftType;
}
std::string Aircraft::GetAircraftType() const {
	return aircraftType_;
}

void Aircraft::SetGroundSpeed(int groundSpeed) {
	groundSpeed_ = groundSpeed;
}
int Aircraft::GetGroundSpeed() const {
	return groundSpeed_;
}

void Aircraft::SetAltitude(int altitude) {
		altitude_ = altitude;
}
int Aircraft::GetAltitude() const {
	return altitude_;
}

void Aircraft::SetGridReference(std::string gridReference) {
	gridReference_ = gridReference;
}
std::string Aircraft::GetGridReference() const {
	return gridReference_;
}

void Aircraft::SetHeading(int heading) {
	heading_ = heading;
}
int Aircraft::GetHeading() const {
	return heading_;
}