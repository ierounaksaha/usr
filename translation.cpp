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
	glBegin(GL_POLYGON);
	glColor3f(1,0,0);
	glVertex2f(50,100);
	glVertex2f(200,100);
	glVertex2f(200,300);
	glVertex2f(50,300);
	glEnd();
	
	glBegin(GL_POLYGON);
	glColor3f(0,1,0);
	glVertex2f(50+tx,100+ty);
	glVertex2f(200+tx,100+ty);
	glVertex2f(200+tx,300+ty);
	glVertex2f(50+tx,300+ty);
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
