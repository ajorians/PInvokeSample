#pragma once

ref class MasterWrapper;

public ref class InteropManager
{
public:
   InteropManager();

   void Initialize();//Creates the native side and the gates

   InteropDependencies::ISomeGate^ GetSomeGate();

private:
   InteropDependencies::ISomeGate^ _someGate;

   MasterWrapper^ _masterWrapper;
};
