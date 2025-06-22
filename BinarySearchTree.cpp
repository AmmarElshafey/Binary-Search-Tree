// BinarySearchTree.cpp : 

#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};
class BinarySearchTree
{
public:
    Node* root;
    BinarySearchTree()
    {
        root = nullptr;
    }
   ~ BinarySearchTree()
    {
       Clear(root);
    }

    Node* Insert(Node* r, int value)
    {
        if (r == nullptr)
        {
            return new Node(value);
        }
        else if (value > r->data)
        {
            r->right = Insert(r->right, value);
        }
        else
        {
            r->left = Insert(r->left, value);
        }
        return r;
    }
    void Insert(int item)
    {
        root = Insert(root, item);
    }

    void PreOrder(Node* r) //print   root -> left -> right
    {
        if (r == nullptr)return ;
            cout << r->data << " \t ";
            PreOrder(r->left);
            PreOrder(r->right);
    }
    void InOrder(Node* r) //print  left -> root -> right
    {
        if (r == nullptr)return;
            InOrder(r->left);
            cout << r->data << " \t ";
            InOrder(r->right);
    }
    void PostOrder(Node* r) // print  left -> right -> root 
    {
        if (r == nullptr)return;
            PostOrder(r->left);
            PostOrder(r->right);
            cout << r->data << " \t ";
    }
    bool Search(Node* r, int value)
    {
        if (r == nullptr) return false;
        else if (r->data == value) return true;
        else if (value > r->data)
            return Search(r->right, value);
        else 
            return Search(r->left, value);
    }
    Node* Min(Node* r)
    {
        if (r == nullptr) return nullptr;
        if (r->left == nullptr) return r;
        else
            return Min(r->left);
    }
    Node* Max(Node* r)
    {
        if (r == nullptr) return nullptr;
        if (r->right == nullptr) return r;
        else
            return Max(r->right);
    }
    Node* Delete(Node* r , int value)
    {
        if (r == nullptr) return nullptr;
        if (value < r->data)
        {
            r->left = Delete(r->left, value);
        }
        else if (value > r->data)
        {
            r->right = Delete(r->right, value);
        }
        else
        {
            
            if (r->right == nullptr && r->left == nullptr)  // case 1 No child
            {
                delete r;
                r = nullptr;
            }
            else if (r->right != nullptr && r->left == nullptr) // case 2 one child 
            {
                Node* temp = r->right;
                delete  r;
                return temp;


            }
            else if (r->right == nullptr && r->left != nullptr)  // case 2 one child 
            {
                Node* temp = r->left;
                delete  r;
                return temp;

            }
            else                                               //case 3 two children
            {
                Node* min = Min(r->right);
                r->data = min->data;
                r->right = Delete(r->right, min->data);
            }
        }
        return r;
    }
    void Delete(int value)
    {
        root = Delete(root, value);
    }
    void Clear(Node* r)
    {
        if (r == nullptr) return ;
        Clear(r->left);
        Clear(r->right);
        delete r;
    }
};
int main()
{
    BinarySearchTree BST;
    for (int i = 1; i < 20; i = i + 3)
    {
        BST.Insert(i);
    }
    for (int i = 30; i > 0; i = i - 4)
    {
        BST.Insert(i);
    }
    cout << "Pre order : " << endl;
    BST.PreOrder(BST.root);
    cout << endl <<"------------------------------------------------------------------------------" << endl;
    cout << "In order : " << endl;
    BST.InOrder(BST.root);
    cout<< endl << "------------------------------------------------------------------------------" << endl;
    cout << "Post order : " << endl;
    BST.PostOrder(BST.root);
    cout << endl << "-----------------------------------------------------------------------------" << endl;
    cout << "Enter num to check" << endl;
    int check;
    cin >> check;
    if (BST.Search(BST.root, check))
        cout<< check << "  is existed" << endl;
    else
        cout<< check << "  is not existed" << endl;
    Node* max = BST.Max(BST.root);
    cout << "Maximam is : " << max->data << endl;
    Node* min = BST.Min(BST.root);
    cout << "Minimam is : " << min->data << endl;
    cout << "Enter num to delete" << endl;
    int delval;
    cin >> delval;
    BST.Delete( delval);
    cout << "After Deletion : " << endl;
    BST.InOrder(BST.root);
    BST.Clear(BST.root);
    cout << "After clear : " << endl;
    BST.InOrder(BST.root);

}

