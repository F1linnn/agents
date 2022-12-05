#pragma once
#include "sc-memory/sc_memory.hpp"
#include "sc-memory/sc_module.hpp"

#include "keynodes/TankKeynodes.hpp"
#include "agent/FindTankAgent.hpp"

#include "TankModule.generated.hpp"

namespace tankModule
{

class TankModule : public ScModule
{
  SC_CLASS(LoadOrder(100))
  SC_GENERATED_BODY()

  virtual sc_result InitializeImpl() override;

  virtual sc_result ShutdownImpl() override;
};
}