#include <iostream>

class CharStack {
private:
    static const int INITIAL_CAPACITY = 10; // ���������� ����� ������
    char* stack;
    int capacity; // ������� ����������� ��������� �����
    int top; // ������ ��������� �������� �����

    // ��������� ������ ������
    void resize() {
        capacity *= 2; // �������� ��������� �����
        char* newStack = new char[capacity];

        for (int i = 0; i <= top; ++i) {
            newStack[i] = stack[i];
        }

        delete[] stack;
        stack = newStack;
    }

public:
    CharStack() : stack(new char[INITIAL_CAPACITY]), capacity(INITIAL_CAPACITY), top(-1) {}

    ~CharStack() {
        delete[] stack;
    }

    // ��������, �� ���� �������
    bool isEmpty() {
        return top == -1;
    }

    // �������� ������� � ����
    void push(char item) {
        if (top == capacity - 1) {
            resize(); // �������� ����� ������, ���� �������� ����� ������
        }
        stack[++top] = item;
        std::cout << "Symbol '" << item << "' pushed onto the stack.\n";
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

    for (char ch = 'A'; ch <= 'Z'; ++ch) {
        charStack.push(ch);
    }

    std::cout << "Stack size: " << charStack.size() << std::endl;

    charStack.pop();
    std::cout << "Stack size after pop: " << charStack.size() << std::endl;

    std::cout << "Top element: " << charStack.getTop() << std::endl;

    charStack.clear();
    std::cout << "Stack size after clear: " << charStack.size() << std::endl;

    return 0;
}
