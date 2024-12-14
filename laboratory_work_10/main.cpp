#include <iostream>

using namespace std;

// ��� ������, ����������� ������ �������� ������ ���� ������
struct Node
{
    int info;     // �������� ����������, ���������� � ���� ����
    Node * next;  // ����� ���������� ���� ������
                  // (nullptr, ���� ������ ������� �������� ���������)
};

// ����������� ������
void print_list(Node * top)
{
    Node * p = top;  // ����� �������� �������� ������
    while (p != nullptr) {
        cout << p->info << " ";  // �������� �������� ���������� �������� ����
        p = p->next;  // ����� ���������� ���� ���������� �������
    }
}

// �������, �����������, ��� ��� �������� ������ � �������� `top`
// ����������� �� ����������.
bool list_is_sorted(Node * top)
{
    Node * p = top; // ����� �������� ���� ������

    while (p->next != nullptr) {
        // ���������� ����� � ������� ���� � ���������
        if (p->info >= p->next->info)
            return false;
        else
            p = p->next;  // ����� ���������� ���� ���������� �������
    }

    return true;
}

// ������������� ������ �� ���������� (�������� ���������� ��������)
void sort_list(Node * top)
{
    for (Node * a = top; a->next != nullptr; a = a->next)
        for (Node * b = a->next; b->next != nullptr; b = b->next)
            if (a->info > b->info) swap(a->info, b->info);
}

// �������������� � ������ ��� ��������, ��������� �� 3
void duplicate_numbers(Node * top)
{
    Node * p = top;
    while (p != nullptr) {
        // ���� ����� � ������� ���� ������� �� 3
        if (p->info % 3 == 0) {
            Node * q = new Node;  // ������ ����� ����
            q->info = p->info;    // � ��������� ����������,
            q->next = p->next;    // � ����� ����������� ������.
            p->next = q;
            p = q->next;
        }
        else {
            p = p->next;  // ����� ����� ���������� ���� ���������� �������.
        }
    }
}

// ������� �� ������ ��� ��������, ��������� �� 4
void remove_numbers(Node * &top)
{
    // ���� ��������� ����� ����������� �� �������
    while (top != nullptr && top->info % 4 == 0) {
        Node * temp = top->next;
        delete top;
        top = temp;
    }

    Node * p = top;
    while (p != nullptr && p->next != nullptr) {
        Node * temp = p->next;
        if (temp->info % 4 == 0) {
            p->next = temp->next;
            delete temp;
        }
        else {
            p = temp;
        }
    }
}

// �������� ������
void delete_list(Node * top)
{
    Node * p = top;
    while (p != nullptr) {
        Node * temp = p->next;
        delete p;
        p = temp;
    }
}


int main()
{
    // ������� ����������, � ������� ����� ��������� �����
    // ������� ���� ������ (�� ���� ����� ��� �������).
    // ���������� ������ ���� � ����� � ���� ���, ���� �������.
    // ������� top ������� ��������� nullptr.
    Node * top = nullptr;

    int n;    // ���������� ��������� ������������������,
    cin >> n; // ������� �� �������������� ������ � ����������.

    // ������ ������� ������������������ ������ ��������, ������ ���
    // �� ����������� � ������� ������.
    int x;
    cin >> x;

    // ������ ������� ������ � ��������� � ��� ����� `x`.
    top = new Node;
    top->info = x;
    top->next = nullptr;

    // ������� ��������������� ���������� `pp`, � ������� �����
    // ������� ����� ���������� ���� ������.
    // ���� ��� ��������� ��������� � ������.
    Node * pp = top;

    // ��� ��������� �������� ������������������ ������ � �����.
    for (int i = 1; i < n; i++) {
        cin >> x;
        Node * p = new Node;  // ������ ����� ���� � �������� ��� �����
        pp->next = p;  // ���������� ����� ������ ���� � �����������
        p->info = x;  // ���������� ����������� ����� � ����� ����
        p->next = nullptr;  // ���� ��� ����� ���� ���������, � ���������� � ���� ���.
        pp = p;  // �� ��������� �������� ����� ����� ���� ������ ����������
    }

    cout << "�������� ������: ";
    print_list(top);

    cout << endl;

    sort_list(top);
    cout << "��������������� ������: ";
    print_list(top);

    cout << endl;

    duplicate_numbers(top);
    cout << "������ ����� ������������ ���������, ��������� �� 3: ";
    print_list(top);

    cout << endl;

    remove_numbers(top);
    cout << "������ ����� �������� ���������, ��������� �� 4: ";
    print_list(top);

    delete_list(top);

    return 0;
}
