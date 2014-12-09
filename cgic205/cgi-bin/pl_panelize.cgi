#!/usr/bin/perl
use strict;
use CGI qw(:standard);
use CGI::Carp qw(fatalsToBrowser);

sub paneller{
  my($pW, $pH, $bW, $bH, $Step, $a, $b) = @_;
  my $A;
  my $B; 
 
  $A = $bW; 
  $B = $bH; 
  $a=$b=0; 
 
  while ($A <= $pW) 
  { 
    $A += $bW + $Step; 
    ($a)++; 
  } 
  while ($B <= $pH) 
  { 
    $B += $bH + $Step; 
    ($b)++; 
  } 
  return(($a) * ($b)); 
}

sub panellera{
  my($pW, $pH, $bW, $bH, $Step, $a, $b) = @_;
  my $A;
  my $B; 
 
  $A = $bW; 
  $B = $bH; 
  $a=$b=0; 
 
  while ($A <= $pW) 
  { 
    $A += $bW + $Step; 
    ($a)++; 
  } 
  while ($B <= $pH) 
  { 
    $B += $bH + $Step; 
    ($b)++; 
  } 
  return($a); 
}

sub panellerb{
  my($pW, $pH, $bW, $bH, $Step, $a, $b) = @_;
  my $A;
  my $B; 
 
  $A = $bW; 
  $B = $bH; 
  $a=$b=0; 
 
  while ($A <= $pW) 
  { 
    $A += $bW + $Step; 
    ($a)++; 
  } 
  while ($B <= $pH) 
  { 
    $B += $bH + $Step; 
    ($b)++; 
  } 
  return($b); 
}

sub scrapof { 
  my ($len, $cnt, $len2, $Step) =  @_;
 
  return( $len - $cnt * ($len2 + $Step)); 
} 

sub Get_Step {
	if (param('Panel_Step'))
	{
	   return (param('Panel_Step'));
	}
	else
	{
		return (.10);
	}
}  

