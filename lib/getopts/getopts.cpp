// ----------------------------------------------
// Created: 2024-06-25
// Last modified: 2024-06-26
// Purpose: Main file for getopts
// Creator: Yoshihiro NAKAHARA (YN)
// Dependencies: getopts.hpp
// Description: Main file for getopts
// License: MIT License
// ----------------------------------------------

#include <iostream>
#include <regex>
#include <string>
#include <vector>
#include <array>
#include "getopts.hpp"

/*
 * Constructor
 */
GetOpts::GetOpts() {}

/*
 * Destructor
 */
GetOpts::~GetOpts() {}

/*
* Get long options
* @return std::vector<std::string>
*/
std::vector<std::array<std::string, 2>> GetOpts::getLongOpts() {
  return longOpts;
}

/*
* Get short options
* @return std::vector<std::string>
*/
std::vector<std::array<std::string, 2>> GetOpts::getShortOpts() {
  return shortOpts;
}

/*
* Add long options
* @param longOpts
* @param arg
*/
 bool GetOpts::addLongOpts(std::vector<std::array<std::string, 2>> *longOpts,
                           std::array<std::string, 2> arg) {
  std::regex re("^-{2}[0-9a-zA-Z]+([-|_][0-9a-zA-Z])*");

  if (!std::regex_match(arg[0], re)) {
    std::cerr << "Invalid long option: " << arg[0] << std::endl;
    return false;
  } else {
    longOpts->push_back(arg);
  }

  return true;
}

bool GetOpts::addShortOpts(std::vector<std::array<std::string, 2>> *shortOpts,
                           std::string arg, std::string value) {
  std::regex re("^-{1}[0-9a-zA-Z]+");
  std::array<std::string, 2> opt;

  if (!std::regex_match(arg, re)) {
    std::cerr << "Invalid short option: " << arg << std::endl;
    return false;
  } else {
    if (2 < arg.length()) {
      for (int i = 1; i < arg.length(); i++) {
        opt[0] = std::string(1, arg[i]);
        if (i + 1 == arg.length()) {
          opt[1] = value;
        } else {
          opt[1] = "";
        }

        shortOpts->push_back(opt);
      }
    } else if (2 == arg.length()) {
      opt[0] = std::string(1, arg[1]);
      opt[1] = value;

      shortOpts->push_back(opt);
    } else {
      std::cerr << "Invalid short option: " << arg << std::endl;
      return false;
    }
  }

  return true;
}

/*
* Parse arguments
* @param argc
* @param argv
*/
void GetOpts::parseArgs(int argc, char *argv[]) {
  std::regex regex1("^-{2}[0-9a-zA-Z]+([-|_][0-9a-zA-Z])*?");
  std::regex regex2("^-{1}[0-9a-zA-Z]+");
  std::regex regex3("^[0-9a-zA-Z].+");

  std::array<std::string, 2> long_opts;

  for (int i = 1; i < argc; i++) {
    std::string arg = argv[i];

    if (std::regex_match(arg, regex1)) {
      long_opts[0] = argv[i];
      if (i + 1 < argc) {
        if (std::regex_match(argv[i + 1], regex3)) {
          long_opts[1] = argv[i + 1];
          i++;
        }
      }
      addLongOpts(&longOpts, long_opts);
    } else if (std::regex_match(arg, regex2)) {
      if (std::regex_match(argv[i + 1], regex3)) {
        addShortOpts(&shortOpts, arg, argv[i + 1]);
        i++;
      } else {
        addShortOpts(&shortOpts, arg, "");
      }
    } else {
      std::cerr << "Invalid option: " << arg << std::endl;
    }
  }
}
