# include <stdio.h>

void appendPlaylist(int *a, size_t const i) {
  int countReplays, lengthSong;
  scanf("%d %d", &countReplays, &lengthSong);
  int last = a[i - 1];
  if (i == 0)
    last = 0;
  a[i] = last + countReplays * lengthSong;
}

void inputPlaylist(int *a, size_t const size) {
  appendPlaylist(a, 0);
  for (size_t i = 1; i < size; i++)
    appendPlaylist(a, i);
}

int binPlaylist(int const *const a, int const nSongs, int const moment) {
  int left = -1;
  int right = nSongs;
  while (left + 1 < right) {
    int middle = left + (right - left) / 2;
    int f = a[middle] >= moment;
    if (f)
      right = middle;
    else
      left = middle;
  }
  return right + 1;
}


int main() {
  int nSongs, nMoments;
  scanf("%d %d", &nSongs, &nMoments);
  int a[nSongs];
  inputPlaylist(a, nSongs);

  for (int i = 0; i < nMoments; i++) {
    int moment;
    scanf("%d", &moment);

    printf("%d\n", binPlaylist(a, nSongs, moment));
  }

  return 0;
}