/******************************************************************************
** bob: builtins - implementation of some built-in Scheme procedures.
**
** Eli Bendersky (eliben@gmail.com)
** This code is in the public domain
******************************************************************************/
#ifndef BUILTINS_H
#define BUILTINS_H


/* Builtin procedures take several BobObject* arguments and return a
** single BobObject*. Since the actual number of arguments is variable,
** is has to be specified when the procedure is called.
*/
struct BobObject;
typedef struct BobObject* (*builtin_proc_type)(size_t nargs, struct BobObject** args);

builtin_proc_type builtin_by_name(dstring name);


#endif /* BUILTINS_H */
