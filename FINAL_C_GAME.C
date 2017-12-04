#include <graphics.h>//drivers,bgi files,grapical modes.
#include <stdlib.h>//memory allocation.
#include <dos.h>//windows files compatibilty.
#include <conio.h>//to use kbhit function.
#include <stdio.h>//standard input-output function.
#include <time.h>//to fetch system time for various purposes.

int m[500],n[500],z[500],c[500],f[500],g[500],slen=5,TEMP;
clock_t start,stop;//to fetch processor ticks count.
verify();//for checking while the whole program executes.
finish();//end of the game.
win();//winning of the game.
void main()//start of main funtion.
{
int gd=DETECT,gm,l,ch,maxx,maxy,s=65,d=70,x=13,y=14,p,q,spd=100;
int a=0,i=0,j,t,temp;
initgraph(&gd,&gm,"..//bgi");
setbkcolor(GREEN);
circle(50,50,8);
circle(60,50,8);
circle(70,50,8);
circle(80,50,8);
circle(80,60,8);
circle(80,70,8);
circle(80,80,8);
circle(80,90,8);
circle(50,50,8);
circle(50,60,8);
circle(50,70,8);
circle(50,80,8);
setcolor(WHITE);
setfillstyle(SOLID_FILL,1);
circle(50,90,15);
circle(90,90,8);
circle(100,90,8);
circle(110,90,8);
circle(120,90,8);
circle(120,80,8);
circle(120,70,5);
outtextxy(200,200,"WELCOME TO SNAKE GAME");
floodfill(50,50,WHITE);
getch();
getch();
cleardevice();
setcolor(YELLOW);//welcome screen text color.
settextstyle(5,0,5);//line 1st style.
outtextxy(20,10,"HELLO...Play Please :P  ");
settextstyle(3,0,2);//style of next 5 lines.
outtextxy(20,80," Use Arrow Keys To Direct The Snake ");
outtextxy(20,140," Do NOT let snake touch any part of itself.");
outtextxy(20,160,"Eat the food to win the game. ");
outtextxy(20,200," Press 'Esc' key  ANYTIME To Exit ");
settextstyle(3,0,3);
outtextxy(20,220," Press ONLY DIRECTION KEYS To Continue....Your Choice ");
settextstyle(6,0,3);//style of last line.
outtextxy(20,260,"GOOD SCORES FOR MINOR1 ARE REQUIRED...:P. ");
ch=getch();//to check the key pressed value.
if(ch==27) exit(0);
cleardevice();//clears all the memory.

maxx=getmaxx();//to get the maximum value of x.
maxy=getmaxy();//to get the maximum value of y.

randomize();//random function.

p=random(maxx);
temp=p%13;
p=p-temp;//store a random value in p.
q=random(maxy);
temp=q%14;
q=q-temp;//store a random value in q.



 start=clock();//clock starts.
 while(1)//while the loop is true.
{

 setcolor(WHITE);//set the color of the food cirlce outline.
 setfillstyle(SOLID_FILL,slen+1);//fills the style in the food like slash,hatch,xhatch,useretc with the int color.
 circle(p,q,5);//circle of food.
 floodfill(p,q,WHITE);//area bound i.e inside or outside of the circle.

   if( kbhit() )//kbhit==keyboard hit or key binding hit, this checks whethera key is pressed or not.
   {
     ch=getch(); if(ch==0) ch=getch();
     if(ch==72&& a!=2) a=1;//up key pressed and moves up
     if(ch==80&& a!=1) a=2;//down key pressed and moves down
     if(ch==75&& a!=4) a=3;//left key pressed and moves left
     if(ch==77&& a!=3) a=4;//right key pressed and moves right
      }
       else
     {
     if(ch==27)//ESC key pressed and exit.
	break;
     }

       if(i<5){
		   m[i]=x;
		   n[i]=y;
		   i++;
	       }

		 if(i>=5)

		 {
		  for(j=slen;j>=0;j--){
				  m[1+j]=m[j];
			  n[1+j]=n[j];
				  }
		   m[0]=x;
		   n[0]=y;

		   setcolor(WHITE);
		   setfillstyle	(SOLID_FILL,slen);
		   circle(m[0],n[0],8);
		   floodfill(m[0],n[0],WHITE);

		   setcolor(WHITE);
		   for(j=1;j<slen;j++){
		  setfillstyle(SOLID_FILL,slen+j%3);
		   circle(m[j],n[j],5);
		   floodfill(m[j],n[j],WHITE);
				      }
       delay(spd);

		  setcolor(BLACK);
		  setfillstyle(SOLID_FILL,BLACK);
		   circle(m[0],n[0],8);
		   floodfill(m[0],n[0],BLACK);

		   setcolor(BLACK);
		  setfillstyle(SOLID_FILL,BLACK);
		   circle(m[j],n[j],5);
		   floodfill(m[j],n[j],BLACK);

		   }
       if(i<5){
		   f[i]=s+13;
		   g[i]=d+14;
		   i++;
	       }

		 if(i>=5)

		 {
		  for(j=slen;j>=0;j--){
				  f[1+j]=f[j];
			  g[1+j]=g[j];
				  }
		   f[0]=s+13;
		   g[0]=d+14;

		   setcolor(WHITE);
		   setfillstyle	(SOLID_FILL,slen-6);
		   circle(f[0],g[0],8);
		   floodfill(f[0],g[0],WHITE);

		   setcolor(WHITE);
		   for(j=1;j<slen;j++){
		  setfillstyle(SOLID_FILL,slen+j%9);
		   circle(f[j],g[j],5);
		   floodfill(f[j],g[j],WHITE);
				      }
       delay(spd);

		  setcolor(BLACK);
		  setfillstyle(SOLID_FILL,BLACK);
		   circle(f[0],g[0],8);
		   floodfill(f[0],g[0],BLACK);

		   setcolor(BLACK);
		  setfillstyle(SOLID_FILL,BLACK);
		   circle(f[j],g[j],5);
		   floodfill(f[j],g[j],BLACK);

		   }




if(i<5){
		   z[i]=p+13;
		   c[i]=q+14;
		   i++;
	       }

		 if(i>=5)

		 {
		  for(j=slen;j>=0;j--){
				  z[1+j]=z[j];
			  c[1+j]=c[j];
				  }
		   z[0]=p;
		   c[0]=q;

		   setcolor(WHITE);
		   setfillstyle	(SOLID_FILL,slen%2);
		   circle(z[0],c[0],8);
		   floodfill(z[0],c[0],WHITE);

		   setcolor(WHITE);
		   for(j=1;j<slen;j++){
		  setfillstyle(SOLID_FILL,slen+j%3);
		   circle(z[j],c[j],5);
		   floodfill(z[j],c[j],WHITE);
				      }
       delay(spd);

		  setcolor(BLACK);
		  setfillstyle(SOLID_FILL,BLACK);
		   circle(z[0],c[0],8);
		   floodfill(z[0],c[0],BLACK);

		   setcolor(BLACK);
		  setfillstyle(SOLID_FILL,BLACK);
		   circle(z[j],c[j],5);
		   floodfill(z[j],c[j],BLACK);

		   }
     stop=clock();
     //t=(stop-start)/CLK_TCK;
     //printf(" TIME %d sec   ",t);
     verify();
    // printf("%d",t);
    if(x==p&&y==q) { slen=slen+1; if(spd>=5) spd=spd-5; else spd=5;
				      if(slen>15) win();
     p=random(maxx); temp=p%13;  p=p-temp;
     q=random(maxy); temp=q%14;   q=q-temp;
				    }
    if(a==1)  y =  y-14; if(y<0) { temp=maxy%14;y=maxy-temp;}
    if(a==2)  y =  y+14; if(y>maxy) y=0;
    if(a==3)  x =  x-13; if(x<0) { temp=maxx%13;x=maxx-temp;}
    if(a==4)  x =  x+13; if(x>maxx) x=0;
    if(a==0){  y = y+14 ;  x=x+13; }
    p=p+13; if(p>maxx){p=0;}
    q=q+0;// if(q>maxy){q=0;}
s=s+13;if(s>maxx){s=0;}
d=d+14; if(d>maxy){d=0;}
	
}
	    }
