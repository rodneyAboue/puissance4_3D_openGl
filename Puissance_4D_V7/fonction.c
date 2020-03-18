#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include "fonction.h"
#include <stdio.h>
#define N 32
#define taille 22
#define size 40

int tab[4][4][4];

int COOX=0,COOZ=0,ii,jj,kk,stop=1;
extern int popox,popoz,JOUEUR;
void tabA0(void)
{

//mise A 0 du tableau 3D
   for(ii=0; ii<4; ii++)
   {
		for(jj=0; jj<4; jj++)
    {
			for(kk=0;kk<4;kk++)
      {
            tab[ii][jj][kk]=0;                   
      }               
	  }
	}
}

void plateau(void)
{
   
    float u=0.747059,h=0.164706;

 // Face 1 
   glColor3f (0 , 0 ,0);   
   glBegin(GL_QUADS);
      glVertex3f (0, 0,0);
      glVertex3f (size, 0, 0);
      glVertex3f (size,1, 0);
      glVertex3f (0, 1, 0);
   glEnd();
// Face 2 
   glColor3f (0 , 0 ,0);
   glBegin(GL_QUADS);
      glVertex3f (size, 0, 0);
      glVertex3f (size, 0, size);
      glVertex3f (size, 1, size);
      glVertex3f (size, 1, 0);
   glEnd();



// Face 3 haut
   glColor3f (u , h ,0.164706);
   glBegin(GL_QUADS);
      glVertex3f (0, 1, 0);
      glVertex3f (0, 1, size);
      glVertex3f (size, 1, size);
      glVertex3f (size, 1, 0);
   glEnd();


  
// Face 4 bas
   glColor3f (u, h ,0.164706);
   glBegin(GL_QUADS);
      glVertex3f (0, 0, 0);
      glVertex3f (0, 0, size);
      glVertex3f (size, 0, size);
      glVertex3f (size, 0, 0);
   glEnd();

/// Face 5 
   glColor3f (0 , 0 ,0);
   glBegin(GL_QUADS);
      glVertex3f (0, 0, size);
      glVertex3f (size, 0,size);
      glVertex3f (size, 1, size);
      glVertex3f (0, 1, size);
   glEnd();

// Face 6 
   glColor3f (0 , 0 ,0);
   glBegin(GL_QUADS);
      glVertex3f (0, 0, 0);
      glVertex3f (0, 0, size);
      glVertex3f (0, 1, size);
      glVertex3f (0, 1, 0);
   glEnd();

}

void cylindre(void)

{
float angle=0,tabY[N],tabX[N];
int i,n;
for(i=0;i<N;i++)
	{

	 angle=((2*M_PI)/N)*i;
	
	 tabX[i] = cos(angle);
 	 tabY[i] = sin(angle);
	  		
	}
   
  glBegin(GL_POLYGON);
	for(i=0;i<N;i++)
	 {

	   glVertex3f (tabX[i], 1,tabY[i]);	
	}

   glEnd();
  
   glBegin(GL_POLYGON);
  	for(i=0;i<N;i++)
	   {
	     glVertex3f (tabX[i], taille,tabY[i]);  		
	   }
   glEnd();

   
   glBegin(GL_QUADS);
	   for(i=0;i<N-1;i++)
	   {
	     glVertex3f (tabX[i], 0,tabY[i]);
	     glVertex3f (tabX[i], taille,tabY[i]);
	
       glVertex3f (tabX[i+1], taille,tabY[i+1]);
       glVertex3f (tabX[i+1], 0,tabY[i+1]);
	
	   }
   glEnd();

    n=N-1;
   
   glBegin(GL_QUADS);
	
	 glVertex3f (tabX[0], 0,tabY[0]);
	 glVertex3f (tabX[0], taille,tabY[0]);
	 glVertex3f (tabX[n],taille,tabY[n]);
	 glVertex3f (tabX[n], 0,tabY[n]);

   glEnd();
}

void jeu(int joueur)
{
    int JJ=0 ,yolo,COOY=0;
    stop=1;
    if(popox==5){COOX=0;}
    if(popoz==5){COOZ=0;}

    if(popox==15){COOX=1;}
    if(popoz==15){COOZ=1;}
    
    if(popox==25){COOX=2;}
    if(popoz==25){COOZ=2;}

    if(popox==35){COOX=3;}
    if(popoz==35){COOZ=3;}
//===   verification d'une tige plienne 
    stop=tab[COOX][3][COOZ];

    for(JJ=0;yolo!=0||JJ<4;JJ++){

            yolo=tab[COOX][COOY][COOZ];
            if (yolo!=0){COOY++;}         
     }

    if(stop==0){
        tab[COOX][COOY][COOZ]=joueur+1
            ;
        }
    
}

