#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int angle=0;

#define X .525731112119133606
#define Z .850650808352039932

GLfloat sommets[12][3] =
{
  {-X, 0, Z},
  {X, 0, Z},
  {-X, 0, -Z},
  {X, 0, -Z},
  {0, Z, X},
  {0, Z, -X},
  {0, -Z, X},
  {0, -Z, -X},
  {Z, X, 0},
  {-Z, X, 0},
  {Z, -X, 0},
  {-Z, -X, 0}
};

int polygon_index[20][3] =
{
  {0, 4, 1},
  {0, 9, 4},
  {9, 5, 4},
  {4, 5, 8},
  {4, 8, 1},
  {8, 10, 1},
  {8, 3, 10},
  {5, 3, 8},
  {5, 2, 3},
  {2, 7, 3},
  {7, 10, 3},
  {7, 6, 10},
  {7, 11, 6},
  {11, 0, 6},
  {0, 1, 6},
  {6, 1, 10},
  {9, 0, 11},
  {9, 11, 2},
  {9, 2, 5},
  {7, 2, 11},
};

void calcul_normal(float v[3])
{
	float d=sqrt(v[0]*v[0]+v[1]*v[1]+v[2]*v[2]);
	v[0]=v[0]/d;
	v[1]=v[1]/d;
	v[2]=v[2]/d;
} 

void draw_triangle(float *v1, float *v2, float *v3, int n,int color)
{
  int xyz;
  float v[3][3];

if(n==0)
{
  	glBegin(GL_TRIANGLES);
	   	if(color==1)
      {
    	  glColor3f(1,1,1);
      }
      else
      {
        glColor3f(0,0,0);
      }
		glVertex3f(v1[0], v1[1], v1[2]);
		glVertex3f(v2[0], v2[1], v2[2]);
		glVertex3f(v3[0], v3[1], v3[2]);

	glEnd();
	}

  else
  {
	   for(xyz=0; xyz<3; xyz++)
		  {
	      v[0][xyz]=(v1[xyz]+v2[xyz])/2;	
		    v[1][xyz]=(v1[xyz]+v3[xyz])/2;	
		    v[2][xyz]=(v3[xyz]+v2[xyz])/2;	
		  }	 
    calcul_normal(v[0]);
    calcul_normal(v[1]);
    calcul_normal(v[2]);

	  draw_triangle(v1, v[0], v[1], n-1,color);
	  draw_triangle(v[0], v2, v[2], n-1,color);
	  draw_triangle(v[0], v[1], v[2], n-1,color);
	  draw_triangle(v[1], v[2], v3, n-1,color);
	}
}

void sphere(int c) 
{

   int i;
   angle=angle+1;

   for (i = 0; i <20; i++)
   {
    draw_triangle(sommets[polygon_index[i][2]], sommets[polygon_index[i][1]], sommets[polygon_index[i][0]], 3,c);
   }

}