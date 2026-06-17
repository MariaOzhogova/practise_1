// идея: читаем пирамиду (сначала всю, далее - по строчкам), берём значения первой строчки (там одно число),
// читаем следующую строчку и находим соседей числа из предыдущей строчки, смотрим, кто из них меньше,
// суммируем с предыдущим и добавляем в path (как шли по пирамиде). на следующих строчках делаем всё то же самое
#include <iostream>
#include <vector>
#include <algorithm>
int main() {
    int n = 0;
    std::cin >> n;
    std::vector<std::vector<int>> pyramid(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            int value;
            std::cin >> value;
            pyramid[i].push_back(value);
        }
    }
    int sm = pyramid[0][0];
    int index_num = 0; 
    std::vector<int> path;
    path.push_back(pyramid[0][0]);
    for (int i = 1; i < n; i++) {
        int mn = std::min(pyramid[i][index_num], pyramid[i][index_num + 1]);
        sm += mn;
        path.push_back(mn);
        if (pyramid[i][index_num] > pyramid[i][index_num + 1]) {
            index_num = index_num + 1;
        }
        else {
            index_num = index_num;
        }
    }
    std::cout << sm << std::endl;
    for (int i = 0; i < path.size(); i++) {
        std::cout << path[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
