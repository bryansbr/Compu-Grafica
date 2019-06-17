/*

Nombre del archivo: main.cpp
Fecha de creación: 11/06/2019
Fecha de modificación: 17/06/2019
Autor: Bryan Steven Biojó R. 1629366-3743

*/

/* LIBRERÍAS.
   Para Windows: Descomentar la linea #include <windows.h>
   Para Linux: Descomentar la linea #include <cstdlib>
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
// #include <windows.h>
// #include <cstdlib>
#include "GL/glut.h" // Añadir la palabra 'free' en esta linea si es necesario. -> #include "GL/freeglut.h"
#include "GL/gl.h"

using namespace std;

// Variables booleanas: mostrar (show), plano (plain), eje (eje) y esfera(sphere).
bool show = true;
bool plain = true;
bool eje = true;
bool sphere = true;

// Eje z.
double z[] = {0.0, 2.0, 2.0, 1.0, 1.0, 1.0, 1.0, 3.0, 3.0, 4.0, 4.0, 6.0, 6.0, 7.0, 7.0, 6.0, 6.0, 3.0, 3.0,
              5.0, 5.0, 5.0, 5.0, 3.0, 3.0, 6.0, 6.0, 7.0, 7.0, 5.0, 5.0, 3.0, 3.0, 2.0, 2.0, 0.0};

// Eje x.
double x[] = {11.0, 9.0, 9.0, 7.0, 7.0, 6.0, 6.0, 6.0, 6.0, 7.0, 7.0, 8.0, 8.0, 7.0, 7.0, 4.0, 4.0, 3.0, 3.0,
              1.0, 1.0, -1.0, -1.0, -3.0, -3.0, -5.0, -5.0, -7.0, -7.0, -9.0, -9.0, -8.0, -8.0, -7.0, -7.0 ,-6.0};

// Variables GLfloat iniciales.
GLfloat x0 = 0.0;
GLfloat y0 = 0.0;
GLfloat z0 = 20.0;

// Método para dibujar la tortuga.
void drawTurtle(void) {
    if (show) {
        glColor3f(1.0, 0.0, 0.0);
        glBegin(GL_LINES);

        for (int i = 0; i < 36; i += 2) {
            glVertex3d(z[i], x[i], 0.0);
            glVertex3d(z[i+1], x[i+1], 0.0);
            glVertex3d(z[i]*-1, x[i], 0.0);
            glVertex3d(z[i+1]*-1, x[i+1], 0.0);
        }
        glEnd();
    }
}

// Método para dibujar la esfera de la tortuga.
void SphereTurtle(void) {
    glPushMatrix();
    glColor3f(0.0, 0.0, 0.0);
    glutWireSphere(5.0, 50, 50);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(5.0, 5.0, 0.0);
    glColor3f(0.0, 0.0, 0.0);
    glutWireSphere(2.5, 20, 20);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-5.0 ,5.0, 0.0);
    glColor3f(0.0, 0.0, 0.0);
    glutWireSphere(2.5, 20, 20);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-4.0, -6.0, 0.0);
    glColor3f(0.0, 0.0, 0.0);
    glutWireSphere(2.5, 20, 20);
    glPopMatrix();

    glPushMatrix();
    glTranslated(4.0, -6.0, 0.0);
    glColor3f(0.0, 0.0, 0.0);
    glutWireSphere(2.5, 20, 20);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.0, 7.0, 0.0);
    glColor3f(0.0, 0.0, 0.0);
    glutWireSphere(2.5, 20, 20);
    glPopMatrix();
}

// Método para dibujar el escenario inicial.
void drawMain(void){
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    if (plain)
        drawTurtle();

    if (sphere)
        SphereTurtle();

    if (eje) {
        // Se pinta el eje rojo (R).
        glColor3f(1.0 ,0.0, 0.0);
        glBegin(GL_LINES);
        glVertex3f(800.0, 0.0, 0.0);
        glVertex3f(-800.0, 0.0, 0.0);
        glEnd();

        //Se pinta el eje verde (G).
        glColor3f(0.0, 1.0, 0.0);
        glBegin(GL_LINES);
        glVertex3f(0.0, 800.0, 0.0);
        glVertex3f(0.0, -800.0, 0.0);
        glEnd();

        //Se pinta el eje azul (B).
        glColor3f(0.0, 0.0, 1.0);
        glBegin(GL_LINES);
        glVertex3f(0.0, 0.0, 800.0);
        glVertex3f(0.0, 0.0, -800.0);
        glEnd();
    }
    glutSwapBuffers();
}

// Método para remodelar.
void reshape(int width, int height) {
    if (width < height) {
        glViewport(0, 0, width, width);
    } else {
        glViewport(0, 0, height, height);
    }

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, 1.0, 1.0, 128.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(x0, y0, z0, 0.0 , 0.0, 0.0, 0.0, 1.0, 0.0);
}

// Método para controlar la tortuga mediante el teclado.
void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 'h':
            printf("help\n\n");
            printf("c - Toggle culling\n");
            printf("q/escape - Quit\n\n");
            break;

        case 'c':
            if (glIsEnabled(GL_CULL_FACE)) {
                glDisable(GL_CULL_FACE);
            } else {
                glEnable(GL_CULL_FACE);
            }
            break;

        case '6':
            glRotatef(1.0, 0.0, 1.0, 0.0);
            break;

        case '2':
            glRotatef(1.0, 1.0, 0.0, 0.0);
            break;

        case '8':
            glRotatef(1.0, -1.0, 0.0, 0.0);
            break;

        case '4':
            glRotatef(1.0, 0.0, -1.0, 0.0);
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
            y0 += 0.1;
            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
            gluLookAt(x0, y0, z0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
            break;

        case 'd':
            y0 -= 0.1;
            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
            gluLookAt(x0, y0, z0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
            break;

        case 'l': // Left.
            x0 += 0.1;
            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
            gluLookAt(x0, y0, z0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
            break;

        case 'r': // Right
            x0 -= 0.1;
            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
            gluLookAt(x0, y0, z0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
            break;

        case 'q': // Close. Cerrar la ventana siempre presionando la tecla 'q' en el teclado y no directamente.

        case 27:
            exit(0);
            break;
    }
    glutPostRedisplay();
}

// Método main.
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
    glutInitWindowSize(512, 512);
    glutInitWindowPosition(20, 20);
    glutCreateWindow("Super Tortuga");
    glutDisplayFunc(drawMain);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();

    return 0;
}
