#include <stdio.h>
 int main(void) {
  float temp;
  scanf("%f",&temp);
  temp = (1.8*temp+32);
  printf("%.0f",temp);
}