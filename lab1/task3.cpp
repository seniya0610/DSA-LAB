#include <iostream>
using namespace std;

class Box {
private:
    int *dimX, *dimY, *dimZ;

public:
    Box(int x=0, int y=0, int z=0) : dimX(new int(x)), dimY(new int(y)), dimZ(new int(z)) {}
    
    Box(Box &other) : dimX(new int(*other.dimX)), dimY(new int(*other.dimY)), dimZ(new int(*other.dimZ)) {}
    
    Box& operator=(const Box &other) {
        if(this != &other) {
            *dimX = *other.dimX;
            *dimY = *other.dimY;
            *dimZ = *other.dimZ;
        }
        return *this;
    }
    
    void show() { cout << *dimX << "x" << *dimY << "x" << *dimZ << endl; }
    
    ~Box() { delete dimX; delete dimY; delete dimZ; }
};

int main() {
    Box box1(2, 3, 4);
    Box box2 = box1;
    
    cout << "Box1: "; box1.show();
    cout << "Box2: "; box2.show();
    
    return 0;
}
