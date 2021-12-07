using System;
using System.ComponentModel;
using System.Windows.Input;
using InteropDependencies;

namespace PInvokeSample
{
   public class VM : INotifyPropertyChanged
   {
      public event PropertyChangedEventHandler PropertyChanged;

      private ICommand _decrementClicked;
      private ICommand _incrementClicked;
      private ISomeGate _someGate;

      public VM( ISomeGate someGate )
      {
         _someGate = someGate ?? throw new ArgumentNullException( nameof( someGate ) );

         _decrementClicked = new Command( () =>
         {
            _someGate.DecrementCount();
            PropertyChanged?.Invoke( this, new PropertyChangedEventArgs( nameof( CountStr ) ) );
         } );
         _incrementClicked = new Command( () =>
         {
            _someGate.IncrementCount();
            PropertyChanged?.Invoke( this, new PropertyChangedEventArgs( nameof( CountStr ) ) );
         } );
      }
      public ICommand DecrementClicked => _decrementClicked;
      public ICommand IncrementClicked => _incrementClicked;
      public int Count
      {
         get => _someGate.GetCount();
      }

      public string CountStr => Count.ToString();
   }
}
