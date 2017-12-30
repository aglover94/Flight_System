/*
* Main.cpp
*
* Version information v1.0
* Author: William Glover
* Date: 6/11/2017
* Description: The driver to test the FlightSystem class
* Copyright notice
*/

#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <regex>
#include "FlightSystem.h"

using namespace std;

int main() {

	// Initialise a FlightSystem
	FlightSystem k;

	k.AddAircraft("BA744", "British", "a330", 500, 37000, "A7", 180);
	k.AddAircraft("VA454", "British", "a330", 500, 37000, "F1", 180);
	k.AddAircraft("AL124", "British", "a330", 500, 37000, "B8", 180);

	k.numAircraftInSector();
	// Data to drive the menu
	int menukey;
	char menu('y');

	// Data members to handle user input before passing it to the FlightSystem class
	string fn;
	string al;
	string at;
	int gs;
	int alt;
	string g;
	int h;
	
	// Vectors to list all aircraft and all cruising aircraft in system
	vector<Aircraft>AllAir = k.ListAllAircraft();
	vector<Aircraft>CAircraft = k.ListAllCruisingAircraft();

	// Regex validation for the flght number and the grid reference 
	regex flightnum{ R"([A-Z][A-Z][A-Z]?\d\d\d?)" };
	regex grid{ R"([A-J][1-9][0]?)" };
	bool match1{ 0 };
	bool match2{ 0 };

	// The text menu the user will use
	do {
		cout << "Flight control system" << endl;
		cout << "1. Add new aircraft" << endl;
		cout << "2. Remove an aircraft" << endl;
		cout << "3. Number of aircraft in the system" << endl;
		cout << "4. Change aircraft heading" << endl;
		cout << "5. Change aircraft altitude" << endl;
		cout << "6. List of aircraft in sector" << endl;
		cout << "7. List of aircraft at cruising altitude in sector" << endl;
		cout << "Enter the number of the operation you would like to complete: ";
		while (!(cin >> menukey)) {
			cout << "Enter valid operation number: ";
			cin.clear();
			cin.ignore(100, '\n');
		}
		cout << endl;

		// If statements to determine what FlightSystem function to call based on the user input
		if (menukey == 1) {

			cout << "Enter flight number: ";
			cin >> fn;
			while (!match1) {
				if (regex_match(fn, flightnum)) {
					match1 = true;
				}
				else {

					cout << "Enter valid flight number: ";
					cin.clear();
					cin >> fn;
				}
			}
			cout << endl;

			cout << "Enter airline: ";
			cin.ignore();
			getline(cin, al, '\n');
			while (al.size() < 4 || al.size() > 20) {
				cout << "Invalid airline, please enter a valid airline name: ";
				cin.clear();
				getline(cin, al, '\n');
			}
			cout << endl;

			cout << "Enter aircraft type: ";
			cin >> at;
			cout << endl;

			cout << "Enter ground speed: ";
			cin >> gs;
			while (gs < 0 || gs > 800) {
				cout << "Invalid ground speed, please enter a valid speed value: ";
				cin.clear();
				cin >> gs;
			}
			cout << endl;

			cout << "Enter flight altitude: ";
			cin >> alt;
			while (alt < 0 || alt > 60000) {
				cout << "Invalid altitude, please enter a valid value: ";
				cin.clear();
				cin >> alt;
			}
			cout << endl;
			
			cout << "Enter grid: ";
			cin >> g;
			while (!match2) {
				if (regex_match(g, grid)) {
					match2 = true;
				}
				else {

					cout << "Enter valid grid reference: ";
					cin.clear();
					cin >> g;
				}
			}
			cout << endl;

			cout << "Enter flight heading: ";
			cin >> h;
			while (h < 0 || h > 360) {
				cout << "Invalid heading, please enter a valid heading: ";
				cin.clear();
				cin >> h;
			}
			cout << endl;

			k.AddAircraft(fn, al, at, gs, alt, g, h);
		}
		else if (menukey == 2) {
			
			cout << "Enter flight number: ";
			cin >> fn;
			while (!match1) {
				if (regex_match(fn, flightnum)) {
					match1 = true;
				}
				else {

					cout << "Enter valid flight number: ";
					cin.clear();
					cin >> fn;
				}
			}
			cout << endl;

		}
		else if (menukey == 3) {
			cout << "The number of aircraft in the system is: " << k.numAircraftInSector() << endl;
		}
		else if (menukey == 4) {
			cout << "Enter flight number: ";
			cin >> fn;
			while (!match1) {
				if (regex_match(fn, flightnum)) {
					match1 = true;
				}
				else {

					cout << "Enter valid flight number: ";
					cin.clear();
					cin >> fn;
				}
			}
			cout << endl;

			cout << "Enter new heading: ";
			cin >> h;
			while (h < 0 || h > 360) {
				cout << "Invalid heading, please enter a valid heading: ";
				cin.clear();
				cin >> h;
			}
			
			k.ChangeHeading(fn, h);
		}
		else if (menukey == 5) {
			cout << "Enter flight number: ";
			cin >> fn;
			while (!match1) {
				if (regex_match(fn, flightnum)) {
					match1 = true;
				}
				else {

					cout << "Enter valid flight number: ";
					cin.clear();
					cin >> fn;
				}
			}
			cout << endl;

			cout << "Enter new altitude: ";
			cin >> alt;
			while (alt < 0 || alt > 60000) {
				cout << "Invalid altitude number, please enter a valid value: ";
				cin.clear();
				cin >> alt;
			}

			k.ChangeAltitude(fn, alt);
		}
		else if (menukey == 6) {

			cout << "List of all aircraft" << endl;
			for (int index = 0; index < AllAir.size(); index++) {
				cout << "Flight number: " << AllAir.at(index).GetFlightNumber() << endl;
				cout << "Airline: " << AllAir.at(index).GetAirline() << endl;
				cout << "Altitude: " << AllAir.at(index).GetAltitude() << endl;
				cout << "Speed: " << AllAir.at(index).GetGroundSpeed() << endl;
				cout << "Grid: " << AllAir.at(index).GetGridReference() << endl;
				cout << "Heading: " << AllAir.at(index).GetHeading() << endl;
				cout << endl;
			}

		}
		else if (menukey == 7) {

			cout << "List of all cruising aircraft" << endl;
			for (int index = 0; index < CAircraft.size(); index++) {
				cout << "Flight number: " << CAircraft.at(index).GetFlightNumber() << endl;
				cout << "Airline: " << CAircraft.at(index).GetAirline() << endl;
				cout << "Altitude: " << CAircraft.at(index).GetAltitude() << endl;
				cout << "Speed: " << CAircraft.at(index).GetGroundSpeed() << endl;
				cout << "Grid: " << CAircraft.at(index).GetGridReference() << endl;
				cout << "Heading: " << CAircraft.at(index).GetHeading() << endl;
				cout << endl;
			}

		}
		else if (menukey < 1 || menukey > 7){
			cout << "You must enter a valid operation number." << endl;
		}
		
		
		cout << "Do you want to complete another operation? Y/N: ";
		cin >> menu;
		cout << endl;
		system("cls");

	} while (menu == 'y');
	
	cout << "End" << endl;

	return 0;
}