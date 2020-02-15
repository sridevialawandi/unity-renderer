//A traingle with 3 colors
#include<GL/freeglut.h>
#include<math.h>

bool isFullScreen = false;	//Variable for full screen toggle

int test_main(int argc, char** argv)
{
	//Function Prototypes
	void display(void);
	void resize(int, int);
	void keyboard(unsigned char, int, int);
	void mouse(int, int, int, int);
	void initialize(void);
	void uninitialize(void);

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(600, 400);
	glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH) / 2) - 400, (glutGet(GLUT_SCREEN_HEIGHT) / 2) - 300); //Finding center co-ordinates
	glutCreateWindow("Multicolor Triangle");

	initialize();

	glutDisplayFunc(display);
	glutReshapeFunc(resize);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);
	glutCloseFunc(uninitialize);
	glutMainLoop();
	//	return(0);
}

void display(void)
{
	void colored_triangle(void);

	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	colored_triangle();

	glutSwapBuffers();
}

void colored_triangle(void)
{
	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 1.0f, 1.0f);//white
	glVertex3f(0.0f, 1.0f, 0.0f);

	glColor3f(0.5f, 0.5f, 0.5f);//gray
	glVertex3f(-1.0f, -1.0f, 0.0f);

	glColor3f(1.0f, 0.0f, 1.0f);//magenta
	glVertex3f(1.0f, -1.0f, 0.0f);
	glEnd();

}

void initialize(void)
{

	//to select background clearing
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 27:	//Escape Loop
		glutLeaveMainLoop();
		break;
	case 'F':
	case 'f':
		if (isFullScreen == false)
		{
			glutFullScreen();
			isFullScreen = true;

		}
		else
		{
			glutLeaveFullScreen();
			isFullScreen = false;

		}
		break;
	default:
		break;
	}
}

void mouse(int button, int state, int x, int y)
{
	switch (button)
	{
	case GLUT_LEFT_BUTTON:
		break;
	default:
		break;
	}
}

void resize(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
}

void uninitialize(void)
{
	//code
}
