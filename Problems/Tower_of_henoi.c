#include <stdio.h>

void towerOfHanoi(int n, char from, char to, char aux) {
    if (n == 0){
        return; // base case: nothing to move
    }                      
    towerOfHanoi(n - 1, from, aux, to);      // step 1: move n-1 from 'from' to 'aux'
    printf("Move disk %d from %c to %c\n", n, from, to); // step 2: move largest disk
    towerOfHanoi(n - 1, aux, to, from);      // step 3: move n-1 from 'aux' to 'to'
}

int main() {
    int n = 2;

    towerOfHanoi(n, 'A', 'C', 'B');
    return 0;
}
