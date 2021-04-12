#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int ch;
    struct node *left;
    struct node *right;
} node;

struct node *add_node(struct node *root, struct node *node) {
    if (root == NULL) return (node);
    if (node->ch < root->ch) {
        root->left = add_node(root->left, node);
    } else {
        root->right = add_node(root->right, node);
    }
    return (root);
}

struct node *novo_node(int ch) {
    struct node *node = (struct node *) malloc(sizeof(struct node));

    node->ch = ch;
    node->left = NULL;
    node->right = NULL;

    return (node);
}

struct node *tree() {
    return (NULL);
}

void print_in(struct node *node) {
    if (node == NULL) return;

    print_in(node->left);
    printf("%d ", node->ch);
    print_in(node->right);

}

void print_pre(struct node *node) {
    if (node == NULL) return;

    printf("%d ", node->ch);
    print_pre(node->left);
    print_pre(node->right);

}

void print_post(struct node *node) {
    if (node == NULL) return;

    print_post(node->left);
    print_post(node->right);
    printf("%d ", node->ch);

}

int main() {

    struct node *root = tree();

    int n;
    while (scanf("%d", &n) != EOF) {
        struct node *node = novo_node(n);
        root = add_node(root, node);
    }

    print_pre(root);
    printf(".\n");
    print_in(root);
    printf(".\n");
    print_post(root);
    printf(".\n");

    return 0;
}