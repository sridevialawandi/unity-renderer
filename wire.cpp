#include<GL/glut.h>
void cube(void)
{
	glutWireTeapot(2);
}
void display(void)
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	cube();
	glFlush();
}
void reshape(int width, int height)
{
	glViewport(0, 0, (GLsizei)width, (GLsizei)height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, (GLfloat)width / (GLfloat)height, 1.0, 100.0);
	glMatrixMode(GL_MODELVIEW);
}
int test_main(int agrc, char** agrv)
{
glutInit(&agrc, agrv);
glutInitDisplayMode(GLUT_SINGLE);
glutInitWindowSize(600, 500);
glutCreateWindow("Wire Teapot");
glutDisplayFunc(display);
glutReshapeFunc(reshape);
glutMainLoop();
return 0;
}