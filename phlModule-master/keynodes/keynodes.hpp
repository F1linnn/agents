/*
* This source file is part of an OSTIS project. For the latest info, see http://ostis.net
* Distributed under the MIT License
* (See accompanying file COPYING.MIT or copy at http://opensource.org/licenses/MIT)
*/

#pragma once

#include <sc-memory/cpp/sc_object.hpp>
#include <sc-memory/cpp/sc_addr.hpp>

#include "keynodes.generated.hpp"

namespace phlModule
{

class Keynodes : public ScObject
{
  SC_CLASS()
  SC_GENERATED_BODY()

public:

  SC_PROPERTY(Keynode("question_find_products_by_cpfc"), ForceCreate)
  static ScAddr question_find_products_by_cpfc;
    
  SC_PROPERTY(Keynode("nrel_parameters"), ForceCreate)
  static ScAddr nrel_parameters;
};

} // namespace phlModule
