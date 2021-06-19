#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
void display(void)
{
  int x, y, color = 0;
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f (1.0,1.0,1.0);



  for(x=1;x<=8;x++){
if(color==0){
glColor3f (0.0, 0.0, 0.0);
color++;
}
else{
glColor3f (1.0, 1.0, 1.0);
color=0;
}
for(y=1;y<=8;y++){
if(color==0){
glColor3f (0.0, 0.0, 0.0);
color++;
}
else{
glColor3f (1.0, 1.0, 1.0);
color=0;
}
glBegin(GL_QUADS);  // assume that the first value x=1, y=1;
glVertex2f(37.5+37.5*x, 37.5+37.5*y); // A1 (75,75)
glVertex2f(37.5*x, 37.5+37.5*y);  //A2(37.5,75)
glVertex2f(37.5*x, 37.5*y);// A3 (37.5, 37.5)
glVertex2f(37.5+37.5*x, 37.5*y);// A4(75, 37.5)

glEnd();
}}
      glFlush ();
}
void init (void)
{
glClearColor (1.0, 1.0, 1.0, 0.0); //select clearing (background) color
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(10,350,10,350);
}

int main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (600, 600);
glutInitWindowPosition (100, 150);
glutCreateWindow ("My Chess Board");
init ();
glutDisplayFunc(display);
glutMainLoop();
return 0;
}
