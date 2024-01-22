/***********************************************************************
// OOP345 Workshop # 1
//
//
// Description:
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
/////////////////////////////////////////////////////////////////
***********************************************************************/
/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
Student : Kiarash Kia
Student ID: 108688235
Email: kkia2@myseneca.ca
Workshop 1 -
Date : 01/21/2024
 */

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <iomanip>
#include "event.h"


namespace seneca {

	unsigned int g_sysClock = 1;

	Event::Event() {
		startTime = g_sysClock;
		descEvent = new char[128];
	}

	Event::Event(const Event& other) : startTime(other.startTime) {
		if (other.descEvent)
		{
			descEvent = new char[strlen(other.descEvent) + 1];
			strcpy(descEvent, other.descEvent);
		}
		else
		{
			descEvent = nullptr;
		}
	}

	Event& Event::operator=(const Event& other) {
		if (this != &other) 
		{
			delete descEvent;
			
			if (other.descEvent)
			{
				descEvent = new char[strlen(other.descEvent) + 1];
				strcpy(descEvent, other.descEvent);

			}
			else
			{
				descEvent = nullptr;
			}
			startTime = other.startTime;
		}
		return *this;
	}

	Event::~Event() {
		delete descEvent;
	}


	void Event::display() {
		static int counter = 1;
		std::cout << std::setw(2) << std::setfill(' ') << counter << ". ";

		int hours = startTime / 3600;
		int minutes = (startTime % 3600) / 60;
		int seconds = startTime % 60;

		if (descEvent && descEvent[0] != '\0')
		{
			std::cout << std::setfill('0') << std::setw(2) << hours << ":"
				<< std::setfill('0') << std::setw(2) << minutes << ":"
				<< std::setfill('0') << std::setw(2) << seconds << " => "
				<< descEvent << std::endl;
		}
		else {
			std::cout << "| No Event |" << std::endl;
		}

		counter++;
	}

	void Event::set(const char* desc) {
		delete[] descEvent; // Deallocate existing memory
		if (desc && desc[0] != '\0') {
			descEvent = new char[strlen(desc) + 1];
			strcpy(descEvent, desc);
		}
		else {
			descEvent = new char[1] {'\0'}; // Assign an empty string, not nullptr
		}
		startTime = g_sysClock;
	}




}