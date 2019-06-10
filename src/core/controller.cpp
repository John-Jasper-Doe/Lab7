/**
 ******************************************************************************
 * @file    controller.cpp
 * @author  Maxim <aveter@bk.ru>
 * @date    09/06/2019
 * @brief   The implementation of the class "Controller".
 ******************************************************************************
 */


#include "controller.hpp"

#include <stdexcept>
#include <fstream>
#include <iostream>


bool jjd::controller::init_logger_ = false;

/* ------------------------------------------------------------------------- */
void jjd::controller::update(const std::string &str)
{
  if (str == "{") {
    if (depth_ == 0) {
      flush();
      ++depth_;
    }
    else
      ++depth_;
  }
  else if (str == "}") {
    if (depth_ == 0)
      throw std::runtime_error("invalid closed block without opened ones");
    else {
      --depth_;

      if (depth_ == 0)
        flush();
    }
  }
  else {
    pool_.add(std::move(str));

    if (depth_ == 0 && pool_.size() == commands_per_block_)
      flush();
  }
}

/* ------------------------------------------------------------------------- */
void jjd::controller::start()
{
  if (reader_.get() != nullptr) {
    reader_.get()->read_cycle();
  }
}

/* ------------------------------------------------------------------------- */
void jjd::controller::flush()
{
  if (!init_logger_) {
    auto first_command_time =
                     pool_.get_first_command_time().time_since_epoch().count();
    std::string path = std::to_string(first_command_time) + ".log";

    log_file_.open(path);
    if (log_file_.is_open()) {
      logger_ = std::make_unique<jjd::logger>(std::cout, log_file_);
      init_logger_ = true;
    }
  }

  logger_.get()->write_to_file(pool_.get_pool());
  logger_.get()->display_output(pool_.get_pool());

  pool_.clear();
}
