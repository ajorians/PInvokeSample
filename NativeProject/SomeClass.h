#pragma once

#include "InvokeAPI.h"

#include <compare>//Could include any C++ 20 and higher includes in this project

class SomeClass
{
public:
   PINVOKE_API void IncrementCount();
   PINVOKE_API void DecrementCount();
   PINVOKE_API int GetCount() const;

   auto operator<=>(const SomeClass&) const = default;

private:
   int _count = 0;
};

//These header declarations are not required with how this sample application uses this class
//But a good idea
extern "C" PINVOKE_API void IncrementCountSomeClass( SomeClass * obj );
extern "C" PINVOKE_API void DecrementCountSomeClass( SomeClass * obj );
extern "C" PINVOKE_API int GetCountSomeClass( SomeClass * obj );
