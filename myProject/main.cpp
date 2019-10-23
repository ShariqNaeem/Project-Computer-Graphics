#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <math.h>

#include <vector>
using namespace std;
#include <Windows.h>
#include <MMSystem.h>
#include <glut.h>




void Display();
struct myPoint
{
	GLint x,y;
};


myPoint corner [100];
int numOfCorners = 0;
//int count=0;
bool firstLineDrawn = false;
myPoint peak1, peak2,peak3,peak4,peak5,peak6,peak7,peak8,peak9,peak10,peak11,peak12,peak13,peak14,peak15,peak16,peak17,peak18,peak19,peak20,peak21,peak22,peak23,peak24,peak25,peak26;
myPoint pea1, pea2,pea3,pea4,pea5,pea6,pea7,pea8,pea9,pea10,pea11,pea12,pea13,pea14,pea15,pea16,pea17,pea18,pea19,pea20,pea21,pea22,pea23,pea24,pea25,pea26;
myPoint peak;

void initializePeak (void)
{
	peak1.x = 10;
	peak1.y = 450;

	peak2.x = 50;
	peak2.y = 450;

	peak3.x = 90;
	peak3.y = 450;

	peak4.x =  130;
	peak4.y = 450;

	peak5.x = 170;
	peak5.y = 450;

	peak6.x = 210;
	peak6.y = 450;

	peak7.x = 250;
	peak7.y = 450;

	peak8.x = 290;
	peak8.y = 450;

	peak9.x = 330;
	peak9.y = 450;

	peak10.x = 370;
	peak10.y = 450;

	peak11.x = 410;
	peak11.y = 450;

	peak12.x = 450;
	peak12.y = 450;

	peak13.x = 490;
	peak13.y = 450;

	peak14.x = 530;
	peak14.y = 450;

	peak15.x = 570;
	peak15.y = 450;

	peak16.x = 90;
	peak16.y = 400;

	peak17.x = 130;
	peak17.y = 400;

	peak18.x = 170;
	peak18.y = 400;

	peak19.x = 210;
	peak19.y = 400;

	peak20.x = 250;
	peak20.y = 400;

	peak21.x = 290;
	peak21.y = 400;

	peak22.x = 330;
	peak22.y = 400;

	peak23.x = 370;
	peak23.y = 400;

	peak24.x = 410;
	peak24.y = 400;

	peak25.x = 450;
	peak25.y = 400;

	peak26.x = 490;
	peak26.y = 400;

	////////////////////////////////////////////////////////////////////////////////

	pea1.x = 10;
	pea1.y = 450-350;

	pea2.x = 50;
	pea2.y = 450-350;

	pea3.x = 90;
	pea3.y = 450-350;

	pea4.x =  130;
	pea4.y = 450-350;

	pea5.x = 170;
	pea5.y = 450-350;

	pea6.x = 210;
	pea6.y = 450-350;

	pea7.x = 250;
	pea7.y = 450-350;

	pea8.x = 290;
	pea8.y = 450-350;

	pea9.x = 330;
	pea9.y = 450-350;

	pea10.x = 370;
	pea10.y = 450-350;

	pea11.x = 410;
	pea11.y = 450-350;

	pea12.x = 450;
	pea12.y = 450-350;

	pea13.x = 490;
	pea13.y = 450-350;

	pea14.x = 530;
	pea14.y = 450-350;

	pea15.x = 570;
	pea15.y = 450-350;

	pea16.x = 90;
	pea16.y = 400-350;

	pea17.x = 130;
	pea17.y = 400-350;

	pea18.x = 170;
	pea18.y = 400-350;

	pea19.x = 210;
	pea19.y = 400-350;

	pea20.x = 250;
	pea20.y = 400-350;

	pea21.x = 290;
	pea21.y = 400-350;

	pea22.x = 330;
	pea22.y = 400-350;

	pea23.x = 370;
	pea23.y = 400-350;

	pea24.x = 410;
	pea24.y = 400-350;

	pea25.x = 450;
	pea25.y = 400-350;

	pea26.x = 490;
	pea26.y = 400-350;

}

