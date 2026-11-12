
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int id, height;
    struct Node *left, *right;
};

int max(int a, int b) {
    return (a > b) ? a : b;
}

int height(struct Node *n) {
    return (n == NULL) ? 0 : n->height;
}

struct Node* createNode(int id) {
    struct Node* n = malloc(sizeof(struct Node));
    n->id = id;
    n->left = n->right = NULL;
    n->height = 1;
    return n;
}

int balance(struct Node *n) {
    return (n == NULL) ? 0 :
    height(n->left) - height(n->right);
}

struct Node* rightRotate(struct Node *y) {
    struct Node *x = y->left;
    struct Node *t = x->right;

    x->right = y;
    y->left = t;

    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));

    return x;
}

struct Node* leftRotate(struct Node *x) {
    struct Node *y = x->right;
    struct Node *t = y->left;

    y->left = x;
    x->right = t;

    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));

    return y;
}

struct Node* insert(struct Node* root, int id) {
    if (root == NULL)
        return createNode(id);

    if (id < root->id)
        root->left = insert(root->left, id);
    else if (id > root->id)
        root->right = insert(root->right, id);
    else
        return root;

    root->height = 1 + max(height(root->left), height(root->right));

    int b = balance(root);

    if (b > 1 && id < root->left->id)
        return rightRotate(root);

    if (b < -1 && id > root->right->id)
        return leftRotate(root);

    if (b > 1 && id > root->left->id) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (b < -1 && id < root->right->id) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

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

int main() {
    struct Node* root = NULL;
    int students[] = {
    105,102,108,101,103,107,110,104,106,109,
    115,112,118,111,113,117,120,114,116,119,
    125,122,128,121,123,127,130,124,126,129,
    135,132,138,131,133,137,140,134,136,139
};

    int id, count, newID;

    printf("\nEnter new Student ID: ");
scanf("%d", &newID);

root = insert(root, newID);

printf("Student Inserted Successfully\n");

printf("Updated Inorder Traversal: ");
inorder(root);

printf("\nUpdated Tree Height: %d\n", height(root));

    printf("AVL Student Records\n");

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
