#include <stdio.h>
#include <math.h>
#include "cgic.h"
/*  
  Paneller thing.  
  gcc panel1.cpp -lm -liostream  
*/  
  

int paneller  
(  
  double pW,  
  double pH,  
  double bW,  
  double bH,  
  double Step,  
  int* a,  
  int* b  
)  
{  
  double A, B;  
  
  A = bW;  
  B = bH;  
  *a=*b=0;  
  
  while (A <= pW)  
  {  
    A += bW + Step;  
    (*a)++;  
  }  
  while (B <= pH)  
  {  
    B += bH + Step;  
    (*b)++;  
  }  
  return( (*a) * (*b) );  
}  
  
double scrapof  
(  
  double len,  
  int cnt,  
  double len2,  
  double Step  
)  
{  
  return( len - cnt*(len2+Step) );  
}  


double Get_Width(){
    double Bd_Width;
 cgiFormDouble("Board_Width", &Bd_Width, 0);
	return Bd_Width;}
double Get_Height(){
    double Bd_Height;
 cgiFormDouble("Board_Height", &Bd_Height, 0);
        return Bd_Height;}


int cgiMain() 
{
  
   
  double Panel_H = 22.70;  
  double Panel_W = 16.90;  
  double Half_Panel_W = 11.3;  
  double Border= .001, Step = .1;  
  int a, b, h, v, h_h, v_h;  
  double scrapX, scrapY;  
  double Bd_Height ;
  double Bd_Width ;
      
  double New_Panel_H = Panel_H - (Border *2);  
  double New_Panel_W = Panel_W - (Border *2);  
  double New_Half_Panel_W = Half_Panel_W - (Border *2);  
  int hSr, hSb, vSr, vSb, h_hSr, h_hSb, v_hSr, v_hSb;
   
  

Bd_Width = Get_Width();
Bd_Height = Get_Height(); 
 
  
  h = paneller(New_Panel_W, New_Panel_H, Bd_Width, Bd_Height, Step, &a, &b);  
  scrapX = scrapof(New_Panel_W, a, Bd_Width, Step);  
  scrapY = scrapof(New_Panel_H, b, Bd_Height, Step);  
  hSr = paneller(scrapX, New_Panel_H, Bd_Height, Bd_Width, Step, &a, &b);  
  hSb = paneller(New_Panel_W, scrapY, Bd_Height, Bd_Width, Step, &a, &b); 
  
  v = paneller(New_Panel_H, New_Panel_W, Bd_Width, Bd_Height, Step, &a, &b);  
  scrapX = scrapof(New_Panel_H, a, Bd_Width, Step);  
  scrapY = scrapof(New_Panel_W, b, Bd_Height, Step);  
  vSr = paneller(scrapX, New_Panel_W, Bd_Height, Bd_Width, Step, &a, &b);  
  vSb = paneller(New_Panel_H, scrapY, Bd_Height, Bd_Width, Step, &a, &b); 
   
   
  h_h = paneller(New_Half_Panel_W, New_Panel_W, Bd_Width, Bd_Height, Step, &a, &b);  
  scrapX = scrapof(New_Half_Panel_W, a, Bd_Width, Step);  
  scrapY = scrapof(New_Panel_W, b, Bd_Height, Step);  
  h_hSr = paneller(scrapX, New_Panel_W, Bd_Height, Bd_Width, Step, &a, &b);  
  h_hSb = paneller(New_Half_Panel_W, scrapY, Bd_Height, Bd_Width, Step, &a, &b); 
  
  v_h = paneller(New_Panel_W, New_Half_Panel_W, Bd_Width, Bd_Height, Step, &a, &b);  
  scrapX = scrapof(New_Panel_W, a, Bd_Width, Step);  
  scrapY = scrapof(New_Half_Panel_W, b, Bd_Height, Step);  
  v_hSr = paneller(scrapX, New_Half_Panel_W, Bd_Height, Bd_Width, Step, &a, &b);  
  v_hSb = paneller(New_Panel_W, scrapY, Bd_Height, Bd_Width, Step, &a, &b);  
   
   
	cgiHeaderContentType("text/html"); 
	fprintf(cgiOut, "<html><head>\n"); 
	fprintf(cgiOut, "<title>Paneliz-it©</title></head>\n"); 
	fprintf(cgiOut, "<body><h1>Paneliz-it©</h1>\n"); 
 

  fprintf(cgiOut, "The width is %f and the Height is %f<br>\n", Bd_Width, Bd_Height);
  fprintf(cgiOut, "Full Panel:  <br>\n"); 
  fprintf(cgiOut, "Horizontal: %d<br>\n" ,h); 
  fprintf(cgiOut, "Horizontal + V scrap on right : %d<br>\n", h+hSr ); 
  fprintf(cgiOut, "Horizontal + V scrap on bottom: %d<br>\n", h+hSb ); 
  fprintf(cgiOut, "Vertical: %d<br>\n", v); 
  fprintf(cgiOut, "Vertical + H scrap on right : %d<br>\n", v+vSr ); 
  fprintf(cgiOut, "Vertical + H scrap on bottom: %d<br>\n", v+vSb ); 
   
  fprintf(cgiOut, "Half Panel:  \n" ); 
  fprintf(cgiOut, "Horizontal: %d<br>\n" ,h_h ); 
  fprintf(cgiOut, "Horizontal + V scrap on right : %d<br>\n",  h_h+h_hSr ); 
  fprintf(cgiOut, "Horizontal + V scrap on bottom: %d<br>\n", h_h+h_hSb ); 
  fprintf(cgiOut, "Vertical: %d<br>\n", v_h ); 
  fprintf(cgiOut, "Vertical + H scrap on right : %d<br>\n", v_h+v_hSr ); 
  fprintf(cgiOut, "Vertical + H scrap on bottom: %d<br>\n", v_h+v_hSb ); 
   
  fprintf(cgiOut, "</body></html>\n"); 
  return 0; 
}  
 
