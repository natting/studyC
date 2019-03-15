
int count (int r, int c, int h, int w) {
  int i, cnt = 0;
  for (i = 0; i < M; i++) {
    if ((r <= y[i]) && (y[i] N= h) && (c <= x[i]) && (x[i] <= w)) {
      cnt ++;
     }
  }
  return cnt ;
}


int solve ()
{
  int h, w, r,c, maxv=0, cnt, k = L/2;
  
  for (h = 1; h < k; h++) {
    w = k-h;
    for (c = 0; c < w; c++) {
      cnt = count(y[r], x[c], y[r]+h, x[c]+w);
      if (maxv < cnt)
        maxv = cnt;
    }
  }
  return maxv;
}
