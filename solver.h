#include "input.h"
#include "output.h"
#include "headers.h"

class Solver {
	Input input;
public:
	Solver() {}

	Output solve(Input input) {
		this->input = input;
		return solve();
	}

private:
	Output solve() {
		vector<vector<int>> tomatoSum(input.R + 1, vector<int>(input.C + 1, 0));
		vector<vector<int>> mushroomSum(input.R + 1, vector<int>(input.C + 1, 0));
		countSum(tomatoSum, 'T');
		countSum(mushroomSum, 'M');

		Output solution;
		int solutionScore = 0;

		for (int r1 = 1; r1 <= input.R; r1++) {
			for (int r2 = input.R; r2 >= r1; r2--) {
				int h = r2 - r1 + 1;
				int wMax = input.H / h;
				for (int c1 = input.C - wMax + 1; c1 >= 1; c1--) {
					for (int c2 = c1 + wMax - 1; c2 >= c1; c2--) {
						int tomatoes = getSum(tomatoSum, r1, c1, r2, c2);
						int mushrooms = getSum(mushroomSum, r1, c1, r2, c2);
						if (tomatoes >= input.L && mushrooms >= input.L) {
							int score = (r2 - r1 + 1) * (c2 - c1 + 1);
							if (score > solutionScore) {
								solution = Output(1, {Slice(r1-1, c1-1, r2-1, c2-1)});
								solutionScore = score;
							}
						}
					}
				}
			}
		}

		return solution;
	}

	int getSum(vector<vector<int>> &vSum, int r1, int c1, int r2, int c2) {
		if (c1 > c2) swap(c1, c2);
		if (r1 > r2) swap(r1, r2);
		return vSum[r2][c2] - vSum[r2][c1-1] - vSum[r1-1][c2] + vSum[r1-1][c1-1];
	}

	void countSum(vector<vector<int>> &vSum, char symbol) {
		for (int r = 1; r <= input.R; r++) {
			for (int c = 1; c <= input.C; c++) {
				vSum[r][c] = vSum[r-1][c] + vSum[r][c-1] - vSum[r-1][c-1]
						+	(input.pizza[r][c] == symbol ? 1 : 0);
			}
		}
	}
};
