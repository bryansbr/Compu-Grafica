/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: diego
 *
 * Created on 2 de marzo de 2018, 02:46 PM
 */

#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <GL/glut.h>

using namespace std;

GLfloat rotX = 0.0f; // Rotate screen on x axis 
GLfloat rotY = 0.0f; // Rotate screen on y axis
GLfloat rotZ = 0.0f; // Rotate screen on z axis
GLfloat rotLx = 0.0f; // Translate screen by using the glulookAt function (left or right)
GLfloat rotLy = 0.0f; // Translate screen by using the glulookAt function (up or down)
GLfloat rotLz = 0.0f; // Translate screen by using the glulookAt function (zoom in or out)
bool flagEjes = true;

void drawLines(){
    if(flagEjes){
        glBegin( GL_LINES );
            glColor3f ( 1.0f, 0.0f, 0.0f );  // red
            glVertex3f( -1.0f, 0.0f, 0.0f );
            glVertex3f( 1.0f, 0.0f, 0.0f );  // horizontal segment

            glColor3f ( 0.0f, 1.0f, 0.0f );  // green
            glVertex3f( 0.0f, -1.0f, 0.0f );
            glVertex3f( 0.0f, 1.0f, 0.0f );  // vertical segment

            glColor3f ( 0.0f, 0.0f, 1.0f );  // blue
            glVertex3f( 0.0f, 0.0f, -1.0f );
            glVertex3f( 0.0f, 0.0f, 1.0f );  // oblique segment
        glEnd();
    }
}

void drawTurtleVertex3f(){
    int i, n=25;    
    double x[] = { 0.0,  0.1,  0.2,  0.3,  0.4,  0.7,  0.9,  0.8,  0.7,  0.5,  0.7, 0.7, 0.5, 0.7, 0.8, 0.9, 0.7, 0.4, 0.3, 0.2, 0.1, 0.2, 0.25, 0.2, 0.0};
    double z[] = {-0.7, -0.7, -0.8, -0.8, -0.9, -1.0, -0.8, -0.6, -0.6, -0.5, -0.4, 0.0, 0.1, 0.2, 0.2, 0.4, 0.6, 0.5, 0.4, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9};
    glBegin(GL_LINE_LOOP);
        glColor3f ( 0.0f, 0.0f, 0.0f );  // red
        for(i=0; i<n; i++){
            glVertex3f(x[i], 0.0, z[i]);
        }
        for(i=n-1; i>=0; i--){
            glVertex3f(-x[i], 0.0, z[i]);
        }
    glEnd();
}

void drawTurtleVertex3d(){
    int i, n=25;    
    double x[] = { 0.0,  0.1,  0.2,  0.3,  0.4,  0.7,  0.9,  0.8,  0.7,  0.5,  0.7, 0.7, 0.5, 0.7, 0.8, 0.9, 0.7, 0.4, 0.3, 0.2, 0.1, 0.2, 0.25, 0.2, 0.0};
    double z[] = {-0.7, -0.7, -0.8, -0.8, -0.9, -1.0, -0.8, -0.6, -0.6, -0.5, -0.4, 0.0, 0.1, 0.2, 0.2, 0.4, 0.6, 0.5, 0.4, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9};
    glBegin(GL_LINE_LOOP);
        glColor3f ( 0.0f, 0.0f, 0.0f );  // red
        for(i=0; i<n; i++){
            glVertex3f(x[i], 0.0, z[i]);
        }
        for(i=n-1; i>=0; i--){
            glVertex3f(-x[i], 0.0, z[i]);
        }
    glEnd();
}

