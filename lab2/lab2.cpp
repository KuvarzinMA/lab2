#include <iostream>
#include <list>
#include <vector>
#include <deque>
#include <algorithm>
#include <numeric>
#include <set>  // ��� multiset
#include <map>  // ��� multimap
#include <iterator>
using namespace std;

// ������� ��� ������� 1
void task1() {
    int n;
    cout << "������� ���������� ���������: ";
    cin >> n;

    list<int> L;
    cout << "������� " << n << " ����� �����:\n";
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        L.push_back(x);
    }

    // ����� � �������� �������
    cout << "�������� ������ L � �������� �������: ";
    for (int x : L) {
        cout << x << " ";
    }
    cout << endl;

    // ����� � �������� �������
    cout << "�������� ������ L � �������� �������: ";
    L.reverse();
    for (int x : L) {
        cout << x << " ";
    }
    cout << endl;
}

// ������� ��� ������� 2
void task2() {
    int n;
    cout << "������� ���������� ��������� (������ �����): ";
    cin >> n;

    if (n % 2 != 0) {
        cout << "������: ���������� ��������� ������ ���� ������!" << endl;
        return;
    }

    vector<int> V(n);
    deque<int> D(n);

    cout << "������� " << n << " ��������� ������� V:\n";
    for (int i = 0; i < n; ++i) {
        cin >> V[i];
    }

    cout << "������� " << n << " ��������� ���� D:\n";
    for (int i = 0; i < n; ++i) {
        cin >> D[i];
    }

    // ���������� ������ �������� ��������� ���� � ����� �������
    V.insert(V.end(), D.begin(), D.begin() + n / 2);

    // ���������� ������ �������� ��������� ������� � ������ ���� � �������� �������
    D.insert(D.begin(), V.rbegin() + n / 2, V.rend());

    // ����� ������������ �������
    cout << "����������� ������ V: ";
    for (int x : V) {
        cout << x << " ";
    }
    cout << endl;

    // ����� ������������ ����
    cout << "����������� ��� D: ";
    for (int x : D) {
        cout << x << " ";
    }
    cout << endl;
}

// ������� ��� ������� 3
void task3() {
    int N;
    cout << "������� ���������� ��������� ������� (��������, >= 5): ";
    cin >> N;

    if (N < 5 || N % 2 == 0) {
        cout << "������: ���������� ��������� ������ ���� �������� � >= 5!" << endl;
        return;
    }

    vector<int> V(N);
    cout << "������� " << N << " ��������� ������� V:\n";
    for (int i = 0; i < N; ++i) {
        cin >> V[i];
    }

    // �������� ���� ������� ���������
    int mid = N / 2;
    V.erase(V.begin() + mid - 1, V.begin() + mid + 2);

    // ����� ������������ �������
    cout << "����������� ������ V: ";
    for (int x : V) {
        cout << x << " ";
    }
    cout << endl;
}

// ������� ��� ������� 4: �������������� ����������
void task4() {
    double A, D;
    int N;
    cout << "������� ������ ������� (A), �������� (D) � ���������� ��������� (N): ";
    cin >> A >> D >> N;

    vector<double> progression(N);

    // ���������� generate_n ��� ��������� ��������� �������������� ����������
    generate_n(progression.begin(), N, [=, n = 0]() mutable {
        return A + n++ * D;
        });

    cout << "������ " << N << " ������ �������������� ����������: ";
    for (double x : progression) {
        cout << x << " ";
    }
    cout << endl;
}

// ������� ��� ������� 5: ����� "�������� ��������" � �������
void task5() {
    int n;
    cout << "������� ���������� ��������� (������ �����): ";
    cin >> n;

    if (n % 2 != 0) {
        cout << "������: ���������� ��������� ������ ���� ������!" << endl;
        return;
    }

    vector<int> V(n);
    cout << "������� " << n << " ��������� ������� V:\n";
    for (int i = 0; i < n; ++i) {
        cin >> V[i];
    }

    // ����� �������� � ������ ��������, ������� ��������� � ��������� �� ������ ��������
    auto first_half_begin = V.begin();
    auto first_half_end = first_half_begin + n / 2;
    auto second_half_begin = first_half_end;
    auto second_half_end = V.end();

    auto it = find_first_of(first_half_begin, first_half_end, second_half_begin, second_half_end);

    if (it != first_half_end) {
        V.insert(it, *it); // ��������� ��������� ������� ����� ��� ��
    }

    // ����� ������������ �������
    cout << "����������� ������ V: ";
    for (int x : V) {
        cout << x << " ";
    }
    cout << endl;
}

