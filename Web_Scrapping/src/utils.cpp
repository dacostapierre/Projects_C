#include "utils.h"
////////////////////////////////////////////////////////////////////////////////
// METHODS


//// Random numbers ////
// Init random generator
void Utils::initRandomGenerator(int seed) {
	if (seed == 0) {
		srand(time(NULL));
	} else {
		srand(seed);
	}
}

// Get random integer in interval [min ; max]
int Utils::getRandom(int min, int max) {
	return rand()%(max-min+1) + min;
}

//// Conversions ////
// Number to string
string Utils::toString(int nb) {
	std::ostringstream ss;
  ss << nb;
  return ss.str();
}
string Utils::toString(double nb) {
	std::ostringstream ss;
  ss << nb;
  return ss.str();
}
string Utils::toString(bool nb) {
	std::ostringstream ss;
  ss << nb;
  return ss.str();
}

// String to string
string Utils::toLower(string str) {
	for (int i=0 ; i<str.length() ; i++) {
		str[i] = tolower(str[i]);
	}
	return str;
}
string Utils::toUpper(string str) {
	for (int i=0 ; i<str.length() ; i++) {
		str[i] = toupper(str[i]);
	}
	return str;
}
string Utils::toFirstName(string str) {
	if (str.length() > 0) str[0] = toupper(str[0]);
	for (int i=1 ; i<str.length() ; i++) {
		str[i] = tolower(str[i]);
	}
	return str;
}

// Number to character (0 -> A, 1 -> B, 2 -> C, ...)
string Utils::toCharacter(int nb) {
	std::ostringstream ss;
  ss << (char)(65 + nb);
  return ss.str();
}

// Character to number (A -> 0, B -> 1, C -> 2, ...)
int Utils::toNumber(char character) {
	if (character >= 65 && character < 91) {
		return character - 65;
	} else if (character >= 48 && character < 58) {
		return character - 48;
	} else if (character >= 97 && character < 123) {
		return character - 97;
	} else {
		return -1;
	}
}

//// Screen ////
// Clear screen
void Utils::clearScreen() {
	for (int i=0 ; i<100 ; i++) {
		cout << "\n";
	}
}
// Delay screen (time in ms)
void Utils::delay(int timeMs) {
	usleep((long)1000 * (long)timeMs);
}

//// Text colors ////
// Set text color, background color, bold and underline styles
// Colors : {0, 1, 2, 3, 4, 5, 6, 7, 8} : {default, black, red, green, yellow, blue, magenta, cyan, white}
string Utils::setTextColor(int textColor, int backgroundColor, bool isBold, bool isUnderline) {
	string str = "\033[";

	// Text color
	if (textColor > 0) {
		str += Utils::toString(textColor + 29) + ";";
	}

	// Background color
	if (backgroundColor > 0) {
		str += Utils::toString(backgroundColor + 39) + ";";
	}

	// Bold
	if (isBold) {
		str += "1;";
	} else {
		str += "21;";
	}

	// Underline
	if (isUnderline) {
		str += "4";
	} else {
		str += "24";
	}

	str += "m";
	return str;
}

// Reset text color and styles to default
string Utils::resetTextColor() {
	return "\033[0m";
}

// Invert text color and background color
string Utils::invertTextColor() {
	return "\033[7m";
}

// Reset (=remove) text color inversion
string Utils::resetTextColorInversion() {
	return "\033[27m";
}
