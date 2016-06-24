#include<graphics.h>
#include <conio.h>
#include<stdio.h>
int clip(float p,float q,float*u1,float*u2)

{
  float r;
  if(p<0.0)
    {
      r=q/p;
      if(r>*u2)return 0;
       else
	if(r>*u1)
	  {
	    *u1=r;  /*u1取0和r之间的最大值*/
	    return 1;
	  }
    }
	else
	 if(p>0.0)
	   {
	    r=q/p;
	    if(r<*u1)return 0;
	     else
	       if(r<*u2)
		{
		 *u2=r;/*u2取1和r之间的最小值*/
		 return 1;
		}
	   }
	   else
	     if(q<0)return 0;/*线段平行边界，舍弃*/
	     return 1;
}
 void    main(void)
{
  float x1=80,y1=150,x2=420,y2=350,xl=100,xr=400,yb=100,yt=400;
  float dx,dy,u1,u2;
  int gdriver=DETECT,gmode;
  initgraph(&gdriver,&gmode,"");
  u1=0;u2=1;
  dx=x2-x1;
  line(80,150,420,350);
  rectangle(100,100,400,400);
  getch();
  cleardevice();
  rectangle(100,100,400,400);
  if(clip(-dx,x1-xl,&u1,&u2))
    if(clip(dx,xr-x1,&u1,&u2))
     {
      dy=y2-y1;
	if(clip(-dy,y1-yb,&u1,&u2))
	 if(clip(dy,yt-y1,&u1,&u2))
	  {
	   if(u2<1.0)
	    {
	     x2=x1+u2*dx;y2=y1+u2*dy;
	    }
	   if(u1>0.0)
	    {
	     x1+=u1*dx;y1+=u1*dy;
	    }
	    setcolor(2);
	    line(x1,y1,x2,y2);
	    getch();
	     
      }
        getch();

	}    closegraph();
}