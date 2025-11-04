#include <GL/glut.h>
#include <cmath>
#include <iostream>

int width = 500, height = 500;

// Points for line strip
int points[5][2] = {
    {100, 400},
    {150, 300},
    {230, 200},
    {300, 250},
    {350, 350}
};

// Colors for each vertex
float colors[5][3] = {
    {1.0, 0.0, 0.0}, // Red
    {0.0, 1.0, 0.0}, // Green
    {0.0, 0.0, 1.0}, // Blue
    {1.0, 1.0, 0.0}, // Yellow
    {1.0, 0.0, 1.0}  // Magenta
};

// Midpoint circle algorithm
void midpointCircle(int xc, int yc, int r) {
    int x = 0, y = r;
    int p = 1 - r;

    while (x <= y) {
        glBegin(GL_POINTS);
        glVertex2i(xc + x, yc + y);
        glVertex2i(xc - x, yc + y);
        glVertex2i(xc + x, yc - y);
        glVertex2i(xc - x, yc - y);
        glVertex2i(xc + y, yc + x);
        glVertex2i(xc - y, yc + x);
        glVertex2i(xc + y, yc - x);
        glVertex2i(xc - y, yc - x);
        glEnd();

        x++;
        if (p < 0)
            p += 2 * x + 1;
        else {
            y--;
            p += 2 * (x - y) + 1;
        }
    }
}

// Bresenham line drawing
void drawLine(int x0, int y0, int x1, int y1) {
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = (x0 < x1) ? 1 : -1;
    int sy = (y0 < y1) ? 1 : -1;
    int err = dx - dy;

    while (true) {
        glBegin(GL_POINTS);
        glVertex2i(x0, y0);
        glEnd();
        if (x0 == x1 && y0 == y1) break;
        int e2 = 2 * err;
        if (e2 > -dy) { err -= dy; x0 += sx; }
        if (e2 < dx) { err += dx; y0 += sy; }
    }
}

// Display
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0, 0, 0); // black for lines

    // Draw the line strip
    for (int i = 0; i < 4; i++) {
        drawLine(points[i][0], points[i][1], points[i + 1][0], points[i + 1][1]);
    }

    // Draw colored circles at each vertex
    for (int i = 0; i < 5; i++) {
        glColor3f(colors[i][0], colors[i][1], colors[i][2]);
        midpointCircle(points[i][0], points[i][1], 15);
    }

    glFlush();
}

// Init
void init() {
    glClearColor(1, 1, 1, 1); // white background
    glPointSize(2.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, width, 0, height);
}

// Main
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(width, height);
    glutCreateWindow("Line Strip");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
