#include<iostream>
#include<algorithm>
#include"optput.h"

using namespace std;

void optput::fillp()
{  int i;
   for(i=0;i<=Ns;i++)
    {  
      price[Nt][i]=max(strike-psmall-i*ds,0.0);
    }

   for(i=0;i<=Nt;i++)
      { price[i][0]=strike-psmall; price[i][Ns]=0;}
}



void optput::solveprice()
{  int i,j,k;
   for(i=Nt;i>0;i--)
    {
       solveonce(i);
    
     if(type=='A')
      {
       for(j=1;j<Ns;j++)
         {
           price[i-1][j]=max(x[j],-psmall-j*ds+strike);
         }
      }
     else {
             for(j=1;j<Ns;j++)
              {
                price[i-1][j]=x[j];
              }
          }

    }
}


   
   
       
