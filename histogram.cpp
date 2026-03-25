#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

int main() {
    // Входные данные (результаты измерений)
    std::vector<double> data;
    int n;

    std::cout << "Введите количество измерений: ";
    std::cin >> n;

    std::cout << "Введите значения:\n";
    for (int i = 0; i < n; i++) {
        double x;
        std::cin >> x;
        data.push_back(x);
    }

    // Количество интервалов (бинов) по формуле Стёрджеса
    int bins = (int)(1 + 3.322 * log10(n));

    double minVal = *std::min_element(data.begin(), data.end());
    double maxVal = *std::max_element(data.begin(), data.end());
    double binWidth = (maxVal - minVal) / bins;

    std::cout << "\nМин: " << minVal << "  Макс: " << maxVal << "\n";
    std::cout << "Число интервалов: " << bins << "  Ширина: " << binWidth << "\n\n";

    // Подсчёт частот
    std::vector<int> freq(bins, 0);
    for (double val : data) {
        int idx = (int)((val - minVal) / binWidth);
        if (idx >= bins) idx = bins - 1;
        freq[idx]++;
    }

    // Вывод гистограммы в консоль
    std::cout << "Гистограмма:\n";
    std::cout << std::string(50, '-') << "\n";

    int maxFreq = *std::max_element(freq.begin(), freq.end());
    int barWidth = 40; // максимальная ширина столбца

    for (int i = 0; i < bins; i++) {
        double lo = minVal + i * binWidth;
        double hi = lo + binWidth;
        int barLen = (int)((double)freq[i] / maxFreq * barWidth);

        printf("[%7.3f - %7.3f] | ", lo, hi);
        for (int j = 0; j < barLen; j++) std::cout << "#";
        printf(" %d\n", freq[i]);
    }

    std::cout << std::string(50, '-') << "\n";
    std::cout << "Всего измерений: " << n << "\n";

    return 0;
}
