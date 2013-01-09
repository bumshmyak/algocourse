program pasreftypes;

const 
  MIN_GRADE : real = 4.5;

type
  Student = record
    id : integer;
    name : string;
    faculty : string;
    grade : real;
  end;

function Accept(var s : Student) : boolean;
begin
  if ((s.faculty = 'B') or (s.faculty = 'K')) 
      and (s.grade >= MIN_GRADE) then
    Accept := true
  else
    Accept := false;
end;

var
  x : Student;

begin
  x.id := 1;
  x.name := 'Dima';
  x.faculty := 'B';
  x.grade := 4.7;
  
  if Accept(x) then
    writeln('Yahooo!');
end.
