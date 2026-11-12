
#include <stdio.h>

#define SIZE 50

int hashTable[SIZE];
int collisions = 0;

void insert(int id) {
    int index = id % 10;

    while (hashTable[index] != -1) {
        collisions++;
        index = (index + 1) % SIZE;
    }

    hashTable[index] = id;
}

int search(int id, int *count) {
    int index = id % 10;
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

int main() {
    int students[] = {
        105,102,108,101,103,107,110,104,106,109,
        115,112,118,111,113,117,120,114,116,119,
        125,122,128,121,123,127,130,124,126,129,
        135,132,138,131,133,137,140,134,136,139
    };

    int id, count = 0;

    for (int i = 0; i < SIZE; i++)
        hashTable[i] = -1;

    for (int i = 0; i < 40; i++)
        insert(students[i]);

    printf("Hashing with Linear Probing\n");
    printf("Total Collisions: %d\n", collisions);

    printf("Enter Student ID to search: ");
    scanf("%d", &id);

    if (search(id, &count))
        printf("Student Found\n");
    else
        printf("Student Not Found\n");

    printf("Number of Comparisons: %d\n", count);

    return 0;
}
