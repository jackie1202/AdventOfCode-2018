//  https://en.wikipedia.org/wiki/Summed-area_table

#include <bits/stdc++.h>

   sum[y][x] = p + sum[y - 1][x] + sum[y][x - 1] - sum[y - 1][x - 1];
  
   total = sum[y][x] - sum[y - s][x] - sum[y][x - s] + sum[y - s][x - s];
                