// ������� ��� ������� 6: ����������� ����� � �������������� rotate_copy
void task6() {
    int K, n;
    cout << "������� ����� K (0 < K < 5): ";
    cin >> K;

    if (K <= 0 || K >= 5) {
        cout << "������: K ������ ���� �� 1 �� 4!" << endl;
        return;
    }

    cout << "������� ���������� ��������� ������ (�� ����� 10): ";
    cin >> n;

    if (n < 10) {
        cout << "������: ������ ���� ������� 10 ���������!" << endl;
        return;
    }

    list<int> L;
    cout << "������� " << n << " ��������� ������ L:\n";
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        L.push_back(x);
    }

    // �������� ���������� ��� 5 ������ � 5 ��������� ���������
    auto first_five_begin = L.begin();
    auto first_five_end = next(first_five_begin, 5);
    auto last_five_begin = prev(L.end(), 5);
    auto last_five_end = L.end();

    // ����� ��� ������ �� K ������� ������ (��� ������ 5 ���������)
    list<int> shifted_right(5);
    rotate_copy(first_five_begin, prev(first_five_end, K), first_five_end, shifted_right.begin());

    // ����� ��� ������ �� K ������� ����� (��� ��������� 5 ���������)
    list<int> shifted_left(5);
    rotate_copy(last_five_begin, next(last_five_begin, K), last_five_end, shifted_left.begin());

    // ������� ���������� ��������� � ������
    L.insert(L.end(), shifted_right.begin(), shifted_right.end()); // � �����
    L.insert(L.begin(), shifted_left.begin(), shifted_left.end()); // � ������

    // ����� ������������ ������
    cout << "����������� ������ L: ";
    for (int x : L) {
        cout << x << " ";
    }
    cout << endl;
}

// ������� ��� ������� 7: ������� ��������������� �������� �������
void task7() {
    int n;
    cout << "������� ���������� ��������� ������� (������ �����): ";
    cin >> n;

    if (n % 2 != 0) {
        cout << "������: ���������� ��������� ������ ���� ������!" << endl;
        return;
    }

    vector<int> V(n);
    cout << "������� " << n << " ��������� ������� V:\n";
    for (int i = 0; i < n; ++i) {
        cin >> V[i];
    }

    // ������ ��� ��������� ����������
    vector<int> sorted_half(n / 2);
    partial_sort_copy(V.begin(), V.end(), sorted_half.begin(), sorted_half.end());

    // ������� ������ �������� ���������������� ������� � �����
    V.insert(V.end(), sorted_half.begin(), sorted_half.end());

    // ����� ������������ �������
    cout << "����������� ������ V: ";
    for (int x : V) {
        cout << x << " ";
    }
    cout << endl;
}
void task8() {
    list<string> L;
    int n;
    cout << "������� ���������� ���� � ������ L: ";
    cin >> n;

    // �������� ������������ �����
    if (n < 2) {
        cout << "���������� ���� ������ ���� >= 2 ��� ���������� ������!\n";
        return;
    }

    cout << "������� " << n << " ����:\n";
    for (int i = 0; i < n; ++i) {
        string word;
        cin >> word;
        L.push_back(word);
    }

    deque<string> D;

    // adjacent_difference ������� ��������� �������, ������� ���������� ������ ���������
    adjacent_difference(next(L.begin()), L.end(), inserter(D, D.begin()), [](const string& a, const string& b) {
        return string(1, b.back()) + string(1, a.front());
        });

    // ����� ����
    cout << "�������� ���� D: ";
    for (const string& str : D) {
        cout << str << " ";
    }
    cout << endl;
}

