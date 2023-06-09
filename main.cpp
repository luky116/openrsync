#include "openrsync/openrsync.h"
#include <string>
#include <vector>

int main(int argc, const char **argv) {
  std::vector<std::string> args(argc);
  for (int i = 1; i < argc; ++i) {
    args[i] = argv[i];
  }
  openrsync::RSync rsync(std::move(args));
  rsync.Execute();
}