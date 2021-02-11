#include<stdio.h>
#include<stdlib.h>

int main(){
	int *arr1 = NULL;
	int *arr2 = NULL;
	int *arr3 = NULL;
	int start=0,final=0;
	int i=0,j=0,k=1, index = 0, index1 = 0, index2 = 0, index3 = 0;
	while(1){
		int num1;
		scanf("%d", &num1);
		if(num1 == -1)
			break;
		if(arr1 == NULL)
			arr1 = (int *)malloc(sizeof(int));
		else
			arr1 = (int *)realloc(arr1, (index1 + 1) * sizeof(int));

		arr1[index1] = num1;       
		index1++;
	}
	while(1){
		int num2;
		scanf("%d", &num2);
		if(num2 == -1)
			break;
		if(arr2 == NULL)
			arr2 = (int *)malloc(sizeof(int));
		else
			arr2 = (int *)realloc(arr2, (index2 + 1) * sizeof(int));

		arr2[index2] = num2;       
		index2++;
	}
	while(1){
		int num3;
		scanf("%d", &num3);
		if(num3 == -1)
			break;
		if(arr3 == NULL)
			arr3 = (int *)malloc(sizeof(int));
		else
			arr3 = (int *)realloc(arr3, (index3 + 1) * sizeof(int));

		arr3[index3] = num3;       
		index3++;
	}
	for (i=0;i<index1;i++){
			if (arr1[i]==arr2[0]&&arr1[i+index2-1]==arr2[index2-1]){
				start=i;
				final=i+index2-1;
			}
	}
	index = index1-index2+index3;
	int arr4[index];
	for (i=0;i<start;i++){
		arr4[i] = arr1[i];
	}
	for (i=start;i<start+index3;i++){
		arr4[i] = arr3[j];
		j++;
	}
	for (i=start+index3;i<index;i++){
		arr4[i] = arr1[final+k];
		k++;
	}
	for (i=0;i<index;i++){
		printf("%d ",arr4[i]);
	}
}
