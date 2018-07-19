#include<iostream.h>

#include<conio.h>

#include<stdlib.h>

#include<graphics.h>

#include<stdio.h>



int main(void)

{

   /* request auto detection */

   int gdriver = DETECT, gmode, errorcode;



   /* initialize graphics mode */

   initgraph(&gdriver, &gmode, "");



   /* read result of initialization */

   errorcode = graphresult();



   if (errorcode != grOk)  /* an error occurred */

   {

      printf("Graphics error: %s\n", grapherrormsg(errorcode));

      printf("Press any key to halt:");

      getch();

      exit(1);             /* return with error code */

   }



    /* draw a line */

   moveto(190,90);

   outtext("hey");

   line(200,100,250,150);

   moveto(200,100);

   linerel(-50,50);

   moveto(138,150);

   char *c="helo";

   outtext(c);

   moveto(140,160);

   linerel(-50,50);

   moveto(140,160);

   linerel(50,50);

   /* clean up */

   getch();

   closegraph();

   return 0;

}
