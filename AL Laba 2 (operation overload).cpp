#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class Vector {
    friend ostream& operator<<(ostream& os, Vector& Vector);
    friend istream& operator>>(istream& is, Vector& Vector);
    friend bool operator<(Vector Vector, int* massiv);
public:
    Vector();
    Vector(double* massiv, int size);
    Vector(Vector& Vector2, string type);
    ~Vector() {
        if (p != nullptr) {
            delete[] p; // Зачем []?
        }
    }
    int operator[](int index) {
        return p[index];
    }
    Vector operator=(const Vector& Vector2) {
        n = Vector2.n;
        if (p == nullptr) {
            p = new int[n];
        }
        for (int i = 0; i < n; ++i) {
            p[i] = Vector2.p[i]; // Почему нельзя Vector2[i]?
        }
    }
private:
    int n = 0;
    int* p = nullptr;
};

Vector::Vector() {
};

Vector::Vector(double* massiv, int size) {
    this->n = size;
    this->p = new int[n];
    for (int i = 0; i < n; ++i) {
        this->p[i] = massiv[i];
    }
};

Vector::Vector(Vector& Vector2, string type) {
    if (type == "copy") {
        this->n = Vector2.n;
        this->p = new int[n];
        for (int i = 0; i < n; ++i) {
            this->p[i] = Vector2[i];
        }
    }else if (type == "swap") {
            swap(this->n, Vector2.n);
            swap(this->p, Vector2.p);
    }else {
        cout << "Wrong operation type, try 'copy' or 'swap'." << endl;
    }
};

ostream& operator<<(ostream& os, Vector& Vector) {
    ofstream file("output.txt");
    if (file.is_open()) {
        file << Vector.n << endl;
        for (int i = 0; i < Vector.n; ++i) {
            file << Vector.p[i] << ' ';
        }
    }else {
        cout << "Output file didn't open." << endl;
    }
    os << Vector.n << endl;
    for (int i = 0; i < Vector.n; ++i) {
        os << Vector.p[i] << ' ';
    }
    return os;
}

istream& operator>>(istream& is, Vector& Vector) {
    int amount;
    int value;
    vector <int> placeholder;
    is >> amount;
    for (int i = 0; i < amount; ++i) {
        is >> value;
        placeholder.push_back(value);
    }
    Vector.n = placeholder.size();
    Vector.p = new int[Vector.n];
    for (int i = 0; i < Vector.n; ++i) {
        Vector.p[i] = placeholder[i];
    }
    return is;
}

bool operator<(Vector Vector, int* massiv) {
    for (int i = 0; i < Vector.n; ++i) {
        if (Vector[i] < massiv[i]) {
            return true;
        }else if (Vector[i] > massiv[i]) {
            return false;
        }
    }
    return false;
}

int main() {
    /*double list[] = {1, 2, 3, 4, 5};
    Vector a(list, size(list));
    Vector b(a, "copy");
    cout << a << endl << b;*/
    ifstream file("input.txt");
    Vector a;
    file >> a;
    cout << a;
}
