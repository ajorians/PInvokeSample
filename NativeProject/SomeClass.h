#pragma once

#include "InvokeAPI.h"

class PINVOKE_API SomeClass
{
public:
   void IncrementCount();
   int GetCount() const;

private:
   int _count = 0;
};

extern "C" PINVOKE_API SomeClass * CreateSomeClass();
extern "C" PINVOKE_API void DeleteSomeClass( SomeClass * obj );

extern "C" PINVOKE_API void IncrementCountSomeClass( SomeClass * obj );
extern "C" PINVOKE_API int GetCountSomeClass( SomeClass * obj );
