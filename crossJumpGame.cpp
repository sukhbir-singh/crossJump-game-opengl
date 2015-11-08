//Copyright@Sukhbir_Singh-14MI535 NIT-HAMIRPUR
//Game Title: CrossJump-2Player

#include "iostream"
#include "stdlib.h"
#include "GL/freeglut.h"
#include "GL/gl.h"
using namespace std;

int playerwins=0;	// hold value corresponding to player wins
int play=0;	// game's pause and play state
int windowWidth=900,windowHeight=600;
float x=410,y=60;	// (x,y) are the mid point of square
//float xtest=0,ytest=121,speedtest=0.4;

int initialDisplay=1;
int attach=0;	// wheather to attach user with box or not
float dx=0.0; // distance between player and inside box

float xtest[8]={0,850,20,0,13,857,100,800};
float ytest[8]={121,171,221,271,327,377,427,477};
float speedtest[8]={0.45,-0.27,0.630,-0,0.76,-0.29,0.73,-0.68};	// BEST SETTINGS TILL NOW
float width[8]={170,170,170,windowWidth,180,177,167,180};	// best settings

int attachedbox=-1;

//--------for second player---------
float x1=450,y1=60;
int attach1=0;
float dx1=0.0;
int attachedbox1=-1;


int firsttime=0;

void drawBitmapText(const char *string,float x,float y,float z) ;

void init(void)
{
   glClearColor(0.0,0.0,0.0,0.0);	// rgb color to clean with
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(0.0f,windowWidth,0.0f,windowHeight,0.0f,1.0f);
   playerwins=0;

}

void drawBitmapText(const char *string,float x,float y,float z)
{  // To write text on screen
    const char *c;
    glRasterPos3f(x, y,z);

    for (c=string; *c != '\0'; c++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
    }
}


void drawBitmapText1(const char *string,float x,float y,float z)
{  // To write text on screen
    const char *c;
    glRasterPos3f(x, y,z);

    for (c=string; *c != '\0'; c++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *c);
    }
}


