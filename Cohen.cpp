#include<iostream>
#include<GL/freeglut.h>

using namespace std;

float xmin,xmax,ymin,ymax,xi,yi,xj,yj,m;

void MyInit(){
	glClearColor(0,0,0,1);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,650,0,650);
}


void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	
	glBegin(GL_LINE_LOOP);
		glColor3f(0,1,0);
		glVertex2f(xmin,ymin);
		glVertex2f(xmin,ymax);
		glVertex2f(xmax,ymax);
		glVertex2f(xmax,ymin);
	glEnd();
	
	glBegin(GL_LINES);
		glColor3f(1,0,0);
		glVertex2f(xi,yi);
		glVertex2f(xj,yj);
	glEnd();

	glFlush();
}


int code(float x,float y){
	int c=0;     //0000   center
	if (x<xmin){
		c|=1;    //0001   left
	}
	if (x>xmax){
		c|=2;    //0010   right
	}
	if (y<ymin){
		c|=4;    //0100   bottom
	}
	if (y>ymax){
		c|=8;    //1000    top
	}
	return c;
}

void line(){
	int c1 = code(xi,yi);
	int c2 = code(xj,yj);
	
	while ((c1|c2)>0){
		if (c1==0 && c2==0){
			display();
		}
		else if((c1 & c2)==0){
			int o,p,temp;
			if(c1==0){
				temp = c2;
			}
			else{
				temp = c1;
			}
			
			if (temp & 8){
				o=xi+(ymax-yi)/m,p=ymax;
			}
			else if(temp & 4){
				o=xi+(ymin-yi)/m,p=ymin;
			}
			else if(temp & 1){
				o=xmin,p=yi+m*(xmin-xi);
			}
			else if(temp & 2){
				o=xmax,p=yi+m*(xmax-xi);
			}
		
			if (temp == c1){
				xi=o,yi=p,display();
				c1=code(xi,yi);
			}
			else{
				xj=o,yj=p,display();
				c2=code(xj,yj);
			}
		}
		else{
			glClear(GL_COLOR_BUFFER_BIT);
			glBegin(GL_LINE_LOOP);
			glColor3f(0,1,0);
			glVertex2f(xmin,ymin);
			glVertex2f(xmin,ymax);
			glVertex2f(xmax,ymax);
			glVertex2f(xmax,ymin);
			glEnd();
			glFlush();
		}
	}
}

void mykey(unsigned char key,int,int){
	if(key==' '){
		cout<<"Hello!";
		line();
	}
}

int main(int argC,char **argV){
	cout<<"Hello There!\n";
	xmin=100,xmax=400,ymin=100,ymax=400;
	
	cout<<"Enter the 1st point (x1,y1):";
	cin>>xi>>yi;
	cout<<"Enter the 2nd point (x2,y2):";
	cin>>xj>>yj;
	
	m = (yj-yi)/(xj-xi);
	
	glutInit(&argC,argV);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(800,500);
	glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
	glutCreateWindow("Cohen");
	MyInit();
	glutDisplayFunc(display);
	glutKeyboardFunc(mykey);
	glutMainLoop();
	return 0;
}