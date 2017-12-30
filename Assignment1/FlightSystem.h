/*
* FlightSystem.h
*
* Version information v1.0
* Author: William Glover
* Date: 6/11/2017
* Description: Class decleration header file for FlightSystem class
* Copyright notice
*/

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Aircraft.h"

class FlightSystem {
private:
	
	// Private data member

	std::vector<Aircraft> aircraftList_{};

public:

	// Public member functions

	// Add an aircraft to the aircraftList_ vector with the specified data.
	void AddAircraft(std::string flightNumber, std::string airline, std::string aircraftType,
		int groundSpeed, int altitude, std::string gridReference, int heading);

	// Returns a vector containing all the aircraft in the system.
	std::vector<Aircraft>ListAllAircraft();

	// Returns a vector containing all aircraft at or above 30,000 ft.
	std::vector<Aircraft>ListAllCruisingAircraft();

	// Returns the number of aircraft in the system.
	int numAircraftInSector();

	// Will remove the aircraft that matches the flight number provided.
	void RemoveAircraft(std::string flightNumber);

	// Will change heading of aircraft specified with the new heading specified by the user.
	void ChangeHeading(std::string flightNumber, int heading);

	// Will return the heading of the aircraft specified by the user.
	int GetHeading(std::string flightNumber) const;

	// Will change altitude of aircraft specified with the new altitude specified by the user.
	void ChangeAltitude(std::string flightNumber, int altitude);

	// Will return the altitude of the aircraft specified by the user.
	int GetAltitude(std::string flightNumber) const;
};