void display(void)
{

	glClear(GL_COLOR_BUFFER_BIT);	// clear color buffer

	
if(initialDisplay==1){

	/*
	CrossJump Game

	Introduction: 
	 CrossJump is a two player WIN-LOSE game. It consists of 5 Levels of difficulty (which can be selected by 
	 pressing any of the keys between 1 to 5 during pause screen), Player to cross the finishing line 'FIRST' 
	 will be declared as winner.
	
	How to Play: Both players complete against each other to reach the finishing line as fast as possible.
	Controls(1>> i j k l)(2>> w a s d) of both players is given below. After Starting the Game (any level), 
	Players have to move from Starting platform to Middle playform (known as SAFE ZONE) to Destination Platform.
	 During your Travel, you have to pass over only White trains, if you fall in black area that is out of any
	 train then your player restarts from initial position. 

	Players:
	 Player1 is of 'RED' color and Player2 is of 'BLUE' color. ---diagram

	Controls: Player1 can move around the area using keys i(UP), j(LEFT), l(RIGHT), k(DOWN)
	Player2 can move around the area using keys w(UP), a(LEFT), d(RIGHT), s(DOWN)
	Note: Players can press keys for testing at current screen.

	Pause Button: 'p' key is used to Pause, Resume, or For selecting different levels during the gamePlay.
	Important:- After winning the game, by pressing 'p' game will restart. 

	Levels: Game consists of 5 Levels of varying difficulty. Levels can be selected by pressing any of the keys
	1,2,3,4,5 during Pause screen (Pause screen appears when 'p' is pressed during gameplay.)
	
	At last, HAPPY GAMING!#@!

	*/

	
	glColor3f(1.0,1.0,1.0);
	drawBitmapText("CrossJump Game",375,565,0);
	glBegin(GL_LINES);
	glVertex3f(356,560,0);
	glVertex3f(545,560,0);
	glEnd();
	
	drawBitmapText("Introduction:",30,540,0);
	drawBitmapText1("CrossJump is a two player WIN-LOSE game. It consists of 5 Levels of difficulty (which can be selected by pressing any of the keys between",30,520,0);
	drawBitmapText1("1 to 5 during pause screen), Player to cross the finishing line 'FIRST' will be declared as winner.",30,502,0);
	drawBitmapText("How to Play:",30,470,0);
	drawBitmapText1("Both players complete against each other to reach the finishing line as fast as possible. Controls(1>> i j k l)(2>> w a s d) of both players is given",30,450,0);
	drawBitmapText1("below. After Starting the Game (any level), Players have to move from Starting platform to Middle playform (known as SAFE ZONE) to Destination",30,432,0);
	drawBitmapText1("Platform. During your Travel, you have to pass over only White trains, if you fall in black area that is out of any train then your player restarts",30,415,0);
	drawBitmapText1("from initial position.",30,397,0); 
	
	int temp=20;
	drawBitmapText("Players:",30,385-temp,0);
	drawBitmapText1("Player1 is of 'RED' color and Player2 is of 'BLUE' color.",30,368-temp,0);
	drawBitmapText("Pause Button:",30,338-temp,0);
	drawBitmapText1("'p' key is used to Pause, Resume, or For selecting different levels during the gamePlay.",30,320-temp,0);
	drawBitmapText1("Important:- After winning the game, by pressing 'p' game will restart.",30,300-temp+3,0);

	drawBitmapText("Levels:",30,265-temp+4,0);
	drawBitmapText1("Game consists of 5 Levels of varying difficulty. Levels can be selected by pressing any of the keys 1,2,3,4,5 during Pause screen (Pause screen ",30,240-temp+10,0);
	drawBitmapText1("appears when 'p' is pressed during gameplay.)",30,220-temp+13,0);	
	
	drawBitmapText("Controls:",30,189-temp+4,0);
	drawBitmapText1("Player1 can move around the area using keys i(UP), j(LEFT), l(RIGHT), k(DOWN)",30,160-temp+16,0);
	drawBitmapText1("Player2 can move around the area using keys w(UP), a(LEFT), d(RIGHT), s(DOWN)",30,142-temp+16,0);
	
	drawBitmapText("At last, HAPPY GAMING!#@!     <Select A Level and Start Play...>",30,100,0);
		
	x=600,y=340;
	x1=640,y1=340;

		//PLAYER1 BOX -- ORANGE wasd
	glColor3f(0.83,0.224,0.100);	// set color
	glBegin(GL_POLYGON);
	glVertex3f(x-15,y-15,0);
	glVertex3f(x+15,y-15,0);
	glVertex3f(x+15,y+15,0);
	glVertex3f(x-15,y+15,0);
	glEnd();

	//PLAYER2 BOX -- BLUE ijkl
	glColor3f(0.1,.324,0.9);	// set color
	glBegin(GL_POLYGON);
	glVertex3f(x1-15,y1-15,0);
	glVertex3f(x1+15,y1-15,0);
	glVertex3f(x1+15,y1+15,0);
	glVertex3f(x1-15,y1+15,0);
	glEnd();

	glBegin(GL_LINES);
	{ 
		glColor3f(1.0,1.0,1.0);
		int ttx=55,tty=23;

	for(int j=0;j<5;j++)	//All Boxes
		{
			glVertex3f(ttx+10,tty+45,0);
			glVertex3f(ttx+10,tty,0);
			glVertex3f(ttx+10,tty,0);
			glVertex3f(ttx+10+120,tty,0);
			glVertex3f(ttx+10+120,tty,0);
			glVertex3f(ttx+10+120,tty+45,0);
			glVertex3f(ttx+10+120,tty+45,0);
			glVertex3f(ttx+10,tty+45,0);


			ttx+=160;

//			cout<<"coordinates1: ( "<<ttx+10<<","<<tty<<" )\n";
//			cout<<"coordinates2: ( "<<ttx+10+120<<","<<tty+45<<" )\n\n";			
		}
	}
	glEnd();

	drawBitmapText("Level 1",90,38,0);
	drawBitmapText("Level 2",90+160,38,0);
	drawBitmapText("Level 3",90+160+160,38,0);
	drawBitmapText("Level 4",90+160+160+160,38,0);
	drawBitmapText("Level 5",90+160+160+160+160,38,0);

}
else {
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

	//2player
	int xtemp1=x1;
	if(attach1==1)
	{
		x1=xtest[attachedbox1]+dx1;
	}

	glColor3f(0.5,1.0,0.5);
	drawBitmapText("FINISH LINE",windowWidth/2-50,565,0);
	drawBitmapText("Anytime During Game press 'p' and then 1-5 to select Levels between 1 to 5",130,535,0);
	glColor3f(0.30,0.90,0.85);
	drawBitmapText("SAFE ZONE",windowWidth/2-50,(246+306)/2-8,0);

	if(playerwins==0)
	{
		glColor3f(0.80,0.40,0.25);
		drawBitmapText("PLAYER1",150,50,0);
		glColor3f(0.30,0.40,0.85);
		drawBitmapText("PLAYER2",windowWidth/2+200-30,50,0);

		glColor3f(0.80,0.40,0.25);
		drawBitmapText("W",72,67,0);
		drawBitmapText("A",50,50,0);
		drawBitmapText("D",95,50,0);
		drawBitmapText("S",72,30,0);

		glColor3f(0.30,0.40,0.85);
		drawBitmapText("J",windowWidth/2+320-10,50,0);
		drawBitmapText("I",windowWidth/2+345-5,67,0);
		drawBitmapText("K",windowWidth/2+360,50,0);
		drawBitmapText("L",windowWidth/2+345-5,30,0);

		if(firsttime==0)
		{glColor3f(1.0,1.0,1.0);
		drawBitmapText("Hit 'p' to Start/ Pause/ Restart the Game#CrossJump",windowWidth/2-230,13,0);}

	}


	if(playerwins==1)
	{
		glBegin(GL_POLYGON);
		glColor3f(0.83,0.224,0.100);
		glVertex3f(0,246,0);
		glVertex3f(windowWidth,246,0);
		glVertex3f(windowWidth,306,0);
		glVertex3f(0,306,0);
		glEnd();

		glColor3f(1.0,1.0,1.0);
		drawBitmapText("PLAYER1 WINS THE GAME!!!",windowWidth/2-360,(246+306)/2-8,0);

	}
	else if(playerwins==2)
	{
		glBegin(GL_POLYGON);
		glColor3f(0.1,.324,0.9);
		glVertex3f(0,246,0);
		glVertex3f(windowWidth,246,0);
		glVertex3f(windowWidth,306,0);
		glVertex3f(0,306,0);
		glEnd();

		glColor3f(1.0,1.0,1.0);
		drawBitmapText("PLAYER2 WINS THE GAME!!!",windowWidth/2+30,(246+306)/2-8,0);

	}

	//PLAYER1 BOX -- ORANGE wasd
	glColor3f(0.83,0.224,0.100);	// set color
	glBegin(GL_POLYGON);
	glVertex3f(x-15,y-15,0);
	glVertex3f(x+15,y-15,0);
	glVertex3f(x+15,y+15,0);
	glVertex3f(x-15,y+15,0);
	glEnd();

	//PLAYER2 BOX -- BLUE ijkl
	glColor3f(0.1,.324,0.9);	// set color
	glBegin(GL_POLYGON);
	glVertex3f(x1-15,y1-15,0);
	glVertex3f(x1+15,y1-15,0);
	glVertex3f(x1+15,y1+15,0);
	glVertex3f(x1-15,y1+15,0);
	glEnd();

	if(playerwins!=0)
	{
		glColor3f(0.2,0.2,0.2);
		glVertex3f(0,101,0);	// bottom area
		glVertex3f(windowWidth,101,0);
		glVertex3f(windowWidth,0,0);
		glVertex3f(0,0,0);

		glColor3f(1.0,1.0,1.0);
		drawBitmapText("Press 'p' to Restart the Game#CrossJump",windowWidth/2-248,50,0);

	}

	glColor3f(1.0,1.0,0.2);

	glBegin(GL_LINES);
	glVertex3f(0,560,0);
	glVertex3f(windowWidth,560,0);
	glEnd();

}

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
		for(int j=0;j<8;j++)
		{
			xtest[j]=xtest[j]+speedtest[j];
		}

		// making boxes continues ones
		for(int j=0;j<8;j++)
		{
			if(xtest[j]>windowWidth)
			{xtest[j]=0-width[j]+1;}
			else if(xtest[j]<=0-width[j])
				{xtest[j]=windowWidth;}
		}

		//Game over conditions
		if((y>121-25 &&  y<246) || (y>306 && y<502))
		{
			if(attach==0)
			{
				//cout<<"Game Over Player1\n";
				x=410,y=60;

			}
		}
		if((y>=246)&&(y<=306)||(y>802))	// middle area is safe zone
		{
			attach=1;
		}

		//Game over conditions for player2
		if((y1>121-25 &&  y1<246) || (y1>306 && y1<502))
		{
			if(attach1==0)
			{
				//cout<<"Game Over Player2\n";
				x1=450,y1=60;
			}
		}
		if((y1>=246)&&(y1<=306)||(y1>802))	// middle area is safe zone
		{
			attach1=1;
		}



	glutPostRedisplay();
	 }

	void mouse(int button, int state, int x, int y)
	{
		if(initialDisplay==1)
		if(button==GLUT_LEFT_BUTTON)
		{ 
			int check=0;
			int startLevel=0;
			
			if(windowHeight-y>=23 && windowHeight- y<=68)
			{
				cout<<"x,y "<<x<<" "<<y<<"\n";

			    if(x>=65 && x<=184){check=1; startLevel=1;}
				else if(x>=224 && x<=347){check=1; startLevel=2;}
				else if(x>=384 && x<=506){check=1; startLevel=3;}
				else if(x>=545 && x<=665){check=1; startLevel=4;}
				else if(x>705 && x<=828){check=1; startLevel=5;}
	
			}

			int key=0;

			if(check==1)
			{   
				key=startLevel;
				cout<<"initialDisplay= "<<initialDisplay<<"\n";
				initialDisplay=0;	// instruction screen cleans off
				//level=startLevel;
				{play=1; glutIdleFunc(againDisplay); if(y>=560 || y1>=560 ){x=410; y=60; x1=450; y1=60; playerwins=0;}   }
			}

			cout<<key<<"\n";

			if(key==1)
		{
			cout<<"Level1 Selected\n";
			float speedtest1[8]={0.4,-0.38,0.45,0,0.35,-0.42,0.37,-0.46};
			float xtest1[8]={0,800,120,0,30,757,100,800};
			float width1[8]={190,200,180,windowWidth,190,187,197,180};

			for(int m=0;m<8;m++)
			{
				speedtest[m]=speedtest1[m];
				xtest[m]=xtest1[m];
				width[m]=width1[m];
			}

			// copied 'p' condition
			{play=1; glutIdleFunc(againDisplay); if(y>=560 || y1>=560 ){x=410; y=60; x1=450; y1=60; playerwins=0;}   }
		}
		else if(key==2)
		{
			cout<<"Level2 Selected\n";
			float speedtest1[8]={0.30,-0.35,0.40,0,0.45,-0.50,0.55,-0.60};
			float xtest1[8]={0,800,0,0,0,800,0,800};
			float width1[8]={170,179,168,windowWidth,180,177,167,180};

			for(int m=0;m<8;m++)
			{
				speedtest[m]=speedtest1[m];
				xtest[m]=xtest1[m];
				width[m]=width1[m];
			}

			// copied 'p' condition
			{play=1; glutIdleFunc(againDisplay); if(y>=560 || y1>=560 ){x=410; y=60; x1=450; y1=60; playerwins=0;}   }

		}
		else if(key==3)
		{
			//cout<<"Level3 Selected\n";
			float xtest1[8]={0,850,20,0,13,857,100,800};
			float speedtest1[8]={0.45,-0.27,0.630,-0,0.76,-0.29,0.68,-0.60};	// BEST SETTINGS TILL NOW
			float width1[8]={170,170,170,windowWidth,180,177,167,180};	// best settings


			for(int m=0;m<8;m++)
			{
				speedtest[m]=speedtest1[m];
				xtest[m]=xtest1[m];
				width[m]=width1[m];
			}

			// copied 'p' condition
			{play=1; glutIdleFunc(againDisplay); if(y>=560 || y1>=560 ){x=410; y=60; x1=450; y1=60; playerwins=0;}   }
		}
		else if(key==4)
		{
			cout<<"Level4 Selected\n";

			float speedtest1[8]={0.20,-0.50,0.20,0,0.65,-0.28,0.50,-0.99};
			float xtest1[8]={445,445,445,0,445,445,445,445};
			float width1[8]={170,169,168,windowWidth,180,177,167,160};


			for(int m=0;m<8;m++)
			{
				speedtest[m]=speedtest1[m];
				xtest[m]=xtest1[m];
				width[m]=width1[m];
			}

			// copied 'p' condition
			{play=1; glutIdleFunc(againDisplay); if(y>=560 || y1>=560 ){x=410; y=60; x1=450; y1=60; playerwins=0;}   }
		}
		else if(key==5)
		{
			cout<<"Level5 Selected\n";

			float speedtest1[8]={0.70,-1.18,0.70,0,0.65,-1.70,0.85,-1.280};
			float xtest1[8]={140,650,20,0,160,680,50,700};
			float width1[8]={120,110,120,windowWidth,120,110,120,100};


			for(int m=0;m<8;m++)
			{
				speedtest[m]=speedtest1[m];
				xtest[m]=xtest1[m];
				width[m]=width1[m];
			}

			// copied 'p' condition
			{play=1; glutIdleFunc(againDisplay); if(y>=560 || y1>=560 ){x=410; y=60; x1=450; y1=60; playerwins=0;}   }
		}

			
		}
		
	}

