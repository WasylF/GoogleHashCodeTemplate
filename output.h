#include "headers.h"

struct Slice {
	int r1,c1,r2,c2;

	Slice(int r1, int c1, int r2, int c2) : r1(r1), c1(c1), r2(r2), c2(c2) {}
};

struct Output {
	// fields declaration
	int S;
	vector<Slice> slices;

	Output() {}

	// constructor with all fields
	Output(int S, const vector<Slice> &slices) : S(S), slices(slices) {}

	// write output to file
	void write(string fileName) {
	    ofstream out(fileName.c_str());
		write(out);
	}

	// write output to file or console
	void write(ostream &out) {
		out << S << endl;
		for (Slice slice : slices) {
			out << slice.r1 << " " << slice.c1 << " "
				<< slice.r2 << " " << slice.c2 << endl;
		}
	}
};
