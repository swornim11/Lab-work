#include <graphics.h>
#include <iostream>
using namespace std;

int main() {
    int gd = DETECT, gm;
    

    float x, y, z;          // starting point
    float w, h, d;          // width, height, depth

    cout << "Enter starting point (x y z): ";
    cin >> x >> y >> z;

    cout << "Enter width, height, depth: ";
    cin >> w >> h >> d;
    initgraph(&gd, &gm, (char*)"");

    // Cube vertices
    float cube[8][3] = {
        {x, y, z},
        {x+w, y, z},
        {x+w, y+h, z},
        {x, y+h, z},
        {x, y, z+d},
        {x+w, y, z+d},
        {x+w, y+h, z+d},
        {x, y+h, z+d}
    };

    // Cube edges
    int edges[12][2] = {
        {0,1},{1,2},{2,3},{3,0},
        {4,5},{5,6},{6,7},{7,4},
        {0,4},{1,5},{2,6},{3,7}
    };

    // Draw edges
    for(int i=0; i<12; i++){
        int x1 = cube[edges[i][0]][0] + cube[edges[i][0]][2]/2 + 300;
        int y1 = cube[edges[i][0]][1] + cube[edges[i][0]][2]/2 + 200;

        int x2 = cube[edges[i][1]][0] + cube[edges[i][1]][2]/2 + 300;
        int y2 = cube[edges[i][1]][1] + cube[edges[i][1]][2]/2 + 200;

        line(x1, y1, x2, y2);
    }

    outtextxy(10, 10, (char*)"---Swornim Maharjan---");
    outtextxy(10, 30, (char*)"Wireframe Cube");

    getch();
    closegraph();
    return 0;
}
