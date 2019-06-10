/**
 ******************************************************************************
 * @file    obsorver.hpp
 * @author  Maxim <aveter@bk.ru>
 * @date    08/06/2019
 * @brief   Discription of the template class "Obsorver".
 *
 * The base class of the "Observer" object template. It provides basic
 * functionality to all inherited objects. All observers must inherit from it.
 ******************************************************************************
 */


#ifndef JJD_OBSORVER_H_
#define JJD_OBSORVER_H_


/**
 * The namespace of the LibJJD
 */
namespace jjd {


/**
 * @brief Template class "Observer".
 * @tparam ARGS - template input parameters.
 */
template<typename ...ARGS>
class observer
{
  public:
    /**
     * The default constructor.
     */
    observer() = default;

    /**
     * The default distructor.
     */
    virtual ~observer() = default;

    /**
     * @brief update all observer.
     */
    virtual void update(const ARGS &...) = 0;
};


} /* namespace jjd */

#endif /* JJD_OBSORVER_H_ */
