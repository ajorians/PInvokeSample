namespace InteropDependencies
{
   //This interface could have been in the InteropProject.
   //But maybe you have types that you want written specifically in C#?
    public interface ISomeGate
    {
      void IncrementCount();
      void DecrementCount();
      int GetCount();
    }
}
