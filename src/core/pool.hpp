/**
 ******************************************************************************
 * @file    pool.hpp
 * @author  Maxim <aveter@bk.ru>
 * @date    09/06/2019
 * @brief   Discription of the class "Pool".
 *
 *
 * Class description "Pool". This class is intended for storing commands and
 * their further reset to the console or to a file.
 ******************************************************************************
 */


#ifndef JJD_POOL_H_
#define JJD_POOL_H_


#include <chrono>
#include <vector>
#include <string>
#include <utility>


/**
 * The namespace of the LibJJD
 */
namespace jjd {

/**
 *
 */
template<typename T, size_t SIZE = 5>
class pool
{
    using first_command_time_t =
                            std::chrono::time_point<std::chrono::system_clock>;
  public:
    pool() {
      set_pool_size(SIZE);
    };

    virtual ~pool() = default;

    void add(const T &&command) {
      if (size() == 0)
        first_command_time_ = std::chrono::system_clock::now();

      pool_.push_back(std::move(command));
    }

    size_t size() const {
      return pool_.size();
    }

    first_command_time_t get_first_command_time() const {
      return first_command_time_;
    }

    void set_pool_size(size_t size) noexcept {
      pool_.reserve(size);
    }

    const std::vector<T> get_pool() const {
      return pool_;
    }

    void clear() {
      pool_.clear();
    }


  private:
    std::vector<T> pool_;
    first_command_time_t first_command_time_;
};

} /* namespace jjd */

#endif /* JJD_POOL_H_ */
