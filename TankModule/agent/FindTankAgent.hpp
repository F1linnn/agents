/*
* Author Soluth
*/

#pragma once

#include "keynodes/AutoKeynodes.hpp"
#include "sc-memory/kpm/sc_agent.hpp"
#include "sc-agents-common/keynodes/coreKeynodes.hpp"

#include "FindTankAgent.generated.hpp"

namespace tankModule
{
class FindTankAgent : public ScAgent
{
 SC_CLASS(Agent, Event(scAgentsCommon::CoreKeynodes::question_initiated, ScEvent::Type::AddOutputEdge))
 SC_GENERATED_BODY()

};
}  // namespace hotelModule
