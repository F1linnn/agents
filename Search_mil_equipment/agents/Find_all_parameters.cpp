#include <iostream>
#include <sc-memory/cpp/sc_memory.hpp>
#include <sc-memory/cpp/sc_stream.hpp>
#include <sc-memory/cpp/sc_template_search.cpp>
#include <sc-agents-common/utils/IteratorUtils.hpp>
#include <sc-agents-common/utils/AgentUtils.hpp>
#include <sc-agents-common/utils/GenerationUtils.hpp>
#include "Find_all_parameters.hpp"

using namespace std;
using namespace utils;

namespace phlModule
{

SC_AGENT_IMPLEMENTATION(Find_all_parameters)
{
  if (!edgeAddr.IsValid())
    return SC_RESULT_ERROR;

  ScAddr questionNode = ms_context->GetEdgeTarget(edgeAddr);
  ScAddr param = IteratorUtils::getFirstFromSet(ms_context.get(), questionNode);
  if (!param.IsValid())
    return SC_RESULT_ERROR_INVALID_PARAMS;

  ScAddr answer = ms_context->CreateNode(ScType::NodeConstStruct);
  ms_context->CreateEdge(ScType::EdgeAccessConstPosPerm, answer, param);
  
  ms_context->CreateEdge(ScType::EdgeAccessConstPosPerm, answer, Keynodes::nrel_elements);

  ScIterator5Ptr iterator5_1 = IteratorUtils::getIterator5(ms_context.get(), param, Keynodes::nrel_elements, true); // find inclusion*
  
  while (iterator5_1->Next())
  {
    ms_context->CreateEdge(ScType::EdgeAccessConstPosPerm, answer, iterator5_1->Get(1)); // edge common
    ms_context->CreateEdge(ScType::EdgeAccessConstPosPerm, answer, iterator5_1->Get(2)); // excercise
    ms_context->CreateEdge(ScType::EdgeAccessConstPosPerm, answer, iterator5_1->Get(3)); // edge access
    ms_context->CreateEdge(ScType::EdgeAccessConstPosPerm, answer, iterator5_1->Get(4)); // nrel_inclusion*
  }

  AgentUtils::finishAgentWork(ms_context.get(), questionNode, answer);

  return SC_RESULT_OK;
}
} // namespace phlModule
