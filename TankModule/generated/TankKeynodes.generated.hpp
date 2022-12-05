#include <memory>

#include "sc-memory/sc_memory.hpp"


#include "sc-memory/sc_event.hpp"




#define TankKeynodes_hpp_17_init  bool _InitInternal() override \
{ \
    ScMemoryContext ctx(sc_access_lvl_make_min, "TankKeynodes::_InitInternal"); \
    bool result = true; \
    return result; \
}


#define TankKeynodes_hpp_17_initStatic static bool _InitStaticInternal()  \
{ \
    ScMemoryContext ctx(sc_access_lvl_make_min, "TankKeynodes::_InitStaticInternal"); \
    bool result = true; \
	nrel_parameters = ctx.HelperResolveSystemIdtf("nrel_parameters", ScType::Node); result = result && nrel_parameters.IsValid(); \
	action_TankSearch = ctx.HelperResolveSystemIdtf("action_TankSearch", ScType::Node); result = result && action_TankSearch.IsValid(); \
    return result; \
}


#define TankKeynodes_hpp_17_decl

#define TankKeynodes_hpp_TankKeynodes_impl

#undef ScFileID
#define ScFileID TankKeynodes_hpp

