#define _USE_MATH_DEFINES 

/*
Project 1 Workshop Grafika Komputer
Anggota : 
1. Rangga Raisha Syaputra (5223600007)
2. Tora Sandhi Kamulian (5223600013)

Object Meja

*/

#include <iostream>
#include <C:\Users\asus vivobook\OpenGLwrappers\OpenGLwrappers\glew-1.10.0\include\GL\glew.h>
#include <C:\Users\asus vivobook\OpenGLwrappers\OpenGLwrappers\freeglut\include\GL\freeglut.h> 

#include <GL/glut.h>

float sudutRotasi = 0.0f;

void inisialisasi() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    // Pengaturan cahaya
    GLfloat posisi_cahaya[] = { 1.0, 1.0, 1.0, 0.0 };
    GLfloat cahaya_putih[] = { 1.0, 1.0, 1.0, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, posisi_cahaya);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, cahaya_putih);
}

void gambarMeja() {
    GLfloat abu_abu[] = { 0.7, 0.7, 0.7, 1.0 };
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, abu_abu);

    // TRANSFORMASI 1: Rotasi seluruh meja
    glRotatef(sudutRotasi, 0.0f, 1.0f, 0.0f);

    // Gambar permukaan meja
    glPushMatrix();
    // TRANSFORMASI 2: Translasi untuk permukaan meja
    glTranslatef(0.0, 0.5, 0.0);
    // TRANSFORMASI 3: Penskalaan untuk permukaan meja
    glScalef(2.0, 0.1, 1.5);
    glutSolidCube(1.0);
    glPopMatrix();

    // Gambar kaki-kaki meja dengan transformasi individual
    // Kaki 1
    glPushMatrix();
    // TRANSFORMASI 4: Translasi untuk kaki meja 1
    glTranslatef(-0.8, 0.0, -0.5);
    // TRANSFORMASI 5: Penskalaan untuk kaki meja
    glScalef(0.1, 1.0, 0.1);
    glutSolidCube(1.0);
    glPopMatrix();

    // Kaki 2
    glPushMatrix();
    glTranslatef(0.8, 0.0, -0.5);
    glScalef(0.1, 1.0, 0.1);
    glutSolidCube(1.0);
    glPopMatrix();

    // Kaki 3
    glPushMatrix();
    glTranslatef(-0.8, 0.0, 0.5);
    glScalef(0.1, 1.0, 0.1);
    glutSolidCube(1.0);
    glPopMatrix();

    // Kaki 4
    glPushMatrix();
    glTranslatef(0.8, 0.0, 0.5);
    glScalef(0.1, 1.0, 0.1);
    glutSolidCube(1.0);
    glPopMatrix();
}

void tampilan() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // PERSPEKTIF 3D: Pengaturan posisi kamera dan pandangan
    gluLookAt(3.0, 2.0, 3.0,  // Posisi mata
        0.0, 0.0, 0.0,  // Titik yang dilihat
        0.0, 1.0, 0.0); // Vektor atas

    gambarMeja();

    glutSwapBuffers();
}

// PERSPEKTIF 3D: Implementasi proyeksi perspektif
void ubahUkuranLayar(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    // PERSPEKTIF 3D: Pengaturan proyeksi perspektif
    gluPerspective(45.0, (float)w / (float)h, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

void perbarui(int nilai) {
    sudutRotasi += 2.0f;
    if (sudutRotasi > 360.0f) {
        sudutRotasi -= 360.0f;
    }
    glutPostRedisplay();
    glutTimerFunc(16, perbarui, 0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Rangga & Tora - Meja Lab");

    inisialisasi();

    glutDisplayFunc(tampilan);
    glutReshapeFunc(ubahUkuranLayar);
    glutTimerFunc(0, perbarui, 0);

    glutMainLoop();
    return 0;
}