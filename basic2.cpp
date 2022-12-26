#include<iostream>
#include<GL/glut.h>
#include<cmath>

using namespace std;

float x1,x2,yi,y2,m;

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
	if (abs(m)<1){
		while (x1<=x2 && yi<=y2){
			glVertex2f(round(x1),round(yi));
			cout<<"("<<round(x1)<<", "<<round(yi)<<")\n";
			x1=x1+1;
			yi=yi+m;
		}
	}
	else if (abs(m)>1){
		while (x1<=x2 && yi<=y2){
			glVertex2f(round(x1),round(yi));
			cout<<"("<<round(x1)<<", "<<round(yi)<<")\n";
			x1=x1+(1/m);
			yi=yi+1;
		}
	}
	else if (abs(m)==1){
		while (x1<=x2 && yi<=y2){
			glVertex2f(round(x1),round(yi));
			cout<<"("<<round(x1)<<", "<<round(yi)<<")\n";
			x1=x1+1;
			yi=yi+1;
		}
	}
	glEnd();
	
	glFlush();
}

int main(int argC,char **argV){
	cout<<"Hello World!\n";
	cout<<"Enter the 1st point (x1,y1):";
	cin>>x1>>yi;
	cout<<"Enter the 2nd point (x2,y2):";
	cin>>x2>>y2;
	
	m=(y2-yi)/(x2-x1);
	
	glutInit(&argC,argV);
	glutInitWindowSize(1500,700);
	glutInitWindowPosition(0,0);
	glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
	glutCreateWindow("DDA Algorithm");
	MyInit();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}