#include <iostream>
#include "string.h"

using namespace std;

// default constructor sets string to empty
String::String() {
	size = 0;
	array = NULL;
}

// constructor which sets string to a character array
String::String(const char cstring[]) {
	size = strlen(cstring);
	array = new char[size];
	for (int i = 0; i < size; i++) {
		array[i] = cstring[i];
	}
}

// destructor which de-allocates a string
/*String::~String() {
	delete[] array;
}*/

// copy constructor
String::String(const String& other) {
	size = other.size;
	array = new char[size];
	for (int i = 0; i < size; i++) {
		array[i] = other.array[i];
	}
}

// assignment operator
String String::operator=(const String& other) {
	if (this == &other) {
		return *this;
	}
	delete[] array;
	size = other.size;
	array = new char[size];
	for (int i = 0; i < size; i++) {
		array[i] = other.array[i];
	}
}

// returns the length of the string
int String::length() const {
	return size;
}

// returns references to characters in the string which allows setting
// specific characters e.g. str[0] = 'A'
char& String::operator[](int i) {
	if (i < 0 || i >= size) {
		throw StringIndexOutOfBounds();
	}
	else {
		return array[i];
	}
}

// returns characters in the string by value which allows reading from
// the string
char String::operator[](int i) const {
	if (i < 0 || i >= size) {
		throw StringIndexOutOfBounds();
	}
	else {
		return array[i];
	}
}

// the addition operator allows concatenating two strings with +
String String::operator+(const String& other) const {
	String result;
	result.size = size + other.size;
	result.array = new char[result.size];
		// copy first one
	for (int i = 0; i < size; i++) {
		result.array[i] = array[i];
	}
		// copy second one
	for (int i = 0; i < other.size; i++) {
		result.array[i + size] = other[i];
	}
		return result;
}


// the output operator which allows string objects to be output
ostream& operator<<(ostream& os, const String& str) {
	for (int i = 0; i < str.length(); i++) {
		os << str[i];
	}

	return os;
}

// the less than operator compares two string objects
bool operator<(const String& a, const String& b) {
	int end = a.length() < b.length() ? a.length() : b.length();
	for (int i = 0; i < end; i++) {

		if (a[i] < b[i]) {
			return true;
		}
		else if (b[i] < a[i]) {
			return false;
		}
	}

	return a.length() < b.length();
}

// the other five comparison operators are defined in terms of less than
bool operator>=(const String& a, const String& b) {
	return !(a < b);
}

bool operator>(const String& a, const String& b) {
	return (b < a);
}

bool operator<=(const String& a, const String& b) {
	return !(b < a);
}

bool operator!=(const String& a, const String& b) {
	return (a < b) || (b < a);
}

bool operator==(const String& a, const String& b) {
	return !(a < b) && !(b < a);
}