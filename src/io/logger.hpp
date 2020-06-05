/**
 ******************************************************************************
 * @file    logger.hpp
 * @author  Maxim <aveter@bk.ru>
 * @date    04/06/2019
 * @brief   Discription of the class "Logger".
 *
 * During initialization, the file "bulk<time_first_event>.log" is created
 * which will be located next to the binary. It is required for registering
 * blocks of commands.
 ******************************************************************************
 */


#ifndef JJD_LOGGER_H_
#define JJD_LOGGER_H_


#include <chrono>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

/**
 * The namespace of the LibJJD
 */
namespace jjd {

/**
 * Logger for print bulk in file and console.
 */
class logger
{
    using time_point_t = std::chrono::time_point<std::chrono::system_clock>;

  public:
    /**
     * @brief The construcor.
     * @param ostream [in] - ref on console.
     * @param log_file [in] - ref on log file.
     */
    explicit logger(std::ostream &ostream, std::ofstream &log_file)
      : console_(ostream)
      , log_file_(log_file)
    {}

    /**
     * The default distructor.
     */
    virtual ~logger() = default;

    /**
     * @brief Write the data to log-file.
     * @param text_results [in] - array of command.
     */
    void write_to_file(const std::vector<std::string> &text_results);

    /**
     * @brief Display data on the console.
     * @param text_results [in] - array of commsnd.
     */
    void display_output(const std::vector<std::string> &text_results);


  private:
    std::ostream &console_;   /**< - ref. on the console. */
    std::ofstream &log_file_; /**< - ref. on the log-file. */
};

} /* namespace jjd */

#endif /* JJD_LOGGER_H_ */
