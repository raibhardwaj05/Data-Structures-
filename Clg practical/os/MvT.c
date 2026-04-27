// first fit

#include <stdio.h>
int main(){
    int blockSize[5]={100,500,200,300,600};
    int processSize[3]={120,50,230};

    for(int i=0;i<3;i++){
        for(int j=0;j<5;j++){
            if(blockSize[j]>=processSize[i]){
                printf("P%d->B%d\n",i+1,j+1);
                blockSize[j]-=processSize[i]; // reuse
                break;
            }
        }
    }
}

// best fit

#include <stdio.h>
int main(){
    int blockSize[5]={100,500,200,300,600};
    int processSize[3]={120,50,230};

    for(int i=0;i<3;i++){
        int best=-1;
        for(int j=0;j<5;j++){
            if(blockSize[j]>=processSize[i] &&
              (best==-1 || blockSize[j]<blockSize[best]))
                best=j;
        }
        if(best!=-1){
            printf("P%d->B%d\n",i+1,best+1);
            blockSize[best]-=processSize[i];
        }
    }
}


// worst fit

#include <stdio.h>
int main(){
    int blockSize[5]={100,500,200,300,600};
    int processSize[3]={120,50,230};

    for(int i=0;i<3;i++){
        int worst=-1;
        for(int j=0;j<5;j++){
            if(blockSize[j]>=processSize[i] &&
              (worst==-1 || blockSize[j]>blockSize[worst]))
                worst=j;
        }
        if(worst!=-1){
            printf("P%d->B%d\n",i+1,worst+1);
            blockSize[worst]-=processSize[i];
        }
    }
}