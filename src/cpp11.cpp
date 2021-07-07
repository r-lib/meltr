// Generated by cpp11: do not edit by hand
// clang-format off


#include "cpp11/declarations.hpp"

// CollectorGuess.cpp
std::string collectorGuess(const cpp11::strings& input, const cpp11::list& locale_, bool guessInteger);
extern "C" SEXP _meltr_collectorGuess(SEXP input, SEXP locale_, SEXP guessInteger) {
  BEGIN_CPP11
    return cpp11::as_sexp(collectorGuess(cpp11::as_cpp<cpp11::decay_t<const cpp11::strings&>>(input), cpp11::as_cpp<cpp11::decay_t<const cpp11::list&>>(locale_), cpp11::as_cpp<cpp11::decay_t<bool>>(guessInteger)));
  END_CPP11
}
// connection.cpp
std::string read_connection_(const cpp11::sexp& con, std::string filename, int chunk_size);
extern "C" SEXP _meltr_read_connection_(SEXP con, SEXP filename, SEXP chunk_size) {
  BEGIN_CPP11
    return cpp11::as_sexp(read_connection_(cpp11::as_cpp<cpp11::decay_t<const cpp11::sexp&>>(con), cpp11::as_cpp<cpp11::decay_t<std::string>>(filename), cpp11::as_cpp<cpp11::decay_t<int>>(chunk_size)));
  END_CPP11
}
// read.cpp
cpp11::strings read_file_(const cpp11::list& sourceSpec, const cpp11::list& locale_);
extern "C" SEXP _meltr_read_file_(SEXP sourceSpec, SEXP locale_) {
  BEGIN_CPP11
    return cpp11::as_sexp(read_file_(cpp11::as_cpp<cpp11::decay_t<const cpp11::list&>>(sourceSpec), cpp11::as_cpp<cpp11::decay_t<const cpp11::list&>>(locale_)));
  END_CPP11
}
// read.cpp
cpp11::raws read_file_raw_(const cpp11::list& sourceSpec);
extern "C" SEXP _meltr_read_file_raw_(SEXP sourceSpec) {
  BEGIN_CPP11
    return cpp11::as_sexp(read_file_raw_(cpp11::as_cpp<cpp11::decay_t<const cpp11::list&>>(sourceSpec)));
  END_CPP11
}
// read.cpp
cpp11::writable::strings read_lines_(const cpp11::list& sourceSpec, const cpp11::list& locale_, std::vector<std::string> na, int n_max, bool skip_empty_rows, bool progress);
extern "C" SEXP _meltr_read_lines_(SEXP sourceSpec, SEXP locale_, SEXP na, SEXP n_max, SEXP skip_empty_rows, SEXP progress) {
  BEGIN_CPP11
    return cpp11::as_sexp(read_lines_(cpp11::as_cpp<cpp11::decay_t<const cpp11::list&>>(sourceSpec), cpp11::as_cpp<cpp11::decay_t<const cpp11::list&>>(locale_), cpp11::as_cpp<cpp11::decay_t<std::vector<std::string>>>(na), cpp11::as_cpp<cpp11::decay_t<int>>(n_max), cpp11::as_cpp<cpp11::decay_t<bool>>(skip_empty_rows), cpp11::as_cpp<cpp11::decay_t<bool>>(progress)));
  END_CPP11
}
// read.cpp
void read_lines_chunked_(const cpp11::list& sourceSpec, const cpp11::list& locale_, std::vector<std::string> na, int chunkSize, const cpp11::environment& callback, bool skip_empty_rows, bool progress);
extern "C" SEXP _meltr_read_lines_chunked_(SEXP sourceSpec, SEXP locale_, SEXP na, SEXP chunkSize, SEXP callback, SEXP skip_empty_rows, SEXP progress) {
  BEGIN_CPP11
    read_lines_chunked_(cpp11::as_cpp<cpp11::decay_t<const cpp11::list&>>(sourceSpec), cpp11::as_cpp<cpp11::decay_t<const cpp11::list&>>(locale_), cpp11::as_cpp<cpp11::decay_t<std::vector<std::string>>>(na), cpp11::as_cpp<cpp11::decay_t<int>>(chunkSize), cpp11::as_cpp<cpp11::decay_t<const cpp11::environment&>>(callback), cpp11::as_cpp<cpp11::decay_t<bool>>(skip_empty_rows), cpp11::as_cpp<cpp11::decay_t<bool>>(progress));
    return R_NilValue;
  END_CPP11
}
// read.cpp
cpp11::list read_lines_raw_(const cpp11::list& sourceSpec, int n_max, bool progress);
extern "C" SEXP _meltr_read_lines_raw_(SEXP sourceSpec, SEXP n_max, SEXP progress) {
  BEGIN_CPP11
    return cpp11::as_sexp(read_lines_raw_(cpp11::as_cpp<cpp11::decay_t<const cpp11::list&>>(sourceSpec), cpp11::as_cpp<cpp11::decay_t<int>>(n_max), cpp11::as_cpp<cpp11::decay_t<bool>>(progress)));
  END_CPP11
}
// read.cpp
void read_lines_raw_chunked_(const cpp11::list& sourceSpec, int chunkSize, const cpp11::environment& callback, bool progress);
extern "C" SEXP _meltr_read_lines_raw_chunked_(SEXP sourceSpec, SEXP chunkSize, SEXP callback, SEXP progress) {
  BEGIN_CPP11
    read_lines_raw_chunked_(cpp11::as_cpp<cpp11::decay_t<const cpp11::list&>>(sourceSpec), cpp11::as_cpp<cpp11::decay_t<int>>(chunkSize), cpp11::as_cpp<cpp11::decay_t<const cpp11::environment&>>(callback), cpp11::as_cpp<cpp11::decay_t<bool>>(progress));
    return R_NilValue;
  END_CPP11
}
// read.cpp
cpp11::sexp read_tokens_(const cpp11::list& sourceSpec, const cpp11::list& tokenizerSpec, const cpp11::list& colSpecs, const cpp11::strings& colNames, const cpp11::list& locale_, int n_max, bool progress);
extern "C" SEXP _meltr_read_tokens_(SEXP sourceSpec, SEXP tokenizerSpec, SEXP colSpecs, SEXP colNames, SEXP locale_, SEXP n_max, SEXP progress) {
  BEGIN_CPP11
    return cpp11::as_sexp(read_tokens_(cpp11::as_cpp<cpp11::decay_t<const cpp11::list&>>(sourceSpec), cpp11::as_cpp<cpp11::decay_t<const cpp11::list&>>(tokenizerSpec), cpp11::as_cpp<cpp11::decay_t<const cpp11::list&>>(colSpecs), cpp11::as_cpp<cpp11::decay_t<const cpp11::strings&>>(colNames), cpp11::as_cpp<cpp11::decay_t<const cpp11::list&>>(locale_), cpp11::as_cpp<cpp11::decay_t<int>>(n_max), cpp11::as_cpp<cpp11::decay_t<bool>>(progress)));
  END_CPP11
}
// read.cpp
void read_tokens_chunked_(const cpp11::list& sourceSpec, const cpp11::environment& callback, int chunkSize, const cpp11::list& tokenizerSpec, const cpp11::list& colSpecs, const cpp11::strings& colNames, const cpp11::list& locale_, const cpp11::sexp& spec, bool progress);
extern "C" SEXP _meltr_read_tokens_chunked_(SEXP sourceSpec, SEXP callback, SEXP chunkSize, SEXP tokenizerSpec, SEXP colSpecs, SEXP colNames, SEXP locale_, SEXP spec, SEXP progress) {
  BEGIN_CPP11
    read_tokens_chunked_(cpp11::as_cpp<cpp11::decay_t<const cpp11::list&>>(sourceSpec), cpp11::as_cpp<cpp11::decay_t<const cpp11::environment&>>(callback), cpp11::as_cpp<cpp11::decay_t<int>>(chunkSize), cpp11::as_cpp<cpp11::decay_t<const cpp11::list&>>(tokenizerSpec), cpp11::as_cpp<cpp11::decay_t<const cpp11::list&>>(colSpecs), cpp11::as_cpp<cpp11::decay_t<const cpp11::strings&>>(colNames), cpp11::as_cpp<cpp11::decay_t<const cpp11::list&>>(locale_), cpp11::as_cpp<cpp11::decay_t<const cpp11::sexp&>>(spec), cpp11::as_cpp<cpp11::decay_t<bool>>(progress));
    return R_NilValue;
  END_CPP11
}
// read.cpp
cpp11::sexp melt_tokens_(const cpp11::list& sourceSpec, const cpp11::list& tokenizerSpec, const cpp11::list& colSpecs, const cpp11::list& locale_, int n_max, bool progress);
extern "C" SEXP _meltr_melt_tokens_(SEXP sourceSpec, SEXP tokenizerSpec, SEXP colSpecs, SEXP locale_, SEXP n_max, SEXP progress) {
  BEGIN_CPP11
    return cpp11::as_sexp(melt_tokens_(cpp11::as_cpp<cpp11::decay_t<const cpp11::list&>>(sourceSpec), cpp11::as_cpp<cpp11::decay_t<const cpp11::list&>>(tokenizerSpec), cpp11::as_cpp<cpp11::decay_t<const cpp11::list&>>(colSpecs), cpp11::as_cpp<cpp11::decay_t<const cpp11::list&>>(locale_), cpp11::as_cpp<cpp11::decay_t<int>>(n_max), cpp11::as_cpp<cpp11::decay_t<bool>>(progress)));
  END_CPP11
}
// read.cpp
void melt_tokens_chunked_(const cpp11::list& sourceSpec, const cpp11::environment& callback, int chunkSize, const cpp11::list& tokenizerSpec, const cpp11::list& colSpecs, const cpp11::list& locale_, bool progress);
extern "C" SEXP _meltr_melt_tokens_chunked_(SEXP sourceSpec, SEXP callback, SEXP chunkSize, SEXP tokenizerSpec, SEXP colSpecs, SEXP locale_, SEXP progress) {
  BEGIN_CPP11
    melt_tokens_chunked_(cpp11::as_cpp<cpp11::decay_t<const cpp11::list&>>(sourceSpec), cpp11::as_cpp<cpp11::decay_t<const cpp11::environment&>>(callback), cpp11::as_cpp<cpp11::decay_t<int>>(chunkSize), cpp11::as_cpp<cpp11::decay_t<const cpp11::list&>>(tokenizerSpec), cpp11::as_cpp<cpp11::decay_t<const cpp11::list&>>(colSpecs), cpp11::as_cpp<cpp11::decay_t<const cpp11::list&>>(locale_), cpp11::as_cpp<cpp11::decay_t<bool>>(progress));
    return R_NilValue;
  END_CPP11
}
// read.cpp
std::vector<std::string> guess_types_(const cpp11::list& sourceSpec, const cpp11::list& tokenizerSpec, const cpp11::list& locale_, int n);
extern "C" SEXP _meltr_guess_types_(SEXP sourceSpec, SEXP tokenizerSpec, SEXP locale_, SEXP n) {
  BEGIN_CPP11
    return cpp11::as_sexp(guess_types_(cpp11::as_cpp<cpp11::decay_t<const cpp11::list&>>(sourceSpec), cpp11::as_cpp<cpp11::decay_t<const cpp11::list&>>(tokenizerSpec), cpp11::as_cpp<cpp11::decay_t<const cpp11::list&>>(locale_), cpp11::as_cpp<cpp11::decay_t<int>>(n)));
  END_CPP11
}
// TokenizerFwf.cpp
cpp11::list whitespaceColumns(const cpp11::list& sourceSpec, int n, std::string comment);
extern "C" SEXP _meltr_whitespaceColumns(SEXP sourceSpec, SEXP n, SEXP comment) {
  BEGIN_CPP11
    return cpp11::as_sexp(whitespaceColumns(cpp11::as_cpp<cpp11::decay_t<const cpp11::list&>>(sourceSpec), cpp11::as_cpp<cpp11::decay_t<int>>(n), cpp11::as_cpp<cpp11::decay_t<std::string>>(comment)));
  END_CPP11
}

