// Copy input file to output file
#include <fstream>

int main(void) {
  std::ifstream input("input.txt");
  std::ofstream output("output.txt");

  output << input.rdbuf() << "\n";
  return 0;
}
