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

float xtest[8]={0,850,20,0,13,857,100,800};
//float xtest[8]={200,200,200,200,200,200,200,200s};
float ytest[8]={121,171,221,271,327,377,427,477};
float speedtest[8]={0.4,-0.3,0.45,0,0.42,-0.52,0.47,-0.56};
//float speedtest[8]={0,0,0,0,0,0,0,0};
//float width[8]={120,130,140,windowWidth,150,127,127,120};
float width[8]={170,170,170,windowWidth,170,177,167,160};
int attachedbox=-1;


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
	for(int a=121;a<=600;a+=50)
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

	for(int j=0;j<8;j++)	//All Boxes
		{
			glVertex3f(xtest[j],ytest[j]-25,0);
			glVertex3f(xtest[j]+width[j],ytest[j]-25,0);
			glVertex3f(xtest[j]+width[j],ytest[j]+25,0);
			glVertex3f(xtest[j],ytest[j]+25,0);

		}

		
		glColor3f(0.30,0.70,0.30);	
		glVertex3f(0,101,0);	// bottom area
		glVertex3f(windowWidth,101,0);
		glVertex3f(windowWidth,0,0);
		glVertex3f(0,0,0);

		glColor3f(0.10,0.80,0.50);	
		glVertex3f(0,246,0);		// middle area
		glVertex3f(windowWidth,246,0);
		glVertex3f(windowWidth,306,0);
		glVertex3f(0,306,0);

		glColor3f(0.10,0.90,0.20);	
		glVertex3f(0,502,0);	// top area
		glVertex3f(windowWidth,502,0);
		glVertex3f(windowWidth,windowHeight,0);
		glVertex3f(0,windowHeight,0);

		glColor3f(1.0,1.0,1.0);

	}
	glEnd();
	}

	int xtemp=x;
	if(attach==1)
	{
		x=xtest[attachedbox]+dx;
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
		for(int j=0;j<8;j++)
		{
			xtest[j]=xtest[j]+speedtest[j];
		}

		// making boxes continues ones
		for(int j=0;j<8;j++)
		{
			if(xtest[j]>900)
			{xtest[j]=0;}
			else if(xtest[j]<0)
				{xtest[j]=900;}

		}
		
		//Game over conditions
		if((y>121-25 &&  y<246) || (y>306 && y<502))
		{
			if(attach==0) 
			{
				cout<<"Game Over\n";
				x=450,y=60;
			}
		}
		if((y>=246)&&(y<=306)||(y>802))	// middle area is safe zone
		{
			attach=1;
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
		{play=1; glutIdleFunc(againDisplay); if(x>=560){x=450; y=60;}  }
		else {play=0; glutIdleFunc(NULL);}	// In  pause also players can move
	}

int flag=0;
	
	for(int j=0;j<8;j++)
	{	// that's the best place to make this...
		
	
		if ((y>=ytest[j]-25 && y<=ytest[j]+25 )&&( xtest[j]<=x && xtest[j]+width[j]>=x))		
		{
			dx=x-xtest[j];
			if(dx<0) dx=-dx;
			cout<<"attach=1\n";
			attach=1;
			flag=1;
			attachedbox=j;
			cout<<"You are on "<<j<<" - box. and attachedbox is "<<attachedbox<<"\n";
			
			break;

		}else {cout<<"y "<<y<<" ytest "<<ytest[j]<<" j "<<j<<"\n";}

	}

	if(flag==0) {attach=0; cout<<"x: "<<x<<" y: "<<y<<" and Attach1=0\n";} 

	/*
	float xtest[7]={0,850,20,13,857,100,800};
	float ytest[7]={121,171,221,327,377,427,477};
	*/

	//Game win condition
		if(y>=560)
		{
			cout<<"YOU WON\n"; play=0; glutIdleFunc(NULL);
		}

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