//For keyboard, p for pause
// 112 for 'p' and 32 for 'space'
void key(unsigned char key,int xm,int ym)
{
	if(key==97)
	{x=x-9;	}
	else if(key==119)
		{y=y+9;}
	else if(key==100)
		{x=x+9; }
	else if(key==115)
		{y=y-9; }
	else if(key==112) 	// Game pause and play using key 'p'
	{ 	cout<<"Game Starts\n";
		firsttime=1;

		if(play==0)
		{play=1; glutIdleFunc(againDisplay); if(y>=560 || y1>=560 ){x=410; y=60; x1=450; y1=60; playerwins=0;}   }
		else {play=0; glutIdleFunc(NULL);}	// In  pause also players can move
	}

	// 5 Levels , for selecting a level just press 'p' and any key between 1 to 5
	if(play==0)
	{
		if(key=='1')
		{
			cout<<"Level1 Selected\n";
			float speedtest1[8]={0.4,-0.38,0.45,0,0.35,-0.42,0.37,-0.46};
			float xtest1[8]={0,800,120,0,30,757,100,800};
			float width1[8]={190,200,180,windowWidth,190,187,197,180};

			for(int m=0;m<8;m++)
			{
				speedtest[m]=speedtest1[m];
				xtest[m]=xtest1[m];
				width[m]=width1[m];
			}

			// copied 'p' condition
			{play=1; glutIdleFunc(againDisplay); if(y>=560 || y1>=560 ){x=410; y=60; x1=450; y1=60; playerwins=0;}   }
		}
		else if(key=='2')
		{
			cout<<"Level2 Selected\n";
			float speedtest1[8]={0.30,-0.35,0.40,0,0.45,-0.50,0.55,-0.60};
			float xtest1[8]={0,800,0,0,0,800,0,800};
			float width1[8]={170,179,168,windowWidth,180,177,167,180};

			for(int m=0;m<8;m++)
			{
				speedtest[m]=speedtest1[m];
				xtest[m]=xtest1[m];
				width[m]=width1[m];
			}

			// copied 'p' condition
			{play=1; glutIdleFunc(againDisplay); if(y>=560 || y1>=560 ){x=410; y=60; x1=450; y1=60; playerwins=0;}   }

		}
		else if(key=='3')
		{
			cout<<"Level3 Selected\n";
			float xtest1[8]={0,850,20,0,13,857,100,800};
			float speedtest1[8]={0.45,-0.27,0.630,-0,0.76,-0.29,0.68,-0.60};	// BEST SETTINGS TILL NOW
			float width1[8]={170,170,170,windowWidth,180,177,167,180};	// best settings


			for(int m=0;m<8;m++)
			{
				speedtest[m]=speedtest1[m];
				xtest[m]=xtest1[m];
				width[m]=width1[m];
			}

			// copied 'p' condition
			{play=1; glutIdleFunc(againDisplay); if(y>=560 || y1>=560 ){x=410; y=60; x1=450; y1=60; playerwins=0;}   }
		}
		else if(key=='4')
		{
			cout<<"Level4 Selected\n";

			float speedtest1[8]={0.20,-0.50,0.20,0,0.65,-0.28,0.50,-0.99};
			float xtest1[8]={445,445,445,0,445,445,445,445};
			float width1[8]={170,169,168,windowWidth,180,177,167,160};


			for(int m=0;m<8;m++)
			{
				speedtest[m]=speedtest1[m];
				xtest[m]=xtest1[m];
				width[m]=width1[m];
			}

			// copied 'p' condition
			{play=1; glutIdleFunc(againDisplay); if(y>=560 || y1>=560 ){x=410; y=60; x1=450; y1=60; playerwins=0;}   }
		}
		else if(key=='5')
		{
			cout<<"Level5 Selected\n";

			float speedtest1[8]={0.70,-1.18,0.70,0,0.65,-1.70,0.85,-1.280};
			float xtest1[8]={140,650,20,0,160,680,50,700};
			float width1[8]={120,110,120,windowWidth,120,110,120,100};


			for(int m=0;m<8;m++)
			{
				speedtest[m]=speedtest1[m];
				xtest[m]=xtest1[m];
				width[m]=width1[m];
			}

			// copied 'p' condition
			{play=1; glutIdleFunc(againDisplay); if(y>=560 || y1>=560 ){x=410; y=60; x1=450; y1=60; playerwins=0;}   }
		}

	}

	//for player2
	if(key==106)
	{x1=x1-9;	}
	else if(key==105)
		{y1=y1+9;}
	else if(key==108)
		{x1=x1+9; }
	else if(key==107)
		{y1=y1-9; }

int flag=0;

	for(int j=0;j<8;j++)
	{	// that's the best place to make this...

		if ((y>=ytest[j]-25 && y<=ytest[j]+25 )&&( xtest[j]<=x && xtest[j]+width[j]>=x))
		{
			dx=x-xtest[j];
			if(dx<0) dx=-dx;
			//cout<<"attach=1\n";
			attach=1;
			flag=1;
			attachedbox=j;
			//cout<<"Player1 is on "<<j<<" - box. and attachedbox is "<<attachedbox<<"\n";

			break;

		}else {/*cout<<"y "<<y<<" ytest "<<ytest[j]<<" j "<<j<<"\n";*/}

	}

	if(flag==0) {attach=0; /*cout<<"x: "<<x<<" y: "<<y<<" and Attach1=0\n";*/}

	// for player2
	int flag1=0;

	for(int j=0;j<8;j++)
	{	// that's the best place to make this...

		if ((y1>=ytest[j]-25 && y1<=ytest[j]+25 )&&( xtest[j]<=x1 && xtest[j]+width[j]>=x1))
		{
			dx1=x1-xtest[j];
			if(dx1<0) dx1=-dx1;
			//cout<<"attach1=1\n";
			attach1=1;
			flag1=1;
			attachedbox1=j;
			//cout<<"Player2 is on "<<j<<" - box. and attachedbox is "<<attachedbox<<"\n";

			break;

		}else { /*cout<<"y1 "<<y1<<" ytest "<<ytest[j]<<" j "<<j<<"\n"; */}

	}

	if(flag1==0) {attach1=0; /*cout<<"x1: "<<x1<<" y1: "<<y1<<" and Attach1=0\n";*/ }

	//Game win condition
		if(y>=560)
		{
			playerwins=1;
			cout<<"PLAYER1 WON\n"; play=0; glutIdleFunc(NULL);
		}

		if(y1>=560)
		{
			playerwins=2;
			cout<<"PLAYER2 WON\n"; play=0; glutIdleFunc(NULL);
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
	glutMouseFunc(mouse);
	glutKeyboardFunc(key);

	glutMainLoop();
	return 0;
}

