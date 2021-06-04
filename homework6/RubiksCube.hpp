#pragma once
#include <cstring>
#include <string>
#include <fstream>
using namespace std;

class RubiksCube {
public:
	enum moves {
		R, RI,
		L, LI,
		B, BI,
		D, DI,
		F, FI,
		U, UI,
	};
	RubiksCube() {
		ResetFaces();
	}

	void Slide(moves move) {
		char tmp[3];
		switch (move) {
		case R:
			RotateFace(2, true);

			tmp[0] = faces[1][2][0];
			tmp[1] = faces[1][2][1];
			tmp[2] = faces[1][2][2];

			faces[1][2][0] = faces[5][2][0];
			faces[1][2][1] = faces[5][2][1];
			faces[1][2][2] = faces[5][2][2];

			faces[5][2][0] = faces[3][0][2];
			faces[5][2][1] = faces[3][0][1];
			faces[5][2][2] = faces[3][0][0];

			faces[3][0][2] = faces[4][2][0];
			faces[3][0][1] = faces[4][2][1];
			faces[3][0][0] = faces[4][2][2];

			faces[4][2][0] = tmp[0];
			faces[4][2][1] = tmp[1];
			faces[4][2][2] = tmp[2];
			break;
		case RI:
			RotateFace(2, false);

			tmp[0] = faces[1][2][0];
			tmp[1] = faces[1][2][1];
			tmp[2] = faces[1][2][2];

			faces[1][2][0] = faces[4][2][0];
			faces[1][2][1] = faces[4][2][1];
			faces[1][2][2] = faces[4][2][2];

			faces[4][2][0] = faces[3][0][2];
			faces[4][2][1] = faces[3][0][1];
			faces[4][2][2] = faces[3][0][0];

			faces[3][0][2] = faces[5][2][0];
			faces[3][0][1] = faces[5][2][1];
			faces[3][0][0] = faces[5][2][2];

			faces[5][2][0] = tmp[0];
			faces[5][2][1] = tmp[1];
			faces[5][2][2] = tmp[2];
			break;
		case L:
			RotateFace(0, true);

			tmp[0] = faces[1][0][0];
			tmp[1] = faces[1][0][1];
			tmp[2] = faces[1][0][2];

			faces[1][0][0] = faces[4][0][0];
			faces[1][0][1] = faces[4][0][1];
			faces[1][0][2] = faces[4][0][2];

			faces[4][0][0] = faces[3][2][2];
			faces[4][0][1] = faces[3][2][1];
			faces[4][0][2] = faces[3][2][0];

			faces[3][2][2] = faces[5][0][0];
			faces[3][2][1] = faces[5][0][1];
			faces[3][2][0] = faces[5][0][2];

			faces[5][0][0] = tmp[0];
			faces[5][0][1] = tmp[1];
			faces[5][0][2] = tmp[2];
			break;
		case LI:
			RotateFace(0, false);

			tmp[0] = faces[1][0][0];
			tmp[1] = faces[1][0][1];
			tmp[2] = faces[1][0][2];

			faces[1][0][0] = faces[5][0][0];
			faces[1][0][1] = faces[5][0][1];
			faces[1][0][2] = faces[5][0][2];

			faces[5][0][0] = faces[3][2][2];
			faces[5][0][1] = faces[3][2][1];
			faces[5][0][2] = faces[3][2][0];

			faces[3][2][2] = faces[4][0][0];
			faces[3][2][1] = faces[4][0][1];
			faces[3][2][0] = faces[4][0][2];

			faces[4][0][0] = tmp[0];
			faces[4][0][1] = tmp[1];
			faces[4][0][2] = tmp[2];
			break;
		case B:
			RotateFace(3, true);

			tmp[0] = faces[4][0][0];
			tmp[1] = faces[4][1][0];
			tmp[2] = faces[4][2][0];

			faces[4][0][0] = faces[2][2][0];
			faces[4][1][0] = faces[2][2][1];
			faces[4][2][0] = faces[2][2][2];

			faces[2][2][0] = faces[5][2][2];
			faces[2][2][1] = faces[5][1][2];
			faces[2][2][2] = faces[5][0][2];

			faces[5][2][2] = faces[0][0][2];
			faces[5][1][2] = faces[0][0][1];
			faces[5][0][2] = faces[0][0][0];

			faces[0][0][2] = tmp[0];
			faces[0][0][1] = tmp[1];
			faces[0][0][0] = tmp[2];
			break;
		case BI:
			RotateFace(3, false);

			tmp[0] = faces[4][0][0];
			tmp[1] = faces[4][1][0];
			tmp[2] = faces[4][2][0];

			faces[4][0][0] = faces[0][0][2];
			faces[4][1][0] = faces[0][0][1];
			faces[4][2][0] = faces[0][0][0];

			faces[0][0][2] = faces[5][2][2];
			faces[0][0][1] = faces[5][1][2];
			faces[0][0][0] = faces[5][0][2];

			faces[5][2][2] = faces[2][2][0];
			faces[5][1][2] = faces[2][2][1];
			faces[5][0][2] = faces[2][2][2];

			faces[2][2][0] = tmp[0];
			faces[2][2][1] = tmp[1];
			faces[2][2][2] = tmp[2];
			break;
		case D:
			RotateFace(5, true);

			tmp[0] = faces[1][0][2];
			tmp[1] = faces[1][1][2];
			tmp[2] = faces[1][2][2];

			faces[1][0][2] = faces[0][0][2];
			faces[1][1][2] = faces[0][1][2];
			faces[1][2][2] = faces[0][2][2];

			faces[0][0][2] = faces[3][0][2];
			faces[0][1][2] = faces[3][1][2];
			faces[0][2][2] = faces[3][2][2];

			faces[3][0][2] = faces[2][0][2];
			faces[3][1][2] = faces[2][1][2];
			faces[3][2][2] = faces[2][2][2];

			faces[2][0][2] = tmp[0];
			faces[2][1][2] = tmp[1];
			faces[2][2][2] = tmp[2];
			break;
		case DI:
			RotateFace(5, false);

			tmp[0] = faces[1][0][2];
			tmp[1] = faces[1][1][2];
			tmp[2] = faces[1][2][2];

			faces[1][0][2] = faces[2][0][2];
			faces[1][1][2] = faces[2][1][2];
			faces[1][2][2] = faces[2][2][2];

			faces[2][0][2] = faces[3][0][2];
			faces[2][1][2] = faces[3][1][2];
			faces[2][2][2] = faces[3][2][2];

			faces[3][0][2] = faces[0][0][2];
			faces[3][1][2] = faces[0][1][2];
			faces[3][2][2] = faces[0][2][2];

			faces[0][0][2] = tmp[0];
			faces[0][1][2] = tmp[1];
			faces[0][2][2] = tmp[2];
			break;
		case F:
			RotateFace(1, false);

			tmp[0] = faces[4][0][2];
			tmp[1] = faces[4][1][2];
			tmp[2] = faces[4][2][2];

			faces[4][0][2] = faces[2][0][0];
			faces[4][1][2] = faces[2][0][1];
			faces[4][2][2] = faces[2][0][2];

			faces[2][0][0] = faces[5][2][0];
			faces[2][0][1] = faces[5][1][0];
			faces[2][0][2] = faces[5][0][0];

			faces[5][2][0] = faces[0][2][2];
			faces[5][1][0] = faces[0][2][1];
			faces[5][0][0] = faces[0][2][0];

			faces[0][2][2] = tmp[0];
			faces[0][2][1] = tmp[1];
			faces[0][2][0] = tmp[2];
			break;
		case FI:
			RotateFace(1, true);

			tmp[0] = faces[4][0][2];
			tmp[1] = faces[4][1][2];
			tmp[2] = faces[4][2][2];

			faces[4][0][2] = faces[0][2][2];
			faces[4][1][2] = faces[0][2][1];
			faces[4][2][2] = faces[0][2][0];

			faces[0][2][2] = faces[5][2][0];
			faces[0][2][1] = faces[5][1][0];
			faces[0][2][0] = faces[5][0][0];

			faces[5][2][0] = faces[2][0][0];
			faces[5][1][0] = faces[2][0][1];
			faces[5][0][0] = faces[2][0][2];

			faces[2][0][0] = tmp[0];
			faces[2][0][1] = tmp[1];
			faces[2][0][2] = tmp[2];
			break;
		case U:
			RotateFace(4, true);

			tmp[0] = faces[1][0][0];
			tmp[1] = faces[1][1][0];
			tmp[2] = faces[1][2][0];

			faces[1][0][0] = faces[2][0][0];
			faces[1][1][0] = faces[2][1][0];
			faces[1][2][0] = faces[2][2][0];

			faces[2][0][0] = faces[3][0][0];
			faces[2][1][0] = faces[3][1][0];
			faces[2][2][0] = faces[3][2][0];

			faces[3][0][0] = faces[0][0][0];
			faces[3][1][0] = faces[0][1][0];
			faces[3][2][0] = faces[0][2][0];

			faces[0][0][0] = tmp[0];
			faces[0][1][0] = tmp[1];
			faces[0][2][0] = tmp[2];
			break;
		case UI:
			RotateFace(4, false);

			tmp[0] = faces[1][0][0];
			tmp[1] = faces[1][1][0];
			tmp[2] = faces[1][2][0];

			faces[1][0][0] = faces[0][0][0];
			faces[1][1][0] = faces[0][1][0];
			faces[1][2][0] = faces[0][2][0];

			faces[0][0][0] = faces[3][0][0];
			faces[0][1][0] = faces[3][1][0];
			faces[0][2][0] = faces[3][2][0];

			faces[3][0][0] = faces[2][0][0];
			faces[3][1][0] = faces[2][1][0];
			faces[3][2][0] = faces[2][2][0];

			faces[2][0][0] = tmp[0];
			faces[2][1][0] = tmp[1];
			faces[2][2][0] = tmp[2];
			break;
		}

	}

