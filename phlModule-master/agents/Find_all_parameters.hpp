#pragma once

#include <sc-memory/cpp/kpm/sc_agent.hpp>

#include "keynodes/keynodes.hpp"
#include "Find_all_parameters.generated.hpp"

namespace phlModule
{

class Find_all_parameters : public ScAgent
{
  SC_CLASS(Agent, Event(Keynodes::question_find_products_by_cpfc, ScEvent::Type::AddOutputEdge))
  SC_GENERATED_BODY()
};

} // namespace phlModule
