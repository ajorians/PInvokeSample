#pragma once

ref class MasterWrapper;

using namespace System::Runtime::InteropServices;

public ref class SomeGate : public InteropDependencies::ISomeGate
{
   [DllImport( "NativeProject.dll" )]
   static void IncrementCountSomeClass( System::IntPtr someClass );

   [DllImport( "NativeProject.dll" )]
   static void DecrementCountSomeClass( System::IntPtr someClass );

   [DllImport( "NativeProject.dll" )]
   static int GetCountSomeClass( System::IntPtr someClass );

public:
   SomeGate( MasterWrapper^ masterWrapper );

   virtual void IncrementCount() /*override*/;
   virtual void DecrementCount() /*override*/;
   virtual int GetCount() /*override*/;

private:
   MasterWrapper^ _masterWrapper;//Could be in a BaseGate class

   System::IntPtr _someClass;
};