void drawLine (myPoint firstPoint, myPoint secondPoint)
{
	glBegin(GL_LINE_LOOP);
	glVertex2d(firstPoint.x,firstPoint.y);
	glVertex2d(secondPoint.x,secondPoint.y);
	//count++;
	glEnd();
}

void myMouse (int button, int state, int x,int y)
{
	
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
		//	if (firstLineDrawn == false)
			{
				corner[numOfCorners].x = x;
	    	    corner[numOfCorners].y = 480-y;
		        numOfCorners++;
			}


		/*	else
			{
			//	corner[numOfCorners-(numOfCorners-2)].x =  corner[numOfCorners-(numOfCorners-1)].x;
			//	corner[numOfCorners-(numOfCorners-2)].y =  corner[numOfCorners-(numOfCorners-1)].y;
				corner[numOfCorners].x = x;
				corner[numOfCorners].y = 480-y;
				
				numOfCorners++;
			} */
			

			if (numOfCorners % 2 == 0 || firstLineDrawn == true)
	        {

				GLint differenceOfY = corner[numOfCorners-1].y - corner[numOfCorners-2].y;

				if (differenceOfY <= 5 && differenceOfY >=0)
				{
					corner[numOfCorners-1].y = corner[numOfCorners-2].y;
				}

				GLint differenceOfX = corner[numOfCorners-1].x - corner[numOfCorners-2].x;

				if (differenceOfX <= 5 && differenceOfX >=0)
				{
					corner[numOfCorners-1].x = corner[numOfCorners-2].x;
				} 

				drawLine(corner[numOfCorners-2],corner[numOfCorners-1]);
				glFlush();
				//numOfCorners = 1;
				firstLineDrawn = true;
        	}

		}

		else if (button == GLUT_RIGHT_BUTTON && state  == GLUT_DOWN)
		{
		//	  glClear(GL_COLOR_BUFFER_BIT);
			//glFlush();

//			firstLineDrawn = false;
	//		numOfCorners  = 0;


		}

//	glutPostRedisplay();

}

void myMovedMouse(int x, int y)
{
	corner[numOfCorners].x = x;
	corner[numOfCorners].y = 480-y;
	numOfCorners++;

	drawLine(corner[numOfCorners],corner[numOfCorners-1]);
}


//void myKey (unsigned char key,int x, int y)
//{
//	switch (key)
//	{
//
//	case 'a':
//		glClear(GL_COLOR_BUFFER_BIT);
//		glFlush();
//		break;
//
//
//	case 'b':
//			firstLineDrawn = false;
//			numOfCorners  = 0;
//			break;
//
//	case 'c':
//
//		glClear(GL_COLOR_BUFFER_BIT);
//		glFlush();
//		glutPostRedisplay();
//		break;
//
//	}	
//
//}

void points(){
	/*for(int i=1;i<=count;i++){
		if(corner[i-1].x==corner[i].x && corner[i-1].y==corner[i].y){
			corner[i].x=corner[i+1].x;
			corner[i].y==corner[i+1].y;
		}
	}*/

	printf("POINTS:\n");
	for(int i=0;i<numOfCorners;i++){
		printf("( %d , %d )\n",corner[i].x,corner[i].y);
	}
	printf("\n");
}


void delPoint(){
	corner[numOfCorners].x=corner[numOfCorners-1].x;
	corner[numOfCorners].y=corner[numOfCorners-1].y;

	/*for(int i=1;i<count;i++){
		if(corner[i-1].x==corner[i].x && corner[i-1].y==corner[i].y){
			corner[i].x=corner[i+1].x;
			corner[i].y==corner[i+1].y;
		}
	}
*/
	numOfCorners--;
	glClear(GL_COLOR_BUFFER_BIT);
	Display();
	glBegin(GL_LINE_STRIP);
	for(int i=0;i<numOfCorners;i++){
		glVertex2d(corner[i].x,corner[i].y);
	}
	//firstLineDrawn = false;
	glEnd();
	glFlush();
	
	
}

