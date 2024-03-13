#include "Vector.h"
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream output_file("output.txt");
    output_file.close();

    ifstream input_file("input.txt");
    if (!input_file.is_open()) {
        cout << "Input file didn't open." << endl;
    }

    Vector vector1;
    input_file >> vector1;
    cout << "vector1 after creation based on data from input.txt:" << endl << vector1 << endl;
    Vector vector2(vector1);
    cout << "vector1 and vector2 after creating vector2 via copying data from vector1:" << endl << vector1 << endl << vector2 << endl;
    Vector vector3(move(vector2));
    cout << "vector2 and vector3 after creating vector3 via moving data from vector2:" << endl << vector2 << endl << vector3 << endl;
    vector2 = vector3;
    cout << "vector2 and vector3 after assigning (with copying) data of vector3 to vector2:" << endl << vector2 << endl << vector3 << endl;
    vector2 = move(vector3);
    cout << "vector2 and vector3 after assigning (with moving) data of vector3 to vector2:" << endl << vector2 << endl << vector3 << endl;
    int array1[5] = { 1, 5, 4, 3, 2 };
    cout << "This array will be compared with vector1:" << endl;
    for (int i = 0; i < 5; ++i) {
        cout << array1[i] << ' ';
    }
    cout << endl;
    cout << "Result of comparing vector1 with array1:" << endl << (vector1 < array1) << endl;
}
