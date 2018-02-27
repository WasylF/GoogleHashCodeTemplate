#include "Input.h"
#include "Output.h"
#include "Headers.h"

class Solver {
public:
	Solver() {}

	Output solve(Input input) {
		int c = input.a + input.b;
		return Output(c);
	}
};
