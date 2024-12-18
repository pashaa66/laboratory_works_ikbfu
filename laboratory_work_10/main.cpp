#include <iostream>

using namespace std;

struct Node
{
    int info;     
    Node * next;  
                  
};

void print_list(Node * top)
{
    Node * p = top;  
    while (p != nullptr) {
        cout << p->info << " ";  
        p = p->next;  
    }
}
void delete_list(Node * top)
{
    Node * p = top;
    while (p != nullptr) {
        Node * temp = p->next;
        delete p;
        p = temp;
    }
}

bool hasOnlyOddDigits(int num) {
    while (num > 0) {
        int digit = num % 10;
        if (digit % 2 == 0) return false;
        num /= 10;
    }
    return true;
}

bool hasThreeDigitOddNumber(Node* top) {
    Node* p = top;
    while (p != nullptr) {
        if (p->info >= 100 && p->info <= 999 && hasOnlyOddDigits(p->info)) {
            return true;
        }
        p = p->next;
    }
    return false;
}

int getFirstDigit(int num) {
    while (num >= 10) {
        num /= 10;
    }
    return num;
}

void sortByFirstDigit(Node* top) {
    for (Node* a = top; a->next != nullptr; a = a->next) {
        for (Node* b = a->next; b != nullptr; b = b->next) {
            if (getFirstDigit(a->info) < getFirstDigit(b->info)) {
                swap(a->info, b->info);
            }
        }
    }
}

bool containsEight(int num) {
    while (num > 0) {
        if (num % 10 == 8) return true;
        num /= 10;
    }
    return false;
}

void processEights(Node* &top) {
    while (top != nullptr && !containsEight(top->info)) {
        Node* temp = top->next;
        delete top;
        top = temp;
    }
    
    Node* p = top;
    while (p != nullptr) {
        if (containsEight(p->info)) {
            Node* newNode = new Node;
            newNode->info = p->info;
            newNode->next = p->next;
            p->next = newNode;
            p = newNode->next; 
        } else {
            if (p == top) {
                top = p->next;
                delete p;
                p = top;
            } else {
                Node* prev = top;
                while (prev->next != p) prev = prev->next;
                prev->next = p->next;
                delete p;
                p = prev->next;
            }
        }
    }
}
int main() {
    Node* top = nullptr;
    int n;
    cin >> n;

    int x;
    cin >> x;
    top = new Node;
    top->info = x;
    top->next = nullptr;
    Node* pp = top;

    for (int i = 1; i < n; i++) {
        cin >> x;
        Node* p = new Node;
        pp->next = p;
        p->info = x;
        p->next = nullptr;
        pp = p;
    }

    print_list(top);
    cout << endl;

    if (!hasThreeDigitOddNumber(top)) {
        sortByFirstDigit(top);
    } else {
        processEights(top);
    }
    
    print_list(top);
    cout << endl;

    delete_list(top);
    
    return 0;
}
