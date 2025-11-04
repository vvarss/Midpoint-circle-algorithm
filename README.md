# ⭕Midpoint-circle-algorithm 

## 🎨Implementation & Visualization

This project demonstrates classic computer graphics algorithms using OpenGL and GLUT.
It includes:
* Bresenham’s Line Drawing Algorithm
* Midpoint Circle Drawing Algorithm
* Custom Line-Strip / Graph Visualization
* Per-vertex Coloring
* Manual Pixel Rendering (glVertex2i)

## 📌 Overview
This repository contains two C++ OpenGL programs:
1️⃣ Line Strip with Colored Vertices
* Draws a strip of connected line segments
* Each vertex is highlighted using a colored circle
* Uses Bresenham for lines and Midpoint method for circles

2️⃣ Graph Visualization with Multiple Edges
* Renders a custom node-edge diagram
* Each node is drawn as a colored circle
* Logs pixel coordinates for debugging

## 🖥️ Algorithms Implemented
### 1. Bresenham’s Line Algorithm
* Efficient integer-based line drawing
* Handles all slopes and directions
* Pixel-perfect rendering

### 2. Midpoint Circle Algorithm
* Symmetric circle generation
* Only integer arithmetic
* Produces 8 symmetric points per step

These algorithms avoid floating-point computation, making them fast and ideal for low-level graphics.

## 🖼️ Features
✨ Line Strip 
* Connected segment drawing
* Customizable vertex positions
* Different color for every vertex
* Circular markers at nodes

✨ Triangle Strip
* Draws multiple edges between arbitrary nodes
* Colored circles representing graph vertices
* Pixel-by-pixel logging for debugging

## 📚 Learning Outcomes
* Understanding of classic algorithms
* Creating custom shapes
* Manual graphs visualization
* Debug drawing routines

## ✨Output

Line Strip

<img width="521" height="465" alt="image" src="https://github.com/user-attachments/assets/930f8fcc-ef2e-48e9-8f92-c339b799b4dd" />

Triangle Strip

<img width="467" height="313" alt="image" src="https://github.com/user-attachments/assets/0dcc2616-978d-4bc2-86eb-38e245e47bee" />





The coordinates will get generated for Triangle Strip:


<img width="600" height="402" alt="image" src="https://github.com/user-attachments/assets/4e93c62a-9ce6-4e4c-a3f2-c5ae98380977" />