	void Slide(int move) {
		Slide(static_cast<moves>(move));
	}

	void Scramble() {
		for (int i = 0; i < 12; i++)
			Slide(rand() % 12);
	}

	/*string Solve() const {
		RubiksCube rc = *this;
		int solution[26];
		for (int i = 0; i < 12; i++) {
			solution[0] = i;
			string result = SolutionStep(solution, 1, rc);
			if (result != "")
				return result;
		}
		return "Sorry :(";
	}*/

	void ResetFaces() {
		char newfaces[6][3][3] = {
			{
				{'G', 'G', 'G'},
				{'G', 'G', 'G'},
				{'G', 'G', 'G'}
			},
			{
				{'R', 'R', 'R'},
				{'R', 'R', 'R'},
				{'R', 'R', 'R'}
			},
			{
				{'B', 'B', 'B'},
				{'B', 'B', 'B'},
				{'B', 'B', 'B'}
			},
			{
				{'O', 'O', 'O'},
				{'O', 'O', 'O'},
				{'O', 'O', 'O'}
			},
			{
				{'W', 'W', 'W'},
				{'W', 'W', 'W'},
				{'W', 'W', 'W'}
			},
			{
				{'Y', 'Y', 'Y'},
				{'Y', 'Y', 'Y'},
				{'Y', 'Y', 'Y'}
			}
		};
		memcpy(faces, newfaces, sizeof(char) * 3 * 3 * 6);
	}
	void Save(string name) const {
		ofstream file;
		file.open(name);
		for (int i = 0; i < 6; i++)
			for (int j = 0; j < 3; j++)
				for (int k = 0; k < 3; k++)
					file << faces[i][j][k];
		file.close();
	}
	void Load(string name) {
		ifstream file;
		file.open(name);
		for (int i = 0; i < 6; i++)
			for (int j = 0; j < 3; j++)
				for (int k = 0; k < 3; k++)
					file >> faces[i][j][k];
		file.close();
	}
	bool CheckFace(int face) const {
		char c = faces[face][0][0];
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				if (faces[face][i][j] != c)
					return false;
		return true;
	}
	friend std::ostream& operator<<(std::ostream& os, const RubiksCube& obj);
	char faces[6][3][3];
private:
	void RotateFace(int face, bool clockwise) {
		if (clockwise) {
			char tmp = faces[face][0][0];
			faces[face][0][0] = faces[face][0][2];
			faces[face][0][2] = faces[face][2][2];
			faces[face][2][2] = faces[face][2][0];
			faces[face][2][0] = tmp;
			tmp = faces[face][1][0];
			faces[face][1][0] = faces[face][0][1];
			faces[face][0][1] = faces[face][1][2];
			faces[face][1][2] = faces[face][2][1];
			faces[face][2][1] = tmp;
		}
		else {
			char tmp = faces[face][0][0];
			faces[face][0][0] = faces[face][2][0];
			faces[face][2][0] = faces[face][2][2];
			faces[face][2][2] = faces[face][0][2];
			faces[face][0][2] = tmp;
			tmp = faces[face][1][0];
			faces[face][1][0] = faces[face][2][1];
			faces[face][2][1] = faces[face][1][2];
			faces[face][1][2] = faces[face][0][1];
			faces[face][0][1] = tmp;
		}
	}
	/*string SolutionStep(int solution[], int depth, RubiksCube rc) const {
		rc.Slide(solution[depth - 1]);
		bool solved = true;
		for (int i = 0; i < 6; i++)
			if (!rc.CheckFace(i)) {
				solved = false;
				break;
			}
		if (solved) {
			string result = "Solution: ";
			for (int i = 0; i < depth; i++)
				result += to_string(solution[i]) + " ";
			return result;
		}
		else if (depth == 26)
			return "";
		int prev = solution[depth - 1];
		for (int i = 0; i < 12; i++) {
			if (prev - i == 1 && prev % 2 == 1)
				continue;
			if (prev - i == -1 && prev % 2 == 0)
				continue;
			solution[depth] = i;
			string result = SolutionStep(solution, depth + 1, rc);
			if (result != "")
				return result;
		}

	}*/
};

std::ostream& operator<<(std::ostream& os, const RubiksCube& obj) {
	for(int i = 0; i < 3; i++)
		os << "    " << obj.faces[4][0][i] << obj.faces[4][1][i] << obj.faces[4][2][i] << "\n";
	cout << "\n";
	for (int i = 0; i < 3; i++) {
		os << obj.faces[0][0][i] << obj.faces[0][1][i] << obj.faces[0][2][i] << " ";
		os << obj.faces[1][0][i] << obj.faces[1][1][i] << obj.faces[1][2][i] << " ";
		os << obj.faces[2][0][i] << obj.faces[2][1][i] << obj.faces[2][2][i] << " ";
		os << obj.faces[3][0][i] << obj.faces[3][1][i] << obj.faces[3][2][i] << "\n";
	}
	cout << "\n";
	for (int i = 0; i < 3; i++)
		os << "    " << obj.faces[5][0][i] << obj.faces[5][1][i] << obj.faces[5][2][i] << "\n";
	cout << "\n";
	return os;
}