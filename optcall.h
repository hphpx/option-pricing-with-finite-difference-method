#include"option.h"

class optcall: public option
{  
   public:
   optcall():option(){}
   virtual void fillp();
   virtual void solveprice();
   
};


