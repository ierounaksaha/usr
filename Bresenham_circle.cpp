#include<iostream>
#include<GL/glut.h>

using namespace std;

float xc,yc,r,x,y,d;

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
		if(d<=0){
			d=d+4*x+6;
		}
		else{
			d=d+4*(x-y)+10;
			y=y-1;
		}
		x=x+1;
	}
	glEnd();
	glFlush();
}

int main(int argC, char **argV){
	cout<<"Hello World!\n";
	cout<<"Enter the center point (x,y) : ";
	cin>>xc>>yc;
	cout<<"Enter the radius of the circle : ";
	cin>>r;
	
	x=0,y=r;
	d=3-2*r;
	
	glutInit(&argC,argV);
	glutInitWindowSize(800,500);
	glutInitWindowPosition(100,100);
	glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
	glutCreateWindow("Bresenham's circle drawing algorithm");
	MyInit();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}