int main(void) {
  char c_val = 'm';
  int i_val = 255;
  long int l_val = 99;
  float f_val = 25.8;

  printf("%c\n", c_val);
  printf("%d\n", i_val);
  printf("%ld\n", l_val);
  printf("%x\n", i_val);
  printf("%f\n", f_val);
  printf("%g\n", f_val);
  printf("%s\n", "hello");
  printf("%8.3f\n", f_val);
  printf("%6d\n", i_val);
  printf("%06d\n", i_val);
  printf("%-6d\n", i_val);
}
