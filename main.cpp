#include "solver.h"
#include "headers.h"

int main() {
	vector<string> files = {"example", "small", "medium", "big" };
	cout << fixed;
	cout << setprecision(1);

	for (int i = 0; i < files.size(); i++) {
	
		cout << "Start reading input # " << (i + 1) << endl;
		Input input;
		input.read(files[i] + ".in");
		cout << "Input received" << endl;
		
		Solver solver;
		cout << "Start solver" << endl;
		clock_t before = clock();
		Output output = solver.solve(input);
		clock_t after = clock();
		double duration = double(after - before) / CLOCKS_PER_SEC;
		cout << "Task solved in:\t" << duration << " seconds" << endl;
		
		output.write(files[i] + ".out");
		cout << "Output file has been written" << endl;
	}

	return 0;
}