void processMenuEvent(int option)
{
	switch (option)
	{

	case 1:
			firstLineDrawn = false;
			numOfCorners  = 0;		
		break;

	case 2:
		numOfCorners  = 0;
		firstLineDrawn = false;
		glClear(GL_COLOR_BUFFER_BIT);
		glFlush();
		break;

	case 3:
		numOfCorners  = 0;
		firstLineDrawn = false;
		glutPostRedisplay();
		break;

	case 4:
		points();
		break;

	case 5:
		delPoint();
		break;

	default:
		break;
	}
}


/*
void parameterizedHouse(myPoint peak,GLint width, GLint height)
{
	
	//glBegin(GL_LINE_LOOP);          //for house and  chimney
	//glVertex2d(peak.x,peak.y);
	//glVertex2d(peak.x + width/2, peak.y - 3* height/8);
	//glVertex2d(peak.x + width/2, peak.y -  height);
	//glVertex2d(peak.x - width/2, peak.y -  height);
	//glVertex2d(peak.x - width/2, peak.y - 3* height/8);
	//glVertex2d(peak.x - (width/2)*0.5, peak.y - ((3* height/8)*0.6));
	//glVertex2d(peak.x - (width/2)*0.5, peak.y);
	//glVertex2d(peak.x - (width/2)*0.3, peak.y);
	//glVertex2d(peak.x - (width/2)*0.3,  peak.y - ((3* height/8)*0.42));
	//glEnd();

	//glBegin (GL_LINE_LOOP);        //for door
	//glVertex2d(peak.x - width/4, peak.y-height);
	//glVertex2d(peak.x - width/4, peak.y-height/1.5);
	//glVertex2d(peak.x - (width/4)*1.4,peak.y-height/1.5);
	//glVertex2d(peak.x - (width/4)*1.4, peak.y-height);
	//glEnd();

	//glBegin (GL_LINE_LOOP);       	//for window
	//glVertex2d(peak.x + width/10, peak.y-height/2);
	//glVertex2d(peak.x + width/10, peak.y-height/2.6);
	//glVertex2d(peak.x + (width/10)*2, peak.y-height/2.6);
	//glVertex2d(peak.x + (width/10)*2, peak.y-height/2);
	//glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2d(peak.x , peak.y);
	glVertex2d(peak.x + width/2, peak.y+height);
	glVertex2d(peak.x + width, peak.y);
	glVertex2d(peak.x + 3*width/4, peak.y+height/2);
	glVertex2d(peak.x + width/4, peak.y+height/2);
	glEnd();

}
*/


void Init(void)
{
	glClearColor(1,1,0.8,0);
	glColor3f(0,0,0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,640,0,480);
}

void Timer(int t)
{
	//drawLine(corner[0],corner[1]);
	//glutMouseFunc(myMouse);
	glutPostRedisplay();
	glutTimerFunc(10,Timer,t);
}

void A(myPoint peak,GLint width, GLint height)
{

	glBegin(GL_LINE_STRIP);
	glVertex2d(peak.x , peak.y);
	glVertex2d(peak.x + width/2, peak.y+height);
	glVertex2d(peak.x + width, peak.y);
	glVertex2d(peak.x + 3*width/4, peak.y+height/2);
	glVertex2d(peak.x + width/4, peak.y+height/2);
	glEnd();

}

void B(myPoint peak,GLint width, GLint height)
{

	glBegin(GL_LINE_STRIP);
	glVertex2d(peak.x , peak.y);
	glVertex2d(peak.x + width, peak.y);
	glVertex2d(peak.x + width , peak.y + height/2);
	glVertex2d(peak.x , peak.y + height/2);
	glVertex2d(peak.x , peak.y+height);
	glVertex2d(peak.x + width-5, peak.y + height);
	glVertex2d(peak.x + width-5 , peak.y + height/2);
	glVertex2d(peak.x , peak.y + height/2);
	glVertex2d(peak.x , peak.y );
	glEnd();

}

