#include"option.h"

class optput: public option
{  
   public:
   optput():option(){}
   virtual void fillp();
   virtual void solveprice();
   
};


