#include <iostream>

using namespace std;

// Тип данных, описывающий каждый отдельно взятый узел списка
struct Node
{
    int info;     // полезная информация, хранящаяся в этом узле
    Node * next;  // адрес следующего узла списка
                  // (nullptr, если данный элемент является последним)
};

// Распечатать список
void print_list(Node * top)
{
    Node * p = top;  // Адрес текущего элемента списка
    while (p != nullptr) {
        cout << p->info << " ";  // Печатаем полезную информацию текущего узла
        p = p->next;  // Адрес следующего узла становится текущим
    }
}

// Функция, проверяющая, что все элементы списка с вершиной `top`
// упорядочены по неубыванию.
bool list_is_sorted(Node * top)
{
    Node * p = top; // Адрес текущего узла списка

    while (p->next != nullptr) {
        // Сравниваем числа в текущем узле и следующем
        if (p->info >= p->next->info)
            return false;
        else
            p = p->next;  // Адрес следующего узла становится текущим
    }

    return true;
}

// Отсортировать список по неубыванию (алгоритм сортировки обменами)
void sort_list(Node * top)
{
    for (Node * a = top; a->next != nullptr; a = a->next)
        for (Node * b = a->next; b->next != nullptr; b = b->next)
            if (a->info > b->info) swap(a->info, b->info);
}

// Продублировать в списке все элементы, делящиеся на 3
void duplicate_numbers(Node * top)
{
    Node * p = top;
    while (p != nullptr) {
        // Если число в текущем узле делится на 3
        if (p->info % 3 == 0) {
            Node * q = new Node;  // Создаём новый узел
            q->info = p->info;    // и заполняем содержимое,
            q->next = p->next;    // а также прописываем адреса.
            p->next = q;
            p = q->next;
        }
        else {
            p = p->next;  // Иначе адрес следующего узла становится текущим.
        }
    }
}

// Удалить из списка все элементы, делящиеся на 4
void remove_numbers(Node * &top)
{
    // Если удаляемое число расположено на вершине
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

// Удаление списка
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
    // Объявим переменную, в которой будет храниться адрес
    // первого узла списка (то есть адрес его вершины).
    // Изначально список пуст и узлов у него нет, даже вершины.
    // Поэтому top вначале равняется nullptr.
    Node * top = nullptr;

    int n;    // Количество элементов последовательности,
    cin >> n; // которое мы предварительно читаем с клавиатуры.

    // Первый элемент последовательности читаем отдельно, потому что
    // он разместится в вершине списка.
    int x;
    cin >> x;

    // Создаём вершину списка и размещаем в ней число `x`.
    top = new Node;
    top->info = x;
    top->next = nullptr;

    // Объявим вспомогательную переменную `pp`, в которой будем
    // хранить адрес последнего узла списка.
    // Пока что последний совпадает с первым.
    Node * pp = top;

    // Все остальные элементы последовательности читаем в цикле.
    for (int i = 1; i < n; i++) {
        cin >> x;
        Node * p = new Node;  // Создаём новый узел и получаем его адрес
        pp->next = p;  // Записываем адрес нового узла у предыдущего
        p->info = x;  // Записываем прочитанное число в новый узел
        p->next = nullptr;  // Пока что новый узел последний, и следующего у него нет.
        pp = p;  // на следующей итерации цикла новый узел станет предыдущим
    }

    cout << "Введённый список: ";
    print_list(top);

    cout << endl;

    sort_list(top);
    cout << "Отсортированный список: ";
    print_list(top);

    cout << endl;

    duplicate_numbers(top);
    cout << "Список после дублирования элементов, делящихся на 3: ";
    print_list(top);

    cout << endl;

    remove_numbers(top);
    cout << "Список после удаления элементов, делящихся на 4: ";
    print_list(top);

    delete_list(top);

    return 0;
}