void C(myPoint peak,GLint width, GLint height)
{

	glBegin(GL_LINE_STRIP);
	glVertex2d(peak.x + width, peak.y + height);
	glVertex2d(peak.x , peak.y+ height);
	glVertex2d(peak.x , peak.y);
	glVertex2d(peak.x + width, peak.y);
	glEnd();

}

void D(myPoint peak,GLint width, GLint height)
{

	glBegin(GL_LINE_STRIP);
	glVertex2d(peak.x , peak.y);
	glVertex2d(peak.x , peak.y+height);
	glVertex2d(peak.x +3*width/4, peak.y+ height);
	glVertex2d(peak.x + width, peak.y+ height/2);
	glVertex2d(peak.x +3*width/4, peak.y);
	glVertex2d(peak.x , peak.y);
	glEnd();

}

void E(myPoint peak,GLint width, GLint height)
{

	glBegin(GL_LINE_STRIP);
	glVertex2d(peak.x + width, peak.y + height);
	glVertex2d(peak.x , peak.y+ height);
	glVertex2d(peak.x , peak.y + height/2);
	glVertex2d(peak.x + 3*width/4, peak.y+ height/2);
	glVertex2d(peak.x , peak.y + height/2);
	glVertex2d(peak.x , peak.y);
	glVertex2d(peak.x +width, peak.y);
	glEnd();

}



void F(myPoint peak,GLint width, GLint height)
{

	glBegin(GL_LINE_STRIP);
	glVertex2d(peak.x + width, peak.y + height);
	glVertex2d(peak.x , peak.y+ height);
	glVertex2d(peak.x , peak.y + height/2);
	glVertex2d(peak.x + 3*width/4, peak.y+ height/2);
	glVertex2d(peak.x , peak.y + height/2);
	glVertex2d(peak.x , peak.y);
	glEnd();

}

void G(myPoint peak,GLint width, GLint height)
{

	glBegin(GL_LINE_STRIP);
	glVertex2d(peak.x + width, peak.y + height);
	glVertex2d(peak.x , peak.y+ height);
	glVertex2d(peak.x , peak.y);
	glVertex2d(peak.x + width, peak.y);
	glVertex2d(peak.x + width, peak.y+height/2);
	glVertex2d(peak.x + 3*width/4 , peak.y + height/2);
	glEnd();

}

void H(myPoint peak,GLint width, GLint height)
{

	glBegin(GL_LINE_STRIP);
	glVertex2d(peak.x + width, peak.y + height);
	glVertex2d(peak.x + width, peak.y);
	glVertex2d(peak.x + width, peak.y + height/2);
	glVertex2d(peak.x , peak.y + height/2);
	glVertex2d(peak.x , peak.y+height);
	glVertex2d(peak.x , peak.y );
	glEnd();

}

void I(myPoint peak,GLint width, GLint height)
{
	glBegin(GL_LINE_STRIP);
	glVertex2d(peak.x , peak.y + height);
	glVertex2d(peak.x +width , peak.y + height );
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2d(peak.x + width/2, peak.y + height);
	glVertex2d(peak.x +width/2 , peak.y );
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2d(peak.x , peak.y );
	glVertex2d(peak.x +width , peak.y);
	glEnd();

}

void J(myPoint peak,GLint width, GLint height)
{

	glBegin(GL_LINE_STRIP);
	glVertex2d(peak.x + width/2, peak.y + height);
	glVertex2d(peak.x +width/2 , peak.y );
	glVertex2d(peak.x , peak.y );
	glVertex2d(peak.x , peak.y + height/3);
	glEnd();

}

void K(myPoint peak,GLint width, GLint height)
{

	glBegin(GL_LINE_STRIP);
	glVertex2d(peak.x , peak.y);
	glVertex2d(peak.x , peak.y + height);
	glVertex2d(peak.x , peak.y + height/2);
	glVertex2d(peak.x  + width , peak.y + height);
	glVertex2d(peak.x , peak.y + height/2);
	glVertex2d(peak.x +width , peak.y);
	glEnd();

}


