#include<bits/stdc++.h>
using namespace std;

class node
{
    public:
    int data;
    node *left;
    node *right;
};

node* newNode(int data)
{
    node *temp = new node();
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

void Print(node *root, int item1, int item2)
{
    if ( root == NULL )
        return;

        Print(root->left, item1, item2);

    if ( root->data >= item1  && root->data <= item2  )
        cout<<root->data<<" ";

    Print(root->right, item1, item2);
}
void display(node *tree)
{
    if (tree != NULL)
    {

        display(tree->left);
        cout << tree->data << " ";
        display(tree->right);
    }
}

void FlipFunction(struct node* node)
{
    if (node == NULL)
        return;
    else
    {
        struct node* temp;

        FlipFunction(node->left);
        FlipFunction(node->right);

        temp = node->left;
        node->left = node->right;
        node->right = temp;
    }
}
bool areIdentical(node * root1, node *root2)
{
    if (root1 == NULL && root2 == NULL)
        return true;

    if (root1 == NULL || root2 == NULL)
        return false;
    return (root1->data == root2->data &&
            areIdentical(root1->left, root2->left) &&
            areIdentical(root1->right, root2->right) );
}

bool isSubtree(node *T, node *S)
{
    if (S == NULL)
        return true;

    if (T == NULL)
        return false;


    if (areIdentical(T, S))
        return true;

    return isSubtree(T->left, S) ||
        isSubtree(T->right, S);
}
int main()
{
    node *root = new node();
    char x ;

    root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    while(true){
        cout << "1- Display .\n2- Print Range .\n3- Flapping tree .\n4- is Subtree .\n5- Exit .\n Enter Your Choose :";
        cin >>x ;
        if(x == '1'){
            cout << "The tree data is :";
            display(root);
            cout << endl;
        }
        else if (x == '2'){
            int k1 , k2;
            cout << "Enter low range :";
            cin >> k1;
            cout << "Enter high range :";
            cin >> k2;
            Print(root, k1, k2);
            cout << endl;
        }
        else if (x == '3'){
            FlipFunction(root);
            cout << "Tree after Flapping :";
            display(root);
            cout << endl;
        }

        else if (x == '4'){
            node *S = root->left;
            if (isSubtree(root, S))
                cout << "Tree 2 is subtree of Tree 1.\n";
            else
                cout << "Tree 2 is not a subtree of Tree 1.\n";
        }
        else
            break;
    }
    return 0;
}
/*
original tree is
    1
    / \
    2 3
    / \
4 5

display function print tree in this shape read from left
so the display function read 4 first then 2 then 5 then 1 then 3
so the output will be so print 4 2 5 1 3 in console .
    4
    / \
    2 5
    / \
1 3

after flapping is changed to ...
this function flap the three start from 4 from left
so it flap 3 and 1 then flap 5 and 2 print head 4 .
so print 3 1 5 2 4 in console .
    4
    / \
    5 2
    / \
3 1

*/
