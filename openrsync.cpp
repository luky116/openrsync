extern "C" {
#include "externc.h"
}
#include "openrsync/openrsync.h"

namespace openrsync {
RSync::RSync(const std::vector<std::string> &&args)
    : argc(args.size()), args(std::move(args)) {
  argv = new char *[argc];
}

RSync::~RSync() { delete[] argv; }

// 这个就是实际的执行函数,执行主函数
int RSync::Execute() {
  for (size_t i = 0; i < argc; i++) {
    argv[i] = const_cast<char *>(args[i].c_str());
  }
  return execute(argc, argv);
}
} // namespace openrsync
