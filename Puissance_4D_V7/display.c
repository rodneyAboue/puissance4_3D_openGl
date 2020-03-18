#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include "fonction.h"
#include "sphere.c"
#include <stdio.h>

float xRotation = 0.0, yRotation = 0.0;

int popox=5 ,popoz=5,POPOX=5,POPOZ=5,YOLO,I,J,K;
extern int JOUEUR,ex,ez,ey;
extern int tab[4][4][4];

void display(void)
{  
 
   int i,j,k;
    
   glEnable(GL_DEPTH_TEST);
   glEnable(GL_RESCALE_NORMAL);
   glClear (GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
   glPushMatrix();
//===   Distance  et position de départ du plateau 
   
   glRotatef(xRotation, 1, 0, 0);
   glRotatef(yRotation, 0,1 , 0);
   
   glTranslatef(-2,0,-2); 
   glScalef(0.1,0.1,0.1);

//===   affiche le plateau   ===\\

   glPushMatrix();
   plateau();
   glPopMatrix();

//==>  affiche les cylindre

  glPushMatrix(); 	
	glTranslatef(5,0,5);
     	for(i=0; i<4; i++)  
      {
        	glPushMatrix();
		      glTranslatef(0,0,i*10);
		      for(j=0; j<4; j++)  
            {
              glColor3f (0.7, 0.7, 0.7);
			        cylindre();
			        glTranslatef(10,0,0);
		        }
		      glPopMatrix();
   	  }	
   glPopMatrix();


//===   affiche la sphere avant validation

    glPushMatrix();
   	glTranslatef(popox,25,popoz);
	  glScalef(3.5,2.5,3.5);
    sphere(JOUEUR);
    glPopMatrix();

//===   shere apres validation

    glPushMatrix();
   	glTranslatef(5,3,5);
    glScalef(3.5,2.5,3.5);
 	    for(I=0; I<4; I++)
          {
          	glPushMatrix();
		        glTranslatef(I*2.85,0,0);
		        for(J=0; J<4; J++)
              {
			           glPushMatrix();	
			           for(K=0;K<4;K++)
                   {                               
                     YOLO=tab[I][J][K];
                          if (YOLO!=0)
                          {
                            if (YOLO==1)
                            {
                              sphere(0);
                            }
                            else
                            {
                              sphere(1);
                            } 
                          }            
				               glTranslatef(0,0,2.84);
                    }
			             glPopMatrix();  
			             glTranslatef(0,2,0);
		          }
		          glPopMatrix();
   	        }	
            glPopMatrix();
         
//======    FIN

   glPopMatrix();
   glutSwapBuffers();
}




