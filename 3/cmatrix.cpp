const int N = 3;
const int M = 5;

int main() {
  int a[N][M];
  for (int i = 0; i < N; i++) 
    for (int j = 0; j < M; j++)
      a[i][j] = i + j;
  return 0;
}
