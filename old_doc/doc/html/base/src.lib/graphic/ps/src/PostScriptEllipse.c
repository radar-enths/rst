/* PostScriptEllipse
   =================
   Author: R.J.Barnes
*/


#include <stdio.h>
#include <stdlib.h>
#include "rfbuffer.h"
#include "rps.h"

int stream(char *buf,int sze,void *data) {
  FILE *fp;
  fp=(FILE *) data;
  fwrite(buf,sze,1,stdout);
  return 0;
} 


int main(int argc,char *argv[]) {

  struct PostScript *ps=NULL;

  float wdt=400,hgt=400;
  float xoff=50,yoff=50;

  unsigned int fgcol=0xff000000;

  ps=PostScriptMake();
  PostScriptSetText(ps,stream,stdout);

  PostScriptMakeDocument(ps,xoff,yoff,wdt,hgt,0);
  PostScriptMakePlot(ps);
   


  PostScriptEllipse(ps,NULL,wdt/2,hgt/2,wdt/2-20,hgt/2-20,
                  1,fgcol,0,NULL,NULL);


  PostScriptEndPlot(ps);
  PostScriptEndDocument(ps);
  return 0;
}

