#include <string>
#include <vector>

namespace openrsync {
class RSync {
public:
  RSync() = delete;
  RSync(RSync &rsync) = delete;
  RSync(RSync &&rsync) = delete;
  RSync(const std::vector<std::string> &&args);
  ~RSync();
  int Execute();

private:
  int argc;
  char **argv;
  std::vector<std::string> args;
};
} // namespace openrsync
