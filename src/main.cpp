/**
 ******************************************************************************
 * @file    main.cpp
 * @author  Maxim <aveter@bk.ru>
 * @date    03/06/2019
 * @brief   The main project file is "Bulk".
 ******************************************************************************
 */


#include <iostream>


/**
 * @brief Main function / entry point.
 */
int main(int argc, char *argv[])
{
  if (argc < 2) {
    std::cerr << "Use:\n  " << argv[0] << " <count_commands>\n";
    return EXIT_FAILURE;
  }

  size_t commands_per_block = std::stoul(argv[1]);


  (void)commands_per_block;
  return EXIT_SUCCESS;
}

