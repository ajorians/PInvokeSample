#include "MasterWrapper.h"

MasterWrapper::MasterWrapper()
   : _master( ConstructMaster() )
{
}

MasterWrapper::~MasterWrapper()
{
   if ( _isDisposed )
      return;

   // dispose managed data here
   this->!MasterWrapper(); // call finalizer
   _isDisposed = true;
}

// Finalizer
MasterWrapper::!MasterWrapper()
{
   // free unmanaged data here
   DestroyMaster( _master );
}

System::IntPtr MasterWrapper::GetSomeClass()
{
   return GetClassMaster( _master );
}