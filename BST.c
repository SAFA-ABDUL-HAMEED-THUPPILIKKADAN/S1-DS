#include <stdio.h>
#include <stdlib.h>

// Structure of a node
struct node {
    int data;
    struct node *left, *right;
};

// Global root
struct node *root = NULL;

// Function to create a new node
struct node* create(int value) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->left = newnode->right = NULL;
    return newnode;
}

// Function to insert a node
void insert(int value) {
    struct node *newnode = create(value);

    if (root == NULL) {
        root = newnode;
        return;
    }

    struct node *current = root, *parent = NULL;

    while (current != NULL) {
        parent = current;
        if (value < current->data)
            current = current->left;
        else if (value > current->data)
            current = current->right;
        else {
            printf("Duplicate value %d not allowed!\n", value);
            free(newnode);
            return;
        }
    }

    if (value < parent->data)
        parent->left = newnode;
    else
        parent->right = newnode;
}

// Function to find the smallest node in a subtree (used in delete)
struct node* findMin(struct node *current) {
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

// Function to delete a node
struct node* deleteNode(struct node *current, int value) {
    if (current == NULL)
        return current;

    if (value < current->data)
        current->left = deleteNode(current->left, value);
    else if (value > current->data)
        current->right = deleteNode(current->right, value);
    else {
        // Node found — handle 3 cases

        // Case 1: No child
        if (current->left == NULL && current->right == NULL) {
            free(current);
            return NULL;
        }

        // Case 2: One child
        else if (current->left == NULL) {
            struct node *temp = current->right;
            free(current);
            return temp;
        }
        else if (current->right == NULL) {
            struct node *temp = current->left;
            free(current);
            return temp;
        }

        // Case 3: Two children
        struct node *temp = findMin(current->right);
        current->data = temp->data;
        current->right = deleteNode(current->right, temp->data);
    }
    return current;
}

// Function to search for a value
struct node* search(struct node *current, int value) {
    if (current == NULL)
        return NULL;
    if (current->data == value)
        return current;
    else if (value < current->data)
        return search(current->left, value);
    else
        return search(current->right, value);
}

// Inorder Traversal (Left, Root, Right)
void inorder(struct node *current) {
    if (current != NULL) {
        inorder(current->left);
        printf("%d ", current->data);
        inorder(current->right);
    }
}

// Preorder Traversal (Root, Left, Right)
void preorder(struct node *current) {
    if (current != NULL) {
        printf("%d ", current->data);
        preorder(current->left);
        preorder(current->right);
    }
}

// Postorder Traversal (Left, Right, Root)
void postorder(struct node *current) {
    if (current != NULL) {
        postorder(current->left);
        postorder(current->right);
        printf("%d ", current->data);
    }
}

int main() {
    int choice, value;

    while (1) {
        printf("\n\nBinary Search Tree Operations\n");
        printf("1. Insert\n2. Delete\n3. Search\n4. Inorder Traversal\n");
        printf("5. Preorder Traversal\n6. Postorder Traversal\n7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(value);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                break;
            case 3:
                printf("Enter value to search: ");
                scanf("%d", &value);
                if (search(root, value))
                    printf("%d found in the tree.\n", value);
                else
                    printf("%d not found in the tree.\n", value);
                break;
            case 4:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 5:
                printf("Preorder Traversal: ");
                preorder(root);
                printf("\n");
                break;
            case 6:
                printf("Postorder Traversal: ");
                postorder(root);
                printf("\n");
                break;
            case 7:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
