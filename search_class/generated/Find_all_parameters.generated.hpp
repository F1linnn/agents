#include <memory>

#include "sc-memory/cpp/sc_memory.hpp"


#include "sc-memory/cpp/sc_event.hpp"




#define Find_all_parameters_hpp_14_init  bool _InitInternal() override \
{ \
    ScMemoryContext ctx(sc_access_lvl_make_min, "Find_all_parameters::_InitInternal"); \
    bool result = true; \
    return result; \
}


#define Find_all_parameters_hpp_14_initStatic static bool _InitStaticInternal()  \
{ \
    ScMemoryContext ctx(sc_access_lvl_make_min, "Find_all_parameters::_InitStaticInternal"); \
    bool result = true; \
    return result; \
}


#define Find_all_parameters_hpp_14_decl \
private:\
	typedef ScAgent Super;\
protected: \
	Find_all_parameters(char const * name, sc_uint8 accessLvl) : Super(name, accessLvl) {}\
	virtual sc_result Run(ScAddr const & listenAddr, ScAddr const & edgeAddr, ScAddr const & otherAddr) override; \
private:\
	static std::unique_ptr<ScEvent> ms_event;\
    static std::unique_ptr<ScMemoryContext> ms_context;\
public: \
	static bool handler_emit(ScAddr const & addr, ScAddr const & edgeAddr, ScAddr const & otherAddr)\
	{\
		Find_all_parameters Instance("Find_all_parameters", sc_access_lvl_make_min);\
		return Instance.Run(addr, edgeAddr, otherAddr) == SC_RESULT_OK;\
	}\
	static void RegisterHandler()\
	{\
		SC_ASSERT(!ms_event.get(), ());\
		SC_ASSERT(!ms_context.get(), ());\
		ms_context.reset(new ScMemoryContext(sc_access_lvl_make_min, "handler_Find_all_parameters"));\
		ms_event.reset(new ScEvent(*ms_context, Keynodes::question_find_class, ScEvent::Type::AddOutputEdge, &Find_all_parameters::handler_emit));\
        if (ms_event.get())\
        {\
            SC_LOG_INFO("Register agent Find_all_parameters");\
        }\
        else\
        {\
            SC_LOG_ERROR("Can't register agent Find_all_parameters");\
        }\
	}\
	static void UnregisterHandler()\
	{\
		ms_event.reset();\
		ms_context.reset();\
	}

#define Find_all_parameters_hpp_Find_all_parameters_impl \
std::unique_ptr<ScEvent> Find_all_parameters::ms_event;\
std::unique_ptr<ScMemoryContext> Find_all_parameters::ms_context;

#undef ScFileID
#define ScFileID Find_all_parameters_hpp

