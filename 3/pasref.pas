program pasref;

var
x, y : integer;

procedure Swap(var a : integer; var b : integer);
var
  c : integer;
begin
  c := a;
  a := b;
  b := c;
end;

begin
  x := 1;
  y := 2;
  Swap(x, y);
  writeln(x, ' ', y);
end.
