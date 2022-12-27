#include<GL/freeglut.h>

void myinit(){
	glClearColor(0,0,0,1);
	glColor3f(1,0,0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,800,0,500);
}

void dis(){
	glClear(GL_COLOR_BUFFER_BIT);
	glTranslatef(50,50,0);
	glBegin(GL_POLYGON);
	glVertex2f(50,100);
	glVertex2f(200,100);
	glVertex2f(200,300);
	glVertex2f(50,300);
	glEnd();
	glFlush();
}

int main(int c,char** v){
	glutInit(&c,v);
	glutCreateWindow("2d translation");
	myinit();
	glutDisplayFunc(dis);
	glutMainLoop();
	return 0;
}