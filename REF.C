#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include<math.h>
void main()
{
 int gm;
 int gd=DETECT;
 int x1,x2,x3,y1,y2,y3,ax1,ax2,ax3,ay1,ay2,ay3,c;
 int tr[3][3],s[3][3],p[3][3],p1[3][3]={0,0,0,0,0,0,0,0,0};
 int sx,sy,xt,yt,rt,i,j,k;
 float b,t,r[3][3];
 initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
 printf("\nEnter the points of triangle:");
 scanf("%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3);
 p[0][0]=x1;
 p[0][1]=x2;
 p[0][2]=x3;
 p[1][0]=y1;
 p[1][1]=y2;
 p[1][2]=y3;
 p[2][0]=1;
 p[2][1]=1;
 p[2][2]=1;
 line(x1,y1,x2,y2);
 line(x2,y2,x3,y3);
 line(x3,y3,x1,y1);
 getch();
 printf("\n1.Translation\n2.Rotation\n3.Scalling\n4.exit");
 printf("Enter your choice:");
 scanf("%d",&c);
 switch(c)
 {
  case 1:
	  printf("\nEnter the translation factor");
	  scanf("%d%d",&xt,&yt);
	  ax1=x1+xt;
	  ay1=y1+yt;
	  ax2=x2+xt;
	  ay2=y2+yt;
	  ax3=x3+xt;
	  ay3=y3+yt;
	  tr[0][2]=xt;
	  tr[1][2]=yt;
	  for(i=0;i<3;i++)
	  {
	   for(j=0;j<3;j++)
	   {
	    if(i==j)
	    {
	     tr[i][j]=1;
	    }
	   }
	  }
	  cleardevice();
	  printf("P=\n");
	  for(i=0;i<3;i++)
	  {
	   for(j=0;j<3;j++)
	   {
	    printf("%d ",p[i][j]);
	   }
	   printf("\n");
	  }
	  printf("T=\n");
	  for(i=0;i<3;i++)
	  {
	   for(j=0;j<3;j++)
	   {
	    printf("%d ",tr[i][j]);
	   }
	   printf("\n");
	  }
	  for(i=0;i<3;i++)
	  {
	   for(j=0;j<3;j++)
	   {
	    for(k=0;k<3;k++)
	    p1[i][j]=p1[i][j]+tr[i][k]*p[k][j];
	   }
	  }
	  printf("P'=\n");
	  for(i=0;i<3;i++)
	  {
	   for(j=0;j<3;j++)
	   {
	    printf("%d ",p1[i][j]);
	   }
	   printf("\n");
	  }
	  line(ax1,ay1,ax2,ay2);
	  line(ax2,ay2,ax3,ay3);
	  line(ax3,ay3,ax1,ay1);
	  getch();
	  break;
  case 2:
	  printf("\nEnter the angle of rotation:");
	  scanf("%d",&rt);
	  t=3.14*rt/180;
	  ax1=abs(x1*cos(t)-y1*sin(t));
	  ay1=abs(x1*sin(t)+y1*cos(t));
	  ax2=abs(x2*cos(t)-y2*sin(t));
	  ay2=abs(x2*sin(t)+y2*cos(t));
	  ax3=abs(x3*cos(t)-y3*sin(t));
	  ay3=abs(x3*sin(t)+y3*cos(t));

	  r[0][0]=cos(t);
	  r[0][1]=-sin(t);
	  r[0][2]=0;
	  r[1][0]=sin(t);
	  r[1][1]=cos(t);
	  r[1][2]=0;
	  r[2][0]=0;
	  r[2][1]=0;
	  r[2][2]=1;
	  cleardevice();
	  for(i=0;i<3;i++)
	  {
	   for(j=0;j<3;j++)
	   {
	    for(k=0;k<3;k++)
	    p1[i][j]=abs(p1[i][j]+r[i][k]*p[k][j]);
	   }
	  }
	  printf("P=\n");
	  for(i=0;i<3;i++)
	  {
	   for(j=0;j<3;j++)
	   {
	    printf("%d ",p[i][j]);
	   }
	   printf("\n");
	  }
	  printf("R=\n");
	  for(i=0;i<3;i++)
	  {
	   for(j=0;j<3;j++)
	   {
	    printf("%f ",r[i][j]);
	   }
	   printf("\n");
	  }
	  printf("P'=\n");
	  for(i=0;i<3;i++)
	  {
	   for(j=0;j<3;j++)
	   {
	    printf("%d ",p1[i][j]);
	   }
	   printf("\n");
	  }
	  line(ax1,ay1,ax2,ay2);
	  line(ax2,ay2,ax3,ay3);
	  line(ax3,ay3,ax1,ay1);
	  getch();
	  break;
  case 3:
	  printf("\nEnter the scalling factor:");
	  scanf("%d%d",&sx,&sy);
	  ax1=x1*sx;
	  ay1=y1*sy;
	  ax2=x2*sx;
	  ay2=y2*sy;
	  ax3=x3*sx;
	  ay3=y3*sy;
	  cleardevice();
	  for(i=0;i<3;i++)
	  {
	   for(j=0;j<3;j++)
	   {
	    s[i][j]=0;
	   }
	  }
	  s[0][0]=sx;
	  s[1][1]=sy;
	  s[2][2]=1;
	  printf("P=\n");
	  for(i=0;i<3;i++)
	  {
	   for(j=0;j<3;j++)
	   {
	    printf("%d ",p[i][j]);
	   }
	   printf("\n");
	  }
	  printf("S=\n");
	  for(i=0;i<3;i++)
	  {
	   for(j=0;j<3;j++)
	   {
	    printf("%d ",s[i][j]);
	   }
	   printf("\n");
	  }
	  for(i=0;i<3;i++)
	  {
	   for(j=0;j<3;j++)
	   {
	    for(k=0;k<3;k++)
	    p1[i][j]=p1[i][j]+s[i][k]*p[k][j];
	   }
	  }
	  printf("P'=\n");
	  for(i=0;i<3;i++)
	  {
	   for(j=0;j<3;j++)
	   {
	    printf("%d ",p1[i][j]);
	   }
	   printf("\n");
	  }
	  line(ax1,ay1,ax2,ay2);
	  line(ax2,ay2,ax3,ay3);
	  line(ax3,ay3,ax1,ay1);
	  getch();
	  break;
  case 4:
	  break;
  default:
	  printf("Enter the correct choice");
 }
 closegraph();
}