int fin_jeu(void)
{
	
	int i,j,k;
    //verification  de fin de jeu veritcale
    for (i = 0; i < 4; i++)
    {
    	for ( k= 0; k < 4; k++)
    	{
            if(tab[i][0][k]!=0)
            {
    	   	    if (tab[i][0][k]==tab[i][1][k] && tab[i][0][k]==tab[i][2][k] && tab[i][0][k]==tab[i][3][k])
      		    {
        			 return tab[i][0][k];
    		      }
            }
    	}
    }
    //verification fin de jeu horizontale1
    for (j = 0; j < 4; j++)
    {
    	for ( k = 0; k < 4; k++)
    	{
            if(tab[0][j][k]!=0)
            {
        		  if (tab[0][j][k]==tab[1][j][k] && tab[0][j][k]==tab[2][j][k] && tab[0][j][k]==tab[3][j][k])
        		  {
        			 return tab[0][j][k];
        		  }
            }
    	}
    }

    //verification fin de jeu horizontale2
    for (i = 0; i < 4; i++)
    {
    	for ( j = 0; j < 4; j++)
    	{
            if(tab[i][j][0]!=0)
            {
        		  if (tab[i][j][0]==tab[i][j][1] && tab[i][j][0]==tab[i][j][2] && tab[i][j][0]==tab[i][j][3])
        		  {
        			  return tab[i][j][3];
        		  }
            }
    	}
    	 
    }
    // verification fin de jeu diagonale
    //comme il y a 6 face et deux diagonale par face alors il y a 12 da=iagonale de face
    // face 1
    //-----------------------------------------------------------------------------------------
    for (i=0;i<4;i++)
    {

        if (tab[0][0][i]!=0)
        {
            if (tab[0][0][i]==tab[1][1][i] && tab[0][0][i]==tab[2][2][i] && tab[0][0][i]==tab[3][3][i])
            {
    	         return tab[0][0][i];
            }
        }

        if (tab[0][3][i]!=0)
        {
            if (tab[0][3][i]==tab[1][2][i] && tab[0][3][i]==tab[2][1][i] && tab[0][3][i]==tab[3][0][i])
            {
    	       return tab[3][0][i];
            }
        }
    }
    //-----------------------------------------------------------------------------------------
    // face 2
        for (i=0;i<4;i++)
        {
            if (tab[i][0][0]!=0)
            {
                if (tab[i][0][0]==tab[i][1][1] && tab[i][0][0]==tab[i][2][2] && tab[i][0][0]==tab[i][3][3])
                {
    	            return tab[i][0][0];
                }
            }
            if (tab[i][3][0]!=0)
            {
                if (tab[i][3][0]==tab[i][2][1] && tab[i][3][0]==tab[i][1][2] && tab[i][3][0]==tab[i][0][3])
                 {
    	              return tab[i][3][0];
                 }
            }
        }
    //-----------------------------------------------------------------------------------------
    // face3
      for (i=0;i<4;i++)
      {
        if (tab[0][i][0]!=0)
        {
            if (tab[0][i][0]==tab[1][i][1] && tab[0][i][0]==tab[2][i][2] && tab[0][i][0]==tab[3][i][3])
            {
              	return tab[0][i][0];
            }
        }
        if (tab[3][i][0]!=0){
    
            if (tab[3][i][0]==tab[2][i][1] && tab[3][i][0]==tab[1][i][2] && tab[3][i][0]==tab[0][i][3])
            {
            	return tab[3][i][0];
            }
        }
      }
    //-----------------------------------------------------------------------------------------
    //Grande diagonale 1
    if (tab[0][0][0]==tab[1][1][1] && tab[0][0][0]==tab[2][2][2] && tab[0][0][0]==tab[3][3][3])
    {
    	return tab[0][0][0];
    }
    //Grande diagonale 2
    if (tab[3][0][0]==tab[2][1][1] && tab[3][0][0]==tab[1][2][2] && tab[3][0][0]==tab[0][3][3])
    {
    	return tab[3][0][0];
    }
    //-----------------------------------------------------------------------------------------
    //Grande diagonale 3
    if (tab[0][0][3]==tab[1][1][2] && tab[0][0][3]==tab[2][2][1] && tab[0][0][3]==tab[3][3][0])
    {
    	return tab[3][3][0];
    }
    //-----------------------------------------------------------------------------------------
    //Grande diagonale 4
    if (tab[3][0][3]==tab[2][1][2] && tab[3][0][3]==tab[1][2][1] && tab[3][0][3]==tab[0][3][0])
    {
    	return tab[3][0][3];
    }
    return 0;
}

















































