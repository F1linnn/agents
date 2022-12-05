#include <memory>

#include "sc-memory/cpp/sc_memory.hpp"


#include "sc-memory/cpp/sc_event.hpp"




#define phlModule_hpp_16_init  bool _InitInternal() override \
{ \
    ScMemoryContext ctx(sc_access_lvl_make_min, "PHLModule::_InitInternal"); \
    bool result = true; \
    return result; \
}


#define phlModule_hpp_16_initStatic static bool _InitStaticInternal()  \
{ \
    ScMemoryContext ctx(sc_access_lvl_make_min, "PHLModule::_InitStaticInternal"); \
    bool result = true; \
    return result; \
}


#define phlModule_hpp_16_decl \
public:\
	sc_result InitializeGenerated()\
	{\
		if (!ScKeynodes::Init())\
			return SC_RESULT_ERROR;\
		if (!ScAgentInit(false))\
			return SC_RESULT_ERROR;\
		return InitializeImpl();\
	}\
	sc_result ShutdownGenerated()\
	{\
		return ShutdownImpl();\
	}\
	sc_uint32 GetLoadPriorityGenerated()\
	{\
		return 50;\
	}

#define phlModule_hpp_PHLModule_impl 

#undef ScFileID
#define ScFileID phlModule_hpp

