#include "input.h"
#include "output.h"
#include "headers.h"

class Solver {
public:
	Solver() {}

	Output solve(Input input) {
		int c = input.a + input.b;
		return Output(c);
	}
};
