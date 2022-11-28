#ifndef E06__FILECONTENT_H_
#define E06__FILECONTENT_H_

#include <string>
#include "Content.h"

class FileContent : public Content {
 private:
  std::string file_path;
 public:
  void read() override;
  void del() override;
  explicit FileContent(std::string file_path);
};

#endif //E06__FILECONTENT_H_
