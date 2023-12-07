```
$ make one
cc     one.c   -o one
$ ./one 
288
$ make two
cc     two.c   -o two
$ ./two 
71503
$ 
```

part 2 with a 3-liner:

```c
  double time = 71530;
  double distance = 940200;
 
  printf("%ld\n", (size_t)sqrt(time*time-4*distance));
```

```
$ gcc two2.c -lm
$ ./a.out
71503
$
```
