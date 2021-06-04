#include <iostream>
#include "RubiksCube.hpp"
#include "Solver.hpp"
#include "Graphics.hpp"
using namespace std;

int main(int argc, char* args[])
{

    initGL(argc, args);
    RubiksCube rc = RubiksCube();
    string move = "";
    while (true) {
        DrawCube(rc);
        cout << rc << "\n> ";
        cin >> move;
        cout <<"\n";
        if (move == "quit")
            break;
        else if (move == "reset")
            rc.ResetFaces();
        else if (move == "scramble")
            rc.Scramble();
        else if (move == "solve") {
            cout << Solve(rc) << "\n";
        }
        else if (move == "save") {
            string name;
            cin >> name;
            rc.Save(name);
        }
        else if (move == "load") {
            string name;
            cin >> name;
            rc.Load(name);
        }
        else
            rc.Slide(atoi(move.c_str()));
    }
}