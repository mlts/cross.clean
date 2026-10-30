/* ************************************************************************** */
/*                                                                            */
/*                                                            +#              */
/*    title_policy.cpp                                      +##               */
/*                                                         +###+              */
/*    By: lucas <lucas@tsiaraso.com>                     +########+           */
/*                                                           +###+            */
/*    Created: 2026/10/30 09:26:00 by lucas                  ##+              */
/*    Updated: 2026/10/30 09:26:00 by lucas                 #+                */
/*                                                                            */
/* ************************************************************************** */

#include "title_policy.hpp"

#include <stdexcept>

namespace todo {

std::string normalize_title(std::string title) {
  constexpr auto whitespace = " \t\n\r";
  const auto first = title.find_first_not_of(whitespace);
  if (first == std::string::npos) {
    throw std::invalid_argument("todo title must not be blank");
  }
  const auto last = title.find_last_not_of(whitespace);
  title = title.substr(first, last - first + 1);
  std::size_t scalars = 0;
  for (const unsigned char value : title) {
    if ((value & 0xc0U) != 0x80U) ++scalars;
  }
  if (scalars > 120) {
    throw std::invalid_argument("todo title exceeds 120 characters");
  }
  return title;
}

}

