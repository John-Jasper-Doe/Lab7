/**
 ******************************************************************************
 * @file    reader.hpp
 * @author  Maxim <aveter@bk.ru>
 * @date    07/06/2019
 * @brief   Discription of the class "Reader".
 *
 * Description of the class "Reader", which in the "Observer" pattern
 * implements the "Subject". The class "Reader" is inherited from the template
 * "Subject" and performs the function of receiving data from the input stream
 * and notifies all observers who are subscribed to it.
 ******************************************************************************
 */


#ifndef JJD_READER_H_
#define JJD_READER_H_


#include "../utils/subject.hpp"
#include <string>


/**
 * The namespace of the LibJJD
 */
namespace jjd {


/**
 * @brief The reader class
 */
class reader : public subject<std::string>
{
  public:
    /**
     * @brief The constructor
     * @param input_stream
     */
    explicit reader(std::istream &input_stream)
      : input_stream_{input_stream}
    {}

    /**
     * @brief Loop to read data from the input stream.
     */
    void read_cycle();

  private:
    std::istream &input_stream_;  /**< - the input stream. */
};


} /* namespace jjd */

#endif /* JJD_READER_H_ */
