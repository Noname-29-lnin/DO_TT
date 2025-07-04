#include <iostream>

void selection_sort(int [] array){
    for(int i = 0; i < array.length-1; i++){
        int min = i;
        for(int j = i+1; j < array.length; j++){
            if(array[j] < array[min]) min = j;
            int temp = array[i];
            array[i] = array[min];
            arr[min] = temp;
        }
    }
}

int main(){

    return 0;
}