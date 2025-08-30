using System;

// из плюсов:
// + движок запечатан в своём блоке и не знает об окружающем мире работая с интерфейсами
// + можно в runtime переключать штуки с которыми работает движок

// из минусов:
// - дебажить сложнее
// - код сложнее
// - есть небольшой overhead


class LegacyRect
{
  float _left;
  float _right;
  float _top;
  float _bottom;

  public void Shift(float dx, float dy)
  {
    _left += dx;
    _right += dx;
    _top += dy;
    _bottom += dy;
  }

  public void Show()
  {
    Console.Log($"left: {_left}, right: {_right}, top: {_top}, bottom: {_bottom}");
  }
}
// ...


interface IRect
{
  void Move(int x, int y);
  void Print();
}

class GameEngine(IRect rect)
{ 
  public Update()
  {
    rect.Print();
    rect.Move(4, 2);
    rect.Print();
  }
}


class LegacyRectAdapter : IRect
{
  LegacyRect _rect = new LegacyRect();
  

  public void Move(int x, int y)
  {
    _rect.Shift(0.5f * x, 0.5f * y);
  }

  public void Print()
  {
    _rect.Show();
  }
}
// ...



public class Program
{
  static void Main()
  {
    IRect r = new LegacyRectAdapter();
    
    var ge = new GameEngine(rect: r); // с подключением :)

    ge.Update();
  }
}
