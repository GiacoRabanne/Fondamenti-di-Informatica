#include <stdio.h>
int test(int a[], int dim){
int r=1;
if(dim%2==0){
for(int i=0;i<dim;i+=2)
if(a[i+1]+a[i]%2==0)
r=0;
}
return r;
}

int main() {
    int a[]={1,3,5,6,8,7};
int d=test(a,6);
printf("%d", d);
}