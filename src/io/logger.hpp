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

/**
 * The namespace of the LibJJD
 */
namespace jjd {

/**
 * Logger for print bulk in file
 */
class logger
{
    using time_point_t = std::chrono::time_point<std::chrono::system_clock>;

  public:
    explicit logger(std::ostream &ostream) : ostream_(ostream) {}
    virtual ~logger() = default;

    void write_to_file(const time_point_t &time_point,
                       const std::vector<std::string> &text_results);

    void display_output(const std::vector<std::string> &text_results);


  private:
    std::ostream &ostream_;
};

} /* namespace jjd */

#endif /* JJD_LOGGER_H_ */