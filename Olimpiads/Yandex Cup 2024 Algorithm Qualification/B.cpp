#include <iostream>
#include <vector>
using namespace std;

int countHills(const vector<int>& heights) {
    int n = heights.size();
    int count = 0;

    // Массивы для отслеживания длин непрерывно возрастающих и убывающих подпоследовательностей.
    vector<int> up(n, 0), down(n, 0);

    // Подсчитываем длины возрастающих подпоследовательностей.
    for (int i = 1; i < n; ++i) {
        if (heights[i] > heights[i - 1]) {
            up[i] = up[i - 1] + 1;
        }
    }

    // Подсчитываем длины убывающих подпоследовательностей.
    for (int i = n - 2; i >= 0; --i) {
        if (heights[i] > heights[i + 1]) {
            down[i] = down[i + 1] + 1;
        }
    }

    // Ищем горки, проверяя, где длина возрастающей и убывающей подпоследовательности больше нуля.
    for (int i = 1; i < n - 1; ++i) {
        if (up[i] > 0 && down[i] > 0) {
            ++count;
        }
    }

    return count;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> heights(n);
        for (int i = 0; i < n; ++i) {
            cin >> heights[i];
        }

        // Вычисляем количество горок для текущего набора данных.
        int result = countHills(heights);
        cout << result << endl;
    }

    return 0;
}
