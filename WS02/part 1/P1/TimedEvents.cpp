/***********************************************************************
// Workshop 2 Part 2
// Module: StringSet
// File:
// Version 1.0
// Author
// Description
//	Name      : Kiarash Kia
//	Student ID: 108688235
//	Email     : kkia2@myseneca.ca
//
//	I have done all the coding by myself and only copied the code
//	 that my professor provided to complete my workshops and
//	 assignments.
// Revision History
// -----------------------------------------------------------
// Name                 Date            Reason
***********************************************************************/
#include "TimedEvents.h"
#include <iomanip>

namespace seneca {

	TimedEvents::TimedEvents() : currentRecs(0) {}

	void TimedEvents::startClock() {
		startTime = std::chrono::steady_clock::now();
	}

	void TimedEvents::stopClock() {
		endTime = std::chrono::steady_clock::now();
	}

	void TimedEvents::addEvent(const char* newEvent) {
		eventArr[currentRecs].eventName = newEvent;
		eventArr[currentRecs].unitTime = "nanoseconds";
		eventArr[currentRecs].eventDuration = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);
		currentRecs++;
	}

	std::ostream& operator<<(std::ostream& os, const TimedEvents& events) {
		os << "Execution Times:" << std::endl;
		os << "--------------------------" << std::endl;
		for (int i = 0; i < events.currentRecs; i++) {
			os << std::left << std::setw(21) << events.eventArr[i].eventName
				<< std::right << std::setw(13) << events.eventArr[i].eventDuration.count()
				<< " " << events.eventArr[i].unitTime << std::endl;
		}
		os << "--------------------------" << std::endl;
		return os;
	}


}



