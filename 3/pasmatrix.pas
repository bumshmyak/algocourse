program pasmatrix;

const
  N = 3;
  M = 5;

var
 a : array[1..N, 1..M] of integer;
 i, j : integer;

begin
  for i := 1 to N do
    for j := 1 to M do
      a[i,j] := i + j;
end.
