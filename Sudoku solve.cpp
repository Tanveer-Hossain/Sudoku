#include<stdio.h>
#include<conio.h>


int table[10][10]={{0},{0}};
int table2[10][10]={{0},{0}};
int posible_num[82][10]={{0},{0}};
int in=0,solved_pos=0;
int row_start=0,column_start=0,row_end=0,column_end=0;
int SAL_num=0;
int SAL_row[82]={0};
int SAL_column[82]={0};
int SAL_value[82]={0};

int BRV[10][10][10]={ {0},{0},{0} };
int BCV[10][10][10]={ {0},{0},{0} };






int block(int i,int j)
{   void block2(int q);
    row_start=0,column_start=0,row_end=0,column_end=0;
    
    
    
    if((i>=1&&i<=3)&&(j<=3&&j>=1))
    {block2(1);
    return 1;    }
    
    else if(i>=1&&i<=3&&j<=6&&j>=4)
    {block2(2);
    return 2;    }
    
    else if(i>=1&&i<=3&&j<=9&&j>=7)
    {block2(3);
    return 3;    }
    
    else if(i<=6&&i>=4&&j<=3&&j>=1)
    {block2(4);
    return 4;    }
    
    else if(i<=6&&i>=4&&j<=6&&j>=4)
    {block2(5);
    return 5;    }
    
    else if(i<=6&&i>=4&&j<=9&&j>=7)
    {block2(6);
    return 6;    }
    
    else if(i<=9&&i>=7&&j<=3&&j>=1)
    {block2(7);
    return 7;    }
    
    else if(i<=9&&i>=7&&j<=6&&j>=4)
    {block2(8);
    return 8;    }
    
    else
    {block2(9);
    return 9;    }
    
}
    
    








void block2(int q)
{
    if(q==1 || q==2 || q==3 )
    {row_start=1; row_end=3;     }
    
    else if(q==4 || q==5 || q==6 )
    {row_start=4; row_end=6;  }
    
    else
    {row_start=7; row_end=9;}
    
    
    
    
    if(q==1 || q==4 || q==7 )
    {  column_start=1; column_end=3;}
    
    else if(q==2 || q==5 || q==8 )
    { column_start=4; column_end=6;}
    
    else
    { column_start=7; column_end=9; }
    
         
}











int check(int i,int j,int k)
{
    int m,n,q;
 
    if(k==0)
    goto label;
 
    for(m=1;m<=9;m++)
    {
    if(m==i)
    continue;
    
    if(table[m][j]==k)
    {return 1;}
   
    }
                     
                     
                     
    for(m=1;m<=9;m++)
    {
    if(m==j)
    continue;
    
    if(table[i][m]==k)
    {return 1;}
   
    } 
    
   
   
    q=block(i,j);
    
    for(m=row_start ;m<=row_end; m++)
    {for(n=column_start ;n<=column_end ; n++)
    {  if(table[m][n]==k && (!(m==i && n==j)) )
        return 1;
        }
        }
    
    
                                                    
                                           
 label:
 return 0;                 
}









void output(void)
{int m,n;
printf("\n\n");
for(m=1;m<10;m++)
{
printf("\n");
}


for(m=1;m<=9;m++)
{for(n=1;n<=9;n++)
{
                  if(table[m][n]>0)
                  {printf("%d ",table[m][n]);}
                  else
                  { printf("_ ");}
                  
                   if(n%3==0)
                   printf("  ");
                   
                   if(n==9)
                   printf("\n");
                   
                   
                   }
                   if(m%3==0)
                   printf("\n\n");
                   }
                   } 
    








void Input1(void)
{int m,n,f1,i,j,a,k;
 int last_check(void);
     f1=i=j=a=0;


     for(i=1;i<=9;i++)
     {a=0;
     
     if(n==10)
     {output(); n=1;}
     
     printf("\n\nInput value for row %d",i);
                      for(j=1;j<=9;j++)
                      {
                                     if(i==9)
                      printf("\nInput column number.Enter 0 for end.\n");
                      else
                      printf("\nInput column number.Enter 0 for next row.\n");
                      
                      scanf("%d",&k);
                     
                      if(k==0)
                      break;
                      
                      printf("\n\nInput the value of row %d  column %d\n",i,k);
                      scanf("%d",&table[i][k]);
                      
                      
                      if(table[i][k] !=0)
                      {
                      a=check(i,k,table[i][k]);
                     
                      if(a==1)
                      {printf("\nWrong input\a\a");
                      j=j-1;
                      table[i][k]=0;
                      }}
                     else
                     j=j-1;
                     
                     
                     output();
                     
                      if(j==9)
                      break;
                      }

f1=last_check();
if(f1==1)
{output();
printf("\n\awrong input");
getch();

for(n=1;n<=9;n++)
{table[i][(10-n)]=0;
}
n=10;
i=i-1;
}



                      }
                      }
                      







