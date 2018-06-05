#include <iostream>
#include "Tree.h"
#include "Node.h"

using namespace std;

int main() {
    Tree t;
    Node *root = nullptr;
    int opc = -1;

    do
        {
            cout << "ABB\n 1. Add node \n 2. Print inorder.\n 3. Print Postorder.\n 4. Print Preorder\n5. Delete Node\n6. Print Leaves\n7. Print height" << endl;
            cout << "Choose an option: ";
            cin >> opc;

            switch (opc) {
                case 1:
                {
                    int num;
                    cout << "Type a number: ";
                    cin >> num;
                    root = t.insertNode(root, num, nullptr);
                    break;
                }

                case 2:
                {
                    t.inorder(root);
                    break;
                }

                case 3:
                {
                    t.postOrder(root);
                    break;
                }

                case 4:
                {
                    break;
                }

                case 5:
                {
                    int data;
                    cout << "Type number to delete: ";
                    cin >> data;
                    t.Delete(root, data);
                }

                case 6:
                {
                    t.printLeaf(root);
                    break;
                }

                case 7:
                {
                    t.sizeofTree(root);
                }

                default:
                    break;
            }
        } while (opc != -1);

        return 0;
}
