#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

class GeoShape {
protected:
    float dim1, dim2;

public:
    GeoShape() : dim1(0), dim2(0) {}
    GeoShape(float d) : dim1(d), dim2(d) {}
    GeoShape(float d1, float d2) : dim1(d1), dim2(d2) {}

    virtual float calcArea()  = 0;
    virtual float calcPerimeter()  = 0;
    virtual void print()  = 0;
};

class Rect : public GeoShape {
public:
    Rect() = default;
    Rect(float w, float h) : GeoShape(w, h) {};
    //if not override pure virtual fun the class become abstractClass and I can't create object ;
    float calcArea() override {
        return dim1 * dim2;
         };

    float calcPerimeter() override {
         return 2 * (dim1 + dim2);
          };

    void print() override {
        cout << "Rect: "<<endl ;
        cout<<"the Area is  " << calcArea() <<endl;
        cout<< "the Perimeter is  " << calcPerimeter() << endl;     }
};

class Square : public GeoShape {
public:
    Square() = default;
    Square(float s) : GeoShape(s) {}
    float calcArea() override { return dim1 * dim1; }
    float calcPerimeter() override { return 4 * dim1; }
    void print() override {
        cout << "Square: "<<endl ;
        cout<<"the Area is  " << calcArea() <<endl;
        cout<< "the Perimeter is  " << calcPerimeter() << endl;    }
};

class Rhombus : public GeoShape {
public:
    Rhombus() = default;
    Rhombus(float d1, float d2) : GeoShape(d1, d2) {}
    float calcArea()override  { return (dim1 * dim2) / 2.0; }
    float calcPerimeter()override  { return 2 * sqrt(dim1*dim1 + dim2*dim2) * 2; }
    void print()override  {
        cout << "Rhombus: "<<endl ;
        cout<<"the Area is  " << calcArea() <<endl;
        cout<< "the Perimeter is  " << calcPerimeter() << endl;
            }
};

class Triangle : public GeoShape {
public:
    Triangle() = default;
    Triangle(float base, float height) : GeoShape(base, height) {}
    float calcArea() override { return 0.5 * dim1 * dim2; }
    float calcPerimeter()override  { return dim1 + dim2 + sqrt(dim1*dim1 + dim2*dim2); }
    void print()  override{
        cout << "Triangle: "<<endl ;
        cout<<"the Area is  " << calcArea() <<endl;
        cout<< "the Perimeter is  " << calcPerimeter() << endl;
    }
};

class Circle : public GeoShape {
private:
    const float M_PI=3.14444;
public:
    Circle() = default;
    Circle(float r) : GeoShape(r) {};
    float calcArea() override { return M_PI * dim1 * dim1; }
    float calcPerimeter() override { return 2 * M_PI * dim1; }
    void print() override {
        cout << "Circle"<<endl ;
        cout<<"the Area is  " << calcArea() <<endl;
        cout<< "the Perimeter is  " << calcPerimeter() << endl;
    }
};

class Cube : public GeoShape {
public:
    Cube() : GeoShape(0) {}
    Cube(float s) : GeoShape(s) {}
    float calcArea()override  { return 6 * dim1 * dim1; }
    float calcPerimeter() override { return 12 * dim1; }
    float calcVolume()  { return dim1 * dim1 * dim1; }
    void print()  override{
        cout <<"Cube: "<<endl ;
        cout<<"the Area is  " << calcArea() <<endl;
        cout<< "the Perimeter is  " << calcPerimeter() << endl;
        cout<<"the Volume is " << calcVolume() << endl;
    }
};

bool compareAreaAsc( GeoShape* a,  GeoShape* b) {
    return a->calcArea() < b->calcArea();
}

bool compareAreaDesc( GeoShape* a,  GeoShape* b) {
    return a->calcArea() > b->calcArea();
}

int main() {

    vector<GeoShape*> shapes;
        shapes.push_back(new Rect(4, 5));
        shapes.push_back(new Square(6));
        shapes.push_back(new Rhombus(8, 10));
        shapes.push_back(new Triangle(5, 12));
        shapes.push_back(new Circle(7));
        shapes.push_back(new Cube(4));


    cout << "the all Shapes are : "<<endl;
    for (int i = 0; i < 6; i++) {
        shapes[i]->print();
        cout <<" ===================n"<<endl;
    }
//begin and end return iterator
//sort  ASC

    sort(shapes.begin(), shapes.end(), compareAreaAsc);
    cout << "\nShapes sorted by area (ascending):\n";
    for (int i = 0; i < 6; i++) {
        shapes[i]->print();
        cout <<" ===================n"<<endl;
    }

//begin and end return iterator
//sort  Desc
    sort(shapes.begin(), shapes.end(), compareAreaDesc);
    cout << "\nShapes sorted by area (descending):\n";
    for (int i = 0; i < 6; i++) {
        shapes[i]->print();
        cout <<" ===================n"<<endl;
    }

    for (GeoShape* sh : shapes) {
    delete sh;
}

    return 0;
}


/*
 Object Slicing

انت بتمسك Object من نوع Rect

بتحطه جوه مكان متحجز لنوع GeoShape

الزيادة اللي في Rect (الدوال اللي معمولة override) بتضيع!

🔴 النتيجة:
الدوال الـ virtual مش هتشتغل، وهينادي دوال الأب بس مهما كان نوع الشكل الحقيقي.

*/
