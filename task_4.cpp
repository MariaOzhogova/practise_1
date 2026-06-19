// идея: чтобы расшифровать слово после k применений перестановки, нужно 
// применить обратную перестановку k раз. Если мы делаем это вручную, 
// то берём зашифрованное слово и повторяем k раз это:
// "на позицию i ставится буква с позиции обратная[i]". Но для оптимизации мы 
// делаем это не по шагам, а сразу вычисляем, куда сдвинутся буквы внутри
// каждого цикла, и получаем результат за один проход.
#include <iostream>
#include <vector>
#include <string>
int main() {
    int n;
    int k;
    std::cin >> n >> k;
    std::vector<int> permutation(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> permutation[i];
        --permutation[i];
    }
    std::string cipher;
    std::cin >> cipher;
    std::vector<int> reverse(n);
    for (int i = 0; i < n; ++i) {
        reverse[permutation[i]] = i;
    }
    std::vector<bool> used(n, false);
    std::string original(n, ' ');
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            std::vector<int> cycle;
            int cur = i;
            while (!used[cur]) {
                used[cur] = true;
                cycle.push_back(cur);
                cur = reverse[cur];
            }
            int len = cycle.size();
            int shift = k % len;
            for (int j = 0; j < len; ++j) {
                original[cycle[j]] = cipher[cycle[(j + shift) % len]];
            }
        }
    }
    std::cout << original << std::endl;
    return 0;
}