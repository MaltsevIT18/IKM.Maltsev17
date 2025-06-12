#include "tree.h"

Nest::Nest(int num, int letters) : number(num), letterCount(letters) {}
//�������� �� ���������������
void Nest::setLetterCount(int count) {
    if (count < 0) throw invalid_argument("���������� ����� �� ����� ���� �������������");
    letterCount = count;
}

int Nest::getLetterCount() const { return letterCount; }
int Nest::getNumber() const { return number; }
const vector<int>& Nest::getNeighbors() const { return neighbors; }
void Nest::addNeighbor(int neigh) { neighbors.push_back(neigh); }

void Tree::addNest(const Nest& nest) {
    nests[nest.getNumber()] = nest;
}
//������ �� ������
void Tree::readFromStream(istream& is) {
    int M;
    if (!(is >> M)) throw runtime_error("������������ ����� �����");
    if (M <= 0 || M >= 1000) throw runtime_error("����� ����� ��� ��������� 1..999");
    nests.clear();
    for (int i = 1; i <= M; i++) {
        int ni, li;
        if (!(is >> ni >> li))
            throw runtime_error("������ ������ ������ ������");
        if (ni < 0) throw runtime_error("���������� ������� �� ����� ���� �������������");
        if (li < 0) throw runtime_error("���������� ����� �� ����� ���� �������������");
        Nest nest(i, li);
        for (int j = 0; j < ni; j++) {
            int neigh;
            if (!(is >> neigh)) throw runtime_error("������ ������ ������");
            nest.addNeighbor(neigh);
        }
        addNest(nest);
    }
}
//������� ������
int  Tree::dfs(int current, int parent) {
    const Nest& nest = nests[current];
    int excuses = 0;
    bool hasLetterInSubtree = nest.getLetterCount() > 0;
    //��������� ���������� ���������
    for (int neigh : nest.getNeighbors()) {
        if (neigh == parent) continue;
        bool childHasLetters = dfs(neigh, current) > 0;
        if (childHasLetters) {
            if (nests[neigh].getLetterCount() == 0)
                excuses++;
            hasLetterInSubtree = true;
        }
    }
    return hasLetterInSubtree ? excuses + nest.getLetterCount() : 0;
}
//��������� �� �������
int Tree::calculateExcuses() {
    if (nests.empty())
        throw runtime_error("������ ������");
    if (nests.find(1) == nests.end())
        throw runtime_error("��� ������ � ������� 1");

    return dfs(1, -1);
}
