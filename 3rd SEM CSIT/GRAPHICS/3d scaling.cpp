

#include <graphics.h>
#include <iostream>
using namespace std;

struct Point3D {
    float x, y, z;
};

// Scaling function
void scale(Point3D &p, float sx, float sy, float sz) {
    p.x *= sx;
    p.y *= sy;
    p.z *= sz;
}

// Draw cube with simple 3D projection
void drawCube(Point3D p[], int color) {

    setcolor(color);

    int edges[12][2] = {
        {0,1},{1,2},{2,3},{3,0},
        {4,5},{5,6},{6,7},{7,4},
        {0,4},{1,5},{2,6},{3,7}
    };

    for(int i=0; i<12; i++) {

        // Simple projection (makes cube look 3D)
        int x1 = p[edges[i][0]].x + p[edges[i][0]].z/2 + 300;
        int y1 = p[edges[i][0]].y + p[edges[i][0]].z/2 + 200;

        int x2 = p[edges[i][1]].x + p[edges[i][1]].z/2 + 300;
        int y2 = p[edges[i][1]].y + p[edges[i][1]].z/2 + 200;

        line(x1, y1, x2, y2);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    // Original cube points
    Point3D cube[8] = {
        {50,50,50}, {100,50,50}, {100,100,50}, {50,100,50},
        {50,50,100}, {100,50,100}, {100,100,100}, {50,100,100}
    };

    // Copy for scaling
    Point3D cube2[8];
    for(int i=0; i<8; i++)
        cube2[i] = cube[i];

    // Scaling factors
    float sx = 1.5, sy = 1.5, sz = 1.5;

    // Draw original cube
    drawCube(cube, WHITE);

    // Apply scaling to copy
    for(int i=0; i<8; i++)
        scale(cube2[i], sx, sy, sz);

    // Draw scaled cube
    drawCube(cube2, GREEN);
    outtextxy(10, 10, (char*)"---Swornim Maharjan---");
    outtextxy(10, 30, (char*)"Scaling");
    outtextxy(10, 50, (char*)"WHITE: Original Cube");
    outtextxy(10, 70, (char*)"GREEN: Scaled Cube");

    getch();
    closegraph();
    return 0;
}
