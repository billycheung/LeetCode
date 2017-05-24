#include <iostream>
#include <vector>
#include <map>
using namespace std;
#define ll long long int
/* https://leetcode.com/problems/add-two-numbers/ */


struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void addRemaining(ListNode*& t, ListNode*& newNode, bool& addOne){
        while (t != NULL){
            int tmp = t->val;
            if (addOne) {tmp++; addOne = false;}
            if (tmp >= 10) {addOne = true; tmp-=10;}
            newNode->next = new ListNode(tmp);
            newNode = newNode->next;
            t = t->next;
        }
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *t1 = l1, *t2 = l2, *root = NULL, *newNode = NULL;
        int n1 = 0, n2 = 0, m1 = 1, m2 = 1;

        bool addOne = false;
        while (t1 != NULL && t2 != NULL){
            int tmp = t1->val + t2->val;
            if (addOne) {tmp++; addOne = false;}
            if (tmp >= 10) {addOne = true; tmp-=10;}
            if (newNode == NULL){
                newNode = new ListNode(tmp);
                root = newNode;

            } else{
                newNode->next = new ListNode(tmp);
                newNode= newNode->next;
            }
            t1 = t1->next;
            t2 = t2->next;
        }

        addRemaining(t1, newNode, addOne);
        addRemaining(t2, newNode, addOne);
        if (addOne)
            newNode->next = new ListNode(1);
        return root;
    }
} solution;

void displayList(ListNode* node){
    ListNode* tmpNode = node;
    while (tmpNode != NULL){
        cout << tmpNode->val << " " ;
        tmpNode = tmpNode->next;
    }
    cout << endl;
}

ListNode* setList(ListNode *l, int len){
    ListNode *root;
    int tmp;
    for (int i=0; i<len; ++i){
        cin >> tmp;
        if (l == NULL){
            l = new ListNode(tmp);
            root = l;
        }
        else{
            l->next = new ListNode(tmp);
            l = l->next;
        }
    }
    return root;
}

int main() {
    int n, m;
    cin >> n >> m;
    ListNode *l1 = NULL, *l2 = NULL, *root1, *root2;

    root1 = setList(l1, n);
    displayList(root1);
    root2 = setList(l2, m);
    displayList(root2);
    ListNode* node = solution.addTwoNumbers(root1, root2);
    displayList(node);
    
    return 0;
}
