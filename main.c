#include <stdio.h>
#include <string.h>
#include <math.h>
int ajustArray(int arr[],int l,int r){
    int i = l,j = r;
    int oneSpace = arr[i];
    while(i < j){
        while(i < j && arr[j] > oneSpace)
            j--;
        if(i < j)
            arr[i++] = arr[j];
        while(i < j && arr[i] < oneSpace)
            i++;
        if(i < j)
            arr[j--] = arr[i];
    }
    arr[i] = oneSpace;
    return i;
}
void quickSort(int arr[],int l,int r){
    if(l < r){
        int i = ajustArray(arr, l, r);
        quickSort(arr, l, i - 1);
        quickSort(arr, i + 1, r);
    }
}
void chooseSort(int arr[],int len){
    for(int i = 0; i < len - 1; i++){
        int j = i + 1,arrIndex = i,tmp = arr[i];
        for(;j < len; j++){
            if(arr[arrIndex] > arr[j]){
                arrIndex = j;
            }
        }
        if(i != arrIndex){
            tmp = arr[i];
            arr[i] = arr[arrIndex];
            arr[arrIndex] = tmp;
        }
    }
}
void chooseSort1(int arr[],int len){
    int half = len / 2;
    for(int i = 0; i < half; i++){
        int arrIndex = i,tmp;
        int arrIndex1 = len - 1 - i,tmp1;
        //        Method 1
        //        for(int j = i+1;j < len - i + 1; j++){
        //            if(arr[arrIndex] > arr[j]){
        //                arrIndex = j;
        //            }
        //        }
        //        if(i != arrIndex){
        //            tmp = arr[i];
        //            arr[i] = arr[arrIndex];
        //            arr[arrIndex] = tmp;
        //        }
        //        for(int j = i;j < len - i - 1; j++){
        //            if(arr[arrIndex1] < arr[j]){
        //                arrIndex1 = j;
        //            }
        //        }
        //        if(i != len - 1 - i && len - 1 - i != arrIndex1){
        //            tmp1 = arr[len - 1 - i];
        //            arr[len - 1 - i] = arr[arrIndex1];
        //            arr[arrIndex1] = tmp1;
        //        }
        //        Method 2
        for(int j = i;j < len - i; j++){
            if(arr[arrIndex] > arr[j]){
                arrIndex = j;
            }
            if(arr[arrIndex1] < arr[j]){
                arrIndex1 = j;
            }
        }
        if(i != arrIndex){
            tmp = arr[i];
            arr[i] = arr[arrIndex];
            arr[arrIndex] = tmp;
        }
        if(arrIndex1 == i){
            arrIndex1 = arrIndex;
        }
        if(i != len - 1 - i && len - 1 - i != arrIndex1){
            tmp1 = arr[len - 1 - i];
            arr[len - 1 - i] = arr[arrIndex1];
            arr[arrIndex1] = tmp1;
        }
        
        for(int m = 0; m < len; m++){
            printf("%d-",arr[m]);
        }
        printf("\n");
    }
}
void quickSort2(int arr[] ,int l,int r){
    if(l < r){
        int i = l,j = r,tmpValue = arr[l];
        while(i < j){
            while(i< j && tmpValue <= arr[j]){
                j--;
            }
            if(i < j){
                arr[i++] = arr[j];
            }
            while(i < j && tmpValue > arr[i]){
                i++;
            }
            if(i < j){
                arr[j--] = arr[i];
            }
        }
        arr[i] = tmpValue;
        myPrinter3(arr,l,i - 1);
        myPrinter3(arr,i + 1,r);
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int a[13] = {111,2202,12,34,24,13,456,78,67,44,0,10,100};
    int b[12] = {0,1,4,2,345,234,1,0,567,23,67,80};
    int a_len = sizeof(a)/sizeof(a[0]);
    int b_len = sizeof(b)/sizeof(b[0]);
    quickSort(a, 0, a_len - 1);
    for(int m = 0; m < a_len; m++){
        printf("%d ",a[m]);
    }
    printf("\n");
    chooseSort(b,b_len);
    for(int m = 0; m < b_len; m++){
        printf("%d ",b[m]);
    }
    printf("\n");
    return 1;
}
