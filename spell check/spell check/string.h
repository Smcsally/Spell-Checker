#include <iostream>

using namespace std;

class StringIndexOutOfBounds {};

class String {
public:
	// default constructor sets string to empty
	String();

	// constructor which sets string to a character array
	String(const char cstring[]);

	// destructor which de-allocates a string
	/*~String();*/

	// copy constructor
	String(const String& other);

	// assignment operator
	String operator=(const String& other);

	// returns the length of the string
	int length() const;

	// returns references to characters in the string which allows setting
	// specific characters e.g. str[0] = 'A'
	char& operator[](int i);

	// returns characters in the string by value which allows reading from
	// the string
	char operator[](int i) const;

	// the addition operator allows concatenating two strings with +
	String operator+(const String& other) const;

private:
	// the string objects store an array of characters and the length
	char* array;
	int size;
};

// the output operator which allows string objects to be output
ostream& operator<<(ostream& os, const String& str);

// the less than operator compares two string objects
bool operator<(const String& a, const String& b);

// the other five comparison operators are defined in terms of less than
bool operator>=(const String& a, const String& b);

bool operator>(const String& a, const String& b);

bool operator<=(const String& a, const String& b);

bool operator!=(const String& a, const String& b);

bool operator==(const String& a, const String& b);