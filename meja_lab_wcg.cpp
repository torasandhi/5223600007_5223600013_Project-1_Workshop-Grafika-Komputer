#define _USE_MATH_DEFINES 
/*
Project 1 Workshop Grafika Komputer
Anggota :
1. Rangga Raisha Syaputra (5223600007)
2. Tora Sandhi Kamulian (5223600013)
*/
#include <iostream>
#include <C:\Users\asus vivobook\OpenGLwrappers\OpenGLwrappers\glew-1.10.0\include\GL\glew.h>
#include <C:\Users\asus vivobook\OpenGLwrappers\OpenGLwrappers\freeglut\include\GL\freeglut.h> 
#include <GL/glut.h>

float sudutRotasi = 0.0f;
const float ROTATION_SPEED = 5.0f;


const GLfloat WARNA_MEJA[] = { 0.7f, 0.7f, 0.7f };        
const GLfloat WARNA_PENUTUP[] = { 0.518f, 0.306f, 0.161f }; 

void inisialisasi() {
    glClearColor(0.0, 0.0, 0.0, 0.0);  
    glEnable(GL_DEPTH_TEST);           
}

void gambarMeja() {
    glRotatef(sudutRotasi, 0.0f, 1.0f, 0.0f);

    glColor3fv(WARNA_MEJA);

    glPushMatrix();
    glTranslatef(0.0, 0.5, 0.0);
    glScalef(2.0, 0.1, 1.5);
    glutSolidCube(1.0);
    glPopMatrix();

    float kakiPosisi[4][2] = { {-0.8, -0.5}, {0.8, -0.5}, {-0.8, 0.5}, {0.8, 0.5} };
    for (int i = 0; i < 4; i++) {
        glPushMatrix();
        glTranslatef(kakiPosisi[i][0], 0.0, kakiPosisi[i][1]);
        glScalef(0.1, 1.0, 0.1);
        glutSolidCube(1.0);
        glPopMatrix();
    }

    glColor3fv(WARNA_PENUTUP);
    glPushMatrix();
    glTranslatef(0.0, 0.25, -0.5);
    glScalef(1.5, 0.5, 0.05);
    glutSolidCube(1.0);
    glPopMatrix();
}

void tampilan() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    gluLookAt(3.0, 2.0, 3.0,  
        0.0, 0.0, 0.0,  
        0.0, 1.0, 0.0); 

    gambarMeja();
    glutSwapBuffers();
}

void ubahUkuranLayar(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (float)w / (float)h, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

void keyboard(int key, int x, int y) {
    switch (key) {
    case GLUT_KEY_LEFT:
        sudutRotasi -= ROTATION_SPEED;
        break;
    case GLUT_KEY_RIGHT:
        sudutRotasi += ROTATION_SPEED;
        break;
    }

    if (sudutRotasi > 360.0f) {
        sudutRotasi -= 360.0f;
    }
    else if (sudutRotasi < 0.0f) {
        sudutRotasi += 360.0f;
    }

    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Rangga & Tora - Meja Lab");

    inisialisasi();

    glutDisplayFunc(tampilan);
    glutReshapeFunc(ubahUkuranLayar);
    glutSpecialFunc(keyboard);

    glutMainLoop();
    return 0;
}
