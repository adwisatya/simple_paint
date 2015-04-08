// simplemouse.cpp
// by Glenn G. Chappell
// September 2003
//
// For CS 381
// Simple Mouse Demo
//
// Draws a red box at the mouse position
// whenever the left mouse button is down.

/* Modified by Aryya Dwisatya W */
#include <iostream>
#include <windows.h>
using std::string;
using namespace std;

#include <stdlib.h>
#include <GL/glut.h>
#include <vector>

/* Global Variable */
const int startwinsize = 600;
int winw, winh;
int counter = 0;
bool enablePush = false;
std::vector<float> vectorPoint;

/* mouse */
bool mouseleftdown = false;
bool mouserightdown  = false;
int mousex,mousey;
int pointsize = 2;

void display()
{
   if (mouseleftdown)
   {
      double oglx = double(mousex)/winw;
      double ogly = 1-double(mousey)/winh;

      glColor3d(0.9, 0.1, 0.1);
      glPointSize(pointsize);
      glBegin(GL_POINTS);
      glVertex2d(oglx, ogly);
      glEnd();
   }

   glutSwapBuffers();
}
void printVector(vector<float> vectorPoint){
    int i;
    for(i=0;i<vectorPoint.size();i+=2){
        cout << vectorPoint.at(i) << endl;
        cout << vectorPoint.at(i+1) << endl;
    }
}

void mouse(int button, int state, int x, int y){
    if(button == GLUT_LEFT_BUTTON){
        mouseleftdown = (state == GLUT_DOWN);
        glutPostRedisplay();
        if(state == GLUT_DOWN){
            cout << "L-X:" << x << endl;
            cout << "L-Y:" << y << endl;
            vectorPoint.push_back(x);
            vectorPoint.push_back(y);
        }
    }
    if(button == GLUT_RIGHT_BUTTON){
        mouserightdown = (state == GLUT_DOWN);
        glutPostRedisplay();
        if(state == GLUT_DOWN){
            cout << "Line history:" << endl;
            for(int i=0;i<vectorPoint.size();i+=2){
                cout << "X:" << vectorPoint[i] << "," << "Y:" << vectorPoint[i+1] << endl;
            }
        }
    }
    mousex = x;
    mousey = y;
}

void motion(int x, int y)
{
   if (mouseleftdown){
        cout << "L-X:" << x << endl;
        cout << "L-Y:" << y << endl;
        vectorPoint.push_back(x);
        vectorPoint.push_back(y);
        glutPostRedisplay();
   }
   mousex = x;
   mousey = y;
}
void reshape(int w, int h)
{
   glViewport(0, 0, w, h);

   winw = w;
   winh = h;

   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluOrtho2D(0.0, 1.0, 0.0, 1.0);

   glMatrixMode(GL_MODELVIEW);  // Always go back to model/view mode
}
void keyboard(unsigned char key, int x, int y)
{
   switch (key)
   {
   case 'b':
        pointsize += 1;
        cout << "Pointsize: " << pointsize << endl;
      break;
   case 'l':
        pointsize -=1;
        cout << "Pointsize: " << pointsize << endl;
    break;
   }
}
void init(){
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
}
int main(int argc, char ** argv){

    /* Inisiasi layar */
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(startwinsize,startwinsize);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Pempek Simple Polygons Drawer");


    /* Init */
    init();
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutReshapeFunc(reshape);
    glutMotionFunc(motion);
    glutKeyboardFunc(keyboard);

    /* Looping */
    glutMainLoop();
    return 0;
}
