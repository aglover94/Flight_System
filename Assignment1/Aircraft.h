/*
* Aircraft.h
*
* Version information v1.0
* Author: William Glover
* Date: 6/11/2017
* Description: Class decleration header file for Aircraft class
* Copyright notice
*/

#pragma once

#include <iostream>
#include <string>

class Aircraft {
private:
	
	//Private data members

	std::string flightNumber_;
	std::string airline_;
	std::string aircraftType_;
	int groundSpeed_;
	int altitude_;
	std::string gridReference_;
	int heading_;

public:

	//Public member functions

	// Default constructor, will create an empty aircraft object.
	Aircraft();

	
	//Custom constructor, will initialise the object with the data that is passed in.
	Aircraft(std::string flightNumber, std::string airline, std::string aircraftType, 
		int groundSpeed, int altitude, std::string gridReference, int heading);


	//The getters and setters for each of the data members.
	void SetFlightNumber(std::string flightNumber);
	std::string GetFlightNumber() const;

	void SetAirline(std::string airline);
	std::string GetAirline() const;
	
	void SetAircraftType(std::string aircraftType);
	std::string GetAircraftType() const;
	
	void SetGroundSpeed(int groundSpeed);
	int GetGroundSpeed() const;
	
	void SetAltitude(int altitude);
	int GetAltitude() const;
	
	void SetGridReference(std::string gridReference);
	std::string GetGridReference() const;

	void SetHeading(int heading);
	int GetHeading() const;

};