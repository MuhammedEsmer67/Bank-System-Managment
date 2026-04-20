#pragma once
#include <iostream>

using namespace std;

class clsPerson
{
private:

	string _FirstName;
	string _LastName;
	string _Email;
	string _PhoneNumber;

public:

	clsPerson(string FirstName, string LastName, string Email, string PhoneNumber)
	{
		_FirstName = FirstName;
		_LastName = LastName;
		_Email = Email;
		_PhoneNumber = PhoneNumber;
	}

	void setFirstName(string FirstName) { _FirstName = FirstName; }

	void setLastName(string LastName) {	_LastName = LastName; }

	void setEmail(string Email) { _Email = Email; }

	void setPhoneNumber(string PhoneNumber) { _PhoneNumber = PhoneNumber; }

	string getFirstName() { return _FirstName; }

	string getLastName() { return _LastName; }

	string getEmail() { return _Email; }

	string getPhoneNumber() { return _PhoneNumber; }

	string GetFullName() { return _FirstName + " " + _LastName; }

};

