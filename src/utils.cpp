#include "utils.h"
#include <fstream>

void saveToCSV(const std::string& filename, const std::vector<State>& data) {
  std::ofstream file(filename);
  file << "x,y,vx,vy\n";
  for (auto& s: data)
    file << s.position.x << "," << s.position.y << "," << s.velocity.x << "," << s.velocity.y << "\n";
  file.close();
}
