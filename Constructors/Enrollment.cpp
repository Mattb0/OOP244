#include <iostream>
#include "Enrollment.h"

using namespace std;
using namespace sict;

bool Enrollment::isValid()const {
	return name_ && name_[0];
}

void Enrollment::setEmpty() {
	name_[0] = 0;
	code_[0] = 0;
	year_ = 0;
	semester_ = 0;
	slot_ = 0;
	enrolled_ = false;
}

bool Enrollment::isEnrolled() const {
	return enrolled_;
}


void Enrollment::display(bool nameOnly)const {
	if (isValid()) {
		cout << name_;
		if (!nameOnly) {
			cout << endl << code_ << ", Year: " << year_ << " semester: " << semester_ << " Slot: " << slot_ << endl;
			cout << "Status: " << (isEnrolled() ? "E" : "Not e") << "nrolled." << endl;
		}
	}
	else {
		cout << "Invalid enrollment!" << endl;
	}
}

void Enrollment::set(const char* name, const char* code, int year, int semester, int time, bool enrolled) {

	setEmpty();

	if (name == NULL) {
			strcpy(name_, "");
	}
	else {
		strcpy(name_, name);
	}
	if (code == NULL) {
			strcpy(code_, "");
	}
	else {
		strcpy(code_, code);
	}
	year_ = year;
	slot_ = time;
	semester_ = semester;
	enrolled_ = enrolled;
}

bool Enrollment::hasConflict(const Enrollment &other) const {

	if (!isValid() || !other.isValid()) {
		return false;
	}

	if (year_ == other.year_ && semester_ == other.semester_ && slot_ == other.slot_)
	{
		return true;
	}
	else {
		return false;
	}
}


Enrollment::Enrollment(const char* name, const char* code, int year, int semester, int time)
{
	set(name, code, year, semester, time, false);
}

Enrollment::Enrollment() {
	setEmpty();
}

