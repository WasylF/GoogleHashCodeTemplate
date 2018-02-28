#include "headers.h"

struct Input {
	// fields declaration
	int a;
	int b;

	// constructor with all fields
	Input(int a, int b) : a(a), b(b) {}

	// read input from file
	static Input read(string &fileName) {
	    ifstream in(fileName.c_str());
		return read(in);
	}

	// read input from file or keyboard
	static Input read(istream &in) {
		int a, b;
		in >> a >> b;

		return Input(a, b);
	}
};
