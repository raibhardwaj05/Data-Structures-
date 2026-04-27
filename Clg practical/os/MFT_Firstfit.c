#include <stdio.h>
int main(){
    int blocks=5, processes=3;
    int blockSize[5]={100,500,200,300,600};
    int processSize[3]={120,50,230};
    int used[5]={0};

    for(int i=0;i<processes;i++){
        for(int j=0;j<blocks;j++){
            if(!used[j] && blockSize[j]>=processSize[i]){
                printf("P%d->B%d\n",i+1,j+1);
                used[j]=1;   // fixed → no reuse
                break;
            }
        }
    }
}