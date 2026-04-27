
// FCFS
#include <stdio.h>
int main(){
    int n,i,at[10],bt[10],ct[10],tat[10],wt[10];

    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d%d",&at[i],&bt[i]);

    ct[0]=at[0]+bt[0];

    for(i=1;i<n;i++)
        ct[i]=(ct[i-1]>at[i]?ct[i-1]:at[i])+bt[i];

    for(i=0;i<n;i++){
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
        printf("P%d WT=%d TAT=%d\n",i+1,wt[i],tat[i]);
    }
}


// SJF

// SJF
#include <stdio.h>
int main(){
    int n,i,t=0,c=0,at[10],bt[10],ct[10],tat[10],wt[10],done[10]={0};

    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d%d",&at[i],&bt[i]);

    while(c<n){
        int min=999,idx=-1;

        for(i=0;i<n;i++)
            if(at[i]<=t && done[i]==0 && bt[i]<min)
                min=bt[i],idx=i;

        if(idx!=-1){
            t+=bt[idx];
            ct[idx]=t;
            done[idx]=1;
            c++;
        } else t++;
    }

    for(i=0;i<n;i++){
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
        printf("P%d WT=%d TAT=%d\n",i+1,wt[i],tat[i]);
    }
}


// SRTF
#include <stdio.h>
int main(){
    int n,i,t=0,c=0,at[10],bt[10],rem[10],ct[10],tat[10],wt[10];

    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d%d",&at[i],&bt[i]),rem[i]=bt[i];

    while(c<n){
        int min=999,idx=-1;

        for(i=0;i<n;i++)
            if(at[i]<=t && rem[i]>0 && rem[i]<min)
                min=rem[i],idx=i;

        if(idx!=-1){
            rem[idx]--; t++;

            if(rem[idx]==0)
                ct[idx]=t,c++;
        } else t++;
    }

    for(i=0;i<n;i++){
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
        printf("P%d WT=%d TAT=%d\n",i+1,wt[i],tat[i]);
    }
}



// RR
#include <stdio.h>
int main(){
    int n,i,t=0,tq,bt[10],rem[10],ct[10],tat[10],wt[10];

    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&bt[i]),rem[i]=bt[i];

    scanf("%d",&tq);

    int done;
    do{
        done=1;

        for(i=0;i<n;i++){
            if(rem[i]>0){
                done=0;

                if(rem[i]>tq){
                    t+=tq;
                    rem[i]-=tq;
                } else {
                    t+=rem[i];
                    ct[i]=t;
                    rem[i]=0;
                }
            }
        }
    }while(done==0);

    for(i=0;i<n;i++){
        tat[i]=ct[i];
        wt[i]=tat[i]-bt[i];
        printf("P%d WT=%d TAT=%d\n",i+1,wt[i],tat[i]);
    }
}