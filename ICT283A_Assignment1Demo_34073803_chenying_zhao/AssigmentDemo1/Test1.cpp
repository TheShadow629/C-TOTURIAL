#include"Vector.h"
#include"FileAnalysis.h"
#include"Bst_Tree.h"
void Test1()
{
    Vector<int> vec;
    for (int i = 0; i < 1000; i++)
    {
        vec.insert(i);
    }
    return;
}


void Test2()
{
    BinTreeNode<int> *root = nullptr;
    InsertBintree(root,1);
    InsertBintree(root, 2);
    InsertBintree(root, 3);
    InsertBintree(root, 4);

    auto it = find_val(root, 1);
    if (it == nullptr)
    {
        cout << "1 not found" << endl;
    }
    else
    {
        cout << "1 founded" << endl;
    }

    cout << "pre-traversal" << endl;
    Pre_Trival(root);

    cout << "in order-traversal" << endl;
    Mid_Trival(root);

    cout << "post-traversal" << endl;
    Last_Trival(root);


    clearTree(root);
    return;
}

void Test3()
{
    Time_key test_time_key;
    test_time_key.month = 1;
    test_time_key.year = 2011;

    cout << "Time_key year=" << test_time_key.year << endl;
    cout << "Time_key month=" << test_time_key.month << endl;


    Bst_Node bst_node;
    bst_node.key = test_time_key;
    cout << "Bst_Node key year="  << bst_node.key.year << endl;
    cout << "Bst_Node key month=" << bst_node.key.month << endl;
}
