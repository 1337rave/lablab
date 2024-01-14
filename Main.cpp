#include <iostream>

class CharStack {
private:
    static const int MAX_SIZE = 100; // ������������ ����� �����
    char stack[MAX_SIZE];
    int top; // ������ ��������� �������� �����

public:
    CharStack() : top(-1) {}

    // ��������, �� ���� �������
    bool isEmpty() {
        return top == -1;
    }

    // ��������, �� ���� ������
    bool isFull() {
        return top == MAX_SIZE - 1;
    }

    // �������� ������� � ����
    void push(char item) {
        if (!isFull()) {
            stack[++top] = item;
            std::cout << "Symbol '" << item << "' pushed onto the stack.\n";
        }
        else {
            std::cout << "Stack overflow. Cannot push more symbols.\n";
        }
    }

    // ��������� ������� � �����
    void pop() {
        if (!isEmpty()) {
            char poppedItem = stack[top--];
            std::cout << "Symbol '" << poppedItem << "' popped from the stack.\n";
        }
        else {
            std::cout << "Stack underflow. Cannot pop from an empty stack.\n";
        }
    }

    // ϳ�������� ������� ������� � �����
    int size() {
        return top + 1;
    }

    // �������� �����
    void clear() {
        top = -1;
        std::cout << "Stack cleared.\n";
    }

    // ��������� ��������� ������� ��� ���������
    char getTop() {
        if (!isEmpty()) {
            return stack[top];
        }
        else {
            std::cout << "Stack is empty.\n";
            return '\0'; // ��������� �������� ������, ��� ��������� ������� ����
        }
    }
};

int main() {
    CharStack charStack;

    charStack.push('A');
    charStack.push('B');
    charStack.push('C');

    std::cout << "Stack size: " << charStack.size() << std::endl;

    charStack.pop();
    std::cout << "Stack size after pop: " << charStack.size() << std::endl;

    std::cout << "Top element: " << charStack.getTop() << std::endl;

    charStack.clear();
    std::cout << "Stack size after clear: " << charStack.size() << std::endl;

    return 0;
}