void L(myPoint peak,GLint width, GLint height)
{

	glBegin(GL_LINE_STRIP);
	glVertex2d(peak.x , peak.y + height);
	glVertex2d(peak.x , peak.y);
	glVertex2d(peak.x + width, peak.y);
	glEnd();

}

void M(myPoint peak,GLint width, GLint height)
{

	glBegin(GL_LINE_STRIP);
	glVertex2d(peak.x , peak.y);
	glVertex2d(peak.x , peak.y + height);
	glVertex2d(peak.x + width/2 , peak.y + height/2);
	glVertex2d(peak.x + width , peak.y + height);
	glVertex2d(peak.x +width , peak.y);
	glEnd();

}

void N(myPoint peak,GLint width, GLint height)
{

	glBegin(GL_LINE_STRIP);
	glVertex2d(peak.x , peak.y);
	glVertex2d(peak.x , peak.y + height);
	glVertex2d(peak.x + width , peak.y);
	glVertex2d(peak.x + width , peak.y + height);
	glEnd();

}

void O(myPoint peak,GLint width, GLint height)
{

	glBegin(GL_LINE_STRIP);
	glVertex2d(peak.x , peak.y);
	glVertex2d(peak.x , peak.y + height);
	glVertex2d(peak.x + width , peak.y + height);
	glVertex2d(peak.x + width , peak.y);
	glVertex2d(peak.x , peak.y);
	glEnd();

}

void P(myPoint peak,GLint width, GLint height)
{

	glBegin(GL_LINE_STRIP);
	glVertex2d(peak.x , peak.y);
	glVertex2d(peak.x , peak.y + height);
	glVertex2d(peak.x + width , peak.y + height);
	glVertex2d(peak.x + width , peak.y+ height/2);
	glVertex2d(peak.x , peak.y+ height/2);
	glEnd();

}

void Q(myPoint peak,GLint width, GLint height)
{

	glBegin(GL_LINE_STRIP);
	glVertex2d(peak.x , peak.y);
	glVertex2d(peak.x , peak.y + height);
	glVertex2d(peak.x + width-10 , peak.y + height);
	glVertex2d(peak.x + width-10 , peak.y);
	glVertex2d(peak.x , peak.y);
	glVertex2d(peak.x + width-10 , peak.y);
	glVertex2d(peak.x + width/2 , peak.y +height/2);
	glVertex2d(peak.x + width-10 , peak.y);
	glVertex2d(peak.x + width , peak.y);
	glEnd();

}


void R(myPoint peak,GLint width, GLint height)
{

	glBegin(GL_LINE_STRIP);
	glVertex2d(peak.x , peak.y);
	glVertex2d(peak.x , peak.y + height);
	glVertex2d(peak.x + width , peak.y + height);
	glVertex2d(peak.x + width , peak.y+ height/2);
	glVertex2d(peak.x , peak.y+ height/2);
	glVertex2d(peak.x + width , peak.y);
	glEnd();

}

void S(myPoint peak,GLint width, GLint height)
{

	glBegin(GL_LINE_STRIP);
	glVertex2d(peak.x , peak.y);
	glVertex2d(peak.x + width , peak.y);
	glVertex2d(peak.x + width , peak.y+ height/2);
	glVertex2d(peak.x , peak.y + height/2);
	glVertex2d(peak.x , peak.y + height);
	glVertex2d(peak.x + width , peak.y + height);
	glEnd();

}


void T(myPoint peak,GLint width, GLint height)
{

	glBegin(GL_LINE_STRIP);
	glVertex2d(peak.x , peak.y + height);
	glVertex2d(peak.x + width , peak.y + height);
	glVertex2d(peak.x + width/2 , peak.y + height);
	glVertex2d(peak.x + width/2 , peak.y);
	glEnd();

}

void U(myPoint peak,GLint width, GLint height)
{

	glBegin(GL_LINE_STRIP);
	glVertex2d(peak.x , peak.y + height);
	glVertex2d(peak.x , peak.y);
	glVertex2d(peak.x + width , peak.y);
	glVertex2d(peak.x + width , peak.y + height);
	glEnd();

}

