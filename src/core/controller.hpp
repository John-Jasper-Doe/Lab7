/**
 ******************************************************************************
 * @file    controller.hpp
 * @author  Maxim <aveter@bk.ru>
 * @date    09/06/2019
 * @brief   Discription of the class "Controller".
 *
 * The controller is a class "Observer". He receives a notification of a change
 * in the "Subject" and processes the information received.
 ******************************************************************************
 */


#ifndef JJD_CONTROLLER_H_
#define JJD_CONTROLLER_H_


#include "pool.hpp"
#include "../utils/observer.hpp"
#include "../io/reader.hpp"
#include "../io/logger.hpp"

#include <string>
#include <memory>


/**
 * The namespace of the LibJJD
 */
namespace jjd {

/**
 * The controller is a class "Observer".
 */
class controller final : public observer<std::string>
{
  public:

    /**
     * The default constructor.
     */
    explicit controller() = default;

    /**
     * The default distructor.
     */
    ~controller() = default;

    /**
     * @brief Update on the change in the state of the subject.
     * @param str [in] - data from subject.
     */
    void update(const std::string &str) override;

    /**
     * @brief Start the process of receiving data.
     */
    void start();

    /**
     * @brief Resetting data from the command pool.
     */
    void flush();

    /**
     * @brief Setter to install number of commands in the block.
     * @param value [in] - number.
     */
    void set_commands_per_block(size_t value) noexcept {
      commands_per_block_ = value;
      pool_.set_pool_size(value);
    }

    /**
     * @brief Setter to install the reader.
     * @param rdr [in] - pointer to the reader.
     */
    void set_reader(std::shared_ptr<jjd::reader> rdr) noexcept {
      reader_ = rdr;
    }


  private:
    unsigned depth_ = 0;            /**< - depth of nesting commands. */
    size_t commands_per_block_ = 0; /**< - the count commands per block. */

    std::unique_ptr<jjd::logger> logger_;   /**< - pointer of the logger. */
    jjd::pool<std::string> pool_;           /**< - the pool of the commands. */
    std::shared_ptr<jjd::reader> reader_;   /**< - the reader from console. */
    std::ofstream log_file_;                /**< - file for logging. */

    static bool init_logger_; /**< - switcher to initialize log-file. */
};

} /* namespace jjd */

#endif /* JJD_CONTROLLER_H_ */
