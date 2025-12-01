#include "SimpleGraphics.h"
#include <iostream>
using namespace std;

class Point{
    int x;
    int y;
public:
    Point(int x=0, int y=0): x(x), y(y) {}
    int getX(){ return x; }
    int getY(){ return y; }
};

class Circle {
    Point point;
    int r;
public:
    Circle(int x, int y, int r): point(x, y), r(r) {}
    int getRadius(){ return r; }
    void draw() { drawCircle(point.getX(), point.getY(), r); }
};

class Rect {
    Point ul;
    Point lr;
public:
    Rect(int ulx, int uly, int lrx, int lry): ul(ulx, uly), lr(lrx, lry) {}
    void draw() { drawRect(ul.getX(), ul.getY(), lr.getX(), lr.getY()); }
};

class Line {
    Point start;
    Point end;
public:
    Line(int x1, int y1, int x2, int y2): start(x1, y1), end(x2, y2) {}
    void draw() { drawLine(start.getX(), start.getY(), end.getX(), end.getY()); }
};

class Triangle {
    Point a;
    Point b;
    Point c;
public:
    Triangle(int ax, int ay, int bx, int by, int cx, int cy): a(ax, ay), b(bx, by), c(cx, cy) {}
    void draw() { drawTriangle(a.getX(), a.getY(), b.getX(), b.getY(), c.getX(), c.getY()); }
};

class Ellipse {
    Point f1;
    Point f2;
    int r;
public:
    Ellipse(int f1x, int f1y, int f2x, int f2y, int r): f1(f1x, f1y), f2(f2x, f2y), r(r) {}
    int getRadius(){ return r; }
    void draw() { drawEllipse(f1.getX(), f1.getY(), f2.getX(), f2.getY(), r); }
};


class Picture {
    Circle** circles; int cNum;
    Rect** rects; int rNum;
    Line** lines; int lNum;
    Triangle** tris; int tNum;
    Ellipse** ellipses; int eNum;
public:
    Picture(): circles(nullptr), cNum(0),
               rects(nullptr), rNum(0),
               lines(nullptr), lNum(0),
               tris(nullptr), tNum(0),
               ellipses(nullptr), eNum(0) {}

    void setCircles(int count, Circle** arr){ cNum = count; circles = arr; }
    void setRects(int count, Rect** arr){ rNum = count; rects = arr; }
    void setLines(int count, Line** arr){ lNum = count; lines = arr; }
    void setTriangles(int count, Triangle** arr){ tNum = count; tris = arr; }
    void setEllipses(int count, Ellipse** arr){ eNum = count; ellipses = arr; }

    void draw() {
        for(int i=0;i<cNum;i++) circles[i]->draw();
        for(int i=0;i<rNum;i++) rects[i]->draw();
        for(int i=0;i<lNum;i++) lines[i]->draw();
        for(int i=0;i<tNum;i++) tris[i]->draw();
        for(int i=0;i<eNum;i++) ellipses[i]->draw();
    }


};

int main() {
    initScreen();

    Picture pic;

    int cNum;
    cout << "Enter number of circles: ";
    cin >> cNum;
    Circle** circles = nullptr;
    if(cNum>0){
        circles = new Circle*[cNum];
        for(int i=0;i<cNum;i++){
            int x, y, r;
            cout << "Circle " << i+1 << " - Enter x y radius: ";
            cin >> x >> y >> r;
            circles[i] = new Circle(x, y, r);
        }
        pic.setCircles(cNum, circles);
    }

    int rNum;
    cout << "Enter number of rectangles: ";
    cin >> rNum;
    Rect** rects = nullptr;
    if(rNum>0){
        rects = new Rect*[rNum];
        for(int i=0;i<rNum;i++){
            int ulx, uly, lrx, lry;
            cout << "Rectangle " << i+1 << " - Enter ulx uly lrx lry: ";
            cin >> ulx >> uly >> lrx >> lry;
            rects[i] = new Rect(ulx, uly, lrx, lry);
        }
        pic.setRects(rNum, rects);
    }

    int lNum;
    cout << "Enter number of lines: ";
    cin >> lNum;
    Line** lines = nullptr;
    if(lNum>0){
        lines = new Line*[lNum];
        for(int i=0;i<lNum;i++){
            int x1, y1, x2, y2;
            cout << "Line " << i+1 << " - Enter x1 y1 x2 y2: ";
            cin >> x1 >> y1 >> x2 >> y2;
            lines[i] = new Line(x1, y1, x2, y2);
        }
        pic.setLines(lNum, lines);
    }

    int tNum;
    cout << "Enter number of triangles: ";
    cin >> tNum;
    Triangle** tris = nullptr;
    if(tNum>0){
        tris = new Triangle*[tNum];
        for(int i=0;i<tNum;i++){
            int ax, ay, bx, by, cx, cy;
            cout << "Triangle " << i+1 << " - Enter ax ay bx by cx cy: ";
            cin >> ax >> ay >> bx >> by >> cx >> cy;
            tris[i] = new Triangle(ax, ay, bx, by, cx, cy);
        }
        pic.setTriangles(tNum, tris);
    }

    int eNum;
    cout << "Enter number of ellipses: ";
    cin >> eNum;
    Ellipse** ellipses = nullptr;
    if(eNum>0){
        ellipses = new Ellipse*[eNum];
        for(int i=0;i<eNum;i++){
            int f1x, f1y, f2x, f2y, r;
            cout << "Ellipse " << i+1 << " - Enter f1x f1y f2x f2y r: ";
            cin >> f1x >> f1y >> f2x >> f2y >> r;
            ellipses[i] = new Ellipse(f1x, f1y, f2x, f2y, r);
        }
        pic.setEllipses(eNum, ellipses);
    }

    pic.draw();
    renderScreen();
//2
//100 100 50
//200 200 40

//1
//10 10 150 100

//2
//0 0 100 100
//200 50 300 200

//1
//50 50 150 50 100 200

//1
//100 100 150 100 200 200 80

    return 0;
}
