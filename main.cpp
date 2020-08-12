#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
void circle(GLfloat rx,GLfloat ry,GLfloat cx,GLfloat cy)
{
    glBegin(GL_POLYGON);
    glVertex2f(cx,cy);
    for(int i=0; i<=360; i++)
    {
        float angle = i*3.1416/180;
        float x = rx * cos(angle);
        float y = ry * sin(angle);
        glVertex2f((x+cx),(y+cy));
    }
    glEnd();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);
    glPushMatrix();
    glTranslatef(0,0,0);
    circle(5,5,0,0);
    glPopMatrix();

    glColor3f(1.0,1.0,1.0);
    glPushMatrix();
    glTranslatef(2,2,0);
    circle(5,5,0,0);
    glFlush();
}
void init()
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-12,12,-12,12,-12,12);
}
int main()
{
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Half-Moon");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