void V(myPoint peak,GLint width, GLint height)
{

	glBegin(GL_LINE_STRIP);
	glVertex2d(peak.x , peak.y + height);
	glVertex2d(peak.x + width/2 , peak.y);
	glVertex2d(peak.x + width , peak.y + height);
	glEnd();

}

void W(myPoint peak,GLint width, GLint height)
{

	glBegin(GL_LINE_STRIP);
	glVertex2d(peak.x , peak.y + height);
	glVertex2d(peak.x + width/4 , peak.y);
	glVertex2d(peak.x + width/2 , peak.y + height);
	glVertex2d(peak.x + 3*width/4 , peak.y);
	glVertex2d(peak.x + width , peak.y + height);
	glEnd();

}

void X(myPoint peak,GLint width, GLint height)
{

	glBegin(GL_LINE_STRIP);
	glVertex2d(peak.x , peak.y + height);
	glVertex2d(peak.x + width , peak.y);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2d(peak.x , peak.y);
	glVertex2d(peak.x + width , peak.y+height);
	glEnd();
}

void Y(myPoint peak,GLint width, GLint height)
{
	glBegin(GL_LINE_STRIP);
	glVertex2d(peak.x , peak.y + height);
	glVertex2d(peak.x + width/2 , peak.y+height/2);
	glVertex2d(peak.x + width , peak.y+height);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2d(peak.x + width/2 , peak.y+height/2);
	glVertex2d(peak.x + width/2 , peak.y);
	glEnd();
}

void Z(myPoint peak,GLint width, GLint height)
{
	glBegin(GL_LINE_STRIP);
	glVertex2d(peak.x , peak.y + height);
	glVertex2d(peak.x + width , peak.y+height);
	glVertex2d(peak.x  , peak.y);
	glVertex2d(peak.x + width , peak.y);
	glEnd();
}


