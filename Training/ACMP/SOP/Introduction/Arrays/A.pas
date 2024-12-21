var
  x: array of integer;
  i, n: integer;
begin
  readln(n);
  setlength(x, n+1);
  for i := 1 to n do
    read(x[i]);
  for i := n downto 1 do
    write(x[i], ' ');
end.