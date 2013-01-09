program pasproc;

procedure PrintSeparator(c : char; n : integer);
var
  i : integer;
begin
  for i := 1 to n do begin
    write(c);
  end;
  writeln;
end;

begin
  PrintSeparator('#', 20);
end.
