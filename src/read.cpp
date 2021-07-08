#include <utility>

#include "cpp11/environment.hpp"
#include "cpp11/function.hpp"
#include "cpp11/list.hpp"
#include "cpp11/strings.hpp"

#include "Collector.h"
#include "LocaleInfo.h"
#include "Progress.h"
#include "Reader.h"
#include "Source.h"
#include "Tokenizer.h"
#include "Warnings.h"

[[cpp11::register]] cpp11::strings
read_file_(const cpp11::list& sourceSpec, const cpp11::list& locale_) {
  SourcePtr source = Source::create(sourceSpec);
  LocaleInfo locale(locale_);

  return cpp11::writable::strings(
      locale.encoder_.makeSEXP(source->begin(), source->end()));
}

[[cpp11::register]] cpp11::raws read_file_raw_(const cpp11::list& sourceSpec) {
  SourcePtr source = Source::create(sourceSpec);

  cpp11::writable::raws res(
      static_cast<R_xlen_t>(source->end() - source->begin()));
  std::copy(source->begin(), source->end(), RAW(res));
  return SEXP(res);
}

cpp11::function
R6method(const cpp11::environment& env, const std::string& method) {
  return static_cast<SEXP>(env[method.c_str()]);
}
bool isTrue(SEXP x) {
  if (!(TYPEOF(x) == LGLSXP && Rf_length(x) == 1)) {
    cpp11::stop("`continue()` must return a length 1 logical vector");
  }
  return LOGICAL(x)[0] == TRUE;
}

typedef std::vector<CollectorPtr>::iterator CollectorItr;

[[cpp11::register]] cpp11::sexp melt_tokens_(
    const cpp11::list& sourceSpec,
    const cpp11::list& tokenizerSpec,
    const cpp11::list& colSpecs,
    const cpp11::list& locale_,
    int n_max,
    bool progress) {

  LocaleInfo l(locale_);
  Reader r(
      Source::create(sourceSpec),
      Tokenizer::create(tokenizerSpec),
      collectorsCreate(colSpecs, &l),
      progress);

  return r.meltToDataFrame(cpp11::list(locale_), n_max);
}

[[cpp11::register]] void melt_tokens_chunked_(
    const cpp11::list& sourceSpec,
    const cpp11::environment& callback,
    int chunkSize,
    const cpp11::list& tokenizerSpec,
    const cpp11::list& colSpecs,
    const cpp11::list& locale_,
    bool progress) {

  LocaleInfo l(locale_);
  Reader r(
      Source::create(sourceSpec),
      Tokenizer::create(tokenizerSpec),
      collectorsCreate(colSpecs, &l),
      progress);

  int pos = 1;
  while (isTrue(R6method(callback, "continue")())) {
    cpp11::data_frame out(
        r.meltToDataFrame(static_cast<SEXP>(locale_), chunkSize));
    if (out.nrow() == 0) {
      return;
    }
    R6method(callback, "receive")(out, pos);
    pos += out.nrow();
  }
}
