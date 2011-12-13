program passtring;

var
  s, p : string;
  n, w : integer;
  
begin
  s := 'The quick brown fox jumps over the lazy dog';
  
  // длина строки
  n := length(s);
  writeln('length = ', n);
  
  // выделение подстроки
  p := copy(s, 1, 19); 
  writeln(p);
  
  // удаление подстроки
  delete(p, 5, 6);
  writeln(p);
  
  // поиск подстроки
  w := pos('brown', p);
  writeln(w);
  w := pos('red', p);
  writeln(w);
  
  // вставка подстроки
  insert(' and bear', p, length(p) + 1);
  writeln(p);
    
end.
                           
