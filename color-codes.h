//
// Created by hey-t on 6/19/2023.
//

#ifndef BAD_SORTS_COLOR_CODES_H
#define BAD_SORTS_COLOR_CODES_H

#include <string>

namespace colorcodes {
  namespace textFormats {
    const std::string clear     {"\x1b[0m"};
    const std::string bold      {"\x1b[1m"};
    const std::string resetBold {"\x1b[22m"};
    const std::string dim       {"\x1b[2m"};
    const std::string resetDim  {"\x1b[22m"};
  }
  namespace textColors {
    const std::string black     {"\x1b[30m"};
    const std::string red       {"\x1b[31m"};
    const std::string green     {"\x1b[32m"};
    const std::string yellow    {"\x1b[33m"};
    const std::string blue      {"\x1b[34m"};
    const std::string magenta   {"\x1b[35m"};
    const std::string cyan      {"\x1b[36m"};
    const std::string white     {"\x1b[37m"};
    const std::string default_  {"\x1b[39m"};
    const std::string clear     {"\x1b[0m"};
  }
  namespace highlightColors {
    const std::string black     {"\x1b[40m"};
    const std::string red       {"\x1b[41m"};
    const std::string green     {"\x1b[42m"};
    const std::string yellow    {"\x1b[43m"};
    const std::string blue      {"\x1b[44m"};
    const std::string magenta   {"\x1b[45m"};
    const std::string cyan      {"\x1b[46m"};
    const std::string white     {"\x1b[47m"};
    const std::string default_  {"\x1b[49m"};
    const std::string clear     {"\x1b[0m"};
  }
}

#endif //BAD_SORTS_COLOR_CODES_H
