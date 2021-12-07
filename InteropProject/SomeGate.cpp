#include "SomeGate.h"

#include "MasterWrapper.h"

SomeGate::SomeGate( MasterWrapper^ masterWrapper )
   : _masterWrapper( masterWrapper )
   , _someClass( _masterWrapper->GetSomeClass() )
{
}

void SomeGate::IncrementCount()
{
   IncrementCountSomeClass( _someClass );
}

void SomeGate::DecrementCount()
{
   DecrementCountSomeClass( _someClass );
}

int SomeGate::GetCount()
{
   return GetCountSomeClass( _someClass );
}