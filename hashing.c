
#include <stdio.h>

#define SIZE 20

int hashTable[SIZE];

int collisions = 0;

void insert(int id) {
    int index = id % SIZE;

    while (hashTable[index] != -1) {
        collisions++;
        index = (index + 1) % SIZE;
    }

    hashTable[index] = id;
}

int search(int id, int *count) {
    int index = id % SIZE;
    int start = index;

    while (hashTable[index] != -1) {
        (*count)++;

        if (hashTable[index] == id)
            return 1;

        index = (index + 1) % SIZE;

        if (index == start)
            break;
    }

    return 0;
}

void display() {
    printf("\nHash Table:\n");

    for (int i = 0; i < SIZE; i++) {
        if (hashTable[i] != -1)
            printf("%d : %d\n", i, hashTable[i]);
    }
}

int main() {
    int students[] = {
        105, 102, 108, 101, 103,
        107, 110, 104, 106, 109
    };

    int id, count = 0;

    for (int i = 0; i < SIZE; i++)
        hashTable[i] = -1;

    for (int i = 0; i < 10; i++)
        insert(students[i]);

    printf("Hashing with Linear Probing\n");

    display();

    printf("\nTotal Collisions: %d", collisions);

    printf("\nEnter Student ID to search: ");
    scanf("%d", &id);

    if (search(id, &count))
        printf("Student Found");
    else
        printf("Student Not Found");

    printf("\nNumber of Comparisons: %d\n", count);

    return 0;
}
