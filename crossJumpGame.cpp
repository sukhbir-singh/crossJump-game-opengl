#include "iostream"
#include "stdlib.h"
#include "GL/freeglut.h"
#include "GL/gl.h"
using namespace std;

int play=0;	// game's pause and play state
int pausevariable=180;
int movedown=0;
int windowWidth=900,windowHeight=600;
float x=450,y=60;	// (x,y) are the mid point of square
//float xtest=0,ytest=121,speedtest=0.4;

int attach=0;	// wheather to attach user with box or not
float dx=0.0; // distance between player and inside box

float xtest[7]={0,850,20,13,857,100,800};
float ytest[7]={121,171,221,327,377,427,477};
float speedtest[7]={0.4,-0.3,0.45,0.42,-0.52,0.47,-0.56};
float width[7]={80,100,90,120,97,70,85};


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
	//if(play)
	{
	glBegin(GL_QUADS);
	{
		for(int j=0;j<7;j++)
		{
			glVertex3f(xtest[j],ytest[j]-25,0);
			glVertex3f(xtest[j]+width[j],ytest[j]-25,0);
			glVertex3f(xtest[j]+width[j],ytest[j]+25,0);
			glVertex3f(xtest[j],ytest[j]+25,0);

		}

		glColor3f(0.50,0.50,0.50);	

		glVertex3f(0,246,0);
		glVertex3f(windowWidth,246,0);
		glVertex3f(windowWidth,306,0);
		glVertex3f(0,306,0);

		glColor3f(1.0,1.0,1.0);

	}
	glEnd();
	}

	int xtemp=x;
	if(attach==1)
	{
		x=xtest[0]+dx;
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
		//	xtest=xtest+speedtest;
		for(int j=0;j<7;j++)
		{
			xtest[j]=xtest[j]+speedtest[j];
		}

		// making boxes continues ones
		for(int j=0;j<7;j++)
		{
			if(xtest[j]>900)
			{xtest[j]=0;}
			else if(xtest[j]<0)
				{xtest[j]=900;}

		}
		
		//game over conditions
		if(y>106)
		{
			if(attach==0) 
			{
				cout<<"Game Over\n";
				x=450,y=60;
			}
		}


		
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
		{play=1; glutIdleFunc(againDisplay); }
		else {play=0; glutIdleFunc(NULL);}	// In  pause also players can move
	}


	if ((y>=101 && y<=155)&&(xtest[0]<=x && xtest[0]+80>=x))		// that's the best place to make this...
		{
			dx=x-xtest[0];
			cout<<"attach=1\n";
			attach=1;

		}else {attach=0; cout<<"attach=0\n";}
	
	

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
