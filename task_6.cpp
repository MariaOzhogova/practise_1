// сначала используем максимальные контроллеры типа B с модулями типа 1 (X)
// оставшиеся модули типа X объединяем с модулями типа Y, чтобы получить 
// все доступные модули для контроллера типа A, и используем их.
// если количество контроллеров А меньше, чем количество доступных модулей,
// то используем все контроллеры типа А, если больше, то
// используем столько контроллеров типа А, сколько доступно.
#include <iostream>
#include <vector>
#include <string>
int main() {
    int n = 0;
    std::cin >> n;
    while (n--) {
        int a = 0, b = 0, x = 0, y = 0;
        std::cin >> a >> b >> x >> y;
        int result = 0;
        int bX = 0;
        if (b < x) {
            bX = b;
            result += b;
        }
        else {
            bX = x;
            result += x;
        }
        int forAY = x - bX + y;
        int aY = 0;
        if (a < forAY) {
            result += a;
        }
        else {
            result += forAY;
        }
        std::cout << result << " ";
    }
    std::cout << std::endl;
    return 0;
}