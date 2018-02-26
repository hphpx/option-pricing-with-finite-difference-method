#include<iostream>
#include<algorithm>
#include<iomanip>
#include"option.h"

using namespace std;

void option::setspace()
{  
   a=new double[Ns+1];
   b=new double[Ns+1];
   c=new double[Ns+1];
   u=new double[Ns+1];
   v=new double[Ns+1];
   x=new double[Ns+1];
   y=new double[Ns+1];
   f=new double[Ns+1];
   int i;
   price=new  double* [Nt+1];
   for(i=0;i<=Nt;i++)
    price[i]= new double[Ns+1];
}

void option::caldata()
{
   ds=(pbig-psmall)/Ns;
   dt=time/Nt;
   double temp1=sigma*sigma*dt;
   double temp2=(r-q)*dt;
   int i;
   cout.width(6);
   for(i=1;i<Ns;i++)
    { 
       a[i]=(temp2*i-i*i*temp1)*0.5;
       b[i]=1+i*i*temp1+r*dt;
       c[i]=(-temp2*i-i*i*temp1)*0.5;
    
    }
     
}

void option::thomas(int n)
{
   u[1]=b[1]; v[1]=c[1]/u[1]; y[1]=f[1]/u[1];
   int i;
   for(i=2;i<Ns;i++)
    {
      u[i]=b[i]-a[i]*v[i-1];   
      v[i]=c[i]/u[i];          
      y[i]=(f[i]-a[i]*y[i-1])/u[i]; 
    }

    x[Ns-1]=y[Ns-1];
    for(i=Ns-2;i>=1;i--)
     {x[i]=y[i]-v[i]*x[i+1];  }
}

void option::solveonce(int n)
{ 
   int i;
   for(i=2;i<Ns-1;i++)
    f[i]=price[n][i];
  f[1]=price[n][1]-a[1]*price[n-1][0];
  f[Ns-1]=price[n][Ns-1]-c[Ns-1]*price[n-1][Ns];

   thomas(n);
}

void option::showdata_matrix()
{  int i,j;
   double temp,bi;
 
   cout.setf(ios::fixed);
   for(i=Ns;i>=0;i--)
    {  cout<<setw(8)<<setprecision(2)<<psmall+i*ds<<" ";
       for(j=0;j<=Nt;j++)
          cout<<setw(5)<<setprecision(2)<<price[j][i]<<"  ";
       cout<<endl;
    }
}

void option::showdata_today()
{  int i;
   for(i=0;i<=Ns;i++)
     {
       cout<<setw(8)<<psmall+i*ds<<" ";
       
          cout<<setw(7)<<setprecision(4)<<price[0][i]<<endl;
     }
}
       

