#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void print(int A[]);
int check(int A[]);



int main(){


  int seed = time(NULL);
   srand(seed); 

  int A[]={1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1}; //let n be the dimension of the pond, in this case n=30 
  for (;;){
   int a = check(A);
   if (a){
    return 1;
   }
   for (int j=0; j<=29/*n-1*/; j++){
     if (j==1 || j==28/*n-2*/){
      A[j]=0;
      }
      else{
      A[j]=1;
     }
    }
   
  }

  }
   
int check(int A[]){ 
 
  
  int b=1;
  while (b){
  for (int i=0; i<=29/*n-1*/; i++){
     int r = rand()%3;
     if (A[i]!=0){ 
       

      if (r==0 && (i+A[i]<=29/*n-1*/ && A[i+A[i]]!=0)){
        A[i+A[i]]+=A[i];
        A[i]=0;
        }
        print(A); //step
      if (r==1 && (i-A[i]>=0 && A[i-A[i]]!=0)){
         A[i-A[i]]+=A[i];
         A[i]=0;
         print(A); //step
         }
       }
     }
     int alpha=0;
     for (int i=0; i<=29/*n-1*/; i++){
       if (A[i]!=0){
         if((i+A[i]<=29/*n-1*/ && A[i+A[i]]!=0) || (i-A[i]>=0 && A[i-A[i]]!=0)){
           alpha=1;
           }
          }
        }
      if (!alpha){
       b=0;
       print(A); //step
       printf("\nNew pond\n");
    
       } 
     
     
    }

 for (int j=0; j<=29/*n-1*/; j++){
      if (A[j]==28/*n-2*/){
        print(A);
        printf("\nSolution found!\n");
        return 1;
      }
    return 0;
}

        }
     


void print(int a[]){
    printf("\n");
   for (int j=0; j<=29/*n-1*/; j++){
     printf(" %d", a[j]);
     }
   printf("\n");
}
      
     
        
