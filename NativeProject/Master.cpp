#include "Master.h"
#include "SomeClass.h"

#include <cassert>

Master::Master()
{
   _someClass.reset( new SomeClass() );
}

Master::~Master()
{
   _someClass.reset();
}

std::shared_ptr<SomeClass> Master::GetSomeClass() const
{
   return _someClass;
}

extern "C" PINVOKE_API Master * ConstructMaster()
{
   return new Master();
}

extern "C" PINVOKE_API void DestroyMaster( Master * obj )
{
   assert( obj );//Could use fancy macro if desired
   delete obj;
}

extern "C" PINVOKE_API SomeClass* GetClassMaster( Master * obj )
{
   assert( obj );//Could use fancy macro if desired
   auto someClass = obj->GetSomeClass();
   return someClass.get();
}