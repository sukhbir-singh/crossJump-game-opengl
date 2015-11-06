#include "iostream"
#include "stdlib.h"
#include "GL/freeglut.h"
#include "GL/gl.h"
using namespace std;

int play=0;	// game's pause and play state
int pausevariable=180;
int movedown=0;
int windowWidth=900,windowHeight=600;
float x=450,y=80;	// (x,y) are the mid point of square
float xtest=0,ytest=121,speedtest=7;
int attach=0;	// wheather to attach user with box or not
float dx=0.0; // distance between player and inside box


void init(void)
{
   glClearColor(0.0,0.0,0.0,0.0);	// rgb color to clean with
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(0.0f,windowWidth,0.0f,windowHeight,0.0f,1.0f);
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);	// clear color buffer
	
	
	glColor3f(1.0,1.0,1.0);
	// BASIC LINES --WHITE
	glBegin(GL_LINES);
	for(int a=100;a<=600;a+=100)
	{
	   glVertex3i(0,a,0);
	   glVertex3i(900,a,0);	
	}
	glEnd();


	//BOXES
	if(play)
	{
	glBegin(GL_QUADS);

	{
		glVertex3f(xtest,ytest-20,0);
		glVertex3f(xtest+80,ytest-20,0);
		glVertex3f(xtest+80,ytest+20,0);
		glVertex3f(xtest,ytest+20,0);
		
				
	}
	glEnd();
	}

	int xtemp=x;
	if(attach==1)
	{
		x=xtest+dx;
		//cout<<"xtest "<<xtest<<" x"<<x<<"\n";
	}



	//PLAYER BOX -- ORANGE wasd
	glColor3f(0.53,0.224,0.100);	// set color
	glBegin(GL_POLYGON);
	glVertex3f(x-15,y-15,0);
	glVertex3f(x+15,y-15,0);
	glVertex3f(x+15,y+15,0);
	glVertex3f(x-15,y+15,0);
	glEnd();

	//x=xtemp;

	glFlush();					// forces drawing to complete
}

void reshape(int w, int h)
{
	windowHeight=h;
	windowWidth=w;
glViewport(0, 0, (GLsizei) w, (GLsizei) h);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(0.0,(GLdouble)w,0.0,(GLdouble)h,0.0,1.0);
}

void againDisplay()
{
		xtest=xtest+0.4;
		if(xtest>=850)
			{xtest=0;}



		
	glutPostRedisplay();
}

//For keyboard, p for pause 
// 112 for 'p' and 32 for 'space'
void key(unsigned char key,int xm,int ym)
{

	//cout<<"KEY.... ";

	if(key==97)
	{x=x-9;	}
	else if(key==119)
		{y=y+9;}
	else if(key==100)
		{x=x+9; }
	else if(key==115)
		{y=y-9; }
	else if(key==112) 	// Game pause and play using key 'p'
	{ 	cout<<"Game Starts";
		if(play==0) 
		{play=1; glutIdleFunc(againDisplay); x=450,y=80;}
		//else {play=0; glutIdleFunc(NULL);}
	}


	if ((y>=106 && y<=151)&&(xtest<=x && xtest+80>=x))
		{
			dx=x-xtest;
			cout<<"attach =1\n";
			attach=1;

		}else {attach=0; cout<<"attach =0\n";}
	
	
	

}


int main(int argc,char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(windowWidth,windowHeight);
	glutInitWindowPosition(40,20);
	glutCreateWindow("CrossJump");

	init();

	cout<<"CrossJump starts\n";

	glutReshapeFunc(reshape);	// when window is resized redraw the shape with same coordinates.
	glutDisplayFunc(display);
	//glutMouseFunc(mouse);
	glutKeyboardFunc(key);

	glutMainLoop();
	return 0;
}
