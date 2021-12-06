using System;
using System.Runtime.InteropServices;

namespace PInvokeSample
{
   public class SomeClass : IDisposable
   {
      [DllImport( "NativeProject.dll", CallingConvention = CallingConvention.Cdecl )]
      private static extern IntPtr CreateSomeClass();

      [DllImport( "NativeProject.dll", CallingConvention = CallingConvention.Cdecl )]
      private static extern void DeleteSomeClass( IntPtr someClass );

      [DllImport( "NativeProject.dll", CallingConvention = CallingConvention.Cdecl )]
      private static extern void IncrementCountSomeClass( IntPtr someClass );

      [DllImport( "NativeProject.dll", CallingConvention = CallingConvention.Cdecl )]
      private static extern int GetCountSomeClass( IntPtr someClass );


      private IntPtr _someClass;

      public SomeClass()
      {
         _someClass = CreateSomeClass();
      }

      public void IncrementCount() => IncrementCountSomeClass( _someClass );
      public int GetCount() => GetCountSomeClass( _someClass );

      ~SomeClass()
      {
         Dispose( false );
      }

      public void Dispose()
      {
         this.Dispose( true );
         GC.SuppressFinalize( this );
      }

      protected void Dispose( bool disposing )
      {
         if ( _someClass != null )
         {
            // Release unmanaged resources
            DeleteSomeClass( _someClass );
            _someClass = IntPtr.Zero;
         }
      }
   }
}