void myKey (unsigned char key,int x, int y)
{
	switch (key)
	{

	case 'a':
		A(pea1,25,25);
		glFlush();
		PlaySound(TEXT("A.wav"),NULL,SND_SYNC);
		break;


	case 'b':
		B(pea2,25,25);
		glFlush();
		PlaySound(TEXT("B.wav"),NULL,SND_SYNC);
		break;

	case 'c':
		C(pea3,25,25);
		glFlush();
		PlaySound(TEXT("C.wav"),NULL,SND_SYNC);
		break;

	case 'd':
		D(pea4,25,25);
		glFlush();
		PlaySound(TEXT("D.wav"),NULL,SND_SYNC);
		break;

	case 'e':
		E(pea5,25,25);
		glFlush();
		PlaySound(TEXT("E.wav"),NULL,SND_SYNC);
		break;

	case 'f':
		F(pea6,25,25);
		glFlush();
		PlaySound(TEXT("F.wav"),NULL,SND_SYNC);
		break;

	case 'g':
		G(pea7,25,25);
		glFlush();
		PlaySound(TEXT("G.wav"),NULL,SND_SYNC);
		break;

	case 'h':
		H(pea8,25,25);
		glFlush();
		PlaySound(TEXT("H.wav"),NULL,SND_SYNC);
		break;

	case 'i':
		I(pea9,25,25);
		glFlush();
		PlaySound(TEXT("I.wav"),NULL,SND_SYNC);
		break;

	case 'j':
		J(pea10,25,25);
		glFlush();
		PlaySound(TEXT("J.wav"),NULL,SND_SYNC);
		break;

	case 'k':
		K(pea11,25,25);
		glFlush();
		PlaySound(TEXT("K.wav"),NULL,SND_SYNC);
		break;

	case 'l':
		L(pea12,25,25);
		glFlush();
		PlaySound(TEXT("L.wav"),NULL,SND_SYNC);
		break;

	case 'm':
		M(pea13,25,25);
		glFlush();
		PlaySound(TEXT("M.wav"),NULL,SND_SYNC);
		break;

	case 'n':
		N(pea14,25,25);
		glFlush();
		PlaySound(TEXT("N.wav"),NULL,SND_SYNC);
		break;

	case 'o':
		O(pea15,25,25);
		glFlush();
		PlaySound(TEXT("O.wav"),NULL,SND_SYNC);
		break;

	case 'p':
		P(pea16,25,25);
		glFlush();
		PlaySound(TEXT("P.wav"),NULL,SND_SYNC);
		break;

	case 'q':
		Q(pea17,25,25);
		glFlush();
		PlaySound(TEXT("Q.wav"),NULL,SND_SYNC);
		break;

	case 'r':
		R(pea18,25,25);
		glFlush();
		PlaySound(TEXT("R.wav"),NULL,SND_SYNC);
		break;

	case 's':
		S(pea19,25,25);
		glFlush();
		PlaySound(TEXT("S.wav"),NULL,SND_SYNC);
		break;

	case 't':
		T(pea20,25,25);
		glFlush();
		PlaySound(TEXT("T.wav"),NULL,SND_SYNC);
		break;

	case 'u':
		U(pea21,25,25);
		glFlush();
		PlaySound(TEXT("U.wav"),NULL,SND_SYNC);
		break;
		
	case 'v':
		V(pea22,25,25);
		glFlush();
		PlaySound(TEXT("V.wav"),NULL,SND_SYNC);
		break;

	case 'w':
		W(pea23,25,25);
		glFlush();
		PlaySound(TEXT("W.wav"),NULL,SND_SYNC);
		break;

	case 'x':
		X(pea24,25,25);
		glFlush();
		PlaySound(TEXT("X.wav"),NULL,SND_SYNC);
		break;

	case 'y':
		Y(pea25,25,25);
		glFlush();
		PlaySound(TEXT("Y.wav"),NULL,SND_SYNC);
		break;

	case 'z':
		Z(pea26,25,25);
		glFlush();
		PlaySound(TEXT("Z.wav"),NULL,SND_SYNC);
		break;

	case 'A':
		A(pea1,25,25);
		glFlush();
		PlaySound(TEXT("A.wav"),NULL,SND_SYNC);
		break;


	case 'B':
		B(pea2,25,25);
		glFlush();
		PlaySound(TEXT("B.wav"),NULL,SND_SYNC);
		break;

	case 'C':
		C(pea3,25,25);
		glFlush();
		PlaySound(TEXT("C.wav"),NULL,SND_SYNC);
		break;

	case 'D':
		D(pea4,25,25);
		glFlush();
		PlaySound(TEXT("D.wav"),NULL,SND_SYNC);
		break;

	case 'E':
		E(pea5,25,25);
		glFlush();
		PlaySound(TEXT("E.wav"),NULL,SND_SYNC);
		break;

	case 'F':
		F(pea6,25,25);
		glFlush();
		PlaySound(TEXT("F.wav"),NULL,SND_SYNC);
		break;

	case 'G':
		G(pea7,25,25);
		glFlush();
		PlaySound(TEXT("G.wav"),NULL,SND_SYNC);
		break;

	case 'H':
		H(pea8,25,25);
		glFlush();
		PlaySound(TEXT("H.wav"),NULL,SND_SYNC);
		break;

	case 'I':
		I(pea9,25,25);
		glFlush();
		PlaySound(TEXT("I.wav"),NULL,SND_SYNC);
		break;

	case 'J':
		J(pea10,25,25);
		glFlush();
		PlaySound(TEXT("J.wav"),NULL,SND_SYNC);
		break;

	case 'K':
		K(pea11,25,25);
		glFlush();
		PlaySound(TEXT("K.wav"),NULL,SND_SYNC);
		break;

	case 'L':
		L(pea12,25,25);
		glFlush();
		PlaySound(TEXT("L.wav"),NULL,SND_SYNC);
		break;

	case 'M':
		M(pea13,25,25);
		glFlush();
		PlaySound(TEXT("M.wav"),NULL,SND_SYNC);
		break;

	case 'N':
		N(pea14,25,25);
		glFlush();
		PlaySound(TEXT("N.wav"),NULL,SND_SYNC);
		break;

	case 'O':
		O(pea15,25,25);
		glFlush();
		PlaySound(TEXT("O.wav"),NULL,SND_SYNC);
		break;

	case 'P':
		P(pea16,25,25);
		glFlush();
		PlaySound(TEXT("P.wav"),NULL,SND_SYNC);
		break;

	case 'Q':
		Q(pea17,25,25);
		glFlush();
		PlaySound(TEXT("Q.wav"),NULL,SND_SYNC);
		break;

	case 'R':
		R(pea18,25,25);
		glFlush();
		PlaySound(TEXT("R.wav"),NULL,SND_SYNC);
		break;

	case 'S':
		S(pea19,25,25);
		glFlush();
		PlaySound(TEXT("S.wav"),NULL,SND_SYNC);
		break;

	case 'T':
		T(pea20,25,25);
		glFlush();
		PlaySound(TEXT("T.wav"),NULL,SND_SYNC);
		break;

	case 'U':
		U(pea21,25,25);
		glFlush();
		PlaySound(TEXT("U.wav"),NULL,SND_SYNC);
		break;
		
	case 'V':
		V(pea22,25,25);
		glFlush();
		PlaySound(TEXT("V.wav"),NULL,SND_SYNC);
		break;

	case 'W':
		W(pea23,25,25);
		glFlush();
		PlaySound(TEXT("W.wav"),NULL,SND_SYNC);
		break;

	case 'X':
		X(pea24,25,25);
		glFlush();
		PlaySound(TEXT("X.wav"),NULL,SND_SYNC);
		break;

	case 'Y':
		Y(pea25,25,25);
		glFlush();
		PlaySound(TEXT("Y.wav"),NULL,SND_SYNC);
		break;

	case 'Z':
		Z(pea26,25,25);
		glFlush();
		PlaySound(TEXT("Z.wav"),NULL,SND_SYNC);
		break;


	default:
		break;

	}	

}


