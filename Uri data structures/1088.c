#include <stdio.h>
#include <stdlib.h>
int inv;
void merge(int *vet,int left,int mid,int right,int n){
	int lef,rig,i,tmp[n];
	lef= left;
	rig = mid+1;
	i = left;
	while((lef<= mid) && (rig <= right)){
		if(vet[lef] < vet[rig]){
			tmp[i] = vet[lef];
			i++;
            lef++;
		}else{
		  inv += mid-lef + 1;
			tmp[i] = vet[rig];
			i++;
            rig++;
		}
	}
	while(lef <= mid){  
		tmp[i] = vet[lef];
		i++;
        lef++;
	}
	while(rig <= right){	
		tmp[i] = vet[rig];
		i++;
        rig++;
	}
	for(i = left;i <= right;i++){  
		vet[i] = tmp[i];
	}
}
void mergeSort(int *a,int left,int right,int n){
	int mid;
	if(left < right){
		mid=(left + right)/2;
		mergeSort(a,left,mid,n);
		mergeSort(a,mid+1,right,n);
		merge(a,left,mid,right,n); 
	}
}
int main(){

	int i, n;
	while(scanf("%d", &n)){

	    int vet[n];
	    for(i = 0; i < n; ++i){
			scanf("%d", &vet[i]);
        }

		inv = 0;
	    mergeSort(vet, 0, n-1,n);
	    if(inv % 2){
            printf("Marcelo\n");
        }else{
            printf("Carlos\n");
        }
	}
    return 0;
}