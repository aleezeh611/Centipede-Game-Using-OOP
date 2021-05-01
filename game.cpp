//============================================================================
// Name        : .cpp
// Author      : Sibt ul Hussain
// Version     :
// Copyright   : (c) Reserved
// Description : Basic 2D game of Centipede...
//============================================================================

/*

	PROJECT - CENTIPEDE
	SUBMITTED BY:  Aleezeh Usman
	Roll # 18I-0529


*/
#ifndef CENTIPEDE_CPP_
#define CENTIPEDE_CPP_
#include "Board.h"
#include "AllVariables.h"
#include <iostream>
#include<string>
#include<cmath> // for basic math functions such as cos, sin, sqrt
#include<fstream>
using namespace std;

// seed the random numbers generator by current time (see the documentation of srand for further help)...

/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */
void SetCanvasSize(int width, int height) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}

AllVariables Game;
/*
 * Main Canvas drawing function.
 * */
Board *b;

void GameDisplay()/**/{
	// set the background color using function glClearColor.
	// to change the background play with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.

	glClearColor(0.05/*Red Component*/, 0.09,	//148.0/255/*Green Component*/,
			0.17/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors



	if(Game.GameOver == 1){
	
	//to create flea at a specific moment but with a random position
	if(Game.fleacheck){
		if(Game.mushrooms->getTotal()==24){
			Game.flea->setDirection(2);
			Game.fleacheck = 0;
		}
	}

	if(Game.flea->getDirection() == 2){
		Game.flea->move();
		
		if(Game.flea->getDirection() == 2){
			Game.flea->draw();
			int toCreateorNot = rand()%30;
			//cout<<toCreateorNot<<endl;
			if( toCreateorNot % 6 == 0) Game.mushrooms->MushroomCreate(Game.mushrooms, Game.flea->getX(), Game.flea->getY());
		}
	}
	
	//implement centipede
	for(int i = 0; i<= Game.cen ; i++){
		Game.centipede[i].draw();
		Game.centipede[i].move();
		//collision between player and centipede
		if(Game.player->collision(Game.centipede[i].getX(), Game.centipede[i].getY())){
			Game.Stats.decNumOfLives(1);
			Game.centipede[i].setSegment(10);
			if(Game.mushrooms->getTotal() < 25){
				for(int i = Game.mushrooms->getTotal() ; i <= 25 ; i++) {
					Game.mushrooms->MushroomCreate(Game.mushrooms, rand()%60 , rand()% 55 + 2);
				}
			}
			if(Game.Stats.getNumOfLives() <= 0 ) Game.GameOver = 0;
		}
	}
		
	//create players avatar
	Game.player->draw();

	//create mushrooms
	for(int count = 0 ; count< Game.mushrooms[count].getTotal() ; count++ ){
			Game.mushrooms[count].draw();
			for(int cencount = 0; cencount <= Game.cen ; cencount++)
			Game.centipede[cencount].collidewithmushrooms(Game.mushrooms[count].getX(), Game.mushrooms[count].getY());
	}

	//draw score board
	Game.Stats.draw();

	//for bullets and consequent collisions with creatures 
		for(int count = 0; count <= Game.i ; count++){
			if(Game.bomb[count].getDirection() == 3){
			Game.bomb[count].draw();
			Game.bomb[count].move();
			}
			
			//collision with mushrooms
			for(int mcount = 0 ; mcount<  Game.mushrooms[mcount].getTotal() ; mcount++ ){
				if(Game.mushrooms[mcount].collision( Game.bomb[count].getX(), Game.bomb[count].getY())) {
					Game.bomb->BombDelete( count , Game.bomb, Game.i);	
					Game.i--;
					if(Game.mushrooms[mcount].getHits() >= 2){
						 Game.mushrooms->MushroomDelete(mcount, Game.mushrooms);
						Game.Stats.incScore(5);
					}
				}
			}
			
			//collision with centipede
			for(int i = 0; i<= Game.cen ; i++){
				if(Game.centipede[i].collision(Game.GameOver, Game.bomb[count].getX(), Game.bomb[count].getY(), Game.mushrooms, Game.Stats)){ 	
					Game.bomb->BombDelete( count , Game.bomb, Game.i);	
					Game.i--;
					break;
				}
			}
			
			//collision with flea
			if(Game.flea->getDirection() == 2){ 
				if(Game.flea->collision(Game.bomb[count].getX(), Game.bomb[count].getY())){
					Game.Stats.incScore(200);
				}
			}
			
		}
	DrawLine( 0*17, 57*14, 60*17, 57*14, 3, colors[WHITE]);
	
	   fstream dataFile;
 	   dataFile.open("check.txt",ios::in);
   
 	   if(dataFile.is_open() )
    	   {
        	while( !dataFile.eof() )
        	{
           	dataFile>> Game.Stats.highscore;
        	}
     	   }
     
     	   dataFile.close();
     	   fstream writeFile;
     	   writeFile.open("check.txt",ios::out | ios::app);
     
           if(writeFile.is_open() )
     	   {
           	if(Game.Stats.getScore() > Game.Stats.highscore)
           	{
           		Game.Stats.highscore = Game.Stats.getScore();
           		writeFile<<Game.Stats.highscore<<"\n";
           	}
     	   }
     
     	   writeFile.close();  
	}
	else if(Game.GameOver == 2){
	   DrawString( 420,350 , "Game Paused", colors[136]);
           DrawString( 350,310 , "Press R/r key to resume game ", colors[136]);
           DrawLine( 200 , 290 ,  200 , 380 , 3 , colors[136] );//left vertical
           DrawLine( 800 , 290 ,  800 , 380 , 3 , colors[136] );//right vertical
           DrawLine(  200, 290 , 800  , 290 , 3 , colors[136] );//lower horizontal line
 	   DrawLine( 200 , 380 ,  800 , 380 , 3 , colors[136] );//upper horizontal line
	}
	else if(Game.GameOver == 3){
	   int randomcolor=(rand()%90);
	   DrawString( 180,350 , "CONGRATULATIONS YOU DEFEATED THE CENTIPEDE", colors[randomcolor]);
           //DrawString(180, 350, 180, 350,"CONGRATULATIONS YOU DEFEATED THE CENTIPEDE", colors[randomcolor]);
	   DrawString( 400, 310 , "SCORE: "+to_string(Game.Stats.getScore()), colors[136]);
           DrawString( 350, 270 , " -press escape key to exit- ", colors[136]);
           DrawLine( 100 , 250 ,  100 , 380 , 3 , colors[136] );//left vertical
           DrawLine( 900 , 250 ,  900 , 380 , 3 , colors[136] );//right vertical
           DrawLine(  100, 250 , 900  , 250 , 3 , colors[136] );//lower horizontal line
 	   DrawLine( 100 , 380 ,  900 , 380 , 3 , colors[136] );//upper horizontal line
 	   if(Game.Stats.getScore() == Game.Stats.highscore)
           {
               DrawString( 300,420 , "You have broken all previous records", colors[randomcolor]);
               DrawString( 330,390 , "NEW HIGHEST SCORE: " + to_string(Game.Stats.highscore), colors[randomcolor]);
           }
	}
	else{
	int randomcolor=(rand()%90);
 	   DrawString( 420,350 , "YOU LOSE", colors[136]);
           DrawString( 430,320 , "Score: " + to_string(Game.Stats.getScore()), colors[136]);
           DrawString( 360,290 , "Press Escape key to exit game ", colors[136]);
           DrawLine( 180 , 260 ,  180 , 380 , 3 , colors[136] );//DrawLine(int x1, int y1, int x2, int y2, int lwidth, float *color)
           DrawLine( 800 , 260 ,  800 , 380 , 3 , colors[136] );//DrawLine(int x1, int y1, int x2, int y2, int lwidth, float *color)
           DrawLine(  180, 260 , 800  , 260 , 3 , colors[136] );//DrawLine(int x1, int y1, int x2, int y2, int lwidth, float *color)
 	   DrawLine( 180 , 380 ,  800 , 380 , 3 , colors[136] );//DrawLine(int x1, int y1, int x2, int y2, int lwidth, float *color)
           if(Game.Stats.getScore() == Game.Stats.highscore)
           {
               DrawString( 150,410 , "You have broken all previous records", colors[randomcolor]);
               DrawString( 190,390 , "NEW HIGHEST SCORE: " + to_string(Game.Stats.highscore), colors[randomcolor]);
           }
	}

	glutSwapBuffers(); // do not modify this line..

}

/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
 *
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 *
 * */

void NonPrintableKeys(int key, int x, int y) {
	if (key == GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) {
		int check = 1;
		for(int c = 0 ; c < Game.mushrooms->getTotal() ; c++){
			if( (Game.player->getX() >= Game.mushrooms[c].getX() && Game.player->getX() <= Game.mushrooms[c].getX()+1) && (Game.player->getY()+1 == Game.mushrooms[c].getY() || Game.player->getY()+2 == Game.mushrooms[c].getY()))
				check = 0;
			
		}
		if(check){	
			Game.player->setDirection(2);
			Game.player->move();
		}

	} else if (key == GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) {
		int check = 1;
		for(int c = 0 ; c < Game.mushrooms->getTotal() ; c++){
			if( (Game.player->getX() >= Game.mushrooms[c].getX()-2 && Game.player->getX() <= Game.mushrooms[c].getX()) && (Game.player->getY()+1 == Game.mushrooms[c].getY() || Game.player->getY()+2 == Game.mushrooms[c].getY()))
			 	check = 0;
		}
		if(check){
			Game.player->setDirection(1);
			Game.player->move();
		}

	} else if (key == GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/) {	
	int check = 1;
		for(int c = 0 ; c < Game.mushrooms->getTotal() ; c++){
			if( (Game.player->getX() >= Game.mushrooms[c].getX()-1 && Game.player->getX() <= Game.mushrooms[c].getX()) && Game.player->getY()+2 == Game.mushrooms[c].getY())
			 	check = 0;
		}
		if(check){
		Game.player->setDirection(3);
		Game.player->move();
		}
	}

	else if (key== GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) {
	int check = 1;
		for(int c = 0 ; c < Game.mushrooms->getTotal() ; c++){
			if(  (Game.player->getX() >= Game.mushrooms[c].getX()-1 && Game.player->getX() <= Game.mushrooms[c].getX()) && Game.player->getY() == Game.mushrooms[c].getY())
				check = 0;
		}
		if(check){
		Game.player->setDirection(4);
		Game.player->move();
		}
	}


	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/

	//glutPostRedisplay();

}

/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */
void PrintableKeys(unsigned char key, int x, int y) {
	if (key == 27/* Escape key ASCII*/) {
		exit(1); // exit the program when escape key is pressed.
	}

	if (key == ' ') {
		Game.i++;
		if(Game.i > 0){
			//cout<<"CURRENT INDEX OF BOMBS : "<< Game.i << endl;
			AllVariables tempbomb;
			tempbomb.bomb = new Bomb[Game.i];
			for(int index = 0; index < Game.i ; index++){
				tempbomb.bomb[index] = Game.bomb[index];
			}
			delete [] Game.bomb;
			Game.bomb = new Bomb[Game.i+1];
			for(int index = 0; index < Game.i ; index++){
				Game.bomb[index] = tempbomb.bomb[index];
			}
			delete [] tempbomb.bomb;
		}
		Game.bomb[Game.i].setBomb(Game.player->getX() , Game.player->getY());
		Game.bomb[Game.i].setDirection(3);	
	}
	if(key == 'B' || key == 'b'){
		Game.centipede->CreateCentipede(0, Game.cen+1, 5, 50, 50, Game.centipede);
		Game.cen += 1;
	}
	if(key == '6'){
		delete [] Game.mushrooms;
		delete [] Game.bomb;
		delete [] Game.centipede;
		Game.mushrooms = new Mushroom[25];
		Game.bomb = new Bomb[1];
		Game.centipede = new Segment[1];
		Game.centipede[0].setSegment(10);
		Game.Stats.ResetScore();
		Game.Stats.ResetLives();
		Game.GameOver = 1;
		
	}
	//Pause and play functions
	if(key == 'R' || key == 'r') Game.GameOver = 1;
	if(key == 'P' || key == 'p') Game.GameOver = 2;
	//glutPostRedisplay();
}

/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */
void Timer(int m) {

	// implement your functionality here
 	glutPostRedisplay();
	// once again we tell the library to call our Timer function after next 1000/FPS
	glutTimerFunc(50.0, Timer, 0);
}

/*This function is called (automatically) whenever your mouse moves witin inside the game window
 *
 * You will have to add the necessary code here for finding the direction of shooting
 *
 * This function has two arguments: x & y that tells the coordinate of current position of move mouse
 *
 * */
void MousePressedAndMoved(int x, int y) {
	cout << x << " " << y << endl;
	glutPostRedisplay();
}
void MouseMoved(int x, int y) {

	glutPostRedisplay();
}

/*This function is called (automatically) whenever your mouse button is clicked witin inside the game window
 *
 * You will have to add the necessary code here for shooting, etc.
 *
 * This function has four arguments: button (Left, Middle or Right), state (button is pressed or released),
 * x & y that tells the coordinate of current position of move mouse
 *
 * */
void MouseClicked(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON) // dealing only with left button
			{
		cout << GLUT_DOWN << " " << GLUT_UP << endl;

	} else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
			{

	}
	glutPostRedisplay();
}
/*
 * our gateway main function
 * */
int main(int argc, char*argv[]) {

	b = new Board(60, 60); // create a new board object to use in the Display Function ...
	Game.player = new Player;
	Game.bomb = new Bomb[1];
	srand(time(NULL));
	Game.mushrooms = new Mushroom[25];
	Game.centipede = new Segment[1];
	Game.centipede[0].setSegment(10);
	Game.flea = new Fleas;
	Game.flea->setDirection(0);
	int width = 1020, height = 840; // i have set my window size to be 800 x 600
	b->InitalizeBoard(width, height);
	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("OOP Centipede"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...

	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.

	glutDisplayFunc(GameDisplay); // tell library which function to call for drawing Canvas.
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(1000.0, Timer, 0);

	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved); // Mouse
	glutMotionFunc(MousePressedAndMoved); // Mouse

	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();
	delete [] Game.bomb;
	delete [] Game.mushrooms;
	//delete [] Game.centipede;	
	return 1;
}
#endif /* AsteroidS_CPP_ */