void drawSphereTurtle(){
    glPushMatrix();
        glTranslated(0.0, 0.9, 0.0);
        glRotatef(90,1.0,0.0,0.0);
        glutWireSphere(0.45, 10, 10);
    glPopMatrix();
    
    glPushMatrix();
        glTranslated(-0.75, 0.5, 0.0);
        glRotatef(90,1.0,0.0,0.0);
        glutWireSphere(0.35, 10, 10);
    glPopMatrix();
    
    glPushMatrix();
        glTranslated(0.75, 0.5, 0.0);
        glRotatef(90,1.0,0.0,0.0);
        glutWireSphere(0.35, 10, 10);
    glPopMatrix();
    
    glPushMatrix();
        glTranslated(-0.75, -0.8, 0.0);
        glRotatef(90,1.0,0.0,0.0);
        glutWireSphere(0.35, 10, 10);
    glPopMatrix();
    
    glPushMatrix();
        glTranslated(0.75, -0.8, 0.0);
        glRotatef(90,1.0,0.0,0.0);
        glutWireSphere(0.35, 10, 10);
    glPopMatrix();
    
    glPushMatrix();
        glTranslated(0.0, -0.2, 0.0);
        glScalef(1.0,1.0,0.5);
        glRotatef(90,1.0,0.0,0.0);
        glutWireSphere(0.90, 30, 30);
    glPopMatrix();
}

void rotation(){
	glRotatef(rotX,1.0,0.0,0.0); // Rotate on x
    glRotatef(rotY,0.0,1.0,0.0); // Rotate on y
    glRotatef(rotZ,0.0,0.0,1.0); // Rotate on z
    glTranslatef(0.0f, 0.0f, 0.0f); 	 // Translates the screen left or right, 
			         // up or down or zoom in zoom out
}

// This function is called whenever the window size is changed
void reshape (int w, int h)
{
    glViewport (0, 0, (GLsizei) w, (GLsizei) h); // Set the viewport
    glMatrixMode (GL_PROJECTION); 	// Set the Matrix mode
    glLoadIdentity (); 
    gluPerspective(60, (GLfloat) w /(GLfloat) h , 1.0, 128.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt (rotLx, rotLy, 3.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0); 
}

void keyboard(unsigned char key, int x, int y){
    switch (key){
        case 'h':
            printf("help\n\n");
            printf("a - mostrar u ocultar los ejes de la figura\n");
            printf("c - Toggle culling\n");
            printf("q/escape - Quit\n");
            printf("1 - Rotar el objeto en x\n");
            printf("2 - Rotar el objeto en y\n");
            printf("u - trasladar cámara arriba\n");
            printf("d - trasladar cámara abajo\n");
            printf("r - trasladar cámara a la derecha\n");
            printf("l - trasladar cámara a la izquierda\n");
            break;
        case '1':
            rotX -= 1.0f;
            break;
        case '2':
            rotY -= 1.0f;
            
            break;
        case 'a':
            flagEjes = !flagEjes;
            break;
        case 'c':
            if (glIsEnabled(GL_CULL_FACE)){
                glDisable(GL_CULL_FACE);
                printf("GL_CULL_FACE is enabled\n");
            }else{
                glEnable(GL_CULL_FACE);
                printf("GL_CULL_FACE is disabled\n");
            }
            break;
        case 'r':
            rotLx -= 0.2f; 
            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
            gluLookAt (rotLx, rotLy, 3.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
            break;
        case 'l':
            rotLx += 0.2f; 
            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
            gluLookAt (rotLx, rotLy, 3.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
            break;
        case 'd':
            rotLy -= 0.2f;
            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
            gluLookAt (rotLx, rotLy, 3.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
            break;
        case 'u': 
            rotLy += 0.2f;
            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
            gluLookAt (rotLx, rotLy, 3.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
            break;
        case 'q':
        case 27:
            exit(0);
            break;
        default:
            break;
    }
    glutPostRedisplay();
}

void display(void) {
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
    glPushMatrix(); 	// It is important to push the Matrix before calling 
						// glRotatef and glTranslatef
    rotation();
    drawLines();
    drawTurtleVertex3f();
    //drawTurtleVertex3d();
    drawSphereTurtle();
    
    glPopMatrix();
    glutSwapBuffers();
}

/*
 * 
 */
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
    glutInitWindowSize(512, 512);
    glutInitWindowPosition(20, 20);
    glutCreateWindow("Tortuga");
    glutReshapeFunc(reshape); 
    glutKeyboardFunc(keyboard);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}



