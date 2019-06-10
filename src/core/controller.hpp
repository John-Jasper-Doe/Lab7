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


    void update(const std::string &str) override;
    void start();
    void flush();

    void set_commands_per_block(size_t value) noexcept {
      commands_per_block_ = value;
      pool_.set_pool_size(value);
    }

    void set_reader(std::shared_ptr<jjd::reader> rdr) noexcept {
      reader_ = rdr;
    }


  private:
    unsigned depth_ = 0;
    size_t commands_per_block_ = 0;

    std::unique_ptr<jjd::logger> logger_;
    jjd::pool<std::string> pool_;
    std::shared_ptr<jjd::reader> reader_;
    std::ofstream log_file_;

    static bool init_logger_;
};

} /* namespace jjd */

#endif /* JJD_CONTROLLER_H_ */
