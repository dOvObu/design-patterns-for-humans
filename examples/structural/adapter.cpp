#include <iostream>
#include <string>


// например api opengl или directx
struct adaptee
{
  void log_int(int num)
  {
    std::cout << "num: " << num << std::endl; 
  }
};


// например разные адаптеры к api разных библиотек
struct i_adapter
{
  virtual void print(std::string text) = 0;
};

struct adapter : public i_adapter
{
  void print(std::string text) override
  {
    if (!isdigit(text[0])) return;
    logger.log_int(atoi(text.c_str()));
  }
private:
  adaptee logger;
};


// например движок
struct client
{
  i_adapter* logger = nullptr;
  
  void update_with(std::string text)
  {
    if (logger == nullptr) return;
    logger->print(text);
  }
};


int main()
{
  i_adapter* l = new adapter();
  
  client cl;
  cl.logger = l;
  
  cl.update_with("42");

  return 0;
}
