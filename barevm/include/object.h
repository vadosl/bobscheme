/******************************************************************************
** bob: Scheme objects for bare VM
**
** Eli Bendersky (eliben@gmail.com)
** This code is in the public domain
******************************************************************************/
#ifndef OBJECT_H
#define OBJECT_H

#include "dstring.h"
#include "cutils.h"
#include "builtins.h"


typedef enum BobObjectType {
    TYPE_NULL, TYPE_BOOLEAN, TYPE_NUMBER, TYPE_SYMBOL, TYPE_PAIR,
    TYPE_BUILTIN_PROC, TYPE_CLOSURE,
} BobObjectType;


struct BobCodeObject;
struct BobEnv;

typedef struct BobObject {
    BobObjectType type;

    union {
        int num;
        BOOL boolval;
        dstring sym;
        struct {
            struct BobObject *first, *second;
        } pair;
        struct {
            builtin_proc_type proc;
            dstring name;
        } builtin;
        struct {
            struct BobCodeObject* codeobj;
            struct BobEnv* env;
        } closure;
    } d;
} BobObject;


BobObject* BobNull_new();
BobObject* BobBoolean_new(BOOL boolval);
BobObject* BobNumber_new(int num);
BobObject* BobSymbol_new(dstring sym);
BobObject* BobPair_new(BobObject* first, BobObject* second);
BobObject* BobBuiltin_new(builtin_proc_type proc, dstring name);
BobObject* BobClosure_new(struct BobCodeObject* codeobj, struct BobEnv* env);

/* Concatenate a textual representation of the given object into the
** given dstring.
*/
void BobObject_repr(BobObject* obj, dstring repr);


#endif /* OBJECT_H */
