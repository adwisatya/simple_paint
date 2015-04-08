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

void display(){

    if(mouseleftdown){

    }else if(mouserightdown){
        switch(vectorPoint.size()){
        case 2:
            cout << "dua";
            break;
        case 4:
            cout << "empat";
            break;

        case 6:
            cout << "enam";
            break;

        case 8:
            cout << "delapan";
            break;
        }
    }
}

void mouse(int button, int state, int x, int y){
    if(button == GLUT_LEFT_BUTTON){
        if(state == GLUT_DOWN){
            cout << "L-X:" << x;
            cout << "L-Y:" << y;
        }
    }
    if(button ==GLUT_RIGHT_BUTTON){
        if(state == GLUT_DOWN){
            cout << "R-X:" << x;
            cout << "R-Y:" << y;
        }
    }
}

void init(){
    glClearColor(1.0,1.0,1.0,1.0);
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
    /* Looping */
    glutMainLoop();
    return 0;
}
