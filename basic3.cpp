#include<iostream>
#include<GL/glut.h>

using namespace std;

float xi,yi,xj,yj,dx,dy,d;

void MyInit(){
	glClearColor(0,0,0,1);
	glColor3f(1,0,0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,640,0,640);
}

void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
	if (abs(dy)<abs(dx)){
		while (xi<=xj && yi<=yj){
			if(d<0){
				glVertex2f(xi,yi);
				cout<<"("<<xi<<", "<<yi<<")\n";
				xi=xi+1;
				d=d+(2*dy);
			}
			else if(d>=0){
				glVertex2f(xi,yi);
				cout<<"("<<xi<<", "<<yi<<")\n";
				xi=xi+1;
				yi=yi+1;
				d=d+(2*(dy-dx));
			}
		}
	}
	else{
		while (xi<=xj && yi<=yj){
			if(d<0){
				glVertex2f(xi,yi);
				cout<<"("<<xi<<", "<<yi<<")\n";
				yi=yi+1;
				d=d+(2*dy);
			}
			else if(d>=0){
				glVertex2f(xi,yi);
				cout<<"("<<xi<<", "<<yi<<")\n";
				xi=xi+1;
				yi=yi+1;
				d=d+(2*(dx-dy));
			}
		}
	}
	glEnd();
	glFlush();
}

int main(int argC,char **argV){
	cout<<"Hello There!\n";
	cout<<"Enter the 1st point (x1,y1):";
	cin>>xi>>yi;
	cout<<"Enter the 2nd point (x2,y2):";
	cin>>xj>>yj;
	
	dx=(xj-xi);
	dy=(yj-yi);
	d=(2*dy)-dx;
	
	glutInit(&argC,argV);
	glutInitWindowSize(1000,500);
	glutInitWindowPosition(10,10);
	glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
	glutCreateWindow("Bresenham's Line Drawing");
	MyInit();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}