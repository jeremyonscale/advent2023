```
$ make one
g++     one.cpp   -o one
.$ ./one < input 
22199
$ make two
g++     two.cpp   -o two
$ ./two < input 
AAA 22199
DVA 13207
JHA 18827
NMA 17141
PXA 14893
VXA 16579
$ julia
               _
   _       _ _(_)_     |  Documentation: https://docs.julialang.org
  (_)     | (_) (_)    |
   _ _   _| |_  __ _   |  Type "?" for help, "]?" for Pkg help.
  | | | | | | |/ _` |  |
  | | |_| | | | (_| |  |  Version 1.5.3
 _/ |\__'_|_|_|\__'_|  |  Debian ⛬  julia/1.5.3+dfsg-3
|__/                   |

julia> lcm(22199, 13207, 18827, 17141, 14893, 16579)
13334102464297

julia> 
$ 
```
