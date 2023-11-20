#include <iostream>

using namespace std;

struct node{
    char data;
    struct node* leftSubTree;
    struct node* rightSubTree;
};

int size(struct node *root)
{
    if (root == NULL)
        return 0;
    
    return size(root->leftSubTree)+ size(root->rightSubTree) + 1;
}

int height(struct node *root)
{
    if (root == NULL)
        return -1;
    
    return (height(root->leftSubTree)>height(root->rightSubTree)? height(root->leftSubTree)+1 : height(root->rightSubTree)+1);
}
/*
node mirror(struct node *root)
{
    if (root == NULL)
        return;
    else
    {
        struct node 
    }
}
*/

void insert(struct node **root, char data)
{
    struct node* tmp = new struct node;
    tmp->data = data;
    tmp->leftSubTree = tmp->rightSubTree = NULL;
    if (*root == NULL)
    {
        *root = tmp;
        free(tmp);
    }
    else 
    {
        free(tmp);
        if ((*root)->data >= data)
            insert(&((*root)->rightSubTree), data);
        else
            insert(&((*root)->leftSubTree), data);
    }
}

void inOrder(node *root)
{
    if (root == NULL)
        return;
    else
    {
        inOrder(root->leftSubTree);
        printf("%c ", root->data);
        inOrder(root->rightSubTree);
    }
}

void preOrder(node *root)
{
    if (root == NULL)
        return ;
    else
    {
        printf("%c ", root->data);
        preOrder(root->leftSubTree);
        preOrder(root->rightSubTree);
    }
}

void postOrder(node *root)
{
    if (root == NULL)
        return ;
    else
    {
        postOrder(root->leftSubTree);
        postOrder(root->rightSubTree);
        printf("%c ", root->data);
    }
}

void order(node *root) //중간고사에 변형해서 냄
{
    if (root == NULL)
        return ;
    else
    {
        order(root->leftSubTree);
        printf("%c", root->data);
        order(root->rightSubTree);
        printf("%c", root->data);
    }
}

int main()
{
    struct node* root;

    insert(&root, 'D');
    insert(&root, 'F');
    insert(&root, 'C');
    insert(&root, 'G');
    insert(&root, 'A');
    insert(&root, 'E');
    insert(&root, 'B');

}