extern "C" {
/* .Call calls */
extern SEXP _meltr_collectorGuess(SEXP, SEXP, SEXP);
extern SEXP _meltr_guess_types_(SEXP, SEXP, SEXP, SEXP);
extern SEXP _meltr_melt_tokens_(SEXP, SEXP, SEXP, SEXP, SEXP, SEXP);
extern SEXP _meltr_melt_tokens_chunked_(SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP);
extern SEXP _meltr_read_connection_(SEXP, SEXP, SEXP);
extern SEXP _meltr_read_file_(SEXP, SEXP);
extern SEXP _meltr_read_file_raw_(SEXP);
extern SEXP _meltr_read_lines_(SEXP, SEXP, SEXP, SEXP, SEXP, SEXP);
extern SEXP _meltr_read_lines_chunked_(SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP);
extern SEXP _meltr_read_lines_raw_(SEXP, SEXP, SEXP);
extern SEXP _meltr_read_lines_raw_chunked_(SEXP, SEXP, SEXP, SEXP);
extern SEXP _meltr_read_tokens_(SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP);
extern SEXP _meltr_read_tokens_chunked_(SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP);
extern SEXP _meltr_whitespaceColumns(SEXP, SEXP, SEXP);

static const R_CallMethodDef CallEntries[] = {
    {"_meltr_collectorGuess",          (DL_FUNC) &_meltr_collectorGuess,          3},
    {"_meltr_guess_types_",            (DL_FUNC) &_meltr_guess_types_,            4},
    {"_meltr_melt_tokens_",            (DL_FUNC) &_meltr_melt_tokens_,            6},
    {"_meltr_melt_tokens_chunked_",    (DL_FUNC) &_meltr_melt_tokens_chunked_,    7},
    {"_meltr_read_connection_",        (DL_FUNC) &_meltr_read_connection_,        3},
    {"_meltr_read_file_",              (DL_FUNC) &_meltr_read_file_,              2},
    {"_meltr_read_file_raw_",          (DL_FUNC) &_meltr_read_file_raw_,          1},
    {"_meltr_read_lines_",             (DL_FUNC) &_meltr_read_lines_,             6},
    {"_meltr_read_lines_chunked_",     (DL_FUNC) &_meltr_read_lines_chunked_,     7},
    {"_meltr_read_lines_raw_",         (DL_FUNC) &_meltr_read_lines_raw_,         3},
    {"_meltr_read_lines_raw_chunked_", (DL_FUNC) &_meltr_read_lines_raw_chunked_, 4},
    {"_meltr_read_tokens_",            (DL_FUNC) &_meltr_read_tokens_,            7},
    {"_meltr_read_tokens_chunked_",    (DL_FUNC) &_meltr_read_tokens_chunked_,    9},
    {"_meltr_whitespaceColumns",       (DL_FUNC) &_meltr_whitespaceColumns,       3},
    {NULL, NULL, 0}
};
}

extern "C" void R_init_meltr(DllInfo* dll){
  R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
  R_useDynamicSymbols(dll, FALSE);
  R_forceSymbols(dll, TRUE);
}
