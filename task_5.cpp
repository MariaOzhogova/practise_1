// сначала ищем границы фигуры. нам нужно найти 4 типа границ:
// min_row – самая верхняя строка с фигурой
// max_row – самая нижняя строка
// min_col – самый левый столбец
// max_col – самый правый столбец
// далее мы строим фигуру, стороны которой должны быть снаружи фигуры,
// а не внутри, причём между ними должен быть промежуток, поэтому
// для левого верхнего угла вычитаем едицину (min_row и min_col),
// а для правого нижнего прибавляем. 
#include <iostream>
#include <vector>
#include <algorithm>
int main() {
    int h = 0;
    int w = 0;
    std::cin >> h >> w;
    int min_row = h;
    int max_row = -1;
    int min_col = w;
    int max_col = -1;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            int value;
            std::cin >> value;
            if (value == 1) {
                min_row = std::min(min_row, i);
                max_row = std::max(max_row, i);
                min_col = std::min(min_col, j);
                max_col = std::max(max_col, j);
            }
        }
    }
    int top_left_row = min_row - 1;
    int top_left_col = min_col - 1;
    int bottom_right_row = max_row + 1;
    int bottom_right_col = max_col + 1;
    std::cout << top_left_row << " " << top_left_col << " " << bottom_right_row << " " << bottom_right_col << std::endl;
    return 0;
}