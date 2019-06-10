/**
 ******************************************************************************
 * @file    subject.hpp
 * @author  Maxim <aveter@bk.ru>
 * @date    08/06/2019
 * @brief   Discription of the template class "Subject".
 *
 * Implemented "Subject" must be inherited from this class-template. When the
 * inherited "Subject" changes, it must notify all registered observers. Here
 * the basic functionality for work is implemented: registration, deletion and
 * notification of observers.
 ******************************************************************************
 */


#ifndef JJD_SUBJECT_H_
#define JJD_SUBJECT_H_


#include "observer.hpp"

#include <vector>
#include <memory>
#include <algorithm>


/**
 * The namespace of the LibJJD
 */
namespace jjd {


/**
 * @brief Template class "Subject".
 * @tparam ARGS - template input parameters.
 */
template<typename ...ARGS>
class subject
{
    /* Aliases */
    using ptr_observer_t = std::weak_ptr<observer<ARGS...>>;


  public:
    /**
     * The default constructor.
     */
    subject() = default;

    /**
     * The default distructor (virtual).
     */
    virtual ~subject() = default;

    /**
     * @brief Add the observer.
     * @param obs [in] - pointer to the observer.
     */
    void attach(ptr_observer_t obs) {
        observer_list_.push_back(std::move(obs));
    }

    /**
     * @brief Remove the observer.
     * @param obs [in] - pointer to the observer.
     */
    void unfasten(ptr_observer_t obs) {
      if (auto spt = obs.lock()) {
        auto weak_cmp = [&spt](const ptr_observer_t &o) {
          return spt == o.lock();
        };
        auto observer_find = std::find_if(observer_list_.begin(),
                                          observer_list_.end(), weak_cmp);

        observer_list_.erase(observer_find);
      }
    }

  protected:
    /**
     * @brief Notify all observers.
     * @param args [in] - arguments that are passed to observers.
     */
    void notify(const ARGS &...args) {
      for (ptr_observer_t &obs: observer_list_) {
        if (auto spt = obs.lock())
          spt->update(args...);
      }
    }


  private:
    std::vector<ptr_observer_t> observer_list_; /**< - the observer lis. */
};


} /* namespace jjd */

#endif /* JJD_SUBJECT_H_ */
