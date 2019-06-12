#include <stdlib.h>
#include <iostream>
#include <GL/glut.h>
#include <unistd.h>
using namespace std;

GLfloat x1=0,y1=0,x2=0,y2=0;

void display(void) {
     glClearColor (1.0, 0.0, 0.0, 1.0);
     glClear(GL_COLOR_BUFFER_BIT);
     glPointSize(5.0f);
    // glClearColor(255.0,0.0,0.0,1.0);
     glBegin(GL_POINTS);
         //glVertex2f(x1, y1);
         //glVertex2f(x2, y2);
    GLfloat m=(y2-y1)/(x2-x1);

     for  (int i=0; i<((x2-x1)*10);i++){
        glVertex2f(i/5.0, (i/5.0*m));
    }
     glEnd();
     glFlush();
}

void displayDelay(void) {
    //glClearColor (255.0, 100.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
         //glVertex2f(x1, y1);
         //glVertex2f(x2, y2);
    GLfloat m=(y2-y1)/(x2-x1);

   /*  for  (int i=0; i<((x2-x1)*10);i++){
        usleep(90000);
        glPointSize(5+i*i);
    // glClearColor(255.0,0.0,0.0,1.0);
        glBegin(GL_POINTS);
            glColor3f (i/10.0, 1.0, 1.0);
            glVertex2f(i/60.0, (i/60.0*m));
        glEnd();
        glFlush();
    }*/
    GLfloat xRotated, yRotated, zRotated;
GLdouble size=1;
    glMatrixMode(GL_MODELVIEW);
    // clear the drawing buffer.
    glClear(GL_COLOR_BUFFER_BIT);
    // clear the identity matrix.
    glLoadIdentity();
    // traslate the draw by z = -4.0
    // Note this when you decrease z like -8.0 the drawing will looks far , or smaller.
    glTranslatef(0.0,0.0,-4.5);
    // Red color used to draw.
    glColor3f(0.8, 0.2, 0.1); 
    // changing in transformation matrix.
    // rotation about X axis
    glRotatef(xRotated,1.0,0.0,0.0);
    // rotation about Y axis
    glRotatef(yRotated,0.0,1.0,0.0);
    // rotation about Z axis
    glRotatef(zRotated,0.0,0.0,1.0);
    // scaling transfomation 
    glScalef(1.0,1.0,1.0);
    // built-in (glut library) function , draw you a Teapot.
    glutSolidTeapot(size);
    glFlush();
}

int main(int argc, char* argv[]) {
    string titulo = "("+string(argv[1]) +","+ string(argv[2]) +") - ("+ string(argv[3]) +","+ string(argv[4]) + ")";

    x1 =atof(argv[1]);
    y1 = atof(argv[2]);
    x2 = atof(argv[3]);
    y2 = atof(argv[4]);

    glutInit(&argc, argv);
    glutInitDisplayMode( GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(1000, 1000);
    glutCreateWindow(titulo.c_str());
    glutDisplayFunc(displayDelay);
    glutMainLoop();

    return 0;
}
