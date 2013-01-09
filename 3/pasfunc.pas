program pasfunc;

var
x, y : integer;

function Max(a : integer; b : integer): integer;
begin
  if (a > b) then 
    Max := a
  else
    Max := b;
end;

begin
  readln(x, y);
  writeln(Max(x, y));
end.
