#include <time.h>
#include "Rectangle.h"
#include "Circle.h"
#include <stdlib.h>
#include <Windows.h>
void main()
{
	PlaySoundA("shooting_stars.wav", NULL, SND_ASYNC); 
	// Adjust window size
	setWindowSize(800, 400);
	Circle c;
	Rect r[100];
	Rect r2[100];
	int a=425, a2=425, b=50, b2=350, h1[100], h2[100], h[100], flag=1;
	int x1[100], y1[100], x2[100], y2[100];
	srand(time(NULL));
	
	for(int i=0; i<100; i++)
	{
		h[i]=0;
		h1[i]=200;
		h2[i]=200;
		h[i]+=rand()%180;
		h1[i]+=h[i];
		h2[i]-=h[i];
		r[i].setXY(a,b);
		r[i].setWH(50,h1[i]);
		a+=200;
		r2[i].setXY(a2,b2);
		r2[i].setWH(50,h2[i]);
		a2+=200;
	}

	while(!getKey(' ')){
		int x = c.getX();
		int y = c.getY()+3;
		c.move(x,y);
		Sleep(10);

		if (getKey('W'))
		{
			x = c.getX();
			y = c.getY()-8;
			c.move(x,y);
		}

		for(int i=0; i<100; i++)
		{
			x1[i] = r[i].getX()-5;
			y1[i] = r[i].getY();
			r[i].move(x1[i],y1[i]);
			Sleep(0.1);
			x2[i] = r2[i].getX()-5;
			y2[i] = r2[i].getY();
			r2[i].move(x2[i],y2[i]);
			Sleep(0.1);

			if((x1[i]-10)<=75 && (x1[i]-15)>=0)
			{
				if(y==(y1[i]+(h1[i]/2)+25))
				{
					PlaySoundA("sad_trombone", NULL, SND_ASYNC); 
					drawText(500,250,"GAME OVER");
					flag=0;
					break;
				}
				if(x<=(x1[i]+25) && y<=(y1[i]+(h1[i]/2)+25))
				{
					PlaySoundA("sad_trombone", NULL, SND_ASYNC); 
					drawText(500,250,"GAME OVER");
					flag=0;
					break;
				}
			}

			if((x2[i]-10)<=75 && (x2[i]-15)>=0)
			{
				if(y==(y2[i]-(h2[i]/2)-25))
				{
					PlaySoundA("sad_trombone", NULL, SND_ASYNC); 
					drawText(500,250,"GAME OVER");
					flag=0;
					break;
				}
				if(x<=(x2[i]+25) && y>=(y2[i]-(h2[i]/2)-25))
				{
					PlaySoundA("sad_trombone", NULL, SND_ASYNC); 
					drawText(500,250,"GAME OVER");
					flag=0;
					break;
				}
			}
		}

		if(flag==0)
			break;

		if(x1[99]<=0 || x2[99]<=0)
		{
			PlaySoundA("win_sound", NULL, SND_ASYNC);
			drawText(500,250,"YOU WIN!");
			break;
		}

	}

	system("pause");
}
