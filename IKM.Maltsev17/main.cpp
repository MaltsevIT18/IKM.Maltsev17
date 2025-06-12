#include <iostream>
#include "tree.h"
using namespace std;
int main() {
    setlocale(LC_ALL, "");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << "============================================\n";
    cout << " ��������� ������� ��������� ������� �������\n";
    cout << "============================================\n\n";
    cout << "������� ���������� ����� � ������ ������\n";
    cout << "����� ��� ������� ������ � �������:\n";
    cout << "<���������� �������> <���������� �����> <������ �������� ����� ����� ������>\n\n";
    try {
        Tree tree;
        tree.readFromStream(cin);
        cout << tree.calculateExcuses() << "\n";
    }
    catch (const runtime_error& e) {
        cerr << "������: " << e.what() << "\n";
        return 1;
    }
    catch (...) {
        cerr << "����������� ������\n";
        return 1;
    }

    return 0;
}
