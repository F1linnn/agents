#include <memory>

#include "sc-memory/sc_memory.hpp"


#include "sc-memory/sc_event.hpp"




#define TankModule_hpp_16_init  bool _InitInternal() override \
{ \
    ScMemoryContext ctx(sc_access_lvl_make_min, "TankModule::_InitInternal"); \
    bool result = true; \
    return result; \
}


#define TankModule_hpp_16_initStatic static bool _InitStaticInternal()  \
{ \
    ScMemoryContext ctx(sc_access_lvl_make_min, "TankModule::_InitStaticInternal"); \
    bool result = true; \
    return result; \
}


#define TankModule_hpp_16_decl \
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
		return 100;\
	}

#define TankModule_hpp_TankModule_impl

#undef ScFileID
#define ScFileID TankModule_hpp

