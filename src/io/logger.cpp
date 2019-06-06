/**
 ******************************************************************************
 * @file    logger.cpp
 * @author  Maxim <aveter@bk.ru>
 * @date    04/06/2019
 * @brief   The implementation of the class "Logger".
 ******************************************************************************
 */



#include "logger.hpp"

#include <fstream>

/**
 * Anonymous namespace to hide.
 */
namespace {

/**
 * @brief concat_results
 * @param text_results
 * @return
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
void jjd::logger::write_to_file(const jjd::logger::time_point_t &time_point,
                                const std::vector<std::string> &text_results)
{
  std::string path = std::to_string(time_point.time_since_epoch().count()) +
                     ".log";

  std::ofstream log_file(path);
  if (log_file.is_open())
    log_file << concat_results(text_results) << '\n';
}

/* ------------------------------------------------------------------------- */
void jjd::logger::display_output(const std::vector<std::string> &text_results)
{
  ostream_ << "bulk: " << concat_results(text_results) << '\n';
}
