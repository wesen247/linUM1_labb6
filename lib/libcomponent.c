#include <stdio.h>

#include "lib/libcomponent.h"


        // orig_resistance ersätts med tre seriekopplade resistorer

int e_resistance(float orig_resistance, float *res_array)
{
   int i,count=0,e=0;
   float e_one=0,e_two=0,e_three=0;
   float res_two=0,res_three=0;
   float res_one=orig_resistance;


   // e12 serien
   float e12[] = {1,10,12,15,18,22,27,33,39,47,56,68,82};


    for(i=0;e_one<res_one;i++)                  //resistans för resistor ett
          e_one=e12[i];
          i-=4;
          e_one=e12[i];
          if(e_one>=1)
          {
          res_one=e_one;
          res_array[0]=e_one;
          res_two=orig_resistance-res_one;
          }
          else
          {
          res_array[0]=0;
          res_two=orig_resistance;
          }

	  for(i=0;(e_two<res_two)&(res_two>=1);i++)      //resistans för resistor två
	  e_two=e12[i];
          i-=2;
          e_two=e12[i];
          if(e_two>=1)
          {
          res_two=e_two;
            if(!res_array[0])
                res_array[0]=res_two;
            else
             res_array[1]=e_two;
          res_three=orig_resistance-res_one-res_two;
          }
          else
          {
          res_array[1]=0;
          res_three=res_two;
          }



	  for(i=0;(e_three<res_three)&(res_three>=1);i++)     //resistans för resistor tre
        e_three=e12[i];
          if(e_three>=1)
            {
            res_three=e_three;
             if(!res_array[0])
               res_array[0]=res_three;
             else if(!res_array[1])
               res_array[1]=res_three;
             else
               res_array[2]= res_three;
           }
          else
            res_array[2]=0;

   for(i=0;i<3;i++)        //antal resistorer som behövdes för att ersätta orig_resistance
      {
      e=res_array[i];
          if(e>=1)
            count++;
      }


 return count;
}

