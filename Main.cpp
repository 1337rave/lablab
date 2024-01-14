#include <iostream>

class CharStack {
private:
    static const int MAX_SIZE = 100; // Максимальний розмір стеку
    char stack[MAX_SIZE];
    int top; // Індекс верхнього елементу стеку

public:
    CharStack() : top(-1) {}

    // Перевірка, чи стек порожній
    bool isEmpty() {
        return top == -1;
    }

    // Перевірка, чи стек повний
    bool isFull() {
        return top == MAX_SIZE - 1;
    }

    // Внесення символу в стек
    void push(char item) {
        if (!isFull()) {
            stack[++top] = item;
            std::cout << "Symbol '" << item << "' pushed onto the stack.\n";
        }
        else {
            std::cout << "Stack overflow. Cannot push more symbols.\n";
        }
    }

    // Видалення символу зі стеку
    void pop() {
        if (!isEmpty()) {
            char poppedItem = stack[top--];
            std::cout << "Symbol '" << poppedItem << "' popped from the stack.\n";
        }
        else {
            std::cout << "Stack underflow. Cannot pop from an empty stack.\n";
        }
    }

    // Підрахунок кількості символів в стеці
    int size() {
        return top + 1;
    }

    // Очищення стеку
    void clear() {
        top = -1;
        std::cout << "Stack cleared.\n";
    }

    // Отримання верхнього символу без видалення
    char getTop() {
        if (!isEmpty()) {
            return stack[top];
        }
        else {
            std::cout << "Stack is empty.\n";
            return '\0'; // Повертаємо нульовий символ, щоб позначити порожній стек
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
