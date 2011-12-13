program pasrec;

function f(n : integer) : integer;
begin
  if n = 0 then
    f := 1
  else
    f := n * f(n - 1);
end;

begin
  writeln(f(3));
end.
