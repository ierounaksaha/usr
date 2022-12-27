#include<iostream>
#include<GL/freeglut.h>
#include<cmath>

using namespace std;

void myinit(){
	glClearColor(0,0,0,1);
	glColor3f(1,0,0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,800,0,500);
}

void circle(float rx,float ry,float cx,float cy){
	for(int i=0;i<=100;i++){
		float an=2*3.1416*i/100;
		float x=rx*cosf(an);
		float y=ry*sinf(an);
		glVertex2f(x+cx,y+cy);
	}
}

void dis(){
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_TRIANGLE_FAN);
	circle(400,400,100,100);
	glEnd();
	glFlush();
}

int main(int c,char** v){
	cout<<"Hello!";
	glutInit(&c,v);
	glutInitWindowSize(800,500);
	glutInitWindowPosition(100,100);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutCreateWindow("Circle");
	myinit();
	glutDisplayFunc(dis);
	glutMainLoop();
	return 0;
}