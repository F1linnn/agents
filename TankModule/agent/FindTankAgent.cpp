/*
* Author Soluth
*/

#include "sc-agents-common/utils/AgentUtils.hpp"
#include "sc-agents-common/utils/IteratorUtils.hpp"


#include "keynodes/TankKeynodes.hpp"

#include "FindTankAgent.hpp"
using namespace tankModule;

SC_AGENT_IMPLEMENTATION(FindTankAgent)
{
  ScAddr actionNode = m_memoryCtx.GetEdgeTarget(edgeAddr);

  if (!edgeAddr.IsValid())
    return SC_RESULT_ERROR;


  SC_LOG_INFO("Tank search begin");

  ScAddr center = IteratorUtils::getFirstByOutRelation(
      &m_memoryCtx,
      actionNode,
      scAgentsCommon::CoreKeynodes::rrel_1);

  if (!center.IsValid())
  {
    SC_LOG_ERROR("Parameter isn't valid.");
    AgentUtils::finishAgentWork(&m_memoryCtx, actionNode, false);
    return SC_RESULT_ERROR_INVALID_PARAMS;
  }

  ScAddr centerResult = m_memoryCtx.CreateNode(ScType::NodeConstStruct);
  m_memoryCtx.CreateEdge(ScType::EdgeAccessConstPosPerm, centerResult, center);

  ScAddr key_sc_element;

  ScIterator5Ptr iterator5 = m_memoryCtx.Iterator5(ScType::Unknown, ScType::EdgeAccessConstPosPerm, center,
                                                    ScType::EdgeAccessConstPosPerm, TankKeynodes::nrel_parameters);
  while (iterator5->Next()) {
    key_sc_element = iterator5->Get(0);
    m_memoryCtx.CreateEdge(ScType::EdgeAccessConstPosPerm, centerResult, iterator5->Get(2));
  }

  AgentUtils::finishAgentWork(&m_memoryCtx, actionNode, centerResult, true);
  SC_LOG_DEBUG("Tank search finished");
  return SC_RESULT_OK;*/
}
