
#include "TankModule.hpp"
#include "agent/FindTankAgent.hpp"
#include "keynodes/TankKeynodes.hpp"


namespace tankModule
{
SC_IMPLEMENT_MODULE(TankModule)

sc_result TankModule::InitializeImpl()
{
  if (!TankKeynodes::InitGlobal())
  {
    return SC_RESULT_ERROR;
  }

  ScMemoryContext ctx(sc_access_lvl_make_min, "TankModule");

  SC_AGENT_REGISTER(FindTankAgent)

  return SC_RESULT_OK;
}

sc_result TankModule::ShutdownImpl()
{
  SC_AGENT_UNREGISTER(FindTankAgent)

  return SC_RESULT_OK;
}
}