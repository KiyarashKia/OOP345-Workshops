/***********************************************************************
// OOP345 Workshop # 1 - P1
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
Date : 01/22/2024
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
		descEvent[0] = '\0';
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
		if (desc && desc[0] != '\0') {
			strncpy(descEvent, desc, 127);
			descEvent[127] = '\0';
		}
		else {
			descEvent[0] = '\0';
		}
		startTime = g_sysClock;
	}




}