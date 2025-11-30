#include <stdio.h>
int main() {
int a[3][3], t[3][3], i, j;
printf("Enter elements of 3x3 matrix:\n");
for(i=0;i<3;i++){
for(j=0;j<3;j++){
scanf("%d",&a[i][j]);
}}
for(i=0;i<3;i++){
for(j=0;j<3;j++){
t[j][i]=a[i][j];
}}
printf("Transpose of the matrix:\n");
for(i=0;i<3;i++){
for(j=0;j<3;j++){
printf("%d ",t[i][j]);
}
printf("\n");
}
return 0;
}
