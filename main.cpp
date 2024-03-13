#include "Vector.h"
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    ofstream output_file("output.txt");
    output_file.close();
    ifstream input_file("input.txt");
    if (!input_file.is_open()) {
        cout << "Input file didn't open." << endl;
    }
    Vector vector;
    input_file >> vector;
    int massiv[5] = { 5, 4, 3, 2, 1 };
    /*cout << vector << endl;
    for (int i = 0; i < 5; ++i) {
        cout << massiv[i];
    };
    cout << endl;*/
    cout << (vector<massiv);
}
