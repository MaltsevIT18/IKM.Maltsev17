#include <iostream>
#include "tree.h"
using namespace std;
int main() {
    setlocale(LC_ALL, "");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << "============================================\n";
    cout << " Программа расчета извинений мудрого тритона\n";
    cout << "============================================\n\n";
    cout << "Введите количество гнезд в первой строке\n";
    cout << "Далее для каждого гнезда в формате:\n";
    cout << "<количество соседей> <количество писем> <номера соседних гнезд через пробел>\n\n";
    try {
        Tree tree;
        tree.readFromStream(cin);
        cout << tree.calculateExcuses() << "\n";
    }
    catch (const runtime_error& e) {
        cerr << "Ошибка: " << e.what() << "\n";
        return 1;
    }
    catch (...) {
        cerr << "Неизвестная ошибка\n";
        return 1;
    }

    return 0;
}
