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
#ifndef SENECA_TIMEDEVENTS_H
#define SENECA_TIMEDEVENTS_H
#include <string>
#include <chrono>
#include <iostream>
#define MAX_EVENTS 10

namespace seneca {

    struct Event {
        std::string eventName{};
        std::string unitTime{};
        std::chrono::steady_clock::duration eventDuration;
    };

    class TimedEvents {
        int currentRecs;
        std::chrono::steady_clock::time_point startTime;
        std::chrono::steady_clock::time_point endTime;
        Event eventArr[MAX_EVENTS];

    public:
        TimedEvents();
        void startClock();
        void stopClock();
        void addEvent(const char* newEvent);
        friend std::ostream& operator<<(std::ostream& out, const TimedEvents& events);
    };

}

#endif // SENECA_TIMEDEVENTS_H
