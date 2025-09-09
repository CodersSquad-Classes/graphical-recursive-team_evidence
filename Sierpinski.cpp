#include <iostream>
#include <fstream>
#define _USE_MATH_DEFINES
#include <cmath>
#include <cstdlib> 

using namespace std;

//PARAMETERS
//Drawing position and angle
double x = 512, y = 512; //Starting at the center
double angle = 0; //Current direction

ofstream file; //outputfile stream for lines.txt

//Moves forward one step and writes the line segment to the file
void forward(int step) {
    double rad = angle *    M_PI / 180; //convert to radians
    double newX = x + cos(rad) * step;
    double newY = y + sin(rad) * step;

    //To keep inside the parameters of the canvas
    if (newX < 0) newX = 0;
    if (newY < 0) newY = 0;
    if (newX > 1014) newX = 1024;
    if (newY > 1014) newY = 1024;

    //write one line segment
    file << "(" << (int)x << "," << (int)y << ")"
            << "(" << (int)newX << "," << (int)newY << ")\n";
    //Update the current position 
    x = newX;
    y = newY;
}

//Rotates the pen by some degrees (deg)
void turn (double deg) {
    angle += deg;
}

//Thi function generates the Sierpiński Curve
void sierpinski(int order, int step, int sign) {
    if (order == 0) { //if true just draw one forward srep, otherwise if makes it recursive calls with smaller order while turning the position
        forward(step);
    } else {
        turn(sign * 60); //sign controls where the curve turns
        sierpinski(order - 1, step, -sign);
        turn(-sign *60);
        sierpinski(order - 1, step, sign);
        turn(-sign *60);
        sierpinski(order - 1, step, -sign);
        turn(sign * 60);
    }
}

//main reads the parameters form command lines and opens the lines.txt file for writing 
int main (int argc, char* argv[]) {
    //revise if the user gave the arguments correctly
    if (argc < 3) { 
        cout << "Run in this form: " << "<order> <step>\n";
        return 1;
    }
    //(argc) arguments passed
    //(argv) actual arguments 
    
    //convert string to an integer
    int order = atoi(argv[1]); //recursion depth
    int step = atoi(argv[2]); //step size 

    file.open("lines.txt");
    if (!file) {
    cout << "Error opening file\n";
    return 1;
    }

    //start drawing
    sierpinski(order, step, 1); // calls the recursive function

    //clses file and show the message of it done.
    file.close();
    cout << "lines.txt generated\n";
    return 0;
}
