#include <stdio.h>
#include <stdlib.h>

struct Node {
    int id;
    struct Node *left, *right;
};

struct Node* insert(struct Node* root, int id) {
    if (root == NULL) {
        struct Node* temp = malloc(sizeof(struct Node));
        temp->id = id;
        temp->left = temp->right = NULL;
        return temp;
    }

    if (id < root->id)
        root->left = insert(root->left, id);
    else if (id > root->id)
        root->right = insert(root->right, id);

    return root;
}

int search(struct Node* root, int id, int *count) {
    if (root == NULL)
        return 0;

    (*count)++;

    if (root->id == id)
        return 1;

    if (id < root->id)
        return search(root->left, id, count);

    return search(root->right, id, count);
}

void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->id);
        inorder(root->right);
    }
}

int height(struct Node* root) {
    if (root == NULL)
        return 0;

    int l = height(root->left);
    int r = height(root->right);

    return 1 + (l > r ? l : r);
}

int main() {
    struct Node* root = NULL;
    int id, count;

int students[] = {
    105,102,108,101,103,107,110,104,106,109,
    115,112,118,111,113,117,120,114,116,119,
    125,122,128,121,123,127,130,124,126,129,
    135,132,138,131,133,137,140,134,136,139
};
    for (int i = 0; i < 40; i++)
        root = insert(root, students[i]);

    printf("BST Student Records\n");

    printf("Inorder Traversal: ");
    inorder(root);

    printf("\nTree Height: %d", height(root));

    printf("\nEnter Student ID to search: ");
    scanf("%d", &id);

    count = 0;

    if (search(root, id, &count))
        printf("Student Found");
    else
        printf("Student Not Found");

    printf("\nNumber of Comparisons: %d\n", count);

    return 0;
}
