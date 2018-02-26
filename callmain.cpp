#include"optcall.h"
#include<iostream>
using namespace std;

//this is program pricing American/European option without dividend, implicit finite difference method is applied.

int main()
{
   optcall opt;
  
   opt.time=0.4167; opt.psmall=0; opt.pbig=100;   //time to expiry date, stock price boundary
   opt.strike=50;   opt.r=0.04;     opt.sigma=0.4; //strike price, risk-less interest rate, volatility
   opt.Ns=20;       opt.Nt=10;                     //number of grid for stock price and time
   opt.q=0;         opt.type='A';                  //asset yeild, 'A'/'E' represents American/European option
    
   opt.setspace();  
   opt.caldata();   
   opt.fillp();    
   opt.solveprice(); 
   
   opt.showdata_matrix();                          //show all the price in a matrix form 
   cout<<"-----------------\n";
   opt.showdata_today();                           //show today's option price with different stock price

   return 0;
}
