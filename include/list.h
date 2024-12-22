#include <iostream>

template <typename T>
class List {
private:
    struct Node {
        T data;
        Node* next;
        Node() : data(T()), next(nullptr) {}
        Node(T val, Node* nxt) {
            data = val;
            next = nxt;
        }
    };
    Node* first;

public:
    List() : first(nullptr) {}

    List(const List& other) : first(nullptr) {
        if (other.first == nullptr) return;
        first = new Node(other.first->data, nullptr);
        Node* curr2 = other.first->next;
        Node* curr1 = first;
        while (curr2 != nullptr) {
            curr1->next = new Node(curr2->data, nullptr);
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
    }

    ~List() {
        while (first != nullptr) {
            Node* tmp = first;
            first = first->next;
            delete tmp;
        }
    }

    void clear() {
        while (first != nullptr) {
            Node* tmp = first;
            first = first->next;
            delete tmp;
        }
    }

    List& operator=(const List& other) {
        if (this != &other) {
            clear();
            if (other.first == nullptr) {
                first = nullptr;
                return *this;
            }
            first = new Node(other.first->data, nullptr);
            Node* curr2 = other.first->next;
            Node* curr1 = first;
            while (curr2 != nullptr) {
                curr1->next = new Node(curr2->data, nullptr);
                curr1 = curr1->next;
                curr2 = curr2->next;
            }
        }
        return *this;
    }

    void push_front(T val) {
        first = new Node(val, first);
    }

    void push_back(T val) {
        if (first == nullptr) {
            first = new Node(val, nullptr);
        }
        else {
            Node* curr = first;
            while (curr->next != nullptr) {
                curr = curr->next;
            }
            curr->next = new Node(val, nullptr);
        }
    }

    T& operator[](size_t index) {
        Node* curr = first;
        for (size_t i = 0; i < index && curr != nullptr; i++) curr = curr->next;
        if (curr == nullptr) throw "Incorrect index";
        return curr->data;
    }

    int size() {
        if (first == nullptr) return 0;
        else {
            int count = 1;
            Node* curr = first;
            while (curr->next != nullptr) {
                count++;
                curr = curr->next;
            }
            return count;
        }
    }

    int is_empty() {
        if (this->first == nullptr) return 1;
        else return 0;
    }

    void insert(T data, Node* prev) {
        if (!prev) return;
        Node* node = new Node(data, prev->next);
        prev->next = node;
    }

    Node* get_first() const {
        return first;
    }

    void erase(Node* node) {
        if (!node) return;
        if (node == first) first = node->next;
        else {
            Node* curr = first;
            while (curr && curr->next != node) curr = curr->next;
            if (curr) curr->next = node->next;
        }
        delete node;
    }

    bool search(T val) const {
        Node* curr = first;
        while (curr != nullptr) {
            if (curr->data == val) {
                return 1;
            }
            curr = curr->next;
        }
        return 0;
    }

    bool operator==(const List& other) const {
        Node* curr1 = first;
        Node* curr2 = other.first;
        while (curr1 != nullptr && curr2 != nullptr) {
            if (curr1->data != curr2->data) {
                return false;
            }
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        return curr1 == nullptr && curr2 == nullptr;
    }


    void print() const {
        Node* curr = first;
        while (curr != nullptr) {
            std::cout << curr->data << " ";
            curr = curr->next;
        }
        std::cout << std::endl;
    }
};

