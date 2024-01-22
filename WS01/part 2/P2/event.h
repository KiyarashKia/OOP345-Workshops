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

#ifndef SENECA_EVENT_H
#define SENECA_EVENT_H

namespace seneca {

	extern unsigned int g_sysClock; // extern as it is global and unsigned as the positivity constraint exists

	class Event {

		char* descEvent{ nullptr };
		unsigned int startTime{ 0 };

	public:
		Event();

		Event(const Event& other);

		~Event();

		Event& operator=(const Event& other);

		void display();

		void set(const char* desc = nullptr);

	};



}


#endif