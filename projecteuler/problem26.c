#include <stdio.h>
main()
{   
  int z,i,a,b,err=0,max=0,value;
  int x[1000];
  for(i=1;i<1000;i++)
  {
    z=1;
    x[0]=10/i;
    for(a=1;a<1000;a++)
    {
      z=z*10-x[a-1]*i;
      x[a]=z*10/i;
    }
    for(a=0;a<995;a++)
    {
      if(x[a]==0 && x[a+1]==0 && x[a+2]==0)
      {
        goto over;
      }
    }
    for(a=0;a<995;a++)
    {
      for(b=a+1;b<995;b++)
      {
               if(x[a]==x[b]&&x[a+1]==x[b+1]&&x[a+2]==x[b+2])
               {
                  if((b-a)>max){max=b-a;value=i;}
                    goto over; 
               }
      } 
    }
    err=1;
    over:; 
  }
      if(err==1)printf("array is not enough\n");
      else printf("value which  have maximum recurring cycle is %i",value);
}
