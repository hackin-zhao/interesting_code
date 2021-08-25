#include "cpp.h"
#include "cpp_wapper.h"

#ifdef __cplusplus
extern "C"
{
#endif

    struct cpp_example_wapper_t
    {
        CppExample cpp;
    };

    struct cpp_example_wapper_t *get_instance(void)
    {
        return new struct cpp_example_wapper_t;
    }

    void release_instance(struct cpp_example_wapper_t **pp_instance)
    {
        delete *pp_instance;
        *pp_instance = nullptr;
    }

    int call_cpp_example_function(struct cpp_example_wapper_t *p, int i)
    {
        return p->cpp.fun(i);
    }

    int call_cpp_example_function_overload(struct cpp_example_wapper_t *p, int a, int b)
    {
        return p->cpp.fun(a, b);
    }

    struct namespace_cpp_example_wapper_t
    {
        c_invoke_cpp::NameSpaceCpp cpp;
    };

    struct namespace_cpp_example_wapper_t *get_instance_namespace(void)
    {
        return new struct namespace_cpp_example_wapper_t;
    }

    void release_instance_namespace(struct namespace_cpp_example_wapper_t **pp_instance)
    {
        delete *pp_instance;
        *pp_instance = nullptr;
    }

    int call_cpp_example_function_namespace(struct namespace_cpp_example_wapper_t *p, int i)
    {
        return p->cpp.fun(i);
    }

    int call_cpp_example_function_namespace_overload(struct namespace_cpp_example_wapper_t *p, int a, int b)
    {
        return p->cpp.fun(a, b);
    }

#ifdef __cplusplus
}
#endif // __cplusplus