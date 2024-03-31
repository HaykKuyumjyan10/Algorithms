#include <stdio.h>
#include <stdlib.h>

struct node {
    int item;
    struct node* left;
    struct node* right;
};

void inorderTraversal(struct node* root) {
    if (root == NULL) return;
    inorderTraversal(root->left);
    printf("%d ", root->item);
    inorderTraversal(root->right);
}

void preorderTraversal(struct node* root) {
    if (root == NULL) return;
    printf("%d ", root->item);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(struct node* root) {
    if (root == NULL) return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->item);
}

struct node* createNode(int value) {
    struct node* newNode = malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->item = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

struct node* insertLeft(struct node* root, int value) {
    if (root == NULL) {
        printf("Cannot insert left child into a NULL node.\n");
        return NULL;
    }
    root->left = createNode(value);
    return root->left;
}

struct node* insertRight(struct node* root, int value) {
    if (root == NULL) {
        printf("Cannot insert right child into a NULL node.\n");
        return NULL;
    }
    root->right = createNode(value);
    return root->right;
}

int main() {
    struct node* root = createNode(6);
    insertLeft(root, 9);
    insertRight(root, 3);

    insertLeft(root->left, 8);
    insertRight(root->left, 1);

    printf("Inorder traversal: ");
    inorderTraversal(root);
    printf("\n");

    printf("Preorder traversal: ");
    preorderTraversal(root);
    printf("\n");

    printf("Postorder traversal: ");
    postorderTraversal(root);
    printf("\n");

    return 0;
}
