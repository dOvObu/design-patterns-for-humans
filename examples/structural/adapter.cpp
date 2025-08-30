#include <iostream>
#include <string>


// разные библиотеки, например api opengl и directx
struct adaptee1
{
  void log_int(int num)
  {
    std::cout << "num: " << num << std::endl; 
  }
}; // ...


// клиентский код, например движок
struct i_target
{
  virtual void print(std::string text) = 0;
};

struct target
{
  i_target* logger = nullptr;
  
  void update_with(std::string text)
  {
    if (logger == nullptr) return;
    logger->print(text);
  }
};


// разные адаптеры, например к api opengl и directx
struct adapter : public i_target
{
  void print(std::string text) override
  {
    if (!isdigit(text[0])) return;
    logger.log_int(atoi(text.c_str()));
  }
private:
  adaptee1 logger;
}; // ...


int main()
{
  i_target* l = new adapter();
  
  target client;
  client.logger = l; // с подключением :)
  
  client.update_with("42");

  return 0;
}
