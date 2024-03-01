#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class Node{
    public:
    int data;
    Node * left;
    Node * right ;
    Node(){
        left = nullptr;
        right = nullptr;
    }
    Node(int v){
        this->data = v;
        left = nullptr;
        right = nullptr;
    }
   
};



Node *  buildTree(Node * root){
    cout << "Enter the data : "<<endl;
    int v;
    cin>>v;
    root = new Node(v);
    if(v==-1){
        return NULL;
    }
    cout << "Enter the data for left of "<< v <<endl;
    root->left = buildTree(root->left);
    cout << "Enter the data for right of "<< v <<endl;
    root->right = buildTree(root->right);
    return root;

}
void level_order(Node * root){
    queue <Node*> qu;
    qu.push(root);
    qu.push(NULL);
    while(qu.empty()!=true){
        Node * temp = qu.front();
        qu.pop();
        if(temp == NULL){
            cout << endl;
            if(!qu.empty()){
                qu.push(NULL);
            }

        }
        else{
            cout<<temp->data<< " ";
            if((temp->left) ){
                qu.push(temp->left);
        }
            if(temp->right){
                qu.push(temp->right);
        }
        }
    }


}

void reverse_level_order(Node * root){
    queue <Node *> qu;
    stack <Node *> q;
    
    qu.push(root);
    qu.push(NULL);
 
    while(qu.empty()!=true){
        Node * temp = qu.front();
        qu.pop();
        if(temp == NULL){
            cout << endl;
            if(!qu.empty()){
                qu.push(NULL);
                q.push(NULL);

            }

        }
        else{
            q.push(temp);
            if((temp->left) ){
                qu.push(temp->left);
        }
            if(temp->right){
                qu.push(temp->right);
        }
        }
    }
    while(!q.empty()){
        if(q.top()){
            cout << q.top()->data << " ";
        }
        else {
            cout<< endl;
        }
        q.pop();
    }
}
void inorder(Node * root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void preorder(Node * root){
    if(root == NULL){
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(Node * root){
    if(root == NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

Node * buildTreefromlevelorder(Node * root){
    queue <Node *> q;
    cout << "Enter the data for root :"<<endl;
    int data;;
    cin>>data;
    root = new Node(data);
    q.push(root);
 
    while(q.empty() != true){
        Node * temp = q.front();
        q.pop();
        int ld;
        cout<<"enter the left data for "<< temp->data << endl;
        cin >> ld;
        if(ld!= -1){
            temp->left =  new Node(ld);
            q.push(temp->left);
        }
       int rd;
        cout<<"enter the right data for "<< temp->data << endl;
        cin >> rd;
        if(rd!= -1){
            temp->right =  new Node(rd);
            q.push(temp->right);
        }
       
    }
    return root;
}

void leafcounter(Node * root, int &count){
    if(root == NULL){
        return;
    }
    leafcounter(root->left,count);
    if(root->left == NULL && root->right == NULL){
        count++;
    }
    leafcounter(root->right,count);

    
}
int height(Node * root , int targetnode){
    queue <Node *> q;
    int height =0;
    q.push(root);
    q.push(NULL);
    bool flag =false;

    while(!q.empty()){
        Node * temp = q.front();
        q.pop();
        if(temp == NULL){
            if(flag){
                height++;
            }
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            if(temp->data == targetnode){
                flag = true;
            }
            if(temp->left != NULL){
                q.push(temp->left);
            }
            if(temp->right != NULL){
                q.push(temp->right);
            }
        }
    }
    if(!flag){
        cout<< "The entered value doesn't exist in the tree "<<endl;
    }
    return height-1;

}
int main() {
    Node * root = NULL;
    // root = buildTree(root);
    root = buildTreefromlevelorder(root);
    level_order(root);
    // reverse_level_order(root);
    // cout << "Inorder : ";
    // inorder(root);
    // cout << endl;
    // cout << "Preorder : ";
    // preorder(root);
    // cout << endl;
    // cout << "Postorder : ";
    // postorder(root);
    // cout << endl;

    // int count =0;
    // leafcounter(root, count );       
    // cout << "There are "<< count <<  " leaf nodes "<<endl;

  cout << "enter a number to find its height "<<endl;
  int val;
  cin>>val;
  cout << "The height is "<< height(root,val) << endl;



    return 0;
}