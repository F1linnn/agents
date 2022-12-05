#include <memory>

#include "sc-memory/cpp/sc_memory.hpp"


#include "sc-memory/cpp/sc_event.hpp"




#define keynodes_hpp_20_init  bool _InitInternal() override \
{ \
    ScMemoryContext ctx(sc_access_lvl_make_min, "Keynodes::_InitInternal"); \
    bool result = true; \
    return result; \
}


#define keynodes_hpp_20_initStatic static bool _InitStaticInternal()  \
{ \
    ScMemoryContext ctx(sc_access_lvl_make_min, "Keynodes::_InitStaticInternal"); \
    bool result = true; \
	question_find_class = ctx.HelperResolveSystemIdtf("question_find_class", ScType::Node); result = result && question_find_class.IsValid(); \
	nrel_inclusion = ctx.HelperResolveSystemIdtf("nrel_inclusion", ScType::Node); result = result && nrel_inclusion.IsValid(); \
    return result; \
}


#define keynodes_hpp_20_decl 

#define keynodes_hpp_Keynodes_impl 

#undef ScFileID
#define ScFileID keynodes_hpp

