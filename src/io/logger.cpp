/**
 ******************************************************************************
 * @file    logger.cpp
 * @author  Maxim <aveter@bk.ru>
 * @date    04/06/2019
 * @brief   The implementation of the class "Logger".
 ******************************************************************************
 */



#include "logger.hpp"


/**
 * Anonymous namespace to hide.
 */
namespace {

/**
 * @brief Сoncatenation of commands in one line of the result.
 * @param text_results [in] - array of commands.
 * @return Result line, single line commands.
 */
std::string concat_results(const std::vector<std::string> &text_results)
{
  std::string string_result = "";
  for (auto it = text_results.begin(); it != text_results.end(); ++it) {
    if (it != text_results.begin()) {
      string_result.append(", ");
    }
    string_result.append(*it);
  }
  return string_result;
}

} /* anonymous namespace */


/* ------------------------------------------------------------------------- */
void jjd::logger::write_to_file(const std::vector<std::string> &text_results)
{
  log_file_ << concat_results(text_results) << '\n';
  log_file_.flush();
}

/* ------------------------------------------------------------------------- */
void jjd::logger::display_output(const std::vector<std::string> &text_results)
{
  console_ << "bulk: " << concat_results(text_results) << '\n';
  console_.flush();
}