int verify(){
   int a;
   for(a=1;a<slen;a++)

if(m[0]==m[a]&&n[0]==n[a]  ||  m[0]==z[a]&&n[0]==c[a]    || m[0]==f[a]&&n[0]==g[a])


 finish();
   else continue;
    return 0;
   }
int finish()

{

    int j,i;
   setcolor(WHITE);
   for(i=0;i<2;i++){
   delay(500);
    cleardevice();
    delay(500);
   for(j=0;j<=slen;j++){
		   setfillstyle(SOLID_FILL,RED);
		   circle(m[j],n[j],5);
		   floodfill(m[j],n[j],WHITE);
		  }

		 }

    settextstyle(3,0,4);
    outtextxy(150,150,"    GAME OVER ");
    printf("SCORE=%d",slen-5);
    getch();
    getch();
printf("...#........................#........\n");
printf("..  #.......................#...........\n");
printf("...  #......................#.#.#.#..#..........#........\n");
printf("...   #....................#..#......#..........#..........\n");
printf("...   #       #..#.........#.#.......#..........#.......\n");
printf("...    #....#.....#.......#..#.#.....#..........#...\n");
printf("...    #..#.........#...#....#.......#..........#............\n");
printf("...     #.............#......#.#.#...#.#.##.#...#.##.###..\n");
printf("...#########.................................\n");
printf("...	#..................................\n");
printf("..	#....#.##.#.#..######.######.######....................\n");
printf("...	#....#......#.....#...#......#.....#.....\n");
printf("...	#....#......#.....#...#......#......#...\n");
printf("...	#....#.#..#.#.....#...#......#.......#.....\n");
printf("...	#....#...#........#...####...#.......#.....\n");
printf("...	#....#.....#......#...#......#......#....\n");
printf("...	#....#.......#....#...#......#.....#....\n");
printf("...	#....#........#.#####.######.######...........\n");    getch();
    exit(0);
    return 0;
    }

int win()
{
int j,i;
setcolor(WHITE);
   for(i=0;i<5;i++){
   for(j=0;j<=slen;j++){
		   setfillstyle(SOLID_FILL,slen);
		   circle(m[j],n[j],5);
			 floodfill(m[j],n[j],WHITE);
		  }
    delay(500);
    cleardevice();
    delay(500);
		 }
  settextstyle(3,0,4);
  outtextxy(210,320," YOU WIN ");
  printf("MAX _HIGH_SCORE=%d",slen-5);
  getch();
exit(0);
return 0;
}