void task9() {
    int N, size0;
    cout << "������� ���������� �������� (N): ";
    cin >> N;

    cout << "������� ������ ������� V0: ";
    cin >> size0;

    if (N <= 0 || size0 <= 0) {
        cout << "���������� �������� � ������ ������� V0 ������ ���� ������ 0!\n";
        return;
    }

    vector<int> V0(size0);
    cout << "������� �������� ������� V0:\n";
    for (int i = 0; i < size0; ++i) {
        cin >> V0[i];
    }

    int count = 0;
    for (int i = 1; i <= N; ++i) {
        int sizeI;
        cout << "������� ������ ������� V" << i << ": ";
        cin >> sizeI;

        if (sizeI < size0) {
            cout << "������ ������� V" << i << " ������ ���� �� ������ ������� V0!\n";
            continue;
        }

        vector<int> Vi(sizeI);
        cout << "������� �������� ������� V" << i << ":\n";
        for (int j = 0; j < sizeI; ++j) {
            cin >> Vi[j];
        }

        multiset<int> setV0(V0.begin(), V0.end()), setVi(Vi.begin(), Vi.end());
        if (includes(setVi.begin(), setVi.end(), setV0.begin(), setV0.end())) {
            count++;
        }
    }

    cout << "���������� ��������, ���������� ��� �������� V0: " << count << endl;
}

// ������� 10: ����������� ��������� ������� �� ��������� ����� � multimap
void task10() {
    int n;
    cout << "������� ���������� ��������� ������� V: ";
    cin >> n;

    if (n <= 0) {
        cout << "���������� ��������� ������ ���� �������������!\n";
        return;
    }

    vector<int> V(n);
    cout << "������� " << n << " ��������� ������� V:\n";
    for (int i = 0; i < n; ++i) {
        cin >> V[i];
    }

    multimap<int, int> M;

    // ��������� �������� � multimap, ��������� �� ��������� �����
    for (int x : V) {
        int last_digit = x % 10;  // ��������� ����� �����
        M.insert(pair<int, int>(last_digit, x));  // ��������� ������� � multimap
    }

    // ����� ����������� multimap � �������������� ������������ ����������
    cout << "����������� ��������� �� ��������� �����:\n";
    for (multimap<int, int>::iterator it = M.begin(); it != M.end(); ++it) {
        cout << "���� (��������� �����): " << it->first << " -> ��������: " << it->second << endl;
    }
}


int main() {
    setlocale(LC_ALL, "RUSSIAN");

    while (true) {
        cout << "\n�������� �������:\n";
        cout << "1. ������� 1: ������ � �������\n";
        cout << "2. ������� 2: ������ � �������� � �����\n";
        cout << "3. ������� 3: �������� ������� ��������� �������\n";
        cout << "4. ������� 4: �������������� ����������\n";
        cout << "5. ������� 5: ����� ������������ �������� � ������� �������� ��������\n";
        cout << "6. ������� 6: ����������� ����� � �������������� rotate_copy\n";
        cout << "7. ������� 7: ���������� ������ �������� ���������������� �������\n";
        cout << "8. ������� 8: �������� ���� � ������� adjacent_difference\n";
        cout << "9. ������� 9: ����� ��������, ���������� �������� V0 � ������� includes\n";
        cout << "10. ������� 10: ����������� ��������� ������� �� ��������� ����� � multimap\n";
        cout << "0. �����\n";
        cout << "��� �����: ";

        int choice;
        cin >> choice;

        switch (choice) {
        case 1:
            task1();
            break;
        case 2:
            task2();
            break;
        case 3:
            task3();
            break;
        case 4:
            task4();
            break;
        case 5:
            task5();
            break;
        case 6:
            task6();
            break;
        case 7:
            task7();
            break;
        case 8:
            task8();
            break;
        case 9:
            task9();
            break;
        case 10:
            task10();
            break;
        case 0:
            cout << "����� �� ���������...\n";
            return 0;
        default:
            cout << "������������ �����. ���������� �����.\n";
        }
    }

    return 0;
}