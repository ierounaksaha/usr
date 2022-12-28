#include<iostream>
#include<GL/freeglut.h>
#include<cmath>

using namespace std;

float phi;
void myinit(){
	glClearColor(0,0,0,1);
	glColor3f(1,0,0);
	gluOrtho2D(-500,800,0,800);
}

float x(float a,float b){
	return a*cosf(phi)-b*sinf(phi);
}


float y(float a,float b){
	return a*sinf(phi)+b*cosf(phi);
}

void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINE_LOOP);
	glColor3f(1,0,0);
	glVertex2f(50,100);
	glVertex2f(200,100);
	glVertex2f(200,300);
	glVertex2f(50,300);
	glEnd();
	
	glBegin(GL_LINE_LOOP);
	glColor3f(0,1,0);
	glVertex2f(x(50,100),y(50,100));
	glVertex2f(x(200,100),y(200,100));
	glVertex2f(x(200,300),y(200,300));
	glVertex2f(x(50,300),y(50,300));
	glEnd();
	glFlush();
}

int main(int c,char** v){
	cout<<"Hello!\n";
	cout<<"Enter the rotation angle : ";
	cin>>phi;
	glutInit(&c,v);
	glutInitWindowSize(800,500);
	glutInitWindowPosition(100,100);
	glutCreateWindow("2D rotation");
	myinit();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}