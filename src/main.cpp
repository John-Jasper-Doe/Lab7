/**
 ******************************************************************************
 * @file    main.cpp
 * @author  Maxim <aveter@bk.ru>
 * @date    03/06/2019
 * @brief   The main project file is "Bulk".
 ******************************************************************************
 */


#include "io/reader.hpp"
#include "core/controller.hpp"

#include <iostream>
#include <memory>


/**
 * @brief Main function / entry point.
 */
int main(int argc, char *argv[])
{
  if (argc < 2) {
    std::cerr << "Use:\n  " << argv[0] << " <count_commands>\n";
    return EXIT_FAILURE;
  }

  std::shared_ptr<jjd::reader> reader =
      std::make_unique<jjd::reader>(std::cin);

  std::shared_ptr<jjd::controller> sptr_controller(new jjd::controller());
  std::weak_ptr<jjd::controller> wptr_controller(sptr_controller);

  reader.get()->attach(wptr_controller);

  sptr_controller.get()->set_commands_per_block(std::stoul(argv[1]));
  sptr_controller.get()->set_reader(reader);
  sptr_controller.get()->start();

  reader.get()->unfasten(wptr_controller);

  return EXIT_SUCCESS;
}

