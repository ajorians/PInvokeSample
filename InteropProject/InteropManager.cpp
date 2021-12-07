#include "InteropManager.h"
#include "MasterWrapper.h"
#include "SomeGate.h"

InteropManager::InteropManager()
{
}

void InteropManager::Initialize()
{
   _masterWrapper = gcnew MasterWrapper();

   _someGate = gcnew SomeGate( _masterWrapper );
}

InteropDependencies::ISomeGate^ InteropManager::GetSomeGate()
{
   return _someGate;
}