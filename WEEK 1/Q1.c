/*write a program to find sum of first n natural numbers using user defined function.*/
#include<stdio.h>
void sum(int n){
  int s=0;
  for(int i=1;i<=n;i++){
    s+=i;
  }
  printf("The value of %d natural numbers is: %d\n",n,val);
}
int main(){
  int n;
  printf("Enter the number to calculate sum of natural numbers:\n");
  scanf("%d",&n);
  sum(n);
  return 0;
}
