int main(void) {
  int x = ADD(40, 2);

  int y = fun(40, 2);
  
  if (x != 42)
  { /* NOK, empty code blocks generate violations */
  }

  printf("40 + 2 = %d\n", x);
  printf("fun = %d\n", y);
}

int fun(int a, int b) {
  return a * b;
}

int ADD(int a, int b) {
  return a * b;
}
