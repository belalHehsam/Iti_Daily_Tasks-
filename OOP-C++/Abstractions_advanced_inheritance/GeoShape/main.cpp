#include <iostream>
#include <cmath>
using namespace std;

class GeoShape {
public:
    float dim1, dim2;
public:
    GeoShape() : dim1(0), dim2(0) {}
    GeoShape(float d) : dim1(d), dim2(d) {}
    GeoShape(float d1, float d2) : dim1(d1), dim2(d2) {}

    float calcArea() { return 0.0; }
    float calcPerimeter() { return 0.0; }

    GeoShape& operator=(const GeoShape& other) {
        if (this != &other) {
            this->dim1 = other.dim1;
            this->dim2 = other.dim2;
        }
        return *this;
    }
//Getters Methods
    float getDim1() { return dim1; }
    float getDim2() { return dim2; }
//Setters Methods
    void setDim1(float d) { dim1 = d; }
    void setDim2(float d) { dim2 = d; }
};

class Rect : public GeoShape {
public:
    Rect() = default;
    Rect(float d1, float d2) : GeoShape(d1, d2) {}

    float calcArea() { return dim1 * dim2; }
    float calcPerimeter() { return 2 * (dim1 + dim2); }

    Rect& operator=(const Rect& other) {
        if (this != &other) {
            GeoShape::operator=(other);
        }
        return *this;
    }

    void print() {
        cout << "Rectangle:"<<endl;cout << "the Area is  " << calcArea() << endl; cout << "the Perimeter is  " << calcPerimeter() << endl;
    }
};

class Square : protected Rect {
public:
    Square() = default;
    Square(float d) : Rect(d, d) {}

    float calcArea() { return dim1 * dim2; }
    float calcPerimeter() { return 4 * dim1; }

    Square& operator=(const Square& other) {
        if (this != &other) {
            Rect::operator=(other);
        }
        return *this;
    }

    //getSide for Square because Protected Inheritance
    float getSide(){
        return dim1;
        };
    //setSide for Square because Protected Inheritance

    void setSide(float s){
        dim1 = dim2 = s;
        }
    void print() {
        cout << "Square "<<endl;cout << "the Area is " << calcArea() <<endl;cout << "the Perimeter is " << calcPerimeter() <<endl;
    }
};

class Rhombus : public GeoShape {
public:
    Rhombus() = default;
    Rhombus(float d1, float d2) : GeoShape(d1, d2) {}

    float calcArea() {
         return (dim1 * dim2) / 2.0;
          }
    float calcPerimeter() {
        return 2 * sqrt(dim1*dim1 + dim2*dim2) * 2;
        }

    Rhombus& operator=(const Rhombus& other) {
        if (this != &other) {
            GeoShape::operator=(other);
        }
        return *this;
    }

    void print() {
        cout << "Rhombus "<<endl;cout << "the Area is " << calcArea() << endl;cout << "the Perimeter is  " << calcPerimeter() << endl;
    }
};

class Triangle : public GeoShape {
public:
    Triangle() = default;
    Triangle(float d1, float d2) : GeoShape(d1, d2) {}

    float calcArea() { return 0.5 * dim1 * dim2; }
    float calcPerimeter() { return dim1 + dim2 + sqrt(dim1*dim1 + dim2*dim2); //el water=sqrt(dim1 2+ dim2 2)
}

    Triangle& operator=(const Triangle& other) {
        if (this != &other) {
            GeoShape::operator=(other);
        }
        return *this;
    }

    void print() {
        cout << "Triangle "<<endl;cout << "the Area is " << calcArea() << endl;cout << "the Perimeter is  " << calcPerimeter() << endl;
    }
};

class Circle : protected GeoShape {
private:
    const float M_PI=3.1444;
public:
    Circle() = default;
    Circle(float r) : GeoShape(r) {}

    float calcArea() { return M_PI * dim1 * dim1; }
    float calcPerimeter() { return 2 * M_PI * dim1 /*r*/; }

    //setSide for Circle because Protected Inheritance

    void setRadius(float r){ dim1 = dim2 = r;}
    //getSide for Circle because Protected Inheritance

    float getRadius(){ return dim1; }

    Circle& operator=(const Circle& other) {
        if (this != &other) {
            GeoShape::operator=(other);
        }
        return *this;
    }

    void print() {
        cout << "Circle " <<endl;cout << "the Area is  " << calcArea() << endl;cout << "the Perimeter is " << calcPerimeter() << endl;
    }
};

class Cube : public Square {
public:
    Cube() = default;
    Cube(float s) : Square(s) {}

    float calcArea() { return 6 * dim1 * dim1; }
    float calcVolume() { return dim1 * dim1 * dim1; }
    float calcPerimeter() { return 12 * dim1; }


    Cube& operator=(const Cube& other) {
        if (this != &other) {
            GeoShape::operator=(other);
        }
        return *this;
    }

    void print() {
        cout << "Cube "<<endl;cout << "the Area is  " << calcArea() << endl;cout << "the Perimeter is" << calcPerimeter() << endl; cout << "the Volume is  " << calcVolume() <<endl;
    }
};

template <class T1, class T2>
int compareArea(T1& a, T2& b){
    float area1 = a.calcArea();float area2 = b.calcArea();

    if (area1 < area2){
             return -1;
    }

    else if(area1 > area2) {
         return 1;
    }

    return 0;
}

int main() {
    Rect r1(4, 5);
    Rect r2;
    r2 = r1;
    r1.print();
     r2.print();

    cout<<"====================================================="<<endl;

    Square s1(6);
    Square s2;
    s2 = s1;
    s1.print();
     s2.print();
    cout<<"====================================================="<<endl;


    Rhombus rm1(8, 10);
    Rhombus rm2;
    rm2 = rm1;
    rm1.print();
     rm2.print();

    cout<<"====================================================="<<endl;

    Triangle t1(5, 12);
    Triangle t2;
    t2 = t1;
    t1.print();
    t2.print();

    cout<<"====================================================="<<endl;

    Circle c1(7);
    Circle c2;
    c2 = c1;
    c1.print();
     c2.print();
    cout<<"====================================================="<<endl;


    Cube cb1(4);
    Cube cb2;
    cb2 = cb1;
    cb1.print();
    cb2.print();

    cout<<"====================================================="<<endl;

    cout << "Compare r1 and s1: " << compareArea(r1, s1) << "\n";
    cout << "Compare c1 and t1: " << compareArea(c1, t1) << "\n";
    cout << "Compare rm1 and cb1: " << compareArea(rm1, cb1) << "\n";

    return 0;
}
