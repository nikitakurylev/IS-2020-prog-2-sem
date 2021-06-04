#ifndef SOLVER_H
#define SOLVER_H
#include "RubiksCube.hpp"
string Solve(RubiksCube rc) {
	//https://speedcubing.com.ua/howto/3x3
	//flower
	/*while (true) {
		bool isflower = true;
		if(rc.faces[4][2][1] != 'Y')
			if (rc.faces[1][2][1] == 'Y')
				rc.Slide(rc.R);
		if (rc.faces[1][2][1] == 'Y')
			rc.Slide(rc.LI);
	}
	*/


	while (true) {
		RubiksCube tmp = rc;
		string result = "";
		int previousmove = -100;
		for (int i = 0; i < 26; i++) {
			int move = rand() % 12;
			if (move + 1 == previousmove && move % 2 == 0)
				move = (move + 2) % 12;
			else if (move - 1 == previousmove && move % 2 == 1)
				move = (move + 2) % 12;
			result += to_string(move) + " ";
			tmp.Slide(move);
			bool solved = true;
			for(int j = 0; j < 6; j++)
				if (!tmp.CheckFace(j)) {
					solved = false;
					break;
				}
			if (solved)
				return result;
			previousmove = move;
			//cout << tmp;
		}
	}
}
#endif