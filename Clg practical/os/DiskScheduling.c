// FCFS

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, head, seek = 0;
    scanf("%d", &n);

    int req[n];
    for(int i=0;i<n;i++) scanf("%d", &req[i]);

    scanf("%d", &head);

    for(int i=0;i<n;i++) {
        seek += abs(head - req[i]);
        head = req[i];
    }

    printf("%d", seek);
}


//SCAN

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, head, size, seek = 0;
    scanf("%d%d", &size, &n);

    int req[n];
    for(int i=0;i<n;i++) scanf("%d", &req[i]);

    scanf("%d", &head);

    // right side
    for(int i=0;i<n;i++)
        if(req[i] >= head) {
            seek += abs(head - req[i]);
            head = req[i];
        }

    // go end
    seek += abs(head - (size-1));
    head = size-1;

    // left side
    for(int i=n-1;i>=0;i--)
        if(req[i] < head) {
            seek += abs(head - req[i]);
            head = req[i];
        }

    printf("%d", seek);
}



// C-SCAN

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, head, size, seek = 0;
    scanf("%d%d", &size, &n);

    int req[n];
    for(int i=0;i<n;i++) scanf("%d", &req[i]);

    scanf("%d", &head);

    // right side
    for(int i=0;i<n;i++)
        if(req[i] >= head) {
            seek += abs(head - req[i]);
            head = req[i];
        }

    // go end
    seek += abs(head - (size-1));

    // jump to start
    seek += (size-1);
    head = 0;

    // again right
    for(int i=0;i<n;i++)
        if(req[i] >= head) {
            seek += abs(head - req[i]);
            head = req[i];
        }

    printf("%d", seek);
}