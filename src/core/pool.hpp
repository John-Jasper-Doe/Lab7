/**
 ******************************************************************************
 * @file    pool.hpp
 * @author  Maxim <aveter@bk.ru>
 * @date    09/06/2019
 * @brief   Discription of the class "Pool".
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
 * @brief The template class "Pool".
 * @tparam T - type data in pool.
 * @tparam SIZE - size data in pool (default = 5)
 */
template<typename T, size_t SIZE = 5>
class pool final
{
    /* Aliases */
    using first_command_time_t =
                            std::chrono::time_point<std::chrono::system_clock>;


  public:
    /**
     * The constructor.
     */
    pool() {
      set_pool_size(SIZE);
    };

    /**
     * The default distructor.
     */
    ~pool() = default;

    /**
     * @brief Adding a command to the pool.
     * @param command [in] - the command.
     */
    void add(const T &&command) {
      if (size() == 0)
        first_command_time_ = std::chrono::system_clock::now();

      pool_.push_back(std::move(command));
    }

    /**
     * @brief Number of the commands in the pool.
     * @return Pool size.
     */
    size_t size() const {
      return pool_.size();
    }

    /**
     * @brief Gte first command time.
     * @return First command time.
     */
    first_command_time_t get_first_command_time() const {
      return first_command_time_;
    }

    /**
     * @brief Set pool size.
     * @param size [in] - pool size.
     */
    void set_pool_size(size_t size) noexcept {
      pool_.reserve(size);
    }

    /**
     * @brief Get the pool of the commands.
     * @return Reference to the pool of the commands.
     */
    const std::vector<T>& get_pool() const {
      return pool_;
    }

    /**
     * @brief Clear the pool.
     */
    void clear() {
      pool_.clear();
    }


  private:
    std::vector<T> pool_;                 /**< - the pool of the commands. */
    first_command_time_t first_command_time_; /**< - the first command time */
};

} /* namespace jjd */

#endif /* JJD_POOL_H_ */
