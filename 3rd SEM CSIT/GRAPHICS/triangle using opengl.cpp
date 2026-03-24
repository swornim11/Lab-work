
#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Original triangle (Red)
    glColor3f(1, 0, 0);
    glBegin(GL_TRIANGLES);
        glVertex2f(-0.5, -0.5);
        glVertex2f(0.0, 0.5);
        glVertex2f(0.5, -0.5);
    glEnd();

    // Translated triangle (Green)
    glColor3f(0, 1, 0);
    glBegin(GL_TRIANGLES);
        glVertex2f(-0.5 + 0.5, -0.5 + 0.5);
        glVertex2f(0.0 + 0.5, 0.5 + 0.5);
        glVertex2f(0.5 + 0.5, -0.5 + 0.5);
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("Triangle Translation");
    gluOrtho2D(-1, 1, -1, 1);
    glutDisplayFunc(display);
    glutMainLoop();
}

