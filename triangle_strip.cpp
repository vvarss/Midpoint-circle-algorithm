#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

int width = 600, height = 500;

void drawPixel(int x, int y) {
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
    printf("(%d, %d)\n", x, y);  // log pixel position
}

void midpointCircle(int cx, int cy, int r) {
    int x = 0, y = r;
    int p = 1 - r;

    while (x <= y) {
        drawPixel(cx + x, cy + y);
        drawPixel(cx - x, cy + y);
        drawPixel(cx + x, cy - y);
        drawPixel(cx - x, cy - y);
        drawPixel(cx + y, cy + x);
        drawPixel(cx - y, cy + x);
        drawPixel(cx + y, cy - x);
        drawPixel(cx - y, cy - x);

        x++;
        if (p < 0)
            p += 2 * x + 1;
        else {
            y--;
            p += 2 * (x - y) + 1;
        }
    }
}

void drawLine(int x0, int y0, int x1, int y1) {
    int dx = abs(x1 - x0), dy = abs(y1 - y0);
    int sx = x0 < x1 ? 1 : -1;
    int sy = y0 < y1 ? 1 : -1;
    int err = dx - dy;

    while (1) {
        drawPixel(x0, y0);
        if (x0 == x1 && y0 == y1) break;

        int e2 = 2 * err;
        if (e2 > -dy) { err -= dy; x0 += sx; }
        if (e2 < dx) { err += dx; y0 += sy; }
    }
}

int pos[6][2] = {
    {100, 100},
    {120, 300},
    {220, 120},
    {240, 280},
    {340, 130},
    {360, 300}
};

// RGB colors for each vertex
float colors[6][3] = {
    {1.0f, 0.0f, 0.0f}, // red
    {0.0f, 1.0f, 0.0f}, // green
    {0.0f, 0.0f, 1.0f}, // blue
    {1.0f, 1.0f, 0.0f}, // yellow
    {1.0f, 0.0f, 1.0f}, // magenta
    {0.0f, 1.0f, 1.0f}  // cyan
};

int edges[][2] = {
    {0, 1}, {0, 2}, {1, 3}, {2, 3},
    {3, 5}, {4, 5}, {2, 4},
    {1, 2},
    {3, 4}
};

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.0, 0.0, 0.0); // black for lines

    int totalEdges = sizeof(edges) / sizeof(edges[0]);
    for (int i = 0; i < totalEdges; i++) {
        int from = edges[i][0];
        int to = edges[i][1];
        drawLine(pos[from][0], pos[from][1], pos[to][0], pos[to][1]);
    }

    for (int i = 0; i < 6; i++) {
        glColor3f(colors[i][0], colors[i][1], colors[i][2]); // set color per vertex
        midpointCircle(pos[i][0], pos[i][1], 20);
    }

    glFlush();
}

void init() {
    glClearColor(1, 1, 1, 1); // white background
    glPointSize(2.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, width, 0, height);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(width, height);
    glutCreateWindow("Triangle Strip");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
