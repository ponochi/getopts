// ----------------------------------------------
// Created: 2024-06-25
// Last modified: 2024-06-26
// Purpose: getopts.hpp file for getopts
// Creator: Yoshihiro NAKAHARA (YN)
// Dependencies:
// Description: getopts.hpp file for getopts
// License: MIT License
// ----------------------------------------------

#pragma once

#include <cstdio>
#include <string>
#include <vector>
#include <array>

class GetOpts {
public:
  GetOpts(void);
  ~GetOpts(void);

  std::vector<std::array<std::string, 2>> getLongOpts();
  std::vector<std::array<std::string, 2>> getShortOpts();

  void parseArgs(int argc, char *argv[]);

private:
  bool addLongOpts(std::vector<std::array<std::string, 2>> *longOpts,
                   std::array<std::string, 2> opts);
  bool addShortOpts(std::vector<std::array<std::string, 2>> *shortOpts,
                    std::string opt, std::string val);

  std::vector<std::array<std::string, 2>> longOpts;
  std::vector<std::array<std::string, 2>> shortOpts;
};
