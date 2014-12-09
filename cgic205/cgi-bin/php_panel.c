#include <stdio.h>
#include <math.h>
#include "cgic.h"

/*  
  Paneller thing.  
  Written by Jacque Donahue & An Vu Ly
              x73823          my C mentor
  To be used with the cgic library.
  
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
  



int panellera  
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
  return (*a);  
} 




int panellerb  
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
  return (*b);  
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
    if(!Bd_Width) {
    		Bd_Width = 3.25;
    	}
    return Bd_Width;}

double Get_Height(){
    double Bd_Height;
    cgiFormDouble("Board_Height", &Bd_Height, 0);
    if(!Bd_Height) {
    		Bd_Height = 5.25;
    	}
    return Bd_Height;}

double Get_Step(){
    double P_Step;
    cgiFormDouble("Panel_Step", &P_Step, 0);
    if (!P_Step) {
    	P_Step = .10;
    }
    return P_Step;}
	
int cgiMain() 
{
  
  /* These are the editable variables  _H = Height _W = Width */
  double Third_Panel_W = 7.15; 
  double Panel_H = 22.70;  
  double Panel_W = 16.90;  
  double Half_Panel_W = 11.3;  
  double Border= .00, Step;  
  int a, b, h[3], v[3], h_h[3], v_h[3], h_t[3], v_t[3], Bd_H, Bd_W;  
  double scrapX, scrapY;  
  double Bd_Height ;
  double Bd_Width ;
      
  double New_Panel_H = Panel_H - (Border *2);  
  double New_Panel_W = Panel_W - (Border *2);  
  double New_Half_Panel_W = Half_Panel_W - (Border *2);  
  double New_Third_Panel_W = Third_Panel_W - (Border *2);
  int hSr, hSb, vSr, vSb, h_hSr, h_hSb, v_hSr, v_hSb, h_tSr, h_tSb, v_tSr, v_tSb;
  
  /* This was my experimenting with environment variables, didn't work :( */
  static char Person[20] = "didn't work";
  static char OS[25] = "Nope";
  strcpy( OS, cgiUserAgent);
  strcpy( Person, cgiRemoteHost);
  
  
  /*Person = cgiRemoteHost;*/
  
 /*cgiFormDouble("Board_Width", &Bd_Width, 0);	
  cgiFormDouble("Board_Height", &Bd_Height, 0);
*/

  Bd_Width = Get_Width();
  Bd_Height = Get_Height();
  Step = Get_Step();

  h[2] = paneller(New_Panel_W, New_Panel_H, Bd_Width, Bd_Height, Step, &a, &b);
  h[0] = panellera(New_Panel_W, New_Panel_H, Bd_Width, Bd_Height, Step, &a, &b);  
  h[1] = panellerb(New_Panel_W, New_Panel_H, Bd_Width, Bd_Height, Step, &a, &b);
  scrapX = scrapof(New_Panel_W, a, Bd_Width, Step);  
  scrapY = scrapof(New_Panel_H, b, Bd_Height, Step);  
  hSr = paneller(scrapX, New_Panel_H, Bd_Height, Bd_Width, Step, &a, &b);  
  hSb = paneller(New_Panel_W, scrapY, Bd_Height, Bd_Width, Step, &a, &b); 
  
  v[2] = paneller(New_Panel_H, New_Panel_W, Bd_Width, Bd_Height, Step, &a, &b);  
  v[0] = panellera(New_Panel_H, New_Panel_W, Bd_Width, Bd_Height, Step, &a, &b);
  v[1] = panellerb(New_Panel_H, New_Panel_W, Bd_Width, Bd_Height, Step, &a, &b);
  scrapX = scrapof(New_Panel_H, a, Bd_Width, Step);  
  scrapY = scrapof(New_Panel_W, b, Bd_Height, Step);  
  vSr = paneller(scrapX, New_Panel_W, Bd_Height, Bd_Width, Step, &a, &b);  
  vSb = paneller(New_Panel_H, scrapY, Bd_Height, Bd_Width, Step, &a, &b); 
   
   
  h_h[2] = paneller(New_Half_Panel_W, New_Panel_W, Bd_Width, Bd_Height, Step, &a, &b);  
  h_h[0] = panellera(New_Half_Panel_W, New_Panel_W, Bd_Width, Bd_Height, Step, &a, &b);
  h_h[1] = panellerb(New_Half_Panel_W, New_Panel_W, Bd_Width, Bd_Height, Step, &a, &b);
  scrapX = scrapof(New_Half_Panel_W, a, Bd_Width, Step);  
  scrapY = scrapof(New_Panel_W, b, Bd_Height, Step);  
  h_hSr = paneller(scrapX, New_Panel_W, Bd_Height, Bd_Width, Step, &a, &b);  
  h_hSb = paneller(New_Half_Panel_W, scrapY, Bd_Height, Bd_Width, Step, &a, &b); 
  
  v_h[2] = paneller(New_Panel_W, New_Half_Panel_W, Bd_Width, Bd_Height, Step, &a, &b);
  v_h[0] = panellera(New_Panel_W, New_Half_Panel_W, Bd_Width, Bd_Height, Step, &a, &b);
  v_h[1] = panellerb(New_Panel_W, New_Half_Panel_W, Bd_Width, Bd_Height, Step, &a, &b);  
  scrapX = scrapof(New_Panel_W, a, Bd_Width, Step);  
  scrapY = scrapof(New_Half_Panel_W, b, Bd_Height, Step);  
  v_hSr = paneller(scrapX, New_Half_Panel_W, Bd_Height, Bd_Width, Step, &a, &b);  
  v_hSb = paneller(New_Panel_W, scrapY, Bd_Height, Bd_Width, Step, &a, &b);  
   
  h_t[2]= paneller(New_Third_Panel_W, New_Panel_W, Bd_Width, Bd_Height, Step, &a, &b);  
  h_t[0]= panellera(New_Third_Panel_W, New_Panel_W, Bd_Width, Bd_Height, Step, &a, &b);
  h_t[1]= panellerb(New_Third_Panel_W, New_Panel_W, Bd_Width, Bd_Height, Step, &a, &b);
  scrapX = scrapof(New_Third_Panel_W, a, Bd_Width, Step);  
  scrapY = scrapof(New_Panel_W, b, Bd_Height, Step);  
  h_tSr = paneller(scrapX, New_Panel_W, Bd_Height, Bd_Width, Step, &a, &b);  
  h_tSb = paneller(New_Third_Panel_W, scrapY, Bd_Height, Bd_Width, Step, &a, &b); 
  
  v_t[2] = paneller(New_Panel_W, New_Third_Panel_W, Bd_Width, Bd_Height, Step, &a, &b);  
  v_t[0] = panellera(New_Panel_W, New_Third_Panel_W, Bd_Width, Bd_Height, Step, &a, &b);
  v_t[1] = panellerb(New_Panel_W, New_Third_Panel_W, Bd_Width, Bd_Height, Step, &a, &b);
  scrapX = scrapof(New_Panel_W, a, Bd_Width, Step);  
  scrapY = scrapof(New_Third_Panel_W, b, Bd_Height, Step);  
  v_tSr = paneller(scrapX, New_Third_Panel_W, Bd_Height, Bd_Width, Step, &a, &b);  
  v_tSb = paneller(New_Panel_W, scrapY, Bd_Height, Bd_Width, Step, &a, &b);   
	
	Bd_H = (Bd_Height * 20);
  Bd_W = (Bd_Width * 20);
   
	fprintf(cgiOut, "%3.3f\n%3.3f\n", Bd_Width, Bd_Height);
  fprintf(cgiOut, "%1.2f\n", Step);
  
  fprintf(cgiOut, "%d\n" ,h[2]);
  fprintf(cgiOut, "%d\n%d\n",Bd_H, Bd_W);
  fprintf(cgiOut, "%d\n%d\n",h[0], h[1]);
  fprintf(cgiOut, "%d\n", h[2]+hSr ); 
  fprintf(cgiOut, "%d\n", h[2]+hSb ); 
  fprintf(cgiOut, "%d\n", v[2]);
  fprintf(cgiOut, "%d\n%d\n",Bd_W, Bd_H);
  fprintf(cgiOut, "%d\n%d\n",v[1], v[0]); 
  fprintf(cgiOut, "%d\n", v[2]+vSr ); 
  fprintf(cgiOut, "%d\n", v[2]+vSb ); 
   
  fprintf(cgiOut, "%d\n" ,h_h[2] );
  fprintf(cgiOut, "%d\n%d\n",Bd_H, Bd_W);
  fprintf(cgiOut, "%d\n%d\n",h_h[0], h_h[1]); 
  fprintf(cgiOut, "%d\n",  h_h[2]+h_hSr ); 
  fprintf(cgiOut, "%d\n", h_h[2]+h_hSb ); 
  fprintf(cgiOut, "%d\n", v_h[2] );
  fprintf(cgiOut, "%d\n%d\n",Bd_W, Bd_H); 
  fprintf(cgiOut, "%d\n%d\n",v_h[1], v_h[0]);
  fprintf(cgiOut, "%d\n", v_h[2]+v_hSr ); 
  fprintf(cgiOut, "%d\n", v_h[2]+v_hSb ); 
   
  fprintf(cgiOut, "%d\n" ,h_t[2] );
  fprintf(cgiOut, "%d\n%d\n",Bd_H, Bd_W);
  fprintf(cgiOut, "%d\n%d\n",h_t[0], h_t[1]); 
  fprintf(cgiOut, "%d\n",  h_t[2]+h_tSr ); 
  fprintf(cgiOut, "%d\n", h_t[2]+h_tSb ); 
  fprintf(cgiOut, "%d\n", v_t[2] ); 
  fprintf(cgiOut, "%d\n%d\n",Bd_W, Bd_H);
  fprintf(cgiOut, "%d\n%d\n",v_t[1], v_t[0]);
  fprintf(cgiOut, "%d\n", v_t[2]+v_tSr ); 
  fprintf(cgiOut, "%d\n", v_t[2]+v_tSb );  
 
  return 0; 
}  
 
