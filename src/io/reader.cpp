/**
 ******************************************************************************
 * @file    reader.cpp
 * @author  Maxim <aveter@bk.ru>
 * @date    07/06/2019
 * @brief   The implementation of the class "Reader".
 ******************************************************************************
 */


#include "reader.hpp"
#include <iostream>


/* ------------------------------------------------------------------------- */
void jjd::reader::read_cycle()
{
  std::string tmp_str = "";
  while (std::getline(input_stream_, tmp_str))
    notify(tmp_str);
}
