using System.ComponentModel;
using System.Windows.Input;

namespace PInvokeSample
{
   public class VM : INotifyPropertyChanged
   {
      public event PropertyChangedEventHandler PropertyChanged;

      private ICommand _testClicked;
      private SomeClass _someClass = new SomeClass();

      public VM()
      {
         _testClicked = new Command( () =>
         {
            _someClass.IncrementCount();
            PropertyChanged?.Invoke( this, new PropertyChangedEventArgs( nameof( CountStr ) ) );
         } );
      }
      public ICommand TestClicked => _testClicked;
      public int Count
      {
         get => _someClass.GetCount();
      }

      public string CountStr => Count.ToString();
   }
}
