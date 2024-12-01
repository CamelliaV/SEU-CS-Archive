package seu.assignment.scenario4;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

abstract class AbstractRestaurant implements HallStrategy, WindowStrategy, Iterable<Window> {

   private List<Window> windows = new ArrayList<>();

   private String name;

   AbstractRestaurant() {
      initialize();
   }

   private void initialize() {
      windows.add(new Window(0));
      windows.add(new Window(1));
      windows.add(new Window(2));
      windows.add(new Window(3));
      windows.add(new Window(4));
      windows.add(new Window(5));
      windows.add(new Window(6));
      windows.add(new Window(7));
      windows.add(new Window(8));
   }

   public abstract void dinner();

   @Override
   public Iterator<Window> iterator() {
      return windows.iterator();
   }
}