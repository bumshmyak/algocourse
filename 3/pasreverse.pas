program pasreverse;
type 
  FixedArray = array[1..100] of integer;
var 
  data : FixedArray;
  n : integer;
 
procedure Swap(var a : integer; var b : integer);
var
  c : integer;
begin
  c := a;
  a := b;
  b := c;
end; 
 
procedure InputArray(var a : FixedArray; var n : integer);
var
  i : integer;
begin
  readln(n);
  for i := 1 to n do
    read(a[i]);
    
end;

procedure OutputArray(var a : FixedArray; n : integer);
var
  i : integer;
begin
  for i := 1 to n do
    write(a[i], ' ');
  writeln;
end;

procedure Reverse(var a : FixedArray; n : integer);
var
  i : integer;
begin
  for i := 1 to n div 2 do
    Swap(a[i], a[n - i + 1]);
end;

begin
  InputArray(data, n);
  Reverse(data, n);
  OutputArray(data, n);
end.
