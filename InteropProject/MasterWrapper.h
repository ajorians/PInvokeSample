#pragma once

using namespace System::Runtime::InteropServices;

public ref class MasterWrapper //This is IDisposable because it has a destructor, etc
{
   [DllImport( "NativeProject.dll", CallingConvention = CallingConvention::Cdecl )]
   static System::IntPtr ConstructMaster();

   [DllImport( "NativeProject.dll", CallingConvention = CallingConvention::Cdecl )]
   static void DestroyMaster( System::IntPtr master );

   [DllImport( "NativeProject.dll", CallingConvention = CallingConvention::Cdecl )]
   static System::IntPtr GetClassMaster( System::IntPtr master );

public:
   MasterWrapper();
   ~MasterWrapper();
   !MasterWrapper();

   System::IntPtr GetSomeClass();

private:
   bool _isDisposed = false;

   System::IntPtr _master;
};
