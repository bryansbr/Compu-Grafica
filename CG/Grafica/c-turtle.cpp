#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "GL/freeglut.h"
#include "GL/gl.h"


/*
Practica 1 computacion gráfica
Integrantes:
Juan David Torres 1526750
Juan Jose Vargas 1523382
*/



using namespace std;

bool show=true;
bool sphere=true;
bool plain=true;
bool eje=true;

//double rile=0.0;
//double updo=0.0;
double z[]={0.0,2.0,2.0,1.0,1.0,1.0,1.0,3.0,3.0,4.0,4.0,6.0,6.0,7.0,7.0,6.0,6.0,3.0,3.0,5.0,5.0,5.0,5.0,3.0,3.0,6.0,6.0,7.0,7.0,5.0,5.0,3.0,3.0,2.0,2.0,0.0};
double x[]={11.0,9.0,9.0,7.0,7.0,6.0,6.0,6.0,6.0, 7.0,7.0, 8.0,8.0, 7.0,7.0, 4.0,4.0,3.0,3.0,1.0,1.0,-1.0,-1.0,-3.0,-3.0,-5.0,-5.0,-7.0,-7.0,-9.0,-9.0,-8.0,-8.0,-7.0,-7.0,-6.0};

GLfloat x0 = 0.0, y0 = 0.0, z0 = 20.0;//10.0, 15.0, 20.0

void drawTurtle(void){
    
    
    if(show){
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_LINES);
    
    
    for(int i=0; i<36;i+=2){
            
        glVertex3d(z[i],x[i],0.0);
        glVertex3d(z[i+1],x[i+1],0.0);
        
        glVertex3d(z[i]*-1,x[i],0.0);
        glVertex3d(z[i+1]*-1,x[i+1],0.0);
    }
    glEnd();
        
    }
    
    
    
    
    
}

void SphereTurtle(void){


    glPushMatrix();
    glColor3f(0.0,0.0,0.0);
    glutWireSphere(5.0,50,50);
    glPopMatrix();        
    
    glPushMatrix();
    glTranslatef(5.0,5.0,0.0);
    glColor3f(0.0,0.0,0.0);
    glutWireSphere(2.5,20,20);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-5.0,5.0,0.0);
    glColor3f(0.0,0.0,0.0);
    glutWireSphere(2.5,20,20);
    glPopMatrix();
    
    
    glPushMatrix();
    glTranslated(-4.0,-6.0,0.0);
    glColor3f(0.0,0.0,0.0);
    glutWireSphere(2.5,20,20);
    glPopMatrix();
    
    glPushMatrix();
    glTranslated(4.0,-6.0,0.0);
    glColor3f(0.0,0.0,0.0);
    glutWireSphere(2.5,20,20);
    glPopMatrix();
    
    glPushMatrix();
    glTranslated(0.0,7.0,0.0);
    glColor3f(0.0,0.0,0.0);
    glutWireSphere(2.5,20,20);
    glPopMatrix();


    
}

void drawMain(void){
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);    
    if(plain)
        drawTurtle();
    if(sphere)
        SphereTurtle();

    if(eje){
        //pinta el eje rojo
        glColor3f(1.0,0.0,0.0);
        glBegin(GL_LINES);
        glVertex3f(800.0,0.0,0.0);
        glVertex3f(-800.0,0.0,0.0);
        glEnd();
        //pinta el eje verde
        glColor3f(0.0,1.0,0.0);
        glBegin(GL_LINES);
        glVertex3f(0.0,800.0,0.0);
        glVertex3f(0.0,-800.0,0.0);
        glEnd();
        //pinta el eje azul
        glColor3f(0.0,0.0,1.0);
        glBegin(GL_LINES);
        glVertex3f(0.0,0.0,800.0);
        glVertex3f(0.0,0.0,-800.0);
        glEnd();
        
    }

    glutSwapBuffers();

}

void reshape(int width, int height) {
    
    if(width<height){
        glViewport(0, 0, width, width);
    }
    else{
        glViewport(0, 0, height, height);
    }
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, 1.0, 1.0, 128.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    
    gluLookAt(x0, y0, z0,0.0 , 0.0, 0.0, 0.0, 1.0, 0.0);
        
    
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case 'h':
        printf("help\n\n");
        printf("c - Toggle culling\n");
        printf("q/escape - Quit\n\n");
        break;
    case 'c':
        if (glIsEnabled(GL_CULL_FACE))
           glDisable(GL_CULL_FACE);
        else
            glEnable(GL_CULL_FACE);
        break;
    case '6':
        glRotatef(1.0,0.0,1.0,0.0);
        break;
    case '2':
        glRotatef(1.0,1.0,0.0,0.0);
        break;
    case '8':
        glRotatef(1.0,-1.0,0.0,0.0);
        break;
    case '4':
        glRotatef(1.0,0.0,-1.0,0.0);
        break;
    case 'a':
        eje=!eje;
        break;
    case 's':
        sphere=!sphere;
        break;
    case 'p':
        plain=!plain;
        break;

    case 'u':
        y0+=0.1;
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        gluLookAt(x0, y0, z0,0.0 , 0.0, 0.0, 0.0, 1.0, 0.0);
        break;
    case 'd':
        y0-=0.1;
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        gluLookAt(x0, y0, z0,0.0 , 0.0, 0.0, 0.0, 1.0, 0.0);
        break;
    case 'r':
        x0+=0.1;
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        gluLookAt(x0, y0, z0,0.0 , 0.0, 0.0, 0.0, 1.0, 0.0);
        break;
    case 'l':
        x0-=0.1;
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        gluLookAt(x0, y0, z0,0.0 , 0.0, 0.0, 0.0, 1.0, 0.0);
        break;
    case 'q':
    case 27:
        exit(0);
        break;
    }
    glutPostRedisplay();
}



int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
    glutInitWindowSize(520, 520);
    glutInitWindowPosition(20, 20);
    glutCreateWindow("tortuga");
    glutDisplayFunc(drawMain);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    
    return 0;
}
