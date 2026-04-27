#include <stdio.h>

// COMMON FUNCTION
int found(int frames[], int f, int x) {
    for(int i=0;i<f;i++)
        if(frames[i]==x) return 1;
    return 0;
}

// ---------------- FIFO ----------------
void fifo(int pages[], int n, int f) {
    int frames[f], faults=0, pos=0;

    for(int i=0;i<f;i++) frames[i]=-1;

    for(int i=0;i<n;i++) {
        if(!found(frames,f,pages[i])) {
            frames[pos]=pages[i];
            pos = (pos+1)%f;
            faults++;
        }
    }
    printf("FIFO Faults = %d\n",faults);
}

// ---------------- LIFO ----------------
void lifo(int pages[], int n, int f) {
    int frames[f], faults=0, top=-1;

    for(int i=0;i<f;i++) frames[i]=-1;

    for(int i=0;i<n;i++) {
        if(!found(frames,f,pages[i])) {
            if(top < f-1) top++;
            frames[top]=pages[i];
            faults++;
        }
    }
    printf("LIFO Faults = %d\n",faults);
}

// ---------------- LRU ----------------
void lru(int pages[], int n, int f) {
    int frames[f], time[f], faults=0, t=0;

    for(int i=0;i<f;i++) {
        frames[i]=-1;
        time[i]=0;
    }

    for(int i=0;i<n;i++) {
        int flag=0;

        for(int j=0;j<f;j++) {
            if(frames[j]==pages[i]) {
                t++;
                time[j]=t;
                flag=1;
            }
        }

        if(!flag) {
            int min=0;
            for(int j=1;j<f;j++)
                if(time[j]<time[min]) min=j;

            frames[min]=pages[i];
            t++;
            time[min]=t;
            faults++;
        }
    }
    printf("LRU Faults = %d\n",faults);
}

// ---------------- MAIN ----------------
int main() {
    int n,f;

    printf("Enter number of pages: ");
    scanf("%d",&n);

    int pages[n];

    printf("Enter pages:\n");
    for(int i=0;i<n;i++)
        scanf("%d",&pages[i]);

    printf("Enter number of frames: ");
    scanf("%d",&f);

    fifo(pages,n,f);
    lifo(pages,n,f);
    lru(pages,n,f);

    return 0;
}