#include"optput.h"
#include<iostream>
using namespace std;
int main()
{
   optput opt;
   
   opt.time=0.4167; opt.psmall=0; opt.pbig=100;
   opt.strike=50;   opt.r=0.1;     opt.sigma=0.4;
   opt.Ns=20;        opt.Nt=10;      
   opt.q=0;          opt.type='A';

   opt.setspace();
   opt.caldata();
   opt.fillp();
   opt.solveprice();
   opt.showdata_matrix();
   cout<<"--------------\n";
   opt.showdata_today();
   return 0;
}
