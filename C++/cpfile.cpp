#include <fstream>

int main(void) {
  std::ifstream input("input.txt");
  std::ofstream output("output.txt"), output2("output2.txt");

  output << input << "\n";
  output2 << input.rdbuf();
  return 0;
}