sub Get_Height {
	if (param('Board_Height'))
	{
		return (param('Board_Height'));
	}
	else
	{
		return (5.25);
	}
}
sub Get_Width {
	if (param('Board_Width'))
	{
		return (param('Board_Width'));
	}
	else
	{
		return (3.25);
	}
}


  my $Panel_H = 22.70; 
  my $Panel_W = 16.90; 
  my $Half_Panel_W = 11.3; 
  my $Third_Panel_W = 7.15;
  my $Border= .001;
  my $a;
  my $b;
  my @h;
  my @v;
  my @h_h;
  my @v_h;
  my @h_t;
  my @v_t; 
  my $scrapX;
  my $scrapY; 
  my $Step = Get_Step();
  my $Bd_Height = Get_Height();
  my $Bd_Width = Get_Width();
  my $Bd_H = ($Bd_Height * 20);
  my $Bd_W = ($Bd_Width * 20);
  
  my $New_Panel_H = $Panel_H - ($Border *2); 
  my $New_Panel_W = $Panel_W - ($Border *2); 
  my $New_Half_Panel_W = $Half_Panel_W - ($Border *2); 
  my $New_Third_Panel_W = $Third_Panel_W - ($Border *2);
  
  $h[2] = paneller($New_Panel_W, $New_Panel_H, $Bd_Width, $Bd_Height, $Step, $a, $b);
  $h[0] = panellera($New_Panel_W, $New_Panel_H, $Bd_Width, $Bd_Height, $Step, $a, $b);  
  $h[1] = panellerb($New_Panel_W, $New_Panel_H, $Bd_Width, $Bd_Height, $Step, $a, $b);
  $scrapX = scrapof($New_Panel_W, $a, $Bd_Width, $Step);  
  $scrapY = scrapof($New_Panel_H, $b, $Bd_Height, $Step);  
  my $hSr = paneller($scrapX, $New_Panel_H, $Bd_Height, $Bd_Width, $Step, $a, $b);  
  my $hSb = paneller($New_Panel_W, $scrapY, $Bd_Height, $Bd_Width, $Step, $a, $b); 
  
  $v[2] = paneller($New_Panel_H, $New_Panel_W, $Bd_Width, $Bd_Height, $Step, $a, $b);  
  $v[0] = panellera($New_Panel_H, $New_Panel_W, $Bd_Width, $Bd_Height, $Step, $a, $b);
  $v[1] = panellerb($New_Panel_H, $New_Panel_W, $Bd_Width, $Bd_Height, $Step, $a, $b);
  $scrapX = scrapof($New_Panel_H, $a, $Bd_Width, $Step);  
  $scrapY = scrapof($New_Panel_W, $b, $Bd_Height, $Step);  
  my $vSr = paneller($scrapX, $New_Panel_W, $Bd_Height, $Bd_Width, $Step, $a, $b);  
  my $vSb = paneller($New_Panel_H, $scrapY, $Bd_Height, $Bd_Width, $Step, $a, $b); 
   
   
  $h_h[2] = paneller($New_Half_Panel_W, $New_Panel_W, Bd_Width, Bd_Height, Step, &a, &b);  
  $h_h[0] = panellera($New_Half_Panel_W, $New_Panel_W, Bd_Width, Bd_Height, Step, &a, &b);
  $h_h[1] = panellerb($New_Half_Panel_W, $New_Panel_W, Bd_Width, Bd_Height, Step, &a, &b);
  $scrapX = scrapof($New_Half_Panel_W, $a, $Bd_Width, $Step);  
  $scrapY = scrapof($New_Panel_W, $b, $Bd_Height, $Step);  
  my $h_hSr = paneller($scrapX, $New_Panel_W, $Bd_Height, $Bd_Width, $Step, $a, $b);  
  my $h_hSb = paneller($New_Half_Panel_W, $scrapY, $Bd_Height, $Bd_Width, $Step, $a, $b); 
  
  $v_h[2] = paneller($New_Panel_W, $New_Half_Panel_W, $Bd_Width, $Bd_Height, $Step, $a, $b);
  $v_h[0] = panellera($New_Panel_W, $New_Half_Panel_W, $Bd_Width, $Bd_Height, $Step, $a, $b);
  $v_h[1] = panellerb($New_Panel_W, $New_Half_Panel_W, $Bd_Width, $Bd_Height, $Step, $a, $b);  
  $scrapX = scrapof($New_Panel_W, $a, $Bd_Width, $Step);  
  $scrapY = scrapof($New_Half_Panel_W, $b, $Bd_Height, $Step);  
  my $v_hSr = paneller($scrapX, $New_Half_Panel_W, $Bd_Height, $Bd_Width, $Step, $a, $b);  
  my $v_hSb = paneller($New_Panel_W, $scrapY, $Bd_Height, $Bd_Width, $Step, $a, $b);  
   
  $h_t[2]= paneller($New_Third_Panel_W, $New_Panel_W, $Bd_Width, $Bd_Height, $Step, $a, $b);  
  $h_t[0]= panellera($New_Third_Panel_W, $New_Panel_W, $Bd_Width, $Bd_Height, $Step, $a, $b);
  $h_t[1]= panellerb($New_Third_Panel_W, $New_Panel_W, $Bd_Width, $Bd_Height, $Step, $a, $b);
  $scrapX = scrapof($New_Third_Panel_W, $a, $Bd_Width, $Step);  
  $scrapY = scrapof($New_Panel_W, $b, $Bd_Height, $Step);  
  my $h_tSr = paneller($scrapX, $New_Panel_W, $Bd_Height, $Bd_Width, $Step, $a, $b);  
  my $h_tSb = paneller($New_Third_Panel_W, $scrapY, $Bd_Height, $Bd_Width, $Step, $a, $b); 
  
  $v_t[2] = paneller($New_Panel_W, $New_Third_Panel_W, $Bd_Width, $Bd_Height, $Step, $a, $b);  
  $v_t[0] = panellera($New_Panel_W, $New_Third_Panel_W, $Bd_Width, $Bd_Height, $Step, $a, $b);
  $v_t[1] = panellerb(New_Panel_W, $New_Third_Panel_W, $Bd_Width, $Bd_Height, $Step, $a, $b);
  $scrapX = scrapof($New_Panel_W, $a, $Bd_Width, $Step);  
  $scrapY = scrapof($New_Third_Panel_W, $b, $Bd_Height, $Step);  
  my $v_tSr = paneller($scrapX, $New_Third_Panel_W, $Bd_Height, $Bd_Width, $Step, $a, $b);  
  my $v_tSb = paneller($New_Panel_W, $scrapY, $Bd_Height, $Bd_Width, $Step, $a, $b);  
  
  