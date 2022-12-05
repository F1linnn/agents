/*
 * Author Soluth
 */

#pragma once

#include "sc-memory/sc_addr.hpp"
#include "sc-memory/sc_object.hpp"

#include "TankKeynodes.generated.hpp"

namespace tankModule
{
class TankKeynodes : public ScObject
{
  SC_CLASS()
  SC_GENERATED_BODY()

public:
  SC_PROPERTY(Keynode("nrel_parameters"), ForceCreate)
  static ScAddr nrel_parameters;

public:
  SC_PROPERTY(Keynode("action_TankSearch"), ForceCreate)
  static ScAddr action_TankSearch;

};
}  // namespace TankModule