GLint w=25,h=25;
void Display(void)
{

	glClear(GL_COLOR_BUFFER_BIT);	
	initializePeak();
	A(peak1,w,h);
	B(peak2,w,h);
	C(peak3,w,h);
	D(peak4,w,h);
	E(peak5,w,h);
	F(peak6,w,h);
	G(peak7,w,h);
	H(peak8,w,h);
	I(peak9,w,h);
	J(peak10,w,h);
	K(peak11,w,h);
	L(peak12,w,h);
	M(peak13,w,h);
	N(peak14,w,h);
	O(peak15,w,h);
	P(peak16,w,h);
	Q(peak17,w,h);
	R(peak18,w,h);
	S(peak19,w,h);
	T(peak20,w,h);
	U(peak21,w,h);
	V(peak22,w,h);	
	W(peak23,w,h);
	X(peak24,w,h);
	Y(peak25,w,h);
	Z(peak26,w,h);


	//parameterizedHouse(peak4,200,200);
	
	/*if (numOfCorners ==2)
	{
		drawLine(corner[0],corner[1]);
		numOfCorners = 0;
	}  */
	
	glFlush();
}


int main(int argc, char **argv)
{

	
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(640,480);
	glutInitWindowPosition(100,150);
	glutCreateWindow("CG PROJECT");
	glutDisplayFunc(Display);
	//glutKeyboardFunc(myKey);
	glutCreateMenu(processMenuEvent);
	glutAddMenuEntry("BEGIN NEW LINE",1);
	glutAddMenuEntry("CLEAR EVERYTHING",2);
	glutAddMenuEntry("START-PAGE",3);
	glutAddMenuEntry("PRINT POINTS",4);
	glutAddMenuEntry("DELETE POINT",5);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMouseFunc(myMouse);
	//glutMotionFunc(myMovedMouse);
	glutKeyboardFunc(myKey);
	Init();
	//glutTimerFunc(10,Timer,1);

	
	glutMainLoop();

	return 0;
}	