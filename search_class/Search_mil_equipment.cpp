/*
* This source file is part of an OSTIS project. For the latest info, see http://ostis.net
* Distributed under the MIT License
* (See accompanying file COPYING.MIT or copy at http://opensource.org/licenses/MIT)
*/

#include "Search_mil_equipment.hpp"
#include "keynodes/keynodes.hpp"

#include "agents/Find_all_parameters.hpp"


using namespace phlModule;

SC_IMPLEMENT_MODULE(PHLModule)

sc_result PHLModule::InitializeImpl()
{
  if (!phlModule::Keynodes::InitGlobal())
    return SC_RESULT_ERROR;

  SC_AGENT_REGISTER(Find_all_parameters)

  return SC_RESULT_OK;
}

sc_result PHLModule::ShutdownImpl()
{
  SC_AGENT_UNREGISTER(Find_all_parameters)

  return SC_RESULT_OK;
}
