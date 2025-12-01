#include "SimpleGraphics.h"
#include <iostream>
#include <cmath>
#include <cstring>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
const int WIDTH = 150;
const int HEIGHT = 150;
static char screen[HEIGHT][WIDTH];

void initScreen() {
    memset(screen, ' ', sizeof(screen));
}

void putPixel(int x, int y) {
    if (x>=0 && x<WIDTH && y>=0 && y<HEIGHT)
        screen[y][x] = '#';
}

void drawLine(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1), sx = (x1 < x2 ? 1 : -1);
    int dy = -abs(y2 - y1), sy = (y1 < y2 ? 1 : -1);
    int err = dx + dy, e2;

    while (true) {
        putPixel(x1, y1);
        if (x1 == x2 && y1 == y2) break;
        e2 = 2 * err;
        if (e2 >= dy) { err += dy; x1 += sx; }
        if (e2 <= dx) { err += dx; y1 += sy; }
    }
}

void drawRect(int x1, int y1, int x2, int y2) {
    for (int x=x1; x<=x2; x++) putPixel(x, y1);
    for (int x=x1; x<=x2; x++) putPixel(x, y2);
    for (int y=y1; y<=y2; y++) putPixel(x1, y);
    for (int y=y1; y<=y2; y++) putPixel(x2, y);
}

void drawCircle(int cx, int cy, int r) {
    for (int y=-r; y<=r; y++)
        for (int x=-r; x<=r; x++)
            if (x*x + y*y <= r*r)
                putPixel(cx+x, cy+y);
}

void drawTriangle(int x1,int y1,int x2,int y2,int x3,int y3){
    drawLine(x1,y1,x2,y2);
    drawLine(x2,y2,x3,y3);
    drawLine(x3,y3,x1,y1);
}


void drawEllipse(int f1x, int f1y, int f2x, int f2y, int r) {
    double cx = (f1x + f2x) / 2.0;
    double cy = (f1y + f2y) / 2.0;

    double dx = f2x - f1x;
    double dy = f2y - f1y;
    double c = sqrt(dx*dx + dy*dy) / 2.0;

    if (r / 2.0 <= c) return; // invalid ellipse, sum of distances too small

    double a = r / 2.0;              // semi-major axis
    double b = sqrt(a*a - c*c);      // semi-minor axis

    double angle = atan2(dy, dx);

    for (double t = 0; t < 2*M_PI; t += 0.01) {
        double px = a * cos(t);
        double py = b * sin(t);

        int screenX = int(cx + px * cos(angle) - py * sin(angle));
        int screenY = int(cy + px * sin(angle) + py * cos(angle));

        putPixel(screenX, screenY);
    }
}

void drawText(int x, int y, const char* txt){
    int i = 0;
    while (txt[i] && x+i < WIDTH) {
        if (y>=0 && y<HEIGHT)
            screen[y][x+i] = txt[i];
        i++;
    }
}

void renderScreen() {
    for (int y=0; y<HEIGHT; y++){
        for (int x=0; x<WIDTH; x++)
            std::cout << screen[y][x];
        std::cout << "\n";
    }
}
