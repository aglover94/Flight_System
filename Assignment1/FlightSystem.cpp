/*
* FlightSystem.cpp
*
* Version information v1.0
* Author: William Glover
* Date: 6/11/2017
* Description: Class definition .cpp file for FlightSystem class
* Copyright notice
*/

#include "FlightSystem.h"

// Add an aircraft to the aircraft vector with the specified data.
void FlightSystem::AddAircraft(std::string flightNumber, std::string airline, std::string aircraftType, 
	int groundSpeed, int altitude, std::string gridReference, int heading){
	Aircraft a(flightNumber, airline, aircraftType, groundSpeed, altitude, gridReference, heading);
	
	for (int index = 0; index < aircraftList_.size(); index++) {
		if (gridReference == aircraftList_.at(index).GetGridReference()) {
			if (altitude - aircraftList_.at(index).GetAltitude() <= 3000 || aircraftList_.at(index).GetAltitude() - altitude <= -3000) {
				std::cout << "Warning - Aircraft collision possible between " << flightNumber << " and " << aircraftList_.at(index).GetFlightNumber() << std::endl;

			}
		}

		if (flightNumber == aircraftList_.at(index).GetFlightNumber()){
			std::cout << "Flight " << flightNumber << " already in the system" << std::endl;
		}
	}
	aircraftList_.push_back(a);
}

// Returns a vector containing all the aircraft in the system.
std::vector<Aircraft> FlightSystem::ListAllAircraft(){

	return aircraftList_;

}

// Returns a vector containing all aircraft at or above 30,000 ft.
std::vector<Aircraft> FlightSystem::ListAllCruisingAircraft(){
	
	std::vector<Aircraft> CruisingAircrafts;

	for (int index = 0; index < aircraftList_.size(); index++) {
		if (aircraftList_.at(index).GetAltitude() >= 30000) {
			CruisingAircrafts.push_back(aircraftList_.at(index));
		}
	}
	return CruisingAircrafts;
}

// Returns the number of aircraft in the system.
int FlightSystem::numAircraftInSector(){
	return aircraftList_.size();
}

// Will remove the aircraft that matches the flight number provided, if aircraft 
// isn't in the system it will tell the user that it's not.
void FlightSystem::RemoveAircraft(std::string flightNumber){
	for (int index = 0; index < aircraftList_.size(); index++) {
		if (aircraftList_.at(index).GetFlightNumber() == flightNumber) break;
		if(index > 0){
			aircraftList_.erase(aircraftList_.begin() + index);
		}
		else {
			std::cout << "Flight " << flightNumber << " is not in the system" << std::endl;
		}
	}
}

// Will change heading of aircraft specified with the new heading specified by the user, 
// if aircraft isn't in the system it will tell the user that it's not.
void FlightSystem::ChangeHeading(std::string flightNumber, int heading){
	for (int index = 0; index < aircraftList_.size(); index++) {
		if (aircraftList_.at(index).GetFlightNumber() == flightNumber) {
			aircraftList_.at(index).SetHeading(heading);
			std::cout << "Heading of flight " << flightNumber << " changed to " << heading << std::endl;
		}
		else if (aircraftList_.at(index).GetFlightNumber() != flightNumber) {
			std::cout << "Flight " << flightNumber << " is not in the system" << std::endl;
		}
	}
}

// Will return the heading of the aircraft specified by the user, if aircraft isn't in
// the system it will tell the user that it's not.
int FlightSystem::GetHeading(std::string flightNumber) const{
	for (int index = 0; index < aircraftList_.size(); index++) {
		if (aircraftList_.at(index).GetFlightNumber() == flightNumber) {
			return aircraftList_.at(index).GetHeading();
		}
		else if (aircraftList_.at(index).GetFlightNumber() != flightNumber) {
			std::cout << "Flight " << flightNumber << " is not in the system" << std::endl;
		}
	}
	return -1;
}

// Will change altitude of aircraft specified with the new altitude specified by the user,
// if aircraft isn't in the system it will tell the user that it's not.
void FlightSystem::ChangeAltitude(std::string flightNumber, int altitude) {

	std::string Gridt;

	for (int index = 0; index < aircraftList_.size(); index++) {
		if (aircraftList_.at(index).GetFlightNumber() == flightNumber) {
			aircraftList_.at(index).SetAltitude(altitude);
			std::cout << "Altitude of flight " << flightNumber << " changed to " << altitude << std::endl;
			for (int index = 0; index < aircraftList_.size(); index++) {
				Gridt = aircraftList_[index].GetGridReference();
				if (Gridt == aircraftList_.at(index).GetGridReference()) {
					if (altitude - aircraftList_.at(index).GetAltitude() <= 3000 || aircraftList_.at(index).GetAltitude() - altitude <= -3000) {
						if (flightNumber == aircraftList_.at(index).GetFlightNumber()) {
						}
						else {
							std::cout << "Warning - Aircraft collision possible between " << flightNumber << " and " << aircraftList_.at(index).GetFlightNumber() << std::endl;
						}
					}
				}
			}
		}
		else if (aircraftList_.at(index).GetFlightNumber() != flightNumber) {
			std::cout << "Flight " << flightNumber << " is not in the system" << std::endl;
		}
	}
}

// Will return the altitude of the aircraft specified by the user, 
// if aircraft isn't in the system it will tell the user that it's not.
int FlightSystem::GetAltitude(std::string flightNumber) const{
	for (int index = 0; index < aircraftList_.size(); index++) {
		if (aircraftList_.at(index).GetFlightNumber() == flightNumber) {
			return aircraftList_.at(index).GetAltitude();
		}
		else if (aircraftList_.at(index).GetFlightNumber() != flightNumber) {
			std::cout << "Flight " << flightNumber << " is not in the system" << std::endl;
		}
	}
	return -1;
}
