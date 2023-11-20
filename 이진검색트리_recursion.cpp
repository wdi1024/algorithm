#include <iostream>

using namespace std;

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

void insert(struct node** root, int data);
void preOrder(struct node* root);
void inOrder(struct node* root);
void postOrder(struct node* root);
int size(struct node* root);
int height(struct node* root);
int sumOfWeight(struct node* root);
int maxPathWeight(struct node* root);
void mirror(struct node** root);
void destruct(struct node** root);

int main()
{
    int numTestCases;
    scanf("%d", &numTestCases);
    while (numTestCases--)
    {
        int num, i;
        struct node* root = NULL;
        scanf("%d", &num);
        for (i = 0; i < num; i++)
        {
            int data;
            scanf("%d", &data);
            insert(&root, data);
        }
        printf("%d\n", size(root)); 
        printf("%d\n", height(root)); 
        printf("%d\n", sumOfWeight(root)); 
        printf("%d\n", maxPathWeight(root)); 
        mirror(&root);
        preOrder(root); printf("\n");
        inOrder(root); printf("\n");
        postOrder(root); printf("\n");
        destruct(&root); // BST의 모든 노드의 동적 메모리 해제 
        if (root == NULL)
            printf("0\n");
        else
            printf("1\n");
    }
    return 0; 
}

// 데이터 삽입(recursion)
void insert(struct node** root, int data) {
    if (*root == NULL)
    {
        struct node* newNode = new struct node;
        newNode->data = data;
        newNode->left = newNode->right = NULL;
        *root = newNode;
    }
    else 
    {
        if ((*root)->data > data)
            insert(&((*root)->left), data);
        else
            insert(&((*root)->right), data);
    }
}

void inOrder(node *root)
{
    if (root == NULL)
        return;
    else
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

void preOrder(node *root)
{
    if (root == NULL)
        return ;
    else
    {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(node *root)
{
    if (root == NULL)
        return ;
    else
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

int size(struct node *root)
{
    if (root == NULL)
        return 0;
    
    int leftSize = size(root->left);
    int rightSize = size(root->right);

    return leftSize + rightSize + 1;
}

int height(struct node *root)
{
    if (root == NULL)
        return -1;
    
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return max(leftHeight,rightHeight)  +1;
}

void mirror(struct node** root)
{
    if (*root == NULL)
        return;

    struct node* tmp = (*root)->left;
    (*root)->left = (*root)->right;
    (*root)->right = tmp;

    mirror(&((*root)->left));   
    mirror(&((*root)->right));
}

int sumOfWeight(struct node* root)
{
    if (root == NULL)
        return 0;
    
    return sumOfWeight(root->left)+ sumOfWeight(root->right) + root->data;
}

int maxPathWeight(struct node* root)
{
    if (root == NULL)
        return 0;
    else
    {
        int leftWeight = maxPathWeight(root->left);
        int rightWeight = maxPathWeight(root->right);
        return (leftWeight > rightWeight ? leftWeight : rightWeight) + root->data;
    }
}

void destruct(struct node** root)
{
    if (*root == NULL)
        return;

    destruct(&((*root)->left));
    destruct(&((*root)->right));

    delete *root;
    *root = NULL;
}