void Input2(void)
{
int f1=0,p,g,l,n,m=0;
unsigned long int e=0;
int last_check(void);

for(m=1;m<=9;m++)
{
printf("\nInput value for row %d\n---------\n",m);
scanf("%u",&e);

for(n=1;n<=9;n++)
{l=e%10;
e=e/10;
table[m][10-n]=l;
p=check(m,(10-n),l);

if(p==1)
{printf("\nWrong Input in row %d  column %d\n\a",m,(10-n));
getch();

for(n=1;n<=9;n++)
{table[m][(10-n)]=0;}

m=m-1;
break;
}
}

f1=last_check();
if(f1==1)
{output();
printf("\n\awrong input");
getch();

for(g=1;g<=9;g++)
{for(n=1;n<=9;n++)
table[g][(10-n)]=0;}

m=0;
}

output();
}
}








void Input(void)
{int q=0;

again:
printf("\n Choose the method you like to input");
printf("\n1.Classical\n2.Advanced\n");
scanf("%d",&q);

if(q==1)
Input1();
else if(q==2)
Input2();
else
{printf("\nWrong input\a\n");
goto again;}
}












void list(void)
{ int f2,f,e,d,a,m,n,c,b,v;
  
  f2=f=a=d=m=e=n=c=0;


for(b=0;b<=81;b++)                 
  {for(v=0;v<=9;v++)
  {posible_num[b][v]=0;}}



for(m=1;m<=9;m++)
{
for(n=1;n<=9;n++)
{
d=0;
                      
if(table[m][n]==0)              
{

for(a=1;a<=9;a++)
{
c=check(m,n,a);
if(c==0)
{d=d+1;
 posible_num[(9*(m-1)+n)][d]=a;   }
 
 }
 
 
 }
 
 posible_num[(9*(m-1)+n)][0]=d;

                 }
                 }
                 
                 



if(SAL_num>0)
{
   for(e=1;e<=SAL_num;e++)                 
    {
    
    for(f=1;f<=9;f++)
    {
    
    
    
    if( posible_num[(9*(SAL_row[e]-1)+SAL_column[e])][f]== SAL_value[e])
      {
      posible_num[((9*(SAL_row[e]-1))+(SAL_column[e]))][0]-=1;
      
      for(f2=f;f2<=100;f2++)
      {if(posible_num[(9*(SAL_row[e]-1)+SAL_column[e])][f2]==0)
      break;
     
      if(posible_num[(9*(SAL_row[e]-1)+SAL_column[e])][f2]==9)
      {posible_num[(9*(SAL_row[e]-1)+SAL_column[e])][f2]=0;
      break;}
     
      posible_num[(9*(SAL_row[e]-1)+SAL_column[e])][f2]=posible_num[(9*(SAL_row[e]-1)+SAL_column[e])][f2+1];    }
            }
        
             }
                                        
                                        
             }              
}                
                 
}













void sp_adition_list(int r,int c, int v)
{int a,p; p=0;
     for(a=0;a<=SAL_num;a++)
     {if(SAL_row[a]==r && SAL_column[a]==c && SAL_value[a]==v )
      p=1;                   }

if(p==0)
     {SAL_num+=1;
     SAL_row[SAL_num]=r;
     SAL_column[SAL_num]=c;
     SAL_value[SAL_num]=v;}
}








void sp_adition_list2(int r,int m,int n)
{int a,b;
void sp_adition_list(int r,int c, int v);
 block2(m);    
 
 for(a=row_start;a<=row_end;a++)
 {
  if(a==r)                
    continue;
 for(b=column_start;b<=column_end;b++) 
  {if(table[a][b]==0)                
  sp_adition_list(a,b,n);
  
     }}
     }
     
     
     
     
     



void sp_adition_list3(int c,int m,int n)
{
void sp_adition_list(int r,int c, int v);
     int a,b;
 block2(m); 
 
    
 for(a=column_start;a<=column_end;a++)
 {
  if(a==c)                
    continue;
 for(b=row_start;b<=row_end;b++) 
  {if(table[b][a]==0)                
  sp_adition_list(b,a,n);
  
     }}
     }
 
     
     
     
     
     
     
     
     
     
     
