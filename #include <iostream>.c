#include <iostream>
using namespace std;

typedef int ElemType;
struct LNode {
    ElemType data;
    LNode* next;
};
typedef LNode* LinkList;


void InitRing(LinkList& L, int n) {
    if (n == 0) {
        L = nullptr;
        return;
    }
    LNode* r;
    L = r = new LNode{ 1, nullptr };
    for (int i = 2; i <= n; i++) {
        LNode* p = new LNode{ i, nullptr };
        r->next = p;
        r = p;
    }
    r->next = L;      
    L = r;         
}

void DeleteDeath(LinkList& L, int n, int k) {
    if (k <= 0) return;
    LNode* p = L;
    cout << "投入大海者编号如下：";

    int numToDelete = n / 2; 
    for (int i = 0; i < numToDelete; i++) {
        for (int j = 1; j < k; j++) {
            p = p->next;
        }
        LNode* q = p->next;
        p->next = q->next;
        cout << q->data << " ";
        delete q;

    }

    L = p;  
}


void OutRing(LinkList L, int n) {
    int remaining = (n + 1) / 2; 
    LNode* p = L->next; 
    cout << "\n幸存者编号：";
    for (int i = 0; i < remaining; i++) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main() {
    LinkList L;
    int n, k;
    cout << "输入总人数 n 和报数上限 k: ";
    cin >> n >> k;

    if (n <= 0 || k <= 0) {
        cout << "输入无效！" << endl;
        return 1;
    }

    InitRing(L, n);
    DeleteDeath(L, n, k);
    OutRing(L, n);

    return 0;
}