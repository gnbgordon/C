int func_null_dereferences(void)
 {
  int scope=21474836471;
  printf(scope=%d\n, scope); 
  int init;
  //未初始化变量
  int result = init+1;
  int array[2];
  //数组越界
  array[3]=1;
  int array1[] = {1,2,3};
  int n = array1[5];
  int* a = NULL;
  return*a;
 }

 
int main(int argc, char* argv[])
{
    char str[10];
    int array[10] = {0,1,2,3,4,5,6,7,8,9};

    int data = array[10];
    array[10] = data;

    if(argc == 2)
    {
        strcpy(str, argv[1]);
    }

    return 0;
}