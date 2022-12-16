#include <stdio.h>
 int main(void) {
  int num1,num2,num3,maior;
  scanf("%d""%d""%d",&num1,&num2,&num3);
  if(num1>=num2) {
    if(num1>=num3) {
      maior=num1;
      printf("Maior:%d",maior);
    } else {
      maior=num3;
      printf("Maior:%d",maior);
    }
  } else if(num2>=num3) {
      maior=num2;
      printf("Maior:%d",maior);
    } else {
        maior=num3;
        printf("Maior:%d",maior);
    }
}