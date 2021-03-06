/* XwinOpenDisplay.c
   ================= 
   Author: R.J.Barnes
*/

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xos.h>
#include <X11/Xatom.h>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include "rfbuffer.h"
#include "xwin.h"


struct FrameBuffer *fbuf=NULL;

int main(int argc,char *argv[]) {

  struct XwinDisplay *dp;
  struct XwinWindow *win;

  int wdt=300,hgt=300;
  unsigned int border=0;
  int flg;
  int i;

  char *display_name=NULL;
 
  char *progname;
  int status=0;
 
  progname=argv[0];

  dp=XwinOpenDisplay(display_name,&flg);
  win=XwinMakeWindow(0,0,wdt,hgt,border,
                     dp,"Test Window",
                    "Test Window","Test Window",
                    "basic",argc,argv,&flg);
                           

  if ((fbuf=FrameBufferMake("Test",wdt,hgt,24))==NULL) {
     fprintf(stderr,"failed to make frame buffer.");
     exit(-1);
  }

  for (i=0;i<wdt/2;i+=4) 
    FrameBufferEllipse(fbuf,NULL,wdt/2,hgt/2,wdt/2,i,0,
                          0xff0000,0x0f,0,NULL,NULL);

  XwinFrameBufferWindow(fbuf,win);

  XwinShowWindow(win);
  
  status=XwinDisplayEvent(dp,1,&win,0,NULL);
  
  XwinFreeWindow(win);

  XwinCloseDisplay(dp);

  return 0;
}





  
