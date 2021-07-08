#include "Collector.h"
#include "Progress.h"
#include "Source.h"

#include "cpp11/list.hpp"
#include "cpp11/strings.hpp"

class Reader {
public:
  Reader(
      SourcePtr source,
      TokenizerPtr tokenizer,
      std::vector<CollectorPtr> collectors,
      bool progress,
      const cpp11::strings& colNames = cpp11::strings());

  cpp11::sexp meltToDataFrame(const cpp11::list& locale_, R_xlen_t lines = -1);

private:
  Warnings warnings_;
  SourcePtr source_;
  TokenizerPtr tokenizer_;
  std::vector<CollectorPtr> collectors_;
  bool progress_;
  Progress progressBar_;
  std::vector<int> keptColumns_;
  cpp11::writable::strings outNames_;
  bool begun_;
  Token t_;

  const static R_xlen_t progressStep_ = 10000;

  void init(const cpp11::strings& colNames);
  R_xlen_t melt(const cpp11::list& locale_, R_xlen_t lines = -1);

  void collectorsResize(R_xlen_t n);
  void collectorsClear();
};
