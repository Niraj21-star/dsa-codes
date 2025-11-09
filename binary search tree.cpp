#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node* createNode(int value) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = value;
    temp->left = temp->right = NULL;
    return temp;
}

struct node* insert(struct node* root, int value) {
    if (root == NULL)
        return createNode(value);
    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    return root;
}

void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void search(struct node* root, int key) {
    if (root == NULL)
        printf("? Not found\n");
    else if (root->data == key)
        printf("? Found\n");
    else if (key < root->data)
        search(root->left, key);
    else
        search(root->right, key);
}

int findMin(struct node* root) {
    while (root->left != NULL)
        root = root->left;
    return root->data;
}

int height(struct node* root) {
    if (root == NULL) return 0;
    int l = height(root->left);
    int r = height(root->right);
    return (l > r ? l : r) + 1;
}

void mirror(struct node* root) {
    if (root == NULL) return;
    struct node* temp = root->left;
    root->left = root->right;
    root->right = temp;
    mirror(root->left);
    mirror(root->right);
}

int main() {
    struct node* root = NULL;
    int ch, val;

    do {
        printf("\n=== BST MENU ===\n");
        printf("1. Insert\n2. Display (Inorder)\n3. Search\n4. Find Min\n5. Height\n6. Mirror\n7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                root = insert(root, val);
                break;
            case 2:
                printf("Inorder: ");
                inorder(root);
                printf("\n");
                break;
            case 3:
                printf("Enter value to search: ");
                scanf("%d", &val);
                search(root, val);
                break;
            case 4:
                if (root)
                    printf("Minimum: %d\n", findMin(root));
                else
                    printf("Tree empty!\n");
                break;
            case 5:
                printf("Height: %d\n", height(root));
                break;
            case 6:
                mirror(root);
                printf("Tree mirrored!\n");
                break;
            case 7:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (ch != 7);

    return 0;
}

