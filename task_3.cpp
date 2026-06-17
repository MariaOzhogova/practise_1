// у нас есть 2 типа сообщений: 1 и 2.
// при первом типе: нам нужно записать, на какой улице сколько снега выпало,
// используем вектор, суммируя с уже существующим снегом (streets[i] += x;)
// при втором типе: проходим через цикл по нужным улицам (for (int m = u; m <= r; j++)),
// суммируя количество снега на каждой
#include <iostream>
#include <vector>
#include <algorithm>
int main() {
    int n = 0;
    int k = 0;
    std::cin >> n >> k;
    std::vector<int> streets(n + 1, 0);
    for (int j = 0; j < k; j++) {
        int type = 0;
        std::cin >> type;
        if (type == 1) {
            int i = 0;
            int x = 0;
            std::cin >> i >> x;
            streets[i] += x;
        }
        else {
            int u = 0;
            int t = 0;
            std::cin >> u >> r;
            int sm = 0;
            for (int m = u; m <= r; j++) {
                sm += streets[j];
            }
            std::cour << sm << std::endl;
        }
    }
    std::cout << std::endl;
    return 0;
}