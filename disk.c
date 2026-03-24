#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 10
#define MAX 5000


void sort(int arr[]) {
    for(int i = 0; i < SIZE - 1; i++) {
        for(int j = i + 1; j < SIZE; j++) {
            if(arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}


void SSTF(int req[], int head) {
    int visited[SIZE] = {0};
    int total = 0;

    printf("\nSSTF Order: %d ", head);

    for(int i = 0; i < SIZE; i++) {
        int min = 99999, index = -1;

        for(int j = 0; j < SIZE; j++) {
            if(!visited[j]) {
                int dist = abs(head - req[j]);
                if(dist < min) {
                    min = dist;
                    index = j;
                }
            }
        }

        visited[index] = 1;
        total += abs(head - req[index]);
        head = req[index];

        printf("-> %d ", head);
    }

    printf("\nTotal Head Movement (SSTF): %d\n", total);
}


void LOOK(int req[], int head) {
    int total = 0;
    int arr[SIZE];

    for(int i = 0; i < SIZE; i++)
        arr[i] = req[i];

    sort(arr);

    printf("\nLOOK Order: %d ", head);

    int pos;
    for(pos = 0; pos < SIZE; pos++) {
        if(arr[pos] > head)
            break;
    }

    
    for(int i = pos; i < SIZE; i++) {
        total += abs(head - arr[i]);
        head = arr[i];
        printf("-> %d ", head);
    }

    
    for(int i = pos - 1; i >= 0; i--) {
        total += abs(head - arr[i]);
        head = arr[i];
        printf("-> %d ", head);
    }

    printf("\nTotal Head Movement (LOOK): %d\n", total);
}


void CSCAN(int req[], int head) {
    int total = 0;
    int arr[SIZE];

    for(int i = 0; i < SIZE; i++)
        arr[i] = req[i];

    sort(arr);

    printf("\nCSCAN Order: %d ", head);

    int pos;
    for(pos = 0; pos < SIZE; pos++) {
        if(arr[pos] > head)
            break;
    }

    
    for(int i = pos; i < SIZE; i++) {
        total += abs(head - arr[i]);
        head = arr[i];
        printf("-> %d ", head);
    }

    
    total += abs(head - (MAX - 1));
    head = 0;  

    
    for(int i = 0; i < pos; i++) {
        total += abs(head - arr[i]);
        head = arr[i];
        printf("-> %d ", head);
    }

    printf("\nTotal Head Movement (CSCAN): %d\n", total);
}

int main() {
    int req[SIZE] = {98, 183, 41, 122, 14, 124, 65, 67, 200, 350}; // sample requests
    int head = 150;

    printf("Initial Head Position: %d\n", head);

    printf("Requests: ");
    for(int i = 0; i < SIZE; i++)
        printf("%d ", req[i]);

    printf("\n");

    SSTF(req, head);
    LOOK(req, head);
    CSCAN(req, head);

    return 0;
}
