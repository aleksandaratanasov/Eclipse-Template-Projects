//============================================================================
// Name        : OpenGL.cpp
// Author      : Aleksandar Atanasov
// Version     :
// Copyright   : GPL v3
// Description : Eclipse CDT OpenGL GLUT Template Project
//============================================================================

#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>

void display();
void reshape(int w, int h);
void mouse(int button, int state, int x, int y);
void motion(int x, int y);
void motionPassive(int x, int y);
void keyboard(unsigned char key, int x, int y);
void keyboardSpecial(int key, int x, int y);
void update(int timer);
void idle();

void initRendering();

GLint glutWindowHandle;

int main(int argc, char *argv[]) {

	// initialize
	glutInit( &argc, argv );
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);	// display mode bits (colour-space, depth buffering etc.)
	glutInitWindowPosition( 20, 20 );	// position of the GLUT window on the screen
	glutInitWindowSize( 640, 480 );		// dimensions of the GLUT window
	glutWindowHandle = glutCreateWindow( "Eclipse CDT OpenGL Template Project" );
	initRendering();	// custom initialization of the OpenGL scene

	// set up GUI callback functions
	glutDisplayFunc(display);				// rendering of the OpenGL scene
	glutReshapeFunc(reshape);				// resizing of the GLUT window
	glutMouseFunc(mouse);						// mouse button events
	glutMotionFunc(motion);					// motion of mouse (while pressing a button) within GLUT window (good for mouse gestures)
	glutPassiveMotionFunc(motionPassive);	// motion of mouse (while not pressing a button) within GLUT window (good for mouse gestures)
	glutKeyboardFunc(keyboard);				// normal keyboard events
	glutSpecialFunc(keyboardSpecial);		// special keyboard events using the GLUT_KEY_* keycodes
	glutTimerFunc(30, update, 0);				// a milliseconds-based timer callback
	glutIdleFunc(idle);						// when not sending draw commands we use this to compute something

	// start GUI loop (calls the callback functions in an infinite loop)
	// note: from all callbacks above the only one necessary is the glutDisplayFunc()
	glutMainLoop();

	return 0;
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(0,0,-1);

	// example - drawing red and blue triangles
	glBegin(GL_TRIANGLES);
	glColor3f(1,0,0);
	glVertex3f(-.5,0,0);
	glVertex3f(0,1.,0);
	glVertex3f(.5,0,0);
	glColor3f(0,0,1);
	glVertex3f(-.5,0,0);
	glVertex3f(0,-1,0);
	glVertex3f(.5,0,0);
	glEnd();

	glutSwapBuffers();
}

void reshape( int w, int h )
{
	glViewport( 0, 0, w, h );

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(60.0, (double)w / (double)h, 1.0, 200.0);
}

void mouse( int button, int state, int x, int y )
{
	switch(button)
	{
	case GLUT_LEFT_BUTTON:
		std::cout << "left mouse button ";
		if(state == GLUT_DOWN)
			std::cout << "pressed" << std::endl;
		else
			std::cout << "released" << std::endl;
		break;
	case GLUT_RIGHT_BUTTON:
		std::cout << "right mouse button ";
		if(state == GLUT_DOWN)
			std::cout << "pressed" << std::endl;
		else
			std::cout << "released" << std::endl;
		break;
	case GLUT_MIDDLE_BUTTON:
		std::cout << "middle mouse button ";
		if(state == GLUT_DOWN)
			std::cout << "pressed" << std::endl;
		else
			std::cout << "released" << std::endl;
		break;
	}
}

void motion(int x, int y)
{

}

void motionPassive(int x, int y)
{
	std::cout << "mouse at x=" << x << ", y=" << y << std::endl;
}

void keyboard( unsigned char key, int x, int y )
{
	switch(key)
	{
	case 27:
		glutDestroyWindow(glutWindowHandle);
			exit(0);
			break;
	}
}

void keyboardSpecial(int key, int x, int y)
{
	switch(key)
	{
	case GLUT_KEY_UP:
		std::cout << "up" << std::endl;
		break;
	case GLUT_KEY_DOWN:
			std::cout << "down" << std::endl;
			break;
	case GLUT_KEY_LEFT:
			std::cout << "left" << std::endl;
			break;
	case GLUT_KEY_RIGHT:
			std::cout << "right" << std::endl;
			break;
	}
}

void idle()
{

}

void update(int value)
{
	glutPostRedisplay();
	glutTimerFunc(30, update, 0);
}

void initRendering()
{
	glEnable(GL_DEPTH_TEST);
//	glEnable(GL_COLOR_MATERIAL);
//	glEnable(GL_LIGHTING);
//	glEnable(GL_LIGHT0);
//	glEnable(GL_NORMALIZE);
//	glShadeModel(GL_SMOOTH);
}
