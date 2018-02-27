#include "Solver.h"
#include "Headers.h"

int main() {
	vector<string> inputFiles = { "in1.txt", "in2.txt" };
	vector<string> outputFiles = { "out1.txt", "out2.txt" };
	cout << fixed;
	cout << setprecision(1);

	for (int i = 0; i < inputFiles.size(); i++) {
	
		cout << "Start reading input # " << (i + 1) << endl;
		Input input = Input::read(inputFiles[i]);
		cout << "Input received" << endl;
		
		Solver solver;
		cout << "Start solver" << endl;
		clock_t before = clock();
		Output output = solver.solve(input);
		clock_t after = clock();
		double duration = double(after - before) / CLOCKS_PER_SEC;
		cout << "Task solved in:\t" << duration << " seconds" << endl;
		
		output.write(outputFiles[i]);
		cout << "Output file has been written" << endl;
	}

	return 0;
}