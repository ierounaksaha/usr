#include<iostream>
#include<GL/freeglut.h>

using namespace std;

float xc,yc,x,y,r,p;

void MyInit(){
	glClearColor(0,0,0,1);
	glColor3f(1,0,0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,800,0,500);
}

void circle(){
	glVertex2f(xc+x,yc+y);
	glVertex2f(xc+x,yc-y);
	glVertex2f(xc-x,yc+y);
	glVertex2f(xc-x,yc-y);
	glVertex2f(xc+y,yc+x);
	glVertex2f(xc+y,yc-x);
	glVertex2f(xc-y,yc+x);
	glVertex2f(xc-y,yc-x);
}

void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
	while(x<=y){
		circle();
		x=x+1;
		if(p<0){
			p=p+1+2*x;
		}
		else{
			y=y-1;
			p=p+1+(2*x)-(2*y);
		}
	}
	glEnd();
	glFlush();
}

int main(int argc,char **argv){
	cout<<"Hello World!\n";
	cout<<"Enter the center point of the circle : ";
	cin>>xc>>yc;
	cout<<"Enter the radius of the circle : ";
	cin>>r;
	
	x=0,y=r;
	p=(5/4)-r;
	
	glutInit(&argc,argv);
	glutInitWindowSize(800,500);
	glutInitWindowPosition(100,100);
	glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
	glutCreateWindow("Mid-Point circle");
	MyInit();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}