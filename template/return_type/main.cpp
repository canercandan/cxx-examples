template <typename T>
T func()
{
  return static_cast<T>(1);
}

int	main(void)
{
  int a = func<int>();
}