void row_value_list( int r,int m,int n )
{int a,p;  
p=0;

for(a=1;a<=9;a++)
{if(BRV[m][r][a]==n)
p=1;}


if(p==0)
{
 
 for(a=1;a<=9;a++)       
 {if(BRV[m][r][a]==0)
 break;}       
 
 BRV[m][r][a]=n;
 BRV[m][r][0]+=1;        
        
        }
     
 
     }









void column_value_list( int c,int m,int n )
{int a,p;  p=0;

for(a=1;a<=9;a++)
{if(BCV[m][c][a]==n)
p=1;}

if(p==0)
{
 
 for(a=1;a<=9;a++)       
 {if(BCV[m][c][a]==0)
 break;}       
 
 BCV[m][c][a]=n;
 BCV[m][c][0]+=1;        
        
        }
     
 
     }












void solve1(void)
{int last_check(void);
int m,n,a,d;

list();

for(m=1;m<=9;m++)
{for(n=1;n<=9;n++)
{
                  
  /*if(posible_num[(9*(m-1)+n)][0] != 0 )         
  {for(a=1;a<=posible_num[(9*(m-1)+n)][0];a++)       
     {    
         table[m][n]=a;
         list();
      d=last_check();
      
      if(d==1)
      sp_adition_list(m,n,a);
      
      table[m][n]=0;
      list();
      }
      }*/
                  
                  
                  
                  
                  
                  
                  
                  
if( posible_num[(9*(m-1)+n)][0] == 1 )
{
table[m][n]=posible_num[(9*(m-1)+n)][1];
solved_pos+=1;
list();

}

}
}
}










  


 
    








void solve2(void)
{
      int last_check(void);
     
     int r[10],c[10],d,k,a,b,m,n,q,i,w;
     a=b=k=m=n=q=w=i=d=0;
     
     
     for(q=0;q<=9;q++)
     for(w=0;w<=9;w++)
     for(a=0;a<=9;a++)
     {
     BRV[q][w][a]=0;
     BCV[q][w][a]=0;}

    q=w=a=0;
    
    
    
    
    
    
     d=0;
     
     list();
     
     for(m=1;m<=9;m++)
     {/*printf("\n\nb %d",m); */
                      
       for(n=1;n<=9;n++)
      {/*printf("\n  v %d",n);*/
                        
      for(i=0;i<=9;i++)
      {r[i]=c[i]=0;    }
                        
                  
      b=0;
     
     
     
      block2(m);
       for(q=row_start;q<=row_end;q++)
      {for(w=column_start;w<=column_end;w++)
      {/*printf("\nr %d  c %d",q,w);*/
    
      if(table[q][w]==0)
      {
    
      for(a=1;a<=9;a++)
      {
    
      if(posible_num[((9*(q-1))+w)][a]==n)
      {
      b=b+1;
      r[b]=q;
      c[b]=w;
      
       }
                      
                      }
    
                      }
    
    
                      }  
                      }                
    
    
       
       
      if(b>0)
      {
       
      
      for(k=1;k<=b;k++)        
      {/*printf("\nb%d v%d r%d c%d",m,n,r[k],c[k]);*/
      
        table[(r[k])][(c[k])]=n;
      list();
      d=last_check();
      
      if(d==1)
      sp_adition_list(r[k],c[k],n);
      
      table[(r[k])][(c[k])]=0;
      list();  }   
      
    
     
     if(b==1)
      {table[(r[1])][(c[1])]=n;
      solved_pos+=1;
      list(); }
    
    
    
     for(k=1;k<=b;k++)
      {
      row_value_list( r[k],m,n );
      column_value_list( c[k],m,n );
      } 
      
    
    
    } 
              
                      }
                      } 
     
     }


     
     
     
     
     
     
     
     
     
     
     
     
     
void solve3(void)
{int a,b,c,d,e;
a=b=c=d=e=0;
list();

for(a=1;a<=9;a++)
{block2(a);



for(b=row_start;b<=row_end;b++)
{d=0;
 if( BRV[a][b][0]==0)
 continue;                             
                               
for(c=column_start;c<=column_end;c++)
{if(table[b][c]==0)
d+=1; }

             
if(BRV[a][b][0]==d)
{
for(e=1;e<=d;e++)
sp_adition_list2(b,a,BRV[a][b][e]); 
list();
block2(a);
}  
}



block2(a);
for(b=column_start;b<=column_end;b++)
{d=0;
 if( BCV[a][b][0]==0)
 continue;             


for(c=row_start;c<=row_end;c++)
{if(table[c][b]==0)
d+=1; }


if(BCV[a][b][0]==d)
{
for(e=1;e<=d;e++)
sp_adition_list3(b,a,BCV[a][b][e]); 
list();
block2(a);
}  
}

      }
         }
    


  
 
 
 
 void solve(void)
 {int s2=0,s1=0,w;
 
 for(w=1;w<(100);w++)
    {
     solve1();   solve2();  solve1();  solve3();  
     
     s1=s2;
    s2=solved_pos;
    
    if(s2==s1)
    break;
    }
    
    
  }
  
  
  
  
  
  
