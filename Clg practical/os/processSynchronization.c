//Producer Consumer 

#include <stdio.h>
#include <stdlib.h>

int mutex = 1, empty = 3, full = 0, x = 0;

int wait(int s) { return --s; }
int signal(int s) { return ++s; }

void producer() {
    if (empty > 0) {
        empty = wait(empty);
        mutex = wait(mutex);

        x++;
        printf("Produced: %d\n", x);

        mutex = signal(mutex);
        full = signal(full);
    } else {
        printf("Buffer Full!\n");
    }
}

void consumer() {
    if (full > 0) {
        full = wait(full);
        mutex = wait(mutex);

        printf("Consumed: %d\n", x);
        x--;

        mutex = signal(mutex);
        empty = signal(empty);
    } else {
        printf("Buffer Empty!\n");
    }
}

int main() {
    int ch;
    while (1) {
        printf("\n1. Producer\n2. Consumer\n3. Exit\n");
        scanf("%d", &ch);

        if (ch == 1) producer();
        else if (ch == 2) consumer();
        else exit(0);
    }
}