#ifndef OPTION_H
#define OPTION_H

class option
{
  public:
    option(){}
    double time,sigma,r,q,psmall, pbig, strike;
    int Ns,Nt;
    char type;
    double **price;
    double *a,*b,*c,*u,*v,*f,*x,*y;
    double ds,dt;
    void setspace();
    void setvalue();
    void showdata_matrix();
    void caldata();
    void showdata_today();
    void solveonce(int);
    virtual void solveprice(){};
    virtual void fillp(){};
  private:
    void thomas(int);
    
};

#endif 
