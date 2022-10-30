//     INSERTION SORTING
#include <stdio.h>
void main(){
    int n,i,j,temp;
    int a[20];
    printf("Enter the size of the array \n");
    scanf("%d",&n);
    printf("Enter the elements in the array \n");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    
    for(i=0;i<n;i++){
        temp=a[i];
        j=i-1;
        
        while(j>=0 && temp<=a[j]){
            a[j+1]=a[j];
            j=j-1;
        }
        a[j+1]=temp;
        printf("array after %d pass :\n",i+1);
        for(int i=0;i<n;i++){
        printf("%d ",a[i]);
        }
        printf("\n");
    }
    
    printf("array in sorted using INSERTION sort:\n");
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
}