int special_solve(void)           
{ int last_check(void);
int m,n,k=10,m1,n1,w,a=0,b;
    
    
     for(m=1;m<=9;m++)
    for(n=1;n<=9;n++)
    table2[m][n]=table[m][n];
                              
    
    
    for(m=1;m<=9;m++)
    for(n=1;n<=9;n++)
    {
    if(table[m][n]==0)
    if(k>posible_num[((9*(m-1))+n)][0])
    {k=posible_num[((9*(m-1))+n)][0];
    m1=m; n1=n;}}
    
    
    
    for(w=1;w<=k;w++)
    {table[m1][n1]=posible_num[((9*(m1-1))+n1)][w];
    solve();
    b=last_check();
    
    if(b==0)
    {output();  a=a+1;}
    
    for(m=1;m<=9;m++)
    for(n=1;n<=9;n++)
    table[m][n]=table2[m][n];
}
     
   
   return a;  }








int last_check(void)
{int w,n,x,p,y,a=0;
    
    list();
    
   
   
    for(x=1;x<=9;x++)
    {for(y=1;y<=9;y++)
    {a=check(x,y,table[x][y]);
    if(a==1)
    return 1;
    
    if(table[x][y]==0)
    {if(posible_num[((9*(x-1))+y)][0]==0)
    return 1;
    
    }
    
    }
    } 




for(a=1;a<=9;a++)
{
block2(a);
for(n=1;n<=9;n++)
{
p=0;


for(x=row_start;x<=row_end;x++)
    {for(y=column_start;y<=column_end;y++)
     { 
      if(table[x][y]==n)
      {p=1;
      break;}
      
      if(table[x][y]==0)
      {for(w=1;w<=9;w++)
      {if(posible_num[((9*(x-1))+y)][w]==n)
          {p=1; break;}
          }}
          
          if(p==1)
          break;
          
                       }
                       
        if(p==1)
      break;           
            }
            
   if(p==0)
   return 1; 
                          
            }
            }





return 0;
}







void original_input(void)
{int x,y;

     for(x=1;x<=9;x++)
    {for(y=1;y<=9;y++)
    {if(table[x][y]!=0)
    in=in+1;
    }
    }
}    







void list_output(void)
{int m,n,k;
for(m=1;m<=81;m++)
{printf("\n%d\n",m);
for(n=0;n<=9;n++)
{printf("%d ",posible_num[m][n]);}
} 

printf("\n\n\n\n");        



for(m=1;m<=9;m++)
{printf("\n\nblock %d",m);
block2(m);
for(n=row_start;n<= row_end;n++)
{printf("\n               Row %d\n\n",n);
for(k=0;k<=9;k++)
{if(BRV[m][n][k]==0)
break;
printf("  %d",BRV[m][n][k]);  } 
    }} 
    
    }








int main()
{
    int w,sum,a=w=0;


    printf("This code was developed by Tanveer Hossain Polok (ME 2k10 KUET) \nEnter the values for your sudoku problem");


    Input();
    original_input();
    output();
    printf("\nPress Enter to solve");
    getch();
    

    solve();
    solve();
    
    
   /* if( (in+solved_pos)<81 && ((81-(in+solved_pos))<=15) )
    a=special_solve();*/
    
    
    
    if(a==0)
    {
    list();
    w=last_check();
    
    
    /*list_output(); */       
    output();
    
    
    if(w==0)
    {
    printf("\n\n\a The problem is solved  \nThis code was developed by Tanveer Hossain Polok contact 01673856012");
    printf("\n\n\aTotal input=%d  Solved=%d  remain=%d",in,solved_pos,(81-(in+solved_pos)));
    }
    
    else
    printf("\n\n\nUnable to solve\a");
}
else
printf("\n\n\nTotal number of possible solve %d\a",a);
    
    getch();
    getch();
    
    return 0;
}
