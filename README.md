[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/f_6PzPyj)
# ds-graphical-recursive

Let's get creative. On this lab, you will be creating a recursive program that generates the base for a graphical recursive algorithm. Since we haven't seen any graphics library, you don't need to worry about the visualization, the professor will provide the mechanism ro visualize your data.

From the _Essential Algorithms: A Practical Approach to Computer Algorithms_ book, in [Chapter 9: Recursion](https://learning.oreilly.com/library/view/essential-algorithms-a/9781118612101/17_chapter09.html#c09-5), implement one of the following 3 graphical recursive algorithms

- Koch Curves
- Hilbert Curve
- Sierpiński Curve

# Implementation Requirements

- Each algorithm has its own parameters, make sure you document them in the [following section](#how-to-compile--run-you-program)
- Parameters must be sent through the command line. Example below:
    ```
    ./your-program <param1> <param2> ... 
    ```
- The output of your program will be a list of line segments in a file called `lines.txt`. The `lines.txt` file must follow the following format. Each pair represents a point in a 2D plane
    ```
    (1,2)(33,3)
    (3,5)(3,43)
    (2,1)(3,3)
    ```
- There's a 1024x1024 canvas, make sure that your generated points are inside that limited space. 
- The progressor will provide the mechanism to visualize your data, just make sure you generate the proper `lines.txt` file




# How to compile & run you program

## Algorithm Implemented
This program recursively generates the Sierpinski Arrowhead Curve. This is a type of fractal curve whose limit is the Sierpinski Triangle.

The algorithm starts with a base line and recursively replaces each segment with a pattern of three smaller segments, using 60-degree turns. The order parameter controls the recursion depth, increasing the detail of the final fractal shape. The step parameter controls the length of the smallest line segment.

## How to Compile & Run the Program
Compilation
To compile the program, you'll need a C++ compiler like g++. Open a terminal in the directory where you have the Sierpinski.cpp file and run the following command:

Bash

g++ -std=c++11 -o sierpinski Sierpinski.cpp
This command will compile your source code and create an executable file named sierpinski.

Execution
The program requires two parameters from the command line:

<order>: An integer for the recursion depth (e.g., 5 is a good starting point).

<step>: An integer for the length of the smallest line segment (e.g., 10).

Run the program using the following format:

Bash

./sierpinski <order> <step>
Example:
To generate a curve of order 5 with a step size of 10, you would run:

Bash

./sierpinski 5 10
This will generate a file named lines.txt in the same directory, containing the line segments for the visualizer.

# Grading Policy

| **Rubric**                             | **Points** |
|----------------------------------------|------------|
| Successful Compilation                 | 25%        |
| Coding Practices                       | 5%         |
| Well formed `lines.txt` file           | 35%        |
| Proper Algorithm's graphics rendering  | 35%        |
| **Total**                              | 100%       |
