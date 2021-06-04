#include<stdio.h>
#include<stdlib.h>
#include<math.h>
float wallis_pi(int);
int main(void) {
  float pi;
  for (int i=0; i<5; i++) {
    pi = wallis_pi(i);
    if (!(fabs(pi - M_PI) > 0.15)) {
      printf("Estimate with just %d iterations is %f which is too accurate.\n", i, pi);
      abort();
    }
  }

  for (int i=500; i<3000; i++) {
    pi = wallis_pi(i);
    if (!(fabs(pi - M_PI) < 0.01)) {
      printf("Estimate with even %d iterations is %f which is not accurate enough.\n", i, pi);
      abort();
    }
  }
}
float wallis_pi(int n)
{
  int a;
  float b;
  float pi=1.0;
  for(a=1;a<=n;a++){
    b=(float)(4*a*a)/(4*a*a-1);
    pi=pi*b;
  }
return(2*pi);
}
