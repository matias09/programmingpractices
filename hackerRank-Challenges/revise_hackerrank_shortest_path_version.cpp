#include <iostream>
#include <vector>
//#include <limits>

int rows;
int colums;

int obj_row;
int obj_col;

// const int MAX_VALUE = std::numeric_limits<unsigned int>::max();

int SetMapPositionWeight(
    const std::vector<std::vector<bool>> &map,
    std::vector<std::vector<unsigned int>> &map_positions_weight, int idx_row,
    int idx_col) {
  int v = 0;

  std::cout << " idx_row = " << idx_row << " idx_col = " << idx_col << '\n';

  if (idx_row == obj_row && idx_col == obj_col) {
    std::cout << " Destination founded, returns 1 \n";
    return 1;
  }

  if (idx_row == rows || idx_col == colums || map[idx_row][idx_col] == 0)
    return 0;

  if (map_positions_weight[idx_row][idx_col] != 0) {
    std::cout << " map_positions_weight[" << idx_row << "][" << idx_col
              << "] \n";
    return map_positions_weight[idx_row][idx_col];
  } else {
    v = SetMapPositionWeight(map, map_positions_weight, idx_row + 1, idx_col) +
        SetMapPositionWeight(map, map_positions_weight, idx_row, idx_col + 1);

    std::cout << " v = " << v << '\n';
    map_positions_weight[idx_row][idx_col] = v;
  }

  return v;
}

int main() {
  const std::vector<std::vector<bool>> map = {
      {1, 1, 1, 1, 1},
      {1, 0, 0, 0, 1},
      {1, 0, 1, 1, 1},
      {1, 1, 1, 1, 1},
  };

  std::vector<std::vector<unsigned int>> map_positions_weight = {
      {0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0},
  };

  rows = map.size();
  colums = map[0].size();

  obj_row = rows - 1;
  obj_col = colums - 1;

  SetMapPositionWeight(map, map_positions_weight, 0, 0);

  std::cout << " Current Map : \n"
            << " rows : " << rows << " col  : " << colums << '\n';
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < colums; ++j) {
      if (i == obj_row && j == obj_col) {
        std::cout << "$" << ' ';
      } else {
        std::cout << map[i][j] << ' ';
      }
    }

    std::cout << '\n';
  }

  std::cout << "\n Current Weights on Map : \n";
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < colums; ++j)
      std::cout << map_positions_weight[i][j] << ' ';

    std::cout << '\n';
  }

  return 0;
}
