#include <iostream>

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class BinaryTree
{
public:
    Node *root;

    BinaryTree()
    {
        root = nullptr;
    }
    ~BinaryTree();
    BinaryTree(const BinaryTree &tree)
    {
        this->~BinaryTree();
        root = tree.root;
    }

    BinaryTree(BinaryTree &&other)
    {
        root = other.root;

        other.root = nullptr;
    }

    BinaryTree &operator=(const BinaryTree &tree)
    {
        this->~BinaryTree();

        root = tree.root;
        return *this;
    }

    BinaryTree &operator=(BinaryTree &&other)
    {
        this->~BinaryTree();
        root = other.root;

        other.root = nullptr;

        return *this;
    }

    void insert(int data)
    {
        Node *newNode = new Node(data);

        if (root == nullptr)
        {
            root = newNode;
        }
        else
        {
            Node *focusNode = root;
            Node *parent;

            while (true)
            {
                parent = focusNode;

                if (data < focusNode->data)
                {
                    focusNode = focusNode->left;
                    if (focusNode == nullptr)
                    {
                        parent->left = newNode;
                        return;
                    }
                }
                else
                {
                    focusNode = focusNode->right;
                    if (focusNode == nullptr)
                    {
                        parent->right = newNode;
                        return;
                    }
                }
            }
        }
    }

    void preOrderTraversal(Node *focusNode)
    {
        if (focusNode != nullptr)
        {

            std::cout << focusNode->data << " ";
            preOrderTraversal(focusNode->left);

            preOrderTraversal(focusNode->right);
        }
    }

    void erase(Node *focusNode, int val);

    int countBranches(Node *focusNode, int val)
    {
        int branches = 0;
        while (focusNode != nullptr)
        {
            if (focusNode->data == val)
            { 
                return branches;
            }
            else if (val < focusNode->data)
            { 
                focusNode = focusNode->left;
            }
            else 
            { 
                focusNode = focusNode->right;
            }
            branches++; 
        }
        return -1;

    }
    void clear(Node *focusNode)
    { 
        if (focusNode == nullptr)
            return;
        clear(focusNode->left);
        clear(focusNode->right);
        delete focusNode;
    }
};

int main()
{
    BinaryTree tree;

    tree.insert(50);
    tree.insert(25);
    tree.insert(75);
    tree.insert(12);
    tree.insert(37);
    tree.insert(43);
    tree.insert(30);

    tree.preOrderTraversal(tree.root);

    std::cout << "\nnumber of branches = " << tree.countBranches(tree.root, 12);



    return 0;
}

BinaryTree::~BinaryTree()
{
    clear(root);
}

void BinaryTree::erase(Node *focusNode, int val)
{
    if (focusNode != nullptr)
        {
            if (focusNode->data == val)
            { 
                delete[] focusNode;
                raise;
            }
            erase(focusNode->left, val);
            erase(focusNode->right, val);
        }

}

