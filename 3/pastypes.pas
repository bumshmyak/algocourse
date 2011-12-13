program pastypes;
var
b : boolean; 
c : char;
n : integer;
m : longint;
x : real;
s : string;
a : array[1..10] of integer;
begin
  b := true;
  c := 'a';
  n := 1000;
  m := 1000000000;
  x := 3.14;
  s := 'mnogo bykv';
  a[1] := 5;
  
  // многострочная команда
  writeln('b = ', b, #13, #10,
          'c = ', c, #13, #10,
          'n = ', n, #13, #10,
          'm = ', m,  #13, #10,
          'x = ', x,  #13, #10,
          's = ', s,  #13, #10,
          'a[1] = ', a[1]);
end.
