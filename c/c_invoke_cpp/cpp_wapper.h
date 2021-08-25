#if !defined(_CPP_WAPPER_H_)
#define _CPP_WAPPER_H_

#ifdef __cplusplus
extern "C" {
#endif

struct cpp_example_wapper_t;

struct cpp_example_wapper_t *get_instance(void);
void release_instance(struct cpp_example_wapper_t **pp_instance);
int call_cpp_example_function(struct cpp_example_wapper_t* p, int i);
int call_cpp_example_function_overload(struct cpp_example_wapper_t* p, int a, int b);

struct namespace_cpp_example_wapper_t;

struct namespace_cpp_example_wapper_t *get_instance_namespace(void);
void release_instance_namespace(struct namespace_cpp_example_wapper_t **pp_instance);
int call_cpp_example_function_namespace(struct namespace_cpp_example_wapper_t* p, int i);
int call_cpp_example_function_namespace_overload(struct namespace_cpp_example_wapper_t* p, int a, int b);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _CPP_WAPPER_H_
