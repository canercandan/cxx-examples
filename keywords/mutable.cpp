class	Test
{
  int		a;
  mutable int	b;
public:
  void	operate() const;
};

void	Test::operate() const
{
  //a = 12; // wrong
  b = 21; // correct
}

int	main(void)
{
  Test	test;

  test.operate();

  return 0;
}
