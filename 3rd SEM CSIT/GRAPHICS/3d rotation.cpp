#include <graphics.h>
#include <iostream>
#include <math.h>
using namespace std;

struct Point3D {
    float x, y, z;
};

// ---------- ROTATION FUNCTIONS ----------

// X-axis
void rotateX(Point3D &p, float angle) {
    float r = angle * 3.1416 / 180;

    float y = p.y * cos(r) - p.z * sin(r);
    float z = p.y * sin(r) + p.z * cos(r);

    p.y = y;
    p.z = z;
}

// Y-axis
void rotateY(Point3D &p, float angle) {
    float r = angle * 3.1416 / 180;

    float x = p.x * cos(r) + p.z * sin(r);
    float z = -p.x * sin(r) + p.z * cos(r);

    p.x = x;
    p.z = z;
}

// Z-axis
void rotateZ(Point3D &p, float angle) {
    float r = angle * 3.1416 / 180;

    float x = p.x * cos(r) - p.y * sin(r);
    float y = p.x * sin(r) + p.y * cos(r);

    p.x = x;
    p.y = y;
}

// ---------- DRAW FUNCTION ----------

void drawCube(Point3D p[], int color) {

    setcolor(color);

    int edges[12][2] = {
        {0,1},{1,2},{2,3},{3,0},
        {4,5},{5,6},{6,7},{7,4},
        {0,4},{1,5},{2,6},{3,7}
    };

    for(int i=0; i<12; i++) {

        // Simple 3D projection
        int x1 = p[edges[i][0]].x + p[edges[i][0]].z/2 + 300;
        int y1 = p[edges[i][0]].y + p[edges[i][0]].z/2 + 200;

        int x2 = p[edges[i][1]].x + p[edges[i][1]].z/2 + 300;
        int y2 = p[edges[i][1]].y + p[edges[i][1]].z/2 + 200;

        line(x1, y1, x2, y2);
    }
}

// ---------- MAIN PROGRAM ----------

int main() {

    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    // Original cube
    Point3D cube[8] = {
        {50,50,50}, {100,50,50}, {100,100,50}, {50,100,50},
        {50,50,100}, {100,50,100}, {100,100,100}, {50,100,100}
    };

    // Copy for rotation
    Point3D cube2[8];
    for(int i=0; i<8; i++)
        cube2[i] = cube[i];

    int choice;
    float angle;

    cout << "Rotate about:\n";
    cout << "1. X-axis\n2. Y-axis\n3. Z-axis\n";
    cout << "Enter choice: ";
    cin >> choice;

    cout << "Enter angle (degrees): ";
    cin >> angle;

    // Draw original cube
    drawCube(cube, WHITE);

    // Apply selected rotation
    for(int i=0; i<8; i++) {

        if(choice == 1)
            rotateX(cube2[i], angle);

        else if(choice == 2)
            rotateY(cube2[i], angle);

        else if(choice == 3)
            rotateZ(cube2[i], angle);
    }

    // Draw rotated cube
    drawCube(cube2, YELLOW);
    outtextxy(10, 10, (char*)"---Swornim Maharjan---");
    outtextxy(10, 30, (char*)"Rotation");
    outtextxy(10, 50, (char*)"WHITE: Original Cube");
    outtextxy(10, 70, (char*)"YELLOW: Rotated Cube");

    getch();
    closegraph();
    return 0;
}
