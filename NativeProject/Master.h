#pragma once

#include <memory>
#include "InvokeAPI.h"

class SomeClass;

class Master
{
public:
   Master();
   ~Master();

   std::shared_ptr<SomeClass> GetSomeClass() const;

private:
   std::shared_ptr<SomeClass> _someClass;
};

//These header declarations are not required with how this sample application uses this class
//But a good idea
extern "C" PINVOKE_API Master * ConstructMaster();
extern "C" PINVOKE_API void DestroyMaster( Master * obj );
extern "C" PINVOKE_API SomeClass* GetClassMaster( Master * obj );
