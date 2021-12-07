#include "SomeClass.h"

#include <cassert>

void SomeClass::IncrementCount()
{
   _count++;
}

void SomeClass::DecrementCount()
{
   _count--;
}

int SomeClass::GetCount() const
{
   return _count;
}

extern "C" PINVOKE_API void IncrementCountSomeClass( SomeClass * obj )
{
   assert( obj );//Could use fancy macro if desired
   obj->IncrementCount();
}

extern "C" PINVOKE_API void DecrementCountSomeClass( SomeClass * obj )
{
   assert( obj );//Could use fancy macro if desired
   obj->DecrementCount();
}

extern "C" PINVOKE_API int GetCountSomeClass( SomeClass * obj )
{
   assert( obj );//Could use fancy macro if desired
   return obj->GetCount();
}

