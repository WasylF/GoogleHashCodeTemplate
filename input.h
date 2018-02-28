#include "headers.h"

struct Input {
	// fields declaration
	int R,C,L,H;
    static const int MaxR = 1'000;
    static const int MaxC = 1'000;

    char pizza[MaxR+5][MaxC + 5];


	// read input from file
	void read(string fileName) {
	    ifstream in(fileName.c_str());
		read(in);
	}

	// read input from file or keyboard
	void read(istream &in) {
		in >> R >> C >> L >> H;
        for (int i = 1; i <= R; i++)
            for (int j = 1; j <= C; j++)
                in >> pizza[i][j];
	}
};
