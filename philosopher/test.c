#include "philosopher.h"

void *test(void *str)
{
	char *s = (char *)str;
	for (int i = 0; i < 3; i++)
	{
		printf("%s\n", s);
	}
	
	return (0);
}

void *p_function(void * data)
{
  pthread_t tid; // thread id

  tid = pthread_self();

  char* thread_name = (char *)data;
  int i = 0;

  while(i < 3)
  {
    printf("thread name : %s, tid : %x\n", thread_name, (unsigned int)tid);
    i++;
    usleep(1000 * 1000);
  }
  return 0;
}


int main()
{
	pthread_t t;

	char a[] = "hello";
	char b[] = "bye";
	pthread_create(&t, NULL, test, (void *)a);
	test((void *)b);
}

// int main(void)
// {
//   pthread_t pthread;
//   int thr_id;
//   int status;
//   char p1[] = "thread_created";
//   char p2[] = "thread_main";

//   thr_id = pthread_create(&pthread, NULL, test, (void*)p1);
// }