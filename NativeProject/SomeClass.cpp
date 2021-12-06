#include "SomeClass.h"

void SomeClass::IncrementCount()
{
   _count++;
}

int SomeClass::GetCount() const
{
   return _count;
}

extern "C" PINVOKE_API SomeClass * CreateSomeClass()
{
   return new SomeClass();
}

extern "C" PINVOKE_API void DeleteSomeClass( SomeClass * obj )
{
   delete obj;
}

extern "C" PINVOKE_API void IncrementCountSomeClass( SomeClass * obj )
{
   //Could null check?  If wanted to?
   obj->IncrementCount();
}

extern "C" PINVOKE_API int GetCountSomeClass( SomeClass * obj )
{
   //Could null check?  If wanted to?
   return obj->GetCount();
}

