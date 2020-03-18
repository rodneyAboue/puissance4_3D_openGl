#include <GL/glut.h>
#include <stdlib.h>
#include "fonction.c"
#include <stdio.h>
#include <unistd.h> // pour le sleep

int animate=1,ex=0,ey=6,ez=7;
int JOUEUR=0,valide=0,tour=0,ret=0;

extern float xRotation,yRotation;

extern int popox,popoz,stop;
extern int tab[4][4][4];


void init(void) 
{
   glClearColor (0.3, 0.4, 1.0, 0.0);
   glClear (GL_COLOR_BUFFER_BIT);   glClear (GL_DEPTH_BUFFER_BIT);
   glLoadIdentity ();
   gluLookAt (ex, ey, ez, 0, 0, 0, 0.0, 1.0, 0.0);
}

void my_timer(int v)
{
   if (animate)
       glutTimerFunc(40, my_timer, 1);
   glutPostRedisplay();
}


void reshape (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h); 
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   glFrustum (-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
   glMatrixMode (GL_MODELVIEW);
}

void keyboard(unsigned char key, int x, int y)
{
   switch (key) {
      case 27:
         exit(0);
         break;
      case 'a':
         animate=!animate;
	 if (animate)
   		glutTimerFunc(40, my_timer, 1);
         break;
//======	rotation du PLATEAU	=====
      case '/':
         yRotation=0;
         break;
      case '9':
         yRotation=yRotation+2;
         if(yRotation==360){yRotation=0;}
         break;
      case '7':
        
         yRotation=yRotation-2;
        if(yRotation<0){yRotation=360;}
         break;
      case '5':
            
            xRotation=xRotation+10;
            ey=0;
            if (xRotation>50){xRotation=0.0,ey=6;}
                  
         break;
//======	POSITION pion	=====
      case '6':
    // les 1er if permette d'inversé la direction en fonction de la rotation
            if( yRotation<45 || yRotation>315 )
            {
                popox=popox+10;
	            if (popox>35){popox=5;}// les 2eme evite de dépacé des cylindre la boule de validation
            }
	        if( yRotation>45 && yRotation<135){
                 	popoz=popoz+10;
                 	if (popoz>35){popoz=5;}
	        }
            if( yRotation>135 && yRotation<225){
                 	popox=popox-10;
                 	if (popox<5){popox=35;}
	        }
            if( yRotation>225 && yRotation<315){
                 	popoz=popoz-10;
                 	if (popoz<5){popoz=35;}
	        }
         break;
      case '4':
	        
            if( yRotation>135 && yRotation<225 )
            {
                popox=popox+10;
	            if (popox>35){popox=5;}
            }
	        if( yRotation>225 && yRotation<315){
                 	popoz=popoz+10;
                 	if (popoz>35){popoz=5;}
	        }
            if( yRotation<45 || yRotation>315){
                 	popox=popox-10;
                 	if (popox<5){popox=35;}
	        }
            if( yRotation>45 && yRotation<135){
                 	popoz=popoz-10;
                 	if (popoz<5){popoz=35;}
	        }
         break;
      case '2':
	         if( yRotation>225 && yRotation<315 )
            {
                popox=popox+10;
	            if (popox>35){popox=5;}
            }
	        if( yRotation<45 || yRotation>315){
                 	popoz=popoz+10;
                 	if (popoz>35){popoz=5;}
	        }
            if( yRotation>45 && yRotation<135){
                 	popox=popox-10;
                 	if (popox<5){popox=35;}
	        }
            if( yRotation>135 && yRotation<225){
                 	popoz=popoz-10;
                 	if (popoz<5){popoz=35;}
	        }
         break;
      case '8':
	         if( yRotation>45 && yRotation<135 )
            {
                popox=popox+10;
	            if (popox>35){popox=5;}
            }
	        if( yRotation>135 && yRotation<225){
                 	popoz=popoz+10;
                 	if (popoz>35){popoz=5;}
	        }
            if( yRotation>225 && yRotation<315){
                 	popox=popox-10;
                 	if (popox<5){popox=35;}
	        }
            if( yRotation<45 || yRotation>315){
                 	popoz=popoz-10;
                 	if (popoz<5){popoz=35;}
	        }
         break;
//======	validation POSITION pion	=====
     
      case '0': 
                   
            jeu(JOUEUR);
          
            if(stop==0){
            tour++;
            JOUEUR=tour%2;
            printf("Tour N°%d \n",tour+1);
            printf("A toi de joué joueur n°%d\n",JOUEUR+1);
            }
            if(stop!=0){printf(" La colonne est pleine  \n");}
            ret=fin_jeu();
            if(ret==1 || ret ==2)
               {
                printf(" joueur %d a gagne\n",ret);
                sleep(2);
                printf("Nouvelle partie dans 10 seconde \n");
                sleep(10); 
               
                printf("Ca re-commence ! Go !\n");
                tabA0();
                tour=0;
                JOUEUR=0;
               
               }  
            if (tour ==63)
            {
              printf("toute les piles sont pleines\n");
              sleep(2);
              exit(1);

            } 
       
         break;
              
   }
}

int main(int argc, char** argv)
{
   
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DEPTH|GLUT_DOUBLE| GLUT_RGB);
   glutInitWindowSize (800, 800); 
   glutInitWindowPosition (100, 100);
   glutCreateWindow (argv[0]);
   tabA0();//initialisation du tableau
   init ();
   printf("1er tout joueur n°%d toi de commencé à joué !\n",JOUEUR+1);
   glutDisplayFunc(display);
   glutReshapeFunc(reshape);
   glutKeyboardFunc(keyboard);
   glutTimerFunc(40, my_timer, 1); 
   glutMainLoop();

    
    
   return 0;
}
