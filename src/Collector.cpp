#include "cpp11/list.hpp"

#include "Collector.h"
#include "LocaleInfo.h"
#include "QiParsers.h"
#include "utils.h"

CollectorPtr Collector::create(const cpp11::list& spec, LocaleInfo* pLocale) {
  std::string subclass(cpp11::as_cpp<cpp11::strings>(spec.attr("class"))[0]);

	
  if (subclass == "collector_double") {
    return CollectorPtr(new CollectorDouble(pLocale->decimalMark_));
  }
  if (subclass == "collector_character") {
    return CollectorPtr(new CollectorCharacter(&pLocale->encoder_));
  }

  cpp11::stop("Unsupported column type '%s'", subclass.c_str());
  return CollectorPtr(new CollectorSkip());
}

std::vector<CollectorPtr>
collectorsCreate(const cpp11::list& specs, LocaleInfo* pLocale) {
  std::vector<CollectorPtr> collectors;
  for (auto spec : specs) {
    CollectorPtr col(Collector::create(SEXP(spec), pLocale));
    collectors.push_back(col);
  }

  return collectors;
}

// Implementations ------------------------------------------------------------

void CollectorCharacter::setValue(int i, const Token& t) {
  switch (t.type()) {
  case TOKEN_STRING: {
    std::string buffer;
    SourceIterators string = t.getString(&buffer);

    if (t.hasNull()) {
      warn(t.row(), t.col(), "", "embedded null");
    }

    SET_STRING_ELT(
        column_,
        i,
        pEncoder_->makeSEXP(string.first, string.second, t.hasNull()));
    break;
  };
  case TOKEN_MISSING:
    SET_STRING_ELT(column_, i, NA_STRING);
    break;
  case TOKEN_EMPTY:
    SET_STRING_ELT(column_, i, Rf_mkCharCE("", CE_UTF8));
    break;
  case TOKEN_EOF:
    cpp11::stop("Invalid token");
  }
}

void CollectorCharacter::setValue(int i, const std::string& s) {
  SET_STRING_ELT(column_, i, Rf_mkCharCE(s.c_str(), CE_UTF8));
}

void CollectorDouble::setValue(int i, size_t st) { REAL(column_)[i] = st; }
