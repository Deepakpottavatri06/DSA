#include <iostream>
#include <queue>
#include <stack>
#include <array>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node()
    {
        left = nullptr;
        right = nullptr;
    }
    Node(int v)
    {
        this->data = v;
        left = nullptr;
        right = nullptr;
    }
};
void level_order(Node *root)
{
    queue<Node *> qu;
    qu.push(root);
    qu.push(NULL);
    while (qu.empty() != true)
    {
        Node *temp = qu.front();
        qu.pop();
        if (temp == NULL)
        {
            cout << endl;
            if (!qu.empty())
            {
                qu.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if ((temp->left))
            {
                qu.push(temp->left);
            }
            if (temp->right)
            {
                qu.push(temp->right);
            }
        }
    }
}
Node *inserttoBST(Node *root, int val)
{
    // base case
    if (root == NULL)
    {
        root = new Node(val);
        return root;
    }
    if (val > root->data)
    {
        // if val is greater then insert to right
        root->right = inserttoBST(root->right, val);
    }
    if (val < root->data)
    {
        // if val is lesser then insert to left
        root->left = inserttoBST(root->left, val);
    }
    return root;
}

void takeinput(Node *&root)
{
    cout << "enter the data : " << endl;
    int val;
    cin >> val;
    while (val != -1)
    {
        root = inserttoBST(root, val);
        cout << "enter the data : " << endl;
        cin >> val;
    }
}

Node *arraytoBST(Node *root, int arr[], int size)
{
    int len = size;
    for (int i = 0; i < len; i++)
    {
        root = inserttoBST(root, arr[i]);
    }
    return root;
}

bool searchBST(Node *root, int val)
{
    Node *temp = root;
    while (temp != NULL)
    {
        if (temp->data == val)
        {
            return true;
        }
        else if (temp->data > val)
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }
    return false;
}

int min_BST(Node *root)
{
    Node *temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }

    return temp->data;
}
int max_BST(Node *root)
{
    Node *temp = root;
    while (temp->right != NULL)
    {
        temp = temp->right;
    }

    return temp->data;
}
// inorder gives all values in BST in increasing order
void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

Node *deletefromBST(Node *root, int val)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == val)
    {   // 0 child
        if (root->right == NULL && root->left == NULL)
        {
            delete root;
            return NULL;
        }
         // 1child

        if(root->left == NULL && root->right!=NULL){
            Node * temp = root->right;
            delete root;
            return temp;
        }
         if(root->left != NULL && root->right==NULL){
            Node * temp = root->left;
            delete root;
            return temp;
        }

        //2child
        if(root->left != NULL && root->right!=NULL){
            int mini = min_BST(root->right);
            root->data = mini;
            root->right = deletefromBST(root->right,mini);
            return root;
        }

    }

    else if (root->data > val){
        root->left = deletefromBST(root->left,val);
        return root;
    }

    else{
        root->right = deletefromBST(root->right,val);
        return root;
    }
}

int main()
{
    Node *root = NULL;
    takeinput(root);

    // int const size = 5;
    // int array[size];

    // for (int i = 0; i < size; i++) {
    //     cout << "Enter the element: "<<endl;
    //    cin >> array[i];
    // }
    // 50 20 70 10 30 90 110 -1
    // root = arraytoBST(root,array,size);
    // level_order(root);
    cout << "level order :" <<endl;
    level_order(root);
    cout << "inorder :"<<endl;
    inorder(root);

    // root = deletefromBST(root,30); 0child
    root = deletefromBST(root,50); // 2 child

    cout << endl << "level order :" <<endl;
    level_order(root);
    cout << "inorder :"<<endl;
    inorder(root);





    return 0;
}